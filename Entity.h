//
// Created by Wake on 2/17/2023.
//

#ifndef SLATFORMER_ENTITY_H
#define SLATFORMER_ENTITY_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Entity
{
public:
    Entity();
    Entity(float p_x, float p_y, SDL_Texture* p_texture);
    float getX();
    float getY();
    void setX(float X);
    void setY(float Y);
    void SetTexture(SDL_Texture* ptexture);
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};

#endif //SLATFORMER_ENTITY_H
