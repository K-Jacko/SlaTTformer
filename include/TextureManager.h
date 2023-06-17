//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_TEXTUREMANAGER_H
#define SLATFORMER_TEXTUREMANAGER_H
#include "SDL.h"
#include "Global.h"

class TextureManager {
public:
    int Init();
    static TextureManager& Instance();
    static void LoadAllTextures();
    static bool LoadTexture(int index);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip);
    static void CheckSpriteDataList();
    static SDL_Texture* GetTexture(int index);
private:
    static std::vector<gbl::AnimationData> animations;
    static std::vector<gbl::SpriteData> spriteDataList;
    static std::vector<SDL_Texture*> textures;
};
#endif //SLATFORMER_TEXTUREMANAGER_H
