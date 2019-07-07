#include "color.h"

color::color()
{
    val[0] = 0;
    val[1] = 0;
    val[2] = 0;
}

color::color(Vector3d col)
{
    val = col;
}

color::~color()
{
    //dtor
}

color::color(int r , int g , int b)
{
    val[0] = r;
    val[1] = g;
    val[2] = b;
}

