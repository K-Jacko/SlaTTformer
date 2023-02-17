//
// Created by Wake on 2/16/2023.
//

#ifndef SLATFORMER_RENDERWINDOW_H
#define SLATFORMER_RENDERWINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.h"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();
    void clear();
    void render(Entity& p_texture);
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif //SLATFORMER_RENDERWINDOW_H
