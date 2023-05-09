#include "Collision.h"
#include "Components/ColliderComponent.h"
#include "Global.h"
#include "Components/SpriteComponent.h"


gbl::CollisionResult Collision::AABBPlayer(const ColliderComponent& colA, const ColliderComponent& colB)
{
    SDL_Rect A = colA.collider;
    SDL_Rect B = colB.collider;
    gbl::CollisionResult result = { false, {0,0,0,0},gbl::CollisionDirection::None};

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
            result.direction = gbl::CollisionDirection::None;
            return result;
        }
        if(colB.tag == "Bait")
        {
            result.direction = gbl::CollisionDirection::None;
            return result;
        }
        if(colB.tag == "!") {
            result.direction = gbl::CollisionDirection::None;
            return result;
        }
        if(colB.tag == "Fish")
        {
            result.direction = gbl::CollisionDirection::None;
            //TODO::ADD TO SCORE SYSTEM
            colB.entity->getComponent<SpriteComponent>().IsActive(false);
            return result;
        }

        if (std::abs(dx1) < std::abs(dx2) && std::abs(dx1) < std::abs(dy1) && std::abs(dx1) < std::abs(dy2)) {
            colA.transform->SetXPositionDown(gbl::PLAYER::COLLISION_BOUNCE);
            colA.transform->SetVelocity(Vector2D(0,0));
            std::cout << "Left" << colA.tag << " : " << colB.tag <<std::endl;
            result.direction = gbl::CollisionDirection::Left;
        } else if (std::abs(dx2) < std::abs(dx1) && std::abs(dx2) < std::abs(dy1) && std::abs(dx2) < std::abs(dy2)) {
            colA.transform->SetXPositionUp(gbl::PLAYER::COLLISION_BOUNCE);
            colA.transform->SetVelocity(Vector2D(0,0));
            std::cout << "Rgt" << colA.tag << " : " << colB.tag << std::endl;
            result.direction = gbl::CollisionDirection::Right;
        } else if (std::abs(dy1) < std::abs(dy2)) {
            colA.transform->SetYPositionDown(gbl::PLAYER::COLLISION_BOUNCE);
            std::cout << "Up" << colA.tag << " : "<< colB.tag << std::endl;
            result.direction = gbl::CollisionDirection::Up;
            colA.transform->SetKinesis(false);
        } else {
            colA.transform->SetYPositionUp(gbl::PLAYER::COLLISION_BOUNCE);
            colA.transform->SetVelocity(Vector2D(0,0));
            std::cout << "Dwn" << colA.tag << " : " << colB.tag << std::endl;
            result.direction = gbl::CollisionDirection::Down;
        }
    }
    return result;
}

gbl::CollisionResult Collision::AABBFL(const ColliderComponent& colA, const ColliderComponent& colB)
{
    gbl::CollisionResult result{};
    if(colA.tag.empty())
    {
        result.direction = gbl::CollisionDirection::None;
        return result;
    }
    if(colA.tag == "")
    {
        result.direction = gbl::CollisionDirection::None;
        return result;
    }
    if(colB.tag.empty())
    {
        result.direction = gbl::CollisionDirection::None;
        return result;
    }
    if(colB.tag == "")
    {
        result.direction = gbl::CollisionDirection::None;
        return result;
    }
    if (colB.tag == "Bait")
    {
        result.direction = gbl::CollisionDirection::None;
        return result;
    }
    if(colB.tag == "Player" || colA.tag == "Player") {
        result.direction = gbl::CollisionDirection::None;
        return result;
    }
    if(colB.tag == "Fish") {
        result.direction = gbl::CollisionDirection::None;
        return result;
    }
    if(colB.tag == "!") {
        result.direction = gbl::CollisionDirection::None;
        return result;
    }
    SDL_Rect A = colA.collider;
    SDL_Rect B = colB.collider;


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
            result.direction = gbl::CollisionDirection::None;
            return result;
        }

        if (std::abs(dx1) < std::abs(dx2) && std::abs(dx1) < std::abs(dy1) && std::abs(dx1) < std::abs(dy2)) {
            colA.transform->SetVelocity(Vector2D(0,0));
            result.direction = gbl::CollisionDirection::Left;
        } else if (std::abs(dx2) < std::abs(dx1) && std::abs(dx2) < std::abs(dy1) && std::abs(dx2) < std::abs(dy2)) {
            colA.transform->SetVelocity(Vector2D(0,0));
            result.direction = gbl::CollisionDirection::Right;
        } else if (std::abs(dy1) < std::abs(dy2)) {
            result.direction = gbl::CollisionDirection::Up;
            colA.transform->CompleteZero();
        } else {
            result.direction = gbl::CollisionDirection::Down;
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

