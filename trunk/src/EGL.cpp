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

#include "EGL.h"

namespace crateris {

#define NO_IMPL()

EGL::EGL()
{
}

EGL::~EGL()
{
}

EGLint EGL::GetError(void)
{
    NO_IMPL();
    return EGL_NOT_INITIALIZED;
}

EGLDisplay EGL::GetDisplay(EGLNativeDisplayType display_id)
{
    (void)display_id;

    NO_IMPL();
    return EGL_NO_DISPLAY;
}

EGLBoolean EGL::Initialize(EGLDisplay dpy, EGLint *major, EGLint *minor)
{
    (void)dpy;
    (void)major;
    (void)minor;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::Terminate(EGLDisplay dpy)
{
    (void)dpy;

    NO_IMPL();
    return EGL_FALSE;
}

const char* EGL::QueryString(EGLDisplay dpy, EGLint name)
{
    (void)dpy;
    (void)name;

    NO_IMPL();
    return 0;
}

EGLBoolean EGL::GetConfigs(EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
    (void)dpy;
    (void)configs;
    (void)config_size;
    (void)num_config;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::ChooseConfig(
    EGLDisplay dpy,
    const EGLint *attrib_list,
    EGLConfig *configs,
    EGLint config_size,
    EGLint *num_config)
{
    (void)dpy;
    (void)attrib_list;
    (void)configs;
    (void)config_size;
    (void)num_config;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::GetConfigAttrib(
    EGLDisplay dpy,
    EGLConfig config,
    EGLint attribute,
    EGLint *value)
{
    (void)dpy;
    (void)config;
    (void)attribute;
    (void)value;

    NO_IMPL();
    return EGL_FALSE;
}

EGLSurface EGL::CreateWindowSurface(
    EGLDisplay dpy,
    EGLConfig config,
    EGLNativeWindowType win,
    const EGLint *attrib_list)
{
    (void)dpy;
    (void)config;
    (void)win;
    (void)attrib_list;

    NO_IMPL();
    return EGL_NO_SURFACE;
}

EGLSurface EGL::CreatePbufferSurface(
    EGLDisplay dpy,
    EGLConfig config,
    const EGLint *attrib_list)
{
    (void)dpy;
    (void)config;
    (void)attrib_list;

    NO_IMPL();
    return EGL_NO_SURFACE;
}

EGLSurface EGL::CreatePixmapSurface(
    EGLDisplay dpy,
    EGLConfig config,
    EGLNativePixmapType pixmap,
    const EGLint *attrib_list)
{
    (void)dpy;
    (void)config;
    (void)pixmap;
    (void)attrib_list;

    NO_IMPL();
    return EGL_NO_SURFACE;
}

EGLBoolean EGL::DestroySurface(EGLDisplay dpy, EGLSurface surface)
{
    (void)dpy;
    (void)surface;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::QuerySurface(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLint attribute,
    EGLint *value)
{
    (void)dpy;
    (void)surface;
    (void)attribute;
    (void)value;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::BindAPI(EGLenum api)
{
    (void)api;

    NO_IMPL();
    return EGL_FALSE;
}

EGLenum EGL::QueryAPI(void)
{
    NO_IMPL();
    return EGL_NONE;
}

EGLBoolean EGL::WaitClient(void)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::ReleaseThread(void)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLSurface EGL::CreatePbufferFromClientBuffer(
    EGLDisplay dpy,
    EGLenum buftype,
    EGLClientBuffer buffer,
    EGLConfig config,
    const EGLint *attrib_list)
{
    (void)dpy;
    (void)buftype;
    (void)buffer;
    (void)config;
    (void)attrib_list;

    NO_IMPL();
    return EGL_NO_SURFACE;
}

EGLBoolean EGL::SurfaceAttrib(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLint attribute,
    EGLint value)
{
    (void)dpy;
    (void)surface;
    (void)attribute;
    (void)value;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::BindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    (void)dpy;
    (void)surface;
    (void)buffer;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::ReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    (void)dpy;
    (void)surface;
    (void)buffer;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::SwapInterval(EGLDisplay dpy, EGLint interval)
{
    (void)dpy;
    (void)interval;

    NO_IMPL();
    return EGL_FALSE;
}

EGLContext EGL::CreateContext(
    EGLDisplay dpy,
    EGLConfig config,
    EGLContext share_context,
    const EGLint *attrib_list)
{
    (void)dpy;
    (void)config;
    (void)share_context;
    (void)attrib_list;

    NO_IMPL();
    return EGL_NO_CONTEXT;
}

EGLBoolean EGL::DestroyContext(EGLDisplay dpy, EGLContext ctx)
{
    (void)dpy;
    (void)ctx;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::MakeCurrent(
    EGLDisplay dpy,
    EGLSurface draw,
    EGLSurface read,
    EGLContext ctx)
{
    (void)dpy;
    (void)draw;
    (void)read;
    (void)ctx;

    NO_IMPL();
    return EGL_FALSE;
}

EGLContext EGL::GetCurrentContext(void)
{
    NO_IMPL();
    return EGL_NO_CONTEXT;
}

EGLSurface EGL::GetCurrentSurface(EGLint readdraw)
{
    (void)readdraw;

    NO_IMPL();
    return EGL_NO_SURFACE;
}

EGLDisplay EGL::GetCurrentDisplay(void)
{
    NO_IMPL();
    return EGL_NO_DISPLAY;
}

EGLBoolean EGL::QueryContext(
    EGLDisplay dpy,
    EGLContext ctx,
    EGLint attribute,
    EGLint *value)
{
    (void)dpy;
    (void)ctx;
    (void)attribute;
    (void)value;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::WaitGL(void)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::WaitNative(EGLint engine)
{
    (void)engine;
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::SwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
    (void)dpy;
    (void)surface;

    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean EGL::CopyBuffers(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLNativePixmapType target)
{
    (void)dpy;
    (void)surface;
    (void)target;

    NO_IMPL();
    return EGL_FALSE;
}

__eglMustCastToProperFunctionPointerType EGL::GetProcAddress(const char *procname)
{
    (void)procname;
    NO_IMPL();
    return 0;
}

}

