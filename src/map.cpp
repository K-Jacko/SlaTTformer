#include "Map.h"
#include "Game.h"
#include <fstream>

Map::Map()
{

}

Map::~Map()
{

}

void Map::LoadMap(std::string path, int sizex, int sizey)
{
    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    for (int y = 0; y < sizey ; ++y) {
        for (int x = 0; x < sizex ; ++x) {
            mapFile.get(tile);
            Game::AddTile(atoi(&tile), x * 48, y * 48);
            mapFile.ignore();
        }
    }

    mapFile.close();

}

void Map::LoadWalls(int xPos, int yPos,int xSize, int ySize)
{
    for (int y = yPos; y < ySize; ++y) {
        for (int x = xPos; x < xSize; ++x) {
            Game::CreateWalls(xPos * x,yPos * y);
        }
    }

}
