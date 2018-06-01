#include <iostream>
#include <string>

// This will be our coordinates to create the ptitCubes
float basicCoord[27][3] = {{-1,1,1},{0,1,1},{1,1,1},  // 0-2
                  {-1,0,1},{0,0,1},{1,0,1},           // 3-5
                  {-1,-1,1},{0,-1,1},{1,-1,-1},       // 6-8
                  {-1,1,0},{0,1,0},{1,1,0},           // 9-11
                  {-1,0,0},{0,0,0},{1,0,0},           // 12-14
                  {-1,-1,0},{0,-1,0},{1,-1,0},        // 15-17
                  {-1,1,-1},{0,1,-1},{1,1,-1},        // 18-20
                  {-1,0,-1},{0,0,-1},{1,0,-1},        // 21-23
                  {-1,-1,-1},{0,-1,-1},{1,-1,-1}};    // 24-26

class ptitCube{
public:
  float coord[3] = {0,0,0};  // [x, y, z] coordonnées
  float orient[3] = {0,0,0}; // [Ox, Oy, Oz] orientation des axes
  char familly;              // m (middle), e (edge) or c (corner)
};

class rubiksCube{
public:
  // Array that will contain the colors 9 colors of each faces
  char colors[6][9] = {{'G','G','G','G','G','G','G','G','G'},  // index 0 = green face
                       {'W','W','W','W','W','W','W','W','W'},  // index 1 = white face
                       {'O','O','O','O','O','O','O','O','O'},  // index 2 = orange face
                       {'Y','Y','Y','Y','Y','Y','Y','Y','Y'},  // index 3 = yellow face
                       {'R','R','R','R','R','R','R','R','R'},  // index 4 = red face
                       {'B','B','B','B','B','B','B','B','B'}}; // index 5 = blue face

  // A RubiksCube is composed by 26 ptitCubes (or 27, but the center one is invisible)
  ptitCube* tabCubes[27];
};

void displayCoordCube(rubiksCube *cube, int idCube){
  std::cout << cube->tabCubes[idCube]->coord[0] << ",";
  std::cout << cube->tabCubes[idCube]->coord[1] << ",";
  std::cout << cube->tabCubes[idCube]->coord[2] << " : " << idCube;
  std::cout << "\n";
}

void displayFlatCube(rubiksCube *cube){
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

// This function takes the face's number parameter which you want to rotate clockwise
void rotateFaceColors(rubiksCube *cube, int face){
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

void rotateGreenFace(rubiksCube *cube){
  // Rotate green face clockwise
  rotateFaceColors(cube, 0);
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

void rotateWhiteFace(rubiksCube *cube){
  // Rotate white face clockwise
  rotateFaceColors(cube, 1);
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

void rotateOrangeFace(rubiksCube *cube){
  // Rotate orange face clockwise
  rotateFaceColors(cube, 2);
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

void rotateYellowFace(rubiksCube *cube){
  // Rotate yellow face clockwise
  rotateFaceColors(cube, 3);
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

void rotateRedFace(rubiksCube *cube){
  // Rotate red face clockwise
  rotateFaceColors(cube, 4);
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

void rotateBlueFace(rubiksCube *cube){
  // Rotate blue face clockwise
  rotateFaceColors(cube, 5);
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

int main() {
  rubiksCube *myCube = new rubiksCube();
  for (int i = 0; i < 27; i++) {
    myCube->tabCubes[i] = new ptitCube();
    myCube->tabCubes[i]->coord[0] = basicCoord[i][0];
    myCube->tabCubes[i]->coord[1] = basicCoord[i][1];
    myCube->tabCubes[i]->coord[2] = basicCoord[i][2];
  }
  for (int i = 0; i < 27; i++) {
    //displayCoordCube(myCube, i);
  }
  displayFlatCube(myCube);
  std::string choice = "";
  while (choice != "exit"){
    std::cout << "Move (type 'exit' to exit) : ";
    std::cin >> choice;
    if (choice == "exit"){
      break;
    } else if (choice == "U"){ // Rotate up face
      rotateWhiteFace(myCube);
    } else if (choice == "F"){ // Rotate front face
      rotateGreenFace(myCube);
    } else if (choice == "L"){ // Rotate left face
      rotateOrangeFace(myCube);
    } else if (choice == "R"){ // Rotate right face
      rotateRedFace(myCube);
    } else if (choice == "B"){ // Rotate back face
      rotateBlueFace(myCube);
    } else if (choice == "D"){ // Rotate down face
      rotateYellowFace(myCube);
    }
    displayFlatCube(myCube);
  }
  return 0;
}
