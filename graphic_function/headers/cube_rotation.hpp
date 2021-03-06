#ifndef cube_rotation_hpp
#define cube_rotation_hpp
#include "../../rubikscube/headers/cube.hpp"
#include "../../rubikscube/headers/rubikscube.hpp"

#include <stdio.h>


class cube_rotation
{
public:
    void rotation(float Ox, float Oy, float Oz,cube cube_rotate);
    void rotationU(rubiksCube *rubikscube_rotate);
    void rotationD(rubiksCube *rubikscube_rotate);
    void rotationF(rubiksCube *rubikscube_rotate);
    void rotationR(rubiksCube *rubikscube_rotate);
    void rotationB(rubiksCube *rubikscube_rotate);
    void rotationL(rubiksCube *rubikscube_rotate);
    void save(rubiksCube *rubikscube_rotate);
    void swapU(rubiksCube *rubikscube_rotate);
    void swapD(rubiksCube *rubikscube_rotate);
    void swapF(rubiksCube *rubikscube_rotate);
    void swapR(rubiksCube *rubikscube_rotate);
    void swapB(rubiksCube *rubikscube_rotate);
    void swapL(rubiksCube *rubikscube_rotate);
};
#endif /* cube_rotation_hpp */
