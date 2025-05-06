#include "IO/NativeVFile.h"

#include <windows.h>

namespace aero3d {

static std::wstring GetFileNameOnlyFromHandle(HANDLE hFile)
{
    wchar_t buffer[MAX_PATH];
    DWORD result = GetFinalPathNameByHandleW(
        hFile,
        buffer,
        MAX_PATH,
        FILE_NAME_NORMALIZED
    );

    if (result == 0 || result >= MAX_PATH)
        return L"";

    std::wstring fullPath(buffer);

    const std::wstring prefix = L"\\\\?\\";
    if (fullPath.starts_with(prefix))
        fullPath = fullPath.substr(prefix.length());

    size_t pos = fullPath.find_last_of(L"\\/");
    if (pos != std::wstring::npos)
        return fullPath.substr(pos + 1);
    else
        return fullPath;
}

NativeVFile::NativeVFile(void* handle)
    : m_Handle(handle)
{
    LARGE_INTEGER size;
    GetFileSizeEx(m_Handle, &size);
    m_Length = size.QuadPart;

    m_Name = GetFileNameOnlyFromHandle(handle);
}

NativeVFile::~NativeVFile()
{
    CloseHandle(m_Handle);
}

void NativeVFile::ReadBytes(void* buffer, size_t size, size_t start)
{
    LARGE_INTEGER li;
    li.QuadPart = static_cast<LONGLONG>(start);
    SetFilePointerEx(m_Handle, li, nullptr, FILE_BEGIN);

    ReadFile(m_Handle, buffer, size, nullptr, nullptr);
}

uint64_t NativeVFile::GetLength() const
{
    return m_Length;
}

std::wstring NativeVFile::GetName() const
{
    return m_Name;
}

} // namespace aero3d