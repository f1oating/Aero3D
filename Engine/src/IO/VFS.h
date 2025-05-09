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

    static void Mount(const std::wstring& path, const std::wstring& mountPoint = L"", DirType type = DirType::NATIVE);

    static std::shared_ptr<VFile> ReadFile(const std::wstring& virtualPath);

private:
    static std::vector<std::unique_ptr<VFDirectory>> m_Dirs;
    static std::unique_ptr<VFDirectory> m_DefaultDir;

};

} // namespace aero3d

#endif // AERO3D_IO_VFS_H_