#include "Game.h"
#include "ECS.h"
#include "Components.h"
#include <vector>

Map* map;
Manager manager;

 SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;
float Game::deltaTime;

bool Game::isDebug;
auto& background(manager.addEntity());
 auto& player(manager.addEntity());
 auto& wall(manager.addEntity());


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
    if (__cplusplus == 202101L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";

    window = SDL_CreateWindow(title, sxPos, syPos, sWidth, sHeight, SDL_WINDOW_SHOWN);

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

    Map::LoadMap("resources/Map1.map",52,1);
    //Map::LoadWalls(400,650, 20,10);

    player.addComponent<TransformComponent>(1,500,120,84,2,1);
    player.addComponent<SpriteComponent>("resources/Character/_Idle.png",true);
    player.addComponent<ColliderComponent>("player",99,44);
    player.addComponent<KeyboardComponent>();

    background.addComponent<TransformComponent>(0,0,1280,720,1,0);
    background.addComponent<SpriteComponent>("resources/Background.png",100,100);

    wall.addComponent<TransformComponent>(400,650,32,32,1);
    wall.addComponent<SpriteComponent>("resources/Tileset.png",48,48);
    wall.addComponent<ColliderComponent>("wall",true);
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

    for (auto& cc : colliders)
    {
        //Collision::AABB(player.getComponent<ColliderComponent>() , *cc);
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc,player.getComponent<TransformComponent>().velocity,cc->transform->velocity);
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

void Game::AddTile(int id, int x, int y)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x,700,id);
    if(id == 1)
        tile.addComponent<ColliderComponent>("Grass",true);


}

void Game::CreateWalls(int x, int y)
{
    auto& wall(manager.addEntity());
    wall.addComponent<TransformComponent>(x,y,32,32,1);
    wall.addComponent<SpriteComponent>("resources/Tileset.png",48,48);
    wall.addComponent<ColliderComponent>("wall", true);
}
