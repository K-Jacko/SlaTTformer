//
// Created by Wake on 2/19/2023.
//

#ifndef SLATFORMER_MATH_H
#define SLATFORMER_MATH_H
#include <iostream>
struct Vector2D
{
    Vector2D();
    Vector2D(float _x, float _y);
    float x, y;

    Vector2D& Add(const Vector2D& vec);
    Vector2D& Subtract(const Vector2D& vec);
    Vector2D& Multiply(const Vector2D& vec);
    Vector2D& Divide(const Vector2D& vec);

    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);

    Vector2D& operator*(const int& i);
    Vector2D& Zero();

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D vec);
};
struct IntVector2D
{
    IntVector2D();
    IntVector2D(int _x, int _y);
    int x, y;

    IntVector2D& Add(const IntVector2D& vec);
    IntVector2D& Subtract(const IntVector2D& vec);
    IntVector2D& Multiply(const IntVector2D& vec);
    IntVector2D& Divide(const IntVector2D& vec);

    friend IntVector2D& operator*(IntVector2D& v1, const IntVector2D& v2);
    friend IntVector2D& operator-(IntVector2D& v1, const IntVector2D& v2);
    friend IntVector2D& operator+(IntVector2D& v1, const IntVector2D& v2);
    friend IntVector2D& operator/(IntVector2D& v1, const IntVector2D& v2);

    IntVector2D& operator+=(const IntVector2D& vec);
    IntVector2D& operator-=(const IntVector2D& vec);
    IntVector2D& operator*=(const IntVector2D& vec);
    IntVector2D& operator/=(const IntVector2D& vec);

    IntVector2D& operator*(const int& i);
    IntVector2D& Zero();

    friend std::ostream& operator<<(std::ostream& stream, const IntVector2D vec);
};

struct Vector4f
{
    Vector4f();
    Vector4f(float _x, float _y, float _h, float _w)
    :x(_x),y(_y),h(_h),w(_w){};
    float x,y,h,w;
};

#endif //SLATFORMER_MATH_H
