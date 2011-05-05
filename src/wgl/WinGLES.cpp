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

#include "WinGLES.h"
#include <stdio.h>

// typedef func
#define DEF_GLAPI0(rettype, name, params)   typedef rettype (__stdcall *Func##name) params;
#define DEF_GLAPI1(rettype, name, params)   DEF_GLAPI0(rettype, name, params)
#include "glapi.inl" // Define
#undef DEF_GLAPI0
#undef DEF_GLAPI1

#define DEF_GLAPI0(rettype, name, params)   static Func##name proxy_gl##name = 0;
#define DEF_GLAPI1(rettype, name, params)   DEF_GLAPI0(rettype, name, params)
#include "glapi.inl" // Define
#undef DEF_GLAPI0
#undef DEF_GLAPI1

static FuncClearDepth proxy_glClearDepthf = 0;
static FuncClipPlane proxy_glClipPlanef = 0;
static FuncDepthRange proxy_glDepthRangef = 0;
static FuncFrustum proxy_glFrustumf = 0;
static FuncGetClipPlane proxy_glGetClipPlanef = 0;
static FuncOrtho proxy_glOrthof = 0;

#define CALL(name, exp) \
    ((proxy_gl##name) ? (proxy_gl##name exp) : (GLES::name exp))

#define NO_IMPL()

namespace crateris {

WinGLES::WinGLES()
{
}

WinGLES::~WinGLES()
{
    if (module_) {
        FreeLibrary(module_);
    }
}

static bool validate(void* func, const char* name)
{
    if (!func) {
        char buf[256];
        sprintf_s(buf, sizeof(buf), "Failed to load %s in WinGLES.\n", name);
        OutputDebugStringA(buf);
    }
    return func != 0;
}

bool WinGLES::loadGLAPI()
{
    HMODULE mod = LoadLibraryA("opengl32.dll");
    bool ret = true;

#define DEF_GLAPI0(rettype, name, params)   \
    proxy_gl##name = (Func##name)GetProcAddress(mod, "gl" #name); \
    ret = validate(proxy_gl##name, "gl" #name) && ret;

#define DEF_GLAPI1(rettype, name, params)   \
    proxy_gl##name = (Func##name)wglGetProcAddress("gl" #name); \
    ret = validate(proxy_gl##name, "gl" #name) && ret;

#define DEF_GLAPI2(rettype, name, params)   DEF_GLAPI0(rettype, name, params)
#include "glapi.inl"

    proxy_glClearDepthf = proxy_glClearDepth;
    proxy_glDepthRangef = proxy_glDepthRange;
    proxy_glFrustumf = proxy_glFrustum;
    proxy_glOrthof = proxy_glOrthof;

    proxy_glClipPlanef = proxy_glClipPlane;
    proxy_glGetClipPlanef = proxy_glGetClipPlane;

    module_ = mod;

    return ret;
}

void WinGLES::AlphaFunc(
    GLenum func,
    GLclampf ref)
{
    CALL(AlphaFunc, (func, ref));
}

void WinGLES::ClearColor(
    GLclampf red,
    GLclampf green,
    GLclampf blue,
    GLclampf alpha)
{
    CALL(ClearColor, (red, green, blue, alpha));
}

void WinGLES::ClearDepthf(GLclampf depth)
{
    CALL(ClearDepthf, (depth));
}

void WinGLES::ClipPlanef(
    GLenum plane,
    const GLfloat *equation)
{
    if (!proxy_glClipPlanef) {
        GLES::ClipPlanef(plane, equation);
        return ;
    }

    double eqn[4] = {equation[0], equation[1], equation[2], equation[3]};
    proxy_glClipPlanef(plane, eqn);
}

void WinGLES::Color4f(
    GLfloat red,
    GLfloat green,
    GLfloat blue,
    GLfloat alpha)
{
    CALL(Color4f, (red, green, blue, alpha));
}

void WinGLES::DepthRangef(
    GLclampf zNear,
    GLclampf zFar)
{
    CALL(DepthRangef, (zNear, zFar));
}

void WinGLES::Fogf(
    GLenum pname,
    GLfloat param)
{
    CALL(Fogf, (pname, param));
}

void WinGLES::Fogfv(
    GLenum pname,
    const GLfloat *params)
{
    CALL(Fogfv, (pname, params));
}

void WinGLES::Frustumf(
    GLfloat left,
    GLfloat right,
    GLfloat bottom,
    GLfloat top,
    GLfloat zNear,
    GLfloat zFar)
{
    CALL(Frustumf, (left, right, bottom, top, zNear, zFar));
}

void WinGLES::GetClipPlanef(
    GLenum pname,
    GLfloat eqn[4])
{
    if (!proxy_glGetClipPlanef) {
        WinGLES::GetClipPlanef(pname, eqn);
        return ;
    }

    double equation[4];
    proxy_glGetClipPlanef(pname, equation);
    eqn[0] = (GLfloat)equation[0];
    eqn[1] = (GLfloat)equation[1];
    eqn[2] = (GLfloat)equation[2];
    eqn[3] = (GLfloat)equation[3];
}

void WinGLES::GetFloatv(
    GLenum pname,
    GLfloat *params)
{
    CALL(GetFloatv, (pname, params));
}

void WinGLES::GetLightfv(
    GLenum light,
    GLenum pname,
    GLfloat *params)
{
    CALL(GetLightfv, (light, pname, params));
}

void WinGLES::GetMaterialfv(
    GLenum face,
    GLenum pname,
    GLfloat *params)
{
    CALL(GetMaterialfv, (face, pname, params));
}

void WinGLES::GetTexEnvfv(
    GLenum env,
    GLenum pname,
    GLfloat *params)
{
    CALL(GetTexEnvfv, (env, pname, params));
}

void WinGLES::GetTexParameterfv(
    GLenum target,
    GLenum pname,
    GLfloat *params)
{
    CALL(GetTexParameterfv, (target, pname, params));
}

void WinGLES::LightModelf(
    GLenum pname,
    GLfloat param)
{
    CALL(LightModelf, (pname, param));
}

void WinGLES::LightModelfv(
    GLenum pname,
    const GLfloat *params)
{
    CALL(LightModelfv, (pname, params));
}

void WinGLES::Lightf(
    GLenum light,
    GLenum pname,
    GLfloat param)
{
    CALL(Lightf, (light, pname, param));
}

void WinGLES::Lightfv(
    GLenum light,
    GLenum pname,
    const GLfloat *params)
{
    CALL(Lightfv, (light, pname, params));
}

void WinGLES::LineWidth(GLfloat width)
{
    CALL(LineWidth, (width));
}

void WinGLES::LoadMatrixf(const GLfloat *m)
{
    CALL(LoadMatrixf, (m));
}

void WinGLES::Materialf(
    GLenum face,
    GLenum pname,
    GLfloat param)
{
    CALL(Materialf, (face, pname, param));
}

void WinGLES::Materialfv(
    GLenum face,
    GLenum pname,
    const GLfloat *params)
{
    CALL(Materialfv, (face, pname, params));
}

void WinGLES::MultMatrixf(const GLfloat *m)
{
    CALL(MultMatrixf, (m));
}

void WinGLES::MultiTexCoord4f(
    GLenum target,
    GLfloat s,
    GLfloat t,
    GLfloat r,
    GLfloat q)
{
    CALL(MultiTexCoord4f, (target, s, t, r, q));
}

void WinGLES::Normal3f(
    GLfloat nx,
    GLfloat ny,
    GLfloat nz)
{
    CALL(Normal3f, (nx, ny, nz));
}

void WinGLES::Orthof(
    GLfloat left,
    GLfloat right,
    GLfloat bottom,
    GLfloat top,
    GLfloat zNear,
    GLfloat zFar)
{
    CALL(Orthof, (left, right, bottom, top, zNear, zFar));
}

void WinGLES::PointParameterf(
    GLenum pname,
    GLfloat param)
{
    CALL(PointParameterf, (pname, param));
}

void WinGLES::PointParameterfv(
    GLenum pname,
    const GLfloat *params)
{
    CALL(PointParameterfv, (pname, params));
}

void WinGLES::PointSize(GLfloat size)
{
    CALL(PointSize, (size));
}

void WinGLES::PolygonOffset(
    GLfloat factor,
    GLfloat units)
{
    CALL(PolygonOffset, (factor, units));
}

void WinGLES::Rotatef(
    GLfloat angle,
    GLfloat x,
    GLfloat y,
    GLfloat z)
{
    CALL(Rotatef, (angle, x, y, z));
}

void WinGLES::Scalef(
    GLfloat x,
    GLfloat y,
    GLfloat z)
{
    CALL(Scalef, (x, y, z));
}

void WinGLES::TexEnvf(
    GLenum target,
    GLenum pname,
    GLfloat param)
{
    CALL(TexEnvf, (target, pname, param));
}

void WinGLES::TexEnvfv(
    GLenum target,
    GLenum pname,
    const GLfloat *params)
{
    CALL(TexEnvfv, (target, pname, params));
}

void WinGLES::TexParameterf(
    GLenum target,
    GLenum pname,
    GLfloat param)
{
    CALL(TexParameterf, (target, pname, param));
}

void WinGLES::TexParameterfv(
    GLenum target,
    GLenum pname,
    const GLfloat *params)
{
    CALL(TexParameterfv, (target, pname, params));
}

void WinGLES::Translatef(
    GLfloat x,
    GLfloat y,
    GLfloat z)
{
    CALL(Translatef, (x, y, z));
}

void WinGLES::ActiveTexture(GLenum texture)
{
    CALL(ActiveTexture, (texture));
}

void WinGLES::BindBuffer(
    GLenum target,
    GLuint buffer)
{
    CALL(BindBuffer, (target, buffer));
}

void WinGLES::BindTexture(
    GLenum target,
    GLuint texture)
{
    CALL(BindTexture, (target, texture));
}

void WinGLES::BlendFunc(
    GLenum sfactor,
    GLenum dfactor)
{
    CALL(BlendFunc, (sfactor, dfactor));
}

void WinGLES::BufferData(
    GLenum target,
    GLsizeiptr size,
    const GLvoid *data,
    GLenum usage)
{
    CALL(BufferData, (target, size, data, usage));
}

void WinGLES::BufferSubData(
    GLenum target,
    GLintptr offset,
    GLsizeiptr size,
    const GLvoid *data)
{
    CALL(BufferSubData, (target, offset, size, data));
}

void WinGLES::Clear(GLbitfield mask)
{
    CALL(Clear, (mask));
}

void WinGLES::ClearStencil(GLint s)
{
    CALL(ClearStencil, (s));
}

void WinGLES::ClientActiveTexture(GLenum texture)
{
    CALL(ClientActiveTexture, (texture));
}

void WinGLES::Color4ub(
    GLubyte red,
    GLubyte green,
    GLubyte blue,
    GLubyte alpha)
{
    CALL(Color4ub, (red, green, blue, alpha));
}

void WinGLES::ColorMask(
    GLboolean red,
    GLboolean green,
    GLboolean blue,
    GLboolean alpha)
{
    CALL(ColorMask, (red, green, blue, alpha));
}

void WinGLES::ColorPointer(
    GLint size,
    GLenum type,
    GLsizei stride,
    const GLvoid *pointer)
{
    CALL(ColorPointer, (size, type, stride, pointer));
}

void WinGLES::CompressedTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLsizei imageSize,
    const GLvoid *data)
{
    CALL(CompressedTexImage2D, (
        target, level, internalformat, width, height, border, imageSize, data));
}

void WinGLES::CompressedTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLsizei imageSize,
    const GLvoid *data)
{
    CALL(CompressedTexSubImage2D, (
        target, level, xoffset, yoffset, width, height, format, imageSize, data));
}

void WinGLES::CopyTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLint border)
{
    CALL(CopyTexImage2D, (
        target, level, internalformat, x, y, width, height, border));
}

void WinGLES::CopyTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height)
{
    CALL(CopyTexSubImage2D, (
        target, level, xoffset, yoffset, x, y, width, height));
}

void WinGLES::CullFace(GLenum mode)
{
    CALL(CullFace, (mode));
}

void WinGLES::DeleteBuffers(
    GLsizei n,
    const GLuint *buffers)
{
    CALL(DeleteBuffers, (n, buffers));
}

void WinGLES::DeleteTextures(
    GLsizei n,
    const GLuint *textures)
{
    CALL(DeleteTextures, (n, textures));
}

void WinGLES::DepthFunc(GLenum func)
{
    CALL(DepthFunc, (func));
}

void WinGLES::DepthMask(GLboolean flag)
{
    CALL(DepthMask, (flag));
}

void WinGLES::Disable(GLenum cap)
{
    CALL(Disable, (cap));
}

void WinGLES::DisableClientState(GLenum array)
{
    CALL(DisableClientState, (array));
}

void WinGLES::DrawArrays(GLenum mode, GLint first, GLsizei count)
{
    CALL(DrawArrays, (mode, first, count));
}

void WinGLES::DrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
    CALL(DrawElements, (mode, count, type, indices));
}

