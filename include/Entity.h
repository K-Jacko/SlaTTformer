//
// Created by Wake on 2/17/2023.
//

#ifndef SLATFORMER_ENTITY_H
#define SLATFORMER_ENTITY_H
#include <SDL.h>
#include <SDL_image.h>
#include <chrono>
#include "Math.h"
#include "Collider.h"
#include "RenderWindow.h"


class Entity
{
public:
    Entity();
    Entity(float p_x, float p_y, SDL_Texture* p_texture);
    Vector2f position;
    Vector2f GetPosition();
    SDL_Texture* getTexture();
    SDL_Rect* getCurrentFrame();
    Collider collider;
    void SetPosition(float px, float py);
    void SetTexture(SDL_Texture* ptexture);
    void SetCurrentFrame(SDL_Rect frame);
    virtual void Init(RenderWindow* renderer, SDL_Texture* texture);

private:
    SDL_Rect currentFrame;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    void SetupRenderer();
};

#endif //SLATFORMER_ENTITY_H
