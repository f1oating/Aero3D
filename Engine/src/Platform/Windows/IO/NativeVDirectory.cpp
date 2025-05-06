#include "IO/NativeVFDirectory.h"

#include <Windows.h>
#include <memory>

#include "IO/NativeVFile.h"

namespace aero3d {

NativeVFDirectory::NativeVFDirectory(const std::wstring& path, const std::wstring& mountPoint)
{
    m_Path = path;
    m_MountPoint = mountPoint;
}

NativeVFDirectory::~NativeVFDirectory()
{
}

std::unique_ptr<VFile> NativeVFDirectory::OpenFile(std::wstring path)
{
    std::wstring fileRelativePath = path.substr(m_MountPoint.length());
    std::wstring filePath = m_Path + fileRelativePath;

    HANDLE fileHandle = CreateFileW(
        filePath.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    return std::make_unique<NativeVFile>(fileHandle);
}

std::vector<std::wstring> NativeVFDirectory::ListFiles()
{
    std::vector<std::wstring> v;
    return v;
}

} // namespace aero3d