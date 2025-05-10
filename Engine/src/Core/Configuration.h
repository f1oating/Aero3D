#ifndef AERO3D_CORE_CONFIGURATION_H_
#define AERO3D_CORE_CONFIGURATION_H_

#include <unordered_map>
#include <string>
#include <memory>

#include "IO/VFile.h"
#include "Graphics/RenderAPI.h"

namespace aero3d {

class Configuration
{
public:
    static bool Init();
    static void Shutdown();

    static std::string GetValue(std::string key);

private:
    static std::unordered_map<std::string, std::string> s_ConfigMap;
    static std::shared_ptr<VFile> s_ConfigFile;

};

} // namespace aero3d

#endif // AERO3D_CORE_CONFIGURATION_H_