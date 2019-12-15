cmake_minimum_required(VERSION 3.14)
project(rap_apps VERSION 1.0 LANGUAGES CXX)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_17)

set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(compiler_flags INTERFACE "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

add_subdirectory(client)