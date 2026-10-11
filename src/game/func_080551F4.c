#include "types.h"

struct Zoid
{
    u16 flags;
    u8 pad_2[4];
    u16 id;
    u8 pad_8[0x30];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[0xAD];
} D_02000B5C;

extern u8 D_0200E8A1;
extern u8 D_0200E7F4[];

void func_080551F4(void)
{
    s16 i;

    D_0200E8A1 = 0;
    for (i = 0; i <= 0xAC; i++)
    {
        if (D_02000B5C.zoids[i].id != 0 && (D_02000B5C.zoids[i].flags & 0x800))
        {
            D_0200E7F4[D_0200E8A1] = i;
            D_0200E8A1++;
        }
    }
}
