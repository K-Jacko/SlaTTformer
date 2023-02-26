#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <thread>
#include "Game.h"
#include "RenderWindow.h"
#include "Utils.h"

#define FLOORTILE_NUMBER = int 7

void HandleEntities(SDL_Texture* textures[]);

void LoadTextures(RenderWindow window);

void RenderTextures();

void CreateCharacter();

void InitEntities(SDL_Texture* textures[], RenderWindow* renderWindow);


//FloorTile floorTiles[7];
//Entity entities[0];
//Character player;

Game* game = nullptr;

int main(int argc, char* args[])
{
    const int fps = 60;
    const int frameDelay = 1000 / fps;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->Init("Cozy",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,720,1280,false);
    while (game->Running())
    {
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameStart = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameStart);
        }
    }
    game->Clean();
    return 0;

//    LoadTextures(window);
//
//    bool gameRunning = true;
//
//    SDL_Event event;
//
//    const float deltaTime = 0.01f;
//    float accumulator = 0.0f;
//    float currentTime = utils::hireTimeInSeconds();
//
//    while(gameRunning)
//    {
//        float newTime = utils::hireTimeInSeconds();
//        float frameTime = newTime - currentTime;
//
//        currentTime = newTime;
//
//        accumulator += frameTime;
//
//        while (accumulator >= deltaTime)
//        {
//            while(SDL_PollEvent(&event))
//            {
//                if (!(event.type == SDL_QUIT)) {
//                    if (event.type == SDL_KEYDOWN) {
//                        player.UpdatePosition(event);
//                    }
//                } else
//                    gameRunning = false;
//
//            }
//
//            accumulator -= deltaTime;
//        }
//        if(frameDelay >= 1.0f)
//        {
//            fps = static_cast<int>(1.9f / frameTime);
//            frameDelay -= 1.0f;
//        }
//
//        window.clear();
//        RenderTextures();
//        SDL_Texture* test  = window.loadTexture("resources/Background.png");
//        SDL_Rect dst;
//        dst.x = 0;
//        dst.y = 0;
//        dst.h = 100;
//        dst.w = 100;
//        window.renderBackground(*test);
//        window.display();
//
//    }
//    window.cleanUp();
//    SDL_Quit();
//



    //build Entities
    //Generate Colliders
    //Generate
}

void LoadTextures(RenderWindow window)
{
    SDL_Texture* textures[3];
    textures[0] = window.loadTexture("resources/Background.png");
    textures[1] = window.loadTexture("resources/Character/_Idle.png");
    textures[2] = window.loadTexture("resources/Tileset.png");
    InitEntities(textures, &window);
}

void InitEntities(SDL_Texture* textures[], RenderWindow* renderWindow)
{
//    for (int i = 0; i < SDL_arraysize(floorTiles); ++i) {
//        floorTiles[i].Init(renderWindow, textures[2]);
//    }
//    player.Init(renderWindow, textures[1]);



//    floorTiles[0].Init(renderer, textures[0]);
//
//    entities[0].Init(renderer, textures[0]);
//    entities[1].Init(renderer, textures[1]);
//
//
//    for (int i = 2; i < 29; ++i)
//    {
//        entities[i].SetPosition((i - 2) * 48, 700);
//        entities[i].SetTexture(textures[2]);
//    }
//    CreateCharacter();

}

void RenderTextures()
{
//    for (int i = 0; i < SDL_arraysize(floorTiles); ++i) {
//        floorTiles[i].RenderEntity();
//    }

//    window.renderBackground(*entities[0].getTexture());
//    window.renderEntity(entities[1]);
//    for (int i = 2; i < 35; ++i) {
//        window.renderCharacter(entities[i]);
//    }

}

void HandleEntities(SDL_Texture* textures[])
{

}

void CreateCharacter()
{


    //entities[1] = character;
    //character.Init();

}

//    SDLTest_TextWindow* textWindow = SDLTest_TextWindowCreate(0, 0, 100, 100);
//    std::string fpsText = "FPS: " + std::to_string(fps);
//    SDLTest_TextWindowAddText(textWindow,fpsText.c_str());
//    SDL_Color textColor = { 255, 255, 255 };
//    TTF_Font* font = TTF_OpenFont("resources/arial.ttf", 1);
//    SDL_Color textColor = { 255, 255, 255 }; // white color
//    std::string text = "Hello, world!";
//    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
//    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(window.GetRenderer(), textSurface);
//    SDL_Rect textRect = { 0, 0, textSurface->w, textSurface->h };
//    SDL_Rect srcrect = {0,0,100,100};
//    SDL_RenderCopy(window.GetRenderer(), textTexture, &srcrect, &textRect);