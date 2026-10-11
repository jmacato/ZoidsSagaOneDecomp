#include "types.h"

extern u8 D_0200EB84[];

void func_08046848(void)
{
    register u32 index asm("r2") = 0;
    u8 *base = D_0200EB84;
    register u32 zero_offset asm("r6") = 0x21F4;
    register u32 zero asm("r5") = 0;
    register u32 flag_offset asm("r4") = 0x21F5;
    register u32 mask asm("r3") = 255;
    asm("" : : "r"(index), "r"(base), "r"(zero_offset), "r"(zero), "r"(flag_offset));
    asm("" : "+r"(mask));
    do
    {
        register u32 position asm("r1") = index * 4 + (u32)base;
        register u32 address asm("r0") = position + zero_offset;
        asm("" : : "r"(position), "r"(address));
        *(u8 *)address = zero;
        position += flag_offset;
        asm("" : : "r"(position));
        *(u8 *)position |= mask;
        {
            register u32 next asm("r0") = index + 1;
            asm("" : : "r"(next));
            index = (u8)next;
        }
    } while (index <= 5);
}
