//
// Created by Wake on 2/25/2023.
//

#ifndef SLATFORMER_SPRITECOMPONENT_H
#define SLATFORMER_SPRITECOMPONENT_H
#include "TransformComponent.h"
#include "TextureManager.h"
#include "Components.h"
#include "SDL.h"



class SpriteComponent : public Component
{

public:
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

    void SetTexture(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
        srcRect.x = srcRect.y = 0;
    }

    void Init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }
    void Update() override
    {
        dstRect.x = (int)transform->position.x;
        dstRect.y =  (int)transform->position.y;
        dstRect.w = transform->width * transform->scale;
        dstRect.h = transform->height * transform->scale;
    }
    void Draw() override
    {
        TextureManager::Draw(texture, srcRect, dstRect);
    }
private:
    TransformComponent* transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;
};
#endif //SLATFORMER_SPRITECOMPONENT_H
