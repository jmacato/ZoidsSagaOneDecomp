#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0x86];
};

struct Slot
{
    u16 active;
    u8 pad_2[0x1A];
};

extern struct Sprite D_03004BBC[];
extern const u8 D_086D41D8[];
extern u8 D_086D41CC[2][6];
extern u8 D_0200E24A;
extern struct Slot D_0200D920[];

void func_080455A8(s32, s32, s32);
void func_08045568(const u8 *, u16, s32);
void func_0804551C(const u8 *, u16, s32);
void func_08000DF4(u8);
void func_0805EE78(s32);

void func_080452C4(s32 unused, u8 mode)
{
    u8 j = 0;
    u8 i;
    u32 k;

    switch (mode)
    {
    case 0:
        func_080455A8(0x17, 0, 0);
        D_03004BBC[23].flags |= 0x8000;
        func_08045568(D_086D41D8, 0, 0);
        for (i = 1; i <= 15; i++)
        {
            func_08045568(D_086D41D8, i, 0);
            for (j = 0x13; j != 0; j--)
                func_08000DF4(j);
            func_0805EE78(1);
        }
        D_03004BBC[23].flags &= 0xFFDF;
        func_0804551C(D_086D41D8, 0, 0);
        {
            register struct Slot *slots asm("r3");
            i = 0;
            asm("" : : "r"(i));
            slots = D_0200D920;
            asm("" : : "r"(slots));
            for (; i <= 5; i++)
            {
                if (D_0200E24A)
                {
                    k = D_086D41CC[1][i];
                    asm("" : "+r"(k));
                    k += 6;
                }
                else
                    k = D_086D41CC[0][i];
                if (slots[k].active)
                    D_03004BBC[i + 14].flags |= 0x8000;
            }
        }
        for (j = 0x13; j != 0; j--)
            func_08000DF4(j);
        func_0805EE78(1);
        for (i = 1; i <= 15; i++)
        {
            func_0804551C(D_086D41D8, i, 0);
            for (j = 0x13; j != 0; j--)
                func_08000DF4(j);
            func_0805EE78(1);
        }
        break;
    case 1:
        j = 1;
    case 2:
        j++;
        func_0804551C(D_086D41D8, 15, 0);
        func_08045568(D_086D41D8, 15, 0);
        {
            register struct Slot *slots asm("r3");
            i = 0;
            asm("" : : "r"(i));
            slots = D_0200D920;
            asm("" : : "r"(slots));
            for (; i <= 5; i++)
            {
                if (D_0200E24A)
                {
                    k = D_086D41CC[1][i];
                    asm("" : "+r"(k));
                    k += 6;
                }
                else
                    k = D_086D41CC[0][i];
                if (slots[k].active)
                    D_03004BBC[i + 14].flags |= 0x8000;
            }
        }
        func_0805EE78(j);
        for (i = 0; i <= 14; i++)
        {
            func_0804551C(D_086D41D8, 14 - i, 0);
            func_08045568(D_086D41D8, 14 - i, 0);
            func_0805EE78(j);
        }
        for (i = 0; i <= 5; i++)
            D_03004BBC[i + 14].flags &= 0x7FFF;
        D_03004BBC[23].flags &= 0x7FFF;
        break;
    }
}
