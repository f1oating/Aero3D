#include "Platform/OpenGL/OpenGLIndexBuffer.h"

#include <glad/glad.h>

namespace aero3d {

    OpenGLIndexBuffer::OpenGLIndexBuffer(const void* data, size_t size, size_t count)
        : m_IBO(0), m_IndexCount(count)
    {
        glGenBuffers(1, &m_IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &m_IBO);
    }

    void OpenGLIndexBuffer::Bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
    }

    void OpenGLIndexBuffer::Unbind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    size_t OpenGLIndexBuffer::GetIndexCount()
    {
        return m_IndexCount;
    }

} // namespace aero3d