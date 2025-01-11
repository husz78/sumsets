#pragma once

#include <stdatomic.h>
#include "common/sumset.h"

typedef struct {
    Sumset* s;
    atomic_int count;
} Shared_ptr;

// Initializes the pointer.
void init_ptr(Shared_ptr* p, Sumset* s);

// Decreases count for the pointer and if it is 0
// then deallocates memory for the pointer.
void decrease_count(Shared_ptr* p);