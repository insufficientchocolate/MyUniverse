#ifndef _UNIVERSE_EVENT_BUS_HPP
#define _UNIVERSE_EVENT_BUS_HPP
#include <functional>
#include <memory>
#include <type_traits>
#include "event.hpp"

namespace Universe::Event {
template <class T>
class EventBus {
 public:
  typedef Event<T> EventType;
  typedef std::shared_ptr<const EventType> EventPointer;
  typedef std::function<void(EventPointer)> EventListenerType;
  virtual void dispatch(const EventPointer) const = 0;
  virtual void registerListener(EventListenerType callback) = 0;
};
};  // namespace Universe::Event
#endif
