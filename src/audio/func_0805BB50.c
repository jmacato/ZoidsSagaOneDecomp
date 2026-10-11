#include "types.h"

register u8 *track asm("r1");
register u32 byte_value asm("r3");
register u32 saved_link asm("ip");

__attribute__((optimize("no-reorder-blocks"))) void func_0805BB50(void)
{
    /* This SDK command returns through ip and leaves lr to its byte-reader calls. */
    asm volatile("mov %0, lr" : "=r"(saved_link));
    asm volatile("bl func_0805BB44" : "+r"(track), "+r"(byte_value) : : "r0", "r2", "memory", "cc");
    track[0x19] = byte_value;
    if (byte_value == 0)
        asm volatile("bl func_0805BB28"
                     : "+r"(track), "+r"(byte_value)
                     :
                     : "r0", "r2", "memory", "cc");
    asm volatile("bx %0" : : "r"(saved_link));
    __builtin_unreachable();
}
