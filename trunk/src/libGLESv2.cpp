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

#define GL_APICALL extern "C" __declspec(dllexport)
#include "EGL.h"
#include "GLES2.h"

#define InitAPI()   \
    crateris::GLES2* gl = crateris_get_EGL()->getGLES2()

GL_APICALL void GL_APIENTRY glActiveTexture (GLenum texture)
{
    InitAPI();
    gl->ActiveTexture(texture);
}

GL_APICALL void GL_APIENTRY glAttachShader (GLuint program, GLuint shader)
{
    InitAPI();
    gl->AttachShader(program, shader);
}

GL_APICALL void GL_APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar* name)
{
    InitAPI();
    gl->BindAttribLocation(program, index, name);
}

GL_APICALL void GL_APIENTRY glBindBuffer (GLenum target, GLuint buffer)
{
    InitAPI();
    gl->BindBuffer(target, buffer);
}

GL_APICALL void GL_APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer)
{
    InitAPI();
    gl->BindFramebuffer(target, framebuffer);
}

GL_APICALL void GL_APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer)
{
    InitAPI();
    gl->BindRenderbuffer(target, renderbuffer);
}

GL_APICALL void GL_APIENTRY glBindTexture (GLenum target, GLuint texture)
{
    InitAPI();
    gl->BindTexture(target, texture);
}

GL_APICALL void GL_APIENTRY glBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    InitAPI();
    gl->BlendColor(red, green, blue, alpha);
}

GL_APICALL void GL_APIENTRY glBlendEquation ( GLenum mode )
{
    InitAPI();
    gl->BlendEquation(mode);
}

GL_APICALL void GL_APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha)
{
    InitAPI();
    gl->BlendEquationSeparate(modeRGB, modeAlpha);
}

GL_APICALL void GL_APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor)
{
    InitAPI();
    gl->BlendFunc(sfactor, dfactor);
}

GL_APICALL void GL_APIENTRY glBlendFuncSeparate (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    InitAPI();
    gl->BlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}

GL_APICALL void GL_APIENTRY glBufferData (GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
{
    InitAPI();
    gl->BufferData(target, size, data, usage);
}

GL_APICALL void GL_APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data)
{
    InitAPI();
    gl->BufferSubData(target, offset, size, data);
}

GL_APICALL GLenum GL_APIENTRY glCheckFramebufferStatus (GLenum target)
{
    InitAPI();
    return gl->CheckFramebufferStatus(target);
}

GL_APICALL void GL_APIENTRY glClear (GLbitfield mask)
{
    InitAPI();
    gl->Clear(mask);
}

GL_APICALL void GL_APIENTRY glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    InitAPI();
    gl->ClearColor(red, green, blue, alpha);
}

GL_APICALL void GL_APIENTRY glClearDepthf (GLclampf depth)
{
    InitAPI();
    gl->ClearDepthf(depth);
}

GL_APICALL void GL_APIENTRY glClearStencil (GLint s)
{
    InitAPI();
    gl->ClearStencil(s);
}

GL_APICALL void GL_APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    InitAPI();
    gl->ColorMask(red, green, blue, alpha);
}

GL_APICALL void GL_APIENTRY glCompileShader (GLuint shader)
{
    InitAPI();
    gl->CompileShader(shader);
}

