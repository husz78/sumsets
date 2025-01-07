#include "stack.h"
#include "common/sumset.h"
#include <stdlib.h>
#include <stdio.h>

void stack_init(Stack *s) {
    s->capacity = MAX_BITS * 2;
    s->nodes = malloc(sizeof(Node) * s->capacity);
    if (!s->nodes) exit(1);
    s->top = 0;
}


int push(Stack* s, Sumset* a, Sumset* b) {
    if (s->top >= s->capacity) return -1;
    s->nodes[s->top].a = a;
    s->nodes[s->top].b = b;
    s->top++;
    return 0;
}

Node* pop(Stack* s) {
    if (s->top == 0) return NULL;
    s->top--;
    return &s->nodes[s->top];
}

bool empty(Stack* s) {
    return s->top == 0;
}

void stack_destroy(Stack *s) {
    free(s->nodes);
    free(s);
}