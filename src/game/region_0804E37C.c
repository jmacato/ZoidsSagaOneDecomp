#include "types.h"

extern u16 D_0300234A;
extern u16 D_03002350;
extern u16 D_03002342;
extern u16 D_03002346;
extern u8 D_03002B9C[];
extern const u8 D_0875BA9C[];

extern struct
{
    u8 pad_0[0x558];
    u32 field_558;
    u32 field_55C;
} D_02000034;

void func_08000DB8(void);
void func_08000D1C(s32);
void func_08001A54(const u8 *, s32, s32);
void func_0803E024(s32, s32, s32);
void func_08003DF8(s32, void *);
void func_08053524(void);
void func_08004034(void);

void region_0804E37C(u8 task)
{
    func_08000DB8();
    {
        vu32 fill = 0x01340134;
        vu32 *dma = (vu32 *)0x040000D4;

        dma[0] = (vu32)&fill;
        dma[1] = (vu32)D_03002B9C;
        dma[2] = 0x85000400;
        dma[2];
    }
    func_08000D1C(0);
    *(vu16 *)0x04000000 = 0x1F40;
    *(vu16 *)0x0400000A = 0x185;
    *(vu16 *)0x0400000C = 0x38B;
    *(vu16 *)0x0400000E = 0x48B;
    D_0300234A = 0x1F;
    D_03002350 = 0x1F;
    D_03002342 = 0x897;
    D_03002346 = 0x205F;
    func_08001A54(D_0875BA9C, 0, 1);
    func_08001A54(D_0875BA9C, 1, 1);
    func_08001A54(D_0875BA9C, 2, 1);
    func_08001A54(D_0875BA9C, 3, 1);
    func_0803E024(3, 0, 0xFF);
    func_08003DF8(task, func_08053524);
    func_08003DF8(10, func_08004034);
    D_02000034.field_558 = 0;
    D_02000034.field_55C = 0;
}
