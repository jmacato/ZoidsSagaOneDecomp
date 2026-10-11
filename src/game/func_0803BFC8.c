#include "types.h"

extern struct
{
    u8 row;
    u8 pad_1[5];
    u8 grid[20][9];
    u8 flags[20][9];
} D_0200E8A4;

extern u8 D_02007C57[];
extern u8 D_08675BEC[];
extern u8 D_08675C5C[];
extern u8 D_08675DD4[];

void func_080339F8(u8, s32, u8, u8 *);
void func_0803E488(u8 *, s32);
void func_0803C084(u8, u8);

void func_0803BFC8(u8 index)
{
    u16 i;

    func_080339F8(index, 0, D_0200E8A4.row, D_02007C57);
    func_0803E488(D_08675BEC, 0xB);
    func_0803E488(D_08675BEC, 9);
    func_0803E488(D_08675DD4, 1);
    func_0803E488(D_08675C5C, 0x24);
    func_0803C084(D_0200E8A4.grid[index][0], D_0200E8A4.flags[index][0]);
    for (i = 1; i <= 5; i++)
    {
        func_0803E488(D_08675C5C, 0);
        func_0803E488(D_08675DD4, i + 1);
        func_0803E488(D_08675C5C, 0x24);
        func_0803C084(D_0200E8A4.grid[index][i], D_0200E8A4.flags[index][i]);
    }
    func_0803E488(D_08675BEC, 9);
}