GL_APICALL void GL_APIENTRY glCompressedTexImage2D (
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLsizei imageSize,
    const GLvoid* data)
{
    InitAPI();
    gl->CompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

GL_APICALL void GL_APIENTRY glCompressedTexSubImage2D (
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLsizei imageSize,
    const GLvoid* data)
{
    InitAPI();
    gl->CompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

GL_APICALL void GL_APIENTRY glCopyTexImage2D (
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
    gl->CopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}

GL_APICALL void GL_APIENTRY glCopyTexSubImage2D (
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
    gl->CopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

GL_APICALL GLuint GL_APIENTRY glCreateProgram (void)
{
    InitAPI();
    return gl->CreateProgram();
}

GL_APICALL GLuint GL_APIENTRY glCreateShader (GLenum type)
{
    InitAPI();
    return gl->CreateShader(type);
}

GL_APICALL void GL_APIENTRY glCullFace (GLenum mode)
{
    InitAPI();
    gl->CullFace(mode);
}

GL_APICALL void GL_APIENTRY glDeleteBuffers (GLsizei n, const GLuint* buffers)
{
    InitAPI();
    gl->DeleteBuffers(n, buffers);
}

GL_APICALL void GL_APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint* framebuffers)
{
    InitAPI();
    gl->DeleteFramebuffers(n, framebuffers);
}

GL_APICALL void GL_APIENTRY glDeleteProgram (GLuint program)
{
    InitAPI();
    gl->DeleteProgram(program);
}

GL_APICALL void GL_APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint* renderbuffers)
{
    InitAPI();
    gl->DeleteRenderbuffers(n, renderbuffers);
}

GL_APICALL void GL_APIENTRY glDeleteShader (GLuint shader)
{
    InitAPI();
    gl->DeleteShader(shader);
}

GL_APICALL void GL_APIENTRY glDeleteTextures (GLsizei n, const GLuint* textures)
{
    InitAPI();
    gl->DeleteTextures(n, textures);
}

GL_APICALL void GL_APIENTRY glDepthFunc (GLenum func)
{
    InitAPI();
    gl->DepthFunc(func);
}

GL_APICALL void GL_APIENTRY glDepthMask (GLboolean flag)
{
    InitAPI();
    gl->DepthMask(flag);
}

GL_APICALL void GL_APIENTRY glDepthRangef (GLclampf zNear, GLclampf zFar)
{
    InitAPI();
    gl->DepthRangef(zNear, zFar);
}

GL_APICALL void GL_APIENTRY glDetachShader (GLuint program, GLuint shader)
{
    InitAPI();
    gl->DetachShader(program, shader);
}

GL_APICALL void GL_APIENTRY glDisable (GLenum cap)
{
    InitAPI();
    gl->Disable(cap);
}

GL_APICALL void GL_APIENTRY glDisableVertexAttribArray (GLuint index)
{
    InitAPI();
    gl->DisableVertexAttribArray(index);
}

GL_APICALL void GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
    InitAPI();
    gl->DrawArrays(mode, first, count);
}

GL_APICALL void GL_APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices)
{
    InitAPI();
    gl->DrawElements(mode, count, type, indices);
}

GL_APICALL void GL_APIENTRY glEnable (GLenum cap)
{
    InitAPI();
    gl->Enable(cap);
}

GL_APICALL void GL_APIENTRY glEnableVertexAttribArray (GLuint index)
{
    InitAPI();
    gl->EnableVertexAttribArray(index);
}

GL_APICALL void GL_APIENTRY glFinish (void)
{
    InitAPI();
    gl->Finish();
}

GL_APICALL void GL_APIENTRY glFlush (void)
{
    InitAPI();
    gl->Flush();
}

GL_APICALL void GL_APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    InitAPI();
    gl->FramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

GL_APICALL void GL_APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    InitAPI();
    gl->FramebufferTexture2D(target, attachment, textarget, texture, level);
}

GL_APICALL void GL_APIENTRY glFrontFace (GLenum mode)
{
    InitAPI();
    gl->FrontFace(mode);
}

GL_APICALL void GL_APIENTRY glGenBuffers (GLsizei n, GLuint* buffers)
{
    InitAPI();
    gl->GenBuffers(n, buffers);
}

GL_APICALL void GL_APIENTRY glGenerateMipmap (GLenum target)
{
    InitAPI();
    gl->GenerateMipmap(target);
}

GL_APICALL void GL_APIENTRY glGenFramebuffers (GLsizei n, GLuint* framebuffers)
{
    InitAPI();
    gl->GenFramebuffers(n, framebuffers);
}

GL_APICALL void GL_APIENTRY glGenRenderbuffers (GLsizei n, GLuint* renderbuffers)
{
    InitAPI();
    gl->GenRenderbuffers(n, renderbuffers);
}

GL_APICALL void GL_APIENTRY glGenTextures (GLsizei n, GLuint* textures)
{
    InitAPI();
    gl->GenTextures(n, textures);
}

GL_APICALL void GL_APIENTRY glGetActiveAttrib (
    GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name)
{
    InitAPI();
    gl->GetActiveAttrib(program, index, bufsize, length, size, type, name);
}

GL_APICALL void GL_APIENTRY glGetActiveUniform (
    GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name)
{
    InitAPI();
    gl->GetActiveUniform(program, index, bufsize, length, size, type, name);
}

