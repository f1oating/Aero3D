#include "Core/Configuration.h"

#include <unordered_map>
#include <string>
#include <sstream>

#include "IO/VFS.h"
#include "Utils/Log.h"

namespace aero3d {

static std::map<std::string, std::string> parseKeyValueString(const std::string& input) {
    std::map<std::string, std::string> result;
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

static std::string serializeKeyValueMap(const std::map<std::string, std::string>& map) {
    std::ostringstream stream;

    for (const auto& [key, value] : map) {
        stream << key << '=' << value << '\n';
    }

    return stream.str();
}

Configuration::Configuration()
    : m_ConfigFile(nullptr)
{
}

Configuration::~Configuration()
{
    std::string str = serializeKeyValueMap(m_ConfigMap);

    m_ConfigFile->Truncate();
    m_ConfigFile->WriteBytes((void*)str.c_str(), str.length());
}

void Configuration::Open(std::string path)
{
    m_ConfigFile = VFS::ReadFile(path);
    m_ConfigMap = parseKeyValueString(m_ConfigFile->ReadString());
}

std::string Configuration::GetValue(std::string key)
{
    return m_ConfigMap.at(key);
}

} // namespace aero3d