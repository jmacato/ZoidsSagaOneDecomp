#include "types.h"

extern struct
{
    u8 row;
    u8 pad_1[5];
    u8 grid[20][9];
    u8 flags[20][9];
} D_0200EA14;

extern u8 D_02007FAB[];
extern u8 D_08675BEC[];
extern u8 D_08675C5C[];

void func_080339F8(u8, s32, u8, u8 *);
void func_0803E488(u8 *, s32);
void func_0803B6EC(u8, u8);

void func_0803B650(u8 index)
{
    u16 i;

    func_080339F8(index, 0, D_0200EA14.row, D_02007FAB);
    func_0803E488(D_08675BEC, 0xC);
    func_0803E488(D_08675BEC, 0xA);
    func_0803B6EC(D_0200EA14.grid[index][0], D_0200EA14.flags[index][0]);
    for (i = 1; i <= 5; i++)
    {
        if (D_0200EA14.grid[index][i] != 0xFF)
        {
            func_0803E488(D_08675C5C, 0);
            func_0803B6EC(D_0200EA14.grid[index][i], D_0200EA14.flags[index][i]);
        }
    }
    func_0803E488(D_08675BEC, 0xA);
}
