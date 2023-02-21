//
// Created by Wake on 2/19/2023.
//
#include "../include/Character.h"
#include "../include/Entity.h"

Character::Character() {}

void Character::Init(RenderWindow* renderer, SDL_Texture* texture)
{

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 120;
    dst.h = 80;
    this->SetCurrentFrame(dst);
    this->SetPosition(70,619);
}

void Character::UpdatePosition(SDL_Event event){
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
