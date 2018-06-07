#include "headers/camera_position.hpp"
#include <math.h>

#define DIST -5

void camera_position::camera_rotation(float degres, float *camera)
{
    camera[0]=DIST*cos(degres);
    camera[1]=DIST*sin(degres);
    camera[2]=0;
}
