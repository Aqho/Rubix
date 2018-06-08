#ifndef cube_rotation_hpp
#define cube_rotation_hpp
#include "../../rubikscube/headers/cube.hpp"
#include "../../rubikscube/headers/rubikscube.hpp"

#include <stdio.h>


class rotation_cube
{
public:
    void rotationU(float Ox, float Oy, float Oz,cube cube_rotate);
    void rotationcube(float Ox, float Oy, float Oz,cube cube_rotate);
    void rotateFaceColors(rubiksCube *cube, int face);
    void rotateGreenFace(rubiksCube *cube);
    void rotateWhiteFace(rubiksCube *cube);
    void rotateOrangeFace(rubiksCube *cube);
    void rotateYellowFace(rubiksCube *cube);
    void rotateRedFace(rubiksCube *cube);
    void rotateBlueFace(rubiksCube *cube);
};
#endif /* cube_rotation_hpp */
