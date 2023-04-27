//
// Created by Wake on 4/12/2023.
//

#ifndef SLATFORMER_GRIDCOMPONENT_H
#define SLATFORMER_GRIDCOMPONENT_H
#include "Math.h"
#include "ECS.h"
#include "Game.h"

class GridComponent : public Component
{
public:
    GridComponent(int _width, int _height, float _cellSize)
    {
        width = _width;
        height = _height;
        cellSize = _cellSize;


        border.x = 0;
        border.y = 0;
        border.w = 10 - width;
        border.h = 10 - height ;
    }
    void Draw() override
    {

    }
    void CreateGridObject(int x , int y)
    {
//        grid_cursor_ghost.x = (event.motion.x / grid_cell_size) * grid_cell_size;
//        grid_cursor_ghost.y = (event.motion.y / grid_cell_size) * grid_cell_size;
    }
    void Debug() override
    {
        for (int x = 0; x < 1 + width * cellSize;
             x += cellSize) {
            SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
            SDL_RenderDrawLine(Game::renderer, x, 0, x, Game::WindowY);
        }

        for (int y = 0; y < 1 + height * cellSize;
             y += cellSize) {
            SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
            SDL_RenderDrawLine(Game::renderer, 0, y, Game::WindowX, y);
        }

        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(Game::renderer, &border);
    }
private:
    int width;
    int height;
    float cellSize;
    SDL_Rect border;

};





#endif //SLATFORMER_GRIDCOMPONENT_H
