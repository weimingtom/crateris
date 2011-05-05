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

#include "WinSurface.h"

namespace crateris {

WinSurface::WinSurface()
: config_id_(0)
, hwnd_(0)
, hdc_(0)
{
}

WinSurface::~WinSurface()
{
    if (hglrc_) {
        wglDeleteContext(hglrc_);
    }

    if (hdc_) {
        ReleaseDC(hwnd_, hdc_);
    }
}

bool WinSurface::create(HWND win, const Config& config, int config_id)
{
    if (!win)
        return false;

    HDC dc = GetDC(win);
    if (NULL == dc)
        return false;

    if (FALSE == SetPixelFormat(dc, config.index_, &config.desc_))
        return false;

    if (hglrc_) {
        wglDeleteContext(hglrc_);
    }

    if (hdc_) {
        ReleaseDC(hwnd_, hdc_);
    }

    hwnd_ = win;
    hdc_ = dc;
    hglrc_ = wglCreateContext(dc);
    config_id_ = config_id;

    return true;
}

bool WinSurface::Swap()
{
    return (FALSE != ::SwapBuffers(hdc_));
}

int WinSurface::getWidth()
{
    RECT rect;
    ::GetClientRect(hwnd_, &rect);
    return rect.right;
}

int WinSurface::getHeight()
{
    RECT rect;
    ::GetClientRect(hwnd_, &rect);
    return rect.bottom;
}

}
