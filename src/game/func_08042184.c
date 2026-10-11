#include "types.h"

extern const u8 D_086F87D0[];
extern const u8 D_086F6790[];
extern const u8 D_086F7620[];

s32 func_08044DB8(const void *, u16);
u8 func_08044DD4(const void *, u16);

u32 func_08042184(u16 kind, u16 value)
{
    switch (kind)
    {
    case 0x149:
    case 0x14F:
        value = 0x8000;
        break;
    case 0xF2:
        value = 0x8001;
        break;
    case 0x236:
        value = 0x8002;
        break;
    case 0x224:
        value = 0x8003;
        break;
    case 0x22A:
        value = 0x8004;
        break;
    case 0x161:
        value = 0x8005;
        break;
    }
    return value;
}

u16 func_08042210(u16 start)
{
    u16 i = start + 1;

    while (!(u8)func_08044DB8(D_086F87D0, i))
    {
        if (i == 0xA0)
            i = 0;
        else
            i++;
    }
    return i;
}

u16 func_08042244(u16 start)
{
    u16 i = start + 1;

    for (;;)
    {
        register u32 selector asm("r0") = (u32)(i * 3) << 16;

        asm("" : "+r"(selector));
        if ((u8)func_08044DB8(D_086F6790, selector >> 16))
            break;
        if (i == 8)
            i = 0;
        else
            i++;
    }
    return i;
}

u16 func_08042280(u16 start)
{
    u16 i = start + 1;

    while (!func_08044DD4(D_086F7620, i))
    {
        if (i == 0x96)
            i = 0;
        else
            i++;
    }
    return i;
}
