//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_COLLISION_H
#define SLATFORMER_COLLISION_H
#include "SDL.h"
#include "Math.h"

class ColliderComponent;
enum class CollisionDirection {
    None,
    Up,
    Down,
    Left,
    Right
};
//TODO:Do this
struct CollisionResult {
    bool collides;
    SDL_Rect intersection;
    CollisionDirection direction; // 0: top, 1: right, 2: bottom, 3: left
};


class Collision
{
public:
    static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
    //static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
    static CollisionResult AABB(const ColliderComponent& colA, const ColliderComponent& colB);

};


#endif //SLATFORMER_COLLISION_H
