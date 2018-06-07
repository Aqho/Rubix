#include "cube_rotation.hpp"
#include "../rubikscube/headers/cube.hpp"

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
/*
// This function takes the face's number parameter which you want to rotate clockwise
void rotation_cube::rotateFaceColors(rubiksCube *cube, int face){
  char tempColors[6][9];
  for (int i=0; i<6; i++){
     for (int j=0; j<9; j++){
        tempColors[i][j]=cube->colors[i][j];
     }
  }
  cube->colors[face][0]=tempColors[face][6];
  cube->colors[face][1]=tempColors[face][7];
  cube->colors[face][2]=tempColors[face][0];
  cube->colors[face][3]=tempColors[face][1];
  cube->colors[face][4]=tempColors[face][2];
  cube->colors[face][5]=tempColors[face][3];
  cube->colors[face][6]=tempColors[face][4];
  cube->colors[face][7]=tempColors[face][5];
}

void rotation_cube::rotateGreenFace(rubiksCube *cube){
  // Rotate green face clockwise
  rotation_cube::rotateFaceColors(cube, 0);
  // Rotate involved lines
  char tempColors[6][9];
  for (int i=0; i<6; i++){
     for (int j=0; j<9; j++){
        tempColors[i][j]=cube->colors[i][j];
     }
  }
  cube->colors[1][6]=tempColors[2][4];
  cube->colors[1][5]=tempColors[2][3];
  cube->colors[1][4]=tempColors[2][2];
  cube->colors[4][0]=tempColors[1][6];
  cube->colors[4][7]=tempColors[1][5];
  cube->colors[4][6]=tempColors[1][4];
  cube->colors[3][2]=tempColors[4][0];
  cube->colors[3][1]=tempColors[4][7];
  cube->colors[3][0]=tempColors[4][6];
  cube->colors[2][4]=tempColors[3][2];
  cube->colors[2][3]=tempColors[3][1];
  cube->colors[2][2]=tempColors[3][0];
}

void rotation_cube::rotateWhiteFace(rubiksCube *cube){
  // Rotate white face clockwise
  rotation_cube::rotateFaceColors(cube, 1);
  // Rotate involved lines
  char tempColors[6][9];
  for (int i=0; i<6; i++){
     for (int j=0; j<9; j++){
        tempColors[i][j]=cube->colors[i][j];
     }
  }
  cube->colors[0][2]=tempColors[4][2];
  cube->colors[0][1]=tempColors[4][1];
  cube->colors[0][0]=tempColors[4][0];
  cube->colors[2][2]=tempColors[0][2];
  cube->colors[2][1]=tempColors[0][1];
  cube->colors[2][0]=tempColors[0][0];
  cube->colors[5][0]=tempColors[2][0];
  cube->colors[5][1]=tempColors[2][1];
  cube->colors[5][2]=tempColors[2][2];
  cube->colors[4][0]=tempColors[5][0];
  cube->colors[4][1]=tempColors[5][1];
  cube->colors[4][2]=tempColors[5][2];
}

void rotation_cube::rotateOrangeFace(rubiksCube *cube){
  // Rotate orange face clockwise
  rotation_cube::rotateFaceColors(cube, 2);
  // Rotate involved lines
  char tempColors[6][9];
  for (int i=0; i<6; i++){
     for (int j=0; j<9; j++){
        tempColors[i][j]=cube->colors[i][j];
     }
  }
  cube->colors[0][0]=tempColors[1][0];
  cube->colors[0][7]=tempColors[1][7];
  cube->colors[0][6]=tempColors[1][6];
  cube->colors[3][0]=tempColors[0][0];
  cube->colors[3][6]=tempColors[0][7];
  cube->colors[3][7]=tempColors[0][6];
  cube->colors[5][4]=tempColors[3][0];
  cube->colors[5][3]=tempColors[3][6];
  cube->colors[5][2]=tempColors[3][7];
  cube->colors[1][0]=tempColors[5][4];
  cube->colors[1][7]=tempColors[5][3];
  cube->colors[1][6]=tempColors[5][2];
}

void rotation_cube::rotateYellowFace(rubiksCube *cube){
  // Rotate yellow face clockwise
  rotation_cube::rotateFaceColors(cube, 3);
  // Rotate involved lines
  char tempColors[6][9];
  for (int i=0; i<6; i++){
     for (int j=0; j<9; j++){
        tempColors[i][j]=cube->colors[i][j];
     }
  }
  cube->colors[0][6]=tempColors[2][6];
  cube->colors[0][5]=tempColors[2][5];
  cube->colors[0][4]=tempColors[2][4];
  cube->colors[4][6]=tempColors[0][6];
  cube->colors[4][5]=tempColors[0][5];
  cube->colors[4][4]=tempColors[0][4];
  cube->colors[5][6]=tempColors[4][6];
  cube->colors[5][5]=tempColors[4][5];
  cube->colors[5][4]=tempColors[4][4];
  cube->colors[2][6]=tempColors[5][6];
  cube->colors[2][5]=tempColors[5][5];
  cube->colors[2][4]=tempColors[5][4];
}

void rotation_cube::rotateRedFace(rubiksCube *cube){
  // Rotate red face clockwise
  rotation_cube::rotateFaceColors(cube, 4);
  // Rotate involved lines
  char tempColors[6][9];
  for (int i=0; i<6; i++){
     for (int j=0; j<9; j++){
        tempColors[i][j]=cube->colors[i][j];
     }
  }
  cube->colors[0][4]=tempColors[3][4];
  cube->colors[0][3]=tempColors[3][3];
  cube->colors[0][2]=tempColors[3][2];
  cube->colors[1][4]=tempColors[0][4];
  cube->colors[1][3]=tempColors[0][3];
  cube->colors[1][2]=tempColors[0][2];
  cube->colors[5][0]=tempColors[1][4];
  cube->colors[5][7]=tempColors[1][3];
  cube->colors[5][6]=tempColors[1][2];
  cube->colors[3][4]=tempColors[5][0];
  cube->colors[3][3]=tempColors[5][7];
  cube->colors[3][2]=tempColors[5][6];
}

void rotation_cube::rotateBlueFace(rubiksCube *cube){
  // Rotate blue face clockwise
  rotation_cube::rotateFaceColors(cube, 5);
  // Rotate involved lines
  char tempColors[6][9];
  for (int i=0; i<6; i++){
     for (int j=0; j<9; j++){
        tempColors[i][j]=cube->colors[i][j];
     }
  }
  cube->colors[1][2]=tempColors[4][4];
  cube->colors[1][1]=tempColors[4][3];
  cube->colors[1][0]=tempColors[4][2];
  cube->colors[2][0]=tempColors[1][2];
  cube->colors[2][7]=tempColors[1][1];
  cube->colors[2][6]=tempColors[1][0];
  cube->colors[3][6]=tempColors[2][0];
  cube->colors[3][5]=tempColors[2][7];
  cube->colors[3][4]=tempColors[2][6];
  cube->colors[4][4]=tempColors[3][6];
  cube->colors[4][3]=tempColors[3][5];
  cube->colors[4][2]=tempColors[3][4];
}
*/
