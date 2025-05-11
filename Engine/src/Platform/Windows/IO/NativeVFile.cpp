#include "IO/NativeVFile.h"

#define NOMINMAX
#include <windows.h>

#include "Utils/Log.h"

namespace aero3d {

static std::string GetFileNameOnlyFromHandle(HANDLE hFile)
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
    : m_Handle(handle), m_Data(nullptr), m_Length(0), m_Name(""), m_Opened(false)
{
    if (m_Handle && m_Handle != INVALID_HANDLE_VALUE) m_Opened = true;

    if (m_Opened)
    {
        LARGE_INTEGER size;
        if (GetFileSizeEx(m_Handle, &size)) {
            m_Length = size.QuadPart;
        }
        else {
            m_Length = 0;
        }

        m_Name = GetFileNameOnlyFromHandle(handle);
    }
}

NativeVFile::~NativeVFile()
{
    if (m_Handle && m_Handle != INVALID_HANDLE_VALUE)
        CloseHandle(m_Handle);

    if (m_Data) delete[] m_Data;
}

void NativeVFile::ReadBytes(void* buffer, size_t size, size_t start)
{
    if (!buffer)
    {
        LogErr(ERROR_INFO, "Buffer is nullptr in file: %s", m_Name.c_str());
        return;
    }

    if (start + size > m_Length)
    {
        LogErr(ERROR_INFO, "Size is bigger than length inf file: %s", m_Name.c_str());
        size = static_cast<size_t>(m_Length - start);
    }

    LARGE_INTEGER li;
    li.QuadPart = static_cast<LONGLONG>(start);
    SetFilePointerEx(m_Handle, li, nullptr, FILE_BEGIN);

    if (!ReadFile(m_Handle, buffer, static_cast<DWORD>(size), nullptr, nullptr))
        LogErr(ERROR_INFO, "Failed to read bytes from file: %s", m_Name.c_str());
}

std::string NativeVFile::ReadString()
{
    std::string result(static_cast<size_t>(m_Length), '\0');

    LARGE_INTEGER li;
    li.QuadPart = 0;
    if (!SetFilePointerEx(m_Handle, li, nullptr, FILE_BEGIN))
    {
        LogErr(ERROR_INFO, "Failed to set read pointer in file: %s", m_Name.c_str());
        return "";
    }

    DWORD bytesRead = 0;
    if (!ReadFile(m_Handle, result.data(), static_cast<DWORD>(m_Length), &bytesRead, nullptr) || bytesRead != m_Length)
    {
        LogErr(ERROR_INFO, "Failed to read string from file: %s", m_Name.c_str());
        return "";
    }

    return result;
}

void NativeVFile::Truncate(size_t pos)
{
    if (pos > static_cast<size_t>(std::numeric_limits<LONGLONG>::max()))
    {
        LogErr(ERROR_INFO, "Pos is bigger than maximum value in file: %s", m_Name.c_str());
        return;
    }

    LARGE_INTEGER li;
    li.QuadPart = static_cast<LONGLONG>(pos);
    if (!SetFilePointerEx(m_Handle, li, nullptr, FILE_BEGIN))
    {
        LogErr(ERROR_INFO, "Failed to set read pointer in file: %s", m_Name.c_str());
        return;
    }

    if (!SetEndOfFile(m_Handle))
    {
        LogErr(ERROR_INFO, "Failed to set EOF in file: %s", m_Name.c_str());
        return;
    }

    m_Length = pos;
}

void NativeVFile::WriteBytes(void* data, size_t size, size_t start)
{
    if (!data || size == 0)
    {
        LogErr(ERROR_INFO, "Data pointer or size is incorrect in file: %s", m_Name.c_str());
        return;
    }

    if (start > std::numeric_limits<uint64_t>::max() - size)
        LogErr(ERROR_INFO, "Pos is bigger than maximum value in file: %s", m_Name.c_str());
        return;

    LARGE_INTEGER li;
    li.QuadPart = static_cast<LONGLONG>(start);
    if (!SetFilePointerEx(m_Handle, li, nullptr, FILE_BEGIN))
    {
        LogErr(ERROR_INFO, "Failed to set read pointer in file: %s", m_Name.c_str());
        return;
    }

    DWORD bytesWritten = 0;
    if (!WriteFile(m_Handle, data, static_cast<DWORD>(size), &bytesWritten, nullptr))
    {
        LogErr(ERROR_INFO, "Failed to write bytes in file: %s", m_Name.c_str());
        return;
    }

    if (start + bytesWritten > m_Length) {
        m_Length = start + bytesWritten;
    }
}

void NativeVFile::Load()
{
    m_Data = new byte[m_Length];
    ReadBytes(m_Data, m_Length, 0);
}

void NativeVFile::Unload()
{
    delete m_Data;
    m_Data = nullptr;
}

bool NativeVFile::IsWritable()
{
    return true;
}

bool NativeVFile::IsOpened()
{
    return m_Opened;
}

void* NativeVFile::GetData()
{
    return m_Data;
}

uint64_t NativeVFile::GetLength() const
{
    return m_Length;
}

const std::string& NativeVFile::GetName() const
{
    return m_Name;
}

} // namespace aero3d