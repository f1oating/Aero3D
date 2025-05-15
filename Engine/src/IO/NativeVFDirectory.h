#ifndef AERO3D_IO_NATIVEVDIRECTORY_H_
#define AERO3D_IO_NATIVEVDIRECTORY_H_

#include "IO/VFDirectory.h"

namespace aero3d {

class NativeVFDirectory : public VFDirectory
{
public:
    NativeVFDirectory(std::string virtualPath, std::string mountPoint);
    ~NativeVFDirectory();

    virtual std::shared_ptr<VFile> OpenFile(std::string& path) override;

    virtual bool FileExists(std::string& path) override;

};

} // namespace aero3d

#endif // AERO3D_IO_NATIVEVDIRECTORY_H_