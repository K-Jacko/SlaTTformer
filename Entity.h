//
// Created by Wake on 2/17/2023.
//

#ifndef SLATFORMER_ENTITY_H
#define SLATFORMER_ENTITY_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.h"


class Entity
{
public:
    Entity();
    Entity(float p_x, float p_y, SDL_Texture* p_texture);
    Vector2f position;
    void SetPosition(float px, float py);
    Vector2f GetPosition();
    void SetTexture(SDL_Texture* ptexture);
    SDL_Texture* getTexture();
    SDL_Rect* getCurrentFrame();
    void SetCurrentFrame(SDL_Rect frame);
    void SetX(float x);
    void SetY(float y);
private:
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};

#endif //SLATFORMER_ENTITY_H
