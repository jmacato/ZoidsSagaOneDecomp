#include "types.h"

extern struct
{
    u8 pad_0[2];
    u16 flags;
    u8 pad_4[0x22A4];
    u8 available[4];
    u8 weather;
} D_0200EB84;

extern struct
{
    u8 pad_0[2];
    u8 area;
} D_02000B5C;

extern const u8 D_0866B96C[];
extern const u8 D_0866B980[];

u16 func_08001080(void);

void func_0803680C(void)
{
    u16 roll = (u16)func_08001080() % 20;

    if (roll > 19)
        roll = 0;
    if (D_0200EB84.flags & 1)
        roll = 0;
    if (D_02000B5C.area != 10)
        D_0200EB84.weather = D_0866B96C[roll];
    else
        D_0200EB84.weather = D_0866B980[roll];
    switch (D_0200EB84.weather)
    {
    case 4:
        if (D_0200EB84.available[3] == 0xFF)
            D_0200EB84.weather = 0;
        break;
    case 3:
        if (D_0200EB84.available[2] == 0xFF)
            D_0200EB84.weather = 0;
        break;
    case 2:
        if (D_0200EB84.available[1] == 0xFF)
            D_0200EB84.weather = 0;
        break;
    case 1:
        if (D_0200EB84.available[0] == 0xFF)
            D_0200EB84.weather = 0;
        break;
    }
}
