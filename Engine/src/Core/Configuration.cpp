#include "Core/Configuration.h"

#include <unordered_map>
#include <string>
#include <sstream>

#include "IO/VFS.h"
#include "Utils/Log.h"

namespace aero3d {

    std::unordered_map<std::string, std::string> Configuration::m_ConfigMap;
    std::shared_ptr<VFile> Configuration::m_ConfigFile = nullptr;

    static std::unordered_map<std::string, std::string> parseKeyValueString(const std::string& input) {
        std::unordered_map<std::string, std::string> result;
        std::istringstream stream(input);
        std::string line;

        while (std::getline(stream, line)) {
            if (line.empty()) continue;

            std::string key, value;
            std::istringstream lineStream(line);

            if (std::getline(lineStream, key, '=') && std::getline(lineStream, value)) {
                result[key] = value;
            }
        }

        return result;
    }

    static std::string serializeKeyValueMap(const std::unordered_map<std::string, std::string>& map) {
        std::ostringstream stream;

        for (const auto& [key, value] : map) {
            stream << key << '=' << value << '\n';
        }

        return stream.str();
    }

    bool Configuration::Init()
    {
        LogMsg("Configuration Initialize.");

        m_ConfigFile = VFS::ReadFile("res/config.conf");
        m_ConfigMap = parseKeyValueString(m_ConfigFile->ReadString());

        return true;
    }

    void Configuration::Shutdown()
    {
        LogMsg("Configuration Shutdown.");

        std::string str = serializeKeyValueMap(m_ConfigMap);

        m_ConfigFile->Truncate();
        m_ConfigFile->WriteBytes((void*)str.c_str(), str.length());
    }

} // namespace aero3d