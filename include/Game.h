#ifndef SLATFORMER_GAME_H
#define SLATFORMER_GAME_H
#include "SDL.h"
#include <vector>
#include "Math.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "TextureManager.h"
#include "Collision.h"
#include <iostream>
#include "ECS.h"


class ColliderComponent;

class Game
{
public:
    Game();
    ~Game();
    void Init(const char* title, int sxPos, int syPos, int sHeight, int sWidth, bool fullscreen);
    void HandleEvents();
    void Update();
    void Collision();
    void StateMachines();
    void AI();
    void Render();
    void Clean();
    bool Running() { return isRunning;};
    static float deltaTime;
    static int WindowX;
    static int WindowY;
    static int GridSize;
    static void AddTile(int id, int x, int y);
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static Vector2D mousePosition;
    static bool isDebug;
    static std::vector<ColliderComponent*> colliders;

private:
    int counter;
    bool isRunning;
    SDL_Window* window;
};

#endif //SLATFORMER_GAME_H
