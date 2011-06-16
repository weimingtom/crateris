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

#define GL_API extern "C" __declspec(dllexport)
#define GL_APIENTRY __stdcall
#include "EGL.h"
#include "GLES.h"

#define InitAPI()   \
    crateris::GLES* gl = crateris_get_EGL()->getGLES()

GL_API void GL_APIENTRY glAlphaFunc(GLenum func, GLclampf ref)
{
    InitAPI();
    gl->AlphaFunc(func, ref);
}

GL_API void GL_APIENTRY glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    InitAPI();
    gl->ClearColor(red, green, blue, alpha);
}

GL_API void GL_APIENTRY glClearDepthf (GLclampf depth)
{
    InitAPI();
    gl->ClearDepthf(depth);
}

GL_API void GL_APIENTRY glClipPlanef (GLenum plane, const GLfloat *equation)
{
    InitAPI();
    gl->ClipPlanef(plane, equation);
}

GL_API void GL_APIENTRY glColor4f (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    InitAPI();
    gl->Color4f(red, green, blue, alpha);
}

GL_API void GL_APIENTRY glDepthRangef (GLclampf zNear, GLclampf zFar)
{
    InitAPI();
    gl->DepthRangef(zNear, zFar);
}

GL_API void GL_APIENTRY glFogf (GLenum pname, GLfloat param)
{
    InitAPI();
    gl->Fogf(pname, param);
}

GL_API void GL_APIENTRY glFogfv (GLenum pname, const GLfloat *params)
{
    InitAPI();
    gl->Fogfv(pname, params);
}

GL_API void GL_APIENTRY glFrustumf (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
{
    InitAPI();
    gl->Frustumf(left, right, bottom, top, zNear, zFar);
}

GL_API void GL_APIENTRY glGetClipPlanef (GLenum pname, GLfloat eqn[4])
{
    InitAPI();
    gl->GetClipPlanef(pname, eqn);
}

GL_API void GL_APIENTRY glGetFloatv (GLenum pname, GLfloat *params)
{
    InitAPI();
    gl->GetFloatv(pname, params);
}

GL_API void GL_APIENTRY glGetLightfv (GLenum light, GLenum pname, GLfloat *params)
{
    InitAPI();
    gl->GetLightfv(light, pname, params);
}

GL_API void GL_APIENTRY glGetMaterialfv (GLenum face, GLenum pname, GLfloat *params)
{
    InitAPI();
    gl->GetMaterialfv(face, pname, params);
}

GL_API void GL_APIENTRY glGetTexEnvfv (GLenum env, GLenum pname, GLfloat *params)
{
    InitAPI();
    gl->GetTexEnvfv(env, pname, params);
}

GL_API void GL_APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params)
{
    InitAPI();
    gl->GetTexParameterfv(target, pname, params);
}

GL_API void GL_APIENTRY glLightModelf (GLenum pname, GLfloat param)
{
    InitAPI();
    gl->LightModelf(pname, param);
}

GL_API void GL_APIENTRY glLightModelfv (GLenum pname, const GLfloat *params)
{
    InitAPI();
    gl->LightModelfv(pname, params);
}

GL_API void GL_APIENTRY glLightf (GLenum light, GLenum pname, GLfloat param)
{
    InitAPI();
    gl->Lightf(light, pname, param);
}

GL_API void GL_APIENTRY glLightfv (GLenum light, GLenum pname, const GLfloat *params)
{
    InitAPI();
    gl->Lightfv(light, pname, params);
}

GL_API void GL_APIENTRY glLineWidth (GLfloat width)
{
    InitAPI();
    gl->LineWidth(width);
}

GL_API void GL_APIENTRY glLoadMatrixf (const GLfloat *m)
{
    InitAPI();
    gl->LoadMatrixf(m);
}

GL_API void GL_APIENTRY glMaterialf (GLenum face, GLenum pname, GLfloat param)
{
    InitAPI();
    gl->Materialf(face, pname, param);
}

GL_API void GL_APIENTRY glMaterialfv (GLenum face, GLenum pname, const GLfloat *params)
{
    InitAPI();
    gl->Materialfv(face, pname, params);
}

GL_API void GL_APIENTRY glMultMatrixf (const GLfloat *m)
{
    InitAPI();
    gl->MultMatrixf(m);
}

GL_API void GL_APIENTRY glMultiTexCoord4f (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    InitAPI();
    gl->MultiTexCoord4f(target, s, t, r, q);
}

GL_API void GL_APIENTRY glNormal3f (GLfloat nx, GLfloat ny, GLfloat nz)
{
    InitAPI();
    gl->Normal3f(nx, ny, nz);
}

