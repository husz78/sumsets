add_executable(nonrecursive main.c)
add_library(stack stack.c stack.h)
target_link_libraries(nonrecursive io err stack)
