add_executable(
    message_test
    message_action_test.cpp
)

target_compile_features(
    message_test
    INTERFACE cxx_std_17
)

target_compile_options(
    message_test
    INTERFACE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
)

find_package(GTest REQUIRED)

target_link_libraries(
    message_test
    rapchat
    GTest::Main
)

add_test(NAME MessageTest COMMAND message_test)