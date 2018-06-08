#include <iostream>
#include <string>
#include "headers/rubikscube.hpp"
#include "../graphic_function/headers/cube_rotation.hpp"

void rubiksCube::initCube(){
    for (int i = 0; i < 27; i++) {
        tabCubes[i].receive_coordonate(basicCoord[i][0],basicCoord[i][1],basicCoord[i][2],0,0,0);
    }
}

void rubiksCube::displayFlatCube(rubiksCube *cube){
    printf("\nDisplaying flat Rubik's Cube\n");
    printf("\n");
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
    /*rotation_cube rotate;
     for (int i = 0; i < moves.length(); i++) {
     if (moves[i] == 'x'){
     break;
     // All moves dones with green face as front face and white face as the upper face
     } else if (moves[i] == 'U'){ // Rotate up face
     rotate.rotateWhiteFace(cube);
     } else if (moves[i] == 'F'){ // Rotate front face
     rotate.rotateGreenFace(cube);
     } else if (moves[i] == 'L'){ // Rotate left face
     rotate.rotateOrangeFace(cube);
     } else if (moves[i] == 'R'){ // Rotate right face
     rotate.rotateRedFace(cube);
     } else if (moves[i] == 'B'){ // Rotate back face
     rotate.rotateBlueFace(cube);
     } else if (moves[i] == 'D'){ // Rotate down face
     rotate.rotateYellowFace(cube);
     }
     rubiksCube::displayFlatCube(cube);
     }*/
}
