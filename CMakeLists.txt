cmake_minimum_required(VERSION 3.14)
project(rapchat VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(libs)
add_subdirectory(apps)