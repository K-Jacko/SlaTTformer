//
// Created by Wake on 2/25/2023.
//

#ifndef SLATFORMER_POSITION_H
#define SLATFORMER_POSITION_H
#include "ECS.h"
#include "Math.h"
#include "Game.h"
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

    float speed = 2.0f;
    float friction = -0.15f;
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
        acceleration.Zero();

        float length = atan2(acceleration.y, acceleration.x);
        velocity.x = cos(speed) * length;
        velocity.y = sin(speed) * length;

        auto length2 =  sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        velocity.x = cos(-3.14159265358979323846 / 2) * length2;
        velocity.y = sin(-3.14159265358979323846 / 2) * length2;


    }

    void Update() override
    {
        //acceleration.x += 1;

//        position.x += velocity.x * speed * Game::deltaTime;
//        position.y += velocity.y * speed * Game::deltaTime;
        velocity += acceleration;
        if(kinematic == 1)
        {


            Gravity();

//            if(acceleration.x != 0.0f && acceleration.y != 0.0f)
//            {
//                acceleration *= 0.707f;
//            }
//            acceleration.x *= Game::deltaTime * speed;
//            acceleration.y *= Game::deltaTime * speed;
//

//
//            //position.x = position.x + Game::deltaTime;
//            position.x += Game::deltaTime * velocity.x + Game::deltaTime * Game::deltaTime * 0.5f * acceleration.x;
//            position.y += Game::deltaTime * velocity.y + Game::deltaTime * Game::deltaTime * 0.5f * acceleration.y;
//
//            velocity.x += Game::deltaTime * acceleration.x;
//            velocity.y += Game::deltaTime * acceleration.y;
//
//            acceleration.Zero();
            //std::cout << position << "  " << acceleration << "  " << velocity << std::endl;
        }
        velocity.x += friction * velocity.x;
        velocity.y += friction * velocity.y;
        //velocity.x = std::clamp(velocity.x, -1.0f, 1.0f);
//       d
        position += velocity;
    }


    void Gravity()
    {
        velocity.y += 9.81f * mass * Game::deltaTime;
        //std::cout << position << "  " << acceleration << "  " << velocity << std::endl;
        //std::cout << position << "  " << acceleration << std::endl;
    }


};
#endif //SLATFORMER_POSITION_H
