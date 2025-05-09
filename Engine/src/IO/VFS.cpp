#include "IO/VFS.h"

#include <memory>

#include "IO/NativeVFDirectory.h"
#include "Utils/Assert.h"
#include "Utils/Log.h"

namespace aero3d {

std::vector<std::unique_ptr<VFDirectory>> VFS::m_Dirs;
std::unique_ptr<VFDirectory> VFS::m_DefaultDir = std::make_unique<NativeVFDirectory>(L"", L"");

bool VFS::Init()
{
    LogMsg("VFS Initialize.");

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

        if (virtualPath.starts_with(mountPoint))
        {
            if (dir->FileExists(virtualPath))
            {
                return dir->OpenFile(virtualPath);
            }
        }
    }

    if (m_DefaultDir->FileExists(virtualPath))
    {
        return m_DefaultDir->OpenFile(virtualPath);
    }

    return nullptr;
}

} // namespace aero3d