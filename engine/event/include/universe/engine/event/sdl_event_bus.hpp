#include <SDL.h>
#include <memory>
#include <vector>
#include "base_event_bus.hpp"
#include "event_bus.hpp"

namespace Universe::Event {
class SDLEventBus : public BaseEventBus<Uint32>,
                    public std::enable_shared_from_this<SDLEventBus> {
 public:
  typedef std::shared_ptr<SDLEventBus> Pointer;
  static Pointer getInstance();

 private:
  SDLEventBus();
  static std::weak_ptr<SDLEventBus> instance;
};
};  // namespace Universe::Event
