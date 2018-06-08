#define GL3_PROTOTYPES 1

// X compilation libraries
#ifdef __unix__
#include <GL/glu.h>
#else
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

// Libraries
#include <SDL2/SDL.h>
#include <math.h>
#include "graphic_function/headers/camera_position.hpp"
#include "render/headers/render.hpp"
#include "rubikscube/headers/cube.hpp"
#include "rubikscube/headers/rubikscube.hpp"
//#include "graphic_function/headers/cube_rotation.hpp"
#include <iostream>
#include <string>

// Defines
#define PI 3.14159265
#define check_gl_error() do { \
GLenum e##__LINE__ = glGetError(); \
if (e##__LINE__ != GL_NO_ERROR) \
fprintf(stderr,"ERROR:%d:glerr=%d\n", __LINE__, e##__LINE__); \
} while(0)

// Initialize the SDL windows
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
    rubiksCube *myCube = new rubiksCube;
    std::string moves;
    myCube->initCube();
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
        SDL_Quit();
        return EXIT_FAILURE;
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
    int direction = 0;
    float camera[6]{0,0,0,0,0,0};
    //petitscubes[1].receive_coordonate(0, 1, 1, 0, 0, 0);

    while (quit != true) {
        SDL_Event ev;
        /* process events until timeout occurs */
        while (SDL_WaitEventTimeout(&ev, 20)) {
            switch (ev.type) {
                case SDL_QUIT:
                    quit = true;
                case SDL_KEYDOWN:
                    if(ev.key.keysym.sym == SDLK_ESCAPE){quit = true;;}
                    if(ev.key.keysym.sym == SDLK_RIGHT){direction = 1;}
                    if(ev.key.keysym.sym == SDLK_LEFT){direction = 2;}
                    if(ev.key.keysym.sym == SDLK_UP){direction = 3;}
                    if(ev.key.keysym.sym == SDLK_DOWN){direction = 4;}
                    if(ev.key.keysym.sym == SDLK_u){ myCube->doAskedMove("U", myCube);}
                    if(ev.key.keysym.sym == SDLK_d){ myCube->doAskedMove("D", myCube);}
                    if(ev.key.keysym.sym == SDLK_r){ myCube->doAskedMove("R", myCube);}
                    if(ev.key.keysym.sym == SDLK_l){ myCube->doAskedMove("L", myCube);}
                    if(ev.key.keysym.sym == SDLK_f){ myCube->doAskedMove("F", myCube);}
                    if(ev.key.keysym.sym == SDLK_b){ myCube->doAskedMove("B", myCube);}
            }
        }
        if ( SDL_PollEvent(&ev) == 1 )
        {

        }
        float *cam = camera;
        camera_position my_cam;
        my_cam.camera_rotation(direction, cam);
        direction = 0;
        render actual_render;
        actual_render.Rendering(cam, myCube->arrayCube);
        //angle = angle + 0.02;
        rot = rot + 1;
        for(int i = 0; i < 9; i++)
        {
            myCube->tabCubes[i].receive_coordonate(myCube->tabCubes[i].coordonate[0], myCube->tabCubes[i].coordonate[1], myCube->tabCubes[i].coordonate[2], 0, 0, 45.0 * PI / 180);
        }
        if (rot > 359.95)
        {
            rot = 0.0;
        }
        if (angle > 359.95)
        {
            angle = 0.0;
        }
    }
}
