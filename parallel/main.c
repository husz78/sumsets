#include <stddef.h>
#include <pthread.h>
#include <stdatomic.h>

#include "common/io.h"
#include "common/sumset.h"
#include "common/err.h"
#include "lock_free_stack.h"

#define NOWORK_CHECK 1000 // Number of solves that thread will make until the next check
// for possiblity of waiving some computations and pushing them to the stack.

pthread_t* threads; // Array of threads.
atomic_int occupied = 0; // Number of threads that are executing solve atm.
_Atomic Stack stack = {0, NULL};
int n_threads; // Number of helper threads that are used to compute the result.

void solve(Sumset* a, Sumset* b, int check, int d) {
    if (a->sum > b->sum)
        return solve(b, a, ++check, d);
    
    if (is_sumset_intersection_trivial(a, b)) {
        for (size_t i = a->last; i <= d; ++i) {
            Sumset a_with_i;
            sumset_add(&a_with_i, a, i);
            // Finish this.
        }
    }
}

void* start_thread(void* args) {
    int d = *(int*)args;
    while (true) {
        Pair* pair = pop(&stack);
        if (pair) {
            atomic_fetch_add(&occupied, 1);
            solve(pair->a, pair->b, 0, d);
            free(pair);
            atomic_fetch_sub(&occupied, 1);
        }
    }
}

int main()
{
    InputData input_data;
    input_data_read(&input_data);
    // input_data_init(&input_data, 8, 10, (int[]){0}, (int[]){1, 0});
    n_threads = input_data.t;
    push(&stack, &input_data.a_start, &input_data.b_start); 

    threads = malloc(sizeof(pthread_t) * n_threads);
    for (int i = 0; i < n_threads; i++) {
        ASSERT_ZERO(pthread_create(&threads[i], NULL, start_thread, (void*)input_data.d));
    }

    Solution best_solution;
    solution_init(&best_solution);

    // ...

    solution_print(&best_solution);
    return 0;
}
