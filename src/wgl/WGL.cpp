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

#include <windows.h>
#include "WGL.h"
#include "WinDisplay.h"
#include "WinContext.h"
#include "WinSurface.h"

#define NO_IMPL()

static crateris::WGL* s_singleton = 0;

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpvReserved)
{
    (void)hinstDLL;
    (void)lpvReserved;

    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        s_singleton = new crateris::WGL();
        break;
    case DLL_PROCESS_DETACH:
        if (s_singleton)
        {
            delete s_singleton;
            s_singleton = 0;
        }
        break;
    default:
        break;
    }

    return TRUE;
}

CR_API crateris::EGL* crateris_get_EGL()
{
    return s_singleton;
}

namespace crateris {

WGL::WGL()
: error_(EGL_NOT_INITIALIZED)
, tls_index_(0xffffffff)
{
    dpy_ = new WinDisplay(this, NULL);
    tls_index_ = TlsAlloc();
}

WGL::~WGL()
{
    TlsFree(tls_index_);

    if (dpy_) {
        delete dpy_;
    }
}

WinContext* WGL::getCurrentContext()
{
    return (WinContext*)TlsGetValue(tls_index_);
}

void WGL::setCurrentContext(WinContext* ctx)
{
    TlsSetValue(tls_index_, ctx);
}

EGLint WGL::GetError(void)
{
    return error_;
}

void WGL::setError(EGLint error)
{
    error_ = error;
}

EGLDisplay WGL::GetDisplay(
    EGLNativeDisplayType display_id)
{
    if (display_id == EGL_DEFAULT_DISPLAY) {
        return dpy_;
    } else {
        return EGL_NO_DISPLAY;
    }
}

EGLBoolean WGL::Initialize(
    EGLDisplay dpy,
    EGLint *major,
    EGLint *minor)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    if (!dpy_->initialize()) {
        setError(EGL_NOT_INITIALIZED);
        return EGL_FALSE;
    }

    if (major)
        *major = 1;

    if (minor)
        *minor = 4;

    return EGL_TRUE;
}

EGLBoolean WGL::Terminate(EGLDisplay dpy)
{
    return EGL_TRUE;
}

const char* WGL::QueryString(EGLDisplay dpy, EGLint name)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return 0;
    }

    return dpy_->QueryString(name);
}

EGLBoolean WGL::GetConfigs(
    EGLDisplay dpy,
    EGLConfig *configs,
    EGLint config_size,
    EGLint *num_config)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    return dpy_->GetConfigs(configs, config_size, num_config);
}

EGLBoolean WGL::ChooseConfig(
    EGLDisplay dpy,
    const EGLint *attrib_list,
    EGLConfig *configs,
    EGLint config_size,
    EGLint *num_config)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    return dpy_->ChooseConfig(attrib_list, configs, config_size, num_config);
}

EGLBoolean WGL::GetConfigAttrib(
    EGLDisplay dpy,
    EGLConfig config,
    EGLint attribute,
    EGLint *value)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    return dpy_->GetConfigAttrib(config, attribute, value);
}

EGLSurface WGL::CreateWindowSurface(
    EGLDisplay dpy,
    EGLConfig config,
    EGLNativeWindowType win,
    const EGLint *attrib_list)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_NO_SURFACE;
    }

    if (!dpy_->validate(config)) {
        setError(EGL_BAD_CONFIG);
        return EGL_NO_SURFACE;
    }

    if (!win) {
        setError(EGL_BAD_NATIVE_WINDOW);
        return EGL_NO_SURFACE;
    }

    WinSurface* surface = new WinSurface();

    bool ret = surface->create(win, dpy_->getConfig(config), (int)config);
    if (!ret) {
        delete surface;
        setError(EGL_BAD_NATIVE_WINDOW);
        return EGL_NO_SURFACE;
    }

    return surface;
}

EGLSurface WGL::CreatePbufferSurface(
    EGLDisplay dpy,
    EGLConfig config,
    const EGLint *attrib_list)
{
    NO_IMPL();
    return EGL_NO_SURFACE;
}

EGLSurface WGL::CreatePixmapSurface(
    EGLDisplay dpy,
    EGLConfig config,
    EGLNativePixmapType pixmap,
    const EGLint *attrib_list)
{
    NO_IMPL();
    return EGL_NO_SURFACE;
}

EGLBoolean WGL::DestroySurface(EGLDisplay dpy, EGLSurface surface)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    if (!surface) {
        setError(EGL_BAD_SURFACE);
        return EGL_FALSE;
    }

    WinSurface* srf = (WinSurface*)surface;

    delete srf;

    return EGL_TRUE;
}

