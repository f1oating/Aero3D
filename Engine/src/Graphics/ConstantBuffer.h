#ifndef AERO3D_GRAPHICS_CONSTANTBUFFER_H_
#define AERO3D_GRAPHICS_CONSTANTBUFFER_H_

namespace aero3d {

class ConstantBuffer
{
public:
    virtual ~ConstantBuffer() = default;

    virtual void Bind(unsigned int slot) = 0;

    virtual void SetData(const void* data, size_t size) = 0;

};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_CONSTANTBUFFER_H_