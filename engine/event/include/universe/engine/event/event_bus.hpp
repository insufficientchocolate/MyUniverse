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
		typedef std::function<void(std::shared_ptr<const EventType>)> EventListenerType;
	  virtual void dispatch(const std::shared_ptr<const EventType> event) const = 0;
	  virtual void registerListener(EventListenerType callback) = 0;
  };
};
#endif
