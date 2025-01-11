#include <stdlib.h>
#include <stdatomic.h>

#include "lock_free_stack.h"
#include "shared_pointer.h"

// const int counter = 1000000;

void push(_Atomic Stack* stack, Shared_ptr* a, Shared_ptr* b) {
    Stack next, prev;

    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        exit(EXIT_FAILURE);
    }
    new_node->data = malloc(sizeof(Pair));
    if (!new_node->data) {
        free(new_node);
        exit(1);
    }
    new_node->data->a = a;
    new_node->data->b = b;

    prev = atomic_load(stack);
    do {
        new_node->next = prev.head;
        next.head = new_node;
        next.tag = prev.tag + 1;
    } while (!atomic_compare_exchange_weak(stack, &prev, next));
}

Pair* pop(_Atomic Stack* stack) {
    Pair* data;
    Stack next, prev;
    
    prev = atomic_load(stack);
    do {
        if (prev.head == NULL) {
            return NULL;
        }
        next.head = prev.head->next;
        next.tag = prev.tag + 1;
    } while(!atomic_compare_exchange_weak(stack, &prev, next));

    data = prev.head->data;
    free(prev.head);

    return data;
}

// void* f(void* stack_arg) {
//     _Atomic Stack* stack = (_Atomic Stack*) stack_arg;

//     for (int i = 0; i < counter; i++) {
//         int* data = malloc(sizeof(int));
//         if (!data) {
//             fprintf(stderr, "Memory allocation failed\n");
//             exit(EXIT_FAILURE);
//         }
//         *data = i;
//         push(stack, data);
//     }

//     return NULL;
// }

// int main() {
//     _Atomic Stack s = {0, NULL};
//     pthread_t t1, t2;

//     printf("atomic_is_lock_free: %d\n", atomic_is_lock_free(&s));
//     // Ponieważ strutkura Stack zajmuje więcej niż 64 bity,
//     // to w przypadku większości kompilatorów i architektur
//     // będzie ona zaimplementowana przy użyciu mutexa.

//     pthread_create(&t1, NULL, f, &s);
//     pthread_create(&t2, NULL, f, &s);

//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);

//     int node_count = 0;
//     void* n;
//     while ((n = pop(&s)) != NULL) {
//         node_count++;
//         free(n);
//     }

//     printf("node count: %d\n", node_count);

//     return 0;
// }