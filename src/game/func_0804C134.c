#include "types.h"

extern u16 D_0200758C[];
extern u16 D_030022E8[];

u16 func_0804C0B0(s32, u16, u16);

void func_0804C134(u8 slot, u16 key)
{
    u16 *name = &D_0200758C[slot];
    u16 *code = &D_030022E8[slot];

    if (*name != func_0804C0B0(0, *code, key))
    {
        *name = func_0804C0B0(0, *code, key);
        return;
    }
    switch (key)
    {
    case 0xFFFF:
        *name = 0x814A;
        break;
    case 0xFFFE:
        *name = 0x814B;
        break;
    }
    *(D_030022E8 + slot) = D_0200758C[slot];
}
