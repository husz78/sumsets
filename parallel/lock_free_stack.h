#pragma once

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
    int tag; 
    Node* head;
} Stack;

// Pushes both Sumsets on the stack.
void push(_Atomic Stack* stack, Shared_ptr* a, Shared_ptr* b);

// Pops Pair from the stack where Pair->a and Pair->b are both pointers to Sumset-s.
// Returns NULL if the stack is empty
Pair* pop(_Atomic Stack* stack);