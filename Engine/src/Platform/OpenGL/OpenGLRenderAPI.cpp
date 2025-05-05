#include "Platform/OpenGL/OpenGLRenderAPI.h"

#include <glad/glad.h>

#include "Utils/Log.h"
#include "Utils/Assert.h"

namespace aero3d {

static GLenum IndexTypeToGL(IndexBufferType type)
{
    switch (type)
    {
    case IndexBufferType::UNSIGNED_BYTE: return GL_UNSIGNED_BYTE;
    case IndexBufferType::UNSIGNED_SHORT: return GL_UNSIGNED_SHORT;
    case IndexBufferType::UNSIGNED_INT: return GL_UNSIGNED_INT;
    default: Assert("This IndexBufferType doesnt exist !", false);
    }
}

OpenGLRenderAPI::OpenGLRenderAPI()
{
}

OpenGLRenderAPI::~OpenGLRenderAPI()
{
}

bool OpenGLRenderAPI::Init()
{
    LogMsg("OpenGL Render API Initialize.");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);

    return true;
}

void OpenGLRenderAPI::Shutdown()
{
    LogMsg("OpenGL Render API Shutdown.");
}

void OpenGLRenderAPI::SetViewport(int x, int y, int width, int height)
{
    glViewport(x, y, width, height);
}

void OpenGLRenderAPI::SetClearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void OpenGLRenderAPI::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderAPI::Draw(std::shared_ptr<VertexBuffer> vb, size_t count)
{
    vb->Bind();
    glDrawArrays(GL_TRIANGLES, 0, count);
}

void OpenGLRenderAPI::DrawIndexed(std::shared_ptr<VertexBuffer> vb, std::shared_ptr<IndexBuffer> ib)
{
    vb->Bind();
    ib->Bind();
    glDrawElements(GL_TRIANGLES, ib->GetIndexCount(), IndexTypeToGL(ib->GetIndexBufferType()), nullptr);
}

} // namespace aero3d