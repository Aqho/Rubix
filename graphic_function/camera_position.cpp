#include "headers/camera_position.hpp"
#include <math.h>

#define DIST -5
#define PI 3.14159265
#include <iostream>

void camera_position::camera_rotation(int direction, float *camera)
{
    if (direction == 1){
        if(camera[3]<360){camera[3] = camera[3]+8;}
        else{camera[3]=camera[3]-352;}
    }
    else if (direction == 2){
        if(camera[3]>0){camera[3] =camera[3] -8;}
        else{camera[3]=camera[3]+352;}
    }
    else if (direction == 3){
        if (camera[2] < 8.0f){camera[2] = camera[2]+0.2;}
    }
    else if (direction == 4){
        if (camera[2] > -8.0f){camera[2] = camera[2]-0.2;}

    }
    camera[0]=DIST*cos(camera[3] * PI / 180);
    camera[1]=DIST*sin(camera[3] * PI / 180);
}
