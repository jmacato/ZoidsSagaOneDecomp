#include "types.h"

extern u16 D_03002358;
void func_08044DE8(u32, s32, s32);
void func_0805EE78(u32);

u32 func_08044D10(u8 selected)
{
    register u32 mode asm("r6") = selected;
    register u32 position asm("r5");
    register u32 step asm("r4");
    asm("" : : "r"(mode));
    switch (mode)
    {
    case 0:
        position = 0x400000;
        asm("" : : "r"(position));
        break;
    case 1:
        position = 0;
        asm("" : : "r"(position));
        break;
    }
    step = 0x2000;
    asm("" : : "r"(step));
    for (;;)
    {
        switch (mode)
        {
        case 0:
            if (position > 0xFF800000)
            {
                func_08044DE8(0, 0, 0);
                return 0;
            }
            func_08044DE8(0, position, 0);
            position -= step;
            if (D_03002358 & 2)
                step += 0x8000;
            else
                step += 0x1000;
            break;
        case 1:
            if (position > 0x400000)
            {
                func_08044DE8(0, 0x400000, 0);
                return 0;
            }
            func_08044DE8(0, position, 0);
            position += step;
            if (D_03002358 & 2)
                step += 0x8000;
            else
                step += 0x1000;
            break;
        }
        func_0805EE78(1);
    }
}
