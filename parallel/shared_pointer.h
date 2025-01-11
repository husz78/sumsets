#pragma once

#include <stdatomic.h>
#include "common/sumset.h"

typedef struct {
    Sumset* s;
    atomic_int count;
    Sumset* prev;
} Shared_ptr;

// Initializes the pointer.
void init_ptr(Shared_ptr* p, Sumset* s);

// Increases count for the pointer p and sets next->prev = p.
void link_next(Shared_ptr* p, Shared_ptr* next);

// Decreases count for the pointer and if it is 0
// then deallocates memory for the pointer.
void decrease_count(Shared_ptr* p);