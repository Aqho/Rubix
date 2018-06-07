#include "headers/render.hpp"
#include "../rubikscube/headers/cube.hpp"
#ifdef __unix__
#include <GL/glu.h>
#else
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#include <SDL2/SDL.h>
#include <iostream>


void render::Rendering(float *camera, cube *cubearray)
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
    for(int cube = 0; cube < 27; cube++)
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

/*
void render::displayFlatCube(rubiksCube *cube){
  printf("\nDisplaying flat Rubik's Cube\n");
  printf("\n");
  printf("              -----------\n");
  printf("             | %c | %c | %c |\n",cube->colors[1][0],cube->colors[1][1],cube->colors[1][2]);
  printf("             | %c | %c | %c |\n",cube->colors[1][7],cube->colors[1][8],cube->colors[1][3]);
  printf("             | %c | %c | %c |\n",cube->colors[1][6],cube->colors[1][5],cube->colors[1][4]);
  printf("              -----------\n");
  printf(" -----------  -----------  -----------  -----------\n");

  printf("| %c | %c | %c || %c | %c | %c || %c | %c | %c || %c | %c | %c |\n",
  cube->colors[2][0],cube->colors[2][1],cube->colors[2][2],cube->colors[0][0],cube->colors[0][1],cube->colors[0][2],
  cube->colors[4][0],cube->colors[4][1],cube->colors[4][2],cube->colors[5][0],cube->colors[5][1],cube->colors[5][2]);

  printf("| %c | %c | %c || %c | %c | %c || %c | %c | %c || %c | %c | %c |\n",
  cube->colors[2][7],cube->colors[2][8],cube->colors[2][3],cube->colors[0][7],cube->colors[0][8],cube->colors[0][3],
  cube->colors[4][7],cube->colors[4][8],cube->colors[4][3],cube->colors[5][7],cube->colors[5][8],cube->colors[5][3]);

  printf("| %c | %c | %c || %c | %c | %c || %c | %c | %c || %c | %c | %c |\n",
  cube->colors[2][6],cube->colors[2][5],cube->colors[2][4],cube->colors[0][6],cube->colors[0][5],cube->colors[0][4],
  cube->colors[4][6],cube->colors[4][5],cube->colors[4][4],cube->colors[5][6],cube->colors[5][5],cube->colors[5][4]);
  printf(" -----------  -----------  -----------  -----------\n");
  printf("              -----------\n");
  printf("             | %c | %c | %c |\n",cube->colors[3][0],cube->colors[3][1],cube->colors[3][2]);
  printf("             | %c | %c | %c |\n",cube->colors[3][7],cube->colors[3][8],cube->colors[3][3]);
  printf("             | %c | %c | %c |\n",cube->colors[3][6],cube->colors[3][5],cube->colors[3][4]);
  printf("              -----------\n");
}
*/
