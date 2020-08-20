add_library(
    rapchat
        src/message.cpp
)

target_compile_features(
    rapchat
    INTERFACE cxx_std_17
)

target_compile_options(
    rapchat
    INTERFACE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
)

target_include_directories(
    rapchat
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(
    rapchat
    PRIVATE "RAPCHAT_LIBRARY"
)