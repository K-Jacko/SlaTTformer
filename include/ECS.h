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

class Component {
public:
    Entity* entity;
    Component(){}
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
    void Update()
    {
        for(auto& c : components) c->Update();
    }
    void Draw()
    {
        for(auto& c : components) c->Draw();
    }
    void Debug()
    {
        for(auto& c : components) c->Debug();
    }
    bool isActive() const { return active;}
    void destroy() { active = false; }

    template <typename T> bool hasComponent() const
    {
        return  componentBitSet[getComponentTypeID<T>()];
    }

    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{c };
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


private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
};

class Manager
{
public:
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

    void Debug(){
        for (auto& e : entities) e->Debug();
    }

private:
    std::vector<std::unique_ptr<Entity>> entities;
};
#endif //SLATFORMER_ECS_H
