#ifndef COLOR_H
#define COLOR_H
#include <Eigen/Dense>
using namespace Eigen;

class color
{
    public:
        color();
        virtual ~color();
        color(int r, int g , int b);
        color( Vector3d );
        //color information
        Vector3d val;

    protected:

    private:
};

#endif // COLOR_H
