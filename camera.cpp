#include "camera.h"

camera::camera(image_plane* img , Vector3d camera_position = Vector3d(0,0,0))
{

    // default camera position
    this->camera_position = camera_position;

    // initializing the matrix for translation
    translation_matrix << 1,0,0,0,
                          0,1,0,0,
                          0,0,1,0,
                          0,0,0,1;

    // initializing the transition matrix
    //transition_mat.resize(NoChange , p_height*p_width);

    // finally initializing the image plane..
    this->img = img;
}

camera::~camera()
{
    //dtor
}

void camera::translate(Vector3d pos)
{
/*
    // first we are going to translate every pixel in image plane
    translation_matrix(0,3) = pos[0];
    translation_matrix(1,3) = pos[1];
    translation_matrix(2,3) = pos[2];

    // changing the camera position
    camera_position = translation_matrix * camera_position;
    cout << "camera position: " << camera_position << endl;

    //   now we are going to apply translation to all pixel vectors
    for (int i = 0; i < img->p_height ; i++)
    {
        for (int j = 0 ; j < img->p_width ; j++)
        {
            Vector3d temp = translation_matrix * img->image_rays[i][j].to_point;
            img->image_rays[i][j].recreate( camera_position , temp);
        }
    }

    return;
*/
}
