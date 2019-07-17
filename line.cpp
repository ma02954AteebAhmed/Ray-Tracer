#include "line.h"

line::line(Vector3d start , Vector3d End)
{
    this->origin = start;
    calc_direction(start , End);
    this->to_point = End;
    is_normalized = false;
    this->normalize_direction = this->direction;
}

line::line(point start , point End)
{
    this->origin[0] = start.x;
    this->origin[1] = start.y;
    this->origin[2] = start.z;
    calc_direction(start , End);
}

line::~line()
{
    //dtor
}

void line::calc_direction(Vector3d start , Vector3d End)
{
    this->direction = End - start;

}

void line::calc_direction(point start , point End)
{

}

void line::recreate(Vector3d start , Vector3d End)
{
    this->origin = start;
    calc_direction( start , End );
    this->to_point = End;
    this->normalize_direction = this->direction;
    is_normalized = false;
}

void line::normalize()
{
    if (is_normalized == false)
    {
        normalize_direction.normalize();
        is_normalized = true;
    }
    else{return;}
}
