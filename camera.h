#ifndef CAMERA_H
#define CAMERA_H
#include "image_plane.h"
#include <Eigen/Dense>
using namespace Eigen;

class camera
{
    public:
        camera(int , int , Vector4d);
        virtual ~camera();
        Matrix4d translation_matrix ;

        // to control translation of image plane and camera
        void translate( Vector4d );

        // camera default position
        Vector4d camera_position;

        //  transition Matrix it is used to store intermediate results when
        //  applying translation to image plane
        //Matrix <double, 4, Dynamic> transition_mat;

        // image plane
        image_plane* img;
    protected:

    private:
        // the camera should have an image plane



        // camera translation matrix

};

#endif // CAMERA_H
