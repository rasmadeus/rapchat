add_library(
    rap SHARED
    rap.cpp
)

target_include_directories(rap INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(rap PRIVATE "RAP_LIBRARY")

install(
    TARGETS rap
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(
    FILES
        rap_global.h
        rap.h
    DESTINATION
        include/rap
)
