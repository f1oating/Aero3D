#ifndef AERO3D_IO_VFDIRECTORY_H_
#define AERO3D_IO_VFDIRECTORY_H_

#include <memory>
#include <vector>
#include <string>

#include "IO/VFile.h"

namespace aero3d {

class VFDirectory
{
public:
    virtual ~VFDirectory() = default;
    
    virtual std::unique_ptr<VFile> ReadFile() = 0;

    virtual std::vector<std::string> ListFiles() = 0;

};

} // namespace aero3d

#endif // AERO3D_IO_VFDIRECTORY_H_