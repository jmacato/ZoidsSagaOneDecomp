#include "types.h"

struct AudioClearBlock
{
    u32 words[4];
};

register u32 fourth_zero asm("r4");

void func_0805B3A4(struct AudioClearBlock *destination)
{
    register struct AudioClearBlock *cursor asm("r0") = destination;
    register u32 saved_fourth asm("ip") = fourth_zero;
    register u32 first_zero asm("r1");
    register u32 second_zero asm("r2");
    register u32 third_zero asm("r3");
    asm("" : "+r"(saved_fourth));
    first_zero = 0;
    asm("" : "+r"(first_zero));
    second_zero = 0;
    asm("" : "+r"(second_zero));
    third_zero = 0;
    asm("" : "+r"(third_zero));
    fourth_zero = 0;
    asm("" : "+r"(fourth_zero));
    unsigned block;
#pragma GCC unroll 4
    for (block = 0; block < 4; block++)
    {
        /* Preserve the SDK's four-word store and its cursor writeback. */
        asm volatile("stmia %0!, {%1, %2, %3, %4}"
                     : "+r"(cursor)
                     : "r"(first_zero), "r"(second_zero), "r"(third_zero), "r"(fourth_zero)
                     : "memory");
    }
    fourth_zero = saved_fourth;
}
