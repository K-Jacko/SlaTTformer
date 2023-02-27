//
// Created by Wake on 2/25/2023.
//

#ifndef SLATFORMER_POSITION_H
#define SLATFORMER_POSITION_H
#include "Components.h"
#include "ECS.h"
#include "Math.h"

struct TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D velocity;

    int height, width = 80;
    int scale = 1;

    int speed = 2;

    ~TransformComponent() override
    {
        speed = 0;
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

    void Init() override
    {
        velocity.Zero();
    }

    void Update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
        //std::cout << velocity << std::endl;
    }

};
#endif //SLATFORMER_POSITION_H
