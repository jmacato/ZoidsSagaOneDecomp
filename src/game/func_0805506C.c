#include "types.h"

struct Zoid
{
    u8 pad_0[6];
    u16 kind;
    u8 pad_8[0x30];
};

struct Pilot
{
    u8 pad_0[2];
    u8 zoid;
    u8 pad_3;
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[180];
    u8 pad_348C[0x18];
    struct Pilot pilots[16];
} D_02000B5C;

extern u8 D_0200E8A1;
extern u8 D_0200E7F4[];

void func_0805506C(u16 exclude)
{
    s16 i;

    D_0200E8A1 = 0;
    for (i = 0; i <= 0xAC; i++)
    {
        if (D_02000B5C.zoids[i].kind != 0)
        {
            if ((s16)exclude == 0xFF || i != D_02000B5C.pilots[(s16)exclude].zoid)
            {
                D_0200E7F4[D_0200E8A1] = i;
                D_0200E8A1++;
            }
        }
    }
}
