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

#include "WinGLES2.h"
#include <stdio.h>

// typedef func
#define DEF_GLAPI0(rettype, name, params)   typedef rettype (__stdcall *Func##name) params;
#define DEF_GLAPI1(rettype, name, params)   DEF_GLAPI0(rettype, name, params)
#define DEF_GLAPI2(rettype, name, params)   DEF_GLAPI0(rettype, name, params)
#include "gl2api.inl" // Define
#undef DEF_GLAPI0
#undef DEF_GLAPI1
#undef DEF_GLAPI2

typedef void (__stdcall *FuncClearDepth)(double depth);
typedef void (__stdcall *FuncDepthRange)(double zNear, double zFar);

struct FuncTable {
#define DEF_GLAPI0(rettype, name, params)   Func##name proxy_gl##name;
#define DEF_GLAPI1(rettype, name, params)   DEF_GLAPI0(rettype, name, params)
#define DEF_GLAPI2(rettype, name, params)   DEF_GLAPI0(rettype, name, params)
#include "gl2api.inl" // Define
#undef DEF_GLAPI0
#undef DEF_GLAPI1
#undef DEF_GLAPI2
    FuncClearDepth proxy_glClearDepth;
    FuncDepthRange proxy_glDepthRange;
};


#define CALL(name, exp) \
    ((((FuncTable*)func_table_)->proxy_gl##name) ? (((FuncTable*)func_table_)->proxy_gl##name exp) : (GLES2::name exp))

namespace crateris {

WinGLES2::WinGLES2()
: func_table_(0)
{
}

WinGLES2::~WinGLES2()
{
    if (func_table_) {
        free(func_table_);
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


#define DEF_GLAPI0(rettype, name, params)   \
    ((FuncTable*)func_table_)->proxy_gl##name = (Func##name)GetProcAddress(mod, "gl" #name); \
    ret = validate(((FuncTable*)func_table_)->proxy_gl##name, "gl" #name) && ret;

#define DEF_GLAPI1(rettype, name, params)   \
    ((FuncTable*)func_table_)->proxy_gl##name = (Func##name)wglGetProcAddress("gl" #name); \
    ret = validate(((FuncTable*)func_table_)->proxy_gl##name, "gl" #name) && ret;

bool WinGLES2::loadGLAPI(bool valid_es2_profile)
{
    bool ret = true;

    func_table_ = malloc(sizeof(FuncTable));

    if (!valid_es2_profile) {
        HMODULE mod = LoadLibraryA("opengl32.dll");

#define DEF_GLAPI2(rettype, name, params)   \
    ((FuncTable*)func_table_)->proxy_gl##name = 0;

#include "gl2api.inl"

        if (!((FuncTable*)func_table_)->proxy_glClearDepthf) {
            DEF_GLAPI0(void, ClearDepth, (double depth));
        }

        if (!((FuncTable*)func_table_)->proxy_glDepthRangef) {
            DEF_GLAPI0(void, DepthRange, (double zNear, double zFar));
        }

#undef DEF_GLAPI2

        module_ = mod;

    } else {
        HMODULE mod = LoadLibraryA("opengl32.dll");

        ((FuncTable*)func_table_)->proxy_glClearDepth = 0;
        ((FuncTable*)func_table_)->proxy_glDepthRange = 0;

#define DEF_GLAPI2(rettype, name, params)   DEF_GLAPI1(rettype, name, params)

#include "gl2api.inl"

#undef DEF_GLAPI2

        module_ = mod;
    }

    return ret;
}

#undef DEF_GLAPI0
#undef DEF_GLAPI1

void WinGLES2::ActiveTexture(GLenum texture)
{
    CALL(ActiveTexture, (texture));
}

void WinGLES2::AttachShader(GLuint program, GLuint shader)
{
    CALL(AttachShader, (program, shader));
}

void WinGLES2::BindAttribLocation(GLuint program, GLuint index, const GLchar* name)
{
    CALL(BindAttribLocation, (program, index, name));
}

void WinGLES2::BindBuffer(GLenum target, GLuint buffer)
{
    CALL(BindBuffer, (target, buffer));
}

void WinGLES2::BindFramebuffer(GLenum target, GLuint framebuffer)
{
    CALL(BindFramebuffer, (target, framebuffer));
}

void WinGLES2::BindRenderbuffer(GLenum target, GLuint renderbuffer)
{
    CALL(BindRenderbuffer, (target, renderbuffer));
}

void WinGLES2::BindTexture(GLenum target, GLuint texture)
{
    CALL(BindTexture, (target, texture));
}

void WinGLES2::BlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    CALL(BlendColor, (red, green, blue, alpha));
}

void WinGLES2::BlendEquation( GLenum mode )
{
    CALL(BlendEquation, (mode));
}

void WinGLES2::BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    CALL(BlendEquationSeparate, (modeRGB, modeAlpha));
}

void WinGLES2::BlendFunc(GLenum sfactor, GLenum dfactor)
{
    CALL(BlendFunc, (sfactor, dfactor));
}

void WinGLES2::BlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    CALL(BlendFuncSeparate, (srcRGB, dstRGB, srcAlpha, dstAlpha));
}

void WinGLES2::BufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
{
    CALL(BufferData, (target, size, data, usage));
}

void WinGLES2::BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data)
{
    CALL(BufferSubData, (target, offset, size, data));
}

GLenum WinGLES2::CheckFramebufferStatus(GLenum target)
{
    return CALL(CheckFramebufferStatus, (target));
}

void WinGLES2::Clear(GLbitfield mask)
{
    CALL(Clear, (mask));
}

void WinGLES2::ClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    CALL(ClearColor, (red, green, blue, alpha));
}

void WinGLES2::ClearDepthf(GLclampf depth)
{
    if (((FuncTable*)func_table_)->proxy_glClearDepthf) {
        CALL(ClearDepthf, (depth));
    } else {
        CALL(ClearDepth, (depth));
    }
}

void WinGLES2::ClearStencil(GLint s)
{
    CALL(ClearStencil, (s));
}

void WinGLES2::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    CALL(ColorMask, (red, green, blue, alpha));
}

void WinGLES2::CompileShader(GLuint shader)
{
    CALL(CompileShader, (shader));
}

void WinGLES2::CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data)
{
    CALL(CompressedTexImage2D, (target, level, internalformat, width, height, border, imageSize, data));
}

