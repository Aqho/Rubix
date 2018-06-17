#include "headers/cube_rotation.hpp"
#include "../rubikscube/headers/cube.hpp"
#include "../rubikscube/headers/rubikscube.hpp"
#include "../render/headers/render.hpp"
#include <math.h>
#include <iostream>
#define PI 3.14159265

void cube_rotation::rotationU(rubiksCube *rubikscube_rotate)
{
    /*for (float angle = 0.0; angle < 90; angle=angle+0.2000)
     {
     for (int i = 0; i < 1; i++){
     for (int face = 0; face < 6; face++)
     {
     for (int vertex = 0; vertex < 4; vertex++)
     {
     for (int coord = 0; coord < 3; coord++)
     {
     //if (coord == 0){rubikscube_rotate->arrayCube[i].vertexcube[face][vertex][coord] = rubikscube_rotate->arrayCube[i].vertexcubebase[face][vertex][0]*cos(angle/180*PI)-rubikscube_rotate->arrayCube[i].vertexcubebase[face][vertex][1]*sin(angle/180*PI)+rubikscube_rotate->arrayCube[i].vertexcube[face][vertex][0];}
     //if (coord == 1){rubikscube_rotate->arrayCube[i].vertexcube[face][vertex][coord] = +rubikscube_rotate->arrayCube[i].vertexcubebase[face][vertex][0]*sin(angle/180*PI)+rubikscube_rotate->arrayCube[i].vertexcubebase[face][vertex][1]*cos(angle/180*PI)+rubikscube_rotate->arrayCube[i].vertexcube[face][vertex][2];}

     }
     }
     }
     }
     render actual_render;
     actual_render.Rendering(cam, rubikscube_rotate->arrayCube);
     }*/
    swapU(rubikscube_rotate);
}
void cube_rotation::rotationD(rubiksCube *rubikscube_rotate)
{
    swapD(rubikscube_rotate);
}
void cube_rotation::rotationF(rubiksCube *rubikscube_rotate)
{
    swapF(rubikscube_rotate);
}
void cube_rotation::rotationR(rubiksCube *rubikscube_rotate)
{
    swapR(rubikscube_rotate);
}
void cube_rotation::rotationB(rubiksCube *rubikscube_rotate)
{
    swapB(rubikscube_rotate);
}
void cube_rotation::rotationL(rubiksCube *rubikscube_rotate)
{
    swapL(rubikscube_rotate);
}
void cube_rotation::swapU(rubiksCube *rubikscube_rotate)
{
    for(int edge = 0; edge < 4; edge++)//Pour les 4 vertex par faces
    {
        for(int data = 6; data < 9; data++)//modification des données contenant le code couleur de la face.
        {
            //corner
            rubikscube_rotate->arrayCube[0].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[0].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[0].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[0].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[2][edge][data];

            //upper face
            rubikscube_rotate->arrayCube[0].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[1].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[3].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[5].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[4][edge][data];

            //edge
            rubikscube_rotate->arrayCube[1].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[1].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[1].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[1].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[5].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[5].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[5].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[5].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[3].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[3].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[3].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[3].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[2][edge][data];
        }
    }
    save(rubikscube_rotate);

}
void cube_rotation::swapD(rubiksCube *rubikscube_rotate)
{
    for(int cube = 18; cube<27; cube++)
    {
        for(int edge = 0; edge < 4; edge++)
        {
            for(int data = 6; data < 9; data++)
            {
                rubikscube_rotate->arrayCube[18].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[3][edge][data];
                rubikscube_rotate->arrayCube[18].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[2][edge][data];
                rubikscube_rotate->arrayCube[18].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[1][edge][data];
                rubikscube_rotate->arrayCube[18].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[0][edge][data];
                rubikscube_rotate->arrayCube[20].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[3][edge][data];
                rubikscube_rotate->arrayCube[20].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[2][edge][data];
                rubikscube_rotate->arrayCube[20].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[1][edge][data];
                rubikscube_rotate->arrayCube[20].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[0][edge][data];
                rubikscube_rotate->arrayCube[26].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[3][edge][data];
                rubikscube_rotate->arrayCube[26].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[2][edge][data];
                rubikscube_rotate->arrayCube[26].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[1][edge][data];
                rubikscube_rotate->arrayCube[26].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[0][edge][data];
                rubikscube_rotate->arrayCube[24].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[3][edge][data];
                rubikscube_rotate->arrayCube[24].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[2][edge][data];
                rubikscube_rotate->arrayCube[24].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[1][edge][data];
                rubikscube_rotate->arrayCube[24].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[0][edge][data];
                //upper face
                rubikscube_rotate->arrayCube[18].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[5][edge][data];
                rubikscube_rotate->arrayCube[19].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[5][edge][data];
                rubikscube_rotate->arrayCube[20].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[5][edge][data];
                rubikscube_rotate->arrayCube[21].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[5][edge][data];
                rubikscube_rotate->arrayCube[23].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[5][edge][data];
                rubikscube_rotate->arrayCube[24].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[5][edge][data];
                rubikscube_rotate->arrayCube[25].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[5][edge][data];
                rubikscube_rotate->arrayCube[26].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[5][edge][data];
                //edge
                rubikscube_rotate->arrayCube[19].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[3][edge][data];
                rubikscube_rotate->arrayCube[19].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[2][edge][data];
                rubikscube_rotate->arrayCube[19].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[1][edge][data];
                rubikscube_rotate->arrayCube[19].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[0][edge][data];
                rubikscube_rotate->arrayCube[23].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[3][edge][data];
                rubikscube_rotate->arrayCube[23].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[2][edge][data];
                rubikscube_rotate->arrayCube[23].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[1][edge][data];
                rubikscube_rotate->arrayCube[23].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[0][edge][data];
                rubikscube_rotate->arrayCube[25].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[3][edge][data];
                rubikscube_rotate->arrayCube[25].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[2][edge][data];
                rubikscube_rotate->arrayCube[25].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[1][edge][data];
                rubikscube_rotate->arrayCube[25].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[0][edge][data];
                rubikscube_rotate->arrayCube[21].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[3][edge][data];
                rubikscube_rotate->arrayCube[21].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[2][edge][data];
                rubikscube_rotate->arrayCube[21].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[1][edge][data];
                rubikscube_rotate->arrayCube[21].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[0][edge][data];

            }
        }
    }
    save(rubikscube_rotate);
}
void cube_rotation::swapF(rubiksCube *rubikscube_rotate)
{
    for(int edge = 0; edge < 4; edge++)//6 7 8 9 15 16 17 24 25 26
    {
        for(int data = 6; data < 9; data++)
        {
            rubikscube_rotate->arrayCube[0].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[3][edge][data];//corner
            rubikscube_rotate->arrayCube[0].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[0].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[0].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[4][edge][data];

            rubikscube_rotate->arrayCube[0].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[3].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[21].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[0][edge][data];

            rubikscube_rotate->arrayCube[3].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[3][edge][data];//edge
            rubikscube_rotate->arrayCube[3].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[3].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[3].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[3].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[21].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[21].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[21].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[21].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[21].vertexcubebase[4][edge][data];
        }
    }
    save(rubikscube_rotate);
}
void cube_rotation::swapR(rubiksCube *rubikscube_rotate)
{
    for(int edge = 0; edge < 4; edge++)//6 7 8 9 15 16 17 24 25 26
    {
        for(int data = 6; data < 9; data++)
        {
            //corner
            rubikscube_rotate->arrayCube[8].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[4][edge][data];


            //upper face
            rubikscube_rotate->arrayCube[8].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[6].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[6].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[24].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[24].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[25].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[1][edge][data];
            //edge
            rubikscube_rotate->arrayCube[7].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[7].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[15].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[15].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[25].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[25].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[25].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[25].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[25].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[7].vertexcubebase[4][edge][data];
        }
    }
    save(rubikscube_rotate);
}
void cube_rotation::swapB(rubiksCube *rubikscube_rotate)
{
    for(int edge = 0; edge < 4; edge++)//6 7 8 9 15 16 17 24 25 26
    {
        for(int data = 6; data < 9; data++)
        {
            rubikscube_rotate->arrayCube[2].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[1][edge][data];//corner
            rubikscube_rotate->arrayCube[2].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[5][edge][data];

            rubikscube_rotate->arrayCube[2].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[8].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[5].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[8].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[26].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[23].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[26].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[2][edge][data];

            rubikscube_rotate->arrayCube[5].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[1][edge][data];//edge
            rubikscube_rotate->arrayCube[5].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[5].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[5].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[17].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[17].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[23].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[23].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[23].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[23].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[23].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[1][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[1][edge][data] = rubikscube_rotate->arrayCube[5].vertexcubebase[5][edge][data];
        }
    }
    save(rubikscube_rotate);

}
void cube_rotation::swapL(rubiksCube *rubikscube_rotate)
{
    for(int edge = 0; edge < 4; edge++)//6 7 8 9 15 16 17 24 25 26
    {
        for(int data = 6; data < 9; data++)
        {
            //corner
            rubikscube_rotate->arrayCube[0].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[0].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[0].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[0].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[0][edge][data];
            //upper face
            rubikscube_rotate->arrayCube[0].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[2].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[2].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[20].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[20].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[18].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[18].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[0].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[1].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[19].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[3][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[3][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[3][edge][data];
            //edge
            rubikscube_rotate->arrayCube[1].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[1].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[1].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[1].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[11].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[11].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[19].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[19].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[19].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[19].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[19].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[9].vertexcubebase[0][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[0][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[4][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[4][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[2][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[2][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[5][edge][data];
            rubikscube_rotate->arrayCube[9].vertexcube[5][edge][data] = rubikscube_rotate->arrayCube[1].vertexcubebase[0][edge][data];
        }
    }
    save(rubikscube_rotate);
}

void cube_rotation::save(rubiksCube *rubikscube_rotate)
{
    for(int cubes = 0; cubes < 27; cubes++)
    {
        for(int edge = 0; edge < 4; edge++)//6 7 8 9 15 16 17 24 25 26
        {
            for(int data = 6; data < 9; data++)
            {
                rubikscube_rotate->arrayCube[cubes].vertexcubebase[0][edge][data] = rubikscube_rotate->arrayCube[cubes].vertexcube[0][edge][data];
                rubikscube_rotate->arrayCube[cubes].vertexcubebase[1][edge][data] = rubikscube_rotate->arrayCube[cubes].vertexcube[1][edge][data];
                rubikscube_rotate->arrayCube[cubes].vertexcubebase[2][edge][data] = rubikscube_rotate->arrayCube[cubes].vertexcube[2][edge][data];
                rubikscube_rotate->arrayCube[cubes].vertexcubebase[3][edge][data] = rubikscube_rotate->arrayCube[cubes].vertexcube[3][edge][data];
                rubikscube_rotate->arrayCube[cubes].vertexcubebase[4][edge][data] = rubikscube_rotate->arrayCube[cubes].vertexcube[4][edge][data];
                rubikscube_rotate->arrayCube[cubes].vertexcubebase[5][edge][data] = rubikscube_rotate->arrayCube[cubes].vertexcube[5][edge][data];

            }
        }
    }
}
