#define GL3_PROTOTYPES 1

#ifdef __unix__
#include <GL/glu.h>
#else
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

#include <SDL2/SDL.h>
#include <math.h>
#include "graphic_function/headers/camera_position.hpp"
#include "render/headers/render.hpp"
#include "rubikscube/headers/cube.hpp"
//#include "graphic_function/headers/cube_rotation.hpp"
#include <iostream>

#define check_gl_error() do { \
GLenum e##__LINE__ = glGetError(); \
if (e##__LINE__ != GL_NO_ERROR) \
fprintf(stderr,"ERROR:%d:glerr=%d\n", __LINE__, e##__LINE__); \
} while(0)

#define PI 3.14159265

// This will be our coordinates to create the ptitCubes
float basicCoord[27][3] = {{-1,1,1},{0,1,1},{1,1,1},  // 0-2
                  {-1,0,1},{0,0,1},{1,0,1},           // 3-5
                  {-1,-1,1},{0,-1,1},{1,-1,-1},       // 6-8
                  {-1,1,0},{0,1,0},{1,1,0},           // 9-11
                  {-1,0,0},{0,0,0},{1,0,0},           // 12-14
                  {-1,-1,0},{0,-1,0},{1,-1,0},        // 15-17
                  {-1,1,-1},{0,1,-1},{1,1,-1},        // 18-20
                  {-1,0,-1},{0,0,-1},{1,0,-1},        // 21-23
                  {-1,-1,-1},{0,-1,-1},{1,-1,-1}};    // 24-26

/*
class rubiksCube{
public:
  // Array that will contain the colors 9 colors of each faces
  char colors[6][9] = {{'G','G','G','G','G','G','G','G','G'},  // index 0 = green face
                       {'W','W','W','W','W','W','W','W','W'},  // index 1 = white face
                       {'O','O','O','O','O','O','O','O','O'},  // index 2 = orange face
                       {'Y','Y','Y','Y','Y','Y','Y','Y','Y'},  // index 3 = yellow face
                       {'R','R','R','R','R','R','R','R','R'},  // index 4 = red face
                       {'B','B','B','B','B','B','B','B','B'}}; // index 5 = blue face
*/
  // A RubiksCube is composed by 26 ptitCubes (or 27, but the center one is invisible)
  cube tabCubes[27];
  cube *arrayCube = tabCubes;
//};

static void window_initializer(void)
{
    SDL_Window *main_win = SDL_GL_GetCurrentWindow();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(main_win);
    int width, height;
    SDL_GetWindowSize(main_win, &width, &height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 800/400, 0.1, 1000);
    glEnable(GL_DEPTH_TEST);
    glTranslated(0.0, 0.0, -1.0);
    check_gl_error();
}

int main()
{
    //rubiksCube *myCube = new rubiksCube;
    for (int i = 0; i < 27; i++) {
      tabCubes[i].receive_coordonate(basicCoord[i][0],basicCoord[i][1],basicCoord[i][2],0,0,0);
      std::cout << tabCubes[i].vertexcube[0][0][0] << tabCubes[i].vertexcube[0][0][1] << tabCubes[i].vertexcube[0][0][2] << std::endl;
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return EXIT_FAILURE;

#if 0
    /* configure the OpenGL version to use. */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
#endif

    /* create a window suitable for OpenGL. */
    SDL_Window *mainwin = SDL_CreateWindow("Cube",
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                           800, 400, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (!mainwin) {
        fprintf(stderr, "ERROR:%s\n", SDL_GetError());
        //goto failure;
    }
    SDL_GLContext glctx = SDL_GL_CreateContext(mainwin);
    if (!glctx) {
        fprintf(stderr, "ERROR:%s\n", SDL_GetError());
        //goto cleanup;
    }
    float angle = 0.0;
    bool quit = false;
    window_initializer();

    //test array cube
    float rot = 0.0;

    //petitscubes[1].receive_coordonate(0, 1, 1, 0, 0, 0);

    while (1) {
        SDL_Event ev;

        /* process events until timeout occurs */
        while (SDL_WaitEventTimeout(&ev, 15)) {
            switch (ev.type) {
                case SDL_QUIT:
                    quit = true;
                    goto bail;
            }
        }

        float camera[3];
        float *cam = camera;
        camera_position my_cam;
        my_cam.camera_rotation(angle, cam);
        render actual_render;
        actual_render.Rendering(cam, arrayCube);
        angle = angle + 0.02;
        rot = rot + 1;
        //std::cout << rot << std::endl;
        tabCubes[0].receive_coordonate(0, 1, 1, 0, 0, rot * PI / 180);
        if (rot > 359.95)
        {
            rot = 0.0;
        }
        if (angle > 359.95)
        {
            angle = 0.0;
        }
    }
bail:

    SDL_DestroyWindow(mainwin);
    SDL_Quit();
    return 0;
cleanup:
    SDL_DestroyWindow(mainwin);
failure:
    SDL_Quit();
    return EXIT_FAILURE;
}
