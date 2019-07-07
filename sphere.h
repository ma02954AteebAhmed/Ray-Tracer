#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include <Eigen/Dense>
#include "line.h"
#include "object.h"


class sphere : public object
{
    public:
        sphere(Vector4d center , double radius);
        virtual ~sphere();
        Vector4d* collision_detection( line* ray );

    protected:

    private:
        double radius;
        double radius_square;
        double radius_inverse;
        Vector4d center;

};

#endif // SPHERE_H
