#include "point.h"

point::point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

point::point()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;

}

point::~point()
{
    //dtor
}
