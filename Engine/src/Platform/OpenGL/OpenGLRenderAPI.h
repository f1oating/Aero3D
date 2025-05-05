#ifndef AERO3D_PLATFORM_OPENGL_OPENGLRENDERAPI_H_
#define AERO3D_PLATFORM_OPENGL_OPENGLRENDERAPI_H_

#include "Graphics/RenderAPI.h"

namespace aero3d {

class OpenGLRenderAPI : public RenderAPI
{
public:
    OpenGLRenderAPI();
    ~OpenGLRenderAPI();

    virtual bool Init() override;
    virtual void Shutdown() override;

    virtual void SetViewport(int x, int y, int width, int height) override;

    virtual void SetClearColor(float r, float g, float b, float a) override;
    virtual void Clear() override;

    virtual void Draw(std::shared_ptr<VertexBuffer> vb, size_t count) override;
    virtual void DrawIndexed(std::shared_ptr<VertexBuffer> vb, std::shared_ptr<IndexBuffer> ib) override;

};

} // namespace aero3d

#endif // AERO3D_PLATFORM_OPENGL_OPENGLRENDERAPI_H_