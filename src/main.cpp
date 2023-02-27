#include <iostream>
#include <SDL.h>
#include "Game.h"
#define FLOORTILE_NUMBER = int 7


//FloorTile floorTiles[7];
//Entity entities[0];
//Character player;

Game* game = nullptr;

int main(int argc, char* args[])
{
    const int fps = 60;
    const int frameDelay = 1000 / fps;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->Init("Cozy",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,720,1280, true);
    while (game->Running())
    {
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameStart = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameStart);
        }
    }
    game->Clean();
    return 0;
}