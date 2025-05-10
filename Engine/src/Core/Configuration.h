#ifndef AERO3D_CORE_CONFIGURATION_H_
#define AERO3D_CORE_CONFIGURATION_H_

#include <map>
#include <string>
#include <memory>

#include "IO/VFile.h"
#include "Graphics/RenderAPI.h"

namespace aero3d {

class Configuration
{
public:
    Configuration();
    ~Configuration();

    void Open(const char* path);

    std::string GetValue(std::string key);

private:
    std::map<std::string, std::string> m_ConfigMap;
    std::shared_ptr<VFile> m_ConfigFile;

};

} // namespace aero3d

#endif // AERO3D_CORE_CONFIGURATION_H_