#include "types.h"

struct Sprite
{
    u8 pad_0[0x56];
    u16 field_56;
    u8 pad_58[8];
    u16 field_60;
    u8 pad_62[2];
    u16 slot;
    u16 script;
    u16 step;
    u16 field_6A;
    u16 field_6C;
    u8 pad_6E[0x1A];
};

struct Slot
{
    u8 pad_0[8];
    u16 script;
    u8 state;
    u8 step;
    u8 field_C;
    u8 field_D;
    u8 pad_E[2];
};

extern struct Sprite D_03004BBC[];
extern const u16 *const D_08320258[];
extern struct
{
    u8 pad_0[0x50];
    struct Slot slots[32];
} D_02000B5C;

void func_0800AB18(u16 index)
{
    const u16 *script;

    D_03004BBC[index].field_56 = 0;
    script = D_08320258[D_03004BBC[index].script];
    D_03004BBC[index].step = 0;
    D_03004BBC[index].field_6A = script[0];
    D_03004BBC[index].field_6C = script[D_03004BBC[index].step * 2 + 1];
    D_03004BBC[index].field_60 = 9;
    if (D_03004BBC[index].slot != 0xFFFF)
    {
        D_02000B5C.slots[D_03004BBC[index].slot].state = D_03004BBC[index].field_60;
        D_02000B5C.slots[D_03004BBC[index].slot].script = D_03004BBC[index].script;
        D_02000B5C.slots[D_03004BBC[index].slot].step = D_03004BBC[index].step;
        D_02000B5C.slots[D_03004BBC[index].slot].field_C = D_03004BBC[index].field_6A;
        D_02000B5C.slots[D_03004BBC[index].slot].field_D = D_03004BBC[index].field_6C;
    }
}
