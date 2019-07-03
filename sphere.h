#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include "point.h"
#include "line.h"
#include "object.h"

class sphere : public object
{
    public:
        sphere(vector center , double radius);
        virtual ~sphere();
        vector* collision_detection( line* ray );

    protected:

    private:
        double radius;
        double radius_square;
        double radius_inverse;
        vector center;

};

#endif // SPHERE_H
