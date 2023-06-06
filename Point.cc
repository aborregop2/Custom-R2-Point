#include "Point.hpp"
double slope(vector<double> &vs);

Point::Point() 
{

}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point::Point(Point &p)
{
    this->x = p.x;
    this->y = p.y;
}

Point::~Point()
{

}

vector<double> Point::generateVector(Point p)
{
    vector<double> v(2);
    v[0] = p.x - x;
    v[1] = p.y - y;

    return v;
}

void Point::movePoint(double x, double y)
{
    if (this->x != x and this->y != y) {
        this->x = x;
        this->y = y;
    }
}

void Point::operator=(Point p) 
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
        double snow;
        double sinitial = slope(this->generateVector(vp[0]));

        if (sinitial < 0) {
            sinitial *= -1.0;
        }

        for (unsigned int i = 1; i < vp.size() and aligned; i++) {
            if (sinitial != snow) {
                aligned = false;
            }

            snow = slope(this->generateVector(vp[i]));
            if (snow < 0) {
                snow *= -1.0;
            }
        }
    }

    return aligned;
}

bool Point::operator==(Point p) const 
{
    return (x == p.x) and (y == p.y);
}

istream& Point::operator>>(istream &is, Point &p)
{
    is >> p.x >> p.y;
    return is;
}

ostream& Point::operator<<(ostream &os, Point &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}


/* Auxiliar Function */

double slope(vector<double> &vs)
{
    return double(vs[1]/vs[0]);
}
