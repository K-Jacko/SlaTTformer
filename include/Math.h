//
// Created by Wake on 2/19/2023.
//

#ifndef SLATFORMER_MATH_H
#define SLATFORMER_MATH_H
#include <iostream>
struct Vector2f
{
    Vector2f()
    :x(0.0f), y(0.0f){}
    Vector2f(float _x,float _y)
    :x(_x), y(_y){};
    float x, y;

    void print()
    {
        std::cout << "x" << x << "y" << y << std::endl;
    }
};

struct Vector4f
{
    Vector4f();
    Vector4f(float _x, float _y, float _h, float _w)
    :x(_x),y(_y),h(_h),w(_w){};
    float x,y,h,w;
};

#endif //SLATFORMER_MATH_H
