#include <math.h>
#define DIST -4

void camera_rotation(double degres, double *camera)
{
    camera[0]=DIST*cos(degres);
    camera[1]=DIST*sin(degres);
    camera[2]=0;
}
