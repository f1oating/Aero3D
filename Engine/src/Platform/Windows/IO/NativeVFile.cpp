#include "IO/NativeVFile.h"

#include <windows.h>

namespace aero3d {

NativeVFile::NativeVFile(void* handle, std::string name, uint64_t pos, uint64_t length)
{
    m_Name = name;
    m_Position = pos;
    m_Length = length;
    m_Handle = handle;
}

NativeVFile::~NativeVFile()
{
    CloseHandle(m_Handle);
}

void NativeVFile::ReadBytes(void* buffer, size_t size)
{
    ReadFile(m_Handle, buffer, size, nullptr, nullptr);
}

void NativeVFile::Seek(uint64_t pos)
{
    LARGE_INTEGER liOffset;
    liOffset.QuadPart = static_cast<LONGLONG>(pos);
    SetFilePointerEx(m_Handle, liOffset, nullptr, FILE_BEGIN
    );
}

} // namespace aero3d