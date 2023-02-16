#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.h"

int main(int argc, char* args[]) {
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "ERROR" << SDL_GetError() << std::endl;
    }

    if(!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "ERROR" << SDL_GetError() << std::endl;
    }

    RenderWindow window("GAME", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("resources/Tileset.png");

    bool gameRunning = true;

    SDL_Event event;

    while(gameRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();
        window.render(grassTexture);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
