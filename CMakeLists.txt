cmake_minimum_required(VERSION 3.5)
project(3D-Physics-Engine LANGUAGES CXX VERSION 0.0.1)

include_directories(include src)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(CTest)
enable_testing()

add_library(phys_eng 
    src/objects.hpp
    src/GUI.cpp
)

target_include_directories(phys_eng  
    PUBLIC 
        src
)

add_executable(src_main
    src/main.cpp
 )

target_link_libraries(src_main 
    PRIVATE 
        phys_eng 
)

add_library(Catch2 INTERFACE)
target_include_directories(Catch2 
    INTERFACE
        test/
)

add_executable(unit_tests
    test/main.cpp
    test/test_objects.cpp
    test/test_GUI.cpp
)

target_include_directories(unit_tests 
    PUBLIC
        test/
)

target_link_libraries(unit_tests
    PRIVATE 
        phys_eng 
        Catch2
 )

include(ParseAndAddCatchTests)
ParseAndAddCatchTests(unit_tests)

install(
    TARGETS unit_tests
    RUNTIME DESTINATION bin
)