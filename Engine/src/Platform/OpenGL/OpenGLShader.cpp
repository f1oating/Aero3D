#include "Platform/OpenGL/OpenGLShader.h"

#include <memory>

#include <glad/glad.h>

#include "IO/VFS.h"
#include "Utils/Log.h"

namespace aero3d {

OpenGLShader::OpenGLShader(std::string& vertexPath, std::string& pixelPath)
{
    std::string vertexShaderSource = VFS::ReadFile(vertexPath)->ReadString();
    std::string pixelShaderSource = VFS::ReadFile(pixelPath)->ReadString();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexSourceCStr = vertexShaderSource.c_str();
    glShaderSource(vertexShader, 1, &vertexSourceCStr, nullptr);
    glCompileShader(vertexShader);

    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
        char* infoLog = new char[logLength];
        glGetShaderInfoLog(vertexShader, logLength, &logLength, infoLog);
        LogErr(ERROR_INFO, "Vertex Shader Compilation Error: %s", infoLog);
        delete[] infoLog;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentSourceCStr = pixelShaderSource.c_str();
    glShaderSource(fragmentShader, 1, &fragmentSourceCStr, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
        char* infoLog = new char[logLength];
        glGetShaderInfoLog(fragmentShader, logLength, &logLength, infoLog);
        LogErr(ERROR_INFO, "Pixel Shader Compilation Error: %s", infoLog);
        delete[] infoLog;
    }

    m_Program = glCreateProgram();
    glAttachShader(m_Program, vertexShader);
    glAttachShader(m_Program, fragmentShader);
    glLinkProgram(m_Program);

    glGetProgramiv(m_Program, GL_LINK_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetProgramiv(m_Program, GL_INFO_LOG_LENGTH, &logLength);
        char* infoLog = new char[logLength];
        glGetProgramInfoLog(m_Program, logLength, &logLength, infoLog);
        LogErr(ERROR_INFO, "Program Linking Error: %s", infoLog);
        delete[] infoLog;
    }

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