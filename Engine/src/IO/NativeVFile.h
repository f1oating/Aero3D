#ifndef AERO3D_IO_NATIVEVFILE_H_
#define AERO3D_IO_NATIVEVFILE_H_

#include "IO/VFile.h"

namespace aero3d {

class NativeVFile : public VFile
{
public:
    NativeVFile(void* handle, std::string name, uint64_t pos, uint64_t length);
    ~NativeVFile();

    virtual void ReadBytes(void* buffer, size_t size) override;
    virtual void Seek(uint64_t pos) override;

};

} // namespace aero3d

#endif // AERO3D_IO_NATIVEVFILE_H_