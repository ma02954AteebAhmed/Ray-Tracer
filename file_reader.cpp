#include "file_reader.h"

file_reader::file_reader()
{
    //ctor
}

file_reader::~file_reader()
{
    //dtor
}

bool file_reader::read_ply2( string path , scene* s )
{

   // reading file
   std::vector<Eigen::Vector3d> vertex_list;
   ifstream f(path);
   string line;

   // getting number of vertices
   getline(f,line);
   int num_vertices = stoi(line);

   // getting number of faces
   getline(f, line);
   int num_faces = stoi(line);

   // storing the vertices for later assignment
   for (int i = 0 ; i < num_vertices ; i++)
   {
       getline(f,line);
       Vector3d vertex;
       string_to_vector(vertex , line);
       // pushing the vector in the data structure
       vertex_list.push_back(vertex);
   }

   // now we create the polygons
   for (int i = 0 ; i < num_faces ; i++)
   {
       getline(f,line);
       s->add_object( string_to_face(line , vertex_list) );
   }

   cout << "file loaded successfully!" << endl;
   return 1;
}

triangle* file_reader::string_to_face( string& s , std::vector<Eigen::Vector3d>& v )
{
    string temp = "";
    vector<int> index;

    for (int i = 2; i < s.size() ; i++)
    {
        if (s[i] == ' '){

            index.push_back(stoi(temp));
            temp = "";
            continue;
        }
        temp += s[i];
    }

    triangle* t = new triangle( v[index[0]] , v[index[1]] , v[index[2]] );
    return t;

}

void file_reader::string_to_vector(Vector3d& v , string& s)
{

    string temp = "";
    int index = 0;

    for(auto i: s)
    {
        if (i == ' ')
        {
            v[index] = stod(temp);
            index += 1;
            temp = "";
            continue;
        }
        temp += i;
    }
}







