#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <fstream>
#include "point.h"
#include "scene.h"
#include "image_plane.h"
#include "color.h"
#include "object.h"
#include "sphere.h"
#include "vector.h"
#include "scene.h"
#include "line.h"
#include "camera.h"

using namespace Eigen;
using std::cout;
using std::endl;

// limits of the scene (scene scope)
#define MAX_WIDTH 5000
#define MAX_HEIGHT 5000
#define MAX_WEIGHT 5000

//func decls
void ray_cast(camera* c , sphere* s);
void save_ppm_image(camera* c);

int main()
{

    // starting point of image plane
    Vector4d p1(1,1,1,1);
    // camera position
   camera canon_5d_mk1 = camera(250 ,250, p1);

    // sphere
    Vector4d c = {0,0,-3,1};
    sphere s = sphere(c , 2);




    // casting the rays
    ray_cast(&canon_5d_mk1 , &s);
    save_ppm_image(&canon_5d_mk1);

    return 0;
}

void ray_cast(camera* c , sphere* s)
{
    int counter = 0;
    Vector4d* res;
    for(int i = 0; i < c->img->p_height ; i++)
    {
        for (int j = 0; j < c->img->p_width; j++)
        {
            res = s->collision_detection( &c->img->image_rays[i][j] );
            if (res != nullptr)
            {
                //assigning the color
                c->img->image_pixels[i][j].val = Vector3d(255,15,150);

                counter += 1;
            }
        }
    }
    cout << "# of intersections : " << counter << endl;
    return ;
}

void save_ppm_image(camera* c)
{

    // opening file stream
    std::ofstream myfile ;
    // opening file to write on
    myfile.open("ray_traced.ppm");
    // writing the header section of the image
    myfile << "P3 \n";
    // writing the dimensions of the image
    myfile << c->img->p_width << " " << c->img->p_height << "\n";
    // writing the max value of pixel intensity
    myfile << 255 << "\n";


    // WRITING PIXEL INFORMATION
    for (int i = 0 ; i != c->img->p_height ; i++ )
    {
        for (int j = 0; j < c->img->p_width ; j++)
        {
            for (int k = 0 ; k < 3 ; k ++)
            {
                myfile << c->img->image_pixels[i][j].val[k] << " ";
            }
        }

        myfile << "\n" ;
    }

    return;
}







