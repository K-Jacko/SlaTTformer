#include <vector>
#include "Game.h"
#include "Components/Components.h"
#include "Global.h"
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

float Game::deltaTime;

 Game::Game(){}
void Game::Init(const char* title, bool fullscreen)
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

    window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, gbl::SCREEN::WIDTH, gbl::SCREEN::HEIGHT, SDL_WINDOW_SHOWN);

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


    auto& Director(EntityManager::Instance().addEntity());
    Player = &EntityManager::Instance().addEntity();

    //MapComponent::LoadWalls(400,650, 20,10);

    Director.addComponent<TransformComponent>(0, 0, gbl::SCREEN::WIDTH, gbl::SCREEN::HEIGHT, 1, false);
    Director.addComponent<SpriteComponent>("resources/Background.png");
    Director.addComponent<GridComponent>(gbl::SCREEN::WIDTH / gbl::GAME::CELL_SIZE, gbl::SCREEN::HEIGHT / gbl::GAME::CELL_SIZE, gbl::GAME::CELL_SIZE);
    Director.addComponent<MapComponent>();

    Player->addComponent<TransformComponent>(gbl::SCREEN::WIDTH * 0.5, gbl::SCREEN::HEIGHT - 220 ,32, 32 ,4,gbl::GAME::ISKINEIMATIC);
    Player->addComponent<SpriteComponent>("resources/Entities/Player/Player_Front_STATIC_32x32.png");
    Player->addComponent<ColliderComponent>("Player");
    Player->addComponent<PlayerStateMachine>();
    Player->addComponent<KeyboardComponent>();
    Player->addComponent<MouseComponent>();
    Camera::Instance().SetPosition(Player->getComponent<TransformComponent>().GetPosition());


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

void Game::UpdateCamera()
{
    Camera::Instance().Update();
}

void Game::Update()
{
    EntityManager::Instance().Refresh();
    EntityManager::Instance().Update();
}

void Game::Collision()
{
    for (auto& cc : colliders)
    {
        gbl::CollisionResult playerCollisionResult = Collision::AABBPlayer(Game::Player->getComponent<ColliderComponent>(), *cc);
    }
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    EntityManager::Instance().Draw();
    if(DEBUG)
        EntityManager::Instance().Debug();
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
    auto& tile(EntityManager::Instance().addEntity());
    tile.addComponent<TileComponent>(x,y,id,gbl::GAME::CELL_SIZE);
    switch (id) {
        case 0 :

            break;
        case 1 :
            tile.addComponent<ColliderComponent>("Grass");
            break;
        case 2 :
            tile.addComponent<ColliderComponent>("Wall");
            break;
    }
}

