#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include <Eigen/Dense>
#include "line.h"
#include "object.h"
#include <cmath>

using namespace Eigen;

class sphere : public object
{
    public:
        sphere(Vector3d center , double radius);
        virtual ~sphere();
        Vector3d* collision_detection( line* ray , Vector3i& color);

    protected:
    private:
        double radius;
        double radius_square;
        double radius_inverse;
        Vector3d center;
};

#endif // SPHERE_H