GL_APICALL void GL_APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)
{
    InitAPI();
    gl->GetAttachedShaders(program, maxcount, count, shaders);
}

GL_APICALL int GL_APIENTRY glGetAttribLocation (GLuint program, const GLchar* name)
{
    InitAPI();
    return gl->GetAttribLocation(program, name);
}

GL_APICALL void GL_APIENTRY glGetBooleanv (GLenum pname, GLboolean* params)
{
    InitAPI();
    gl->GetBooleanv(pname, params);
}

GL_APICALL void GL_APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint* params)
{
    InitAPI();
    gl->GetBufferParameteriv(target, pname, params);
}

GL_APICALL GLenum GL_APIENTRY glGetError (void)
{
    InitAPI();
    return gl->GetError();
}

GL_APICALL void GL_APIENTRY glGetFloatv (GLenum pname, GLfloat* params)
{
    InitAPI();
    gl->GetFloatv(pname, params);
}

GL_APICALL void GL_APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint* params)
{
    InitAPI();
    gl->GetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

GL_APICALL void GL_APIENTRY glGetIntegerv (GLenum pname, GLint* params)
{
    InitAPI();
    gl->GetIntegerv(pname, params);
}

GL_APICALL void GL_APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint* params)
{
    InitAPI();
    gl->GetProgramiv(program, pname, params);
}

GL_APICALL void GL_APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    InitAPI();
    gl->GetProgramInfoLog(program, bufsize, length, infolog);
}

GL_APICALL void GL_APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint* params)
{
    InitAPI();
    gl->GetRenderbufferParameteriv(target, pname, params);
}

GL_APICALL void GL_APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint* params)
{
    InitAPI();
    gl->GetShaderiv(shader, pname, params);
}

GL_APICALL void GL_APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    InitAPI();
    gl->GetShaderInfoLog(shader, bufsize, length, infolog);
}

GL_APICALL void GL_APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision)
{
    InitAPI();
    gl->GetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}

GL_APICALL void GL_APIENTRY glGetShaderSource (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source)
{
    InitAPI();
    gl->GetShaderSource(shader, bufsize, length, source);
}

GL_APICALL const GLubyte* GL_APIENTRY glGetString (GLenum name)
{
    InitAPI();
    return gl->GetString(name);
}

GL_APICALL void GL_APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat* params)
{
    InitAPI();
    gl->GetTexParameterfv(target, pname, params);
}

GL_APICALL void GL_APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint* params)
{
    InitAPI();
    gl->GetTexParameteriv(target, pname, params);
}

GL_APICALL void GL_APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat* params)
{
    InitAPI();
    gl->GetUniformfv(program, location, params);
}

GL_APICALL void GL_APIENTRY glGetUniformiv (GLuint program, GLint location, GLint* params)
{
    InitAPI();
    gl->GetUniformiv(program, location, params);
}

GL_APICALL int GL_APIENTRY glGetUniformLocation (GLuint program, const GLchar* name)
{
    InitAPI();
    return gl->GetUniformLocation(program, name);
}

GL_APICALL void GL_APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat* params)
{
    InitAPI();
    gl->GetVertexAttribfv(index, pname, params);
}

GL_APICALL void GL_APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint* params)
{
    InitAPI();
    gl->GetVertexAttribiv(index, pname, params);
}

GL_APICALL void GL_APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid** pointer)
{
    InitAPI();
    gl->GetVertexAttribPointerv(index, pname, pointer);
}

GL_APICALL void GL_APIENTRY glHint (GLenum target, GLenum mode)
{
    InitAPI();
    gl->Hint(target, mode);
}

GL_APICALL GLboolean GL_APIENTRY glIsBuffer (GLuint buffer)
{
    InitAPI();
    return gl->IsBuffer(buffer);
}

GL_APICALL GLboolean GL_APIENTRY glIsEnabled (GLenum cap)
{
    InitAPI();
    return gl->IsEnabled(cap);
}

GL_APICALL GLboolean GL_APIENTRY glIsFramebuffer (GLuint framebuffer)
{
    InitAPI();
    return gl->IsFramebuffer(framebuffer);
}

GL_APICALL GLboolean GL_APIENTRY glIsProgram (GLuint program)
{
    InitAPI();
    return gl->IsProgram(program);
}

