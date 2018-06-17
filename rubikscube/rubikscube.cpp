#include <iostream>
#include <string>
#include "headers/rubikscube.hpp"
#include <chrono>
#include <thread>
#include "../graphic_function/headers/cube_rotation.hpp"

void rubiksCube::initCube(){
    for (int i = 0; i < 27; i++) {
        tabCubes[i].receive_coordonate(basicCoord[i][0],basicCoord[i][1],basicCoord[i][2],0,0,0);
    }
}

void rubiksCube::displayFlatCube(rubiksCube *cube){
    printf("              -----------\n");
    printf("             | %c | %c | %c |\n",cube->colors[1][0],cube->colors[1][1],cube->colors[1][2]);
    printf("             | %c | %c | %c |\n",cube->colors[1][7],cube->colors[1][8],cube->colors[1][3]);
    printf("             | %c | %c | %c |\n",cube->colors[1][6],cube->colors[1][5],cube->colors[1][4]);
    printf("              -----------\n");
    printf(" -----------  -----------  -----------  -----------\n");

    printf("| %c | %c | %c || %c | %c | %c || %c | %c | %c || %c | %c | %c |\n",
           cube->colors[2][0],cube->colors[2][1],cube->colors[2][2],cube->colors[0][0],cube->colors[0][1],cube->colors[0][2],
           cube->colors[4][0],cube->colors[4][1],cube->colors[4][2],cube->colors[5][0],cube->colors[5][1],cube->colors[5][2]);

    printf("| %c | %c | %c || %c | %c | %c || %c | %c | %c || %c | %c | %c |\n",
           cube->colors[2][7],cube->colors[2][8],cube->colors[2][3],cube->colors[0][7],cube->colors[0][8],cube->colors[0][3],
           cube->colors[4][7],cube->colors[4][8],cube->colors[4][3],cube->colors[5][7],cube->colors[5][8],cube->colors[5][3]);

    printf("| %c | %c | %c || %c | %c | %c || %c | %c | %c || %c | %c | %c |\n",
           cube->colors[2][6],cube->colors[2][5],cube->colors[2][4],cube->colors[0][6],cube->colors[0][5],cube->colors[0][4],
           cube->colors[4][6],cube->colors[4][5],cube->colors[4][4],cube->colors[5][6],cube->colors[5][5],cube->colors[5][4]);
    printf(" -----------  -----------  -----------  -----------\n");
    printf("              -----------\n");
    printf("             | %c | %c | %c |\n",cube->colors[3][0],cube->colors[3][1],cube->colors[3][2]);
    printf("             | %c | %c | %c |\n",cube->colors[3][7],cube->colors[3][8],cube->colors[3][3]);
    printf("             | %c | %c | %c |\n",cube->colors[3][6],cube->colors[3][5],cube->colors[3][4]);
    printf("              -----------\n");
}

void rubiksCube::doAskedMove(std::string moves, rubiksCube *cube){
    for (int i = 0; i < moves.length(); i++) {
      printf("\nDisplaying flat Rubik's Cube\n");
      printf("Actual move : %c\n",moves[i]);
      // All moves dones with green face as front face and white face as the upper face
      if (moves[i] == 'u'){ // Rotate up face clockwise
        rubiksCube::rotateWhiteFace(cube);
      } else if (moves[i] == 'f'){ // Rotate front face clockwise
        rubiksCube::rotateGreenFace(cube);
      } else if (moves[i] == 'l'){ // Rotate left face clockwise
        rubiksCube::rotateOrangeFace(cube);
      } else if (moves[i] == 'r'){ // Rotate right face clockwise
        rubiksCube::rotateRedFace(cube);
      } else if (moves[i] == 'b'){ // Rotate back face clockwise
        rubiksCube::rotateBlueFace(cube);
      } else if (moves[i] == 'd'){ // Rotate down face clockwise
        rubiksCube::rotateYellowFace(cube);
      } else if (moves[i] == 'U'){ // Rotate down face counter-clockwise
        rubiksCube::rotateWhiteFace(cube);
        rubiksCube::rotateWhiteFace(cube);
        rubiksCube::rotateWhiteFace(cube);
      }  else if (moves[i] == 'F'){ // Rotate front face counter-clockwise
        rubiksCube::rotateGreenFace(cube);
        rubiksCube::rotateGreenFace(cube);
        rubiksCube::rotateGreenFace(cube);
      } else if (moves[i] == 'L'){ // Rotate left face counter-clockwise
        rubiksCube::rotateOrangeFace(cube);
        rubiksCube::rotateOrangeFace(cube);
        rubiksCube::rotateOrangeFace(cube);
      } else if (moves[i] == 'R'){ // Rotate right face counter-clockwise
        rubiksCube::rotateRedFace(cube);
        rubiksCube::rotateRedFace(cube);
        rubiksCube::rotateRedFace(cube);
      } else if (moves[i] == 'B'){ // Rotate back face counter-clockwise
        rubiksCube::rotateBlueFace(cube);
        rubiksCube::rotateBlueFace(cube);
        rubiksCube::rotateBlueFace(cube);
      } else if (moves[i] == 'D'){ // Rotate down face counter-clockwise
        rubiksCube::rotateYellowFace(cube);
        rubiksCube::rotateYellowFace(cube);
        rubiksCube::rotateYellowFace(cube);
      }
      rubiksCube::displayFlatCube(cube);
      if (rubiksCube::isItFinished(cube)){
          cube->movesDone.clear();
          break;
      }
      if (i > 1){
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
      }
    }
}

bool rubiksCube::isItFinished(rubiksCube *cube){
  for (int i=0; i<6; i++){
     for (int j=0; j<9; j++){
        if (cube->solvedColors[i][j] != cube->colors[i][j]){
          return false;
        }
     }
  }
  return true;
}

// This function takes the face's number parameter which you want to rotate clockwise
void rubiksCube::rotateFaceColors(rubiksCube *cube, int face){
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

void rubiksCube::rotateGreenFace(rubiksCube *cube){
  // Rotate green face clockwise
  rubiksCube::rotateFaceColors(cube, 0);
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

void rubiksCube::rotateWhiteFace(rubiksCube *cube){
  // Rotate white face clockwise
  rubiksCube::rotateFaceColors(cube, 1);
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

void rubiksCube::rotateOrangeFace(rubiksCube *cube){
  // Rotate orange face clockwise
  rubiksCube::rotateFaceColors(cube, 2);
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
  cube->colors[3][7]=tempColors[0][7];
  cube->colors[3][6]=tempColors[0][6];
  cube->colors[5][4]=tempColors[3][0];
  cube->colors[5][3]=tempColors[3][7];
  cube->colors[5][2]=tempColors[3][6];
  cube->colors[1][0]=tempColors[5][4];
  cube->colors[1][7]=tempColors[5][3];
  cube->colors[1][6]=tempColors[5][2];
}

void rubiksCube::rotateYellowFace(rubiksCube *cube){
  // Rotate yellow face clockwise
  rubiksCube::rotateFaceColors(cube, 3);
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

void rubiksCube::rotateRedFace(rubiksCube *cube){
  // Rotate red face clockwise
  rubiksCube::rotateFaceColors(cube, 4);
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

void rubiksCube::rotateBlueFace(rubiksCube *cube){
  // Rotate blue face clockwise
  rubiksCube::rotateFaceColors(cube, 5);
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
