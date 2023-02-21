//
// Created by Wake on 2/20/2023.
//
#include "Entity.h"
#include "FloorTile.h"

FloorTile::FloorTile(SDL_Texture* _texture)
{
    this->SetTexture(_texture);
    this->SetPosition(0,0);
}