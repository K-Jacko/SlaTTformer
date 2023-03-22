#ifndef SLATFORMER_TILECOMPONENT_H
#define SLATFORMER_TILECOMPONENT_H
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
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
    TileComponent(int x, int y, int id)
    {
        tileRect.x = x;
        tileRect.y = y;

        tileID = id;

        switch (tileID) {
            case 0:
                path = "resources/Tileset.png";
                //Air
                tileRect.w = 10;
                tileRect.h = 10;
                break;
            case 1:
                path = "resources/Tileset2.png";
                //Grass
                tileRect.w = 32;
                tileRect.h = 32;
//                src.x = src.y = 0;
//                src.w = dst.w = 48;
//                src.h = dst.h = 48;
//                dst.x = dst.y = 0;
                break;
            case 2:
                path = "resources/Tileset.png";
//                Wall
//                wsrc.x = 48;
//                wsrc.y = 48;
//                wdst.x = wdst.y = 0;
//                wsrc.w = 32;
//                wdst.w = 48;
//                wsrc.h = wdst.h = 46;
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
        entity->addComponent<TransformComponent>((float)tileRect.x,(float)tileRect.y,tileRect.w,tileRect.h,1);

        entity->addComponent<SpriteComponent>(path);
    }

private:

};

#endif //SLATFORMER_TILECOMPONENT_H
