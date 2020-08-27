add_executable(
    well_formed
    main.cpp
    message_test.cpp
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

target_include_directories(
    well_formed
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(GTest REQUIRED)

target_link_libraries(
    well_formed
    rapchat
    GTest::GTest
)

add_test(NAME MessageUnitTest COMMAND well_formed)