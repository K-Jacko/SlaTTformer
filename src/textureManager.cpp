#include "TextureManager.h"
#include "SDL_image.h"
#include <iostream>


SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(Game::renderer, filename);

    if(texture == NULL)
        std::cout << "ERROR :: COULD NOT LOAD TEXTURE" << std::endl;

    return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(Game::renderer,texture,&src,&dst);
}

