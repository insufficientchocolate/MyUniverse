#ifndef _UNIVERSE_SDL_CUSTOM_EVENT_TYPE_H_
#define _UNIVERSE_SDL_CUSTOM_EVENT_TYPE_H_
#include <SDL.h>

namespace Universe::Event {
class SDLCustomEventTypeAssigner {
 public:
  SDLCustomEventTypeAssigner() : type(SDL_RegisterEvents(1)) {}
  const Uint32 type;
};
};  // namespace Universe::Event
#endif