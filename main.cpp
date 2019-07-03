#include <iostream>
#include "point.h"
#include "scene.h"
#include "image_plane.h"
#include "color.h"
#include <vector>
#include "object.h"
#include "sphere.h"
#include "vector.h"


// limits of the scene (scene scope)
#define MAX_WIDTH 5000
#define MAX_HEIGHT 5000
#define MAX_WEIGHT 5000



int main()
{
    /*
    // starting point of image plane
    point p = {15,55,28};

    // camera position
    point camera_position = {1,55, 22};

    // initializing the image plane
    image_plane im = image_plane(p , 1280,720,1,1);
    im.image_init(camera_position);
*/
    // testing intersection
    point u = {0,0,0};
    point v = {3.38,2.88,2.61};
    line* ray = new line(u,v);
    vector c = {5,4,3};
    sphere s = sphere(c , 2);
    vector* p = s.collision_detection(ray);

    std::cout << p->x << ","<< p->y << ","<< p->z << std::endl;



    return 0;
}