void WinGLES2::CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data)
{
    CALL(CompressedTexSubImage2D, (target, level, xoffset, yoffset, width, height, format, imageSize, data));
}

void WinGLES2::CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    CALL(CopyTexImage2D, (target, level, internalformat, x, y, width, height, border));
}

void WinGLES2::CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    CALL(CopyTexSubImage2D, (target, level, xoffset, yoffset, x, y, width, height));
}

GLuint WinGLES2::CreateProgram(void)
{
    return CALL(CreateProgram, ());
}

GLuint WinGLES2::CreateShader(GLenum type)
{
    return CALL(CreateShader, (type));
}

void WinGLES2::CullFace(GLenum mode)
{
    CALL(CullFace, (mode));
}

void WinGLES2::DeleteBuffers(GLsizei n, const GLuint* buffers)
{
    CALL(DeleteBuffers, (n, buffers));
}

void WinGLES2::DeleteFramebuffers(GLsizei n, const GLuint* framebuffers)
{
    CALL(DeleteFramebuffers, (n, framebuffers));
}

void WinGLES2::DeleteProgram(GLuint program)
{
    CALL(DeleteProgram, (program));
}

void WinGLES2::DeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers)
{
    CALL(DeleteRenderbuffers, (n, renderbuffers));
}

void WinGLES2::DeleteShader(GLuint shader)
{
    CALL(DeleteShader, (shader));
}

void WinGLES2::DeleteTextures(GLsizei n, const GLuint* textures)
{
    CALL(DeleteTextures, (n, textures));
}

void WinGLES2::DepthFunc(GLenum func)
{
    CALL(DepthFunc, (func));
}

void WinGLES2::DepthMask(GLboolean flag)
{
    CALL(DepthMask, (flag));
}

void WinGLES2::DepthRangef(GLclampf zNear, GLclampf zFar)
{
    if (((FuncTable*)func_table_)->proxy_glDepthRangef) {
        CALL(DepthRangef, (zNear, zFar));
    } else {
        CALL(DepthRange, (zNear, zFar));
    }
}

void WinGLES2::DetachShader(GLuint program, GLuint shader)
{
    CALL(DetachShader, (program, shader));
}

void WinGLES2::Disable(GLenum cap)
{
    CALL(Disable, (cap));
}

void WinGLES2::DisableVertexAttribArray(GLuint index)
{
    CALL(DisableVertexAttribArray, (index));
}

