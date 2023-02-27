//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_TEXTUREMANAGER_H
#define SLATFORMER_TEXTUREMANAGER_H
#include "SDL.h"

class TextureManager {
public:
    static  SDL_Texture* LoadTexture(const char* filename);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
    static void DrawEx(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip);
private:

};
#endif //SLATFORMER_TEXTUREMANAGER_H
