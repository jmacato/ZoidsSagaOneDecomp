#include "types.h"

struct Zoid
{
    u8 pad_0[2];
    u16 flags;
    u8 pad_4[0x34];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[0xAD];
    u8 count;
} D_02000B5C;


void func_0805D270(const void *, void *, u32);
void func_08036A98(u8, struct Zoid *, u8);

u8 func_0803699C(u8 id, u8 mode)
{
    s16 found = 0xFF;
    s16 i;
    u8 slot;
    vu16 zero;

    if (mode != 1)
    {
        D_02000B5C.count = 0;
        for (i = 0; i <= 0x98; i++)
        {
            if (!(D_02000B5C.zoids[i].flags & 1))
            {
                if (found == 0xFF)
                {
                    found = 1;
                    slot = i;
                }
            }
            else
                D_02000B5C.count++;
        }
    }
    else
    {
        for (i = 0x99; i <= 0xAC; i++)
        {
            if (!(D_02000B5C.zoids[i].flags & 1))
            {
                found = 1;
                slot = i;
                break;
            }
        }
    }
    if (found == 1)
    {
        zero = 0;
        func_0805D270((void *)&zero, &D_02000B5C.zoids[slot], 0x0100001C);
        func_08036A98(id, &D_02000B5C.zoids[slot], slot);
        found = slot;
    }
    return found;
}
