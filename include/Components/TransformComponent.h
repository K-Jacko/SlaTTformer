//
// Created by Wake on 2/25/2023.
//

#ifndef SLATFORMER_POSITION_H
#define SLATFORMER_POSITION_H
#include "ECS.h"
#include "Math.h"
#include "Game.h"
#include "Global.h"
#include <cmath>

struct TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;

    float mass = 1;

    int height, width = 80;
    int scale = 1;
    float friction = -0.25f;
    int kinematic = 0;



    ~TransformComponent() override
    {
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
    }

    void Init() override
    {
//        acceleration.Zero();
//
//        float length = atan2(acceleration.y, acceleration.x);
//        velocity.x = cos(speed) * length;
//        velocity.y = sin(speed) * length;
//
//        auto length2 =  sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
//        velocity.x = cos(-3.14159265358979323846 / 2) * length2;
//        velocity.y = sin(-3.14159265358979323846 / 2) * length2;


    }

    void Update() override
    {
        velocity += acceleration;
        if(kinematic == 1)
        {
            Gravity();
        }
        velocity.x += friction * velocity.x;
        velocity.y += friction * velocity.y;
        position += velocity;
        // std::cout << velocity << std::endl;

    }


    void Gravity()
    {
        velocity.y += gbl::GAME::GRAVITY * mass * Game::deltaTime;
    }


};
#endif //SLATFORMER_POSITION_H
