#ifndef rubikscube_hpp
#define rubikscube_hpp
#include "cube.hpp"
#include <string>

class rubiksCube{
public:
  // This will be our coordinates to create the ptitCubes
  float basicCoord[27][3] = {{-1,1,1},{0,1,1},{1,1,1},  // 0-2
                             {-1,0,1},{0,0,1},{1,0,1},           // 3-5
                             {-1,-1,1},{0,-1,1},{1,-1,1},       // 6-8
                             {-1,1,0},{0,1,0},{1,1,0},           // 9-11
                             {-1,0,0},{0,0,0},{1,0,0},           // 12-14
                             {-1,-1,0},{0,-1,0},{1,-1,0},        // 15-17
                             {-1,1,-1},{0,1,-1},{1,1,-1},        // 18-20
                             {-1,0,-1},{0,0,-1},{1,0,-1},        // 21-23
                             {-1,-1,-1},{0,-1,-1},{1,-1,-1}};    // 24-26

  // Array that will contain the colors 9 colors of each faces
  char colors[6][9] = {{'G','G','G','G','G','G','G','G','G'},  // index 0 = green face
                       {'W','W','W','W','W','W','W','W','W'},  // index 1 = white face
                       {'O','O','O','O','O','O','O','O','O'},  // index 2 = orange face
                       {'Y','Y','Y','Y','Y','Y','Y','Y','Y'},  // index 3 = yellow face
                       {'R','R','R','R','R','R','R','R','R'},  // index 4 = red face
                       {'B','B','B','B','B','B','B','B','B'}}; // index 5 = blue face

  // A RubiksCube is composed by 26 ptitCubes (or 27, but the center one is invisible)
  cube tabCubes[27];
  cube *arrayCube = tabCubes;
  void initCube();
  void displayFlatCube(rubiksCube *cube);
  void doAskedMove(std::string moves, rubiksCube *cube);
};

#endif
