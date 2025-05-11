#include "IO/NativeVFDirectory.h"

#include <Windows.h>
#include <memory>
#include <string.h>

#include "IO/NativeVFile.h"
#include "Utils/StringManip.h"
#include "Utils/Log.h"

namespace aero3d {

NativeVFDirectory::NativeVFDirectory(std::string path, std::string mountPoint)
{
    m_Path = path;
    m_MountPoint = mountPoint;
}

NativeVFDirectory::~NativeVFDirectory()
{
}

std::shared_ptr<VFile> NativeVFDirectory::OpenFile(std::string& path)
{
    std::string fileRelativePath = path.substr(m_MountPoint.size());
    std::string filePath = m_Path + fileRelativePath;

    HANDLE fileHandle = CreateFileA(
        filePath.c_str(),
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (fileHandle == INVALID_HANDLE_VALUE)
    {
        LogErr(ERROR_INFO, "Failed to open file: %s", path);
        return nullptr;
    }

    return std::make_shared<NativeVFile>(fileHandle);
}

bool NativeVFDirectory::FileExists(std::string& path)
{
    DWORD attrs = GetFileAttributesA(path.c_str());
    return (attrs != INVALID_FILE_ATTRIBUTES) && !(attrs & FILE_ATTRIBUTE_DIRECTORY);
}

} // namespace aero3d