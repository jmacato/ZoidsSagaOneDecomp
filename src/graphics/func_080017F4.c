#include "types.h"

void func_080017F4(vu16 *data, u16 count)
{
    register u32 outer_count asm("r4") = count;
    register vu16 *pointer asm("r1");
    u32 i;

    asm("" : : "r"(outer_count));
    pointer = data;
    asm("" : : "r"(pointer));
    i = 0;
    if (i < outer_count)
    {
        register u32 stride asm("r5") = 0;

        asm("" : "+r"(stride));
        do
        {
            if (i <= 63)
            {
                vu16 *element = (vu16 *)(stride * 2 + (u32)pointer);

                do
                {
                    u16 value = *element;
                    register u32 shifted asm("r0");
                    register u32 step asm("r3");

                    if (value)
                        *element = value;
                    shifted = i << 16;
                    asm("" : : "r"(shifted));
                    step = 0x20000;
                    asm("" : "+r"(step));
                    i = (shifted + step) >> 16;
                } while (i <= 63);
            }
            asm("" : "+r"(pointer));
            pointer = (vu16 *)((u8 *)pointer + stride);
            i = (u16)(i + 1);
        } while (i < outer_count);
    }
}
