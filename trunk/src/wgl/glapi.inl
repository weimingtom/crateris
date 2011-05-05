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


DEF_GLAPI0(void, AlphaFunc, (GLenum func, GLclampf ref))
DEF_GLAPI0(void, ClearColor, (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha))
DEF_GLAPI0(void, Color4f, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha))
DEF_GLAPI0(void, Fogf, (GLenum pname, GLfloat param))
DEF_GLAPI0(void, Fogfv, (GLenum pname, const GLfloat *params))
DEF_GLAPI0(void, GetFloatv, (GLenum pname, GLfloat *params))
DEF_GLAPI0(void, GetLightfv, (GLenum light, GLenum pname, GLfloat *params))
DEF_GLAPI0(void, GetMaterialfv, (GLenum face, GLenum pname, GLfloat *params))
DEF_GLAPI0(void, GetTexEnvfv, (GLenum env, GLenum pname, GLfloat *params))
DEF_GLAPI0(void, GetTexParameterfv, (GLenum target, GLenum pname, GLfloat *params))
DEF_GLAPI0(void, LightModelf, (GLenum pname, GLfloat param))
DEF_GLAPI0(void, LightModelfv, (GLenum pname, const GLfloat *params))
DEF_GLAPI0(void, Lightf, (GLenum light, GLenum pname, GLfloat param))
DEF_GLAPI0(void, Lightfv, (GLenum light, GLenum pname, const GLfloat *params))
DEF_GLAPI0(void, LineWidth, (GLfloat width))
DEF_GLAPI0(void, LoadMatrixf, (const GLfloat *m))
DEF_GLAPI0(void, Materialf, (GLenum face, GLenum pname, GLfloat param))
DEF_GLAPI0(void, Materialfv, (GLenum face, GLenum pname, const GLfloat *params))
DEF_GLAPI0(void, MultMatrixf, (const GLfloat *m))
DEF_GLAPI0(void, Normal3f, (GLfloat nx, GLfloat ny, GLfloat nz))
DEF_GLAPI0(void, PointSize, (GLfloat size))
DEF_GLAPI0(void, PolygonOffset, (GLfloat factor, GLfloat units))
DEF_GLAPI0(void, Rotatef, (GLfloat angle, GLfloat x, GLfloat y, GLfloat z))
DEF_GLAPI0(void, Scalef, (GLfloat x, GLfloat y, GLfloat z))
DEF_GLAPI0(void, TexEnvf, (GLenum target, GLenum pname, GLfloat param))
DEF_GLAPI0(void, TexEnvfv, (GLenum target, GLenum pname, const GLfloat *params))
DEF_GLAPI0(void, TexParameterf, (GLenum target, GLenum pname, GLfloat param))
DEF_GLAPI0(void, TexParameterfv, (GLenum target, GLenum pname, const GLfloat *params))
DEF_GLAPI0(void, Translatef, (GLfloat x, GLfloat y, GLfloat z))
DEF_GLAPI0(void, BindTexture, (GLenum target, GLuint texture))
DEF_GLAPI0(void, BlendFunc, (GLenum sfactor, GLenum dfactor))
DEF_GLAPI0(void, Clear, (GLbitfield mask))
DEF_GLAPI0(void, ClearStencil, (GLint s))
DEF_GLAPI0(void, Color4ub, (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha))
DEF_GLAPI0(void, ColorMask, (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha))
DEF_GLAPI0(void, ColorPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer))
DEF_GLAPI0(void, CopyTexImage2D,
        (GLenum target,
        GLint level,
        GLenum internalformat,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height,
        GLint border))
