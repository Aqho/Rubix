#include "cube_rotation.hpp"
#include "../rubixcube/headers/cube.hpp"

void rotation_cube::rotation(float Ox, float Oy, float Oz,cube cube_rotate)
{

};


/*
 for (int face = 0; face < 6; face++)
{
    for (int vertex = 0; vertex < 4; vertex++)
    {
        for (int coord = 0; coord < 3; coord++)
        {
            if (coord == 0){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][coord]+x;}
            if (coord == 1){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][coord]+y;}
            if (coord == 2){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][coord]+z;}
            if (Ox !=0 && Oy == 0 && Oz ==0)
            {
                if (coord == 0){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][0]*cos(Oz)-vertexcubebase[face][vertex][1]*sin(Oz)+x;}
                if (coord == 1){vertexcube[face][vertex][coord] = +vertexcubebase[face][vertex][0]*sin(Oz)+vertexcubebase[face][vertex][1]*cos(Oz)+z;}
            }
            if (Ox ==0 && Oy != 0 && Oz ==0)
            {
                std::cout << Oy << std::endl;
                if (coord == 0){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][0]*cos(Oy)-vertexcubebase[face][vertex][1]*sin(Oy)+x;}
                if (coord == 1){vertexcube[face][vertex][coord] = +vertexcubebase[face][vertex][0]*sin(Oy)+vertexcubebase[face][vertex][1]*cos(Oy)+z;}
                }
                if (Ox ==0 && Oy == 0 && Oz !=0)
                {
                    if (coord == 0){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][0]*cos(Oz)-vertexcubebase[face][vertex][1]*sin(Oz)+x;}
                    if (coord == 1){vertexcube[face][vertex][coord] = +vertexcubebase[face][vertex][0]*sin(Oz)+vertexcubebase[face][vertex][1]*cos(Oz)+z;}
                    
                }
                }
                }
                }
*/
