#include "types.h"

struct Zoid
{
    u8 data[0x38];
};

struct Pilot
{
    u16 flags;
    u8 zoid;
    u8 pad_3;
};

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
    u8 pad_D64[0x34A4 - 0xD64];
    struct Pilot pilots[0x57];
    struct Entry entries[6];
} D_02000B5C;

void func_0805D270(const void *, void *, u32);
void func_08037A88(u8);
void func_08036B98(u8);

void func_080372F8(u8 index)
{
    u8 i;

    if (D_02000B5C.pilots[index].flags & 2)
    {
        if (D_02000B5C.pilots[index].flags & 0x10)
        {
            for (i = 0; i < 6; i++)
            {
                if (D_02000B5C.entries[i].pilot == index)
                {
                    func_08037A88(i);
                    break;
                }
            }
            D_02000B5C.pilots[index].flags &= 0xFFEF;
        }
        if (D_02000B5C.pilots[index].flags & 8)
        {
            struct Zoid *zoid = &D_02000B5C.zoids[D_02000B5C.pilots[index].zoid];
            vu16 zero = 0;

            func_0805D270((void *)&zero, zoid, 0x0100001C);
            D_02000B5C.pilots[index].zoid = 0xFF;
            D_02000B5C.pilots[index].flags &= 0xFFF7;
        }
        if (D_02000B5C.pilots[index].zoid != 0xFF)
            func_08036B98(index);
        if (D_02000B5C.pilots[index].flags & 4)
            D_02000B5C.pilots[index].flags &= 0xFFFB;
        D_02000B5C.pilots[index].flags &= 0xFFFD;
    }
}
