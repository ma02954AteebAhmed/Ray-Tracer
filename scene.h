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

    protected:

    private:
        // scene has some data structure(vector) that has every object (physical object) stored in it.
        std::vector<object*> elements;

};

#endif // SCENE_H
