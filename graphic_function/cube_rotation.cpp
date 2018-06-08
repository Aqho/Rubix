#include "cube_rotation.hpp"
#include "../rubikscube/headers/cube.hpp"
#include "../rubikscube/headers/rubikscube.hpp"
#include <math.h>

void rotation_cube::rotationU(float Ox, float Oy, float Oz,cube cube_rotate)
{
    for (int face = 0; face < 6; face++)
    {
        for (int vertex = 0; vertex < 4; vertex++)
        {
            for (int coord = 0; coord < 3; coord++)
            {
                if (Ox ==0 && Oy == 0 && Oz !=0)
                {
                    if (coord == 0){cube_rotate.vertexcube[face][vertex][coord] = cube_rotate.vertexcubebase[face][vertex][0]*cos(Oz)-cube_rotate.vertexcubebase[face][vertex][1]*sin(Oz)+cube_rotate.vertexcube[face][vertex][0];}
                    if (coord == 1){cube_rotate.vertexcube[face][vertex][coord] = +cube_rotate.vertexcubebase[face][vertex][0]*sin(Oz)+cube_rotate.vertexcubebase[face][vertex][1]*cos(Oz)+cube_rotate.vertexcube[face][vertex][2];}
                }
            }
        }
    }
}
void rotation_cube::rotationcube(float Ox, float Oy, float Oz,cube cube_rotate)
{
    for (int face = 0; face < 6; face++)
    {
        for (int vertex = 0; vertex < 4; vertex++)
        {
            for (int coord = 0; coord < 3; coord++)
            {
                if (Ox ==0 && Oy == 0 && Oz !=0)
                {
                    if (coord == 0){cube_rotate.vertexcube[face][vertex][coord] = cube_rotate.vertexcubebase[face][vertex][0]*cos(Oz)-cube_rotate.vertexcubebase[face][vertex][1]*sin(Oz)+cube_rotate.vertexcube[face][vertex][0];}
                    if (coord == 1){cube_rotate.vertexcube[face][vertex][coord] = +cube_rotate.vertexcubebase[face][vertex][0]*sin(Oz)+cube_rotate.vertexcubebase[face][vertex][1]*cos(Oz)+cube_rotate.vertexcube[face][vertex][2];}
                }
            }
        }
    }
}