GL_APICALL GLboolean GL_APIENTRY glIsRenderbuffer (GLuint renderbuffer)
{
    InitAPI();
    return gl->IsRenderbuffer(renderbuffer);
}

GL_APICALL GLboolean GL_APIENTRY glIsShader (GLuint shader)
{
    InitAPI();
    return gl->IsShader(shader);
}

GL_APICALL GLboolean GL_APIENTRY glIsTexture (GLuint texture)
{
    InitAPI();
    return gl->IsTexture(texture);
}

GL_APICALL void GL_APIENTRY glLineWidth (GLfloat width)
{
    InitAPI();
    gl->LineWidth(width);
}

GL_APICALL void GL_APIENTRY glLinkProgram (GLuint program)
{
    InitAPI();
    gl->LinkProgram(program);
}

GL_APICALL void GL_APIENTRY glPixelStorei (GLenum pname, GLint param)
{
    InitAPI();
    gl->PixelStorei(pname, param);
}

GL_APICALL void GL_APIENTRY glPolygonOffset (GLfloat factor, GLfloat units)
{
    InitAPI();
    gl->PolygonOffset(factor, units);
}

GL_APICALL void GL_APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels)
{
    InitAPI();
    gl->ReadPixels(x, y, width, height, format, type, pixels);
}

GL_APICALL void GL_APIENTRY glReleaseShaderCompiler (void)
{
    InitAPI();
    gl->ReleaseShaderCompiler();
}

GL_APICALL void GL_APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    InitAPI();
    gl->RenderbufferStorage(target, internalformat, width, height);
}

GL_APICALL void GL_APIENTRY glSampleCoverage (GLclampf value, GLboolean invert)
{
    InitAPI();
    gl->SampleCoverage(value, invert);
}

GL_APICALL void GL_APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
    InitAPI();
    gl->Scissor(x, y, width, height);
}

GL_APICALL void GL_APIENTRY glShaderBinary (GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length)
{
    InitAPI();
    gl->ShaderBinary(n, shaders, binaryformat, binary, length);
}

GL_APICALL void GL_APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar** string, const GLint* length)
{
    InitAPI();
    gl->ShaderSource(shader, count, string, length);
}

GL_APICALL void GL_APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask)
{
    InitAPI();
    gl->StencilFunc(func, ref, mask);
}

GL_APICALL void GL_APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask)
{
    InitAPI();
    gl->StencilFuncSeparate(face, func, ref, mask);
}

GL_APICALL void GL_APIENTRY glStencilMask (GLuint mask)
{
    InitAPI();
    gl->StencilMask(mask);
}

GL_APICALL void GL_APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask)
{
    InitAPI();
    gl->StencilMaskSeparate(face, mask);
}

GL_APICALL void GL_APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
    InitAPI();
    gl->StencilOp(fail, zfail, zpass);
}

GL_APICALL void GL_APIENTRY glStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    InitAPI();
    gl->StencilOpSeparate(face, fail, zfail, zpass);
}

GL_APICALL void GL_APIENTRY glTexImage2D (
    GLenum target,
    GLint level,
    GLint internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLenum format,
    GLenum type,
    const GLvoid* pixels)
{
    InitAPI();
    gl->TexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

GL_APICALL void GL_APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param)
{
    InitAPI();
    gl->TexParameterf(target, pname, param);
}

GL_APICALL void GL_APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat* params)
{
    InitAPI();
    gl->TexParameterfv(target, pname, params);
}

GL_APICALL void GL_APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param)
{
    InitAPI();
    gl->TexParameteri(target, pname, param);
}

GL_APICALL void GL_APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint* params)
{
    InitAPI();
    gl->TexParameteriv(target, pname, params);
}

GL_APICALL void GL_APIENTRY glTexSubImage2D (
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    const GLvoid* pixels)
{
    InitAPI();
    gl->TexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

GL_APICALL void GL_APIENTRY glUniform1f (GLint location, GLfloat x)
{
    InitAPI();
    gl->Uniform1f(location, x);
}

GL_APICALL void GL_APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat* v)
{
    InitAPI();
    gl->Uniform1fv(location, count, v);
}

