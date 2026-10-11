#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0xD2];
    u16 state;
    u8 pad_D4[0x14];
    u16 field_E8;
} D_03004BBC;

void func_0805EE78(s32);
void func_08011E08(void);
void func_0802113C(void);

void func_080210F4(void)
{
    while (D_03004BBC.state != 0)
    {
        if (D_03004BBC.state == 4)
            return;
        func_0805EE78(1);
    }
    D_03004BBC.field_E8 = 1;
    func_08011E08();
    D_02000000.first = func_0802113C;
}
