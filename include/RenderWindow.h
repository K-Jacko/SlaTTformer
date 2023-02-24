//
// Created by Wake on 2/16/2023.
//

#ifndef SLATFORMER_RENDERWINDOW_H
#define SLATFORMER_RENDERWINDOW_H
#include "Game.h"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    int getRefreshRate();
    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();

    void cleanUp();
    void clear();
    void renderEntity(SDL_Texture &texture, SDL_Rect src, SDL_Rect dst);
    void renderBackground(SDL_Texture &texture);
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif //SLATFORMER_RENDERWINDOW_H
