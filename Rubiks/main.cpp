#include <iostream>

// This will be our coordinates to create the ptitCubes
float basicCoord[27][3] = {{-1,1,1},{0,1,1},{1,1,1},        // 0-2
                  {-1,0,1},{0,0,1},{1,0,1},       // 3-5
                  {-1,-1,1},{0,-1,1},{1,-1,-1},   // 6-8
                  {-1,1,0},{0,1,0},{1,1,0},       // 9-11
                  {-1,0,0},{0,0,0},{1,0,0},       // 12-14
                  {-1,-1,0},{0,-1,0},{1,-1,0},    // 15-17
                  {-1,1,-1},{0,1,-1},{1,1,-1},    // 18-20
                  {-1,0,-1},{0,0,-1},{1,0,-1},    // 21-23
                  {-1,-1,-1},{0,-1,-1},{1,-1,-1}}; // 24-26

class ptitCube{
public:
  float coord[3] = {0,0,0}; // [x, y, z] coordonnées
  float orient[3] = {0,0,0}; // [Ox, Oy, Oz] orientation des axes
};

class rubiksCube{
public:
  ptitCube* tabCubes[27];
};

void displayCoordCube(rubiksCube *cube, int idCube){
  std::cout << cube->tabCubes[idCube]->coord[0] << ",";
  std::cout << cube->tabCubes[idCube]->coord[1] << ",";
  std::cout << cube->tabCubes[idCube]->coord[2] << " : " << idCube;
  std::cout << "\n";
}

int main() {
  rubiksCube *myCube = new rubiksCube();
  for (int i = 0; i < 27; i++) {
    myCube->tabCubes[i] = new ptitCube();
    myCube->tabCubes[i]->coord[0] = basicCoord[i][0];
    myCube->tabCubes[i]->coord[1] = basicCoord[i][1];
    myCube->tabCubes[i]->coord[2] = basicCoord[i][2];
  }
  for (int i = 0; i < 25; i++) {
    displayCoordCube(myCube, i);
  }
  return 0;
}
