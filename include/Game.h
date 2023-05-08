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
    void Input(Vector2D _input);
    static void CastLine();
    void Render();
    void Clean();
    bool Running() { return isRunning;};
    static float deltaTime;
    static void AddTile(int id, int x, int y);
    static void SetView(SDL_Rect _camera);

    static SDL_Renderer* renderer;
    static int cameraMode;
    static SDL_Event event;
    static Vector2D mousePosition;
    static std::vector<ColliderComponent*> colliders;

private:
    static Entity* fishingLines;
    static Vector2D* CameraTarget;
    bool isRunning;
    SDL_Window* window;

};

#endif //SLATFORMER_GAME_H
