cmake_minimum_required(VERSION 3.24)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
project(Arcade)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(arcade
        src/main.cpp
        src/Utils.cpp
        src/Core/Core.cpp
        src/Core/Text.cpp inc/Text.hpp
        inc/Entity.hpp src/Core/Entity.cpp
        inc/Button.hpp src/Core/Button.cpp inc/ISpriteType.hpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_subdirectory(libraries)