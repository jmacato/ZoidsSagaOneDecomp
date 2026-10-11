#include "engine/random.h"

void seed_random(u16 value)
{
    u32 seed = value + ((value ^ 255) << 8);

    asm volatile("" : "+r"(seed));
    random_seed = seed;
}
