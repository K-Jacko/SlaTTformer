//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_MAP_H
#define SLATFORMER_MAP_H
#include <iostream>

class Map
{
public:
    Map();
    ~Map();
    static void LoadMap(std::string path, int sizex, int sizey);
    static void LoadWalls(int xPos, int yPos, int xSize, int ySize);

private:

};
#endif //SLATFORMER_MAP_H
