//
// Created by Wake on 2/20/2023.
//

#ifndef SLATFORMER_FLOORTILE_H
#define SLATFORMER_FLOORTILE_H
#include "Entity.h"
class FloorTile : Entity
{
public:
    FloorTile();
    void Init(RenderWindow* renderWindow,SDL_Texture &texture);
    void RenderEntity();
private:
};
#endif //SLATFORMER_FLOORTILE_H
