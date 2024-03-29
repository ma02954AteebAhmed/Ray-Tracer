#include "plane.h"

plane::plane(Vector3d& A , Vector3d& B , Vector3d& C) : object()
{
    // calculating the normal
    this->normal = (A-B).cross(B-C);
    this->normal.normalize();

    // calculating the dot product
    double d = A.dot(normal);

}

plane::~plane()
{

}

bool plane::intersect( line* ray , Vector3i& color , double* t )
{
    // first we find v_d i.e. dot product of ray's direction vector and plane's normal vector
    // if v_d = 0 it means the ray is parallel to plane and hence no intersection will occur

    double v_d = ray->direction.dot( this->normal );
    bool hit = false;

    if (v_d == 0){ return hit; }
    else{
        // since the ray is not parallel to plane, we can proceed furthur
        // now we will find the dot product of plane's normal and ray's origin + d
        double v_o = -1 * ( ray->origin.dot(this->normal) + this->d );

        // now we calculate the value of "t"
        double t = v_o / v_d;
        // now we check if t < 0, it means the intersection between plane and ray lies behind
        // the ray's origin hence discarding it
        if (t < 0) {return hit;}
        else{
            // find the co-ordinates of the intersection
            Vector3d* intersection = new Vector3d( ray->origin[0] + t*ray->direction[0] ,
                                                   ray->origin[1] + t*ray->direction[1] ,
                                                   ray->origin[2] + t*ray->direction[2]
                                                  );
            hit = true;
            // assigning color to that pixel
            color[0] = 30;
            color[1] = 65;
            color[2] = 139;
            //cout << *intersection << endl;
            return hit;
        }
    }
}
