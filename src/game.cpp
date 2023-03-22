#include "Game.h"
#include "ECS.h"
#include "Components.h"
#include <vector>

Map* map;
Manager manager;

 SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

bool Game::isDebug;
 auto& player(manager.addEntity());
 auto& wall(manager.addEntity());
 auto& tile0(manager.addEntity());
 auto& tile1(manager.addEntity());
 auto& tile2(manager.addEntity());

 Game::Game(){}
void Game::Init(const char* title, int sxPos, int syPos, int sHeight, int sWidth, bool fullscreen)
{

    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_BORDERLESS;
    }

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "ERROR" << SDL_GetError() << std::endl;
    }
    else
    {

        std::cout << "Video Systems :: Initialised!" << std::endl;

    }

    if(!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "ERROR" << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "IMG :: Systems Initialised!" << std::endl;
    }

    if(TTF_Init() != 0)
    {
        std::cout << "ERROR" << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "Text :: Systems Initialised!" << std::endl;
    }

    window = SDL_CreateWindow(title, sxPos, syPos, sWidth, sHeight, SDL_WINDOW_SHOWN | flags);

    if(window == nullptr)
    {
        std::cerr << "Window :: Error " << SDL_GetError() << std::endl;
    } else if (window)
    {
        std::cout << "Window :: Made " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == nullptr)
    {
        std::cerr << "Renderer :: Error " << SDL_GetError() << std::endl;
    } else if (renderer)
    {
        std::cout << "Renderer :: Made " << SDL_GetError() << std::endl;
    }

    //map = new Map();
    isRunning = true;

    tile0.addComponent<TileComponent>(10,200,0);
    tile0.addComponent<ColliderComponent>("Air");
    tile1.addComponent<TileComponent>(200,200,1);
    tile1.addComponent<ColliderComponent>("Air");
    tile1.addComponent<TileComponent>(200,200,1);
    tile1.addComponent<ColliderComponent>("Grass");
    tile2.addComponent<TileComponent>(48,48,2);
    tile2.addComponent<ColliderComponent>("Wall");

    player.addComponent<TransformComponent>(0,523,120,84,2);
    player.addComponent<SpriteComponent>("resources/Character/_Idle.png",true);
    player.addComponent<ColliderComponent>("player",99,44);
    player.addComponent<KeyboardComponent>();

    wall.addComponent<TransformComponent>(400,650,32,32,1);
    wall.addComponent<SpriteComponent>("resources/Tileset.png",48,48);
    wall.addComponent<ColliderComponent>("wall");

}

void Game::HandleEvents()
{

    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
            }
    }
}

void Game::Update()
{
    manager.Refresh();
    manager.Update();

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<TransformComponent>().velocity.Zero();
        player.getComponent<TransformComponent>().position.x -= 1;
        std::cout << player.getComponent<ColliderComponent>().tag << " Has hit " << wall.getComponent<ColliderComponent>().tag << std::endl;
    }
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    //map->DrawMap();
    manager.Draw();
    manager.Debug();
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleared" << std::endl;
}

Game::~Game()
{
     Game::Clean();
 }
