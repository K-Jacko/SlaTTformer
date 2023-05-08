//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_MAPCOMPONENT_H
#define SLATFORMER_MAPCOMPONENT_H
#include <iostream>
#include "GridComponent.h"


class MapComponent : public Component
{
public:
    MapComponent(){}
    ~MapComponent(){}

    void Init() override
    {
        gridComponent = entity->getComponent<GridComponent>();
        bottomRow = gridComponent.GetCellsInBottomRow();
        cellSize = gridComponent.GetCellSize();
        rightWall = gridComponent.GetRightWall();
        LoadFloor();
        //LoadRightWall();
    }

    void LoadFloor()
    {
        for (const auto& cell : bottomRow) {
            Game::AddTile(1,cell.X ,cell.Y );
        }
    }

    void LoadRightWall()
    {
        for (const auto& cell : rightWall) {
            Game::AddTile(2,cell.X ,cell.Y );
        }
    }

    void Draw() override
    {

    }
private:
    GridComponent gridComponent;
    std::vector<gbl::GridObject> bottomRow;
    std::vector<gbl::GridObject> rightWall;
    int cellSize;

};
#endif //SLATFORMER_MAPCOMPONENT_H