GL_API void GL_APIENTRY glOrthof (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
{
    InitAPI();
    gl->Orthof(left, right, bottom, top, zNear, zFar);
}

GL_API void GL_APIENTRY glPointParameterf (GLenum pname, GLfloat param)
{
    InitAPI();
    gl->PointParameterf(pname, param);
}

GL_API void GL_APIENTRY glPointParameterfv (GLenum pname, const GLfloat *params)
{
    InitAPI();
    gl->PointParameterfv(pname, params);
}

GL_API void GL_APIENTRY glPointSize (GLfloat size)
{
    InitAPI();
    gl->PointSize(size);
}

GL_API void GL_APIENTRY glPolygonOffset (GLfloat factor, GLfloat units)
{
    InitAPI();
    gl->PolygonOffset(factor, units);
}

GL_API void GL_APIENTRY glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    InitAPI();
    gl->Rotatef(angle, x, y, z);
}

GL_API void GL_APIENTRY glScalef (GLfloat x, GLfloat y, GLfloat z)
{
    InitAPI();
    gl->Scalef(x, y, z);
}

GL_API void GL_APIENTRY glTexEnvf (GLenum target, GLenum pname, GLfloat param)
{
    InitAPI();
    gl->TexEnvf(target, pname, param);
}

GL_API void GL_APIENTRY glTexEnvfv (GLenum target, GLenum pname, const GLfloat *params)
{
    InitAPI();
    gl->TexEnvfv(target, pname, params);
}

GL_API void GL_APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param)
{
    InitAPI();
    gl->TexParameterf(target, pname, param);
}

GL_API void GL_APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params)
{
    InitAPI();
    gl->TexParameterfv(target, pname, params);
}

GL_API void GL_APIENTRY glTranslatef (GLfloat x, GLfloat y, GLfloat z)
{
    InitAPI();
    gl->Translatef(x, y, z);
}

GL_API void GL_APIENTRY glActiveTexture (GLenum texture)
{
    InitAPI();
    gl->ActiveTexture(texture);
}

GL_API void GL_APIENTRY glAlphaFuncx (GLenum func, GLclampx ref)
{
    InitAPI();
    gl->AlphaFuncx(func, ref);
}

GL_API void GL_APIENTRY glBindBuffer (GLenum target, GLuint buffer)
{
    InitAPI();
    gl->BindBuffer(target, buffer);
}

GL_API void GL_APIENTRY glBindTexture (GLenum target, GLuint texture)
{
    InitAPI();
    gl->BindTexture(target, texture);
}

GL_API void GL_APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor)
{
    InitAPI();
    gl->BlendFunc(sfactor, dfactor);
}

GL_API void GL_APIENTRY glBufferData (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
    InitAPI();
    gl->BufferData(target, size, data, usage);
}

GL_API void GL_APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)
{
    InitAPI();
    gl->BufferSubData(target, offset, size, data);
}

GL_API void GL_APIENTRY glClear (GLbitfield mask)
{
    InitAPI();
    gl->Clear(mask);
}

GL_API void GL_APIENTRY glClearColorx (GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha)
{
    InitAPI();
    gl->ClearColorx(red, green, blue, alpha);
}

GL_API void GL_APIENTRY glClearDepthx (GLclampx depth)
{
    InitAPI();
    gl->ClearDepthx(depth);
}

GL_API void GL_APIENTRY glClearStencil (GLint s)
{
    InitAPI();
    gl->ClearStencil(s);
}

GL_API void GL_APIENTRY glClientActiveTexture (GLenum texture)
{
    InitAPI();
    gl->ClientActiveTexture(texture);
}

GL_API void GL_APIENTRY glClipPlanex (GLenum plane, const GLfixed *equation)
{
    InitAPI();
    gl->ClipPlanex(plane, equation);
}

GL_API void GL_APIENTRY glColor4ub (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
    InitAPI();
    gl->Color4ub(red, green, blue, alpha);
}

GL_API void GL_APIENTRY glColor4x (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha)
{
    InitAPI();
    gl->Color4x(red, green, blue, alpha);
}

GL_API void GL_APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    InitAPI();
    gl->ColorMask(red, green, blue, alpha);
}

GL_API void GL_APIENTRY glColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    InitAPI();
    gl->ColorPointer(size, type, stride, pointer);
}

GL_API void GL_APIENTRY glCompressedTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLsizei imageSize,
    const GLvoid *data)
{
    InitAPI();
    gl->CompressedTexImage2D(
        target,
        level,
        internalformat,
        width,
        height,
        border,
        imageSize,
        data);
}

