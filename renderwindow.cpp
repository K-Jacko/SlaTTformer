#include <iostream>
#include "RenderWindow.h"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window == NULL)
    {
        std::cout << "ERROR" << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char *p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if(texture == NULL)
        std::cout << "ERROR :: COULD NOT LOAD TEXTURE" << std::endl;

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_Entity)
{
    SDL_Rect src;
    src.x = p_Entity.getCurrentFrame().x;
    src.y = p_Entity.getCurrentFrame().y;
    src.w = p_Entity.getCurrentFrame().w;
    src.h = p_Entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_Entity.getX();
    dst.y = p_Entity.getY();
    dst.w = p_Entity.getCurrentFrame().w;
    dst.h = p_Entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_Entity.getTexture(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}



























//
// Created by Wake on 2/16/2023.
//
