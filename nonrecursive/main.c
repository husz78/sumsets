#include <stddef.h>

#include "common/io.h"
#include "common/sumset.h"
#include <stdlib.h>

typedef struct Node {
    Sumset a;
    Sumset* b;
    int children;
    struct Node* prev;
} Node;

typedef struct Stack {
    Node nodes[MAX_BITS];
    size_t top;
} Stack;

void push(Stack* s, Sumset a, Sumset* b, Node* prev) {
    s->nodes[s->top].a = a;
    s->nodes[s->top].b = b;
    s->nodes[s->top].prev = prev;
    s->nodes[s->top].children = 0;
    if (prev) prev->children++;
    s->top++;
}

void push_one(Stack* s, Sumset *b, Node* prev) {
    s->nodes[s->top].b = b;
    s->nodes[s->top].prev = prev;
    s->nodes[s->top].children = 0;
    if (prev) prev->children++;
    s->top++;
}

Node* first_free(Stack* s) {
    return &s->nodes[s->top];
}

Node* top(Stack* s) {
    return &s->nodes[s->top - 1];
}

void try_pop(Stack* s, bool if_swap, bool if_push) {
    while (s->top > 0) {
        Node* first = top(s);
        if (first->children != 0 || if_swap || if_push) break;
        Node* prev = first->prev;
        s->top--;
        if (prev) prev->children--;
        if (prev && prev != top(s)) break;
    }
}


static void solve(Sumset x, Sumset y, Solution* best_solution, InputData* input) {
    Stack stack = {0};
    Stack* s = &stack;
    push(s, x, &y, NULL);
    bool if_swap = false;
    bool if_push = false;
    while (s->top != 0) {
        Node* node = top(s);
        if_swap = false;
        if_push = false;

        if (node->a.sum > node->b->sum) {
            push(s, *node->b, &node->a, node);
            if_swap = true;
        }
        else if (is_sumset_intersection_trivial(&node->a, node->b)) {
            for (int i = node->a.last; i <= input->d; i++) {
                if (!does_sumset_contain(node->b, i)) {
                    Node* next = first_free(s);
                    sumset_add(&next->a, &node->a, i);
                    push_one(s, node->b, node);
                    if_push = true;
                }
            }
        }
        else if ((node->a.sum == node->b->sum) && (get_sumset_intersection_size(&node->a, node->b) == 2)) {
            if (node->b->sum > best_solution->sum) 
                solution_build(best_solution, input, &node->a, node->b);
        }
        try_pop(s, if_swap, if_push);
    }
}

int main()
{
    InputData input_data;
    // input_data_read(&input_data);
    input_data_init(&input_data, 1, 27, (int[]){0}, (int[]){1, 0});

    Solution best_solution;
    solution_init(&best_solution);

    solve(input_data.a_start, input_data.b_start, &best_solution, &input_data);

    solution_print(&best_solution);
    return 0;
}