#include "types.h"

struct Unit
{
    u8 pad_0[0x42];
    u8 kind;
    u8 pad_43[0x289];
};

extern struct
{
    u8 pad_0[8];
    struct Unit units[6];
} D_0200EB84;

s32 func_08032A88(s32, u8);
void func_08031618(struct Unit *, s32);
void func_08031598(u8);

void func_0803C98C(void)
{
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (func_08032A88(0, i) != 0)
        {
            func_08031618(&D_0200EB84.units[i], 0x11);
            func_08031598(D_0200EB84.units[i].kind);
        }
    }
}
