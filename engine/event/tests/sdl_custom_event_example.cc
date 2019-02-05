#include <SDL.h>
#include <gtest/gtest.h>
#include <universe/engine/event/sdl_custom_event.hpp>

namespace {
class DummyAssigner {
 public:
  DummyAssigner() : type(DummyAssigner::counter++) {}
  static Uint32 counter;
  const Uint32 type;
};
Uint32 DummyAssigner::counter = 31;
TEST(SDLCustomEvent, SubclassExample) {
  class DummyEvent
      : public Universe::Event::SDLCustomEvent<DummyEvent, DummyAssigner> {};
  DummyEvent e;
  ASSERT_EQ(31, e.getType());
  class AnotherDummyEvent
      : public Universe::Event::SDLCustomEvent<AnotherDummyEvent,
                                               DummyAssigner> {};
  AnotherDummyEvent ae;
  ASSERT_EQ(32, ae.getType());
}
};  // namespace
