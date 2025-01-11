#include <stdlib.h>

#include "shared_pointer.h"

void link_next(Shared_ptr* p, Shared_ptr* next) {
    atomic_fetch_add(&p->count, 1);
    next->prev = p;
}

void init_ptr(Shared_ptr* p, Sumset* s) {
    p = malloc(sizeof(Shared_ptr));
    if (!p) exit(1);
    p->s = s;
    atomic_store(&p->count, 0);
}

void decrease_count(Shared_ptr* p) {
    if (atomic_fetch_sub(&p->count, 1) == 1) {
        free(p->s);
        free(p);
        p->prev = NULL;
    }
}