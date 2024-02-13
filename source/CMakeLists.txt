cmake_minimum_required(VERSION 3.20.0)
project(Database
        LANGUAGES CXX C
        DESCRIPTION "Student database"
        VERSION 0.0.1)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(src)

add_executable(Database src/main.cpp )
target_link_libraries(Database PRIVATE libMainLoop)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(test)

# For generating documentation
include(Doxygen)
Doxygen(docs)