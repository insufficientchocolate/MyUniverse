#ifndef _UNIVERSE_ENGINE_EVENT_HPP_
#define _UNIVERSE_ENGINE_EVENT_HPP_
namespace Universe::Event {
template <class T>
class Event {
 public:
  T getType();
};
};  // namespace Universe::Event
#endif
