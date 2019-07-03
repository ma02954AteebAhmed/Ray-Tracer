#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
#include "point.h"
#include <iostream>
#include <iomanip>

class vector
{
    public:
        vector(point);
        vector(){};
        vector(double, double,double);
        virtual ~vector();
        void calc_magnitude();
        void make_unit_vector();
        double dot_product(vector v);
        void normalize();

        // a "point" object to store co-ordinates
        double x,y,z;

        // for storing magnitude
        double magnitude = - 1;
        double magnitude_inverse = -1;

    protected:

    private:
};

#endif // VECTOR_H
