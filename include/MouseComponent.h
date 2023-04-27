//
// Created by Wake on 4/24/2023.
//

#ifndef SLATFORMER_MOUSECOMPONENT_H
#define SLATFORMER_MOUSECOMPONENT_H
#include "ECS.h"
#include "Game.h"
#include "Components.h"

class MouseComponent : public Component
{
public:
    SpriteComponent *spriteComponent;

    void Init() override
    {
        if(!entity->hasComponent<SpriteComponent>())
        {
            entity->addComponent<SpriteComponent>();
        }
        spriteComponent = &entity->getComponent<SpriteComponent>();
    }

    void Update() override
    {
        switch (Game::event.type) {
            case SDL_MOUSEBUTTONDOWN:
                std::cout << Game::mousePosition << std::endl;
                break;
            case SDL_MOUSEBUTTONUP:
                break;
            case SDL_MOUSEMOTION:
                Game::mousePosition.x = Game::event.motion.x / Game::GridSize;
                Game::mousePosition.y = Game::event.motion.y / Game::GridSize;
                break;
        }
    }

};
#endif //SLATFORMER_MOUSECOMPONENT_H