void WinGLES::Enable(GLenum cap)
{
    CALL(Enable, (cap));
}

void WinGLES::EnableClientState(GLenum array)
{
    CALL(EnableClientState, (array));
}

void WinGLES::Finish(void)
{
    CALL(Finish, ());
}

void WinGLES::Flush(void)
{
    CALL(Flush, ());
}

void WinGLES::FrontFace(GLenum mode)
{
    CALL(FrontFace, (mode));
}

void WinGLES::GetBooleanv(GLenum pname, GLboolean *params)
{
    CALL(GetBooleanv, (pname, params));
}

void WinGLES::GetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
    CALL(GetBufferParameteriv, (target, pname, params));
}

void WinGLES::GenBuffers(GLsizei n, GLuint *buffers)
{
    CALL(GenBuffers, (n, buffers));
}

void WinGLES::GenTextures(GLsizei n, GLuint *textures)
{
    CALL(GenTextures, (n, textures));
}

GLenum WinGLES::GetError(void)
{
    return CALL(GetError, ());
}

void WinGLES::GetIntegerv(GLenum pname, GLint *params)
{
    CALL(GetIntegerv, (pname, params));
}

void WinGLES::GetPointerv(GLenum pname, GLvoid **params)
{
    CALL(GetPointerv, (pname, params));
}

