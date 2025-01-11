add_executable(parallel main.c)
add_library(lock_free_stack lock_free_stack.c lock_free_stack.h)
add_library(shared_pointer shared_pointer.c shared_pointer.h)
target_link_libraries(parallel io err lock_free_stack shared_pointer atomic)
