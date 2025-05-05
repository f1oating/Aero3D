#ifndef AERO3D_IO_VFS_H_
#define AERO3D_IO_VFS_H_

#include <string>
#include <map>
#include <memory>

#include "IO/VFDirectory.h"
#include "IO/VFile.h"

namespace aero3d {

class VFS {
public:
    static void Mount(const std::string& archivePath, const std::string& mountPoint = "/");

    static std::unique_ptr<VFile> ReadFile(const std::string& virtualPath);

private:
    std::map<std::string, std::unique_ptr<VFDirectory>> m_Dirs;

};

} // namespace aero3d

#endif // AERO3D_IO_VFS_H_