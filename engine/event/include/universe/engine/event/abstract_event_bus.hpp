#include <universe/engine/event/event_bus.hpp>
#include <vector>
#include <algorithm>

namespace Universe::Event
{
    template<class T>
    class AbstractEventBus: public EventBus<T>
    {
        public:
            virtual void dispatch(const std::shared_ptr<const EventType> e) const
            {
                informListeners(e);
            }

            virtual void registerEventListener(EventListenerType l)
            {
                listeners_.push_back(l);
            }
        protected:
            virtual void informListeners(const std::shared_ptr<const EventType> e) const {
                std::for_each(listeners_.begin(),listeners_.end(), [&e](EventListenerType l) {
                    l(e);
                });
            }
            std::vector<EventListenerType> listeners_;
    };
};