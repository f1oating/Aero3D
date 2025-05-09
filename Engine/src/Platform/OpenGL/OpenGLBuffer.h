#ifndef AERO3D_PLATFORM_OPENGL_OPENGLBUFFER_H_
#define AERO3D_PLATFORM_OPENGL_OPENGLBUFFER_H_

#include "Graphics/Buffer.h"

namespace aero3d {

class OpenGLVertexBuffer : public VertexBuffer
{
public:
    OpenGLVertexBuffer(BufferLayout& layout, const void* data, size_t size);
    ~OpenGLVertexBuffer();

    virtual void Bind() override;
    virtual void Unbind() override;

    virtual void SetData(const void* data, size_t size) override;

private:
    unsigned int m_VBO;
    unsigned int m_VAO;

};

class OpenGLIndexBuffer : public IndexBuffer
{
public:
    OpenGLIndexBuffer(const void* data, size_t size, size_t count);
    ~OpenGLIndexBuffer();

    virtual void Bind() override;
    virtual void Unbind() override;

    virtual size_t GetIndexCount() override;

private:
    unsigned int m_IBO;
    size_t m_IndexCount;

};

} // namespace aero3d

#endif // AERO3D_PLATFORM_OPENGL_OPENGLBUFFER_H_