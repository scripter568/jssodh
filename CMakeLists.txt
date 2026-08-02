cmake_minimum_required(VERSION 3.21)

project(stereo-madness-welcome VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK environment variable is not set")
endif()

add_subdirectory(
    "$ENV{GEODE_SDK}"
    "${CMAKE_CURRENT_BINARY_DIR}/geode-sdk"
)

file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

geode_mod(
    stereo-madness-welcome
    SOURCES ${SOURCES}
)
