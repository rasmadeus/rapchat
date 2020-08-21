add_executable(
    well_formed
    main.cpp
)

target_compile_features(
    well_formed
    INTERFACE cxx_std_17
)

target_compile_options(
    well_formed
    INTERFACE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
)

target_link_libraries(
    well_formed
    PUBLIC rapchat
)