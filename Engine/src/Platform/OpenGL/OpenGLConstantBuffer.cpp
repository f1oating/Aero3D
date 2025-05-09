#include "Platform/OpenGL/OpenGLConstantBuffer.h"

#include <glad/glad.h>

namespace aero3d {

OpenGLConstantBuffer::OpenGLConstantBuffer(const void* data, size_t size)
    : m_CBO(0)
{
    glGenBuffers(1, &m_CBO);
    glBindBuffer(GL_UNIFORM_BUFFER, m_CBO);
    glBufferData(GL_UNIFORM_BUFFER, size, data, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

OpenGLConstantBuffer::~OpenGLConstantBuffer()
{
    glDeleteBuffers(1, &m_CBO);
}

void OpenGLConstantBuffer::Bind(unsigned int slot)
{
    glBindBufferBase(GL_UNIFORM_BUFFER, slot, m_CBO);
}

void OpenGLConstantBuffer::SetData(const void* data, size_t size)
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_CBO);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
    
} // namespace aero3d