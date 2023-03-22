//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_COLLISION_H
#define SLATFORMER_COLLISION_H
#include "SDL.h"

class ColliderComponent;

class Collision
{
public:
    static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};
#endif //SLATFORMER_COLLISION_H
