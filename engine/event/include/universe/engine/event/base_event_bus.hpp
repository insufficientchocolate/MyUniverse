#include <algorithm>
#include <universe/engine/event/event_bus.hpp>
#include <vector>

namespace Universe::Event {
template <class T>
class BaseEventBus : public EventBus<T> {
 public:
  virtual void dispatch(
      const std::shared_ptr<const typename EventBus<T>::EventType> e) const {
    informListeners(e);
  }

  virtual void registerListener(typename EventBus<T>::EventListenerType l) {
    listeners_.push_back(l);
  }

 protected:
  virtual void informListeners(
      const std::shared_ptr<const typename EventBus<T>::EventType> e) const {
    std::for_each(listeners_.begin(), listeners_.end(),
                  [&e](typename EventBus<T>::EventListenerType l) { l(e); });
  }
  std::vector<typename EventBus<T>::EventListenerType> listeners_;
};
};  // namespace Universe::Event