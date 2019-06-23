cmake_minimum_required(VERSION 3.0.0)
project(duke VERSION 0.1.0)

set(CMAKE_C_FLAGS "-std=c99")
set(CMAKE_EXE_LINKER_FLAGS "-lduktape -lm")

add_executable(duke src/main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
