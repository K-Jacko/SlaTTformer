//
// Created by Wake on 4/24/2023.
//

#ifndef SLATFORMER_MOUSECOMPONENT_H
#define SLATFORMER_MOUSECOMPONENT_H
#include "ECS.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "GridComponent.h"

class MouseComponent : public Component
{
public:
    SpriteComponent *spriteComponent;
    GridComponent *gridComponent;

    void Init() override
    {
        if(!entity->hasComponent<SpriteComponent>())
        {
            entity->addComponent<SpriteComponent>();
        }
        spriteComponent = &entity->getComponent<SpriteComponent>();

        if(!entity->hasComponent<GridComponent>())
        {
            entity->addComponent<GridComponent>();
        }
        gridComponent = &entity->getComponent<GridComponent>();
    }

    void Update() override
    {
        switch (Game::event.type) {
            case SDL_MOUSEBUTTONDOWN:
                std::cout << Game::mousePosition << gridComponent->Get1DIndex(Game::mousePosition.x,
                                                                              Game::mousePosition.y) << std::endl;
                break;
            case SDL_MOUSEBUTTONUP:
                break;
            case SDL_MOUSEMOTION:
                Game::mousePosition.x = Game::event.motion.x / gbl::GAME::CELL_SIZE;
                Game::mousePosition.y = Game::event.motion.y / gbl::GAME::CELL_SIZE;
                break;
        }
    }

};
#endif //SLATFORMER_MOUSECOMPONENT_H
