//Custom R2 Point Class by Adrián Borrego
// 04-06-2023
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//...................//
//   R2 Point class  //
//...................//

/*  Point at R2 with different kind of
    methods and utilities.            */ 

class Point {
    private:
        double x;
        double y;
    
    public:
        //...............
        //  Constructor  
        //...............

        /* Pre: true.
           Post: creates a void point. */
        Point();

        /* Pre: true
           Post: creates a point with x coordinate and y ordinate */
        Point(double x, double y);

        /* Pre: true
           Post: creates a copy point of p */
        Point(const Point &p);

        //.............
        //  Destroyer  
        //.............

        /* automatically delete local objects
           in sort of an area of ​​visibility */
        ~Point();

        //...........
        //  Modifiers
        //...........

        /* Pre: true
           Post: returns a vector made by two coordenates with origin 
           at implicit point and extreme at p */
        vector<double> generateVector(Point p);

        /* Pre: true
           Post: changes coordenates at implicit point, moves it */
        void movePoint(double x, double y);
        
        /* Pre: true
           Post: makes an assignment at implicit point of p */
        void operator=(const Point p);

        //............
        //  Consultors
        //............

        /* Pre: true
           Post: return coordinate x of implicit point */
        double getx() const;

        /* Pre: true
           Post: return coordinate y of implicit point */
        double gety() const;

        /* Pre: vp.size() > 1
           Post: returns if the implicit point is aligned with other point/s */
        bool isAligned(const vector<Point> &vp);

        /* Pre: true
           Post: returns if the implicit point is equal to p */
        bool operator==(Point p) const;

        //.......
        //  L/E
        //.......

        /* Pre: a point p is prepared at input channel
           Post: p now have x and y readed at input channel */
        friend istream& operator>>(istream &is, Point &p);

        /* Pre: true
           Post: now x and y are written at output channel */
        friend ostream& operator<<(ostream &os, Point &p);

};