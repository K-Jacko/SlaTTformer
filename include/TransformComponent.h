//
// Created by Wake on 2/25/2023.
//

#ifndef SLATFORMER_POSITION_H
#define SLATFORMER_POSITION_H
#include "ECS.h"
#include "Math.h"
#include "Game.h"

struct TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D velocity = Vector2D(0,0);
    float mass = 1;

    int height, width = 80;
    int scale = 1;

    float speed = 500;

    int kinematic = 0;



    ~TransformComponent() override
    {
        speed = 0.0;
        velocity.Zero();
    }

    TransformComponent()
    {
        position.Zero();
        height = width = 100;
    }
    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
        height = width = 100;
    }
    TransformComponent(float x, float y, float w, float h, float s)
    {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = s;
    }
    TransformComponent(float x, float y, float w, float h, float s, int k)
    :kinematic(k)
    {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = s;
        velocity = Vector2D(0.0f,0.0f);
    }

    void Init() override
    {
        velocity.Zero();
    }

    void Update() override
    {
        position.x += velocity.x * speed * Game::deltaTime;
        position.y += velocity.y * speed * Game::deltaTime;
        if(kinematic == 1)
        {
            Gravity();
        }
        //std::cout << velocity << "  " << speed << std::endl;
    }

    void Gravity()
    {
        velocity.y += 9.81f * mass * Game::deltaTime;
    }


};
#endif //SLATFORMER_POSITION_H
