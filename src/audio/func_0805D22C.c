#include "types.h"

extern u32 (*D_03007224)(const u8 *, u8 *, u32);

void copy_sram_bytes(const u8 *, u8 *, u32);

u32 func_0805D22C(const u8 *src, u8 *dest, u32 size)
{
    u8 i;
    u32 error_addr;

    for (i = 0; i < 3; i++)
    {
        copy_sram_bytes(src, dest, size);
        error_addr = D_03007224(src, dest, size);
        if (error_addr == 0)
            break;
    }

    return error_addr;
}
