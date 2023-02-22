#include "Character.h"
#include "Entity.h"

Character::Character()
{

}



void Character::Init(RenderWindow* renderer, SDL_Texture* texture)
{


    this->SetCurrentFrame(this->dst);
    this->SetPosition(70,619);
}

void Character::UpdatePosition(SDL_Event event)
{

    switch (event.key.keysym.sym) {
        case SDLK_w:
            position.y -= characterSpeed;
            break;
        case SDLK_s:
            position.y += characterSpeed;
            break;
        case SDLK_a:
            position.x -= characterSpeed;
            break;
        case SDLK_d:
            position.x += characterSpeed;
            break;
    }
}
