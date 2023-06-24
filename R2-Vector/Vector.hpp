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

        Vector();

        Vector(float x, float y);

        Vector(const Vector &v);

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
        void modifyx(float &x);

        void modifyy(float &y);

        void modifyVector(float &x, float &y);

        Vector operator+(const Vector &v);

        Vector operator-(const Vector &v);

        Vector operator*(const float &a);

        Vector operator/(const float &a);

        void operator=(Vector &v);

        void unitary();

        void rotate(const float &degree);


        //.............
        //  Consultors  
        //.............

        float getx();

        float gety();

        float slope();

        bool isProportional(const Vector &v);

        float magnitude();

        float scalarProd(const Vector &v);

        float degree_respect(const Vector &v);


        //........
        //  L/E  
        //........

        istream& operator>>(istream &is, Vector &v);

        ostream& operator<<(ostream &os, Vector &v);

};

#endif