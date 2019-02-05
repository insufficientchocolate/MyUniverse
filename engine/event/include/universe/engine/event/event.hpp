#ifndef _UNIVERSE_ENGINE_EVENT_HPP_
#define _UNIVERSE_ENGINE_EVENT_HPP_
namespace Universe::Event {
template <class T>
class Event {
 public:
  virtual T getType() const = 0;
};
};  // namespace Universe::Event
#endif
