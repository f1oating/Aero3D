#ifndef AERO3D_GRAPHICS_BUFFER_H_
#define AERO3D_GRAPHICS_BUFFER_H_

#include <string>
#include <vector>

#include "Utils/API.h"
#include "Utils/Assert.h"

namespace aero3d {

enum class ElementType
{
    FLOAT, FLOAT2, FLOAT3, FLOAT4, INT, INT2, INT3, INT4,
    BOOL, MAT2, MAT3, MAT4
};

static int ElementTypeSize(ElementType type)
{
    switch (type)
    {
    case ElementType::FLOAT: return 4;
    case ElementType::FLOAT2: return 8;
    case ElementType::FLOAT3: return 12;
    case ElementType::FLOAT4: return 16;
    case ElementType::INT: return 4;
    case ElementType::INT2: return 8;
    case ElementType::INT3: return 12;
    case ElementType::INT4: return 16;
    case ElementType::BOOL: return 1;
    case ElementType::MAT2: return 16;
    case ElementType::MAT3: return 36;
    case ElementType::MAT4: return 64;
    default: Assert(ERROR_INFO, false, "This ElementType doesnt exist !");
    }
}

struct LayoutElement
{
    const char* Name;
    int Size;
    int Offset;
    ElementType Type;

    LayoutElement(const char* name, ElementType type)
        : Name(name), Type(type), Size(ElementTypeSize(type)), Offset(0) {}

    uint32_t GetComponentCount() const
    {
        switch (Type)
        {
        case ElementType::FLOAT: return 1;
        case ElementType::FLOAT2: return 2;
        case ElementType::FLOAT3: return 3;
        case ElementType::FLOAT4: return 4;
        case ElementType::INT: return 1;
        case ElementType::INT2: return 2;
        case ElementType::INT3: return 3;
        case ElementType::INT4: return 4;
        case ElementType::BOOL: return 1;
        case ElementType::MAT2: return 4;
        case ElementType::MAT3: return 9;
        case ElementType::MAT4: return 16;
        default: Assert(ERROR_INFO, false, "This ElementType doesnt exist !");
        }
        return 0;
    }

};

struct BufferLayout
{
public:
    BufferLayout(std::vector<LayoutElement>&& elements)
        : m_Elements(std::move(elements)), m_Stride(0)
    {
        for (LayoutElement& element : m_Elements)
        {
            element.Offset = m_Stride;
            m_Stride += element.Size;
        }
    }

    const std::vector<LayoutElement>& GetElements() const { return m_Elements; };
    int GetStride() const { return m_Stride; }

private:
    int m_Stride;
    std::vector<LayoutElement> m_Elements;
};

class A3D_API VertexBuffer
{
public:
    ~VertexBuffer() = default;

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

    virtual void SetData(const void* data, size_t size) = 0;

};

enum class IndexBufferType
{
    UNSIGNED_BYTE,
    UNSIGNED_SHORT,
    UNSIGNED_INT
};

class A3D_API IndexBuffer
{
public:
    IndexBuffer(IndexBufferType type = IndexBufferType::UNSIGNED_INT)
        : m_Type(type) {}
    ~IndexBuffer() = default;

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

    virtual size_t GetIndexCount() = 0;

    void SetIndexBufferType(IndexBufferType type) { m_Type = type; }
    IndexBufferType GetIndexBufferType() { return m_Type; }

protected:
    IndexBufferType m_Type;

};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_BUFFER_H_