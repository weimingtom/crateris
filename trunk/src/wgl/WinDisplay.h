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

#ifndef CRATERIS_WGL_WIN_DISPLAY_H_INCLUDED_
#define CRATERIS_WGL_WIN_DISPLAY_H_INCLUDED_

#include <windows.h>
#include "WGL.h"
#include "WGLUtility.h"

namespace crateris {

class WinDisplay
{
public:
    WinDisplay(WGL* owner, HDC hdc);
    ~WinDisplay();

    bool initialize();

    const char * QueryString(EGLint name);

    EGLBoolean GetConfigs(
        EGLConfig *configs,
        EGLint config_size,
        EGLint *num_config);

    EGLBoolean ChooseConfig(
        const EGLint *attrib_list,
        EGLConfig *configs,
        EGLint config_size,
        EGLint *num_config);

    EGLBoolean GetConfigAttrib(
        EGLConfig config,
        EGLint attribute,
        EGLint *value);

    bool validate(EGLConfig config);
    const Config& getConfig(EGLConfig config);

private:
    WGL* owner_;
    HDC hdc_;
    ConfigList configs_;
};

}

#endif
