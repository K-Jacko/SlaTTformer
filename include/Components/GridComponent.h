#ifndef SLATFORMER_GRIDCOMPONENT_H
#define SLATFORMER_GRIDCOMPONENT_H
#include "Game.h"
#include <vector>
#include "Global.h"

class GridComponent : public Component
{
public:
    GridComponent(){}
    GridComponent(int _width, int _height, float _cellSize)
    {
        width = _width + 100;
        height = _height;
        cellSize = _cellSize;
    }
    void Init()
    {
        std::vector<std::vector<gbl::GridObject>> go(width, std::vector<gbl::GridObject>(height));
        int o = 0;
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                go[x][y].ID = o;
                go[x][y].X = x * cellSize - Camera::Instance().view.x;
                go[x][y].Y = y * cellSize ;
                o++;
            }
        }
        gridOs = go;
    }

    void Update() override
    {
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                gridOs[x][y].X -= Camera::Instance().view.x;
                //gridOs[x][y].Y -= Game::camera->view.y;
            }
        }
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

    std::vector<gbl::GridObject> GetCellsInBottomRow() const
    {
        std::vector<gbl::GridObject> result;
        result.reserve(width); // Reserve enough space for all the cells in the bottom row
        for (int x = 0; x < width; ++x) {
            result.push_back(gridOs[x].back());
        }
        return result;
    }

    std::vector<gbl::GridObject> GetRightWall() const
    {
        return gridOs.back();
    }

    void Debug() override
    {
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y)    {
                SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
                SDL_Rect rc;
                rc.x = gridOs[x][y].X;
                rc.y = gridOs[x][y].Y;
                rc.w = 3;
                rc.h = 3;
                SDL_RenderDrawRect(Game::renderer, &rc);
            }
        }

    }


private:
    int width;
    int height;
    int cellSize;
    std::vector<std::vector<gbl::GridObject>> gridOs;
    int gridObjects;
};





#endif //SLATFORMER_GRIDCOMPONENT_H
