set(include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(libstudent STATIC student.cpp)
target_include_directories(libstudent PUBLIC ${include_directories})

add_library(libdatabase STATIC database.cpp)
target_include_directories(libdatabase PUBLIC ${include_directories})
target_link_libraries(libdatabase PUBLIC libstudent)

add_library(libMainLoop STATIC mainLoop.cpp)
target_include_directories(libMainLoop PUBLIC ${include_directories})
target_link_libraries(libMainLoop PUBLIC libdatabase)