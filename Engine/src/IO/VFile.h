#ifndef AERO3D_IO_VFILE_H_
#define AERO3D_IO_VFILE_H_

#include <string>

namespace aero3d {

class VFile
{
public:
    virtual ~VFile() = default;

    virtual void ReadBytes(void* buffer, size_t size) = 0;
    virtual void Seek(uint64_t pos) = 0;

    uint64_t GetPosition() { return m_Position; }
    uint64_t GetLength() { return m_Length; }
    std::string GetName() { return m_Name; }

protected:
    uint64_t m_Position;
    uint64_t m_Length;
    std::string m_Name;
    void* m_Handle;

};

} // namespace aero3d

#endif // AERO3D_IO_VFILE_H_