DEF_GLAPI0(void, CopyTexSubImage2D,
        (GLenum target,
        GLint level,
        GLint xoffset,
        GLint yoffset,
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height))
DEF_GLAPI0(void, CullFace, (GLenum mode))
DEF_GLAPI0(void, DeleteTextures, (GLsizei n, const GLuint *textures))
DEF_GLAPI0(void, DepthFunc, (GLenum func))
DEF_GLAPI0(void, DepthMask, (GLboolean flag))
DEF_GLAPI0(void, Disable, (GLenum cap))
DEF_GLAPI0(void, DisableClientState, (GLenum array))
DEF_GLAPI0(void, DrawArrays, (GLenum mode, GLint first, GLsizei count))
DEF_GLAPI0(void, DrawElements, (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices))
DEF_GLAPI0(void, Enable, (GLenum cap))
DEF_GLAPI0(void, EnableClientState, (GLenum array))
DEF_GLAPI0(void, Finish, (void))
DEF_GLAPI0(void, Flush, (void))
DEF_GLAPI0(void, FrontFace, (GLenum mode))
DEF_GLAPI0(void, GetBooleanv, (GLenum pname, GLboolean *params))
DEF_GLAPI0(void, GenTextures, (GLsizei n, GLuint *textures))
DEF_GLAPI0(GLenum, GetError, (void))
DEF_GLAPI0(void, GetIntegerv, (GLenum pname, GLint *params))
DEF_GLAPI0(void, GetPointerv, (GLenum pname, GLvoid **params))
DEF_GLAPI0(const GLubyte *, GetString, (GLenum name))
DEF_GLAPI0(void, GetTexEnviv, (GLenum env, GLenum pname, GLint *params))
DEF_GLAPI0(void, GetTexParameteriv, (GLenum target, GLenum pname, GLint *params))
DEF_GLAPI0(void, Hint, (GLenum target, GLenum mode))
DEF_GLAPI0(GLboolean, IsEnabled, (GLenum cap))
DEF_GLAPI0(GLboolean, IsTexture, (GLuint texture))
DEF_GLAPI0(void, LoadIdentity, (void))
DEF_GLAPI0(void, LogicOp, (GLenum opcode))
DEF_GLAPI0(void, MatrixMode, (GLenum mode))
DEF_GLAPI0(void, NormalPointer, (GLenum type, GLsizei stride, const GLvoid *pointer))
DEF_GLAPI0(void, PixelStorei, (GLenum pname, GLint param))
DEF_GLAPI0(void, PopMatrix, (void))
DEF_GLAPI0(void, PushMatrix, (void))
DEF_GLAPI0(void, ReadPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels))
DEF_GLAPI0(void, Scissor, (GLint x, GLint y, GLsizei width, GLsizei height))
DEF_GLAPI0(void, ShadeModel, (GLenum mode))
DEF_GLAPI0(void, StencilFunc, (GLenum func, GLint ref, GLuint mask))
DEF_GLAPI0(void, StencilMask, (GLuint mask))
DEF_GLAPI0(void, StencilOp, (GLenum fail, GLenum zfail, GLenum zpass))
DEF_GLAPI0(void, TexCoordPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer))
DEF_GLAPI0(void, TexEnvi, (GLenum target, GLenum pname, GLint param))
DEF_GLAPI0(void, TexEnviv, (GLenum target, GLenum pname, const GLint *params))
DEF_GLAPI0(void, TexImage2D,
        (GLenum target,
        GLint level,
        GLint internalformat,
        GLsizei width,
        GLsizei height,
        GLint border,
        GLenum format,
        GLenum type,
        const GLvoid *pixels))
DEF_GLAPI0(void, TexParameteri, (GLenum target, GLenum pname, GLint param))
DEF_GLAPI0(void, TexParameteriv, (GLenum target, GLenum pname, const GLint *params))
DEF_GLAPI0(void, TexSubImage2D,
        (GLenum target,
        GLint level,
        GLint xoffset,
        GLint yoffset,
        GLsizei width,
        GLsizei height,
        GLenum format,
        GLenum type,
        const GLvoid *pixels))
DEF_GLAPI0(void, VertexPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer))
DEF_GLAPI0(void, Viewport, (GLint x, GLint y, GLsizei width, GLsizei height))


DEF_GLAPI1(void, MultiTexCoord4f, (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)) // x-o
DEF_GLAPI1(void, PointParameterf, (GLenum pname, GLfloat param)) // x-o
DEF_GLAPI1(void, PointParameterfv, (GLenum pname, const GLfloat *params)) // x-o
DEF_GLAPI1(void, ActiveTexture, (GLenum texture)) // x-o
DEF_GLAPI1(void, BindBuffer, (GLenum target, GLuint buffer)) // x-o
DEF_GLAPI1(void, BufferData, (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)) // x-o
DEF_GLAPI1(void, BufferSubData, (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)) // x-o
DEF_GLAPI1(void, ClientActiveTexture, (GLenum texture)) // x-o
DEF_GLAPI1(void, CompressedTexImage2D,
        (GLenum target,
        GLint level,
        GLenum internalformat,
        GLsizei width,
        GLsizei height,
        GLint border,
        GLsizei imageSize,
        const GLvoid *data)) // x-o
DEF_GLAPI1(void, CompressedTexSubImage2D,
        (GLenum target,
        GLint level,
        GLint xoffset,
        GLint yoffset,
        GLsizei width,
        GLsizei height,
        GLenum format,
        GLsizei imageSize,
        const GLvoid *data)) // x-o
DEF_GLAPI1(void, DeleteBuffers, (GLsizei n, const GLuint *buffers)) // x-o
DEF_GLAPI1(void, GetBufferParameteriv, (GLenum target, GLenum pname, GLint *params)) // x-o
DEF_GLAPI1(void, GenBuffers, (GLsizei n, GLuint *buffers)) // x-o
DEF_GLAPI1(GLboolean, IsBuffer, (GLuint buffer)) // x-o
DEF_GLAPI1(void, SampleCoverage, (GLclampf value, GLboolean invert)) // x-o

DEF_GLAPI0(void, ClearDepth, (double depth)) // x-x
DEF_GLAPI0(void, ClipPlane, (GLenum plane, const double *equation)) // x-x
DEF_GLAPI0(void, DepthRange, (double zNear, double zFar)) // x-x
DEF_GLAPI0(void, Frustum, (double left, double right, double bottom, double top, double zNear, double zFar)) // x-x
DEF_GLAPI0(void, GetClipPlane, (GLenum plane, double *equation)) // x-x
DEF_GLAPI0(void, Ortho, (double left, double right, double bottom, double top, double zNear, double zFar)) // x-x
