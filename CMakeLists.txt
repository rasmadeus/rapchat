cmake_minimum_required(VERSION 3.14)
project(rapchat VERSION 1.0 LANGUAGES CXX)

configure_file(src/rap_config.h.in src/rap_config.h)
target_include_directories(rap PUBLIC "${PROJECT_BINARY_DIR}")

add_library(rap_compiler_flags INTERFACE)
target_compile_features(rap_compiler_flags INTERFACE cxx_std_17)

set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(rap_compiler_flags INTERFACE "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

add_subdirectory(libs)
add_subdirectory(apps)