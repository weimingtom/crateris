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

#include "GLES.h"

namespace crateris {

#define NO_IMPL()

GLES::GLES()
{
}

GLES::~GLES()
{
}

void GLES::AlphaFunc(
    GLenum func,
    GLclampf ref)
{
    (void)func;
    (void)ref;
    NO_IMPL();
}

void GLES::ClearColor(
    GLclampf red,
    GLclampf green,
    GLclampf blue,
    GLclampf alpha)
{
    (void)red;
    (void)green;
    (void)blue;
    (void)alpha;
    NO_IMPL();
}

void GLES::ClearDepthf(GLclampf depth)
{
    (void)depth;
    NO_IMPL();
}

void GLES::ClipPlanef(
    GLenum plane,
    const GLfloat *equation)
{
    (void)plane;
    (void)equation;
    NO_IMPL();
}

void GLES::Color4f(
    GLfloat red,
    GLfloat green,
    GLfloat blue,
    GLfloat alpha)
{
    (void)red;
    (void)green;
    (void)blue;
    (void)alpha;
    NO_IMPL();
}

void GLES::DepthRangef(
    GLclampf zNear,
    GLclampf zFar)
{
    (void)zNear;
    (void)zFar;
    NO_IMPL();
}

void GLES::Fogf(
    GLenum pname,
    GLfloat param)
{
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::Fogfv(
    GLenum pname,
    const GLfloat *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::Frustumf(
    GLfloat left,
    GLfloat right,
    GLfloat bottom,
    GLfloat top,
    GLfloat zNear,
    GLfloat zFar)
{
    (void)left;
    (void)right;
    (void)bottom;
    (void)top;
    (void)zNear;
    (void)zFar;
    NO_IMPL();
}

void GLES::GetClipPlanef(
    GLenum pname,
    GLfloat eqn[4])
{
    (void)pname;
    (void)eqn;
    NO_IMPL();
}

void GLES::GetFloatv(
    GLenum pname,
    GLfloat *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetLightfv(
    GLenum light,
    GLenum pname,
    GLfloat *params)
{
    (void)light;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetMaterialfv(
    GLenum face,
    GLenum pname,
    GLfloat *params)
{
    (void)face;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetTexEnvfv(
    GLenum env,
    GLenum pname,
    GLfloat *params)
{
    (void)env;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetTexParameterfv(
    GLenum target,
    GLenum pname,
    GLfloat *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::LightModelf(
    GLenum pname,
    GLfloat param)
{
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::LightModelfv(
    GLenum pname,
    const GLfloat *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::Lightf(
    GLenum light,
    GLenum pname,
    GLfloat param)
{
    (void)light;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::Lightfv(
    GLenum light,
    GLenum pname,
    const GLfloat *params)
{
    (void)light;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::LineWidth(GLfloat width)
{
    (void)width;
    NO_IMPL();
}

void GLES::LoadMatrixf(const GLfloat *m)
{
    (void)m;
    NO_IMPL();
}

void GLES::Materialf(
    GLenum face,
    GLenum pname,
    GLfloat param)
{
    (void)face;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::Materialfv(
    GLenum face,
    GLenum pname,
    const GLfloat *params)
{
    (void)face;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::MultMatrixf(const GLfloat *m)
{
    (void)m;
    NO_IMPL();
}

void GLES::MultiTexCoord4f(
    GLenum target,
    GLfloat s,
    GLfloat t,
    GLfloat r,
    GLfloat q)
{
    (void)target;
    (void)s;
    (void)t;
    (void)r;
    (void)q;
    NO_IMPL();
}

void GLES::Normal3f(
    GLfloat nx,
    GLfloat ny,
    GLfloat nz)
{
    (void)nx;
    (void)ny;
    (void)nz;
    NO_IMPL();
}

void GLES::Orthof(
    GLfloat left,
    GLfloat right,
    GLfloat bottom,
    GLfloat top,
    GLfloat zNear,
    GLfloat zFar)
{
    (void)left;
    (void)right;
    (void)bottom;
    (void)top;
    (void)zNear;
    (void)zFar;
    NO_IMPL();
}

void GLES::PointParameterf(
    GLenum pname,
    GLfloat param)
{
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::PointParameterfv(
    GLenum pname,
    const GLfloat *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::PointSize(GLfloat size)
{
    (void)size;
    NO_IMPL();
}

void GLES::PolygonOffset(
    GLfloat factor,
    GLfloat units)
{
    (void)factor;
    (void)units;
    NO_IMPL();
}

void GLES::Rotatef(
    GLfloat angle,
    GLfloat x,
    GLfloat y,
    GLfloat z)
{
    (void)angle;
    (void)x;
    (void)y;
    (void)z;
    NO_IMPL();
}

void GLES::Scalef(
    GLfloat x,
    GLfloat y,
    GLfloat z)
{
    (void)x;
    (void)y;
    (void)z;
    NO_IMPL();
}

void GLES::TexEnvf(
    GLenum target,
    GLenum pname,
    GLfloat param)
{
    (void)target;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::TexEnvfv(
    GLenum target,
    GLenum pname,
    const GLfloat *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::TexParameterf(
    GLenum target,
    GLenum pname,
    GLfloat param)
{
    (void)target;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::TexParameterfv(
    GLenum target,
    GLenum pname,
    const GLfloat *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::Translatef(
    GLfloat x,
    GLfloat y,
    GLfloat z)
{
    (void)x;
    (void)y;
    (void)z;
    NO_IMPL();
}

void GLES::ActiveTexture(GLenum texture)
{
    (void)texture;
    NO_IMPL();
}

void GLES::BindBuffer(
    GLenum target,
    GLuint buffer)
{
    (void)target;
    (void)buffer;
    NO_IMPL();
}

void GLES::BindTexture(
    GLenum target,
    GLuint texture)
{
    (void)target;
    (void)texture;
    NO_IMPL();
}

void GLES::BlendFunc(
    GLenum sfactor,
    GLenum dfactor)
{
    (void)sfactor;
    (void)dfactor;
    NO_IMPL();
}

void GLES::BufferData(
    GLenum target,
    GLsizeiptr size,
    const GLvoid *data,
    GLenum usage)
{
    (void)target;
    (void)size;
    (void)data;
    (void)usage;
    NO_IMPL();
}

void GLES::BufferSubData(
    GLenum target,
    GLintptr offset,
    GLsizeiptr size,
    const GLvoid *data)
{
    (void)target;
    (void)offset;
    (void)size;
    (void)data;
    NO_IMPL();
}

void GLES::Clear(GLbitfield mask)
{
    (void)mask;
    NO_IMPL();
}

void GLES::ClearStencil(GLint s)
{
    (void)s;
    NO_IMPL();
}

void GLES::ClientActiveTexture(GLenum texture)
{
    (void)texture;
    NO_IMPL();
}

void GLES::Color4ub(
    GLubyte red,
    GLubyte green,
    GLubyte blue,
    GLubyte alpha)
{
    (void)red;
    (void)green;
    (void)blue;
    (void)alpha;
    NO_IMPL();
}

void GLES::ColorMask(
    GLboolean red,
    GLboolean green,
    GLboolean blue,
    GLboolean alpha)
{
    (void)red;
    (void)green;
    (void)blue;
    (void)alpha;
    NO_IMPL();
}

void GLES::ColorPointer(
    GLint size,
    GLenum type,
    GLsizei stride,
    const GLvoid *pointer)
{
    (void)size;
    (void)type;
    (void)stride;
    (void)pointer;
    NO_IMPL();
}

void GLES::CompressedTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLsizei imageSize,
    const GLvoid *data)
{
    (void)target;
    (void)level;
    (void)internalformat;
    (void)width;
    (void)height;
    (void)border;
    (void)imageSize;
    (void)data;
    NO_IMPL();
}

void GLES::CompressedTexSubImage2D(
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
    (void)target;
    (void)level;
    (void)xoffset;
    (void)yoffset;
    (void)width;
    (void)height;
    (void)format;
    (void)imageSize;
    (void)data;
    NO_IMPL();
}

void GLES::CopyTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLint border)
{
    (void)target;
    (void)level;
    (void)internalformat;
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    (void)border;
    NO_IMPL();
}

void GLES::CopyTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height)
{
    (void)target;
    (void)level;
    (void)xoffset;
    (void)yoffset;
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    NO_IMPL();
}

void GLES::CullFace(GLenum mode)
{
    (void)mode;
    NO_IMPL();
}

void GLES::DeleteBuffers(
    GLsizei n,
    const GLuint *buffers)
{
    (void)n;
    (void)buffers;
    NO_IMPL();
}

void GLES::DeleteTextures(
    GLsizei n,
    const GLuint *textures)
{
    (void)n;
    (void)textures;
    NO_IMPL();
}

void GLES::DepthFunc(GLenum func)
{
    (void)func;
    NO_IMPL();
}

void GLES::DepthMask(GLboolean flag)
{
    (void)flag;
    NO_IMPL();
}

void GLES::Disable(GLenum cap)
{
    (void)cap;
    NO_IMPL();
}

void GLES::DisableClientState(GLenum array)
{
    (void)array;
    NO_IMPL();
}

void GLES::DrawArrays(GLenum mode, GLint first, GLsizei count)
{
    (void)mode;
    (void)first;
    (void)count;
    NO_IMPL();
}

void GLES::DrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
    (void)mode;
    (void)count;
    (void)type;
    (void)indices;
    NO_IMPL();
}

void GLES::Enable(GLenum cap)
{
    (void)cap;
    NO_IMPL();
}

void GLES::EnableClientState(GLenum array)
{
    (void)array;
    NO_IMPL();
}

void GLES::Finish(void)
{
    NO_IMPL();
}

void GLES::Flush(void)
{
    NO_IMPL();
}

void GLES::FrontFace(GLenum mode)
{
    (void)mode;
    NO_IMPL();
}

void GLES::GetBooleanv(GLenum pname, GLboolean *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GenBuffers(GLsizei n, GLuint *buffers)
{
    (void)n;
    (void)buffers;
    NO_IMPL();
}

void GLES::GenTextures(GLsizei n, GLuint *textures)
{
    (void)n;
    (void)textures;
    NO_IMPL();
}

GLenum GLES::GetError(void)
{
    NO_IMPL();
    return GL_INVALID_OPERATION;
}

void GLES::GetIntegerv(GLenum pname, GLint *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetPointerv(GLenum pname, GLvoid **params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

const GLubyte * GLES::GetString(GLenum name)
{
    (void)name;
    NO_IMPL();
    return 0;
}

void GLES::GetTexEnviv(GLenum env, GLenum pname, GLint *params)
{
    (void)env;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::Hint(GLenum target, GLenum mode)
{
    (void)target;
    (void)mode;
    NO_IMPL();
}

GLboolean GLES::IsBuffer(GLuint buffer)
{
    (void)buffer;
    NO_IMPL();
    return GL_FALSE;
}

GLboolean GLES::IsEnabled(GLenum cap)
{
    (void)cap;
    NO_IMPL();
    return GL_FALSE;
}

GLboolean GLES::IsTexture(GLuint texture)
{
    (void)texture;
    NO_IMPL();
    return GL_FALSE;
}

void GLES::LoadIdentity(void)
{
    NO_IMPL();
}

void GLES::LogicOp(GLenum opcode)
{
    (void)opcode;
    NO_IMPL();
}

void GLES::MatrixMode(GLenum mode)
{
    (void)mode;
    NO_IMPL();
}

void GLES::NormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
    (void)type;
    (void)stride;
    (void)pointer;
    NO_IMPL();
}

void GLES::PixelStorei(GLenum pname, GLint param)
{
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::PopMatrix(void)
{
    NO_IMPL();
}

void GLES::PushMatrix(void)
{
    NO_IMPL();
}

void GLES::ReadPixels(
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    GLvoid *pixels)
{
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    (void)format;
    (void)type;
    (void)pixels;
    NO_IMPL();
}

void GLES::SampleCoverage(GLclampf value, GLboolean invert)
{
    (void)value;
    (void)invert;
    NO_IMPL();
}

void GLES::Scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    NO_IMPL();
}

void GLES::ShadeModel(GLenum mode)
{
    (void)mode;
    NO_IMPL();
}

void GLES::StencilFunc(GLenum func, GLint ref, GLuint mask)
{
    (void)func;
    (void)ref;
    (void)mask;
    NO_IMPL();
}

void GLES::StencilMask(GLuint mask)
{
    (void)mask;
    NO_IMPL();
}

void GLES::StencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    (void)fail;
    (void)zfail;
    (void)zpass;
    NO_IMPL();
}

void GLES::TexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    (void)size;
    (void)type;
    (void)stride;
    (void)pointer;
    NO_IMPL();
}

void GLES::TexEnvi(GLenum target, GLenum pname, GLint param)
{
    (void)target;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::TexEnviv(GLenum target, GLenum pname, const GLint *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::TexImage2D(
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
    (void)target;
    (void)level;
    (void)internalformat;
    (void)width;
    (void)height;
    (void)border;
    (void)format;
    (void)type;
    (void)pixels;
    NO_IMPL();
}

void GLES::TexParameteri(GLenum target, GLenum pname, GLint param)
{
    (void)target;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::TexParameteriv(GLenum target, GLenum pname, const GLint *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::TexSubImage2D(
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
    (void)target;
    (void)level;
    (void)xoffset;
    (void)yoffset;
    (void)width;
    (void)height;
    (void)format;
    (void)type;
    (void)pixels;
    NO_IMPL();
}

void GLES::VertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    (void)size;
    (void)type;
    (void)stride;
    (void)pointer;
    NO_IMPL();
}

void GLES::Viewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    NO_IMPL();
}



/*********************************************************/
/* Fixed API                                             */
/*********************************************************/

void GLES::AlphaFuncx(
    GLenum func,
    GLclampx ref)
{
    (void)func;
    (void)ref;
    NO_IMPL();
}

void GLES::ClearColorx(
    GLclampx red,
    GLclampx green,
    GLclampx blue,
    GLclampx alpha)
{
    (void)red;
    (void)green;
    (void)blue;
    (void)alpha;
    NO_IMPL();
}

void GLES::ClearDepthx(GLclampx depth)
{
    (void)depth;
    NO_IMPL();
}

void GLES::ClipPlanex(
    GLenum plane,
    const GLfixed *equation)
{
    (void)plane;
    (void)equation;
    NO_IMPL();
}

void GLES::Color4x(
    GLfixed red,
    GLfixed green,
    GLfixed blue,
    GLfixed alpha)
{
    (void)red;
    (void)green;
    (void)blue;
    (void)alpha;
    NO_IMPL();
}

void GLES::DepthRangex(GLclampx zNear, GLclampx zFar)
{
    (void)zNear;
    (void)zFar;
    NO_IMPL();
}

void GLES::Fogx(GLenum pname, GLfixed param)
{
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::Fogxv(GLenum pname, const GLfixed *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::Frustumx(
    GLfixed left,
    GLfixed right,
    GLfixed bottom,
    GLfixed top,
    GLfixed zNear,
    GLfixed zFar)
{
    (void)left;
    (void)right;
    (void)bottom;
    (void)top;
    (void)zNear;
    (void)zFar;
    NO_IMPL();
}

void GLES::GetClipPlanex(GLenum pname, GLfixed eqn[4])
{
    (void)pname;
    (void)eqn;
    NO_IMPL();
}

void GLES::GetFixedv(GLenum pname, GLfixed *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetLightxv(GLenum light, GLenum pname, GLfixed *params)
{
    (void)light;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetMaterialxv(GLenum face, GLenum pname, GLfixed *params)
{
    (void)face;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetTexEnvxv(GLenum env, GLenum pname, GLfixed *params)
{
    (void)env;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::GetTexParameterxv(GLenum target, GLenum pname, GLfixed *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::LightModelx(GLenum pname, GLfixed param)
{
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::LightModelxv(GLenum pname, const GLfixed *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::Lightx(GLenum light, GLenum pname, GLfixed param)
{
    (void)light;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::Lightxv(GLenum light, GLenum pname, const GLfixed *params)
{
    (void)light;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::LineWidthx(GLfixed width)
{
    (void)width;
    NO_IMPL();
}

void GLES::LoadMatrixx(const GLfixed *m)
{
    (void)m;
    NO_IMPL();
}

void GLES::Materialx(GLenum face, GLenum pname, GLfixed param)
{
    (void)face;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::Materialxv(GLenum face, GLenum pname, const GLfixed *params)
{
    (void)face;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::MultMatrixx(const GLfixed *m)
{
    (void)m;
    NO_IMPL();
}

void GLES::MultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q)
{
    (void)target;
    (void)s;
    (void)t;
    (void)r;
    (void)q;
    NO_IMPL();
}

void GLES::Normal3x(GLfixed nx, GLfixed ny, GLfixed nz)
{
    (void)nx;
    (void)ny;
    (void)nz;
    NO_IMPL();
}

void GLES::Orthox(
    GLfixed left,
    GLfixed right,
    GLfixed bottom,
    GLfixed top,
    GLfixed zNear,
    GLfixed zFar)
{
    (void)left;
    (void)right;
    (void)bottom;
    (void)top;
    (void)zNear;
    (void)zFar;
    NO_IMPL();
}

void GLES::PointParameterx(GLenum pname, GLfixed param)
{
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::PointParameterxv(GLenum pname, const GLfixed *params)
{
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::PointSizex(GLfixed size)
{
    (void)size;
    NO_IMPL();
}

void GLES::PolygonOffsetx(GLfixed factor, GLfixed units)
{
    (void)factor;
    (void)units;
    NO_IMPL();
}

void GLES::Rotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z)
{
    (void)angle;
    (void)x;
    (void)y;
    (void)z;
    NO_IMPL();
}

void GLES::SampleCoveragex(GLclampx value, GLboolean invert)
{
    (void)value;
    (void)invert;
    NO_IMPL();
}

void GLES::Scalex(GLfixed x, GLfixed y, GLfixed z)
{
    (void)x;
    (void)y;
    (void)z;
    NO_IMPL();
}

void GLES::TexEnvx(GLenum target, GLenum pname, GLfixed param)
{
    (void)target;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::TexEnvxv(GLenum target, GLenum pname, const GLfixed *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::TexParameterx(GLenum target, GLenum pname, GLfixed param)
{
    (void)target;
    (void)pname;
    (void)param;
    NO_IMPL();
}

void GLES::TexParameterxv(GLenum target, GLenum pname, const GLfixed *params)
{
    (void)target;
    (void)pname;
    (void)params;
    NO_IMPL();
}

void GLES::Translatex(GLfixed x, GLfixed y, GLfixed z)
{
    (void)x;
    (void)y;
    (void)z;
    NO_IMPL();
}

}
