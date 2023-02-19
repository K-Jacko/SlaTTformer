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
    Vector2f(float x,float y)
    :x(x), y(y){};
    float x, y;

    void print()
    {
        std::cout << "x" << x << "y" << y << std::endl;
    }
};


#endif //SLATFORMER_MATH_H
