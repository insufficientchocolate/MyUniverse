#include <gtest/gtest.h>
#include <universe/engine/event/base_event_bus.hpp>

namespace {
class DummyEvent : public Universe::Event::Event<int> {
 public:
  int getType() const { return 0; }
};

TEST(BaseEventBus, DefaultDispatch) {
  bool called = false;
  Universe::Event::BaseEventBus<int> bus;
  bus.registerListener([&called](auto e) { called = true; });
  bus.dispatch(std::make_shared<DummyEvent>());
  ASSERT_TRUE(called);
}
};  // namespace