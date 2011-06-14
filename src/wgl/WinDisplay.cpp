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

#include "WinDisplay.h"

namespace crateris {

WinDisplay::WinDisplay(WGL* owner, HDC hdc)
: owner_(owner)
, hdc_(hdc)
{
}

WinDisplay::~WinDisplay()
{
}

bool WinDisplay::initialize()
{
    return configs_.initialize(hdc_);
}

bool WinDisplay::validate(EGLConfig config)
{
    int index = (int)config - 1;
    if (!configs_.validate(index)) {
        owner_->setError(EGL_BAD_CONFIG);
        return false;
    }

    return true;
}

const Config& WinDisplay::getConfig(EGLConfig config)
{
    int index = (int)config - 1;
    return configs_.get(index);
}

const char * WinDisplay::QueryString(EGLint name)
{
    (void)name;
    return 0;
}

EGLBoolean WinDisplay::GetConfigs(
    EGLConfig *configs,
    EGLint config_size,
    EGLint *num_config)
{
    if (!num_config || config_size < 0) {
        owner_->setError(EGL_BAD_PARAMETER);
        return EGL_FALSE;
    }

    if (!configs) {
        *num_config = configs_.count();
        return EGL_TRUE;
    }

    int i;
    int count = config_size < configs_.count() ? config_size : configs_.count();
    for (i = 0; i < count; ++i) {
        configs[i] = (EGLConfig)(i + 1);
    }

    *num_config = count;

    return EGL_TRUE;
}

EGLBoolean WinDisplay::ChooseConfig(
    const EGLint *attrib_list,
    EGLConfig *configs,
    EGLint config_size,
    EGLint *num_config)
{
    if (config_size <= 0 || !num_config) {
        owner_->setError(EGL_BAD_PARAMETER);
        return EGL_FALSE;
    }

    DWORD depth_size = 0;
    DWORD stencil_size = 0;
    DWORD alpha_size = 0;
    DWORD red_size = 0;
    DWORD green_size = 0;
    DWORD blue_size = 0;

    if (attrib_list) {
        const EGLint* attr = attrib_list;
        while (*attr != EGL_NONE)
        {
            EGLint type = *attr++;
            EGLint value = *attr++;
            switch (type)
            {
            case EGL_DEPTH_SIZE:
                if (value == EGL_DONT_CARE) {
                    break;
                }
                if (value < 0) {
                    owner_->setError(EGL_BAD_ATTRIBUTE);
                    return EGL_FALSE;
                }
                depth_size = (DWORD)value;
                break;
            case EGL_STENCIL_SIZE:
                if (value == EGL_DONT_CARE) {
                    break;
                }
                if (value < 0) {
                    owner_->setError(EGL_BAD_ATTRIBUTE);
                    return EGL_FALSE;
                }
                stencil_size = (DWORD)value;
                break;
            case EGL_ALPHA_SIZE:
                if (value == EGL_DONT_CARE) {
                    break;
                }
                if (value < 0) {
                    owner_->setError(EGL_BAD_ATTRIBUTE);
                    return EGL_FALSE;
                }
                alpha_size = (DWORD)value;
                break;
            case EGL_RED_SIZE:
                if (value < 0) {
                    owner_->setError(EGL_BAD_ATTRIBUTE);
                    return EGL_FALSE;
                }
                red_size = (DWORD)value;
                break;
            case EGL_GREEN_SIZE:
                if (value < 0) {
                    owner_->setError(EGL_BAD_ATTRIBUTE);
                    return EGL_FALSE;
                }
                green_size = (DWORD)value;
                break;
            case EGL_BLUE_SIZE:
                if (value < 0) {
                    owner_->setError(EGL_BAD_ATTRIBUTE);
                    return EGL_FALSE;
                }
                blue_size = (DWORD)value;
                break;
            case EGL_BUFFER_SIZE:
            case EGL_CONFIG_CAVEAT:
            case EGL_CONFIG_ID:
            case EGL_LEVEL:
            case EGL_NATIVE_RENDERABLE:
            case EGL_NATIVE_VISUAL_TYPE:
            case EGL_SAMPLE_BUFFERS:
            case EGL_SAMPLES:
            case EGL_SURFACE_TYPE:
            case EGL_TRANSPARENT_TYPE:
            case EGL_TRANSPARENT_RED_VALUE:
            case EGL_TRANSPARENT_GREEN_VALUE:
            case EGL_TRANSPARENT_BLUE_VALUE:
            default:
                break;
            }
        }
    }

    DWORD color_size = alpha_size + red_size + green_size + blue_size;
    int count, i;
    int* list = (int*)malloc(sizeof(int) * configs_.count());
    for (i = 0, count = 0; i < configs_.count(); ++i) {
        const Config& c = configs_.get(i);
        if (c.desc_.cDepthBits >= depth_size &&
            c.desc_.cStencilBits >= stencil_size &&
            c.desc_.cColorBits >= color_size)
        {
            list[count] = i;
            ++count;
        }
    }

    *num_config = count;

    // Copy configs
    if (count && configs) {
        if (config_size < count) {
            count = config_size;
        }

        for (i = 0; i < count; ++i) {
            configs[i] = (EGLConfig)(list[i] + 1);
        }
    }

    free(list);

    return EGL_TRUE;
}

EGLBoolean WinDisplay::GetConfigAttrib(
    EGLConfig config,
    EGLint attribute,
    EGLint *value)
{
    if (!value) {
        owner_->setError(EGL_BAD_PARAMETER);
        return EGL_FALSE;
    }

    int index = (int)config - 1;
    if (!configs_.validate(index)) {
        owner_->setError(EGL_BAD_CONFIG);
        return EGL_FALSE;
    }

    const Config& c = configs_.get(index);

    switch (attribute) {
    case EGL_BUFFER_SIZE:
        *value = c.desc_.cColorBits;
        break;
    case EGL_RED_SIZE:
        *value = c.desc_.cRedBits;
        break;
    case EGL_GREEN_SIZE:
        *value = c.desc_.cGreenBits;
        break;
    case EGL_BLUE_SIZE:
        *value = c.desc_.cBlueBits;
        break;
    case EGL_ALPHA_SIZE:
        *value = c.desc_.cAlphaBits;
        break;
    case EGL_DEPTH_SIZE:
        *value = c.desc_.cDepthBits;
        break;
    case EGL_STENCIL_SIZE:
        *value = c.desc_.cStencilBits;
        break;
    case EGL_CONFIG_CAVEAT:
        *value = EGL_NONE;
        break;
    case EGL_CONFIG_ID:
        *value = index;
        break;
    case EGL_LEVEL:
        *value = 0;
        break;
    case EGL_MAX_PBUFFER_WIDTH:
    case EGL_MAX_PBUFFER_HEIGHT:
        *value = 4096;
        break;
    case EGL_MAX_PBUFFER_PIXELS:
        *value = 0x1000 * 0x1000 * 4;
        break;
    case EGL_NATIVE_RENDERABLE:
        *value = EGL_FALSE;
        break;
    case EGL_NATIVE_VISUAL_ID:
        *value = 0;
        break;
    case EGL_NATIVE_VISUAL_TYPE:
        *value = 0;
        break;
    case EGL_SAMPLE_BUFFERS:
        *value = 0;
        break;
    case EGL_SAMPLES:
        *value = 0;
        break;
    case EGL_SURFACE_TYPE:
        *value = EGL_WINDOW_BIT/*|EGL_PIXMAP_BIT*/;
        break;
    case EGL_TRANSPARENT_TYPE:
        *value = EGL_NONE;
        break;
    case EGL_TRANSPARENT_RED_VALUE:
    case EGL_TRANSPARENT_GREEN_VALUE:
    case EGL_TRANSPARENT_BLUE_VALUE:
        *value = 0;
        break;

    default:
        owner_->setError(EGL_BAD_ATTRIBUTE);
        return EGL_FALSE;
    }

    return EGL_TRUE;
}

}
