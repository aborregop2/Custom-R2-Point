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

void Point::modifyx(float &x) 
{
    if(this->x != x) {
        this->x = x;
    }
}

void Point::modifyy(float &y) 
{
    if(this->y != y) {
        this->y = y;
    }
}

Vector Point::generateVector(const Point p)
{
    Vector v(*this, p);

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

Point Point::operator+(const Vector &v)
{
    Point q(x + v.getx(), y + v.gety());

    return q;
}
double Point::getx() const
{
    return x;
}

double Point::gety() const
{
    return y;
}

bool Point::isAligned(vector<Point> &vp)
{   
    bool aligned = false;
    if (vp.size() > 1) {
        aligned = true;

        Vector v(*this, vp[0]);
        float sinitial = v.slope();

        for (unsigned int i = 1; i < vp.size() and aligned; i++) {

            Vector v(*this, vp[i]);
            
            if (sinitial != v.slope()) {
                aligned = false;
            }
        }
    }

    return aligned;
}

float Point::distance(const Point &p) {
    Vector v(*this, p);

    return v.magnitude();
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
