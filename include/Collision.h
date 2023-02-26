//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_COLLISION_H
#define SLATFORMER_COLLISION_H
#include "SDL.h"

class Collision
{
public:
    static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
};
#endif //SLATFORMER_COLLISION_H
