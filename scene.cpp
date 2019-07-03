#include "scene.h"

scene::scene()
{
    //ctor
}

scene::~scene()
{
    //dtor
}

void scene::add_object(object* o)
{
    elements.push_back(o);
}
