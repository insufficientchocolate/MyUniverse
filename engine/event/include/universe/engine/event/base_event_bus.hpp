#include <algorithm>
#include <universe/engine/event/event_bus.hpp>
#include <vector>

namespace Universe::Event {
template <class T>
class BaseEventBus : public EventBus<T> {
 public:
  virtual void dispatch(const typename EventBus<T>::EventPointer e) const {
    informListeners(e);
  }

  virtual void registerListener(typename EventBus<T>::EventListenerType l) {
    listeners_.push_back(l);
  }

 protected:
  virtual void informListeners(
      const typename EventBus<T>::EventPointer e) const {
    std::for_each(listeners_.begin(), listeners_.end(),
                  [&e](typename EventBus<T>::EventListenerType l) { l(e); });
  }
  std::vector<typename EventBus<T>::EventListenerType> listeners_;
};
};  // namespace Universe::Event