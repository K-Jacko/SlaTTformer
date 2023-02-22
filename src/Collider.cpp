//
// Created by Wake on 2/20/2023.
//

#include "Collider.h"
#include <SDL.h>

Collider::Collider(){

};

Collider::Collider(int x, int y, int w, int h)
:_x(x), _y(y), _w(w), _h(h)
{

}
Collider::Collider(SDL_Rect* rect)
:_x(rect->x), _y(rect->x), _w(rect->x), _h(rect->x)
{

}

bool Collider::collidesWith(const Collider &other) const
{
    return _x < other._x + other._w && _x + _w > other._x && _y < other._y + other._h && _y + _h > other._y;
}