GL_API void GL_APIENTRY glCompressedTexSubImage2D(
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
    InitAPI();
    gl->CompressedTexSubImage2D(
        target,
        level,
        xoffset,
        yoffset,
        width,
        height,
        format,
        imageSize,
        data);
}

GL_API void GL_APIENTRY glCopyTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLint border)
{
    InitAPI();
    gl->CopyTexImage2D(
        target,
        level,
        internalformat,
        x,
        y,
        width,
        height,
        border);
}

GL_API void GL_APIENTRY glCopyTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height)
{
    InitAPI();
    gl->CopyTexSubImage2D(
        target,
        level,
        xoffset,
        yoffset,
        x,
        y,
        width,
        height);
}

GL_API void GL_APIENTRY glCullFace (GLenum mode)
{
    InitAPI();
    gl->CullFace(mode);
}

GL_API void GL_APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers)
{
    InitAPI();
    gl->DeleteBuffers(n, buffers);
}

GL_API void GL_APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures)
{
    InitAPI();
    gl->DeleteTextures(n, textures);
}

GL_API void GL_APIENTRY glDepthFunc (GLenum func)
{
    InitAPI();
    gl->DepthFunc(func);
}

GL_API void GL_APIENTRY glDepthMask (GLboolean flag)
{
    InitAPI();
    gl->DepthMask(flag);
}

GL_API void GL_APIENTRY glDepthRangex (GLclampx zNear, GLclampx zFar)
{
    InitAPI();
    gl->DepthRangex(zNear, zFar);
}

GL_API void GL_APIENTRY glDisable (GLenum cap)
{
    InitAPI();
    gl->Disable(cap);
}

GL_API void GL_APIENTRY glDisableClientState (GLenum array)
{
    InitAPI();
    gl->DisableClientState(array);
}

GL_API void GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
    InitAPI();
    gl->DrawArrays(mode, first, count);
}

GL_API void GL_APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
    InitAPI();
    gl->DrawElements(mode, count, type, indices);
}

GL_API void GL_APIENTRY glEnable (GLenum cap)
{
    InitAPI();
    gl->Enable(cap);
}

GL_API void GL_APIENTRY glEnableClientState (GLenum array)
{
    InitAPI();
    gl->EnableClientState(array);
}

GL_API void GL_APIENTRY glFinish (void)
{
    InitAPI();
    gl->Finish();
}

GL_API void GL_APIENTRY glFlush (void)
{
    InitAPI();
    gl->Flush();
}

GL_API void GL_APIENTRY glFogx (GLenum pname, GLfixed param)
{
    InitAPI();
    gl->Fogx(pname, param);
}

GL_API void GL_APIENTRY glFogxv (GLenum pname, const GLfixed *params)
{
    InitAPI();
    gl->Fogxv(pname, params);
}

GL_API void GL_APIENTRY glFrontFace (GLenum mode)
{
    InitAPI();
    gl->FrontFace(mode);
}

GL_API void GL_APIENTRY glFrustumx (GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar)
{
    InitAPI();
    gl->Frustumx(left, right, bottom, top, zNear, zFar);
}

GL_API void GL_APIENTRY glGetBooleanv (GLenum pname, GLboolean *params)
{
    InitAPI();
    gl->GetBooleanv(pname, params);
}

GL_API void GL_APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
    InitAPI();
    gl->GetBufferParameteriv(target, pname, params);
}

GL_API void GL_APIENTRY glGetClipPlanex (GLenum pname, GLfixed eqn[4])
{
    InitAPI();
    gl->GetClipPlanex(pname, eqn);
}

GL_API void GL_APIENTRY glGenBuffers (GLsizei n, GLuint *buffers)
{
    InitAPI();
    gl->GenBuffers(n, buffers);
}

GL_API void GL_APIENTRY glGenTextures (GLsizei n, GLuint *textures)
{
    InitAPI();
    gl->GenTextures(n, textures);
}

GL_API GLenum GL_APIENTRY glGetError (void)
{
    InitAPI();
    return gl->GetError();
}

GL_API void GL_APIENTRY glGetFixedv (GLenum pname, GLfixed *params)
{
    InitAPI();
    gl->GetFixedv(pname, params);
}

GL_API void GL_APIENTRY glGetIntegerv (GLenum pname, GLint *params)
{
    InitAPI();
    gl->GetIntegerv(pname, params);
}

GL_API void GL_APIENTRY glGetLightxv (GLenum light, GLenum pname, GLfixed *params)
{
    InitAPI();
    gl->GetLightxv(light, pname, params);
}

