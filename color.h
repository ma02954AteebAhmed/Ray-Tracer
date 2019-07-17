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
        color( Vector3i );
        //color information
        Vector3i val;

    protected:

    private:
};

#endif // COLOR_H
