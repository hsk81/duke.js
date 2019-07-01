cmake_minimum_required(VERSION 3.0.0)
project(duke VERSION 0.3.0)

set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -fomit-frame-pointer")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -fstrict-aliasing")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -Os")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -pedantic")
set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -Wall")

add_executable(
    duke
)
target_include_directories(
    duke PRIVATE lib/duktape-2.3.0/extras/console
)
target_sources(
    duke PRIVATE lib/duktape-2.3.0/extras/console/duk_console.c
)
target_include_directories(
    duke PRIVATE lib/duktape-2.3.0/src
)
target_sources(
    duke PRIVATE lib/duktape-2.3.0/src/duktape.c
)
target_sources(
    duke PRIVATE src/dracula.cpp
         PRIVATE src/io.cpp
         PRIVATE src/main.cpp
)
target_link_libraries(
    duke "-lm"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
