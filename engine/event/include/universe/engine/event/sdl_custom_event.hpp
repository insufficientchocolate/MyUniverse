#ifndef _UNIVERSE_EVENT_SDL_CUSTOM_EVENT_H_
#define _UNIVERSE_EVENT_SDL_CUSTOM_EVENT_H_
#include "event.hpp"
#include "sdl_custom_event_type_assigner.hpp"

namespace Universe {
namespace Event {
template <class D, class Assigner = SDLCustomEventTypeAssigner>
class SDLCustomEvent : public Event<Uint32> {
 public:
  Uint32 getType() const { return D::getSDLType(); }
  static Uint32 getSDLType() {
    static Assigner* eventType;
    if (eventType == nullptr) {
      eventType = new Assigner();
    }
    return eventType->type;
  };
};
};  // namespace Event
};  // namespace Universe
#endif