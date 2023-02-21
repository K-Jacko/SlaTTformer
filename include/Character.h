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
    int characterSpeed;
    void Init(RenderWindow* renderer, SDL_Texture* texture);
    void UpdatePosition(SDL_Event event);

private:
    int posX, posY;


};
#endif //SLATFORMER_CHARACTER_H
