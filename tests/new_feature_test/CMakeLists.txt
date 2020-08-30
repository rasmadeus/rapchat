add_executable(
    new_feature_test
    main.cpp
 "io_service_timer.h" "io_service_timer_thread.h")

target_compile_features(
    new_feature_test
    INTERFACE cxx_std_17
)

target_compile_options(
    new_feature_test
    INTERFACE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
)

find_package(
    Boost
    COMPONENTS
        system
        date_time
    REQUIRED
)

target_link_libraries(
    new_feature_test
    Boost::system
    Boost::date_time
    Boost::disable_autolinking
    Boost::dynamic_linking
)
