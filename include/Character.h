//
// Created by Wake on 2/19/2023.
//

#ifndef SLATFORMER_CHARACTER_H
#define SLATFORMER_CHARACTER_H
#include "Entity.h"
#include <vector>

class Character : public Entity
{
public:
    Character();
void SetX(int x);
void SetY(int y);
int getX();
int getY();
    int characterSpeed;
private:
    int posX, posY;
};
#endif //SLATFORMER_CHARACTER_H
