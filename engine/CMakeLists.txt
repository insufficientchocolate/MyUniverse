project(engine CXX)

hunter_add_package(SDL2)
hunter_add_package(glew)
hunter_add_package(Boost COMPONENTS filesystem)

find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(Boost CONFIG REQUIRED COMPONENTS filesystem)

add_library(
  "${PROJECT_NAME}"
  window_manager.cc
  error.cc
  sdl_error.cc
  main_render.cc
  gl_program_manager.cc
  include/universe/engine/error.hpp
  include/universe/engine/gl_program_manager.hpp
  include/universe/engine/sdl_error.hpp
  include/universe/engine/main_render.hpp
  include/universe/engine/window_manager.hpp
)

add_subdirectory(event)

target_link_libraries(
  "${PROJECT_NAME}"
  SDL2::SDL2
  OpenGL::GL
  glew::glew
  Boost::filesystem
  event
)

target_include_directories("${PROJECT_NAME}" PUBLIC $<BUILD_INTERFACE: include> $<INSTALL_INTERFACE: include>)
target_compile_definitions("${PROJECT_NAME}" PRIVATE BOOST_ERROR_CODE_HEADER_ONLY DBOOST_SYSTEM_NO_DEPRECATE)

include(GNUInstallDirs)

install(
  TARGETS
  "${PROJECT_NAME}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")

