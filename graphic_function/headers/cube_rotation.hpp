#ifndef cube_rotation_hpp
#define cube_rotation_hpp
#include "../../rubikscube/headers/cube.hpp"
#include "../../rubikscube/headers/rubikscube.hpp"

#include <stdio.h>


class rotation_cube
{
public:
    void rotation(float Ox, float Oy, float Oz,cube cube_rotate);
    void rotationU(float Ox, float Oy, float Oz,cube cube_rotate);
    void rotationcube(float Ox, float Oy, float Oz,cube cube_rotate);
};
#endif /* cube_rotation_hpp */
