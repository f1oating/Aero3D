#include "IO/VFS.h"

#include "IO/NativeVFDirectory.h"

namespace aero3d {

std::vector<std::unique_ptr<VFDirectory>> VFS::m_Dirs;

void VFS::Mount(const std::wstring& path, const std::wstring& mountPoint )
{
    m_Dirs.emplace_back(std::make_unique<NativeVFDirectory>(path, mountPoint));
}

std::unique_ptr<VFile> VFS::ReadFile(const std::wstring& virtualPath)
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