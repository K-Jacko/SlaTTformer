//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_GAMEOBJECT_H
#define SLATFORMER_GAMEOBJECT_H
#include "Game.h"
class GameObject
{
public:
    GameObject(const char* textureSheet, Vector2f* position);
    ~GameObject();

    void Update();
    void Render();
private:
    Vector2f position;
    SDL_Texture* objectTexture;
    SDL_Rect srcRect, dstRect;
};
#endif //SLATFORMER_GAMEOBJECT_H
