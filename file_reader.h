#ifndef FILE_READER_H
#define FILE_READER_H
#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <fstream>
#include <vector>
#include "scene.h"
#include "triangle.h"
using namespace std;

class file_reader
{
    public:
        file_reader();
        virtual ~file_reader();

        // funcs
        bool read_ply2( string , scene* );
        void string_to_vector(Vector3d& , string&);
        triangle* string_to_face(string& , std::vector<Eigen::Vector3d>& v);

    protected:

    private:
};

#endif // FILE_READER_H
