#include "Map.h"
#include "Game.h"
#include <fstream>

Map::Map()
{

}

Map::~Map()
{

}

void Map::LoadMap(std::string path, int sizex, int sizey, int gridSize)
{
//    char tile;
//    std::fstream mapFile;
//    mapFile.open(path);
//
//    for (int y = 0; y < sizey ; ++y) {
//        for (int x = 0; x < sizex ; ++x) {
//            mapFile.get(tile);
//            Game::AddTile(atoi(&tile), x * gridSize, y * gridSize);
//        }
//    }
//    mapFile.close();

Game::AddTile(1,sizex / 2, sizey -80);
}

void Map::LoadWalls(int xPos, int yPos,int xSize, int ySize)
{
    for (int y = yPos; y < ySize; ++y) {
        for (int x = xPos; x < xSize; ++x) {
            Game::CreateWalls(xPos * x,yPos * y);
        }
    }
}