const GLubyte * WinGLES::GetString(GLenum name)
{
    return CALL(GetString, (name));
}

void WinGLES::GetTexEnviv(GLenum env, GLenum pname, GLint *params)
{
    CALL(GetTexEnviv, (env, pname, params));
}

void WinGLES::GetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
    CALL(GetTexParameteriv, (target, pname, params));
}

void WinGLES::Hint(GLenum target, GLenum mode)
{
    CALL(Hint, (target, mode));
}

GLboolean WinGLES::IsBuffer(GLuint buffer)
{
    return CALL(IsBuffer, (buffer));
}

GLboolean WinGLES::IsEnabled(GLenum cap)
{
    return CALL(IsEnabled, (cap));
}

GLboolean WinGLES::IsTexture(GLuint texture)
{
    return CALL(IsTexture, (texture));
}

void WinGLES::LoadIdentity(void)
{
    CALL(LoadIdentity, ());
}

void WinGLES::LogicOp(GLenum opcode)
{
    CALL(LogicOp, (opcode));
}

void WinGLES::MatrixMode(GLenum mode)
{
    CALL(MatrixMode, (mode));
}

void WinGLES::NormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
    CALL(NormalPointer, (type, stride, pointer));
}

void WinGLES::PixelStorei(GLenum pname, GLint param)
{
    CALL(PixelStorei, (pname, param));
}

