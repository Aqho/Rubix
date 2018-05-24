#define GL3_PROTOTYPES 1
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <GLKit/GLKMatrix4.h>
#include <math.h>
#include "graphic function/camera_movement.h"
#include "SDL/window.h"
#include "render/cube_render.h"

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
    double angle = 0.0;
    initialize_window();
    
    bool quit = false;
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
        
        double camera[3];
        double *cam;
        cam = camera;
        camera_rotation(angle, cam);
        Rendering(cam);
        angle = angle + 0.01;
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

