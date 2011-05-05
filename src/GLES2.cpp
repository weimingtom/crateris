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

#include "GLES2.h"

namespace crateris {

#define NO_IMPL()

GLES2::GLES2()
{
}

GLES2::~GLES2()
{
}

void GLES2::ActiveTexture(GLenum texture)
{
    NO_IMPL();
}

void GLES2::AttachShader(GLuint program, GLuint shader)
{
    NO_IMPL();
}

void GLES2::BindAttribLocation(GLuint program, GLuint index, const GLchar* name)
{
    NO_IMPL();
}

void GLES2::BindBuffer(GLenum target, GLuint buffer)
{
    NO_IMPL();
}

void GLES2::BindFramebuffer(GLenum target, GLuint framebuffer)
{
    NO_IMPL();
}

void GLES2::BindRenderbuffer(GLenum target, GLuint renderbuffer)
{
    NO_IMPL();
}

void GLES2::BindTexture(GLenum target, GLuint texture)
{
    NO_IMPL();
}

void GLES2::BlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    NO_IMPL();
}

void GLES2::BlendEquation(GLenum mode)
{
    NO_IMPL();
}

void GLES2::BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    NO_IMPL();
}

void GLES2::BlendFunc(GLenum sfactor, GLenum dfactor)
{
    NO_IMPL();
}

void GLES2::BlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    NO_IMPL();
}

void GLES2::BufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
{
    NO_IMPL();
}

void GLES2::BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data)
{
    NO_IMPL();
}

GLenum GLES2::CheckFramebufferStatus(GLenum target)
{
    NO_IMPL();
    return GL_FRAMEBUFFER_UNSUPPORTED;
}

void GLES2::Clear(GLbitfield mask)
{
    NO_IMPL();
}

void GLES2::ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    NO_IMPL();
}

void GLES2::ClearDepthf(GLclampf depth)
{
    NO_IMPL();
}

void GLES2::ClearStencil(GLint s)
{
    NO_IMPL();
}

void GLES2::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    NO_IMPL();
}

void GLES2::CompileShader(GLuint shader)
{
    NO_IMPL();
}

void GLES2::CompressedTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLsizei imageSize,
    const GLvoid* data)
{
    NO_IMPL();
}

void GLES2::CompressedTexSubImage2D(
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
    NO_IMPL();
}

void GLES2::CopyTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLint border)
{
    NO_IMPL();
}

void GLES2::CopyTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height)
{
    NO_IMPL();
}

GLuint GLES2::CreateProgram(void)
{
    NO_IMPL();
    return 0;
}

GLuint GLES2::CreateShader(GLenum type)
{
    NO_IMPL();
    return 0;
}

void GLES2::CullFace(GLenum mode)
{
    NO_IMPL();
}

void GLES2::DeleteBuffers(GLsizei n, const GLuint* buffers)
{
    NO_IMPL();
}

void GLES2::DeleteFramebuffers(GLsizei n, const GLuint* framebuffers)
{
    NO_IMPL();
}

void GLES2::DeleteProgram(GLuint program)
{
    NO_IMPL();
}

void GLES2::DeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers)
{
    NO_IMPL();
}

void GLES2::DeleteShader(GLuint shader)
{
    NO_IMPL();
}

void GLES2::DeleteTextures(GLsizei n, const GLuint* textures)
{
    NO_IMPL();
}

void GLES2::DepthFunc(GLenum func)
{
    NO_IMPL();
}

void GLES2::DepthMask(GLboolean flag)
{
    NO_IMPL();
}

void GLES2::DepthRangef(GLclampf zNear, GLclampf zFar)
{
    NO_IMPL();
}

void GLES2::DetachShader(GLuint program, GLuint shader)
{
    NO_IMPL();
}

void GLES2::Disable(GLenum cap)
{
    NO_IMPL();
}

void GLES2::DisableVertexAttribArray(GLuint index)
{
    NO_IMPL();
}

void GLES2::DrawArrays(GLenum mode, GLint first, GLsizei count)
{
    NO_IMPL();
}

void GLES2::DrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices)
{
    NO_IMPL();
}

void GLES2::Enable(GLenum cap)
{
    NO_IMPL();
}

void GLES2::EnableVertexAttribArray(GLuint index)
{
    NO_IMPL();
}

void GLES2::Finish(void)
{
    NO_IMPL();
}

void GLES2::Flush(void)
{
    NO_IMPL();
}

void GLES2::FramebufferRenderbuffer(
    GLenum target,
    GLenum attachment,
    GLenum renderbuffertarget,
    GLuint renderbuffer)
{
    NO_IMPL();
}

void GLES2::FramebufferTexture2D(
    GLenum target,
    GLenum attachment,
    GLenum textarget,
    GLuint texture,
    GLint level)
{
    NO_IMPL();
}

void GLES2::FrontFace(GLenum mode)
{
    NO_IMPL();
}

void GLES2::GenBuffers(GLsizei n, GLuint* buffers)
{
    NO_IMPL();
}

