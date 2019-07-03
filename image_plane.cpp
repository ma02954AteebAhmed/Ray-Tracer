#include "image_plane.h"

image_plane::image_plane(point position ,point Q , int p_width , int p_height , int width , int height)
{
    this->position = position;
    this->p_width = p_width;
    this->width = width;
    this->p_height = p_height;
    this->height = height;
    this->Q = Q;
}

image_plane::~image_plane()
{
    //dtor
}

bool image_plane::image_init(point camera_position)
{
    // initializing the pixels with all blacks
    for (int i = 0 ; i < p_height ; i++)
    {
        std::vector<color> temp;
        for (int j = 0 ; j < p_width ; j++)
        {
            color temp_color = {0,0,0};
            temp.push_back(temp_color);

        }
        image_pixels.push_back(temp);
    }

    // initializing the pixels rays in real world
    double del = 0.1;
    double half_del = 0.1/2;
    double x = position.x;
    double y = position.y;
    double z = position.z;

    for (int i = 0 ; i < p_height ; i++)
    {
        std::vector<line> temp;

        // for efficient operation
        double y_del = i*del;
        double x_del = 0;

        for (int j = 0 ; j < p_width ; j++)
        {
            x_del += del;
            point temp_mid_point = { x + x_del + half_del , y + y_del + half_del , z };
            line temp_line = line( camera_position , temp_mid_point);
            temp.push_back(temp_line);
        }
        image_rays.push_back(temp);
    }
    std::cout << image_rays.size() << std::endl;
    return true;
}
