#include "sphere.h"

sphere::sphere(vector center , double radius)
{
    this->center = center;
    this->radius = radius;
    this->radius_square = pow(radius, 2);
    this->radius_inverse = 1/this->radius;
}

sphere::~sphere()
{
    //dtor
}

vector* sphere::collision_detection(line* ray)
{
    vector* intersection_point = nullptr;

    // we are going to use the geometric approach..
    // step 1: Find if the ray's origin is outside the sphere.
    vector oc = { center.x - ray->origin.x , center.y - ray->origin.y , center.z - ray->origin.z};
    double L2oc = oc.dot_product(oc);

    // step 2: Find the closest approach of the ray to the sphere's center.
    bool flag = false; // to check if ray is inside the sphere or outside
    if (L2oc < radius_square)
    {
        // the rays origin lies inside the sphere !! handle it
        flag = true;
    }

    // here we find the closest approach to the spheres center
    ray->direction.make_unit_vector();

    double tca = oc.dot_product(ray->direction);
    if (tca < 0) return nullptr ; // step 3: if tca < 0 it means spheres center is behind rays origin hence they will never intersect
    else{
        // step 4: Else, find the squared distance from the closest approach to the sphere surface.
        double t2hc = radius_square - L2oc + pow(tca,2);
        if (t2hc < 0){return nullptr ;} // step 5: If the value is negative, the ray misses the sphere.
        else{
                if (flag == true)
                    {double t = tca + sqrt(t2hc); // step 6: Else, from the above, find the ray/surface distance.
                     // step 7:  Calculate the [xi yi zi] intersection coordinates.
                    intersection_point = new vector( ray->origin.x + t*ray->direction.x , ray->origin.y + t*ray->direction.y , ray->origin.z + t*ray->direction.z );

                    }
                else{
                    double t = tca - sqrt(t2hc);
                     // step 7:  Calculate the [xi yi zi] intersection coordinates.
                    intersection_point = new vector( ray->origin.x + t*ray->direction.x , ray->origin.y + t*ray->direction.y , ray->origin.z + t*ray->direction.z );
                    }
            }
        }
   // step 8: Calculate the normal at the intersection point.
    intersection_point->x = (intersection_point->x  - center.x) * radius_inverse;
    intersection_point->y = (intersection_point->y  - center.y) * radius_inverse;
    intersection_point->z = (intersection_point->z  - center.z) * radius_inverse;

    return intersection_point;
}