void WinGLES2::DrawArrays(GLenum mode, GLint first, GLsizei count)
{
    CALL(DrawArrays, (mode, first, count));
}

void WinGLES2::DrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices)
{
    CALL(DrawElements, (mode, count, type, indices));
}

void WinGLES2::Enable(GLenum cap)
{
    CALL(Enable, (cap));
}

void WinGLES2::EnableVertexAttribArray(GLuint index)
{
    CALL(EnableVertexAttribArray, (index));
}

void WinGLES2::Finish(void)
{
    CALL(Finish, ());
}

void WinGLES2::Flush(void)
{
    CALL(Flush, ());
}

void WinGLES2::FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    CALL(FramebufferRenderbuffer, (target, attachment, renderbuffertarget, renderbuffer));
}

void WinGLES2::FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    CALL(FramebufferTexture2D, (target, attachment, textarget, texture, level));
}

void WinGLES2::FrontFace(GLenum mode)
{
    CALL(FrontFace, (mode));
}

void WinGLES2::GenBuffers(GLsizei n, GLuint* buffers)
{
    CALL(GenBuffers, (n, buffers));
}

void WinGLES2::GenerateMipmap(GLenum target)
{
    CALL(GenerateMipmap, (target));
}

void WinGLES2::GenFramebuffers(GLsizei n, GLuint* framebuffers)
{
    CALL(GenFramebuffers, (n, framebuffers));
}

void WinGLES2::GenRenderbuffers(GLsizei n, GLuint* renderbuffers)
{
    CALL(GenRenderbuffers, (n, renderbuffers));
}

void WinGLES2::GenTextures(GLsizei n, GLuint* textures)
{
    CALL(GenTextures, (n, textures));
}

void WinGLES2::GetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name)
{
    CALL(GetActiveAttrib, (program, index, bufsize, length, size, type, name));
}

void WinGLES2::GetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name)
{
    CALL(GetActiveUniform, (program, index, bufsize, length, size, type, name));
}

void WinGLES2::GetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)
{
    CALL(GetAttachedShaders, (program, maxcount, count, shaders));
}

GLint WinGLES2::GetAttribLocation(GLuint program, const GLchar* name)
{
    return CALL(GetAttribLocation, (program, name));
}

void WinGLES2::GetBooleanv(GLenum pname, GLboolean* params)
{
    CALL(GetBooleanv, (pname, params));
}

void WinGLES2::GetBufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    CALL(GetBufferParameteriv, (target, pname, params));
}

GLenum WinGLES2::GetError(void)
{
    return CALL(GetError, ());
}

void WinGLES2::GetFloatv(GLenum pname, GLfloat* params)
{
    CALL(GetFloatv, (pname, params));
}

void WinGLES2::GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params)
{
    CALL(GetFramebufferAttachmentParameteriv, (target, attachment, pname, params));
}

void WinGLES2::GetIntegerv(GLenum pname, GLint* params)
{
    CALL(GetIntegerv, (pname, params));
}

void WinGLES2::GetProgramiv(GLuint program, GLenum pname, GLint* params)
{
    CALL(GetProgramiv, (program, pname, params));
}

void WinGLES2::GetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    CALL(GetProgramInfoLog, (program, bufsize, length, infolog));
}

void WinGLES2::GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    CALL(GetRenderbufferParameteriv, (target, pname, params));
}

void WinGLES2::GetShaderiv(GLuint shader, GLenum pname, GLint* params)
{
    CALL(GetShaderiv, (shader, pname, params));
}

void WinGLES2::GetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    CALL(GetShaderInfoLog, (shader, bufsize, length, infolog));
}

void WinGLES2::GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision)
{
    CALL(GetShaderPrecisionFormat, (shadertype, precisiontype, range, precision));
}

void WinGLES2::GetShaderSource(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source)
{
    CALL(GetShaderSource, (shader, bufsize, length, source));
}

const GLubyte* WinGLES2::GetString(GLenum name)
{
    return CALL(GetString, (name));
}

void WinGLES2::GetTexParameterfv(GLenum target, GLenum pname, GLfloat* params)
{
    CALL(GetTexParameterfv, (target, pname, params));
}

void WinGLES2::GetTexParameteriv(GLenum target, GLenum pname, GLint* params)
{
    CALL(GetTexParameteriv, (target, pname, params));
}

void WinGLES2::GetUniformfv(GLuint program, GLint location, GLfloat* params)
{
    CALL(GetUniformfv, (program, location, params));
}

