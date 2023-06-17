#include "TextureManager.h"
#include "SDL_image.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include "Game.h"

std::vector<gbl::SpriteData> TextureManager::spriteDataList;
std::vector<SDL_Texture*> TextureManager::textures;

TextureManager& TextureManager::Instance()
{
    static TextureManager instance;
    return instance;
}

int TextureManager::Init()
{
    //Collect all directory strings from a path and place into a vector
    std::string directoryPath = "resources/Entities/SpriteData";
    std::vector<std::string> filePaths;

    try {
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            if (entry.is_regular_file()) {
                filePaths.push_back(entry.path().string());
            }
        }
    } catch (const std::filesystem::filesystem_error& ex) {
        std::cout << "Error accessing directory: " << ex.what() << std::endl;
        return -1;
    }

    //Process the files using the strings
    for(const auto& filePath : filePaths)
    {
        std::ifstream inputFile(filePath);
        if(!inputFile)
        {
            std::cout << "Failed to open the file:" << filePath << std::endl;
            return -1;
        }

        gbl::SpriteData spriteData;
        while (inputFile >> spriteData.OriginX >> spriteData.OriginY >> spriteData.TEXTURE_ID >>
                         spriteData.SPRITE_HEIGHT >> spriteData.SPRITE_WIDTH >> spriteData.TEXTURE_X >>
                         spriteData.TEXTURE_Y >> spriteData.TEXTURE_INDEX) {
            spriteDataList.push_back(spriteData);
        }

        inputFile.close();
    }

    //Load all Textures
    for(const auto& texturePath : spriteDataList)
    {
        SDL_Texture* tex;
        const char* path = texturePath.TEXTURE_ID.c_str();
        tex = IMG_LoadTexture(Game::renderer, path);
        textures.push_back(tex);
    }
    return 1;
    //Get via string

}

//bool TextureManager::LoadTexture(int index)
//{
//    SDL_Texture* texture = NULL;
//    texture = IMG_LoadTexture(Game::renderer, &spriteData.TEXTURE_ID);
//
//    if(texture == NULL)
//    {
//        std::cout << "ERROR :: COULD NOT LOAD TEXTURE" << std::endl;
//
//    return false;
//}

void TextureManager::CheckSpriteDataList()
{
    for (const auto& spriteData : spriteDataList) {
        std::cout << "OriginX: " << spriteData.OriginX << ", OriginY: " << spriteData.OriginY
                  << ", TEXTURE_ID: " << spriteData.TEXTURE_ID << ", SPRITE_HEIGHT: " << spriteData.SPRITE_HEIGHT
                  << ", SPRITE_WIDTH: " << spriteData.SPRITE_WIDTH << ", TEXTURE_X: " << spriteData.TEXTURE_X
                  << ", TEXTURE_Y: " << spriteData.TEXTURE_Y << ", TEXTURE_INDEX: " << spriteData.TEXTURE_INDEX << std::endl;
    }
}

SDL_Texture* TextureManager::GetTexture(int index)
{
    return textures[index];
}


void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::renderer, texture, &src, &dst, 0, nullptr, flip);
}

