#pragma once

#include <stdbool.h>
#include <pthread.h>
#include "common/sumset.h"
#include "shared_pointer.h"

typedef struct Pair {
    Shared_ptr* a;
    Shared_ptr* b;
} Pair;

typedef struct Node {
    Pair* data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} Stack;

void stack_init(Stack* stack);
void stack_destroy(Stack* stack);
void push(Stack* stack, Shared_ptr* a, Shared_ptr* b);
void pop(Stack* stack, Pair** res);