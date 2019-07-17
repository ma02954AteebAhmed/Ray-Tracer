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
        line( Vector3d , Vector3d );
        line(point , point );
        virtual ~line();
        line(){};

        // for calculating the direction vector
        void calc_direction(Vector3d start, Vector3d End);
        void calc_direction(point start, point End);
        bool is_normalized ;
        // direction vector
        Vector3d direction;
        Vector3d normalize_direction;
        // starting position of line
        Vector3d origin;
        // ending point of line
        Vector3d to_point;


        // to be used when ray needs to be changed
        void recreate(Vector3d , Vector3d);
        void normalize();

    protected:

    private:


};

#endif // LINE_H
