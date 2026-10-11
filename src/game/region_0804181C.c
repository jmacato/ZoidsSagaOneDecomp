#include "types.h"

struct Sprite
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
    u8 pad_10[2];
    u16 field_12;
    u8 pad_14[4];
    void *data;
};

extern struct Sprite D_0200D920[];

void region_0804181C(u16 index, u16 id, u8 kind, u8 flags, u16 x, u16 y, u16 width, u16 height, u16 field_C,
                     u16 field_E, u16 field_12, void *data)
{
    D_0200D920[index].id = id;
    D_0200D920[index].kind = kind;
    D_0200D920[index].flags = flags;
    D_0200D920[index].x = x;
    D_0200D920[index].y = y;
    D_0200D920[index].width = width;
    D_0200D920[index].height = height;
    D_0200D920[index].field_C = field_C;
    D_0200D920[index].field_E = field_E;
    D_0200D920[index].field_12 = field_12;
    D_0200D920[index].data = data;
}
