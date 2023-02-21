#include "../include/Entity.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../include/Math.h"

void Entity::Init(RenderWindow* renderer, SDL_Texture* texture)
{
    this->texture = texture;

    collider = Collider();

}

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
SDL_Texture* Entity::getTexture() {return texture;}
SDL_Rect* Entity::getCurrentFrame() {return &currentFrame;}
void Entity::SetPosition(float px, float py){position = *new Vector2f(px,py);}
void Entity::SetTexture(SDL_Texture* ptexture){texture = ptexture;}
void Entity::SetCurrentFrame(SDL_Rect frame){currentFrame = frame;}



