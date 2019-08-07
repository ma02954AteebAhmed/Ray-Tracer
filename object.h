#ifndef OBJECT_H
#define OBJECT_H
#include "point.h"
#include "line.h"
#include <Eigen/Dense>
using namespace Eigen;

class object
{
    public:
        object();
        virtual ~object();
        // for collision detection between ray and object
        virtual bool intersect(line* ray , Vector3i& color , double& t){};

    protected:

    private:
};

#endif // OBJECT_H
