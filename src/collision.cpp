#include "Collision.h"
#include "ColliderComponent.h"

bool Collision::AABB(const SDL_Rect &A, const SDL_Rect &B)
{
    if(A.x + A.w >= B.x &&
    B.x + B.w >= A.x &&
    A.y + A.h >= B.y &&
    B.y + B.h >= A.y)
    {
        return true;
    }
    return false;
}

bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB)
{
    if(AABB(colA.collider,colB.collider))
    {
        std::cout << colA.tag << " hit: " << colB.tag << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}