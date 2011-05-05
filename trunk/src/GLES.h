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

#ifndef CRATERIS_GLES_H_INCLUDED_
#define CRATERIS_GLES_H_INCLUDED_

#include <GLES/gl.h>

namespace crateris {

class GLES
{
public:

    virtual void AlphaFunc(GLenum func, GLclampf ref);
    virtual void ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    virtual void ClearDepthf(GLclampf depth);
    virtual void ClipPlanef(GLenum plane, const GLfloat *equation);
    virtual void Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    virtual void DepthRangef(GLclampf zNear, GLclampf zFar);
    virtual void Fogf(GLenum pname, GLfloat param);
    virtual void Fogfv(GLenum pname, const GLfloat *params);
    virtual void Frustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
    virtual void GetClipPlanef(GLenum pname, GLfloat eqn[4]);
    virtual void GetFloatv(GLenum pname, GLfloat *params);
    virtual void GetLightfv(GLenum light, GLenum pname, GLfloat *params);
    virtual void GetMaterialfv(GLenum face, GLenum pname, GLfloat *params);
    virtual void GetTexEnvfv(GLenum env, GLenum pname, GLfloat *params);
    virtual void GetTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
    virtual void LightModelf(GLenum pname, GLfloat param);
    virtual void LightModelfv(GLenum pname, const GLfloat *params);
    virtual void Lightf(GLenum light, GLenum pname, GLfloat param);
    virtual void Lightfv(GLenum light, GLenum pname, const GLfloat *params);
    virtual void LineWidth(GLfloat width);
    virtual void LoadMatrixf(const GLfloat *m);
    virtual void Materialf(GLenum face, GLenum pname, GLfloat param);
    virtual void Materialfv(GLenum face, GLenum pname, const GLfloat *params);
    virtual void MultMatrixf(const GLfloat *m);
    virtual void MultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
    virtual void Normal3f(GLfloat nx, GLfloat ny, GLfloat nz);
    virtual void Orthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
    virtual void PointParameterf(GLenum pname, GLfloat param);
    virtual void PointParameterfv(GLenum pname, const GLfloat *params);
    virtual void PointSize(GLfloat size);
    virtual void PolygonOffset(GLfloat factor, GLfloat units);
    virtual void Rotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
    virtual void Scalef(GLfloat x, GLfloat y, GLfloat z);
    virtual void TexEnvf(GLenum target, GLenum pname, GLfloat param);
    virtual void TexEnvfv(GLenum target, GLenum pname, const GLfloat *params);
    virtual void TexParameterf(GLenum target, GLenum pname, GLfloat param);
    virtual void TexParameterfv(GLenum target, GLenum pname, const GLfloat *params);
    virtual void Translatef(GLfloat x, GLfloat y, GLfloat z);
    virtual void ActiveTexture(GLenum texture);
    virtual void BindBuffer(GLenum target, GLuint buffer);
    virtual void BindTexture(GLenum target, GLuint texture);
    virtual void BlendFunc(GLenum sfactor, GLenum dfactor);
    virtual void BufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
    virtual void BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
    virtual void Clear(GLbitfield mask);
    virtual void ClearStencil(GLint s);
    virtual void ClientActiveTexture(GLenum texture);
    virtual void Color4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
    virtual void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    virtual void ColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
    virtual void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
    virtual void CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
    virtual void CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    virtual void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    virtual void CullFace(GLenum mode);
    virtual void DeleteBuffers(GLsizei n, const GLuint *buffers);
    virtual void DeleteTextures(GLsizei n, const GLuint *textures);
    virtual void DepthFunc(GLenum func);
    virtual void DepthMask(GLboolean flag);
    virtual void Disable(GLenum cap);
    virtual void DisableClientState(GLenum array);
    virtual void DrawArrays(GLenum mode, GLint first, GLsizei count);
    virtual void DrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
    virtual void Enable(GLenum cap);
    virtual void EnableClientState(GLenum array);
    virtual void Finish(void);
    virtual void Flush(void);
    virtual void FrontFace(GLenum mode);
    virtual void GetBooleanv(GLenum pname, GLboolean *params);
    virtual void GetBufferParameteriv(GLenum target, GLenum pname, GLint *params);
    virtual void GenBuffers(GLsizei n, GLuint *buffers);
    virtual void GenTextures(GLsizei n, GLuint *textures);
    virtual GLenum GetError(void);
    virtual void GetIntegerv(GLenum pname, GLint *params);
    virtual void GetPointerv(GLenum pname, GLvoid **params);
    virtual const GLubyte * GetString(GLenum name);
    virtual void GetTexEnviv(GLenum env, GLenum pname, GLint *params);
    virtual void GetTexParameteriv(GLenum target, GLenum pname, GLint *params);
    virtual void Hint(GLenum target, GLenum mode);
    virtual GLboolean IsBuffer(GLuint buffer);
    virtual GLboolean IsEnabled(GLenum cap);
    virtual GLboolean IsTexture(GLuint texture);
    virtual void LoadIdentity(void);
    virtual void LogicOp(GLenum opcode);
    virtual void MatrixMode(GLenum mode);
    virtual void NormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
    virtual void PixelStorei(GLenum pname, GLint param);
    virtual void PopMatrix(void);
    virtual void PushMatrix(void);
    virtual void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
    virtual void SampleCoverage(GLclampf value, GLboolean invert);
    virtual void Scissor(GLint x, GLint y, GLsizei width, GLsizei height);
    virtual void ShadeModel(GLenum mode);
    virtual void StencilFunc(GLenum func, GLint ref, GLuint mask);
    virtual void StencilMask(GLuint mask);
    virtual void StencilOp(GLenum fail, GLenum zfail, GLenum zpass);
    virtual void TexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
    virtual void TexEnvi(GLenum target, GLenum pname, GLint param);
    virtual void TexEnviv(GLenum target, GLenum pname, const GLint *params);
    virtual void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
    virtual void TexParameteri(GLenum target, GLenum pname, GLint param);
    virtual void TexParameteriv(GLenum target, GLenum pname, const GLint *params);
    virtual void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
    virtual void VertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
    virtual void Viewport(GLint x, GLint y, GLsizei width, GLsizei height);


