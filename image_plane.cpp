#include "image_plane.h"


image_plane::image_plane(Vector3d& top_left, Vector3d& top_right , Vector3d& bottom_left , Vector3d& camera_position , int p_width , int p_height )
{

    // dimensions of the image plane
    this->p_width = p_width;
    this->p_height = p_height;

    // the matrix that is used to store all virtual world vectors
//    co_ordinates.resize(NoChange, p_width*p_height);

    // initialzing the image plane virtual world vectors
    image_init(camera_position , top_left , top_right, bottom_left);
}

image_plane::image_plane()
{    };

image_plane::~image_plane()
{
    //dtor
}

bool image_plane::image_init( Vector3d& c_p , Vector3d& top_left , Vector3d& top_right , Vector3d& bottom_left ) // expecting the default camera position;
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
//---------------------------------------------------------

    // creating the vector in which we will add direction vectors
    Vector3d pivot = top_left;

    // creating direction vectors
    Vector3d H = (top_right - top_left);
    Vector3d V = (bottom_left - top_left);

    // initializing the pixels coordinates in real world
    double pixel_grid_width =  H.norm()*(1.0) / p_width;
    double pixel_grid_height = V.norm()*(1.0) / p_height;

    // normalizing the direction vectors
    H.normalize();
    V.normalize();

    // scaling H and V to pixel sizes
    H = pixel_grid_width * H;
    V = pixel_grid_height * V;

    // only half of the vertical vector is needed on the inner loop
    Vector3d V_temp = 0.5 * V;

    for (int i = 0 ; i < p_height ; i++)
    {
        std::vector<line> temp;
        for (int j = 0 ; j < p_width ; j++)
        {
            // calculating the co-ordinates of pixel's center
            Vector3d pixel_center = pivot + (j + 0.5) * H + V_temp;

            //cout << pixel_center << endl;

            // creating the ray
            line ray(c_p , pixel_center);

            // inserting the ray in temp vector
            temp.push_back(ray);
        }
        // pushing  in the primary ray vector
        image_rays.push_back(temp);

        // going to the next row
        pivot = pivot + V;

    }

    return true;
}

void image_plane::print_co_ordinates()
{
    for (auto i : image_rays)
    {
        for (auto j : i )
        {
            cout << j.to_point << endl;
        }
    }
}