void WinGLES2::GetUniformiv(GLuint program, GLint location, GLint* params)
{
    CALL(GetUniformiv, (program, location, params));
}

GLint WinGLES2::GetUniformLocation(GLuint program, const GLchar* name)
{
    return CALL(GetUniformLocation, (program, name));
}

void WinGLES2::GetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params)
{
    CALL(GetVertexAttribfv, (index, pname, params));
}

void WinGLES2::GetVertexAttribiv(GLuint index, GLenum pname, GLint* params)
{
    CALL(GetVertexAttribiv, (index, pname, params));
}

void WinGLES2::GetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid** pointer)
{
    CALL(GetVertexAttribPointerv, (index, pname, pointer));
}

void WinGLES2::Hint(GLenum target, GLenum mode)
{
    CALL(Hint, (target, mode));
}

GLboolean WinGLES2::IsBuffer(GLuint buffer)
{
    return CALL(IsBuffer, (buffer));
}

GLboolean WinGLES2::IsEnabled(GLenum cap)
{
    return CALL(IsEnabled, (cap));
}

GLboolean WinGLES2::IsFramebuffer(GLuint framebuffer)
{
    return CALL(IsFramebuffer, (framebuffer));
}

GLboolean WinGLES2::IsProgram(GLuint program)
{
    return CALL(IsProgram, (program));
}

GLboolean WinGLES2::IsRenderbuffer(GLuint renderbuffer)
{
    return CALL(IsRenderbuffer, (renderbuffer));
}

GLboolean WinGLES2::IsShader(GLuint shader)
{
    return CALL(IsShader, (shader));
}

GLboolean WinGLES2::IsTexture(GLuint texture)
{
    return CALL(IsTexture, (texture));
}

void WinGLES2::LineWidth(GLfloat width)
{
    CALL(LineWidth, (width));
}

void WinGLES2::LinkProgram(GLuint program)
{
    CALL(LinkProgram, (program));
}

void WinGLES2::PixelStorei(GLenum pname, GLint param)
{
    CALL(PixelStorei, (pname, param));
}

void WinGLES2::PolygonOffset(GLfloat factor, GLfloat units)
{
    CALL(PolygonOffset, (factor, units));
}

void WinGLES2::ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels)
{
    CALL(ReadPixels, (x, y, width, height, format, type, pixels));
}

void WinGLES2::ReleaseShaderCompiler(void)
{
    CALL(ReleaseShaderCompiler, ());
}

void WinGLES2::RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    CALL(RenderbufferStorage, (target, internalformat, width, height));
}

void WinGLES2::SampleCoverage(GLclampf value, GLboolean invert)
{
    CALL(SampleCoverage, (value, invert));
}

void WinGLES2::Scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    CALL(Scissor, (x, y, width, height));
}

void WinGLES2::ShaderBinary(GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length)
{
    CALL(ShaderBinary, (n, shaders, binaryformat, binary, length));
}

void WinGLES2::ShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length)
{
    CALL(ShaderSource, (shader, count, string, length));
}

void WinGLES2::StencilFunc(GLenum func, GLint ref, GLuint mask)
{
    CALL(StencilFunc, (func, ref, mask));
}

void WinGLES2::StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    CALL(StencilFuncSeparate, (face, func, ref, mask));
}

void WinGLES2::StencilMask(GLuint mask)
{
    CALL(StencilMask, (mask));
}

void WinGLES2::StencilMaskSeparate(GLenum face, GLuint mask)
{
    CALL(StencilMaskSeparate, (face, mask));
}

void WinGLES2::StencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    CALL(StencilOp, (fail, zfail, zpass));
}

void WinGLES2::StencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    CALL(StencilOpSeparate, (face, fail, zfail, zpass));
}

void WinGLES2::TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels)
{
    CALL(TexImage2D, (target, level, internalformat, width, height, border, format, type, pixels));
}

void WinGLES2::TexParameterf(GLenum target, GLenum pname, GLfloat param)
{
    CALL(TexParameterf, (target, pname, param));
}

void WinGLES2::TexParameterfv(GLenum target, GLenum pname, const GLfloat* params)
{
    CALL(TexParameterfv, (target, pname, params));
}

void WinGLES2::TexParameteri(GLenum target, GLenum pname, GLint param)
{
    CALL(TexParameteri, (target, pname, param));
}

