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
    SDL_Rect dst;
    SDL_Rect currentFrame;
    SDL_Texture texture;
    Vector2f GetPosition();
    SDL_Texture* getTexture();
    SDL_Rect* getCurrentFrame();
    Collider collider;
    RenderWindow* window;
    SDL_Renderer* renderer;

    virtual void Init(RenderWindow* renderWindow,SDL_Texture* texture);
    void RenderEntity();
    void SetPosition(float px, float py);
    void SetTexture(SDL_Texture* ptexture);
    void SetCurrentFrame(SDL_Rect frame);
    void SetupCollider();
    void DebugLines(SDL_Rect* rect);
private:



};

#endif //SLATFORMER_ENTITY_H
