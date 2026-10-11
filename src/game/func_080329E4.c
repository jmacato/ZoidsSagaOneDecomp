#include "types.h"

struct Effect
{
    u32 data[7];
    u8 power;
    u8 pad_1D[3];
    u8 kind;
    u8 mode;
    u8 pad_22[2];
};

extern struct
{
    u16 flags;
    u8 type;
    u8 kind;
    u8 field_4;
    u8 power;
    u8 pad_6[2];
    u8 field_8;
    u8 base;
} D_02005C70;
extern struct
{
    u8 pad_0[0x11DC];
    struct Effect effect;
} D_02004A70;
extern const struct Effect D_0867BF4C[];

void func_080329E4(u16 flags, u8 type, u8 power, u8 base)
{
    D_02005C70.flags = flags;
    D_02005C70.field_4 = 0;
    D_02005C70.power = power;
    D_02005C70.field_8 = 0;
    D_02005C70.base = base;
    D_02005C70.type = type;
    D_02005C70.kind = 0x17;
    if (flags & 1)
    {
        D_02004A70.effect = D_0867BF4C[type];
        D_02005C70.power = D_02005C70.base = D_02004A70.effect.power;
        D_02005C70.kind = D_02004A70.effect.kind;
        if (D_02004A70.effect.mode == 1)
        {
            D_02005C70.flags |= 2;
            D_02005C70.flags |= 8;
        }
        else if (D_02004A70.effect.mode == 2)
        {
            D_02005C70.flags |= 4;
            D_02005C70.flags |= 8;
        }
        else if (D_02004A70.effect.mode == 3)
        {
            D_02005C70.flags |= 8;
        }
    }
}
