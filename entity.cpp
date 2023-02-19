#include "Entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.h"


Entity::Entity(float p_x, float p_y, SDL_Texture *p_texture)
:position(*new Vector2f(p_x,p_y)), texture(p_texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.h = 48;
    currentFrame.w = 48;
}
Entity::Entity()
{
    texture = NULL;
    position = *new Vector2f();
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.h = 48;
    currentFrame.w = 48;
}
Vector2f Entity::GetPosition(){return position;}
void Entity::SetPosition(float px, float py){position = *new Vector2f(px,py);}
void Entity::SetX(float x){position.x = x;}
void Entity::SetY(float y){position.y = y;}
SDL_Texture* Entity::getTexture() {return texture;}
void Entity::SetTexture(SDL_Texture* ptexture){texture = ptexture;}
SDL_Rect* Entity::getCurrentFrame() {return &currentFrame;}
void Entity::SetCurrentFrame(SDL_Rect frame){currentFrame = frame;}

