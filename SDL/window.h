#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <GLKit/GLKMatrix4.h>
#include <SDL2/SDL.h>
#include <iostream>

#define check_gl_error() do { \
GLenum e##__LINE__ = glGetError(); \
if (e##__LINE__ != GL_NO_ERROR) \
fprintf(stderr,"ERROR:%d:glerr=%d\n", __LINE__, e##__LINE__); \
} while(0)

static void initialize_window(void)
{
    SDL_Window *rubix_window = SDL_GL_GetCurrentWindow();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(rubix_window);
    int width, height;
    SDL_GetWindowSize(rubix_window, &width, &height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 800/400, 0.1, 1000);
    glEnable(GL_DEPTH_TEST);
    glTranslated(0.0, 0.0, -1.0);
    check_gl_error();
}
