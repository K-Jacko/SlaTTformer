#ifndef SLATFORMER_GAME_H
#define SLATFORMER_GAME_H
#include "SDL.h"
#include "Math.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"
#include <iostream>
class Game
{
public:
    Game();
    ~Game();
    void Init(const char* title, int sxPos, int syPos, int sHeight, int sWidth, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool Running() { return isRunning;};
    static SDL_Renderer* renderer;

private:
    int counter;
    bool isRunning;
    SDL_Window* window;
};

#endif //SLATFORMER_GAME_H
