#include "Platform/OpenGL/OpenGLBuffer.h"

#include <glad/glad.h>

#include "Utils/Assert.h"

namespace aero3d {

///////////////////// Vertex Buffer //////////////////////

static GLenum ToGLType(ElementType type)
{
    switch (type)
    {
    case ElementType::FLOAT: return GL_FLOAT;
    case ElementType::FLOAT2: return GL_FLOAT;
    case ElementType::FLOAT3: return GL_FLOAT;
    case ElementType::FLOAT4: return GL_FLOAT;
    case ElementType::INT: return GL_INT;
    case ElementType::INT2: return GL_INT;
    case ElementType::INT3: return GL_INT;
    case ElementType::INT4: return GL_INT;
    case ElementType::BOOL: return GL_BOOL;
    case ElementType::MAT2: return GL_FLOAT;
    case ElementType::MAT3: return GL_FLOAT;
    case ElementType::MAT4: return GL_FLOAT;
    default: Assert(ERROR_INFO, false, "This ElementType doesnt exist !"); return GL_NONE;
    }
}

OpenGLVertexBuffer::OpenGLVertexBuffer(BufferLayout& layout, const void* data, size_t size)
    : m_VBO(0), m_VAO(0)
{
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    auto elements = layout.GetElements();
    for (size_t i = 0; i < elements.size(); ++i)
    {
        glVertexAttribPointer(static_cast<GLsizei>(i), elements[i].GetComponentCount(),
            static_cast<GLsizei>(ToGLType(elements[i].Type)),
            GL_FALSE, layout.GetStride(), (const void*)elements[i].Offset);
        glEnableVertexAttribArray(static_cast<GLuint>(i));
    }

    glBindVertexArray(0);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void OpenGLVertexBuffer::Bind()
{
    glBindVertexArray(m_VAO);
}

void OpenGLVertexBuffer::Unbind()
{
    glBindVertexArray(0);
}

void OpenGLVertexBuffer::SetData(const void* data, size_t size)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}

////////////////////// Index Buffer //////////////////////

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