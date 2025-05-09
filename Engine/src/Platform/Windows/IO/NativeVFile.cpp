#include "IO/NativeVFile.h"

#include <windows.h>

namespace aero3d {

static const char* GetFileNameOnlyFromHandle(HANDLE hFile)
{
    char buffer[MAX_PATH];
    DWORD result = GetFinalPathNameByHandleA(
        hFile,
        buffer,
        MAX_PATH,
        FILE_NAME_NORMALIZED
    );

    if (result == 0 || result >= MAX_PATH)
        return "";

    const char* prefix = "\\\\?\\";
    size_t prefixLen = strlen(prefix);

    if (strncmp(buffer, prefix, prefixLen) == 0)
    {
        memmove(buffer, buffer + prefixLen, strlen(buffer + prefixLen) + 1);
    }

    const char* lastSlash = strrchr(buffer, '\\');
    const char* lastAltSlash = strrchr(buffer, '/');

    const char* fileName = lastSlash;
    if (!fileName || (lastAltSlash && lastAltSlash > lastSlash))
        fileName = lastAltSlash;

    if (fileName)
        return fileName + 1;
    else
        return buffer;
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

std::string NativeVFile::ReadString()
{
    std::string result(static_cast<size_t>(m_Length), '\0');

    LARGE_INTEGER li;
    li.QuadPart = 0;
    SetFilePointerEx(m_Handle, li, nullptr, FILE_BEGIN);

    DWORD bytesRead = 0;
    if (!ReadFile(m_Handle, result.data(), static_cast<DWORD>(m_Length), &bytesRead, nullptr) || bytesRead != m_Length)
        return "";

    return result;
}

uint64_t NativeVFile::GetLength() const
{
    return m_Length;
}

const char* NativeVFile::GetName() const
{
    return m_Name;
}

} // namespace aero3d