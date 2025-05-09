#include "IO/NativeVFDirectory.h"

#include <Windows.h>
#include <memory>
#include <string.h>

#include "IO/NativeVFile.h"
#include "Utils/StringManip.h"

namespace aero3d {

NativeVFDirectory::NativeVFDirectory(const char* path, const char* mountPoint)
{
    m_Path = path;
    m_MountPoint = mountPoint;
}

NativeVFDirectory::~NativeVFDirectory()
{
}

std::shared_ptr<VFile> NativeVFDirectory::OpenFile(const char* path)
{
    const char* fileRelativePath = path + strlen(m_MountPoint);
    const char* filePath = ConcatStrings(m_Path, fileRelativePath);

    HANDLE fileHandle = CreateFileA(
        filePath,
        GENERIC_READ,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    return std::make_shared<NativeVFile>(fileHandle);
}

bool NativeVFDirectory::FileExists(const char* path)
{
    DWORD attrs = GetFileAttributesA(path);
    return (attrs != INVALID_FILE_ATTRIBUTES) && !(attrs & FILE_ATTRIBUTE_DIRECTORY);
}

} // namespace aero3d