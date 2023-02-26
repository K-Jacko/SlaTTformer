#include "GameObject.h"
#include "TextureManager.h"

//GameObject::GameObject(const char *textureSheet, Vector2f* _position)
//:objectTexture(TextureManager::LoadTexture(textureSheet)), position(_position)
//{
//
//}

void GameObject::Update()
{
    position.x++;
    position.y++;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 120;
    srcRect.h = 80;

    dstRect.x = position.x;
    dstRect.y = position.y;
    dstRect.w = srcRect.w * 2;
    dstRect.h = srcRect.h * 2;

}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &dstRect);
}