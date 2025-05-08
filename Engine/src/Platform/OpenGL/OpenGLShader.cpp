#include "Platform/OpenGL/OpenGLShader.h"

#include <memory>

#include <glad/glad.h>

#include "IO/VFS.h"

namespace aero3d {

OpenGLShader::OpenGLShader(std::wstring& vertexPath, std::wstring& pixelPath)
{
    std::string vertexShaderSource = VFS::ReadFile(vertexPath)->ReadString();
    std::string pixelShaderSource = VFS::ReadFile(pixelPath)->ReadString();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexSourceCStr = vertexShaderSource.c_str();
    glShaderSource(vertexShader, 1, &vertexSourceCStr, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentSourceCStr = pixelShaderSource.c_str();
    glShaderSource(fragmentShader, 1, &fragmentSourceCStr, nullptr);
    glCompileShader(fragmentShader);

    m_Program = glCreateProgram();
    glAttachShader(m_Program, vertexShader);
    glAttachShader(m_Program, fragmentShader);
    glLinkProgram(m_Program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

OpenGLShader::~OpenGLShader()
{
    glDeleteProgram(m_Program);
}

void OpenGLShader::Bind()
{
    glUseProgram(m_Program);
}

void OpenGLShader::Unbind()
{
    glUseProgram(0);
}

} // namespace aero3d