cmake_minimum_required(VERSION 3.0.0)
project(duke)

set(CMAKE_CXX_STANDARD 17)
if (UNIX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif (UNIX)

add_custom_target(
    run COMMAND $<TARGET_FILE:duke> ${RUN_ARGS})
add_executable(
    duke source/module.cpp source/dracula.cpp source/io.cpp source/main.cpp)
target_compile_options(
    duke PRIVATE -Os)
target_include_directories(
    duke PRIVATE library/duktape-2.6.0/extras/console)
target_sources(
    duke PRIVATE library/duktape-2.6.0/extras/console/duk_console.c)
target_include_directories(
    duke PRIVATE library/duktape-2.6.0/extras/module-node)
target_sources(
    duke PRIVATE library/duktape-2.6.0/extras/module-node/duk_module_node.c)
target_include_directories(
    duke PRIVATE library/duktape-2.6.0/source)
target_sources(
    duke PRIVATE library/duktape-2.6.0/source/duktape.c)
