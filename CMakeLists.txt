cmake_minimum_required(
    VERSION 3.15
)

project(
    rapchat
    VERSION 1.0.0
    LANGUAGES CXX
)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(libs)
add_subdirectory(tests)