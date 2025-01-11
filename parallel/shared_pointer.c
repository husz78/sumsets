#include <stdlib.h>
#include <stdatomic.h>
// #include <stdio.h>
#include "shared_pointer.h"


void init_ptr(Shared_ptr* p, Sumset* s) {
    p->s = s;
    atomic_store(&p->count, 1);
}

void decrease_count(Shared_ptr* p) {
    if (!p)return;
    if (atomic_fetch_sub(&p->count, 1) == 1) {
        // printf("My count is: %d\n", atomic_load(&p->count));
        free(p->s);
        free(p);
    }
}