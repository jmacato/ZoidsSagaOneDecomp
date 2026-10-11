// Based on the SRAM routines in jmacato/ZoidsLegacyDecomp.

#include "types.h"

void copy_sram_bytes(const u8 *source, u8 *destination, u32 size)
{
    register u32 remaining asm("r3");
    register s32 sentinel asm("r0");

    remaining = size;
    {
        register volatile u16 *wait_control asm("r2") = (volatile u16 *)0x04000204;
        register u16 wait_value asm("r0");
        u16 mask;

        asm volatile("" : "+r"(wait_control));
        wait_value = *wait_control;
        asm volatile("" : "+r"(wait_value));
        mask = 0xFFFC;
        wait_value &= mask;
        wait_value |= 3;
        *wait_control = wait_value;
    }
    remaining -= 1;
    sentinel = 1;
    sentinel = -sentinel;
    if (remaining != (u32)sentinel) {
        register s32 loop_sentinel asm("r1") = sentinel;

        asm volatile("" : "+r"(loop_sentinel));
        do {
            *destination++ = *source++;
            remaining -= 1;
        } while (remaining != (u32)loop_sentinel);
    }
}
