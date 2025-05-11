#ifndef AERO3D_EVENTSYSTEM_EVENTS_EVENT_H_
#define AERO3D_EVENTSYSTEM_EVENTS_EVENT_H_

namespace aero3d {

class Event
{
public:
    virtual ~Event() = default;

};

class MyEvent : public Event {
public:
    MyEvent(int value) : value(value) {}

    int value;
};

} // namespace aero3d

#endif // AERO3D_EVENTSYSTEM_EVENTS_EVENT_H_