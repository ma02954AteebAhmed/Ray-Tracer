#include "camera.h"

camera::camera(int p_width , int p_height , Vector4d camera_position = Vector4d(0,0,0,1))
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

    // initializing the image plane
    Vector4d image_plane_postion = camera_position;

    // the image plane will always be 1 units away from the camera aligned on the z-axis
    image_plane_postion[2] += -1;
    // finally initializing the image plane..
    img = new image_plane( image_plane_postion , camera_position , p_width , p_height  );
}

camera::~camera()
{
    //dtor
}

void camera::translate(Vector4d pos)
{

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
            Vector4d temp = translation_matrix * img->image_rays[i][j].to_point;
            img->image_rays[i][j].recreate( camera_position , temp);
        }
    }

    return;
}
