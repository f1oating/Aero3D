#ifndef AERO3D_PLATFORM_OPENGL_OPENGLSHADER_H_
#define AERO3D_PLATFORM_OPENGL_OPENGLSHADER_H_

#include <string>

#include "Graphics/Shader.h"

namespace aero3d {

class OpenGLShader : public Shader
{
public:
    OpenGLShader(std::wstring& vertexPath, std::wstring& pixelPath);
    ~OpenGLShader();

    virtual void Bind() override;
    virtual void Unbind() override;

private:
    unsigned int m_Program;

};

} // namespace aero3d

#endif // AERO3D_PLATFORM_OPENGL_OPENGLSHADER_H_