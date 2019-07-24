#ifndef OBJECT_H
#define OBJECT_H
#include "point.h"
#include "line.h"

class object
{
    public:
        object();
        virtual ~object();
        // for collision detection between ray and object
        virtual Vector3d* collision_detection(line* ray , Vector3i& color){};

    protected:

    private:
};

#endif // OBJECT_H