    virtual void AlphaFuncx(GLenum func, GLclampx ref);
    virtual void ClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
    virtual void ClearDepthx(GLclampx depth);
    virtual void ClipPlanex(GLenum plane, const GLfixed *equation);
    virtual void Color4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
    virtual void DepthRangex(GLclampx zNear, GLclampx zFar);
    virtual void Fogx(GLenum pname, GLfixed param);
    virtual void Fogxv(GLenum pname, const GLfixed *params);
    virtual void Frustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
    virtual void GetClipPlanex(GLenum pname, GLfixed eqn[4]);
    virtual void GetFixedv(GLenum pname, GLfixed *params);
    virtual void GetLightxv(GLenum light, GLenum pname, GLfixed *params);
    virtual void GetMaterialxv(GLenum face, GLenum pname, GLfixed *params);
    virtual void GetTexEnvxv(GLenum env, GLenum pname, GLfixed *params);
    virtual void GetTexParameterxv(GLenum target, GLenum pname, GLfixed *params);
    virtual void LightModelx(GLenum pname, GLfixed param);
    virtual void LightModelxv(GLenum pname, const GLfixed *params);
    virtual void Lightx(GLenum light, GLenum pname, GLfixed param);
    virtual void Lightxv(GLenum light, GLenum pname, const GLfixed *params);
    virtual void LineWidthx(GLfixed width);
    virtual void LoadMatrixx(const GLfixed *m);
    virtual void Materialx(GLenum face, GLenum pname, GLfixed param);
    virtual void Materialxv(GLenum face, GLenum pname, const GLfixed *params);
    virtual void MultMatrixx(const GLfixed *m);
    virtual void MultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
    virtual void Normal3x(GLfixed nx, GLfixed ny, GLfixed nz);
    virtual void Orthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
    virtual void PointParameterx(GLenum pname, GLfixed param);
    virtual void PointParameterxv(GLenum pname, const GLfixed *params);
    virtual void PointSizex(GLfixed size);
    virtual void PolygonOffsetx(GLfixed factor, GLfixed units);
    virtual void Rotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
    virtual void SampleCoveragex(GLclampx value, GLboolean invert);
    virtual void Scalex(GLfixed x, GLfixed y, GLfixed z);
    virtual void TexEnvx(GLenum target, GLenum pname, GLfixed param);
    virtual void TexEnvxv(GLenum target, GLenum pname, const GLfixed *params);
    virtual void TexParameterx(GLenum target, GLenum pname, GLfixed param);
    virtual void TexParameterxv(GLenum target, GLenum pname, const GLfixed *params);
    virtual void Translatex(GLfixed x, GLfixed y, GLfixed z);

protected:
    GLES();
    virtual ~GLES() = 0;
};

}

#endif
