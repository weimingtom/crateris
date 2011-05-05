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

#ifndef CRATERIS_WGL_WIN_CONTEXT_H_INCLUDED_
#define CRATERIS_WGL_WIN_CONTEXT_H_INCLUDED_

#include "WinSurface.h"

namespace crateris {

class WinGLES;
class WinGLES2;
class GLES;
class GLES2;

enum APIVersion
{
    API_OPENGL_ES_1_1 = 10,
    API_OPENGL_ES_2_0 = 20,
};

class WinContext
{
public:
    WinContext(const Config& config, int client_version);
    ~WinContext();

    bool Swap();

    bool create(WinSurface* surface);

    const Config& getConfig() { return config_; }
    WinSurface* getSurface() { return surface_; }

    GLES* getGLES();
    GLES2* getGLES2();

private:
    WinContext(const WinContext&);
    void operator=(const WinContext&);

private:
    WinSurface* surface_;
    const Config& config_;
    APIVersion api_version_;
    WinGLES* gles_;
    WinGLES2* gles2_;
};

}

#endif
