#include "vector.h"

vector::vector(point co_ordinate)
{
    this->x = co_ordinate.x;
    this->y = co_ordinate.y;
    this->z = co_ordinate.z;
}

vector::vector(double x, double y , double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vector::~vector()
{
    //dtor
}


void vector::calc_magnitude()
{
    this->magnitude = std::pow(x , 2) + std::pow(y , 2) + std::pow(z ,2);
    this->magnitude = std::sqrt(this->magnitude);
    this->magnitude_inverse = 1 / this->magnitude;
}

void vector::make_unit_vector()
{
    if (this->magnitude == -1)
    {
        calc_magnitude();
    }
    x = x * magnitude_inverse;
    y = y * magnitude_inverse;
    z = z * magnitude_inverse;
}

double vector::dot_product(vector v)
{
    return x*v.x + y*v.y + z*v.z;
}






