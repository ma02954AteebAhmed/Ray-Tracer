#ifndef PLANE_H
#define PLANE_H
#include<iostream>
#include<Eigen/Dense>
#include "line.h"
#include "object.h"

using namespace Eigen;
using namespace std;


class plane : public object
{
    public:
        plane( Vector3d& normal , double d );
        virtual ~plane();
        bool intersect( line* ray , Vector3i& color , double* t);


        // plane's normal vector
        Vector3d normal;
        // distance of plane from the origin
        double d;

    protected:

    private:
};

#endif // PLANE_H
