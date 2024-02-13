cmake_minimum_required(VERSION 3.20.0)
project(Database
        LANGUAGES CXX C
        DESCRIPTION "Student database"
        VERSION 0.0.1)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
#add_subdirectory(test)

add_executable(Database src/main.cpp )
target_link_libraries(Database PRIVATE libMainLoop)

# Google test setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(unit_tests test/tests.cpp)
target_link_libraries(unit_tests PRIVATE GTest::gtest_main libdatabase)

include(GoogleTest)
gtest_discover_tests(unit_tests)