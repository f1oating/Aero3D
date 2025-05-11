#include "IO/VFS.h"

#include <memory>

#include "IO/NativeVFDirectory.h"
#include "Utils/Assert.h"
#include "Utils/Log.h"

namespace aero3d {

std::vector<std::unique_ptr<VFDirectory>> VFS::s_Dirs = {};
std::unique_ptr<VFDirectory> VFS::s_DefaultDir = std::make_unique<NativeVFDirectory>("", "");

bool VFS::Init()
{
    LogMsg("VFS Initialize.");

    return true;
}

void VFS::Shutdown()
{
    LogMsg("VFS Shutdown.");
}

void VFS::Mount(std::string& path, std::string& mountPoint, DirType type)
{
    switch (type)
    {
    case DirType::NATIVE: s_Dirs.emplace_back(std::make_unique<NativeVFDirectory>(path, mountPoint)); break;
    default: Assert(ERROR_INFO, false, "Unknown DirType!");
    }
}

std::shared_ptr<VFile> VFS::ReadFile(std::string& virtualPath)
{
    for (const auto& dir : s_Dirs)
    {
        std::string mountPoint = dir->GetMountPoint();

        if (virtualPath == mountPoint)
        {
            if (dir->FileExists(virtualPath))
            {
                return dir->OpenFile(virtualPath);
            }
        }
    }

    if (s_DefaultDir->FileExists(virtualPath))
    {
        return s_DefaultDir->OpenFile(virtualPath);
    }

    LogErr(ERROR_INFO, "File dont exist: %s", virtualPath);
    return nullptr;
}

} // namespace aero3d