#include "sphere.h"

sphere::sphere(Vector4d center , double radius)
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

Vector4d* sphere::collision_detection( line* ray)
{
   Vector4d* intersection_point = nullptr;

    // we are going to use the geometric approach..
    // step 1: Find if the ray's origin is outside the sphere.
    Vector4d oc = { center[0] - ray->origin[0] , center[1] - ray->origin[1] , center[2] - ray->origin[2] , 1};
   // dot product
    double L2oc = oc[0]*oc[0] + oc[1]*oc[1] + oc[2]*oc[2];
    // step 2: Find the closest approach of the ray to the sphere's center.

    bool flag = false; // to check if ray is inside the sphere or outside
    if (L2oc < radius_square)
    {
        // the rays origin lies inside the sphere !! handle it
        flag = true;
    }

    // here we find the closest approach to the spheres center

    // MAKING THE DIRECTION VECTOR UNIT VECTOR

    ray->normalize();
    double tca = oc[0]*ray->normalize_direction[0] + oc[1]*ray->normalize_direction[1] + oc[2]*ray->normalize_direction[2];
    if (tca < 0) return nullptr ; // step 3: if tca < 0 it means spheres center is behind rays origin hence they will never intersect
    else{
        // step 4: Else, find the squared distance from the closest approach to the sphere surface.
        double t2hc = radius_square - L2oc + pow(tca,2);
        if (t2hc < 0){return nullptr ;} // step 5: If the value is negative, the ray misses the sphere.
        else{
                if (flag == true)
                    {double t = tca + sqrt(t2hc); // step 6: Else, from the above, find the ray/surface distance.
                     // step 7:  Calculate the [xi yi zi] intersection coordinates.
                    intersection_point = new Vector4d( ray->origin[0] + t*ray->direction[0] , ray->origin[1] + t*ray->direction[1] , ray->origin[2] + t*ray->direction[2] , 1 );

                    }
                else{
                    double t = tca - sqrt(t2hc);
                     // step 7:  Calculate the [xi yi zi] intersection coordinates.
                    intersection_point = new Vector4d( ray->origin[0] + t*ray->direction[0] , ray->origin[1] + t*ray->direction[1] , ray->origin[2] + t*ray->direction[2] , 1 );
                    }
            }
        }
   // step 8: Calculate the normal at the intersection point.
    //(*intersection_point)[0] = ( (*intersection_point)[0]  - center[0] )* radius_inverse;
    //(*intersection_point)[1] = ( (*intersection_point)[1]  - center[1] )* radius_inverse;
    //(*intersection_point)[2] = ( (*intersection_point)[2]  - center[2] )* radius_inverse;

    return intersection_point;
}
