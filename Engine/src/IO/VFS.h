#ifndef AERO3D_IO_VFS_H_
#define AERO3D_IO_VFS_H_

#include <string>
#include <vector>
#include <memory>

#include "IO/VFDirectory.h"
#include "IO/VFile.h"

namespace aero3d {

class VFS {
public:
    static bool Init();
    static void Shutdown();

    static void Mount(std::string& path, std::string& mounPoint, DirType type = DirType::NATIVE);

    static std::shared_ptr<VFile> ReadFile(std::string& virtualPath);

private:
    static std::vector<std::unique_ptr<VFDirectory>> s_Dirs;
    static std::unique_ptr<VFDirectory> s_DefaultDir;

};

} // namespace aero3d

#endif // AERO3D_IO_VFS_H_