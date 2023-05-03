#include "Game.h"
#include "Components/Components.h"
#include "StateMachines/StateMachines.h"
#include "Global.h"
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Vector2D Game::mousePosition;
Camera* Game::camera;

std::vector<ColliderComponent*> Game::colliders;

float Game::deltaTime;

bool Game::isDebug;

auto& Director(manager.addEntity());
 auto& player(manager.addEntity());
 auto& wall(manager.addEntity());

 Game::Game(){}
void Game::Init(const char* title, bool fullscreen)
{
     camera = new Camera(gbl::SCREEN::WIDTH, gbl::SCREEN::HEIGHT);
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




    //MapComponent::LoadWalls(400,650, 20,10);

    Director.addComponent<TransformComponent>(0, 0, gbl::SCREEN::WIDTH, gbl::SCREEN::HEIGHT, 1, 0);
    Director.addComponent<SpriteComponent>("resources/Background.png");
    Director.addComponent<GridComponent>(gbl::SCREEN::WIDTH / gbl::GAME::CELL_SIZE, gbl::SCREEN::HEIGHT / gbl::GAME::CELL_SIZE, gbl::GAME::CELL_SIZE);
    Director.addComponent<MouseComponent>();
    Director.addComponent<MapComponent>();

    player.addComponent<TransformComponent>(gbl::SCREEN::WIDTH * 0.5, gbl::SCREEN::HEIGHT - 220 ,21, 50 ,2,1);
    player.addComponent<SpriteComponent>("resources/Character/_Idle.png", 43 , 42, true);
    player.addComponent<ColliderComponent>("player");
    player.addComponent<KeyboardComponent>();
    player.addComponent<PlayerStateMachine>();


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

void Game::UpdateCamera(gbl::CameraMovement cameraMovement)
{
     camera->Update(gbl::CameraMovement::Follow, player.getComponent<TransformComponent>().position.x / 2.0f, player.getComponent<TransformComponent>().position.x / 2.0f);
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
    tile.addComponent<TileComponent>(x,y,id,gbl::GAME::CELL_SIZE);
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

void Game::SetView(SDL_Rect camera)
{

}
