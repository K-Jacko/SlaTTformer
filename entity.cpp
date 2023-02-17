#include "Entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Entity::Entity(float p_x, float p_y, SDL_Texture *p_texture)
:x(p_x), y(p_y), texture(p_texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.h = 48;
    currentFrame.w = 48;
}
Entity::Entity()
{
    texture = NULL;
    x = 0;
    y = 0;
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.h = 48;
    currentFrame.w = 48;
}
float Entity::getX() { return x;}
void Entity::setX(float X) {x = X;}
float Entity::getY() {return y;}
void Entity::setY(float Y) {y = Y;}
SDL_Texture* Entity::getTexture() {return texture;}
void Entity::SetTexture(SDL_Texture* ptexture){texture = ptexture;}
SDL_Rect Entity::getCurrentFrame() {return currentFrame;}

