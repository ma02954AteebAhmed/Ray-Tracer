#ifndef LINE_H
#define LINE_H
#include<Eigen/Dense>
#include "point.h"
#include <iostream>
using namespace Eigen;
using std::cout ;
using std::endl;

class line
{
    public:
        line( Vector4d , Vector4d );
        line(point , point );
        virtual ~line();
        line(){};

        // for calculating the direction vector
        void calc_direction(Vector4d start, Vector4d End);
        void calc_direction(point start, point End);
        bool is_normalized ;
        // direction vector
        Vector4d direction;
        Vector4d normalize_direction;
        // starting position of line
        Vector4d origin;
        // ending point of line
        Vector4d to_point;


        // to be used when ray needs to be changed
        void recreate(Vector4d , Vector4d);
        void normalize();

    protected:

    private:


};

#endif // LINE_H
