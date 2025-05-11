#ifndef AERO3D_IO_NATIVEVFILE_H_
#define AERO3D_IO_NATIVEVFILE_H_

#include <string>

#include "IO/VFile.h"

namespace aero3d {

class NativeVFile : public VFile
{
public:
    NativeVFile(void* handle);
    ~NativeVFile();

    virtual void ReadBytes(void* buffer, size_t size, size_t start = 0) override;
    virtual std::string ReadString() override;

    virtual void Truncate(size_t pos = 0) override;
    virtual void WriteBytes(void* data, size_t size, size_t start = 0) override;

    virtual void Load() override;
    virtual void Unload() override;

    virtual bool IsWritable() override;

    virtual void* GetData() override;

    virtual uint64_t GetLength() const override;
    virtual const std::string& GetName() const override;

private:
    uint64_t m_Length;
    std::string m_Name;
    void* m_Handle;
    void* m_Data;

};

} // namespace aero3d

#endif // AERO3D_IO_NATIVEVFILE_H_