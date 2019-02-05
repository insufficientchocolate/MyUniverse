find_package(GTest CONFIG REQUIRED)

add_executable(
    event_unit_test
    base_event_bus_test.cc
)

target_link_libraries(event_unit_test GTest::gtest GTest::main event)

gtest_discover_tests(event_unit_test)

format(event_unit_test)