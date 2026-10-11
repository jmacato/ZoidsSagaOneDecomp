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
extern struct
{
    u8 pad_0[0x18];
    u16 delay;
} D_0200000C;

u16 func_0800A54C(void);

void func_0800A594(u16 index)
{
    struct Sprite *base = D_03004BBC;
    struct Sprite *sprite = &base[index];

    sprite->field_56 = 0;
    if (sprite->field_4C != 0)
    {
        sprite->field_4C--;
    }
    else
    {
        sprite->field_56 = func_0800A54C();
        D_03004BBC[index].field_7C = 0x8000;
        sprite->field_4C = D_0200000C.delay << 4;
    }
}
