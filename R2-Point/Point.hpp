// Custom R2 Point Class by Adrián Borrego
// 04-06-2023
#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "Vector.hpp"

using namespace std;

//...................//
//   R2 Point class  //
//...................//

/*  Point at R2 with different kind of
    methods and utilities.            */ 

class Point {
    private:
        float x, y;
    
    public:
      //...............
      //  Constructor  
      //...............

      /* Pre: true.
         Post: creates a void point. */
      Point();

      /* Pre: true
         Post: creates a point with x coordinate and y ordinate */
      Point(float x, float y);

      /* Pre: true
         Post: creates a copy point of p */
      Point(const Point &p);


      //.............
      //  Destroyer  
      //.............

      /* automatically delete local objects
         in sort of an area of ​​visibility */
      ~Point();


      //.............
      //  Modifiers
      //.............

      /* Pre: true
         Post: changes coordenate x of implicit point */
      void modifyx(float &x);

      /* Pre: true
         Post: changes coordenate y of implicit point */
      void modifyy(float &y);

      /* Pre: true
         Post: returns a Vector made by two coordenates with origin 
         at implicit point and extreme at p */
      Vector generateVector(const Point p);

      /* Pre: true
         Post: changes coordenates at implicit point, moves it */
      void movePoint(float x, float y);
        
      /* Pre: true
         Post: makes an assignment at implicit point of p */
      void operator=(const Point p);

      /* Pre: true
         Post: returns the sum of a point and a vector */
      Point operator+(const Vector &v);


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
      bool isAligned(vector<Point> &vp);

      /* Pre: true
         Post: returns the distance from implicit point to p*/
      float distance(const Point &p); 

      /* Pre: true
         Post: returns if the implicit point is equal to p */
      bool operator==(Point p) const;


      //.......
      //  L/E
      //.......

      /* Pre: a Point p is prepared at input channel
         Post: p now have x and y readed at input channel */
      friend istream& operator>>(istream &is, Point &p);

      /* Pre: true
         Post: now x and y are written at output channel */
      friend ostream& operator<<(ostream &os, Point &p);

};

#endif