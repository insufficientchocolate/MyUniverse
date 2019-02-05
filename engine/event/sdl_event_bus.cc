#include <universe/engine/event/sdl_event_bus.hpp>

namespace Universe::Event {
void SDLEventBus::dispatch(
    const typename BaseEventBus<Uint32>::EventPointer e) const {
  SDL_Event payload;
  payload.type = e->getType();
  SDL_PushEvent(&payload);
}
}  // namespace Universe::Event
