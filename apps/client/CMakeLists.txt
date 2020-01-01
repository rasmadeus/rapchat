add_executable(
    client
    main.cpp
)

find_package(rap REQUIRED) 
target_link_libraries(client rap)

install(
    TARGETS client
    RUNTIME DESTINATION bin
)
