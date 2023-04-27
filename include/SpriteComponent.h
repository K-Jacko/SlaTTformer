//
// Created by Wake on 2/25/2023.
//

#ifndef SLATFORMER_SPRITECOMPONENT_H
#define SLATFORMER_SPRITECOMPONENT_H
#include "TransformComponent.h"
#include "TextureManager.h"
#include "Components.h"
#include "SDL.h"
#include "Animation.h"
#include <map>



class SpriteComponent : public Component
{

public:
    int frames, speed;
    int animationIndex = 0;
    std::map<const char*, Animation> animations;
    SDL_RendererFlip flip;
    SpriteComponent() = default;

    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }
    SpriteComponent(const char* path)
    {
        SetTexture(path);
    }
    SpriteComponent(const char* path, int x, int y)
    {
        SetTexture(path);
        srcRect.x = x;
        srcRect.y = y;
    }

    SpriteComponent(const char* path, int offsetX, int offsetY, bool t)
    {

        animated = t;
        srcRect.x = offsetX;
        srcRect.y = offsetY;

        Animation idle = Animation(0,10,100);
        Animation walk = Animation(1, 10, 100);
        Animation attack = Animation(2,6,100);
        Animation crouch = Animation(3,1,100);

        animations.emplace("resources/Character/_Idle.png", idle);
        animations.emplace("resources/Character/_Run.png", walk);
        animations.emplace("resources/Character/_Attack2NoMovement.png", attack);
        animations.emplace("resources/Character/_Crouch.png", crouch);

        Play("resources/Character/_Idle.png");
    }

    void SetTexture(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
    }

    void Init() override
    {
        if(!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }
    void Update() override
    {
        if(animated)
        {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }

        dstRect.x = static_cast<int>(transform->position.x);
        dstRect.y = static_cast<int>(transform->position.y);
        dstRect.w = transform->width * transform->scale;
        dstRect.h = transform->height * transform->scale;
        animationIndex++;
    }
    void Draw() override
    {
        TextureManager::Draw(texture, srcRect, dstRect);
    }

    void Play(const char* animationName)
    {
        SetTexture(animationName);
        frames = animations[animationName].frames;
        speed = animations[animationName].speed;
        animationIndex = animations[animationName].index;
    }

    void Stop()
    {
        Play("resources/Character/_Idle.png");
    }
private:
    TransformComponent* transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;

    bool animated = false;
};
#endif //SLATFORMER_SPRITECOMPONENT_H
