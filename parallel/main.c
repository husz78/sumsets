#include <stddef.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <stdio.h>

#include "common/io.h"
#include "common/sumset.h"
#include "common/err.h"
#include "lock_free_stack.h"
#include "shared_pointer.h"

#define NOWORK_CHECK 1000 // Number of solves that thread will make until the next check
// for possiblity of waiving some computations and pushing them to the stack.
#define NOACTIVE_CHECK 10000 // How often a thread will check if it can end.

pthread_mutex_t mutex; // Mutex for best solution.
atomic_int occupied = 0; // Number of threads that are executing solve atm.
Stack stack;
int n_threads; // Number of helper threads that are used to compute the result.
Solution best_solution;
InputData input_data;
struct timespec ts;
    

void solve(Shared_ptr* a, Shared_ptr* b, int* check, const int* d) {
    if (a->s->sum > b->s->sum) {
        (*check)++;
        return solve(b, a, check, d);
    }
       
    
    if (is_sumset_intersection_trivial(a->s, b->s)) {
        for (size_t i = a->s->last; i <= *d; ++i) {
            if (!does_sumset_contain(b->s, i)) {
                Sumset* a_with_i = malloc(sizeof(Sumset));
                if (!a_with_i) exit(1);

                sumset_add(a_with_i, a->s, i);
                Shared_ptr* a_i = malloc(sizeof(Shared_ptr));
                if (!a_i) exit(1);
                init_ptr(a_i, a_with_i);

                if (*check % NOWORK_CHECK == 0 && atomic_load(&occupied) < n_threads) {
                    // atomic_fetch_add(&a_i->count, 1);
                    atomic_fetch_add(&b->count, 1);
                    push(&stack, a_i, b);
                }
                else {
                    (*check)++;
                    solve(a_i, b, check, d);
                }
            }
        }
    }
    else if ((a->s->sum == b->s->sum) && (get_sumset_intersection_size(a->s, b->s) == 2)) {
        ASSERT_ZERO(pthread_mutex_lock(&mutex));
        if (b->s->sum > best_solution.sum) 
            solution_build(&best_solution, &input_data, a->s, b->s);
        ASSERT_ZERO(pthread_mutex_unlock(&mutex));
    }
    
}

void* start_thread(void* args) {
    const int* d = (int*)args;
    int check = 1;
    int no_work_check = 0;
    while (true) {
        // Pair* p = atomic_load(&stack).head->data;
        // printf("%p", p);
        Pair* pair;
        pop(&stack, &pair);
        if (pair) {
            atomic_fetch_add(&occupied, 1);
            solve(pair->a, pair->b, &no_work_check, d);
            decrease_count(pair->a);
            decrease_count(pair->b);
            atomic_fetch_sub(&occupied, 1);
        }
        // Add finishing threads
        if (check % NOACTIVE_CHECK == 0 && atomic_load(&occupied) == 0) return NULL;
        check++;
    }
}



int main()
{
    // input_data_read(&input_data);
    input_data_init(&input_data, 8, 10, (int[]){0}, (int[]){1, 0});

    pthread_t* threads; // Array of threads.
    n_threads = input_data.t;
    Shared_ptr* a = malloc(sizeof(Shared_ptr)); Shared_ptr* b = malloc(sizeof(Shared_ptr));
    stack_init(&stack);
    init_ptr(a, &input_data.a_start);
    init_ptr(b, &input_data.b_start);
    atomic_store(&a->count, input_data.d);
    atomic_store(&b->count, input_data.d);
    push(&stack, a, b); 

    solution_init(&best_solution);
    ASSERT_ZERO(pthread_mutex_init(&mutex, NULL));

    threads = malloc(sizeof(pthread_t) * n_threads);
    for (int i = 0; i < n_threads; i++) {
        ASSERT_ZERO(pthread_create(&threads[i], NULL, start_thread, &input_data.d));
    }

    
    for (int i = 0; i < n_threads; i++) {
        ASSERT_ZERO(pthread_join(threads[i], NULL));
    }
    solution_print(&best_solution);
    free(a);
    free(b);
    ASSERT_ZERO(pthread_mutex_destroy(&mutex));
    stack_destroy(&stack);
    return 0;
}
