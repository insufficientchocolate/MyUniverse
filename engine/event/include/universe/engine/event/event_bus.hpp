#ifndef _UNIVERSE_EVENT_BUS_HPP
#define _UNIVERSE_EVENT_BUS_HPP 
#include <memory>
#include <functional>
#include <type_traits>
#include "event.hpp"

namespace Universe::Event {
	template<class T>
  class EventBus {
	public:
	  typedef Event<T> EventType;
	  virtual void dispatch(const std::shared_ptr<const Event<T>> event) const = 0;
	  template<class ET,class A = typename std::enable_if<std::is_base_of<EventType, ET>::type,T>::type>
	  void registerListener(std::function<void(A)> callback);
  };
};
#endif /* EVENT_BUS_HPP */
