#ifndef SLATFORMER_GRIDCOMPONENT_H
#define SLATFORMER_GRIDCOMPONENT_H
#include "Game.h"
#include <vector>

struct GridObject
{
    GridObject(){
        X = 0;
        Y = 0;
        ID = -100;
    }
    ~GridObject(){}
    int ID;
    int X,Y;

};
class GridComponent : public Component
{
public:
    GridComponent(){}
    GridComponent(int _width, int _height, float _cellSize)
    {
        width = _width + 1;
        height = _height;
        cellSize = _cellSize;

        std::vector<std::vector<GridObject>> go(width, std::vector<GridObject>(height));

        int o = 0;
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                go[x][y].ID = o;
                go[x][y].X = x;
                go[x][y].Y = y;
                o++;
            }
        }
        gridOs = go;

    }
    void Init()
    {


    }
    void Draw() override
    {

    }

    int GetWidth()
    {
        return width;
    }

    int GetHeight()
    {
        return height;
    }

    int GetCellSize()
    {
        return cellSize;
    }

    int Get1DIndex(int x, int y)
    {
        return gridOs[x][y].ID;
    }

    std::vector<GridObject> GetCellsInBottomRow() const
    {
        std::vector<GridObject> result;
        result.reserve(width); // Reserve enough space for all the cells in the bottom row
        for (int x = 0; x < width; ++x) {
            result.push_back(gridOs[x].back());
        }
        return result;
    }

    std::vector<GridObject> GetRightWall() const
    {
        return gridOs.back();
    }

    void Debug() override
    {
        if(Game::isDebug)   {
            for (int x = 0; x < width; ++x) {
                for (int y = 0; y < height; ++y)    {
                    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
                    SDL_Rect rc;
                    rc.x = gridOs[x][y].X * cellSize;
                    rc.y = gridOs[x][y].Y * cellSize;
                    rc.w = 3;
                    rc.h = 3;
                    SDL_RenderDrawRect(Game::renderer, &rc);
                }
            }
        }
    }


private:
    int width;
    int height;
    int cellSize;
    std::vector<std::vector<GridObject>> gridOs;
    int gridObjects;
};





#endif //SLATFORMER_GRIDCOMPONENT_H
