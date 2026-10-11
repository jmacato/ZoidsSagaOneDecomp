#include "types.h"

struct SpriteEntry
{
    u16 id;
    u8 kind;
    u8 flags;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 field_C;
    u16 field_E;
    u16 field_10;
    u16 field_12;
    u8 pad_14[4];
    u32 data;
};

struct SmallEntry
{
    void *data;
    u8 pad_4[8];
};

struct LargeEntry
{
    void *data;
    u8 pad_4[0xC];
};

extern struct SpriteEntry D_0200D920[];
extern const struct SmallEntry D_086F87D0[];
extern const struct SmallEntry D_086F6790[];
extern const struct LargeEntry D_086F7620[];
extern const struct LargeEntry D_086F7FD0[];

void func_0804188C(u16 index, u32 data)
{
    struct SpriteEntry *base = D_0200D920;
    struct SpriteEntry *event = &base[index];

    event->id = 0;
    event->kind = 0;
    event->flags = 0;
    event->x = 0;
    event->y = 0;
    event->width = 0;
    event->height = 0;
    event->field_C = 0;
    event->field_E = 0;
    event->field_10 = 0;
    event->field_12 = 0xFFFF;
    D_0200D920[index].data = data;
}

s32 func_080418CC(u8 kind, u16 index, u16 count)
{
    if (index < count)
    {
        register void *data asm("r0");
        register const void *base asm("r0");

        /* Keep table bases and loaded pointers in the original register. */
        switch (kind)
        {
        case 0:
            base = D_086F87D0;
            asm("" : : "r"(base));
            data = ((const struct SmallEntry *)base)[index].data;
            break;
        case 1:
            base = D_086F6790;
            asm("" : : "r"(base));
            data = ((const struct SmallEntry *)base)[index].data;
            break;
        case 2:
            base = D_086F7620;
            asm("" : : "r"(base));
            data = ((const struct LargeEntry *)base)[index].data;
            break;
        case 3:
            base = D_086F7FD0;
            asm("" : : "r"(base));
            data = ((const struct LargeEntry *)base)[index].data;
            break;
        default:
            return 0;
        }
        asm("" : : "r"(data));
        if (data)
            return 1;
    }
    return 0;
}
