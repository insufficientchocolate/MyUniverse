cmake_minimum_required(VERSION 3.2)
include(cmake/HunterGate.cmake)
include(cmake/clang_format.cmake)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.58.tar.gz"
    SHA1 "ee80dc91f91f5eb6892f80a0a92c83b4de8e980a"
)

project(MyUniverse CXX)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

enable_testing()
include(GoogleTest)

add_subdirectory(engine)

add_executable(
		"${CMAKE_PROJECT_NAME}"
		main.cc
)

target_link_libraries("${CMAKE_PROJECT_NAME}" engine)

format("${CMAKE_PROJECT_NAME}")

install(TARGETS "${CMAKE_PROJECT_NAME}"
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

include(CPack)
