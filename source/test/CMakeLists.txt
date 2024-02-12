cmake_minimum_required(VERSION 3.20.0)

# include module that setup GoogleTests
include(../cmake/AddGoogleTests.cmake)

add_executable(unit_tests test/tests.cpp)
target_link_libraries(unit_tests PRIVATE GTest::gtest_main libdatabase)

include(GoogleTest)
gtest_discover_tests(unit_tests)