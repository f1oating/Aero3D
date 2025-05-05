#ifndef AERO3D_IO_NATIVEVDIRECTORY_H_
#define AERO3D_IO_NATIVEVDIRECTORY_H_

#include "IO/VFDirectory.h"

namespace aero3d {

class NativeVFDirectory : public VFDirectory
{
public:
    NativeVFDirectory(const std::string& archivePath, const std::string& mountPoint);
    ~NativeVFDirectory();

    virtual std::unique_ptr<VFile> ReadFile() override;

    virtual std::vector<std::string> ListFiles() override;

private:
    std::string m_Path;

};

} // namespace aero3d

#endif // AERO3D_IO_NATIVEVDIRECTORY_H_