GL_API void GL_APIENTRY glGetMaterialxv (GLenum face, GLenum pname, GLfixed *params)
{
    InitAPI();
    gl->GetMaterialxv(face, pname, params);
}

GL_API void GL_APIENTRY glGetPointerv (GLenum pname, GLvoid **params)
{
    InitAPI();
    gl->GetPointerv(pname, params);
}

GL_API const GLubyte * GL_APIENTRY glGetString (GLenum name)
{
    InitAPI();
    return gl->GetString(name);
}

GL_API void GL_APIENTRY glGetTexEnviv (GLenum env, GLenum pname, GLint *params)
{
    InitAPI();
    gl->GetTexEnviv(env, pname, params);
}

GL_API void GL_APIENTRY glGetTexEnvxv (GLenum env, GLenum pname, GLfixed *params)
{
    InitAPI();
    gl->GetTexEnvxv(env, pname, params);
}

GL_API void GL_APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint *params)
{
    InitAPI();
    gl->GetTexParameteriv(target, pname, params);
}

GL_API void GL_APIENTRY glGetTexParameterxv (GLenum target, GLenum pname, GLfixed *params)
{
    InitAPI();
    gl->GetTexParameterxv(target, pname, params);
}

GL_API void GL_APIENTRY glHint (GLenum target, GLenum mode)
{
    InitAPI();
    gl->Hint(target, mode);
}

GL_API GLboolean GL_APIENTRY glIsBuffer (GLuint buffer)
{
    InitAPI();
    return gl->IsBuffer(buffer);
}

GL_API GLboolean GL_APIENTRY glIsEnabled (GLenum cap)
{
    InitAPI();
    return gl->IsEnabled(cap);
}

GL_API GLboolean GL_APIENTRY glIsTexture (GLuint texture)
{
    InitAPI();
    return gl->IsTexture(texture);
}

GL_API void GL_APIENTRY glLightModelx (GLenum pname, GLfixed param)
{
    InitAPI();
    gl->LightModelx(pname, param);
}

GL_API void GL_APIENTRY glLightModelxv (GLenum pname, const GLfixed *params)
{
    InitAPI();
    gl->LightModelxv(pname, params);
}

GL_API void GL_APIENTRY glLightx (GLenum light, GLenum pname, GLfixed param)
{
    InitAPI();
    gl->Lightx(light, pname, param);
}

GL_API void GL_APIENTRY glLightxv (GLenum light, GLenum pname, const GLfixed *params)
{
    InitAPI();
    gl->Lightxv(light, pname, params);
}

GL_API void GL_APIENTRY glLineWidthx (GLfixed width)
{
    InitAPI();
    gl->LineWidthx(width);
}

GL_API void GL_APIENTRY glLoadIdentity (void)
{
    InitAPI();
    gl->LoadIdentity();
}

GL_API void GL_APIENTRY glLoadMatrixx (const GLfixed *m)
{
    InitAPI();
    gl->LoadMatrixx(m);
}

GL_API void GL_APIENTRY glLogicOp (GLenum opcode)
{
    InitAPI();
    gl->LogicOp(opcode);
}

GL_API void GL_APIENTRY glMaterialx (GLenum face, GLenum pname, GLfixed param)
{
    InitAPI();
    gl->Materialx(face, pname, param);
}

GL_API void GL_APIENTRY glMaterialxv (GLenum face, GLenum pname, const GLfixed *params)
{
    InitAPI();
    gl->Materialxv(face, pname, params);
}

GL_API void GL_APIENTRY glMatrixMode (GLenum mode)
{
    InitAPI();
    gl->MatrixMode(mode);
}

GL_API void GL_APIENTRY glMultMatrixx (const GLfixed *m)
{
    InitAPI();
    gl->MultMatrixx(m);
}

GL_API void GL_APIENTRY glMultiTexCoord4x (GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q)
{
    InitAPI();
    gl->MultiTexCoord4x(target, s, t, r, q);
}

GL_API void GL_APIENTRY glNormal3x (GLfixed nx, GLfixed ny, GLfixed nz)
{
    InitAPI();
    gl->Normal3x(nx, ny, nz);
}

GL_API void GL_APIENTRY glNormalPointer (GLenum type, GLsizei stride, const GLvoid *pointer)
{
    InitAPI();
    gl->NormalPointer(type, stride, pointer);
}

GL_API void GL_APIENTRY glOrthox (GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar)
{
    InitAPI();
    gl->Orthox(left, right, bottom, top, zNear, zFar);
}

