//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_ECS_H
#define SLATFORMER_ECS_H
#include <iostream>
#include "TextureManager.h"
#include "Math.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;
class Player;

class Manager;

class Component {
public:
    Entity* entity{};
    Component()= default;
    virtual void Init() {}

    virtual void Update() {}

    virtual void Draw() {}

    virtual ~Component() = default;

    virtual void Debug(){}
};
using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID  lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static  ComponentID  typeID = getComponentTypeID();
    return  typeID;
}

constexpr  std::size_t  maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Entity{
public:
    virtual void Update()
    {
        for(auto& c : components) c->Update();
    }
    virtual void Draw()
    {
        for(auto& c : components) c->Draw();
    }
    virtual void Debug()
    {
        for(auto& c : components) c->Debug();
    }
    bool isActive() const { return active;}
    virtual void destroy() { active = false; }

    template <typename T> bool hasComponent() const
    {
        return  componentBitSet[getComponentTypeID<T>()];
    }

    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;

        c->Init();
        return *c;
    }

    template<typename T> T& getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

    void AddInput(Vector2D _vec)
    {
        auto vector = new Vector2D(_vec);
        keyInputs.push_back(vector);
    }
    void AddInput(int i)
    {
        auto input = i;
        mouseInputs.push_back(input);
    }
    void RemoveInput(int _i)
    {
        auto input = _i;
        mouseInputs.erase(std::remove_if(mouseInputs.begin(), mouseInputs.end(), [&](int v) {return matchesTarget(v,input);}), mouseInputs.end());
    }
    void RemoveInput(Vector2D _vec)
    {
        auto vector = new Vector2D(_vec);
        keyInputs.erase(std::remove_if(keyInputs.begin(), keyInputs.end(), [&](Vector2D* v) {return matchesTarget(*v, *vector);}), keyInputs.end());
    }
    static bool matchesTarget(int _i, int _j)
    {
        return _i == _j;
    }
    static bool matchesTarget(Vector2D v, Vector2D t)
    {
        return v.x == t.x && v.y == t.y;
    }
    std::vector<Vector2D*> GetKeyInputs(){return keyInputs;}
    std::vector<int> GetMouseInputs(){return mouseInputs;}


private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    std::vector<Vector2D*> keyInputs;
    std::vector<int> mouseInputs;
};

class Player : public Entity
{
public:
    void CastLine()
    {
        std::cout << "wawa" << std::endl;
    }
};
class Manager
{
public:
    static Manager& Instance()
    {
        static Manager instance;
        return instance;
    }
    void Update(){
        for (auto& e : entities) e->Update();
    }
    void Draw(){
        for (auto& e : entities) e->Draw();
    }
    void Refresh()
    {
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),[](const std::unique_ptr<Entity> &mEntity)
        {
            return !mEntity->isActive();
        }),
                       std::end(entities));
    }

    Entity& addEntity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
    void addEntityRemote(Entity* entity)
    {
        std::unique_ptr<Entity> uPtr{entity};
        entities.emplace_back(std::move(uPtr));
    }

    Player& addPlayer()
    {
        Player* e = new Player();
        std::unique_ptr<Player> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }

    void Debug(){
        for (auto& e : entities) e->Debug();
    }

private:
    std::vector<std::unique_ptr<Entity>> entities;
};
#endif //SLATFORMER_ECS_H
