#include "types.h"

struct Unit
{
    u8 pad_0[0x38];
    s16 field_38;
    s16 field_3A;
};

s32 func_080346C0(s32, u8);

void func_08033874(struct Unit *unit, u8 rate)
{
    s32 delta;

    delta = func_080346C0(unit->field_38, rate);
    unit->field_38 += delta;
    delta = func_080346C0(unit->field_3A, rate);
    unit->field_3A += delta;
}
