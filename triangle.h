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
        triangle(Vector3d , Vector3d , Vector3d);
        virtual ~triangle();

        //METHODS
        bool intersect( line* ray , Vector3i& color , double& t_out );


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
