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
    ~TransformComponent() override
    = default;
    TransformComponent()
    {
        position.Zero();
        height = width = 100;
        scale = mass = 1;
    }
    TransformComponent(float x, float y)
            :position(Vector2D(x,y))
    {
        height = width = 32;
        scale = mass = 0;
    }
    TransformComponent(float x, float y, float w, float h, float s)
            :position(Vector2D(x,y)),width(w),height(h),scale(s){mass = 1;}
    TransformComponent(float x, float y, float w, float h, float s, bool k)
            :position(Vector2D(x,y)),width(w),height(h),scale(s),kinematic(k){mass = 1;}
    TransformComponent(float x, float y, float w, float h, float s, bool k, int m)
            :position(Vector2D(x,y)),width(w),height(h),scale(s),kinematic(k),mass(m){}


    void Init() override
    {
    }

    void Update() override
    {
        if(!entity->GetKeyInputs().empty())
        {
            for (const auto& v : entity->GetKeyInputs())
            {
                velocity += *v;
            }
        }
        if(arc)
        {
            velocity.x = initialVelocityX;
            velocity.y = initialVelocityY - (gbl::GAME::GRAVITY * Game::deltaTime);
            position.x = position.x + (velocity.x * Game::deltaTime) + (0.5f * gbl::GAME::GRAVITY * Game::deltaTime * Game::deltaTime);
            position.y = position.y + (velocity.y * Game::deltaTime) + (0.5f * gbl::GAME::GRAVITY * Game::deltaTime * Game::deltaTime);
        }
        if(kinematic)
            velocity.y += gbl::GAME::GRAVITY * mass * Game::deltaTime;
        if(velocity.x != 0.0f)
            velocity.x = std::clamp(velocity.x, -gbl::PLAYER::MAX_HORIZONTAL_SPEED, gbl::PLAYER::MAX_HORIZONTAL_SPEED);
        if(velocity.y != 0.0f)
            velocity.y = std::clamp(velocity.y, -gbl::GAME::MAX_VERTICAL_SPEED, gbl::GAME::MAX_VERTICAL_SPEED);
        velocity += acceleration;
        velocity += force;
        velocity.x += friction * velocity.x;
        velocity.y += friction * velocity.y;
        position += velocity;

        position.x -= Camera::Instance().view.x;
    }

    void SetArc(gbl::Arc _arc)
    {
        // Convert angle to radians
        float radians = _arc.angle * (M_PI / 180);
        // Calculate initial velocity components
        initialVelocityX = _arc.launchSpeed * std::cos(radians);
        initialVelocityY = _arc.launchSpeed * std::sin(radians);

        // Set initial velocity
        velocity.x = initialVelocityX;
        velocity.y = initialVelocityY;

        arc = true;

    }

    void SetForce(int forceDirection){force.x = forceDirection;}
    int GetWidth() const {return width;}
    void SetWidth(int _width){width = _width;}
    int GetHeight() const {return height;}
    void SetHeight(int _height){height = _height;}
    int GetScale() const {return scale;}
    void SetScale(int _scale){scale = _scale;}
    Vector2D* GetPosition(){return &position;}
    void SetPosition(Vector2D _position){position = _position;}
    void SetYPositionUp(float _y){ position.y += _y;}
    void SetYPositionDown(float _y){ position.y -= _y;}
    void SetXPositionUp(float _x){ position.x += _x;}
    void SetXPositionDown(float _x){ position.x -= _x;}
    Vector2D* GetVelocity(){return &velocity;}
    void SetVelocity(Vector2D _velocity){velocity = _velocity;}
    bool* GetKinesis(){return &kinematic;}
    void SetKinesis(bool _kinesis){kinematic = _kinesis;}

private:
    int height, width;
    Vector2D position;
    Vector2D force;
    Vector2D velocity;
    Vector2D acceleration;
    float initialVelocityX,initialVelocityY;
    float friction = -0.25f;
    bool kinematic = false;
    bool arc = false;
    int scale, mass;



};

#endif //SLATFORMER_POSITION_H
