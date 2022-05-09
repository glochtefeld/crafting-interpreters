cmake_minimum_required(VERSION 3.16)
project(clox VERSION 0.1.0 LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(memory
    src/memory.c
    include/memory.h
    include/object.h
)
target_include_directories(memory PUBLIC include)

add_library(value
    src/value.c
    src/object.c
    include/value.h
    include/object.h
)
target_link_libraries(value PRIVATE memory)

add_library(hash
    src/hash/hashtable.c
    include/hash/hashtable.h
)
target_include_directories(hash PUBLIC include)
target_link_libraries(hash PRIVATE memory)
target_link_libraries(hash PRIVATE value)

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
target_link_libraries(vm PRIVATE memory)

add_library(cl_debug
    src/debug/debug.c
    include/debug/debug.h
)
target_link_libraries(cl_debug PRIVATE chunk)
target_link_libraries(cl_debug PRIVATE vm)

add_library(scanner
    src/scanner/scanner.c
    include/scanner/scanner.h
)
target_include_directories(scanner PUBLIC include)

add_library(compiler
    src/compiler/compiler.c
    include/compiler/compiler.h
)
target_include_directories(compiler PUBLIC include)
target_link_libraries(compiler PRIVATE vm)
target_link_libraries(compiler PRIVATE scanner)
target_link_libraries(compiler PRIVATE cl_debug)

add_executable(clox src/main.c 
    include/common.h
)
target_link_libraries(clox PRIVATE chunk)
target_link_libraries(clox PRIVATE vm)
target_link_libraries(clox PRIVATE cl_debug)
target_link_libraries(clox PRIVATE compiler)
