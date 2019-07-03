#ifndef IMAGE_PLANE_H
#define IMAGE_PLANE_H
#include "point.h"
#include "color.h"
#include <vector>
#include <iostream>
#include "line.h"

class image_plane
{
    public:
        image_plane(point position , point Q , int p_width , int p_height ,int width , int height);
        virtual ~image_plane();
        // procedure that initializes the image plane
        bool image_init(point);
        std::vector < std::vector <line> > image_rays;
        point Q;
    protected:

    private:
        // starting point
        point position;

        // resolution
        int p_width, p_height;

        // size of image plane in 3d virtual world
        int width , height;

        // data structure to hold the pixels = vectors of vectors
        std::vector < std::vector <color> > image_pixels;

        // data structure to hold the position values of pixels in real world


};



#endif // IMAGE_PLANE_H
