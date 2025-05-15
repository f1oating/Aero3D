#include "Event/EventBus.h"

#include "Utils/Log.h"

namespace aero3d {

    std::unordered_map<std::type_index, std::vector<std::function<void(Event&)>>> EventBus::s_Listeners = {};

    bool EventBus::Init()
    {
        LogMsg("Event System Initialize.");
        return true;
    }

    void EventBus::Shutdown()
    {
        LogMsg("Event System Shutdown.");
    }

    void EventBus::Subscribe(std::type_index type, EventHandler handler)
    {
        s_Listeners[type].push_back(handler);
    }

    void EventBus::Publish(Event& event)
    {
        auto it = s_Listeners.find(typeid(event));
        if (it != s_Listeners.end()) {
            for (auto& handler : it->second) {
                handler(event);
            }
        }
    }

} // namespace aero3d