#include "image_plane.h"


image_plane::image_plane(Vector4d position , Vector4d camera_position , int p_width , int p_height )
{
    // initializing the image plane position ( the center of image plane )
    this->position = position;

    // dimensions of the image plane
    this->p_width = p_width;
    this->p_height = p_height;

    // the matrix that is used to store all virtual world vectors
//    co_ordinates.resize(NoChange, p_width*p_height);

    // initialzing the image plane virtual world vectors
    image_init(camera_position);
}

image_plane::image_plane(){
    cout << "auto constructor " << endl;
};

image_plane::~image_plane()
{
    //dtor
}

bool image_plane::image_init(Vector4d c_p) // expecting the default camera position;
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

    // initializing the pixels coordinates in real world
    double pixelNDC_x , pixelNDC_y , screen_x , screen_y;
    int counter = 0;
    for (int i = 0 ; i < p_height ; i++)
    {
        std::vector<line> temp;

        pixelNDC_y = ( i + 0.5 ) / p_height;
        screen_y = 1 - 2*pixelNDC_y;


        for (int j = 0 ; j < p_width ; j++)
        {
            pixelNDC_x = ( j + 0.5 ) / p_width;
            screen_x = 2*pixelNDC_x - 1;

            Vector4d p_l (screen_x , screen_y , this->position[2], 1); // p_l = pixel_location
            line ray(c_p , p_l);

            // inserting in matrix
  /*
            for ( int k = 0; k < 4 ; k++)
            {
                co_ordinates(counter) = p_l[k];
                counter+= 1;
            }
    */
            // inserting the ray in temp vector
            temp.push_back(ray);
        }
        // pushing  in the primary ray vector
        image_rays.push_back(temp);;
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
