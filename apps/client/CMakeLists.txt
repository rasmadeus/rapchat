find_package(Boost REQUIRED COMPONENTS system date_time)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(client
    main.cpp
)

target_link_libraries(client Boost::system Boost::date_time)