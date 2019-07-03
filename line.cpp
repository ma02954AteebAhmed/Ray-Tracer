#include "line.h"

line::line(vector start , vector End)
{
    this->origin = start;
    calc_direction(start , End);
}

line::line(point start , point End)
{
    this->origin.x = start.x;
    this->origin.y = start.y;
    this->origin.z = start.z;

    calc_direction(start , End);
}

line::~line()
{
    //dtor
}

void line::calc_direction(vector start , vector End)
{
    direction.x = End.x - start.x;
    direction.y = End.y - start.y;
    direction.z = End.z - start.z;
}

void line::calc_direction(point start , point End)
{
    direction.x = End.x - start.x;
    direction.y = End.y - start.y;
    direction.z = End.z - start.z;
}
