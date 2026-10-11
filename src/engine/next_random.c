#include "engine/random.h"

u16 next_random(void)
{
    u32 seed;
    u32 step;

    random_counter++;
    seed = random_seed * 5;
    step = (random_counter >> (random_seed & 15)) + 1;
    asm volatile("" : "+r"(step));
    seed += step;
    random_seed = seed + (~(u32)random_input << 1);
    return random_seed;
}
