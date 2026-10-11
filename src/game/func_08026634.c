#include "types.h"

struct Pilot
{
    u16 flags;
    u8 pad_2[2];
};

struct Move
{
    u16 id;
    u8 pad_2[6];
};

extern struct
{
    u8 pad_0[0x34A4];
    struct Pilot pilots[0x57];
} D_02000B5C;

extern const struct Move D_0832AE10[];

void func_080372F8(u16);
void func_0803747C(void);

s32 func_08026634(u16 move)
{
    if (move != 0xFF)
    {
        func_080372F8(D_0832AE10[move].id);
        func_0803747C();
    }
}

u16 func_08026654(void)
{
    u16 count = 0;
    u16 i;

    for (i = 4; i <= 0x56; i++)
    {
        if (D_02000B5C.pilots[i].flags & 2)
            count++;
    }
    return count;
}
