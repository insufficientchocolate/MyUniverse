cmake_minimum_required(VERSION 3.2)
include(cmake/HunterGate.cmake)
include(cmake/clang_format.cmake)
set(CMAKE_CXX_STANDARD 17)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.58.tar.gz"
    SHA1 "ee80dc91f91f5eb6892f80a0a92c83b4de8e980a"
)

project(MyUniverse)

hunter_add_package(SDL2)
hunter_add_package(glew)
find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glew CONFIG REQUIRED)
add_executable(
		"${CMAKE_PROJECT_NAME}"
		main.cc
        window_manager.hpp
        window_manager.cc
        error.hpp
        error.cc
        sdl_error.hpp
        sdl_error.cc
)
target_link_libraries("${CMAKE_PROJECT_NAME}" SDL2::SDL2 OpenGL::GL glew::glew)
format("${CMAKE_PROJECT_NAME}")
