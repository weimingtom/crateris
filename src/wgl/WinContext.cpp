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

#include "WinContext.h"
#include "WinGLES.h"
#include "WinGLES2.h"
#include "Extensions.h"

namespace crateris {

WinContext::WinContext(const Config& config, int client_version)
: surface_(0)
, config_(config)
, api_version_(API_OPENGL_ES_1_1)
, gles_(0)
, gles2_(0)
, hglrc_(NULL)
{
    if (client_version == 2) {
        api_version_ = API_OPENGL_ES_2_0;
    }
}

WinContext::~WinContext()
{
    if (gles_) {
        delete gles_;
    }
    if (gles2_) {
        delete gles2_;
    }
    if (hglrc_) {
        wglDeleteContext(hglrc_);
    }
}

bool WinContext::Swap()
{
    return surface_->Swap();
}

bool WinContext::create(WinSurface* surface)
{
    if (!surface)
        return false;

    HDC hdc = surface->getHDC();

    if (!hdc)
        return false;

    surface_ = surface;

    bool ret = false;

    // Temporary
    HGLRC temp_hglrc = wglCreateContext(hdc);

    if (temp_hglrc) {

        wglMakeCurrent(hdc, temp_hglrc);

        HGLRC hglrc;
        int valid_es2_profile = 0;
        hglrc = crateris_createContext(hdc, api_version_ == API_OPENGL_ES_2_0, &valid_es2_profile);

        if (hglrc) {
            wglMakeCurrent(hdc, hglrc);

            // Load API
            if (gles_) {
                delete gles_;
                gles_ = 0;
            }
            if (gles2_) {
                delete gles2_;
                gles2_ = 0;
            }

            if (api_version_ == API_OPENGL_ES_1_1) {
                gles_ = new WinGLES();
                gles_->loadGLAPI();
            } else if (api_version_ == API_OPENGL_ES_2_0) {
                gles2_ = new WinGLES2();
                gles2_->loadGLAPI(0 != valid_es2_profile);
            }

            if (hglrc_) {
                wglDeleteContext(hglrc_);
            }

            hglrc_ = hglrc;
            ret = true;
        }
    }

    if (temp_hglrc) {
        wglDeleteContext(temp_hglrc);
    }

    return ret;
}

GLES* WinContext::getGLES()
{
    return gles_;
}

GLES2* WinContext::getGLES2()
{
    return gles2_;
}

}
