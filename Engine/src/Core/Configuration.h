#ifndef AERO3D_CORE_CONFIGURATION_H_
#define AERO3D_CORE_CONFIGURATION_H_

#include <unordered_map>
#include <string>
#include <memory>

#include "IO/VFile.h"

namespace aero3d {

class Configuration
{
public:
    static bool Init();
    static void Shutdown();

private:
    static std::unordered_map<std::string, std::string> m_ConfigMap;
    static std::shared_ptr<VFile> m_ConfigFile;

};

} // namespace aero3d

#endif // AERO3D_CORE_CONFIGURATION_H_