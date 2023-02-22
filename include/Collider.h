//
// Created by Wake on 2/20/2023.
//

#ifndef SLATFORMER_COLLIDER_H
#define SLATFORMER_COLLIDER_H
#include "Collider.h"
#include <SDL.h>
class Collider {
public:
    Collider();
    Collider(int x, int y, int w, int h);
    Collider(SDL_Rect* rect);
    bool collidesWith(const Collider& other) const;
private:
    int _x, _y, _w, _h;
};
#endif //SLATFORMER_COLLIDER_H
