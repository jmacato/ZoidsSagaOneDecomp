#include "types.h"

struct Sprite
{
    u8 pad_0[0x4A];
    u16 state;
    u8 pad_4C[0xC];
    u16 target;
    u8 pad_5A[8];
    u16 type;
    u8 pad_64[0x1C];
    u32 script;
    u8 pad_84[4];
};

extern struct Sprite D_03004BBC[];

extern struct
{
    u8 pad_0[0xD28];
    u32 money;
    u8 pad_D2C[0x33E2 - 0xD2C];
    u8 items[0x96];
} D_02000B5C;

extern u8 D_02003EA8[];
extern u8 D_02003E61[];
extern u8 D_02003E68[];

u16 func_080084D4(u16, s16, s16);
void func_08000BD8(s32, s32);
void func_0803699C(u16, s32);
void func_0803723C(s32, s32, s32);
void func_0803702C(u16);

void func_0800B328(u16 sprite, u16 dir, s16 x, s16 y)
{
    u16 hit;
    u16 target;

    hit = func_080084D4(sprite, x, y);
    if (hit & 0x2000)
    {
        target = hit & 0xFF;
        if (D_03004BBC[target].type == 4)
        {
            D_03004BBC[sprite].state = 9;
            D_03004BBC[sprite].target = target;
        }
        else if (D_03004BBC[target].state == 0 && D_03004BBC[target].type != 5)
        {
            D_03004BBC[sprite].target = target;
            D_03004BBC[target].state = 1;
            if (D_03004BBC[target].type <= 1)
                func_08000BD8(target, dir ^ 1);
            if (D_03004BBC[D_03004BBC[sprite].target].script == 0)
                D_03004BBC[sprite].state = 3;
            else
                D_03004BBC[sprite].state = 7;
        }
    }
}

void func_0800B3F0(void)
{
    u16 i;

    D_02000B5C.money = 9999999;
    for (i = 2; i <= 0x95; i++)
    {
        if (i != 0x53 && i != 0x54 && i != 0x57 && i != 0x75)
            func_0803699C(i, 0);
        D_02000B5C.items[i] = 1;
    }
    func_0803723C(4, 2, 0);
    func_0803723C(5, 2, 0);
    func_0803723C(6, 2, 0);
    func_0803723C(7, 2, 0);
    for (i = 0; i <= 0x20; i++)
        func_0803702C(i);
    for (i = 0; i <= 0x80; i++)
        D_02003EA8[i] = 99;
    for (i = 0; i <= 6; i++)
        D_02003E61[i] = 99;
    for (i = 0; i <= 0x3F; i++)
        D_02003E68[i] = 99;
}
