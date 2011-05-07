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

#ifndef CRATERIS_WGL_IMPL_H_INCLUDED_
#define CRATERIS_WGL_IMPL_H_INCLUDED_

#include "EGL.h"
#include <vector>

namespace crateris {

class WinDisplay;
class WinContext;

class WGL
    : public EGL
{
public:
    WGL();
    virtual ~WGL();

    virtual EGLint GetError(void);
    virtual EGLDisplay GetDisplay(EGLNativeDisplayType display_id);
    virtual EGLBoolean Initialize(EGLDisplay dpy, EGLint *major, EGLint *minor);
    virtual EGLBoolean Terminate(EGLDisplay dpy);
    virtual const char * QueryString(EGLDisplay dpy, EGLint name);
    virtual EGLBoolean GetConfigs(EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config);
    virtual EGLBoolean ChooseConfig(
        EGLDisplay dpy, const EGLint *attrib_list,
        EGLConfig *configs, EGLint config_size,
        EGLint *num_config);
    virtual EGLBoolean GetConfigAttrib(
        EGLDisplay dpy, EGLConfig config,
        EGLint attribute, EGLint *value);
    virtual EGLSurface CreateWindowSurface(
        EGLDisplay dpy, EGLConfig config,
        EGLNativeWindowType win,
        const EGLint *attrib_list);
    virtual EGLSurface CreatePbufferSurface(
        EGLDisplay dpy, EGLConfig config,
        const EGLint *attrib_list);
    virtual EGLSurface CreatePixmapSurface(
        EGLDisplay dpy, EGLConfig config,
        EGLNativePixmapType pixmap,
        const EGLint *attrib_list);
    virtual EGLBoolean DestroySurface(EGLDisplay dpy, EGLSurface surface);
    virtual EGLBoolean QuerySurface(
        EGLDisplay dpy, EGLSurface surface,
        EGLint attribute, EGLint *value);
    virtual EGLBoolean BindAPI(EGLenum api);
    virtual EGLenum QueryAPI(void);
    virtual EGLBoolean WaitClient(void);
    virtual EGLBoolean ReleaseThread(void);
    virtual EGLSurface CreatePbufferFromClientBuffer(
        EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer,
        EGLConfig config, const EGLint *attrib_list);
    virtual EGLBoolean SurfaceAttrib(
        EGLDisplay dpy, EGLSurface surface,
        EGLint attribute, EGLint value);
    virtual EGLBoolean BindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
    virtual EGLBoolean ReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
    virtual EGLBoolean SwapInterval(EGLDisplay dpy, EGLint interval);
    virtual EGLContext CreateContext(
        EGLDisplay dpy, EGLConfig config,
        EGLContext share_context,
        const EGLint *attrib_list);
    virtual EGLBoolean DestroyContext(EGLDisplay dpy, EGLContext ctx);
    virtual EGLBoolean MakeCurrent(
        EGLDisplay dpy, EGLSurface draw,
        EGLSurface read, EGLContext ctx);
    virtual EGLContext GetCurrentContext(void);
    virtual EGLSurface GetCurrentSurface(EGLint readdraw);
    virtual EGLDisplay GetCurrentDisplay(void);
    virtual EGLBoolean QueryContext(
        EGLDisplay dpy, EGLContext ctx,
        EGLint attribute, EGLint *value);
    virtual EGLBoolean WaitGL(void);
    virtual EGLBoolean WaitNative(EGLint engine);
    virtual EGLBoolean SwapBuffers(EGLDisplay dpy, EGLSurface surface);
    virtual EGLBoolean CopyBuffers(EGLDisplay dpy, EGLSurface surface,
        EGLNativePixmapType target);
    virtual __eglMustCastToProperFunctionPointerType GetProcAddress(const char *procname);

    virtual GLES* getGLES();
    virtual GLES2* getGLES2();
    virtual void setError(EGLint error);

    WinContext* getCurrentContext();
    void setCurrentContext(WinContext* ctx);

private:
    struct DisplayItem {
        EGLNativeDisplayType hdc;
        WinDisplay* dpy_;
    };

    bool validate(EGLDisplay dpy);

private:
    EGLint error_;
    std::vector<DisplayItem> dpys_;
    DWORD tls_index_;
};

}

#endif
