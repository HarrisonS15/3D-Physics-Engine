cmake_minimum_required(VERSION 3.5)
project(3D-Physics-Engine LANGUAGES C CXX VERSION 0.0.1)

include_directories(include src src/glad.c lib)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


enable_testing()

cmake_policy(SET CMP0110 NEW)

file(GLOB HEADER_FILES 
    "${CMAKE_SOURCE_DIR}/src/*.hpp"
    include/glad/glad.h
)

file(GLOB TEST_FILES 
    "${CMAKE_SOURCE_DIR}/test/*.cpp"
    "${CMAKE_SOURCE_DIR}/test/*.hpp"
    
)
link_directories(${CMAKE_SOURCE_DIR}/lib)

find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

add_library(glad src/glad.c include/glad/glad.h )
target_include_directories(glad PUBLIC ${EXT_INCLUDE_DIR})

add_executable(src_main
    src/main.cpp
    ${HEADER_FILES}
 )

 target_link_libraries(src_main PUBLIC glad glfw3 ${CMAKE_DL_LIBS})

target_include_directories(src_main 
    PUBLIC
        test/
        GLFW/
        KHR/
)

add_executable(unit_tests
    ${TEST_FILES}
    ${HEADER_FILES}
)

target_link_libraries(unit_tests PUBLIC glad glfw3 ${CMAKE_DL_LIBS})

target_include_directories(unit_tests 
    PUBLIC
        test/
        GLFW/
        KHR/
)

find_package(Catch2)

target_link_libraries(unit_tests
    PRIVATE 
        Catch2::Catch2WithMain
 )

 include(CTest)
 include(Catch)

 catch_discover_tests(unit_tests)