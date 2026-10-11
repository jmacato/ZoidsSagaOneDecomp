#include "types.h"

struct SioCnt
{
    u32 baud:2;
    u32 si:1;
    u32 sd:1;
    u32 id:2;
    u32 error:1;
    u32 pad:25;
};

struct Sio
{
    u16 cnt;
    u16 send;
};

extern struct
{
    u8 field_0;
    u8 field_1;
    u8 pad_2[2];
    u8 field_4;
    u8 pad_5;
    u8 field_6;
    u8 field_7;
    u8 pad_8[0xC];
    s32 field_14;
    s32 field_18;
    u32 field_1C;
    u32 field_20;
    u32 field_24;
    u32 field_28;
} D_030021A8;

void func_080064CC(void)
{
    if (D_030021A8.field_1 != 0 && D_030021A8.field_6 != 0)
    {
        u32 temp;

        D_030021A8.field_18 = -1;
        temp = D_030021A8.field_28;
        D_030021A8.field_28 = D_030021A8.field_24;
        D_030021A8.field_24 = temp;
        if (D_030021A8.field_4 != 0)
        {
            temp = D_030021A8.field_20;
            D_030021A8.field_20 = D_030021A8.field_1C;
            D_030021A8.field_1C = temp;
            D_030021A8.field_4 = 0;
            D_030021A8.field_14 = 0;
        }
        D_030021A8.field_7 = ((struct SioCnt *)0x04000128)->error;
        ((struct Sio *)0x04000128)->send = 0xFEFE;
        *(vu16 *)0x04000128 |= 0x80;
        *(vu16 *)0x0400010E = 0xC0;
    }
}
