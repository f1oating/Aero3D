#ifndef AERO3D_IO_VFDIRECTORY_H_
#define AERO3D_IO_VFDIRECTORY_H_

#include <memory>
#include <vector>
#include <string>

#include "IO/VFile.h"

namespace aero3d {

class VFDirectory
{
public:
    virtual ~VFDirectory() = default;
    
    virtual std::unique_ptr<VFile> OpenFile(std::wstring path) = 0;

    virtual std::vector<std::wstring> ListFiles() = 0;

    std::wstring GetPath() const { return m_Path; }
    std::wstring GetMountPoint() const { return m_MountPoint; }

protected:
    std::wstring m_Path;
    std::wstring m_MountPoint;

};

} // namespace aero3d

#endif // AERO3D_IO_VFDIRECTORY_H_