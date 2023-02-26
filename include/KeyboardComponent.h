//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_KEYBOARDCOMPONENT_H
#define SLATFORMER_KEYBOARDCOMPONENT_H
#include "ECS.h"
#include "Game.h"
#include "Components.h"


class KeyboardComponent : public Component
{
public:
    TransformComponent *transform;

    void Init() override
    {
        transform = &entity->getComponent<TransformComponent>();
    }

    void Update() override
    {
        if(Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    break;
            }
        }
        if(Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
            }
        }
    }
};


#endif //SLATFORMER_KEYBOARDCOMPONENT_H
