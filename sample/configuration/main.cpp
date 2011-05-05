
#include <EGL/egl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    EGLDisplay dpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    if (EGL_NO_DISPLAY == dpy) {
        return -1;
    }

    if (EGL_FALSE == eglInitialize(dpy, NULL, NULL)) {
        return -1;
    }

    EGLint num_config;
    if (EGL_FALSE == eglGetConfigs(dpy, NULL, 0, &num_config)) {
        return -1;
    }

    EGLConfig* configs = (EGLConfig*)malloc(num_config * sizeof(EGLConfig));

    if (EGL_FALSE == eglGetConfigs(dpy, configs, num_config, &num_config)) {
        return -1;
    }

    int i;
    for (i = 0; i < num_config; ++i) {
        EGLint a, r, g, b;
        EGLint bits, stencil, depth;

        eglGetConfigAttrib(dpy, configs[i], EGL_BUFFER_SIZE, &bits);
        eglGetConfigAttrib(dpy, configs[i], EGL_ALPHA_SIZE, &a);
        eglGetConfigAttrib(dpy, configs[i], EGL_BLUE_SIZE, &b);
        eglGetConfigAttrib(dpy, configs[i], EGL_GREEN_SIZE, &g);
        eglGetConfigAttrib(dpy, configs[i], EGL_RED_SIZE, &r);
        eglGetConfigAttrib(dpy, configs[i], EGL_DEPTH_SIZE, &depth);
        eglGetConfigAttrib(dpy, configs[i], EGL_STENCIL_SIZE, &stencil);

        printf("== Config(%08p) ==\n", configs[i]);
        printf("EGL_BUFFER_SIZE  = %d\n", bits);
        printf("EGL_ALPHA_SIZE   = %d\n", a);
        printf("EGL_BLUE_SIZE    = %d\n", b);
        printf("EGL_GREEN_SIZE   = %d\n", g);
        printf("EGL_RED_SIZE     = %d\n", r);
        printf("EGL_DEPTH_SIZE   = %d\n", depth);
        printf("EGL_STENCIL_SIZE = %d\n", stencil);
    }

    EGLSurface surface = eglCreateWindowSurface(dpy, configs[0], NULL, NULL);

    free(configs);

    eglBindAPI(EGL_OPENGL_ES_API);

    if (EGL_FALSE == eglTerminate(dpy)) {
        return -1;
    }

    return 0;
}
