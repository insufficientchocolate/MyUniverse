project(engine)

hunter_add_package(SDL2)
hunter_add_package(glew)
hunter_add_package(Boost COMPONENTS filesystem)

find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(Boost CONFIG REQUIRED COMPONENTS filesystem)

add_library(
  "${PROJECT_NAME}"
  include/window_manager.hpp
  window_manager.cc
  include/error.hpp
  error.cc
  include/sdl_error.hpp
  sdl_error.cc
  include/main_render.hpp
  main_render.cc
  include/gl_program_manager.hpp
  gl_program_manager.cc
  include/events.hpp
)

target_link_libraries(
  "${PROJECT_NAME}"
  SDL2::SDL2
  OpenGL::GL glew::glew
  Boost::filesystem)

target_include_directories("${PROJECT_NAME}" PUBLIC $<BUILD_INTERFACE: include> $<INSTALL_INTERFACE: include>)
target_compile_definitions("${PROJECT_NAME}" PRIVATE BOOST_ERROR_CODE_HEADER_ONLY DBOOST_SYSTEM_NO_DEPRECATE)
