#ifndef AERO3D_PLATFORM_OPENGL_OPENGLTEXTURE_H_
#define AERO3D_PLATFORM_OPENGL_OPENGLTEXTURE_H_

#include <string>

#include "Graphics/Texture.h"

namespace aero3d {

class OpenGLTexture : public Texture
{
public:
    OpenGLTexture(std::string& path);
    ~OpenGLTexture();

    virtual void Bind(unsigned int slot) override;

private:
    unsigned int m_TextureID;

};

} // namespace aero3d

#endif // AERO3D_PLATFORM_OPENGL_OPENGLTEXTURE_H_