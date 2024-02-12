cmake_minimum_required(VERSION 3.20.0)
project(Database
        LANGUAGES CXX C
        DESCRIPTION "Student database"
        VERSION 0.0.1)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Database src/main.cpp)