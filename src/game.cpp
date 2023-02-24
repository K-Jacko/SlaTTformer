#include "Game.h"

 SDL_Renderer* Game::renderer = nullptr;
Map* map;
 GameObject* player;

 Game::Game(){}
 Game::~Game(){}
void Game::Init(const char* title, int sxPos, int syPos, int sHeight, int sWidth, bool fullscreen)
{

    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == nullptr)
    {
        std::cerr << "Renderer :: Error " << SDL_GetError() << std::endl;
    } else if (renderer)
    {
        std::cout << "Renderer :: Made " << SDL_GetError() << std::endl;
    }
    Vector2f* position = new Vector2f(2,1);
    player = new GameObject("resources/Character/_Idle.png", position);
    map = new Map();
    isRunning = true;
}

void Game::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            //Player Input
            break;
        default:
            break;
    }
}

void Game::Update()
{
    player->Update();
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->Render();
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleared" << std::endl;
}
