#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.h"
#include "RenderWindow.h"
#include "Character.h"

void HandleEntities(SDL_Texture* textures[]);

void LoadTextures(RenderWindow window);

void RenderTextures(RenderWindow window);

void CreateCharacter();

void SetCharacterEntity();

Entity entities[40];
Character player;

int main(int argc, char* args[]) {
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "ERROR" << SDL_GetError() << std::endl;
    }

    if(!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "ERROR" << SDL_GetError() << std::endl;
    }

    RenderWindow window("GAME", 1280, 720);


    LoadTextures(window);
    CreateCharacter();

    bool gameRunning = true;

    SDL_Event event;

    while(gameRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
            else if(event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        entities[1].setY(entities[1].getY() - 7);
                        break;
                    case SDLK_s:
                        entities[1].setY(entities[1].getY() + 7);
                        break;
                    case SDLK_a:
                        entities[1].setX(entities[1].getX() - 7);
                        break;
                    case SDLK_d:
                        entities[1].setX(entities[1].getX() + 7);
                        break;
                }
            }
        }
        window.clear();
        RenderTextures(window);
        window.display();
    }
    window.cleanUp();
    SDL_Quit();

    return 0;
}

void RenderTextures(RenderWindow window)
{
    window.renderBackground(*entities[0].getTexture());
    window.renderEntity(entities[1]);
    for (int i = 2; i < 35; ++i) {
        window.renderCharacter(entities[i]);
    }

}

void LoadTextures(RenderWindow window)
{
    SDL_Texture* textures[3];
    textures[0] = window.loadTexture("resources/Background.png");
    textures[1] = window.loadTexture("resources/Character/_Idle.png");
    textures[2] = window.loadTexture("resources/Tileset.png");
    HandleEntities(textures);
}

void HandleEntities(SDL_Texture* textures[])
{
    entities[0].SetTexture(textures[0]);
    entities[1].SetTexture(textures[1]);
    for (int i = 2; i < 29; ++i)
    {
        entities[i].setX((i - 2) * 48);
        entities[i].setY(700);
        entities[i].SetTexture(textures[2]);
    }
    CreateCharacter();

}

void CreateCharacter()
{
    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 100;
    dst.h = 100;
    entities[1].SetCurrentFrame(dst);
    entities[1].setX(70);
    entities[1].setY(599);
}