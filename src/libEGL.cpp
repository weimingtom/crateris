/*
 * Copyright (c) 2011, okazoh_tk. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  - Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#define EGLAPI extern "C" __declspec(dllexport)
#include "EGL.h"

#define InitAPI()   \
    crateris::EGL* egl = crateris_get_EGL()

EGLAPI EGLint EGLAPIENTRY eglGetError(void)
{
    InitAPI();
    return egl->GetError();
}

EGLAPI EGLDisplay EGLAPIENTRY eglGetDisplay(
    EGLNativeDisplayType display_id)
{
    InitAPI();
    return egl->GetDisplay(display_id);
}

EGLAPI EGLBoolean EGLAPIENTRY eglInitialize(
    EGLDisplay dpy,
    EGLint *major,
    EGLint *minor)
{
    InitAPI();
    return egl->Initialize(dpy, major, minor);
}

EGLAPI EGLBoolean EGLAPIENTRY eglTerminate(
    EGLDisplay dpy)
{
    InitAPI();
    return egl->Terminate(dpy);
}

EGLAPI const char * EGLAPIENTRY eglQueryString(
    EGLDisplay dpy,
    EGLint name)
{
    InitAPI();
    return egl->QueryString(dpy, name);
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigs(
    EGLDisplay dpy,
    EGLConfig *configs,
    EGLint config_size,
    EGLint *num_config)
{
    InitAPI();
    return egl->GetConfigs(dpy, configs, config_size, num_config);
}

EGLAPI EGLBoolean EGLAPIENTRY eglChooseConfig(
    EGLDisplay dpy,
    const EGLint *attrib_list,
    EGLConfig *configs,
    EGLint config_size,
    EGLint *num_config)
{
    InitAPI();
    return egl->ChooseConfig(dpy, attrib_list, configs, config_size, num_config);
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigAttrib(
    EGLDisplay dpy,
    EGLConfig config,
    EGLint attribute,
    EGLint *value)
{
    InitAPI();
    return egl->GetConfigAttrib(dpy, config, attribute, value);
}

EGLAPI EGLSurface EGLAPIENTRY eglCreateWindowSurface(
    EGLDisplay dpy,
    EGLConfig config,
    EGLNativeWindowType win,
    const EGLint *attrib_list)
{
    InitAPI();
    return egl->CreateWindowSurface(dpy, config, win, attrib_list);
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferSurface(
    EGLDisplay dpy,
    EGLConfig config,
    const EGLint *attrib_list)
{
    InitAPI();
    return egl->CreatePbufferSurface(dpy, config, attrib_list);
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePixmapSurface(
    EGLDisplay dpy,
    EGLConfig config,
    EGLNativePixmapType pixmap,
    const EGLint *attrib_list)
{
    InitAPI();
    return egl->CreatePixmapSurface(dpy, config, pixmap, attrib_list);
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroySurface(
    EGLDisplay dpy,
    EGLSurface surface)
{
    InitAPI();
    return egl->DestroySurface(dpy, surface);
}

EGLAPI EGLBoolean EGLAPIENTRY eglQuerySurface(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLint attribute,
    EGLint *value)
{
    InitAPI();
    return egl->QuerySurface(dpy, surface, attribute, value);
}

EGLAPI EGLBoolean EGLAPIENTRY eglBindAPI(
    EGLenum api)
{
    InitAPI();
    return egl->BindAPI(api);
}

EGLAPI EGLenum EGLAPIENTRY eglQueryAPI(void)
{
    InitAPI();
    return egl->QueryAPI();
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitClient(void)
{
    InitAPI();
    return egl->WaitClient();
}

EGLAPI EGLBoolean EGLAPIENTRY eglReleaseThread(void)
{
    InitAPI();
    return egl->ReleaseThread();
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferFromClientBuffer(
    EGLDisplay dpy,
    EGLenum buftype,
    EGLClientBuffer buffer,
    EGLConfig config,
    const EGLint *attrib_list)
{
    InitAPI();
    return egl->CreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
}

EGLAPI EGLBoolean EGLAPIENTRY eglSurfaceAttrib(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLint attribute,
    EGLint value)
{
    InitAPI();
    return egl->SurfaceAttrib(dpy, surface, attribute, value);
}

EGLAPI EGLBoolean EGLAPIENTRY eglBindTexImage(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLint buffer)
{
    InitAPI();
    return egl->BindTexImage(dpy, surface, buffer);
}

EGLAPI EGLBoolean EGLAPIENTRY eglReleaseTexImage(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLint buffer)
{
    InitAPI();
    return egl->ReleaseTexImage(dpy, surface, buffer);
}

EGLAPI EGLBoolean EGLAPIENTRY eglSwapInterval(
    EGLDisplay dpy,
    EGLint interval)
{
    InitAPI();
    return egl->SwapInterval(dpy, interval);
}

EGLAPI EGLContext EGLAPIENTRY eglCreateContext(
    EGLDisplay dpy,
    EGLConfig config,
    EGLContext share_context,
    const EGLint *attrib_list)
{
    InitAPI();
    return egl->CreateContext(dpy, config, share_context, attrib_list);
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroyContext(
    EGLDisplay dpy,
    EGLContext ctx)
{
    InitAPI();
    return egl->DestroyContext(dpy, ctx);
}

EGLAPI EGLBoolean EGLAPIENTRY eglMakeCurrent(
    EGLDisplay dpy,
    EGLSurface draw,
    EGLSurface read,
    EGLContext ctx)
{
    InitAPI();
    return egl->MakeCurrent(dpy, draw, read, ctx);
}

EGLAPI EGLContext EGLAPIENTRY eglGetCurrentContext(void)
{
    InitAPI();
    return egl->GetCurrentContext();
}

EGLAPI EGLSurface EGLAPIENTRY eglGetCurrentSurface(EGLint readdraw)
{
    InitAPI();
    return egl->GetCurrentSurface(readdraw);
}

EGLAPI EGLDisplay EGLAPIENTRY eglGetCurrentDisplay(void)
{
    InitAPI();
    return egl->GetCurrentDisplay();
}

EGLAPI EGLBoolean EGLAPIENTRY eglQueryContext(
    EGLDisplay dpy,
    EGLContext ctx,
    EGLint attribute,
    EGLint *value)
{
    InitAPI();
    return egl->QueryContext(dpy, ctx, attribute, value);
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitGL(void)
{
    InitAPI();
    return egl->WaitGL();
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitNative(
    EGLint engine)
{
    InitAPI();
    return egl->WaitNative(engine);
}

EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffers(
    EGLDisplay dpy,
    EGLSurface surface)
{
    InitAPI();
    return egl->SwapBuffers(dpy, surface);
}

EGLAPI EGLBoolean EGLAPIENTRY eglCopyBuffers(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLNativePixmapType target)
{
    InitAPI();
    return egl->CopyBuffers(dpy, surface, target);
}

EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY
       eglGetProcAddress(const char *procname)
{
    InitAPI();
    return egl->GetProcAddress(procname);
}
