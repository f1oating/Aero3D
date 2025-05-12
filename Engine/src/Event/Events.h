#ifndef AERO3D_EVENT_EVENTS_H_
#define AERO3D_EVENT_EVENTS_H_

namespace aero3d {

class Event
{
public:
    virtual ~Event() = default;

};

class WindowResizeEvent : public Event {
public:
    WindowResizeEvent(int width, int height) 
        : m_Width(width), m_Height(height) {}

    int GetWidth() { return m_Width; }
    int GetHeight() { return m_Height; }

private:
    int m_Width;
    int m_Height;

};

} // namespace aero3d

#endif // AERO3D_EVENT_EVENTS_H_