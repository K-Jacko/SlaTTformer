//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_COLLIDERCOMPONENT_H
#define SLATFORMER_COLLIDERCOMPONENT_H
#include "SDL.h"
#include "Components.h"
#include <string>

class ColliderComponent : public Component
{
public:
    ColliderComponent(std::string t)
    {
        tag = t;
    }
    ~ColliderComponent() override{}
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;

    void Init() override
    {
        if(!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }

        transform = &entity->getComponent<TransformComponent>();
    }

    void Update() override
    {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = static_cast<int>(transform->width * transform->scale);
        collider.h = static_cast<int>(transform->height * transform->scale);
    }
};


#endif //SLATFORMER_COLLIDERCOMPONENT_H
