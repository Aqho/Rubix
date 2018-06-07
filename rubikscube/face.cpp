#include "headers/face.hpp"


void face::receive_coordonates(float x, float y, float z,char place, char color)
{
    float colors[3];
    float base_x = 0.5;
    float base_y = 0.5;
    float base_z = 0.5;
    if(place == 'L'){base_x=-0.5; }
    if(place == 'b'){base_z = -0.5; }
}
void face::get_coordonates()
{
    
}

/*
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex3f( 1.0f, 1.0f, -1.0f);
 glVertex3f(-1.0f, 1.0f, -1.0f);
 glVertex3f(-1.0f, 1.0f,  1.0f);
 glVertex3f( 1.0f, 1.0f,  1.0f);
 */
