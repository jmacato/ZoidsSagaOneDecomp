#include "types.h"

void func_08044CF0(u8 alpha)
{
    register u32 scaled asm("r0") = (u32)alpha << 24;
    register volatile u16 *control asm("r2");
    register u32 control_bits asm("r3");
    register u32 bits asm("r1");
    asm("" : "+r"(scaled));
    control = (volatile u16 *)0x04000050;
    control_bits = 0x3A64;
    bits = control_bits;
    asm("" : : "r"(control), "r"(control_bits), "r"(bits));
    *control = bits;
    control++;
    asm("" : : "r"(control));
    scaled >>= 16;
    bits = 15;
    asm("" : "+r"(bits));
    *control = scaled | bits;
}
