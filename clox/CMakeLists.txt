cmake_minimum_required(VERSION 3.16)
project(clox VERSION 0.1.0 LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(memory
    src/memory.c
    include/memory.h
)
target_include_directories(memory PUBLIC include)

add_library(value
    src/value.c
    include/value.h
)
target_link_libraries(value PRIVATE memory)

add_library(chunk
    src/chunk/chunk.c
    include/chunk/chunk.h
)
target_include_directories(chunk PUBLIC include)
target_link_libraries(chunk PRIVATE memory)
target_link_libraries(chunk PRIVATE value)

add_library(vm
    src/vm/vm.c
    include/vm/vm.h
)
target_include_directories(vm PUBLIC include)
target_link_libraries(vm PRIVATE chunk)

add_library(cl_debug
    src/debug/debug.c
    include/debug/debug.h
)
target_link_libraries(cl_debug PRIVATE chunk)
target_link_libraries(cl_debug PRIVATE vm)

add_executable(clox src/main.c 
    include/common.h
)
target_link_libraries(clox PRIVATE chunk)
target_link_libraries(clox PRIVATE vm)
target_link_libraries(clox PRIVATE cl_debug)
