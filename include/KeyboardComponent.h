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
    SpriteComponent *spriteComponent;

    void Init() override
    {
        if(!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
        if(!entity->hasComponent<SpriteComponent>())
        {
            entity->addComponent<SpriteComponent>();
        }
        spriteComponent = &entity->getComponent<SpriteComponent>();
    }

    void Update() override
    {
        if(Game::event.type == SDL_MOUSEBUTTONDOWN)
        {
        } else if(Game::event.type == SDL_MOUSEBUTTONUP)
        {
        }
        if(Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->acceleration.y = -0.8;
                    transform->kinematic = 1;
                    break;
                case SDLK_s:
                    transform->acceleration.y = 0;
                    transform->kinematic = 0;
                    spriteComponent->Play("resources/Character/_Crouch.png");
                    break;
                case SDLK_a:
                    transform->acceleration.x = -0.6;
                    transform->kinematic = 1;
                    spriteComponent->Play("resources/Character/_Run.png");
                    spriteComponent->flip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_d:
                    transform->acceleration.x = 0.6;
                    transform->kinematic = 1;
                    spriteComponent->Play("resources/Character/_Run.png");
                    spriteComponent->flip = SDL_FLIP_NONE;
                    break;
                case SDLK_e:
                    spriteComponent->Play("resources/Character/_Attack2NoMovement.png");
                    break;
                case SDLK_SPACE:
                    Game::isDebug = true;
            }
        }
        else{
            transform->acceleration.x = 0;
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
                case SDLK_e:
                    spriteComponent->Play("resources/Character/_Idle.png");
                case SDLK_SPACE:
                    Game::isDebug = false;
                    break;

            }
        }
        if(transform->velocity.x < 0.05f || transform->velocity.x < -0.5f)
            spriteComponent->Stop();
    }
};


#endif //SLATFORMER_KEYBOARDCOMPONENT_H
