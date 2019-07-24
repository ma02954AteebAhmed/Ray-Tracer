#ifndef IMAGE_PLANE_H
#define IMAGE_PLANE_H
#include<Eigen/Dense>
#include "color.h"
#include <vector>
#include <iostream>
#include "line.h"
using namespace Eigen;
using std::cout ;
using std::endl ;

class image_plane
{
    public:

        // METHODS
        image_plane();

        image_plane(Vector3d& top_left, Vector3d& top_right, Vector3d& bottom_left , Vector3d& camera_position , int p_width , int p_height );
        virtual ~image_plane();

        // procedure that initializes the image plane
        bool image_init(Vector3d& , Vector3d& , Vector3d& , Vector3d&);

        // procedure to print the rays vectors
        void print_co_ordinates();


        // ATTRIBUTES
        std::vector < std::vector <line> > image_rays;

        // storing this matrix for efficient multiplication
        //Matrix <double, 4, Dynamic> co_ordinates;

        int p_width, p_height;

        // starting point
        Vector3d position;

        // data structure to hold the pixels = vectors of vectors
        std::vector < std::vector <color> > image_pixels;

    protected:
    private:

        // resolution
        // data structure to hold the position values of pixels in real world
};
#endif // IMAGE_PLANE_H
