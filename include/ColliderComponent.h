//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_COLLIDERCOMPONENT_H
#define SLATFORMER_COLLIDERCOMPONENT_H
#include <string>
#include "SDL.h"
#include "TransformComponent.h"
#include "ECS.h"
#include "Game.h"

class ColliderComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;
    int xOffset, yOffset;
    TransformComponent* transform;
    bool collidesWithPlayer = false;

    ColliderComponent(std::string t, int xOff, int yOff)
    {
        tag = t;
        xOffset = xOff;
        yOffset = yOff;
    }
    ColliderComponent(std::string t, bool cwp)
    {
        tag = t;
        xOffset = 0;
        yOffset = 0;
        collidesWithPlayer = cwp;
    }
    ~ColliderComponent() override{}

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
        collider.x = static_cast<int>(transform->position.x) + (yOffset * transform->scale);
        collider.y = static_cast<int>(transform->position.y) + (yOffset * transform->scale);
        collider.w = static_cast<int>((transform->width - xOffset) * transform->scale) ;
        collider.h = static_cast<int>((transform->height - yOffset) * transform->scale) ;
    }

    void Debug() override
    {
        if(Game::isDebug)
            SDL_RenderDrawRect(Game::renderer,&collider);

    }
};


#endif //SLATFORMER_COLLIDERCOMPONENT_H
