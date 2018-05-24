#include <math.h>

void camera_rotation(double degres, double *camera)
{
    camera[0]=-5.0*cos(degres);
    camera[1]=5.0*sin(degres);
    camera[2]=0;
}
