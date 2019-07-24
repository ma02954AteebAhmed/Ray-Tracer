#ifndef SCENE_H
#define SCENE_H
#include "object.h"
#include <vector>

class scene
{
    public:
        scene();
        virtual ~scene();

        // for adding an element of type "object" in the data structure
        void add_object(object* o);
        object* get_object(int);
        int object_count();

        // scene has some data structure(vector) that has every object (physical object) stored in it.
        std::vector< object* > elements;

    protected:

    private:


};

#endif // SCENE_H
