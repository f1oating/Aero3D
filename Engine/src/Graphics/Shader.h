#ifndef AERO3D_GRAPHICS_SHADER_H_
#define AERO3D_GRAPHICS_SHADER_H_

namespace aero3d {

class Shader
{
public:
    virtual ~Shader() = default;

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_SHADER_H_