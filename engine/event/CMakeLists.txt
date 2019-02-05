project(event)

add_library(
  "${PROJECT_NAME}"
  include/universe/engine/event/event_bus.hpp
  include/universe/engine/event/event.hpp
  include/universe/engine/event/abstract_event_bus.hpp
  include/universe/engine/event/sdl_event_bus.hpp
  sdl_event_bus.cc
)

target_include_directories(
  "${PROJECT_NAME}"
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_link_libraries("${PROJECT_NAME}" SDL2::SDL2)