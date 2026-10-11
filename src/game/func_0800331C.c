#include "types.h"

extern u8 D_0200E8A8;
extern u16 D_0300239C[];

void func_0805EE78(s32);
void func_08003DD8(s32);

void func_0800331C(void)
{
    u32 row;
    u32 column;

    while (!(D_0200E8A8 & 6))
        func_0805EE78(1);
    func_08003DD8(4);
    func_0805EE78(1);
    for (row = 9; row <= 9; row++)
    {
        for (column = 0; column <= 8; column++)
            D_0300239C[row * 32 + 0x40A + column] = 0x100;
    }
    func_08003DD8(5);
    func_0805EE78(1);
}