void GLES2::GenerateMipmap(GLenum target)
{
    NO_IMPL();
}

void GLES2::GenFramebuffers(GLsizei n, GLuint* framebuffers)
{
    NO_IMPL();
}

void GLES2::GenRenderbuffers(GLsizei n, GLuint* renderbuffers)
{
    NO_IMPL();
}

void GLES2::GenTextures(GLsizei n, GLuint* textures)
{
    NO_IMPL();
}

void GLES2::GetActiveAttrib(
    GLuint program,
    GLuint index,
    GLsizei bufsize,
    GLsizei* length,
    GLint* size,
    GLenum* type,
    GLchar* name)
{
    NO_IMPL();
}

void GLES2::GetActiveUniform(
    GLuint program,
    GLuint index,
    GLsizei bufsize,
    GLsizei* length,
    GLint* size,
    GLenum* type,
    GLchar* name)
{
    NO_IMPL();
}

void GLES2::GetAttachedShaders(
    GLuint program,
    GLsizei maxcount,
    GLsizei* count,
    GLuint* shaders)
{
    NO_IMPL();
}

GLint GLES2::GetAttribLocation(GLuint program, const GLchar* name)
{
    NO_IMPL();
    return -1;
}

void GLES2::GetBooleanv(GLenum pname, GLboolean* params)
{
    NO_IMPL();
}

void GLES2::GetBufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    NO_IMPL();
}

GLenum GLES2::GetError(void)
{
    NO_IMPL();
    return GL_INVALID_OPERATION;
}

void GLES2::GetFloatv(GLenum pname, GLfloat* params)
{
    NO_IMPL();
}

void GLES2::GetFramebufferAttachmentParameteriv(
    GLenum target,
    GLenum attachment,
    GLenum pname,
    GLint* params)
{
    NO_IMPL();
}

void GLES2::GetIntegerv(GLenum pname, GLint* params)
{
    NO_IMPL();
}

void GLES2::GetProgramiv(GLuint program, GLenum pname, GLint* params)
{
    NO_IMPL();
}

void GLES2::GetProgramInfoLog(
    GLuint program,
    GLsizei bufsize,
    GLsizei* length,
    GLchar* infolog)
{
    NO_IMPL();
}

void GLES2::GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    NO_IMPL();
}

void GLES2::GetShaderiv(GLuint shader, GLenum pname, GLint* params)
{
    NO_IMPL();
}

void GLES2::GetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    NO_IMPL();
}

void GLES2::GetShaderPrecisionFormat(
    GLenum shadertype,
    GLenum precisiontype,
    GLint* range,
    GLint* precision)
{
    NO_IMPL();
}

void GLES2::GetShaderSource(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source)
{
    NO_IMPL();
}

const GLubyte* GLES2::GetString(GLenum name)
{
    NO_IMPL();
    return 0;
}

void GLES2::GetTexParameterfv(GLenum target, GLenum pname, GLfloat* params)
{
    NO_IMPL();
}

void GLES2::GetTexParameteriv(GLenum target, GLenum pname, GLint* params)
{
    NO_IMPL();
}

void GLES2::GetUniformfv(GLuint program, GLint location, GLfloat* params)
{
    NO_IMPL();
}

void GLES2::GetUniformiv(GLuint program, GLint location, GLint* params)
{
    NO_IMPL();
}

GLint GLES2::GetUniformLocation(GLuint program, const GLchar* name)
{
    NO_IMPL();
    return -1;
}

void GLES2::GetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params)
{
    NO_IMPL();
}

void GLES2::GetVertexAttribiv(GLuint index, GLenum pname, GLint* params)
{
    NO_IMPL();
}

void GLES2::GetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid** pointer)
{
    NO_IMPL();
}

void GLES2::Hint(GLenum target, GLenum mode)
{
    NO_IMPL();
}

GLboolean GLES2::IsBuffer(GLuint buffer)
{
    NO_IMPL();
    return GL_FALSE;
}

GLboolean GLES2::IsEnabled(GLenum cap)
{
    NO_IMPL();
    return GL_FALSE;
}

GLboolean GLES2::IsFramebuffer(GLuint framebuffer)
{
    NO_IMPL();
    return GL_FALSE;
}

GLboolean GLES2::IsProgram(GLuint program)
{
    NO_IMPL();
    return GL_FALSE;
}

GLboolean GLES2::IsRenderbuffer(GLuint renderbuffer)
{
    NO_IMPL();
    return GL_FALSE;
}

GLboolean GLES2::IsShader(GLuint shader)
{
    NO_IMPL();
    return GL_FALSE;
}

GLboolean GLES2::IsTexture(GLuint texture)
{
    NO_IMPL();
    return GL_FALSE;
}

void GLES2::LineWidth(GLfloat width)
{
    NO_IMPL();
}

void GLES2::LinkProgram(GLuint program)
{
    NO_IMPL();
}

void GLES2::PixelStorei(GLenum pname, GLint param)
{
    NO_IMPL();
}

