#ifndef AERO3D_GRAPHICS_RENDERCOMMAND_H_
#define AERO3D_GRAPHICS_RENDERCOMMAND_H_

#include <memory>

#include "Graphics/RenderAPI.h"

namespace aero3d {

    class RenderCommand
    {
    public:
        static bool Init();
        static void Shutdown();

        static void SetViewport(int x, int y, int width, int height);

        static bool SetClearColor(float r, float g, float b, float a);
        static void Clear();

        static void Draw(VertexBuffer vb);
        static void DrawIndexed(VertexBuffer vb, IndexBuffer ib);

    private:
        std::unique_ptr<RenderAPI> m_RenderAPI;

    };

} // namespace aero3d

#endif // AERO3D_GRAPHICS_RENDERCOMMAND_H_