void WinGLES2::TexParameteriv(GLenum target, GLenum pname, const GLint* params)
{
    CALL(TexParameteriv, (target, pname, params));
}

void WinGLES2::TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels)
{
    CALL(TexSubImage2D, (target, level, xoffset, yoffset, width, height, format, type, pixels));
}

void WinGLES2::Uniform1f(GLint location, GLfloat x)
{
    CALL(Uniform1f, (location, x));
}

void WinGLES2::Uniform1fv(GLint location, GLsizei count, const GLfloat* v)
{
    CALL(Uniform1fv, (location, count, v));
}

void WinGLES2::Uniform1i(GLint location, GLint x)
{
    CALL(Uniform1i, (location, x));
}

void WinGLES2::Uniform1iv(GLint location, GLsizei count, const GLint* v)
{
    CALL(Uniform1iv, (location, count, v));
}

void WinGLES2::Uniform2f(GLint location, GLfloat x, GLfloat y)
{
    CALL(Uniform2f, (location, x, y));
}

void WinGLES2::Uniform2fv(GLint location, GLsizei count, const GLfloat* v)
{
    CALL(Uniform2fv, (location, count, v));
}

void WinGLES2::Uniform2i(GLint location, GLint x, GLint y)
{
    CALL(Uniform2i, (location, x, y));
}

void WinGLES2::Uniform2iv(GLint location, GLsizei count, const GLint* v)
{
    CALL(Uniform2iv, (location, count, v));
}

void WinGLES2::Uniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    CALL(Uniform3f, (location, x, y, z));
}

void WinGLES2::Uniform3fv(GLint location, GLsizei count, const GLfloat* v)
{
    CALL(Uniform3fv, (location, count, v));
}

void WinGLES2::Uniform3i(GLint location, GLint x, GLint y, GLint z)
{
    CALL(Uniform3i, (location, x, y, z));
}

void WinGLES2::Uniform3iv(GLint location, GLsizei count, const GLint* v)
{
    CALL(Uniform3iv, (location, count, v));
}

void WinGLES2::Uniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    CALL(Uniform4f, (location, x, y, z, w));
}

void WinGLES2::Uniform4fv(GLint location, GLsizei count, const GLfloat* v)
{
    CALL(Uniform4fv, (location, count, v));
}

void WinGLES2::Uniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)
{
    CALL(Uniform4i, (location, x, y, z, w));
}

void WinGLES2::Uniform4iv(GLint location, GLsizei count, const GLint* v)
{
    CALL(Uniform4iv, (location, count, v));
}

void WinGLES2::UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    CALL(UniformMatrix2fv, (location, count, transpose, value));
}

void WinGLES2::UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    CALL(UniformMatrix3fv, (location, count, transpose, value));
}

void WinGLES2::UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    CALL(UniformMatrix4fv, (location, count, transpose, value));
}

void WinGLES2::UseProgram(GLuint program)
{
    CALL(UseProgram, (program));
}

void WinGLES2::ValidateProgram(GLuint program)
{
    CALL(ValidateProgram, (program));
}

void WinGLES2::VertexAttrib1f(GLuint indx, GLfloat x)
{
    CALL(VertexAttrib1f, (indx, x));
}

void WinGLES2::VertexAttrib1fv(GLuint indx, const GLfloat* values)
{
    CALL(VertexAttrib1fv, (indx, values));
}

void WinGLES2::VertexAttrib2f(GLuint indx, GLfloat x, GLfloat y)
{
    CALL(VertexAttrib2f, (indx, x, y));
}

void WinGLES2::VertexAttrib2fv(GLuint indx, const GLfloat* values)
{
    CALL(VertexAttrib2fv, (indx, values));
}

void WinGLES2::VertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    CALL(VertexAttrib3f, (indx, x, y, z));
}

void WinGLES2::VertexAttrib3fv(GLuint indx, const GLfloat* values)
{
    CALL(VertexAttrib3fv, (indx, values));
}

void WinGLES2::VertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    CALL(VertexAttrib4f, (indx, x, y, z, w));
}

void WinGLES2::VertexAttrib4fv(GLuint indx, const GLfloat* values)
{
    CALL(VertexAttrib4fv, (indx, values));
}

void WinGLES2::VertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr)
{
    CALL(VertexAttribPointer, (indx, size, type, normalized, stride, ptr));
}

void WinGLES2::Viewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    CALL(Viewport, (x, y, width, height));
}

}

