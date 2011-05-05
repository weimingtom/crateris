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

#ifndef CRATERIS_GLES2_H_INCLUDED_
#define CRATERIS_GLES2_H_INCLUDED_

#include <GLES2/gl2.h>

namespace crateris {

class GLES2
{
public:
    virtual void ActiveTexture(GLenum texture);
    virtual void AttachShader(GLuint program, GLuint shader);
    virtual void BindAttribLocation(GLuint program, GLuint index, const GLchar* name);
    virtual void BindBuffer(GLenum target, GLuint buffer);
    virtual void BindFramebuffer(GLenum target, GLuint framebuffer);
    virtual void BindRenderbuffer(GLenum target, GLuint renderbuffer);
    virtual void BindTexture(GLenum target, GLuint texture);
    virtual void BlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    virtual void BlendEquation( GLenum mode );
    virtual void BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
    virtual void BlendFunc(GLenum sfactor, GLenum dfactor);
    virtual void BlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    virtual void BufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
    virtual void BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
    virtual GLenum CheckFramebufferStatus(GLenum target);
    virtual void Clear(GLbitfield mask);
    virtual void ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    virtual void ClearDepthf(GLclampf depth);
    virtual void ClearStencil(GLint s);
    virtual void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    virtual void CompileShader(GLuint shader);
    virtual void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
    virtual void CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
    virtual void CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    virtual void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    virtual GLuint CreateProgram(void);
    virtual GLuint CreateShader(GLenum type);
    virtual void CullFace(GLenum mode);
    virtual void DeleteBuffers(GLsizei n, const GLuint* buffers);
    virtual void DeleteFramebuffers(GLsizei n, const GLuint* framebuffers);
    virtual void DeleteProgram(GLuint program);
    virtual void DeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers);
    virtual void DeleteShader(GLuint shader);
    virtual void DeleteTextures(GLsizei n, const GLuint* textures);
    virtual void DepthFunc(GLenum func);
    virtual void DepthMask(GLboolean flag);
    virtual void DepthRangef(GLclampf zNear, GLclampf zFar);
    virtual void DetachShader(GLuint program, GLuint shader);
    virtual void Disable(GLenum cap);
    virtual void DisableVertexAttribArray(GLuint index);
    virtual void DrawArrays(GLenum mode, GLint first, GLsizei count);
    virtual void DrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
    virtual void Enable(GLenum cap);
    virtual void EnableVertexAttribArray(GLuint index);
    virtual void Finish(void);
    virtual void Flush(void);
    virtual void FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    virtual void FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    virtual void FrontFace(GLenum mode);
    virtual void GenBuffers(GLsizei n, GLuint* buffers);
    virtual void GenerateMipmap(GLenum target);
    virtual void GenFramebuffers(GLsizei n, GLuint* framebuffers);
    virtual void GenRenderbuffers(GLsizei n, GLuint* renderbuffers);
    virtual void GenTextures(GLsizei n, GLuint* textures);
    virtual void GetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
    virtual void GetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
    virtual void GetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders);
    virtual GLint GetAttribLocation(GLuint program, const GLchar* name);
    virtual void GetBooleanv(GLenum pname, GLboolean* params);
    virtual void GetBufferParameteriv(GLenum target, GLenum pname, GLint* params);
    virtual GLenum GetError(void);
    virtual void GetFloatv(GLenum pname, GLfloat* params);
    virtual void GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params);
    virtual void GetIntegerv(GLenum pname, GLint* params);
    virtual void GetProgramiv(GLuint program, GLenum pname, GLint* params);
    virtual void GetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog);
    virtual void GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params);
    virtual void GetShaderiv(GLuint shader, GLenum pname, GLint* params);
    virtual void GetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog);
    virtual void GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
    virtual void GetShaderSource(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source);
    virtual const GLubyte* GetString(GLenum name);
    virtual void GetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
    virtual void GetTexParameteriv(GLenum target, GLenum pname, GLint* params);
    virtual void GetUniformfv(GLuint program, GLint location, GLfloat* params);
    virtual void GetUniformiv(GLuint program, GLint location, GLint* params);
    virtual GLint GetUniformLocation(GLuint program, const GLchar* name);
    virtual void GetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params);
    virtual void GetVertexAttribiv(GLuint index, GLenum pname, GLint* params);
    virtual void GetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid** pointer);
    virtual void Hint(GLenum target, GLenum mode);
    virtual GLboolean IsBuffer(GLuint buffer);
    virtual GLboolean IsEnabled(GLenum cap);
    virtual GLboolean IsFramebuffer(GLuint framebuffer);
    virtual GLboolean IsProgram(GLuint program);
    virtual GLboolean IsRenderbuffer(GLuint renderbuffer);
    virtual GLboolean IsShader(GLuint shader);
    virtual GLboolean IsTexture(GLuint texture);
    virtual void LineWidth(GLfloat width);
    virtual void LinkProgram(GLuint program);
    virtual void PixelStorei(GLenum pname, GLint param);
    virtual void PolygonOffset(GLfloat factor, GLfloat units);
    virtual void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
    virtual void ReleaseShaderCompiler(void);
    virtual void RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    virtual void SampleCoverage(GLclampf value, GLboolean invert);
    virtual void Scissor(GLint x, GLint y, GLsizei width, GLsizei height);
    virtual void ShaderBinary(GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
    virtual void ShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
    virtual void StencilFunc(GLenum func, GLint ref, GLuint mask);
    virtual void StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
    virtual void StencilMask(GLuint mask);
    virtual void StencilMaskSeparate(GLenum face, GLuint mask);
    virtual void StencilOp(GLenum fail, GLenum zfail, GLenum zpass);
    virtual void StencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
    virtual void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
    virtual void TexParameterf(GLenum target, GLenum pname, GLfloat param);
    virtual void TexParameterfv(GLenum target, GLenum pname, const GLfloat* params);
    virtual void TexParameteri(GLenum target, GLenum pname, GLint param);
    virtual void TexParameteriv(GLenum target, GLenum pname, const GLint* params);
    virtual void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
    virtual void Uniform1f(GLint location, GLfloat x);
    virtual void Uniform1fv(GLint location, GLsizei count, const GLfloat* v);
    virtual void Uniform1i(GLint location, GLint x);
    virtual void Uniform1iv(GLint location, GLsizei count, const GLint* v);
    virtual void Uniform2f(GLint location, GLfloat x, GLfloat y);
    virtual void Uniform2fv(GLint location, GLsizei count, const GLfloat* v);
    virtual void Uniform2i(GLint location, GLint x, GLint y);
    virtual void Uniform2iv(GLint location, GLsizei count, const GLint* v);
    virtual void Uniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z);
    virtual void Uniform3fv(GLint location, GLsizei count, const GLfloat* v);
    virtual void Uniform3i(GLint location, GLint x, GLint y, GLint z);
    virtual void Uniform3iv(GLint location, GLsizei count, const GLint* v);
    virtual void Uniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    virtual void Uniform4fv(GLint location, GLsizei count, const GLfloat* v);
    virtual void Uniform4i(GLint location, GLint x, GLint y, GLint z, GLint w);
    virtual void Uniform4iv(GLint location, GLsizei count, const GLint* v);
    virtual void UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    virtual void UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    virtual void UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    virtual void UseProgram(GLuint program);
    virtual void ValidateProgram(GLuint program);
    virtual void VertexAttrib1f(GLuint indx, GLfloat x);
    virtual void VertexAttrib1fv(GLuint indx, const GLfloat* values);
    virtual void VertexAttrib2f(GLuint indx, GLfloat x, GLfloat y);
    virtual void VertexAttrib2fv(GLuint indx, const GLfloat* values);
    virtual void VertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z);
    virtual void VertexAttrib3fv(GLuint indx, const GLfloat* values);
    virtual void VertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    virtual void VertexAttrib4fv(GLuint indx, const GLfloat* values);
    virtual void VertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr);
    virtual void Viewport(GLint x, GLint y, GLsizei width, GLsizei height);

protected:
    GLES2();
    virtual ~GLES2() = 0;
};

}

#endif
