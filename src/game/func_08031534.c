#include "types.h"

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0x3600];
    struct Entry entries[6];
} D_02000B5C;

struct Unit
{
    u8 pad_0[0x10];
    u32 a;
    u32 b;
    u8 pad_18[0x2AC];
    u32 saved_a;
    u32 saved_b;
};

extern const u16 D_0866B70E[][4];

void func_080316EC(void);
void func_080312F8(u8, u8, u8);

u8 func_08031534(u32 value, u32 max, u16 *out, u16 base)
{
    u8 index;
    u8 i;

    if (value == 0)
        index = 0x18;
    else if (value > max)
        index = 0;
    else
    {
        i = value * 24 / max;
        if (i)
            index = 24 - i;
        else
            index = 0x17;
    }
    for (i = 0; i < 4; i++)
        out[i] = base + D_0866B70E[index][i];
    return index;
}

void func_08031598(u8 pilot)
{
    u8 count = 0;
    u8 position;
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (D_02000B5C.entries[i].zoid != 0xFF)
        {
            if (D_02000B5C.entries[i].pilot == pilot)
                position = count;
            count++;
        }
    }
    for (i = 0; i < 6; i++)
    {
        if (D_02000B5C.entries[i].pilot == pilot)
            break;
    }
    func_080316EC();
    func_080312F8(position, i, count);
}

void func_08031618(struct Unit *unit, u8 flags)
{
    if (flags & 1)
        unit->saved_a = unit->a;
    if (flags & 0x10)
        unit->saved_b = unit->b;
}
