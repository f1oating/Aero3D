#include "IO/VFS.h"

#include "IO/NativeVFDirectory.h"
#include "Utils/Assert.h"
#include "Utils/Log.h"

namespace aero3d {

std::vector<std::unique_ptr<VFDirectory>> VFS::m_Dirs;

bool VFS::Init()
{
    LogMsg("VFS Initialize.");
    Mount(L"", L"", DirType::NATIVE);

    return true;
}

void VFS::Shutdown()
{
    LogMsg("VFS Shutdown.");
}

void VFS::Mount(const std::wstring& path, const std::wstring& mountPoint, DirType type)
{
    switch (type)
    {
    case DirType::NATIVE: m_Dirs.emplace_back(std::make_unique<NativeVFDirectory>(path, mountPoint)); break;
    default: Assert("Unknown DirType!", false);
    }
}

std::shared_ptr<VFile> VFS::ReadFile(const std::wstring& virtualPath)
{
    for (const auto& dir : m_Dirs)
    {
        const std::wstring& mountPoint = dir->GetMountPoint();

        if (virtualPath == mountPoint || virtualPath.starts_with(mountPoint))
        {
            return dir->OpenFile(virtualPath);
        }
    }

    return nullptr;
}

} // namespace aero3d