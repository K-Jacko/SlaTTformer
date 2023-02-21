//
// Created by Wake on 2/20/2023.
//

#include "Collider.h"

Collider::Collider(int x, int y, int w, int h)
:_x(x), _y(y), _w(w), _h(h)
{

}

bool Collider::collidesWith(const Collider &other) const
{
    return _x < other._x + other._w && _x + _w > other._x && _y < other._y + other._h && _y + _h > other._y;
}