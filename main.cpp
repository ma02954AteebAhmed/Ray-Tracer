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
#include "plane.h"
#include "triangle.h"
#include "windows.h"
using namespace Eigen;
using std::cout;
using std::endl;


//func decls
void ray_cast(camera* c , scene* s);
void save_ppm_image(camera* c);

int main()
{
    // starting point of image plane
    Vector3d camera_position(0,0,10);

    // initializing the image plane
    Vector3d top_left(-1,1,9);
    Vector3d top_right(1,1,9);
    Vector3d bottom_left(-1,-1,9);

    image_plane im = image_plane(top_left, top_right, bottom_left , camera_position, 500 , 500 );

    // camera position
    camera canon_5d_mk1 = camera(&im ,camera_position);

    // sphere
    Vector3d c = {0,0,-5};
    sphere s = sphere(c , 5);
    Vector3d c1 = {0,0,-7};
    sphere s1 = sphere(c1 , 0.5);

    Vector3d p_n = {0,0,-1};
    plane p(p_n , -5);

    // creating a triangle
    triangle t;
    //vertices
    t.A[0] = 10; t.A[1] = 0; t.A[2] = -5;

    t.C[0] = 3.5; t.C[1] = 10; t.C[2] = -5;

    t.B[0] = -3; t.B[1] = -2; t.B[2] = -5;

    // normals
    t.normal[0] = 0; t.normal[1] = 0; t.normal[2] = -1;
    t.d = -5;

    // stage
    scene stage;
    stage.add_object(&p);
    //stage.add_object(&s);
    stage.add_object(&t);

    // vertices of triangle

    //sphere A =  sphere(Vector3d(0,0,-5) , 3);
    //sphere B =  sphere(Vector3d(-3,-2,-5) , 2);
    //sphere C =  sphere(Vector3d(0,10,-5) , 2);


    //stage.add_object(&A);
    //stage.add_object(&B);
    //stage.add_object(&C);



    //stage.add_object(&s1);


    // casting the rays
    ray_cast(&canon_5d_mk1 , &stage);
    save_ppm_image(&canon_5d_mk1);

    // viewing the image
    ShellExecute(NULL, NULL , "C:\\Users\\ateeb\\Desktop\\Bo Qian c++\\ray tracer\\OpenSeeIt.exe" ,
                 "ray_traced.ppm", NULL , SW_SHOWNORMAL);

    return 0;
}


void ray_cast(camera* c , scene* s)
{
    int counter = 0;
    Vector3d* res;

    for (auto& o : s->elements)
    {
        for(int i = 0 ; i < c->img->p_height ; i++)
        {
            for (int j = 0 ; j < c->img->p_width ; j++)
            {
                res = o->collision_detection( &c->img->image_rays[i][j] , c->img->image_pixels[i][j].val);
                if (res != nullptr)
                {
                    //assigning the color
                    counter += 1;
                }
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







