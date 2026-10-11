#include "types.h"

struct Unit
{
    u8 pad_0[0x4A];
    u8 kind;
    u8 pad_4B[0x281];
};

extern struct
{
    struct Unit units[6];
    u8 pad_10C8[0x1128];
    u8 refresh;
} D_0200EB84;

s32 func_08032A88(s32, u8);

void func_0803CC00(void)
{
    u8 i;

    D_0200EB84.refresh = 1;
    for (i = 0; i <= 5; i++)
    {
        if (func_08032A88(0, i) != 0 && D_0200EB84.units[i].kind == 0)
        {
            D_0200EB84.refresh = 0xFF;
            break;
        }
    }
}
