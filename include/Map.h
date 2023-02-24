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

    void LoadMap(int arr[20][30]);
    void DrawMap();

private:

    SDL_Rect src,dst;
    int map[20][30];
    SDL_Texture* grass;
    SDL_Texture* water;
    SDL_Texture* dirt;
};
#endif //SLATFORMER_MAP_H
