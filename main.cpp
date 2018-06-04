#define GL3_PROTOTYPES 1
#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <GLKit/GLKMatrix4.h>
#include <math.h>
#include "graphic_function/headers/camera_position.hpp"
#include "render/headers/render.hpp"
#include "rubixcube/headers/rubix_cube.hpp"
#include "rubixcube/headers/cube.hpp"
#include <iostream>

#define check_gl_error() do { \
GLenum e##__LINE__ = glGetError(); \
if (e##__LINE__ != GL_NO_ERROR) \
fprintf(stderr,"ERROR:%d:glerr=%d\n", __LINE__, e##__LINE__); \
} while(0)

#define PI 3.14159265

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
    cube petitscubes[2];
    cube *cubearray = petitscubes;
    petitscubes[1].receive_coordonate(0, 1, 1, 0, 0, 0);
    
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
        actual_render.Rendering(cam, cubearray);
        angle = 0;
        rot = rot + 1;
        std::cout << rot << std::endl;
        petitscubes[1].receive_coordonate(0, 1, 1, 0, 0, rot * PI / 180);
        petitscubes[0].receive_coordonate(0, 0, 0, 0, 0, 0);
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