void WinGLES::PopMatrix(void)
{
    CALL(PopMatrix, ());
}

void WinGLES::PushMatrix(void)
{
    CALL(PushMatrix, ());
}

void WinGLES::ReadPixels(
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    GLvoid *pixels)
{
    CALL(ReadPixels, (x, y, width, height, format, type, pixels));
}

void WinGLES::SampleCoverage(GLclampf value, GLboolean invert)
{
    CALL(SampleCoverage, (value, invert));
}

void WinGLES::Scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    CALL(Scissor, (x, y, width, height));
}

void WinGLES::ShadeModel(GLenum mode)
{
    CALL(ShadeModel, (mode));
}

void WinGLES::StencilFunc(GLenum func, GLint ref, GLuint mask)
{
    CALL(StencilFunc, (func, ref, mask));
}

void WinGLES::StencilMask(GLuint mask)
{
    CALL(StencilMask, (mask));
}

void WinGLES::StencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    CALL(StencilOp, (fail, zfail, zpass));
}

void WinGLES::TexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    CALL(TexCoordPointer, (size, type, stride, pointer));
}

void WinGLES::TexEnvi(GLenum target, GLenum pname, GLint param)
{
    CALL(TexEnvi, (target, pname, param));
}

void WinGLES::TexEnviv(GLenum target, GLenum pname, const GLint *params)
{
    CALL(TexEnviv, (target, pname, params));
}

void WinGLES::TexImage2D(
    GLenum target,
    GLint level,
    GLint internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLenum format,
    GLenum type,
    const GLvoid *pixels)
{
    CALL(TexImage2D, (target, level, internalformat, width, height, border, format, type, pixels));
}

void WinGLES::TexParameteri(GLenum target, GLenum pname, GLint param)
{
    CALL(TexParameteri, (target, pname, param));
}

void WinGLES::TexParameteriv(GLenum target, GLenum pname, const GLint *params)
{
    CALL(TexParameteriv, (target, pname, params));
}

void WinGLES::TexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    const GLvoid *pixels)
{
    CALL(TexSubImage2D, (target, level, xoffset, yoffset, width, height, format, type, pixels));
}

void WinGLES::VertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    CALL(VertexPointer, (size, type, stride, pointer));
}

void WinGLES::Viewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    CALL(Viewport, (x, y, width, height));
}

}
