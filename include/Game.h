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
#include "Camera.h"


class ColliderComponent;

class Game
{
public:
    Game();
    ~Game();
    void Init(const char* title, bool fullscreen);
    void HandleEvents();
    void UpdateCamera();
    void Update();
    void Collision();
    void StateMachines();
    void AI();
    void Render();
    void Clean();
    bool Running() { return isRunning;};
    static float deltaTime;
    static void AddTile(int id, int x, int y);
    static void SetView(SDL_Rect _camera);
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;

private:
    bool isRunning;
    SDL_Window* window;
    Entity* Player;

};

#endif //SLATFORMER_GAME_H
