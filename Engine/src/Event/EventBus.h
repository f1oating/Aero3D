#ifndef AERO3D_EVENTSYSTEM_EVENTBUS_H_
#define AERO3D_EVENTSYSTEM_EVENTBUS_H_

#include <vector>
#include <functional>
#include <unordered_map>
#include <typeindex>

#include "Event/Events.h"

namespace aero3d {

class EventBus
{
public:
    using EventHandler = std::function<void(Event&)>;

public:
    static bool Init();
    static void Shutdown();

    static void Subscribe(std::type_index type, EventHandler handler);
    static void Publish(Event& event);

private:
    static std::unordered_map<std::type_index, std::vector<std::function<void(Event&)>>> s_Listeners;

};

} // namespace aero3d

#endif // AERO3D_EVENTSYSTEM_EVENTBUS_H_