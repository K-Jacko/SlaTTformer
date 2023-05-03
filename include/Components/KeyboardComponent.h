//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_KEYBOARDCOMPONENT_H
#define SLATFORMER_KEYBOARDCOMPONENT_H
#include "Game.h"
#include "Global.h"

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
        if(Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y -= gbl::GAME::MAX_VERTICAL_SPEED;
                    transform->kinematic = 1;
                    break;
                case SDLK_s:
                    spriteComponent->Play("resources/Character/_Crouch.png");
                    break;
                case SDLK_a:
                    transform->velocity.x -= gbl::PLAYER::MAX_HORIZONTAL_SPEED;
                    spriteComponent->Play("resources/Character/_Run.png");
                    spriteComponent->flip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_d:
                    transform->velocity.x += gbl::PLAYER::MAX_HORIZONTAL_SPEED;
                    spriteComponent->Play("resources/Character/_Run.png");
                    spriteComponent->flip = SDL_FLIP_NONE;
                    break;
                case SDLK_e:
                    break;
                case SDLK_SPACE:
                    Game::isDebug = true;
            }
        }
        else{
            //transform->acceleration.Zero();
        }
        if(Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    break;
                case SDLK_s:
                    spriteComponent->Play("resources/Character/_Idle.png");
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    spriteComponent->Play("resources/Character/_Idle.png");
                    transform->velocity.x -= gbl::PLAYER::MAX_HORIZONTAL_SPEED;
                    break;
                case SDLK_d:
                    transform->velocity.x += gbl::PLAYER::MAX_HORIZONTAL_SPEED;
                    spriteComponent->Play("resources/Character/_Idle.png");
                    break;
                case SDLK_e:
                    spriteComponent->Play("resources/Character/_Idle.png");
                case SDLK_SPACE:
                    Game::isDebug = false;
                    break;
            }
        }
    }
};


#endif //SLATFORMER_KEYBOARDCOMPONENT_H
