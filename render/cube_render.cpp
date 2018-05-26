#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <GLKit/GLKMatrix4.h>
#include "cube.hpp"
#include <iostream>


void Rendering(double *camera, cube *cubearray)
{
    
    SDL_Window *win = SDL_GL_GetCurrentWindow();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    
    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    gluLookAt(camera[0] , camera[1] , camera[2]+0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    
    
    cube petitcube;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    for(int cube = 0; cube < 2; cube++)
    {
        for(int face = 0; face < 6; face++)
        {
            for(int vertex = 0; vertex < 4; vertex++)
            {
                glColor3f(cubearray[cube].vertexcube[face][vertex][6], cubearray[cube].vertexcube[face][vertex][7], cubearray[cube].vertexcube[face][vertex][8]);
                glVertex3f(cubearray[cube].vertexcube[face][vertex][0], cubearray[cube].vertexcube[face][vertex][1], cubearray[cube].vertexcube[face][vertex][2]);
            }
        }
    }
    glEnd();  // End of drawing color-cube
    SDL_GL_SwapWindow(win);
    
}
