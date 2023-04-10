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
Vector2D& Vector2D::operator*=(float i) {  *this = *this * i ;return *this;}
Vector2D& Vector2D::operator/=(const Vector2D& vec) {   return this->Divide(vec);   }
Vector2D& Vector2D::operator*(const float& i){this->x *= i; this->y *= i; return *this;}
Vector2D& Vector2D::operator*(const int& i){this->x *= i; this->y *= i; return *this;}
Vector2D& Vector2D::Zero() { this->x = 0; this->y = 0; return *this;}
std::ostream& operator<<(std::ostream& stream, const Vector2D vec)  {   stream << "(" << vec.x << "," << vec.y << "y" << ")";   return stream;  }
//var vector = {
//        _x: 1,
//        _y: 0,
//
//        create: function(x, y) {
//            var obj = Object.create(this);
//            obj.setX(x);
//            obj.setY(y);
//            return obj;
//        },
//
//        setX: function(value) {
//            this._x = value;
//        },
//
//        getX: function() {
//            return this._x;
//        },
//
//        setY: function(value) {
//            this._y = value;
//        },
//
//        getY: function() {
//            return this._y;
//        },
//
//        setAngle: function(angle) {
//            var length = this.getLength();
//            this._x = Math.cos(angle) * length;
//            this._y = Math.sin(angle) * length;
//        },
//
//        getAngle: function() {
//            return Math.atan2(this._y, this._x);
//        },
//
//        setLength: function(length) {
//            var angle = this.getAngle();
//            this._x = Math.cos(angle) * length;
//            this._y = Math.sin(angle) * length;
//        },
//
//        getLength: function() {
//            return Math.sqrt(this._x * this._x + this._y * this._y);
//        },
//
//        add: function(v2) {
//            return vector.create(this._x + v2.getX(), this._y + v2.getY());
//        },
//
//        subtract: function(v2) {
//            return vector.create(this._x - v2.getX(), this._y - v2.getY());
//        },
//
//        multiply: function(val) {
//            return vector.create(this._x * val, this._y * val);
//        },
//
//        divide: function(val) {
//            return vector.create(this._x / val, this._y / val);
//        },
//
//        addTo: function(v2) {
//            this._x += v2.getX();
//            this._y += v2.getY();
//        },
//
//        subtractFrom: function(v2) {
//            this._x -= v2.getX();
//            this._y -= v2.getY();
//        },
//
//        multiplyBy: function(val) {
//            this._x *= val;
//            this._y *= val;
//        },
//
//        divideBy: function(val) {
//            this._x /= val;
//            this._y /= val;
//        }
//};