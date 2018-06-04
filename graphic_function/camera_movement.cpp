#include <math.h>
#include "headers/camera_movement.hpp"

#define DIST -3

void camera_movement::camera_rotation(float degres, float *camera)
{
    camera[0]=DIST*cos(degres);
    camera[1]=DIST*sin(degres);
    camera[2]=0;
}
