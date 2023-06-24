#include "Point.hpp"

using namespace std;

int main() 
{
    Point p(1,2);
    cout << p << endl; // (1,2)

    cout << p.getx() << " " << p.gety() << endl;   // 1 2

    p.movePoint(5.3,1.2);  
    cout << p << endl; // (5.3,1.2)

    Point p2(1,1);
    vector<float> v = p.generateVector(p2);
    cout << "(" << v[0] << "," << v[1] << ")" << endl; // (-4,-4)

    Point a(1,1);
    Point b(2,2);
    Point c(3,3);
    vector<Point> vp(2);
    vp.push_back(b);
    vp.push_back(c);
    cout << a.isAligned(vp) << endl;    // 1
    
}