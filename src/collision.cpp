#include "Collision.h"
#include "Components/ColliderComponent.h"
#include "Global.h"


CollisionResult Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB)
{
    if(colA.tag == "Player")
    {
        SDL_Rect A = colA.collider;
        SDL_Rect B = colB.collider;
        CollisionResult result = { false, {0,0,0,0},CollisionDirection::None};

        int modx = A.x + colA.transform->GetVelocity()->x;
        int mody = A.y + colA.transform->GetVelocity()->y;
        SDL_Rect expandedA = { modx, mody, A.w, A.h };

        if (SDL_HasIntersection(&expandedA, &B)) {
            result.collides = true;

            int dx1 = B.x - (A.x + A.w);
            int dx2 = B.x + B.w - A.x;
            int dy1 = B.y - (A.y + A.h);
            int dy2 = B.y + B.h - A.y;

            if(colA.tag == colB.tag)
            {
                result.direction = CollisionDirection::None;
                return result;
            }

            if (std::abs(dx1) < std::abs(dx2) && std::abs(dx1) < std::abs(dy1) && std::abs(dx1) < std::abs(dy2)) {
                colA.transform->SetXPositionDown(gbl::PLAYER::COLLISION_BOUNCE);
                colA.transform->SetVelocity(Vector2D(0,0));
                result.direction = CollisionDirection::Left;
            } else if (std::abs(dx2) < std::abs(dx1) && std::abs(dx2) < std::abs(dy1) && std::abs(dx2) < std::abs(dy2)) {
                colA.transform->SetXPositionUp(gbl::PLAYER::COLLISION_BOUNCE);
                colA.transform->SetVelocity(Vector2D(0,0));
                result.direction = CollisionDirection::Right;
            } else if (std::abs(dy1) < std::abs(dy2)) {
                colA.transform->SetYPositionDown(gbl::PLAYER::COLLISION_BOUNCE);
                result.direction = CollisionDirection::Up;
                colA.transform->SetKinesis(false);
            } else {
                colA.transform->SetYPositionUp(gbl::PLAYER::COLLISION_BOUNCE);
                colA.transform->SetVelocity(Vector2D(0,0));
                result.direction = CollisionDirection::Down;
            }
        }
        return result;
    }
    else {
        SDL_Rect A = colA.collider;
        SDL_Rect B = colB.collider;
        CollisionResult result = { false, {0,0,0,0},CollisionDirection::None};

        int modx = A.x + colA.transform->GetVelocity()->x;
        int mody = A.y + colA.transform->GetVelocity()->y;
        SDL_Rect expandedA = { modx, mody, A.w, A.h };

        if (SDL_HasIntersection(&expandedA, &B)) {
            result.collides = true;

            int dx1 = B.x - (A.x + A.w);
            int dx2 = B.x + B.w - A.x;
            int dy1 = B.y - (A.y + A.h);
            int dy2 = B.y + B.h - A.y;

            if(colA.tag == colB.tag)
            {
                result.direction = CollisionDirection::None;
                return result;
            }

            if (std::abs(dx1) < std::abs(dx2) && std::abs(dx1) < std::abs(dy1) && std::abs(dx1) < std::abs(dy2)) {
                colA.transform->SetXPositionDown(gbl::PLAYER::COLLISION_BOUNCE);
                colA.transform->SetVelocity(Vector2D(0,0));
                result.direction = CollisionDirection::Left;
            } else if (std::abs(dx2) < std::abs(dx1) && std::abs(dx2) < std::abs(dy1) && std::abs(dx2) < std::abs(dy2)) {
                colA.transform->SetXPositionUp(gbl::PLAYER::COLLISION_BOUNCE);
                colA.transform->SetVelocity(Vector2D(0,0));
                result.direction = CollisionDirection::Right;
            } else if (std::abs(dy1) < std::abs(dy2)) {
                colA.transform->SetYPositionDown(gbl::PLAYER::COLLISION_BOUNCE);
                result.direction = CollisionDirection::Up;
                if(colB.tag != "Player")
                {
                    colA.transform->SetKinesis(false);
                    colA.transform->SetVelocity(Vector2D(0,0));
                    colA.transform->SetForce(0);
                }
            } else {
                colA.transform->SetYPositionUp(gbl::PLAYER::COLLISION_BOUNCE);

                result.direction = CollisionDirection::Down;
            }
        }
        return result;
    }

}
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

