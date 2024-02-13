cmake_minimum_required(VERSION 3.20.0)

include(AddGoogleTest)

add_executable(unit_tests tests.cpp)
target_link_libraries(unit_tests PRIVATE GTest::gtest_main libdatabase)

include(GoogleTest)
gtest_discover_tests(unit_tests)