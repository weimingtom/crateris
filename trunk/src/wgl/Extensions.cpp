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


typedef signed   char          khronos_int8_t;
typedef unsigned char          khronos_uint8_t;
typedef signed   short int     khronos_int16_t;
typedef unsigned short int     khronos_uint16_t;
typedef signed   long  int     khronos_intptr_t;
typedef unsigned long  int     khronos_uintptr_t;
typedef signed   long  int     khronos_ssize_t;
typedef unsigned long  int     khronos_usize_t;
typedef          float         khronos_float_t;
typedef __int32                 khronos_int32_t;
typedef unsigned __int32        khronos_uint32_t;
typedef __int64                 khronos_int64_t;
typedef unsigned __int64        khronos_uint64_t;

typedef void             GLvoid;
typedef char             GLchar;
typedef unsigned int     GLenum;
typedef unsigned char    GLboolean;
typedef unsigned int     GLbitfield;
typedef khronos_int8_t   GLbyte;
typedef short            GLshort;
typedef int              GLint;
typedef int              GLsizei;
typedef khronos_uint8_t  GLubyte;
typedef unsigned short   GLushort;
typedef unsigned int     GLuint;
typedef khronos_float_t  GLfloat;
typedef khronos_float_t  GLclampf;
typedef khronos_int32_t  GLfixed;
typedef khronos_int32_t  GLclampx;

typedef khronos_intptr_t GLintptr;
typedef khronos_ssize_t  GLsizeiptr;

#include "wglext.h"
#include "Extensions.h"

static PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
static PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB = NULL;
static PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;
static PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = NULL;
static PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = NULL;

static void initialize();

HGLRC crateris_createContext(HDC hdc, int es2_profile, int* valid_es2_profile)
{
    initialize();

    //if (wglGetExtensionsStringARB) {
    //    OutputDebugStringA(wglGetExtensionsStringARB(hdc));
    //}

    HGLRC ctx = NULL;
    if (wglCreateContextAttribsARB) {
        if (es2_profile) {
            int attrib[] = {
                WGL_CONTEXT_MAJOR_VERSION_ARB, 2,
                WGL_CONTEXT_MINOR_VERSION_ARB, 0,
                WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_ES2_PROFILE_BIT_EXT,
                0,
            };
            ctx = wglCreateContextAttribsARB(hdc, 0, attrib);

            if (valid_es2_profile) {
                *valid_es2_profile = (ctx != NULL);
            }

        } else {
            ctx = wglCreateContextAttribsARB(hdc, 0, NULL);

            if (valid_es2_profile) {
                *valid_es2_profile = 0;
            }
        }

        if (ctx) {
            return ctx;
        }
    }

    if (valid_es2_profile) {
        *valid_es2_profile = 0;
    }
    return wglCreateContext(hdc);
}

static bool initialized = false;
static void initialize()
{
    if (initialized)
        return ;

    wglCreateContextAttribsARB =
        (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

    wglMakeContextCurrentARB =
        (PFNWGLMAKECONTEXTCURRENTARBPROC)wglGetProcAddress("wglMakeContextCurrentARB");

    wglSwapIntervalEXT =
        (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");

    wglGetSwapIntervalEXT =
        (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT");

    wglGetExtensionsStringARB =
        (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB");

    initialized = true;
}
