//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_MAP_H
#define SLATFORMER_MAP_H
#include "Game.h"

class Map
{
public:
    Map();
    ~Map();
    void LoadMap(int arr[16][27]);
    void DrawMap();

private:
    SDL_Rect src,dst,bsrc,bdst,dsrc,ddst,wsrc,wdst;
    int map[16][27];
    SDL_Texture* grass;
    SDL_Texture* wall;
    SDL_Texture* half;
    SDL_Texture* background;
};
#endif //SLATFORMER_MAP_H
