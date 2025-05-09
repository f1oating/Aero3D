#ifndef AERO3D_IO_NATIVEVDIRECTORY_H_
#define AERO3D_IO_NATIVEVDIRECTORY_H_

#include "IO/VFDirectory.h"

namespace aero3d {

class NativeVFDirectory : public VFDirectory
{
public:
    NativeVFDirectory(const std::wstring& path, const std::wstring& mountPoint);
    ~NativeVFDirectory();

    virtual std::shared_ptr<VFile> OpenFile(std::wstring path) override;

    virtual bool FileExists(std::wstring path) override;

};

} // namespace aero3d

#endif // AERO3D_IO_NATIVEVDIRECTORY_H_