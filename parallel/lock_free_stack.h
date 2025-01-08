#pragma once

#include "common/sumset.h"

typedef struct Pair {
    Sumset* a;
    Sumset* b;
} Pair;

typedef struct Node {
    Pair* data;
    Node* next;
} Node;

typedef struct {
    int tag; 
    Node* head;
} Stack;

// Pushes both Sumsets on the stack.
void push(_Atomic Stack* stack, Sumset* a, Sumset* b);

// Pops Pair from the stack where Pair->a and Pair->b are both pointers to Sumset-s.
// Returns NULL if the stack is empty
Pair* pop(_Atomic Stack* stack);