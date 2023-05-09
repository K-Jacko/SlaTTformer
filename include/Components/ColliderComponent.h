//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_COLLIDERCOMPONENT_H
#define SLATFORMER_COLLIDERCOMPONENT_H
#include <string>
#include <utility>
#include "SDL.h"
#include "TransformComponent.h"
#include "ECS.h"
#include "Game.h"

class ColliderComponent : public Component
{
public:
    SDL_Rect collider{};
    std::string tag;
    TransformComponent* transform{};

    explicit ColliderComponent(std::string t)
    {
        tag = std::move(t);
    }
    ~ColliderComponent() override   = default;

    void Init() override
    {
        if(!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();

        Game::colliders.push_back(this);
    }

    void Update() override
    {
        collider.x = static_cast<int>(transform->GetPosition()->x) + transform->GetScale();
        collider.y = static_cast<int>(transform->GetPosition()->y) + transform->GetScale();

        collider.w = static_cast<int>(transform->GetWidth() * transform->GetScale());
        collider.h = static_cast<int>(transform->GetHeight() * transform->GetScale());
    }

    void Debug() override
    {
        SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(Game::renderer,&collider);
    }
};


#endif //SLATFORMER_COLLIDERCOMPONENT_H
