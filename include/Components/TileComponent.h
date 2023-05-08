#ifndef SLATFORMER_TILECOMPONENT_H
#define SLATFORMER_TILECOMPONENT_H
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "TextureManager.h"
#include "SDL.h"

class TileComponent : public Component
{
public:

    SDL_Rect tileRect;
    int tileID;
    const char* path;

    TileComponent();
    ~TileComponent() override
    {
        path = nullptr;
    };
    TileComponent(int x, int y, int id, int gridSize)
    {
        path = nullptr;
        tileID = id;

        switch (tileID) {
            case 0:
                path = "resources/Tileset.png";
                //Air
                srcRect.x = srcRect.y = 700;
                srcRect.w = dstRect.w = 48;
                srcRect.h = dstRect.h = 48;
                dstRect.x = x;
                dstRect.y = y;
                break;
            case 1:
                path = "resources/Tileset2.png";
                //Grass
                srcRect.x = 0;
                srcRect.y = 0;
                srcRect.w = 48;
                srcRect.h = 48;
                dstRect.w = dstRect.h = gridSize;
                dstRect.x = x;
                dstRect.y = y;
                break;
            case 2:
                path = "resources/Tileset.png";
                //Wall
                srcRect.x = srcRect.y = 0;
                dstRect.x = x;
                dstRect.y = y;
                srcRect.w = srcRect.h = 0;
                dstRect.w = dstRect.h = gridSize;
                break;
            case 3:
                path = "resources/Tileset.png";
//                //HalfBlock
//                dsrc.x = 48;
//                dsrc.y = 32;
//                ddst.x = ddst.y = 0;
//                dsrc.w = 32;
//                ddst.w = 48;
//                dsrc.h = ddst.h = 16;
                break;
        }

    }

    void Init() override
    {
        entity->addComponent<TransformComponent>((float)dstRect.x,(float)dstRect.y,dstRect.w,dstRect.h,1);
        if(!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();

        texture = TextureManager::LoadTexture(path);

    }

    void Update() override
    {
        dstRect.x = static_cast<int>(transform->GetPosition()->x);
        dstRect.y = static_cast<int>(transform->GetPosition()->y);
        dstRect.w = transform->GetWidth() * transform->GetScale();
        dstRect.h = transform->GetHeight() * transform->GetScale();
    }

    void Draw() override
    {
        TextureManager::Draw(texture, srcRect, dstRect);
    }

private:
    TransformComponent* transform;
    SpriteComponent* sprite;
    SDL_Texture* texture;
    SDL_Rect srcRect, dstRect;
};

#endif //SLATFORMER_TILECOMPONENT_H
