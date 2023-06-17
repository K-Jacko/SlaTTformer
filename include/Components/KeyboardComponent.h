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
            if(Game::event.key.keysym.sym == SDLK_w)
            {
                entity->AddInput(GetMovementVector(gbl::DIRECTION::Up));
                transform->SetKinesis(true);

            }
            if(Game::event.key.keysym.sym == SDLK_s)
            {
                entity->AddInput(GetMovementVector(gbl::DIRECTION::Down));
            }
            if(Game::event.key.keysym.sym == SDLK_a)
            {
                entity->AddInput(GetMovementVector(gbl::DIRECTION::Left));
                spriteComponent->Play("resources/Entities/Player/PLAYER_IDLE.png");
                spriteComponent->flip = SDL_FLIP_HORIZONTAL;
            }
            if(Game::event.key.keysym.sym == SDLK_d)
            {
                entity->AddInput(GetMovementVector(gbl::DIRECTION::Right));
                spriteComponent->Play("resources/Entities/Player/PLAYER_IDLE.png");
                spriteComponent->flip = SDL_FLIP_NONE;
            }
        }
        else{
            //transform->acceleration.Zero();
        }
        if(Game::event.type == SDL_KEYUP)
        {
            if(Game::event.key.keysym.sym == SDLK_w)
            {
                entity->RemoveInput(GetMovementVector(gbl::DIRECTION::Up));
                transform->SetKinesis(true);
            }
            if(Game::event.key.keysym.sym == SDLK_s)
            {
                entity->RemoveInput(GetMovementVector(gbl::DIRECTION::Down));
                spriteComponent->Play("resources/Entities/Player/PLAYER_IDLE.png");
            }
            if(Game::event.key.keysym.sym == SDLK_a)
            {
                spriteComponent->Play("resources/Entities/Player/PLAYER_IDLE.png");
                entity->RemoveInput(GetMovementVector(gbl::DIRECTION::Left));
            }
            if(Game::event.key.keysym.sym == SDLK_d)
            {
                entity->RemoveInput(GetMovementVector(gbl::DIRECTION::Right));
                spriteComponent->Play("resources/Entities/Player/PLAYER_IDLE.png");
            }
        }
    }

    static Vector2D GetMovementVector(gbl::DIRECTION dir)
    {
        switch (dir) {
            case gbl::Up:
                return {0,-gbl::PLAYER::SPEED};
            case gbl::Down:
                return {0,gbl::PLAYER::SPEED};
            case gbl::Left:
                return {-gbl::PLAYER::SPEED,0};
            case gbl::Right:
                return {gbl::PLAYER::SPEED,0};
        }
        return {0,0};
    }
};


#endif //SLATFORMER_KEYBOARDCOMPONENT_H
