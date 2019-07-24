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

object* scene::get_object(int index)
{
    return this->elements[index];
}

int scene::object_count()
{
    return this->elements.size();
}
