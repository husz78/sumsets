#include <stdlib.h>
#include <stdatomic.h>

#include "lock_free_stack.h"
#include "shared_pointer.h"
#include "common/err.h"


void stack_init(Stack* stack) {
    stack->head = NULL;
    ASSERT_ZERO(pthread_mutex_init(&stack->mutex, NULL));
    ASSERT_ZERO(pthread_cond_init(&stack->cond, NULL));
}

void stack_destroy(Stack* stack) {
    pthread_mutex_destroy(&stack->mutex);
    pthread_cond_destroy(&stack->cond);
    while (stack->head != NULL) {
        Node* temp = stack->head;
        stack->head = stack->head->next;
        free(temp->data);
        free(temp);
    }
}

void push(Stack* stack, Shared_ptr* a, Shared_ptr* b) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        exit(EXIT_FAILURE);
    }
    new_node->data = malloc(sizeof(Pair));
    if (!new_node->data) {
        free(new_node);
        exit(EXIT_FAILURE);
    }
    new_node->data->a = a;
    new_node->data->b = b;

    pthread_mutex_lock(&stack->mutex);
    new_node->next = stack->head;
    stack->head = new_node;
    pthread_cond_signal(&stack->cond); // Signal one waiting thread
    pthread_mutex_unlock(&stack->mutex);
}

void pop(Stack* stack, Pair** res) {
    pthread_mutex_lock(&stack->mutex);
    while (stack->head == NULL) {
        pthread_cond_wait(&stack->cond, &stack->mutex); // Wait for the stack to become non-empty
    }
    Node* temp = stack->head;
    stack->head = stack->head->next;
    *res = temp->data;
    free(temp);
    pthread_mutex_unlock(&stack->mutex);
}