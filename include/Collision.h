//
// Created by Wake on 2/26/2023.
//

#ifndef SLATFORMER_COLLISION_H
#define SLATFORMER_COLLISION_H
#include "SDL.h"
#include "Math.h"
#include "Global.h"

class ColliderComponent;

//TODO:Do this



class Collision
{
public:
    static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
    //static bool AABBPlayer(const ColliderComponent& colA, const ColliderComponent& colB);
    static gbl::CollisionResult AABBFL(const ColliderComponent& colA, const ColliderComponent& colB);
    static gbl::CollisionResult AABBPlayer(const ColliderComponent& colA, const ColliderComponent& colB);

};


#endif //SLATFORMER_COLLISION_H
