#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <Eigen/Dense>
#include <iostream>
#include "line.h"
#include "object.h"
using namespace Eigen;
using namespace std;

class triangle : public object
{
    public:
        triangle();
        virtual ~triangle();

        //METHODS
        Vector3d* collision_detection( line* ray , Vector3i& color );


        // DATA MEMBERS
        //vertices
        Vector3d A,B,C;
        // normal to the plane formed by triangle
        Vector3d normal;
        // d = distance from origin
        double d;
        // barycentric-cooridnates
        double u,v,w ;


    protected:

    private:
};

#endif // TRIANGLE_H
