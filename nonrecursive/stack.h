#pragma once

#include "common/sumset.h"

typedef struct Node {
    Sumset* a;
    Sumset* b;
} Node;

typedef struct Stack {
    Node* nodes;
    size_t capacity;
    size_t top; // Index of the first free space for the next element.
} Stack;

// Initializes the stack (allocates memory for it)
void stack_init(Stack *s);

// Returns 0 if s push is successful and -1 if it is not.
int push(Stack* s, Sumset* a, Sumset* b);

// Returns Node* representing two sumsets if successful and NULL otherwise
Node* pop(Stack* s);

// True if empty ano 0 otherwise
bool empty(Stack* s);

// Deallocates memory for the stack
void stack_destroy(Stack *s);