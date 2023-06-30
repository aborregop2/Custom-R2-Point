// Custom R2 Vector Class by Adrián Borrego
// 24-06-2023
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "Point.hpp"

using namespace std;

//.....................//
//   R2 Vector class  //
//...................//

/*  Vector at R2 with different kind of
    methods and utilities.            */

class Vector {
    private:
        float x, y;
    
    public:
        //...............
        //  Constructor  
        //...............

        /* Pre: true.
           Post: creates a void Vector. */
        Vector();

        /* Pre: true.
           Post: creates a Vector with coordenates x, y. */
        Vector(float x, float y);

        /* Pre: true.
           Post: creates a Vector copy of v. */
        Vector(const Vector &v);

        /* Pre: true.
           Post: creates a Vector that has origin at p1 and ends at p2. */
        Vector(const Point &p1, const Point &p2);


        //.............
        //  Destroyer  
        //.............

        /* automatically delete local objects
           in sort of an area of ​​visibility */
        ~Vector();


        //.............
        //  Modifiers  
        //.............

        /* Pre: true.
           Post: now x from the implicit Vector is x parameter. */
        void modifyx(float &x);

        /* Pre: true.
           Post: now y from the implicit Vector is y parameter. */
        void modifyy(float &y);

        /* Pre: true.
           Post: now x and y from the implicit Vector is x and y parameters. */
        void modifyVector(float &x, float &y);

        /* Pre: v is not empty.
           Post: returns sum of implicit Vector and v. */
        Vector operator+(const Vector &v);

        /* Pre: v is not empty.
           Post: returns substraction of implicit Vector and v. */
        Vector operator-(const Vector &v);

        /* Pre: true.
           Post: returns product of implicit Vector and a. */
        Vector operator*(const float &a);

        /* Pre: true.
           Post: returns division of implicit Vector and a. */
        Vector operator/(const float &a);

        /* Pre: true.
           Post: assigns v at the implicit parameter */
        void operator=(Vector &v);

        /* Pre: true.
           Post: now the implicit Vector is an unitary Vector */
        void unitary();

        /* Pre: true.
           Post: now the implicit Vector has rotated degree degrees */
        void rotate(const float &degree);


        //.............
        //  Consultors  
        //.............

        /* Pre: true.
           Post: returns coordenate of implicit Vector */
        float getx() const;

        /* Pre: true.
           Post: returns ordenate of implicit Vector */
        float gety() const;

        /* Pre: true.
           Post: returns the slope of implicit Vector */
        float slope() const;

        /* Pre: v is not empty.
           Post: returns if the implicit Vector and v are proportional */
        bool isProportional(Vector &v) const;

        /* Pre: true.
           Post: returns the magnitude from the implicit Vector */
        float magnitude() const;

        /* Pre: v is not empty.
           Post: returns scalar product from the implicit Vector and v */
        float scalarProd(Vector &v) const;

        /* Pre: v is not empty.
           Post: returns the degree from implicit Vector respect v */
        float degree_respect(Vector &v) const;


        //........
        //  L/E  
        //........

        /* Pre: Vector v prepared at input channel.
           Post: v now have x and y readed at input channel */
        friend istream& operator>>(istream &is, Vector &v);

        /* Pre: true.
           Post: now x and y are written at output channel */
        friend ostream& operator<<(ostream &os, Vector &v);

};

#endif