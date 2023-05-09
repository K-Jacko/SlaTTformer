//
// Created by Wake on 4/24/2023.
//

#ifndef SLATFORMER_MOUSECOMPONENT_H
#define SLATFORMER_MOUSECOMPONENT_H
#include "ECS.h"
#include "Game.h"
#include "StateMachines/PlayerStateMachine.h"

class MouseComponent : public Component
{
public:
    MouseComponent() = default;

    void Init() override
    {
        if(!entity->hasComponent<PlayerStateMachine>())
        {
            entity->addComponent<PlayerStateMachine>();
        }
    }

    void Update() override
    {
        switch (Game::event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if(Game::event.button.button == SDL_BUTTON_LEFT)
                {
                    entity->AddInput(1);
                }
                if(Game::event.button.button == SDL_BUTTON_RIGHT)
                {
                    entity->AddInput(2);

                }
                break;
            case SDL_MOUSEBUTTONUP:
                if(Game::event.button.button == SDL_BUTTON_LEFT)
                {
                    entity->RemoveInput(1);
                }
                if(Game::event.button.button == SDL_BUTTON_RIGHT)
                {
                    entity->RemoveInput(2);
                }
                break;
            case SDL_MOUSEMOTION:
                SetMousePosition(mousePosition.x / gbl::GAME::CELL_SIZE - Camera::Instance().view.x, mousePosition.y / gbl::GAME::CELL_SIZE - Camera::Instance().view.y);
                break;
        }
    }

    Vector2D GetMousePosition(){return mousePosition;}
    void SetMousePosition(float _x, float _y){mousePosition.x = _x; mousePosition.y = _y;}

private:
    Vector2D mousePosition;

};
#endif //SLATFORMER_MOUSECOMPONENT_H
