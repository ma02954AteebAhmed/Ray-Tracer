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

//func decls
void ray_cast(camera* c , sphere* s);
void save_ppm_image(camera* c);

int main()
{
    cout << "ma life" << endl;

    // starting point of image plane
    Vector3d camera_position(0,0,0);

    // initializing the image plane
    Vector3d top_left(-1,1,-1);
    Vector3d top_right(1,1,-1);
    Vector3d bottom_left(-1,-1,-1);

    image_plane im = image_plane(top_left, top_right, bottom_left , camera_position, 2000 , 2000);

    // camera position
    camera canon_5d_mk1 = camera(&im ,camera_position);

    // sphere
    Vector3d c = {1,-1,-10};
    sphere s = sphere(c , 4);

    //im.print_co_ordinates();

    // casting the rays
    ray_cast(&canon_5d_mk1 , &s);
    save_ppm_image(&canon_5d_mk1);


    /*
    // Checking collision mechanism
    Vector3d origin (0,0,0);
    Vector3d to_point(-0.5,0.5,-1);

    line* ray = new line(origin , to_point);
    Vector3d* collide = s.collision_detection(ray);

    cout <<     collide << endl;

    */



















    return 0;
}

void ray_cast(camera* c , sphere* s)
{
    int counter = 0;
    Vector3d* res;
    for(int i = 0; i < c->img->p_height ; i++)
    {
        for (int j = 0; j < c->img->p_width; j++)
        {
            res = s->collision_detection( &c->img->image_rays[i][j] );
            if (res != nullptr)
            {
                //assigning the color
                c->img->image_pixels[i][j].val = Vector3i(220,150,150);
                counter += 1;
            }
            else{
                c->img->image_pixels[i][j].val = Vector3i(255,255,255);
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
    for (int i = 0 ; i < c->img->p_height ; i++ )
    {
        for (int j = 0; j < c->img->p_width ; j++)
        {
            for (int k = 0 ; k < 3 ; k++)
            {
                myfile << c->img->image_pixels[i][j].val[k] << " ";
            }
        }

        myfile << "\n" ;
    }
    return;
}







