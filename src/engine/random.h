#ifndef ZOIDS_SAGA_RANDOM_H
#define ZOIDS_SAGA_RANDOM_H

#include "types.h"

extern u16 random_seed;
extern u16 random_counter;
extern u16 random_input;

void seed_random(u16 value);
u16 next_random(void);

#endif
