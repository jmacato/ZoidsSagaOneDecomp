// Based on the SRAM comparison routine in jmacato/ZoidsLegacyDecomp.

#include "types.h"

u32 find_first_mismatching_byte(const u8 *source_bytes, const u8 *compared_bytes, u32 byte_count)
{
    register u32 bytes_remaining asm("r3");
    register s32 sentinel asm("r0");

    bytes_remaining = byte_count;
    {
        register volatile u16 *wait_control asm("r2");
        register u16 wait_control_value asm("r0");
        u16 preserved_wait_bits;

        wait_control = (volatile u16 *)0x04000204;
        asm volatile("" : "+r"(wait_control));
        wait_control_value = *wait_control;
        asm volatile("" : "+r"(wait_control_value));
        preserved_wait_bits = 0xFFFC;
        wait_control_value &= preserved_wait_bits;
        wait_control_value |= 3;
        *wait_control = wait_control_value;
    }
    bytes_remaining -= 1;
    sentinel = 1;
    sentinel = -sentinel;
    if (bytes_remaining != (u32)sentinel) {
        register s32 loop_sentinel asm("r2");

        loop_sentinel = sentinel;
        asm volatile("" : "+r"(loop_sentinel));
        do {
            u8 compared_byte;
            u8 source_byte;

            compared_byte = *compared_bytes;
            source_byte = *source_bytes;
            source_bytes += 1;
            compared_bytes += 1;
            if (compared_byte != source_byte) {
                return (u32)(compared_bytes - 1);
            }
            bytes_remaining -= 1;
        } while (bytes_remaining != (u32)loop_sentinel);
    }
    return 0;
}
