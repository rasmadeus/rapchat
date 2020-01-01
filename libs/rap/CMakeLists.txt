cmake_minimum_required(VERSION 3.14)
project(librap VERSION 1.0.0 LANGUAGES CXX)

set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_library(
    rap SHARED
    src/rap.cpp
)

target_compile_features(
    rap
    INTERFACE
        cxx_std_17
)

target_compile_options(
    rap
    INTERFACE
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

target_include_directories(
    rap
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(
    rap
    PRIVATE
        "RAP_LIBRARY"
)

find_package(Boost REQUIRED COMPONENTS system date_time)
target_link_libraries(
    rap
    PUBLIC
        Boost::system
        Boost::date_time
)

install(
    TARGETS rap
    EXPORT rap-targets
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(
    EXPORT rap-targets
    FILE rap-targets.cmake
    NAMESPACE rap::
    DESTINATION find
)

install(
    DIRECTORY
        include/rap
    DESTINATION
        include
)