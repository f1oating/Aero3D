#ifndef AERO3D_PLATFORM_OPENGL_OPENGLINDEXBUFFER_H_
#define AERO3D_PLATFORM_OPENGL_OPENGLINDEXBUFFER_H_

#include "Graphics/Buffer.h"

namespace aero3d {

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

#endif // AERO3D_PLATFORM_OPENGL_OPENGLINDEXBUFFER_H_