#ifndef AERO3D_GRAPHICS_TEXTURE_H_
#define AERO3D_GRAPHICS_TEXTURE_H_

namespace aero3d {

class Texture
{
public:
    virtual ~Texture() = default;

    virtual void Bind(unsigned int slot) = 0;

};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_TEXTURE_H_