cmake_minimum_required(VERSION 3.0.0)
project(duke VERSION 0.0.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fomit-frame-pointer")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-aliasing")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_executable(
    duke
)
target_include_directories(
    duke PRIVATE lib/duktape-2.3.0/src
)
target_sources(
    duke PRIVATE lib/duktape-2.3.0/src/duktape.c
)
target_sources(
    duke PRIVATE src/main.c
)
target_link_libraries(
    duke "-lm"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
