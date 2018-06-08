#include "headers/cube.hpp"
#include <math.h>
#define PI 3.14159265

#include <iostream>

void cube::receive_coordonate(float x, float y, float z, float Ox, float Oy, float Oz)
{
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
}
/*
 {Y
 if (coord == 0){vertexcube[face][vertex][coord] = -vertexcubebase[face][vertex][1]*cos(Oy)+vertexcubebase[face][vertex][0]*sin(Oy)+x;}
 if (coord == 1){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][1]*sin(Oy)+vertexcubebase[face][vertex][0]*cos(Oy)+z;}
 }
 {Z
 if (coord == 0){vertexcube[face][vertex][coord] = -vertexcubebase[face][vertex][2]*cos(Oy)+vertexcubebase[face][vertex][0]*sin(Oy)+x;}
 if (coord == 2){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][2]*sin(Oy)+vertexcubebase[face][vertex][0]*cos(Oy)+z;}
 }
 {X
 if (coord == 1){vertexcube[face][vertex][coord] = -vertexcubebase[face][vertex][2]*cos(Oy)+vertexcubebase[face][vertex][1]*sin(Oy)+x;}
 if (coord == 2){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][2]*sin(Oy)+vertexcubebase[face][vertex][1]*cos(Oy)+z;}
 }

 if (coord == 0){vertexcube[face][vertex][coord] = -vertexcubebase[face][vertex][1]*cos(Oy)+vertexcubebase[face][vertex][0]*sin(Oy) + -vertexcubebase[face][vertex][2]*cos(Oz)+vertexcubebase[face][vertex][0]*sin(Oz)+x;}
 if (coord == 1){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][1]*sin(Oy)+vertexcubebase[face][vertex][0]*cos(Oy) + -vertexcubebase[face][vertex][2]*cos(Ox)+vertexcubebase[face][vertex][1]*sin(Ox)+x;}
 if (coord == 2){vertexcube[face][vertex][coord] = vertexcubebase[face][vertex][2]*sin(Oz)+vertexcubebase[face][vertex][0]*cos(Oz) + vertexcubebase[face][vertex][2]*sin(Ox)+vertexcubebase[face][vertex][1]*cos(Ox)+z;}
*/





 /*
 float vertexcube[6][4][9] = {{{0.5f,0.5f,-0.5f   ,0,0,0,   0.0,1.0,0.0}, {-0.5,0.5,-0.5   ,0,0,0,   0.0,1.0,0.0}, {-0.5,0.5,0.5   ,0,0,0,   0.0,1.0,0.0}, {0.5,0.5,0.5   ,0,0,0,   0.0,1.0,0.0}},{{0.5,-0.5,0.5   ,0,0,0,   0.0,0.0,1.0},{-0.5,-0.5,0.5   ,0,0,0,   0.0,0.0,1.0},{-0.5,-0.5,-0.5   ,0,0,0,   0.0,0.0,1.0},{0.5,-0.5,-0.5   ,0,0,0,   0.0,0.0,1.0}},{{0.5,0.5,0.5   ,0,0,0,   1.0,1.0,1.0},{-0.5,0.5,0.5   ,0,0,0,   1.0,1.0,1.0},{-0.5,-0.5,0.5   ,0,0,0,   1.0,1.0,1.0},{0.5,-0.5,0.5   ,0,0,0,   1.0,1.0,1.0}},{{0.5,-0.5,-0.5   ,0,0,0,   1.0,1.0,0.0},{-0.5,-0.5,-0.5   ,0,0,0,   1.0,1.0,0.0},{-0.5,0.5,-0.5   ,0,0,0,   1.0,1.0,0.0},{0.5,0.5,-0.5   ,0,0,0,   1.0,1.0,0.0}},{{-0.5,0.5,0.5   ,0,0,0,   1.0,0.0,0.0},{-0.5,0.5,-0.5   ,0,0,0,   1.0,0.0,0.0},{-0.5,-0.5,-0.5   ,0,0,0,   1.0,0.0,0.0},{-0.5,-0.5,0.5   ,0,0,0,   1.0,0.0,0.0}},{{0.5,0.5,-0.5   ,0,0,0,   1.0,0.5,0.0},{0.5,0.5,0.5   ,0,0,0,   1.0,0.5,0.0},{0.5,-0.5,0.5   ,0,0,0,   1.0,0.5,0.0},{0.5,-0.5,-0.5   ,0,0,0,   1.0,0.5,0.0}}};

 float vertex1[9] = {0.5,0.5,0.5   ,0,0,0,   0.0,1.0,0.0}; //green[0]
 float vertex2[9] = {0.5,0.5,0.5   ,0,0,0,   0.0,1.0,0.0}; //green
 float vertex3[9] = {0.5,0.5,0.5   ,0,0,0,   0.0,1.0,0.0}; //green
 float vertex4[9] = {0.5,0.5,0.5   ,0,0,0,   0.0,1.0,0.0}; //green

 */
