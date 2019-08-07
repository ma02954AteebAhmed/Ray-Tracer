#include "triangle.h"

triangle::triangle(Vector3d A , Vector3d  B , Vector3d C )
{
    this-> A = A;
    this-> B = B;
    this-> C = C;
    // calculating the normal
    this->normal = (C-A).cross(B-A);
    this->normal.normalize();

    // calculating d
    this->d = (B-A).dot(this->normal);


}

triangle::~triangle()
{
    //dtor
}

bool triangle::intersect( line* ray , Vector3i& color , double& t_out )
{
    // the first step is to see if ray intersect with the plane formed by triangle
    // for that i will paste the whole plane's collision_detection method here
    // in this method
    // PLANES COLLISION_DETECTION FUNCTION
        // first we find v_d i.e. dot product of ray's direction vector and plane's normal vector
    // if v_d = 0 it means the ray is parallel to plane and hence no intersection will occur

    Vector3d P;
    double t;
    double v_d = ray->direction.dot( this->normal );
    bool hit = false;
    if (v_d == 0){ return hit; }
    else{
        // since the ray is not parallel to plane, we can proceed furthur
        // now we will find the dot product of plane's normal and ray's origin + d
        double v_o = -1 * ( ray->origin.dot(this->normal) + this->d );

        // now we calculate the value of "t"
        t = v_o / v_d;
        // now we check if t < 0, it means the intersection between plane and ray lies behind
        // the ray's origin hence discarding it
        if (t < 0) {return hit;}
        else{
            // find the co-ordinates of the intersection
            P[0] =  ray->origin[0] + t*ray->direction[0];
            P[1] =  ray->origin[1] + t*ray->direction[1];
            P[2] =  ray->origin[2] + t*ray->direction[2];
            }
        }
    // the above code will return the vector "intersection".
    // NOW we check whether the point of intersection lies inside the triangle for that we calculate the
    // barycentric co-ordinates of the point P.

    // TO FIND THE BARY-CENTRIC CO-ORDINATES WE CALCULATE THE RATIO OF AREAS OF THREE TRIANGLES FORMED DUE TO POINT P.

    /*
    // MY METHOD

    // First we calculate the area of whole triangle
    double area_ABC_inv = 1 / ( (B-A).cross(C-A) ).norm();

    // Now we calculate the area of all 3 sub-triangle
    double u = ( (C-A).cross(*P-C) ).norm() * area_ABC_inv; // area APC
    double v = ( (A-B).cross(*P-B) ).norm() * area_ABC_inv; // area ABP
    double w = ( (B-C).cross(*P-B) ).norm() * area_ABC_inv; // area BPC
    // the next step is to check if 1 >= u+v
    if ( u >= 0 && u <= 1 && v >=0 && v <= 1 && w >=0 && w <= 1  && 1-(u+v+w) >= -1e-8 && 1-(u+v+w) <= 1e-8 )
    {

        color[0] = u*255;
        color[1] = v*255;
        color[2] = w*255;

        return P;
    }
    else{return nullptr;}
    */


    // ALGORITHM FROM THE BOOK BY CHRISTER ERICSON
    // Compute vectors

    Vector3d v0 = C - A;
    Vector3d v1 = B - A;
    Vector3d v2 = P - A;

    // Compute dot products
    double dot00 = v0.dot(v0);
    double dot01 = v0.dot(v1);
    double dot02 = v0.dot(v2);
    double dot11 = v1.dot(v1);
    double dot12 = v1.dot(v2);

    // Compute barycentric coordinates
    double invDenom = 1 / (dot00 * dot11 - dot01 * dot01);

    double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is in triangle

    if ((u >= 0) && (v >= 0) && (u + v < 1))
    {
        color[0] = u*255;
        color[1] = v*255;
        color[2] = (1-u-v)*255;
        hit = true;
        t_out = t;
        return hit;
    }
    else {return hit;}

}
