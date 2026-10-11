#include "types.h"

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

struct Info
{
    u8 pad_0[0x35];
    u8 size;
};

extern struct
{
    u8 pad_0[0x3600];
    struct Entry entries[6];
} D_02000B5C;

u8 func_080371E8(u8);
void func_08037A88(u8);
void func_08037A20(u8, u8);

void region_08037118(u8 position, u8 pilot, struct Info *info)
{
    u8 list[3];
    u8 count;
    u8 i;

    if (info->size != 2)
    {
        u8 other = func_080371E8(position);

        list[0] = other == 0xFF ? position : other;
        count = 1;
    }
    else
    {
        if (position == 1)
        {
            for (i = 0; i < 3; i++)
                list[i] = i;
        }
        else
        {
            for (i = 0; i < 3; i++)
                list[i] = i + 3;
        }
        count = 3;
    }
    for (i = 0; i < count; i++)
    {
        if (D_02000B5C.entries[list[i]].pilot != 0xFF)
            func_08037A88(list[i]);
    }
    func_08037A20(pilot, position);
}
