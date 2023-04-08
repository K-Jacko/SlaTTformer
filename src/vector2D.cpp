#include "Math.h"


Vector2D::Vector2D()
:x(0.0f), y(0.0f){}

Vector2D::Vector2D(float _x, float  _y)
:x(0.0f), y(0.0f){}

Vector2D& Vector2D::Add(const Vector2D& vec)
{
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vec)
{
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vec)
{
    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vec)
{
    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)   {   return  v1.Multiply(v2);    }
Vector2D& operator-(Vector2D& v1, const Vector2D& v2)   {   return  v1.Subtract(v2);    }
Vector2D& operator+(Vector2D& v1, const Vector2D& v2)   {   return  v1.Add(v2); }
Vector2D& operator/(Vector2D& v1, const Vector2D& v2)   {   return  v1.Divide(v2);  }
Vector2D& Vector2D::operator+=(const Vector2D& vec) {   return this->Add(vec);  }
Vector2D& Vector2D::operator-=(const Vector2D& vec) {   return this->Subtract(vec); }
Vector2D& Vector2D::operator*=(const Vector2D& vec) {   return this->Multiply(vec); }
Vector2D& Vector2D::operator/=(const Vector2D& vec) {   return this->Divide(vec);   }
Vector2D& Vector2D::operator*(const int& i){this->x *= i;   this->y *= i;   return *this;}
Vector2D& Vector2D::Zero() { this->x = 0; this->y = 0;}
std::ostream& operator<<(std::ostream& stream, const Vector2D vec)  {   stream << "(" << vec.x << "," << vec.y << "y" << ")";   return stream;  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
IntVector2D::IntVector2D()
        :x(0), y(0){}

IntVector2D::IntVector2D(int _x, int  _y)
        :x(0), y(0){}

IntVector2D& IntVector2D::Add(const IntVector2D& vec)
{
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

IntVector2D& IntVector2D::Subtract(const IntVector2D& vec)
{
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

IntVector2D& IntVector2D::Multiply(const IntVector2D& vec)
{
    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}

IntVector2D& IntVector2D::Divide(const IntVector2D& vec)
{
    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

IntVector2D& operator*(IntVector2D& v1, const IntVector2D& v2)   {   return  v1.Multiply(v2);    }
IntVector2D& operator-(IntVector2D& v1, const IntVector2D& v2)   {   return  v1.Subtract(v2);    }
IntVector2D& operator+(IntVector2D& v1, const IntVector2D& v2)   {   return  v1.Add(v2); }
IntVector2D& operator/(IntVector2D& v1, const IntVector2D& v2)   {   return  v1.Divide(v2);  }
IntVector2D& IntVector2D::operator+=(const IntVector2D& vec) {   return this->Add(vec);  }
IntVector2D& IntVector2D::operator-=(const IntVector2D& vec) {   return this->Subtract(vec); }
IntVector2D& IntVector2D::operator*=(const IntVector2D& vec) {   return this->Multiply(vec); }
IntVector2D& IntVector2D::operator/=(const IntVector2D& vec) {   return this->Divide(vec);   }
IntVector2D& IntVector2D::operator*(const int& i){this->x *= i;   this->y *= i;   return *this;}
IntVector2D& IntVector2D::Zero() { this->x = 0; this->y = 0;}
std::ostream& operator<<(std::ostream& stream, const IntVector2D vec)  {   stream << "(" << vec.x << "," << vec.y << "y" << ")";   return stream;  }