EGLBoolean WGL::QuerySurface(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLint attribute,
    EGLint *value)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    if (!surface) {
        setError(EGL_BAD_SURFACE);
        return EGL_FALSE;
    }

    if (!value) {
        setError(EGL_BAD_PARAMETER);
        return EGL_FALSE;
    }

    switch (attribute) {
    case EGL_WIDTH:
        *value = ((WinSurface*)surface)->getWidth();
        break;
    case EGL_HEIGHT:
        *value = ((WinSurface*)surface)->getHeight();
        break;
    case EGL_CONFIG_ID:
        *value = ((WinSurface*)surface)->getConfigID();
        break;
    default:
        break;
    }
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean WGL::BindAPI(EGLenum api)
{
    if (api == EGL_OPENGL_ES_API) {
        return EGL_TRUE;
    }

    setError(EGL_BAD_PARAMETER);
    return EGL_FALSE;
}

EGLenum WGL::QueryAPI(void)
{
    NO_IMPL();
    return EGL_NONE;
}

EGLBoolean WGL::WaitClient(void)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean WGL::ReleaseThread(void)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLSurface WGL::CreatePbufferFromClientBuffer(
    EGLDisplay dpy,
    EGLenum buftype,
    EGLClientBuffer buffer,
    EGLConfig config,
    const EGLint *attrib_list)
{
    NO_IMPL();
    return EGL_NO_SURFACE;
}

EGLBoolean WGL::SurfaceAttrib(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLint attribute,
    EGLint value)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean WGL::BindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean WGL::ReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean WGL::SwapInterval(EGLDisplay dpy, EGLint interval)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLContext WGL::CreateContext(
    EGLDisplay dpy,
    EGLConfig config,
    EGLContext share_context,
    const EGLint *attrib_list)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_NO_CONTEXT;
    }

    if (!dpy_->validate(config)) {
        setError(EGL_BAD_CONFIG);
        return EGL_NO_CONTEXT;
    }

    int client_version = 1;
    if (attrib_list) {
        EGLint key, value;

        while (*attrib_list != EGL_NONE) {
            key = *attrib_list++;
            value = *attrib_list++;
            switch (key) {
            case EGL_CONTEXT_CLIENT_VERSION:
                client_version = value;
                break;
            default:
                break;
            }
        }
    }

    WinContext* ctx = new WinContext(dpy_->getConfig(config), client_version);

    return ctx;
}

EGLBoolean WGL::DestroyContext(EGLDisplay dpy, EGLContext ctx)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    if (!ctx) { 
        setError(EGL_BAD_CONTEXT);
        return EGL_FALSE;
    }

    WinContext* context = (WinContext*)ctx;

    delete context;

    return EGL_TRUE;
}

EGLBoolean WGL::MakeCurrent(
    EGLDisplay dpy,
    EGLSurface draw,
    EGLSurface read,
    EGLContext ctx)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    if (!draw || !read) {
        setError(EGL_BAD_SURFACE);
        return EGL_FALSE;
    }

    if (!ctx) { 
        setError(EGL_BAD_CONTEXT);
        return EGL_FALSE;
    }

    WinContext* context = (WinContext*)ctx;

    bool ret = context->create((WinSurface*)draw);

    if (ret) {
        setCurrentContext(context);
    }

    return ret ? EGL_TRUE : EGL_FALSE;
}

EGLContext WGL::GetCurrentContext(void)
{
    return getCurrentContext();
}

EGLSurface WGL::GetCurrentSurface(EGLint readdraw)
{
    WinContext* ctx = getCurrentContext();
    if (!ctx) {
        return EGL_NO_SURFACE;
    }

    return ctx->getSurface();
}

EGLDisplay WGL::GetCurrentDisplay(void)
{
    NO_IMPL();
    return EGL_NO_DISPLAY;
}

EGLBoolean WGL::QueryContext(
    EGLDisplay dpy,
    EGLContext ctx,
    EGLint attribute,
    EGLint *value)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean WGL::WaitGL(void)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean WGL::WaitNative(EGLint engine)
{
    NO_IMPL();
    return EGL_FALSE;
}

EGLBoolean WGL::SwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
    if (dpy != dpy_) {
        setError(EGL_BAD_DISPLAY);
        return EGL_FALSE;
    }

    if (!surface) {
        setError(EGL_BAD_SURFACE);
        return EGL_FALSE;
    }

    WinSurface* srf = (WinSurface*)surface;

    bool ret = srf->Swap();

    return ret ? EGL_TRUE : EGL_FALSE;
}

EGLBoolean WGL::CopyBuffers(
    EGLDisplay dpy,
    EGLSurface surface,
    EGLNativePixmapType target)
{
    NO_IMPL();
    return EGL_FALSE;
}

__eglMustCastToProperFunctionPointerType WGL::GetProcAddress(const char *procname)
{
    return (__eglMustCastToProperFunctionPointerType)::wglGetProcAddress(procname);
}

GLES* WGL::getGLES()
{
    WinContext* ctx = getCurrentContext();
    return ctx ? ctx->getGLES() : 0;
}

GLES2* WGL::getGLES2()
{
    WinContext* ctx = getCurrentContext();
    return ctx ? ctx->getGLES2() : 0;
}

}
