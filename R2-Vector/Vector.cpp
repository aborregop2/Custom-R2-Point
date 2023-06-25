#include "Vector.hpp"

Vector::Vector()
{

}

Vector::Vector(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector::Vector(const Vector &v)
{
    this->x = v.x;
    this->y = v.y;
}

Vector::Vector(const Point &p1, const Point &p2)
{
    this->x = p2.getx() - p1.getx();
    this->y = p2.gety() - p2.gety();
}

Vector::~Vector()
{

}

void Vector::modifyx(float &x)
{
    if (this->x != x) {
        this->x = x;
    }
}

void Vector::modifyy(float &x)
{
    if (this->y != y) {
        this->y = y;
    }
}

void Vector::modifyVector(float &x, float &y)
{
    if (this->x != x) {
        this->x = x;
    }

    if (this->y != y) {
        this->y = y;
    }
}

Vector Vector::operator+(const Vector &v)
{
    Vector q(this->x + v.x, this->y + v.y);
    
    return q;
}

Vector Vector::operator-(const Vector &v)
{
    Vector q(this->x - v.x, this->y - v.y);
    
    return q;
}

Vector Vector::operator*(const float &a)
{
    Vector v(this->x * a, this->y * a);

    return v;
}

Vector Vector::operator/(const float &a)
{
    Vector v(this->x / a, this->y / a);

    return v;
}

void Vector::operator=(Vector &v)
{
    if (this != &v) {
        this->x = v.x;
        this->y = v.y;
    }
}

void Vector::unitary()
{
    x = x / this->magnitude();
    y = y / this->magnitude();
}

void Vector::rotate(const float &degree)
{
    x = x * cos(degree) - y * sin(degree);
    y = y * sin(degree) + x * cos(degree);
}

float Vector::getx() const
{
    return x;
}

float Vector::gety() const
{
    return y;
}

float Vector::slope() const
{
    return y/x;
}

bool Vector::isProportional(Vector &v) const
{
    bool proportional = false;

    if (x/v.x == y/v.y) proportional = true;

    return proportional;
}

float  Vector::magnitude() const
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector::scalarProd(Vector &v) const
{
    return x*v.x + y*v.y;
}


float Vector::degree_respect(Vector &v) const
{
    return acos(this->scalarProd(v) / (this->magnitude() * v.magnitude()));
}

istream& operator>>(istream &is, Vector &v)
{
    is >> v.x >> v.y;

    return is;
}

ostream& operator<<(ostream &os, Vector &v)
{
    os << "->(" << v.x << "," << v.y << ")";

    return os;
}