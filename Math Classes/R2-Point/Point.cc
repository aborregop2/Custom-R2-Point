#include "Point.hpp"
float slope(vector<float> &vs);

Point::Point() 
{

}

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}

Point::Point(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
}

Point::~Point()
{

}

vector<float> Point::generateVector(const Point p)
{
    vector<float> v(2);
    v[0] = p.x - x;
    v[1] = p.y - y;

    return v;
}

void Point::movePoint(float x, float y)
{
    if (this->x != x and this->y != y) {
        this->x = x;
        this->y = y;
    }
}

void Point::operator=(const Point p) 
{
    if (this != &p) {
        x = p.x;
        y = p.y;
    }
}

double Point::getx() const
{
    return x;
}

double Point::gety() const
{
    return y;
}

bool Point::isAligned(const vector<Point> &vp)
{   
    bool aligned = false;
    if (vp.size() > 1) {
        aligned = true;
        float snow;
        float sinitial = abs(slope(this->generateVector(vp[0])));

        for (unsigned int i = 1; i < vp.size() and aligned; i++) {
            if (sinitial != abs(slope(this->generateVector(vp[i])))) {
                aligned = false;
            }
        }
    }

    return aligned;
}

float Point::distance(const Point &p) {
    vector<float> r = this->generateVector(p);

    return sqrt(pow(r[0], 2) + pow(r[1], 2));
}

bool Point::operator==(Point p) const 
{
    return (x == p.x) and (y == p.y);
}

istream& operator>>(istream &is, Point &p)
{
    is >> p.x >> p.y;
    return is;
}

ostream& operator<<(ostream &os, Point &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}


/* Auxiliar Functions */

float slope(vector<float> &vs)
{
    return vs[1]/vs[0];
}
