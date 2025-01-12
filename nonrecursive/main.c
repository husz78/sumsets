#include <stddef.h>

#include "common/io.h"
#include "common/sumset.h"
#include "stack.h"
#include "common/err.h"
#include <stdlib.h>

static void solve(Sumset* a, Sumset* b, Solution* best_solution, InputData* input) {
    Stack* s = malloc(sizeof(Stack));
    if (!s) exit(1);
    stack_init(s); 
    ASSERT_SYS_OK(push(s, a, b));

    while (!empty(s)) {
        Node* node = pop(s);
        if (!node) exit(1);
        Sumset* a = node->a;
        Sumset* b = node->b;

        if (a->sum > b->sum) {
            ASSERT_SYS_OK(push(s, b, a));
        }
        else if (is_sumset_intersection_trivial(a, b)) {
            for (int i = a->last; i <= input->d; i++) {
                if (!does_sumset_contain(b, i)) {
                    Sumset* a_with_i = malloc(sizeof(Sumset));
                    if (!a_with_i) exit(1);
                    sumset_add(a_with_i, a, i);
                    ASSERT_SYS_OK(push(s, a_with_i, b));
                }
            }
        }
        else if ((a->sum == b->sum) && (get_sumset_intersection_size(a, b) == 2)) {
            if (b->sum > best_solution->sum) 
                solution_build(best_solution, input, a, b);
        }
    }

    stack_destroy(s);
}

int main()
{
    InputData input_data;
    // input_data_read(&input_data);
    input_data_init(&input_data, 1, 20, (int[]){0}, (int[]){1, 0});

    Solution best_solution;
    solution_init(&best_solution);

    solve(&input_data.a_start, &input_data.b_start, &best_solution, &input_data);

    solution_print(&best_solution);
    return 0;
}