void GLES2::PolygonOffset(GLfloat factor, GLfloat units)
{
    NO_IMPL();
}

void GLES2::ReadPixels(
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    GLvoid* pixels)
{
    NO_IMPL();
}

void GLES2::ReleaseShaderCompiler(void)
{
    NO_IMPL();
}

void GLES2::RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    NO_IMPL();
}

void GLES2::SampleCoverage(GLclampf value, GLboolean invert)
{
    NO_IMPL();
}

void GLES2::Scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    NO_IMPL();
}

void GLES2::ShaderBinary(
    GLsizei n,
    const GLuint* shaders,
    GLenum binaryformat,
    const GLvoid* binary,
    GLsizei length)
{
    NO_IMPL();
}

void GLES2::ShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length)
{
    NO_IMPL();
}

void GLES2::StencilFunc(GLenum func, GLint ref, GLuint mask)
{
    NO_IMPL();
}

void GLES2::StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    NO_IMPL();
}

void GLES2::StencilMask(GLuint mask)
{
    NO_IMPL();
}

void GLES2::StencilMaskSeparate(GLenum face, GLuint mask)
{
    NO_IMPL();
}

void GLES2::StencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    NO_IMPL();
}

void GLES2::StencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    NO_IMPL();
}

void GLES2::TexImage2D(
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
    NO_IMPL();
}

void GLES2::TexParameterf(GLenum target, GLenum pname, GLfloat param)
{
    NO_IMPL();
}

void GLES2::TexParameterfv(GLenum target, GLenum pname, const GLfloat* params)
{
    NO_IMPL();
}

void GLES2::TexParameteri(GLenum target, GLenum pname, GLint param)
{
    NO_IMPL();
}

void GLES2::TexParameteriv(GLenum target, GLenum pname, const GLint* params)
{
    NO_IMPL();
}

void GLES2::TexSubImage2D(
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
    NO_IMPL();
}

void GLES2::Uniform1f(GLint location, GLfloat x)
{
    NO_IMPL();
}

void GLES2::Uniform1fv(GLint location, GLsizei count, const GLfloat* v)
{
    NO_IMPL();
}

void GLES2::Uniform1i(GLint location, GLint x)
{
    NO_IMPL();
}

void GLES2::Uniform1iv(GLint location, GLsizei count, const GLint* v)
{
    NO_IMPL();
}

void GLES2::Uniform2f(GLint location, GLfloat x, GLfloat y)
{
    NO_IMPL();
}

void GLES2::Uniform2fv(GLint location, GLsizei count, const GLfloat* v)
{
    NO_IMPL();
}

void GLES2::Uniform2i(GLint location, GLint x, GLint y)
{
    NO_IMPL();
}

void GLES2::Uniform2iv(GLint location, GLsizei count, const GLint* v)
{
    NO_IMPL();
}

void GLES2::Uniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    NO_IMPL();
}

void GLES2::Uniform3fv(GLint location, GLsizei count, const GLfloat* v)
{
    NO_IMPL();
}

void GLES2::Uniform3i(GLint location, GLint x, GLint y, GLint z)
{
    NO_IMPL();
}

void GLES2::Uniform3iv(GLint location, GLsizei count, const GLint* v)
{
    NO_IMPL();
}

void GLES2::Uniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    NO_IMPL();
}

void GLES2::Uniform4fv(GLint location, GLsizei count, const GLfloat* v)
{
    NO_IMPL();
}

void GLES2::Uniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)
{
    NO_IMPL();
}

void GLES2::Uniform4iv(GLint location, GLsizei count, const GLint* v)
{
    NO_IMPL();
}

void GLES2::UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    NO_IMPL();
}

void GLES2::UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    NO_IMPL();
}

void GLES2::UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    NO_IMPL();
}

void GLES2::UseProgram(GLuint program)
{
    NO_IMPL();
}

void GLES2::ValidateProgram(GLuint program)
{
    NO_IMPL();
}

void GLES2::VertexAttrib1f(GLuint indx, GLfloat x)
{
    NO_IMPL();
}

void GLES2::VertexAttrib1fv(GLuint indx, const GLfloat* values)
{
    NO_IMPL();
}

void GLES2::VertexAttrib2f(GLuint indx, GLfloat x, GLfloat y)
{
    NO_IMPL();
}

void GLES2::VertexAttrib2fv(GLuint indx, const GLfloat* values)
{
    NO_IMPL();
}

void GLES2::VertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    NO_IMPL();
}

void GLES2::VertexAttrib3fv(GLuint indx, const GLfloat* values)
{
    NO_IMPL();
}

void GLES2::VertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    NO_IMPL();
}

void GLES2::VertexAttrib4fv(GLuint indx, const GLfloat* values)
{
    NO_IMPL();
}

void GLES2::VertexAttribPointer(
    GLuint indx,
    GLint size,
    GLenum type,
    GLboolean normalized,
    GLsizei stride,
    const GLvoid* ptr)
{
    NO_IMPL();
}

void GLES2::Viewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    NO_IMPL();
}

}
