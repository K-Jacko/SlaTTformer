#include "Entity.h"
#include "FloorTile.h"

FloorTile::FloorTile()
{
    texture = NULL;
    position = *new Vector2f();
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.h = 48;
    currentFrame.w = 48;
}
//void FloorTile::Init(RenderWindow* renderWindow,SDL_Texture &texture)
//{
//    this->texture = texture;
//    this->window = renderWindow;
//    SetupCollider();
//}
//
//void FloorTile::RenderEntity()
//{
//    window->renderEntity(texture, &currentFrame,&dst);
//}