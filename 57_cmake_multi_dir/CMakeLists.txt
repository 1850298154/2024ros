cmake_minimum_required(VERSION 3.16)
project(
    CMakeSunny
    
    VERSION 1.0
    DESCRIPTION "A CMake Tutorial"
    LANGUAGES CXX
)

add_executable(
    cmlearn

    main.cpp
)



add_subdirectory(math)
target_link_libraries(
    cmlearn 
    PUBLIC 
    math
)
target_include_directories(
    cmlearn 
    PUBLIC
    "${PROJECT_SOURCE_DIR}/math"
)