GL_API void GL_APIENTRY glPixelStorei (GLenum pname, GLint param)
{
    InitAPI();
    gl->PixelStorei(pname, param);
}

GL_API void GL_APIENTRY glPointParameterx (GLenum pname, GLfixed param)
{
    InitAPI();
    gl->PointParameterx(pname, param);
}

GL_API void GL_APIENTRY glPointParameterxv (GLenum pname, const GLfixed *params)
{
    InitAPI();
    gl->PointParameterxv(pname, params);
}

GL_API void GL_APIENTRY glPointSizex (GLfixed size)
{
    InitAPI();
    gl->PointSizex(size);
}

GL_API void GL_APIENTRY glPolygonOffsetx (GLfixed factor, GLfixed units)
{
    InitAPI();
    gl->PolygonOffsetx(factor, units);
}

GL_API void GL_APIENTRY glPopMatrix (void)
{
    InitAPI();
    gl->PopMatrix();
}

GL_API void GL_APIENTRY glPushMatrix (void)
{
    InitAPI();
    gl->PushMatrix();
}

GL_API void GL_APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
    InitAPI();
    gl->ReadPixels(x, y, width, height, format, type, pixels);
}

GL_API void GL_APIENTRY glRotatex (GLfixed angle, GLfixed x, GLfixed y, GLfixed z)
{
    InitAPI();
    gl->Rotatex(angle, x, y, z);
}

GL_API void GL_APIENTRY glSampleCoverage (GLclampf value, GLboolean invert)
{
    InitAPI();
    gl->SampleCoverage(value, invert);
}

GL_API void GL_APIENTRY glSampleCoveragex (GLclampx value, GLboolean invert)
{
    InitAPI();
    gl->SampleCoveragex(value, invert);
}

GL_API void GL_APIENTRY glScalex (GLfixed x, GLfixed y, GLfixed z)
{
    InitAPI();
    gl->Scalex(x, y, z);
}

GL_API void GL_APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
    InitAPI();
    gl->Scissor(x, y, width, height);
}

GL_API void GL_APIENTRY glShadeModel (GLenum mode)
{
    InitAPI();
    gl->ShadeModel(mode);
}

GL_API void GL_APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask)
{
    InitAPI();
    gl->StencilFunc(func, ref, mask);
}

GL_API void GL_APIENTRY glStencilMask (GLuint mask)
{
    InitAPI();
    gl->StencilMask(mask);
}

GL_API void GL_APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
    InitAPI();
    gl->StencilOp(fail, zfail, zpass);
}

GL_API void GL_APIENTRY glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    InitAPI();
    gl->TexCoordPointer(size, type, stride, pointer);
}

GL_API void GL_APIENTRY glTexEnvi (GLenum target, GLenum pname, GLint param)
{
    InitAPI();
    gl->TexEnvi(target, pname, param);
}

GL_API void GL_APIENTRY glTexEnvx (GLenum target, GLenum pname, GLfixed param)
{
    InitAPI();
    gl->TexEnvx(target, pname, param);
}

GL_API void GL_APIENTRY glTexEnviv (GLenum target, GLenum pname, const GLint *params)
{
    InitAPI();
    gl->TexEnviv(target, pname, params);
}

GL_API void GL_APIENTRY glTexEnvxv (GLenum target, GLenum pname, const GLfixed *params)
{
    InitAPI();
    gl->TexEnvxv(target, pname, params);
}

GL_API void GL_APIENTRY glTexImage2D(
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
    InitAPI();
    gl->TexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

GL_API void GL_APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param)
{
    InitAPI();
    gl->TexParameteri(target, pname, param);
}

GL_API void GL_APIENTRY glTexParameterx (GLenum target, GLenum pname, GLfixed param)
{
    InitAPI();
    gl->TexParameterx(target, pname, param);
}

GL_API void GL_APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params)
{
    InitAPI();
    gl->TexParameteriv(target, pname, params);
}

GL_API void GL_APIENTRY glTexParameterxv (GLenum target, GLenum pname, const GLfixed *params)
{
    InitAPI();
    gl->TexParameterxv(target, pname, params);
}

GL_API void GL_APIENTRY glTexSubImage2D(
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
    InitAPI();
    gl->TexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

GL_API void GL_APIENTRY glTranslatex (GLfixed x, GLfixed y, GLfixed z)
{
    InitAPI();
    gl->Translatex(x, y, z);
}

GL_API void GL_APIENTRY glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    InitAPI();
    gl->VertexPointer(size, type, stride, pointer);
}

GL_API void GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
    InitAPI();
    gl->Viewport(x, y, width, height);
}
