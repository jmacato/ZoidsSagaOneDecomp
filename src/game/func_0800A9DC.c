#include "types.h"

struct Sprite
{
    u8 pad_0[0x4C];
    u16 field_4C;
    u8 pad_4E[8];
    u16 field_56;
    u8 pad_58[0x24];
    u32 field_7C;
    u8 pad_80[8];
};

extern struct Sprite D_03004BBC[];
extern u16 D_03002358;
extern u16 D_0300235A;
extern struct
{
    u8 pad_0[0x18];
    u16 delay;
} D_0200000C;

void func_0800A9DC(u16 index)
{
    struct Sprite *base = D_03004BBC;
    struct Sprite *sprite = &base[index];
    u16 *held = &D_03002358;

    sprite->field_56 = ((D_0300235A & 9) + 0x3F2) & *held;
    D_03004BBC[index].field_7C = 0x10000;
    sprite->field_4C = D_0200000C.delay << 3;
}
