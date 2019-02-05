#include <SDL.h>
#include "event_bus.hpp"
#include "abstract_event_bus.hpp"
#include <vector>
#include <memory>

namespace Universe::Event {
    class SDLEventBus: public AbstractEventBus<Uint32>, public std::enable_shared_from_this<SDLEventBus>
    {
        public:
            typedef std::shared_ptr<SDLEventBus> Pointer;
            static Pointer getInstance();
        private:
            SDLEventBus();
            static std::weak_ptr<SDLEventBus> instance;
    };
};
