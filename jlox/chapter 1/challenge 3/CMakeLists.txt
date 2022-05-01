cmake_minimum_required(VERSION 3.16)
project(DoubleLinkedList VERSION 0.1.0 LANGUAGES C)

add_library(d_linked_list
    src/double-link-list.c
    include/double-link-list.h
)
target_include_directories(d_linked_list PUBLIC include)

add_executable(dlinkedlist_test src/main.c)
target_link_libraries(dlinkedlist_test PRIVATE d_linked_list)
