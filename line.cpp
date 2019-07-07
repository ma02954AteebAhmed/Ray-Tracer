#include "line.h"

line::line(Vector4d start , Vector4d End)
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

void line::calc_direction(Vector4d start , Vector4d End)
{
    this->direction[0] = End[0] - start[0];
    this->direction[1] = End[1] - start[1];
    this->direction[2] = End[2] - start[2];
    this->direction[3] = 1;
}

void line::calc_direction(point start , point End)
{

}

void line::recreate(Vector4d start , Vector4d End)
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
        normalize_direction.block(0,0,3,1).normalize();
        is_normalized = true;
    }
    else{return;}
}
