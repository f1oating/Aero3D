#ifndef AERO3D_PLATFORM_OPENGL_OPENGLCONSTANTBUFFER_H_
#define AERO3D_PLATFORM_OPENGL_OPENGLCONSTANTBUFFER_H_

#include "Graphics/ConstantBuffer.h"

namespace aero3d {

class OpenGLConstantBuffer : public ConstantBuffer
{
public:
    OpenGLConstantBuffer(const void* data, size_t size);
    ~OpenGLConstantBuffer();

    virtual void Bind(unsigned int slot) override;

    virtual void SetData(const void* data, size_t size) override;

private:
    unsigned int m_CBO;

};

} // namespace aero3d

#endif // AERO3D_PLATFORM_OPENGL_OPENGLCONSTANTBUFFER_H_