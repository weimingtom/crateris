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

#include "WGLUtility.h"

namespace crateris {

ConfigList::ConfigList()
{
}

ConfigList::~ConfigList()
{
}

bool ConfigList::initialize(HDC hdc)
{
    Config config = {
        1,
        {   sizeof(PIXELFORMATDESCRIPTOR), // nSize
            1,              // nVersion
            0,              // [o] dwFlags
            PFD_TYPE_RGBA,  // [o] iPixelType
            32,             // [o] cColorBits
            0, 0,           // [x] cRedBits/cRedShift
            0, 0,           // [x] cGreenBits/cGreenShift
            0, 0,           // [x] cBlueBits/cBlueShift
            0,              // [o] cAlphaBits
            0,              // [x] cAlphaShift
            0,              // [o] cAccumBits
            0,              // [x] cAccumRedBits
            0,              // [x] cAccumGreenBits
            0,              // [x] cAccumBlueBits
            0,              // [x] cAccumAlphaBits
            0,              // [o] cDepthBits
            0,              // [o] cStencilBits
            0,              // [x] cAuxBuffers
            PFD_MAIN_PLANE, // [o] iLayerType
            0,              // [x] bReserved
            0,              // [x] dwLayerMask
            0,              // [x] dwVisibleMask
            0               // [x] dwDamageMask
        },
    };

    HDC tmp = hdc;

    if (NULL == hdc) {
        tmp = GetDC(NULL);
    }

    list_.clear();

    // 8888
    config.desc_.cColorBits = 32;
    config.desc_.cAlphaBits = 8;
    config.desc_.dwFlags = PFD_SUPPORT_OPENGL;
    registerConfigs(tmp, config);

    // 888
    config.desc_.cColorBits = 24;
    config.desc_.cAlphaBits = 0;
    config.desc_.dwFlags = PFD_SUPPORT_OPENGL;
    registerConfigs(tmp, config);

    // 4444
    config.desc_.cColorBits = 16;
    config.desc_.cAlphaBits = 4;
    config.desc_.dwFlags = PFD_SUPPORT_OPENGL;
    registerConfigs(tmp, config);

    // 565
    config.desc_.cColorBits = 16;
    config.desc_.cAlphaBits = 0;
    config.desc_.dwFlags = PFD_SUPPORT_OPENGL;
    registerConfigs(tmp, config);

    // 5551
    config.desc_.cColorBits = 16;
    config.desc_.cAlphaBits = 1;
    config.desc_.dwFlags = PFD_SUPPORT_OPENGL;
    registerConfigs(tmp, config);


    if (hdc == NULL) {
        ReleaseDC(NULL, tmp);
    }

    return 0 != list_.size();
}

int ConfigList::count()
{
    return list_.size();
}

const Config& ConfigList::get(int index)
{
    return list_[index];
}

bool ConfigList::validate(int index)
{
    return 0 <= index && index < count();
}

void ConfigList::registerConfigs(HDC hdc, Config& config)
{
    DWORD flags = config.desc_.dwFlags;

    // Windowed without depth and stencil
    config.desc_.dwFlags = (flags|PFD_DRAW_TO_WINDOW|PFD_DOUBLEBUFFER/*|PFD_DRAW_TO_BITMAP*/);
    config.desc_.cDepthBits = 0;
    config.desc_.cStencilBits = 0;
    registerConfig(hdc, config);

    // without depth
    config.desc_.cDepthBits = CR_DEPTH_BITS;
    config.desc_.cStencilBits = 0;
    registerConfig(hdc, config);

    // With stencil
    config.desc_.cDepthBits = 0;
    config.desc_.cStencilBits = CR_STENCIL_BITS;
    registerConfig(hdc, config);

    // With depth and stencil
    config.desc_.cDepthBits = CR_DEPTH_BITS;
    config.desc_.cStencilBits = CR_STENCIL_BITS;
    registerConfig(hdc, config);

#if 0
    // Offscreen with depth
    config.desc_.dwFlags = (flags|PFD_DRAW_TO_BITMAP);
    config.desc_.cDepthBits = CR_DEPTH_BITS;
    config.desc_.cStencilBits = 0;
    registerConfig(hdc, config);

    // With depth and stencil
    config.desc_.cDepthBits = CR_DEPTH_BITS;
    config.desc_.cStencilBits = 8;
    registerConfig(hdc, config);

    // With depth and stencil
    config.desc_.cDepthBits = 0;
    config.desc_.cStencilBits = 8;
    registerConfig(hdc, config);

    // without depth and stencil
    config.desc_.cDepthBits = 0;
    config.desc_.cStencilBits = 0;
    registerConfig(hdc, config);
#endif

    // Clear flags
    config.desc_.cStencilBits = 0;
    config.desc_.cDepthBits = 0;
    config.desc_.dwFlags = flags;
}

void ConfigList::registerConfig(HDC hdc, Config& config)
{
    int idx = ChoosePixelFormat(hdc, &config.desc_);
    if (idx == 0) {
        // Ignore?
        OutputDebugStringA("Failed to ChoosePixelFormat");
        return ;
    }

    Config conf;

    conf.index_ = idx;
    DescribePixelFormat(hdc, idx, sizeof(conf.desc_), &conf.desc_);

    list_.push_back(conf);
}

}
