#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Math.h"
#include "Collider.h"

void Entity::Init(RenderWindow* renderWindow, SDL_Texture* texture)
{
    this->texture = texture;
    this->window = renderWindow;
    SetupCollider();
}

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture)
{
    Vector2f pos;
    position = pos;
    texture = p_texture;
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


void Entity::SetupCollider()
{
    dst.x = 0;
    dst.y = 0;
    dst.h = 100;
    dst.w = 100;
    collider = Collider(&dst);
}

void Entity::RenderEntity()
{
    window->renderEntity(texture, &currentFrame,&dst);
}

void Entity::DebugLines(SDL_Rect* rect)
{
//TODO : This cant just happen one frame. Must move rendering to main loop
SDL_Window* window = SDL_CreateWindow("SDL2 Line", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

SDL_RenderDrawRect(renderer,rect);
}



//dst how big and position
//src the frame of pix the img is in
