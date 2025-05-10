#ifndef AERO3D_IO_NATIVEVDIRECTORY_H_
#define AERO3D_IO_NATIVEVDIRECTORY_H_

#include "IO/VFDirectory.h"

namespace aero3d {

class NativeVFDirectory : public VFDirectory
{
public:
    NativeVFDirectory(const char* path, const char* mountPoint);
    ~NativeVFDirectory();

    virtual std::shared_ptr<VFile> OpenFile(const char* path) override;

    virtual bool FileExists(const char* path) override;

};

} // namespace aero3d

#endif // AERO3D_IO_NATIVEVDIRECTORY_H_