#ifndef AERO3D_IO_VFDIRECTORY_H_
#define AERO3D_IO_VFDIRECTORY_H_

#include <memory>
#include <vector>
#include <string>

#include "IO/VFile.h"

namespace aero3d {

enum class DirType
{
    NATIVE,
    PAK,
    ZIP
};

class VFDirectory
{
public:
    virtual ~VFDirectory() = default;
    
    virtual std::shared_ptr<VFile> OpenFile(std::string& path) = 0;

    virtual bool FileExists(std::string& path) = 0;

    const std::string& GetPath() const { return m_Path; }
    const std::string& GetMountPoint() const { return m_MountPoint; }

protected:
    std::string m_Path;
    std::string m_MountPoint;

};

} // namespace aero3d

#endif // AERO3D_IO_VFDIRECTORY_H_