#include "Game.h"
#include "Components.h"
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Vector2D Game::mousePosition;

int Game::WindowX;
int Game::WindowY;
int Game::GridSize;

std::vector<ColliderComponent*> Game::colliders;

float Game::deltaTime;

bool Game::isDebug;

auto& Director(manager.addEntity());
 auto& player(manager.addEntity());
 auto& wall(manager.addEntity());

 Game::Game(){}
void Game::Init(const char* title, int sxPos, int syPos, int sHeight, int sWidth, bool fullscreen)
{
    int flags = 0;
    WindowX = sWidth;
    WindowY = sHeight;
    GridSize = 25;
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

    //map = new MapComponent();
    isRunning = true;




    //MapComponent::LoadWalls(400,650, 20,10);

    Director.addComponent<TransformComponent>(0, 0, WindowX, WindowY, 1, 0);
    Director.addComponent<SpriteComponent>("resources/Background.png");
    Director.addComponent<GridComponent>(WindowX / GridSize, WindowY / GridSize, GridSize);
    Director.addComponent<MouseComponent>();
    Director.addComponent<MapComponent>();

    player.addComponent<TransformComponent>(WindowX * 0.5, WindowY - 220 ,25, 50 ,2,1);
    player.addComponent<SpriteComponent>("resources/Character/_Idle.png", 44 , 42, true);
    player.addComponent<ColliderComponent>("player");
    player.addComponent<KeyboardComponent>();


    //Director.addComponent<StateMachineComponent>();



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
}

void Game::Collision()
{
    for (auto& cc : colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc,player.getComponent<TransformComponent>().velocity,cc->transform->velocity);
    }
}

void Game::Render()
{
    SDL_RenderClear(renderer);
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
    tile.addComponent<TileComponent>(x,y,id,GridSize);
    switch (id) {
        case 0 :

            break;
        case 1 :
            tile.addComponent<ColliderComponent>("Grass", true);
            break;
        case 2 :
            tile.addComponent<ColliderComponent>("Wall", true);
            break;
    }
}
