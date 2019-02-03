#ifndef _UNIVERSE_EVENTS_HPP_
#define _UNIVERSE_EVENTS_HPP_
namespace Universe {
enum class EventType : Uint32 { RENDER_CRASH };

SDL_Event* newEvent(EventType& eventType);
};  // namespace Universe
#endif
