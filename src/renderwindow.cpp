#include <iostream>
#include "RenderWindow.h"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h)
{

}

int RenderWindow::getRefreshRate()
{
    return 1;
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

void RenderWindow::renderEntity(SDL_Texture &texture, SDL_Rect src, SDL_Rect dst)
{
//    SDL_Rect dst;
//    dst.x = entity.GetPosition().x;
//    dst.y = entity.GetPosition().y;
//    dst.w = entity.getCurrentFrame()->w;
//    dst.h = entity.getCurrentFrame()->h;

//    SDL_RenderCopy(renderer, texture, src, dst);
}

void RenderWindow::renderBackground(SDL_Texture &texture)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 928;
    src.h = 793;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 1280;
    dst.h = 720;

    SDL_RenderCopy(renderer, &texture, &src, &dst);

}

//void RenderWindow:renderCharacter(Entity& entity)
//{
//    SDL_Rect dst;
//    dst.x = entity.GetPosition().x;
//    dst.y = entity.GetPosition().y;
//    dst.w = 100;
//    dst.h = 100;
//
//    SDL_RenderCopy(renderer, entity.getTexture(), entity.getCurrentFrame(), &dst);
//}

SDL_Renderer* RenderWindow::GetRenderer(){  return SDL_GetRenderer(window);}
SDL_Window* RenderWindow::GetWindow() {return window;}

void RenderWindow::display(){   SDL_RenderPresent(renderer);}



























//
// Created by Wake on 2/16/2023.
//
