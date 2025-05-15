#include "IO/NativeVFDirectory.h"

#include <Windows.h>
#include <memory>
#include <string.h>

#include "IO/NativeVFile.h"
#include "Utils/StringManip.h"
#include "Utils/Log.h"

#define A3D_RESOLVE_NATIVE_PATH(p) (m_MountPoint + p)

namespace aero3d {

NativeVFDirectory::NativeVFDirectory(std::string virtualPath, std::string mountPoint)
{
    m_VirtualPath = virtualPath;
    m_MountPoint = mountPoint;
}

NativeVFDirectory::~NativeVFDirectory()
{
}

std::shared_ptr<VFile> NativeVFDirectory::OpenFile(std::string& path)
{
    HANDLE fileHandle = CreateFileA(
        A3D_RESOLVE_NATIVE_PATH(path).c_str(),
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (!fileHandle || fileHandle == INVALID_HANDLE_VALUE)
        LogErr(ERROR_INFO, "Failed to open file: %s", path.c_str());

    return std::make_shared<NativeVFile>(fileHandle, path);
}

bool NativeVFDirectory::FileExists(std::string& path)
{
    DWORD attrs = GetFileAttributesA(A3D_RESOLVE_NATIVE_PATH(path).c_str());
    return (attrs != INVALID_FILE_ATTRIBUTES) && !(attrs & FILE_ATTRIBUTE_DIRECTORY);
}

} // namespace aero3d