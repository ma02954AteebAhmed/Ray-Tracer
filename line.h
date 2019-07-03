#ifndef LINE_H
#define LINE_H
#include "vector.h"
#include "point.h"


class line
{
    public:
        line( vector , vector );
        line(point , point );
        virtual ~line();

        // for calculating the direction vector
        void calc_direction(vector start, vector End);
        void calc_direction(point start, point End);
        // direction vector
        vector direction;
        // starting position of line
        vector origin;

    protected:

    private:


};

#endif // LINE_H