GL_APICALL void GL_APIENTRY glUniform1i (GLint location, GLint x)
{
    InitAPI();
    gl->Uniform1i(location, x);
}

GL_APICALL void GL_APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint* v)
{
    InitAPI();
    gl->Uniform1iv(location, count, v);
}

GL_APICALL void GL_APIENTRY glUniform2f (GLint location, GLfloat x, GLfloat y)
{
    InitAPI();
    gl->Uniform2f(location, x, y);
}

GL_APICALL void GL_APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat* v)
{
    InitAPI();
    gl->Uniform2fv(location, count, v);
}

GL_APICALL void GL_APIENTRY glUniform2i (GLint location, GLint x, GLint y)
{
    InitAPI();
    gl->Uniform2i(location, x, y);
}

GL_APICALL void GL_APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint* v)
{
    InitAPI();
    gl->Uniform2iv(location, count, v);
}

GL_APICALL void GL_APIENTRY glUniform3f (GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    InitAPI();
    gl->Uniform3f(location, x, y, z);
}

GL_APICALL void GL_APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat* v)
{
    InitAPI();
    gl->Uniform3fv(location, count, v);
}

GL_APICALL void GL_APIENTRY glUniform3i (GLint location, GLint x, GLint y, GLint z)
{
    InitAPI();
    gl->Uniform3i(location, x, y, z);
}

GL_APICALL void GL_APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint* v)
{
    InitAPI();
    gl->Uniform3iv(location, count, v);
}

GL_APICALL void GL_APIENTRY glUniform4f (GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    InitAPI();
    gl->Uniform4f(location, x, y, z, w);
}

GL_APICALL void GL_APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat* v)
{
    InitAPI();
    gl->Uniform4fv(location, count, v);
}

GL_APICALL void GL_APIENTRY glUniform4i (GLint location, GLint x, GLint y, GLint z, GLint w)
{
    InitAPI();
    gl->Uniform4i(location, x, y, z, w);
}

GL_APICALL void GL_APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint* v)
{
    InitAPI();
    gl->Uniform4iv(location, count, v);
}

GL_APICALL void GL_APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    InitAPI();
    gl->UniformMatrix2fv(location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    InitAPI();
    gl->UniformMatrix3fv(location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    InitAPI();
    gl->UniformMatrix4fv(location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY glUseProgram (GLuint program)
{
    InitAPI();
    gl->UseProgram(program);
}

GL_APICALL void GL_APIENTRY glValidateProgram (GLuint program)
{
    InitAPI();
    gl->ValidateProgram(program);
}

GL_APICALL void GL_APIENTRY glVertexAttrib1f (GLuint indx, GLfloat x)
{
    InitAPI();
    gl->VertexAttrib1f(indx, x);
}

GL_APICALL void GL_APIENTRY glVertexAttrib1fv (GLuint indx, const GLfloat* values)
{
    InitAPI();
    gl->VertexAttrib1fv(indx, values);
}

GL_APICALL void GL_APIENTRY glVertexAttrib2f (GLuint indx, GLfloat x, GLfloat y)
{
    InitAPI();
    gl->VertexAttrib2f(indx, x, y);
}

GL_APICALL void GL_APIENTRY glVertexAttrib2fv (GLuint indx, const GLfloat* values)
{
    InitAPI();
    gl->VertexAttrib2fv(indx, values);
}

GL_APICALL void GL_APIENTRY glVertexAttrib3f (GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    InitAPI();
    gl->VertexAttrib3f(indx, x, y, z);
}

GL_APICALL void GL_APIENTRY glVertexAttrib3fv (GLuint indx, const GLfloat* values)
{
    InitAPI();
    gl->VertexAttrib3fv(indx, values);
}

GL_APICALL void GL_APIENTRY glVertexAttrib4f (GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    InitAPI();
    gl->VertexAttrib4f(indx, x, y, z, w);
}

GL_APICALL void GL_APIENTRY glVertexAttrib4fv (GLuint indx, const GLfloat* values)
{
    InitAPI();
    gl->VertexAttrib4fv(indx, values);
}

GL_APICALL void GL_APIENTRY glVertexAttribPointer (
    GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr)
{
    InitAPI();
    gl->VertexAttribPointer(indx, size, type, normalized, stride, ptr);
}

GL_APICALL void GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
    InitAPI();
    gl->Viewport(x, y, width, height);
}
