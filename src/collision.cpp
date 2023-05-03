#include "Collision.h"
#include "Components/ColliderComponent.h"


CollisionResult Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB, const Vector2D& Avel, const Vector2D& Bvel)
{
    SDL_Rect A = colA.collider;
    SDL_Rect B = colB.collider;
    CollisionResult result = { false, {0,0,0,0},CollisionDirection::None};

    int modx = A.x + colA.transform->velocity.x;
    int mody = A.y + colA.transform->velocity.y;
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
            //colA.transform->kinematic = 1;
            return result;
        }

        if (std::abs(dx1) < std::abs(dx2) && std::abs(dx1) < std::abs(dy1) && std::abs(dx1) < std::abs(dy2)) {
            colA.transform->position.x -= 0.1f;
            colA.transform->velocity.Zero();
            result.direction = CollisionDirection::Left;
            std::cout << "Left" << colB.tag << std::endl;
        } else if (std::abs(dx2) < std::abs(dx1) && std::abs(dx2) < std::abs(dy1) && std::abs(dx2) < std::abs(dy2)) {
            colA.transform->position.x += 0.1f;
            colA.transform->velocity.Zero();
            result.direction = CollisionDirection::Right;
            std::cout << "Right" << colB.tag << std::endl;
        } else if (std::abs(dy1) < std::abs(dy2)) {
            colA.transform->position.y -= 1.0f;
            //colA.transform->velocity.Zero();
            result.direction = CollisionDirection::Up;
            colA.transform->kinematic = 0;
            std::cout << "Up" << colB.tag << std::endl;
        } else {
            colA.transform->position.y += 1;
            colA.transform->velocity.Zero();
            result.direction = CollisionDirection::Down;
            std::cout << "Down" << colB.tag << std::endl;
        }
    }
    return result;
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

