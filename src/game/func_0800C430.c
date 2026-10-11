#include "types.h"

struct TaskState
{
    u8 pad_0[0x18];
    u32 field_18;
    u8 pad_1C[0x6C];
};

extern struct TaskState D_02000034[];

void func_08003DF8(s32, void *);
void func_08043B10(void);
void func_0805EE78(s32);
void func_08003E3C(s32);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_0803E024(s32, s32, s32);

s32 func_0800C430(void)
{
    vu32 zero;
    vu32 *dma;

    func_08003DF8(4, func_08043B10);
    while (D_02000034[4].field_18 != 1)
        func_0805EE78(1);
    func_08003E3C(4);
    *(vu16 *)0x04000000 = 0x1F40;
    *(vu16 *)0x0400000A = 0x109;
    *(vu16 *)0x0400000C = 0x20A;
    *(vu16 *)0x0400000E = 0x30B;
    zero = 0;
    dma = (vu32 *)0x040000D4;
    dma[0] = (u32)&zero;
    dma[1] = 0x06000000;
    dma[2] = 0x85004000;
    dma[2];
    func_08000DB8();
    func_08000D1C(1);
    func_0803E024(0, 0x140, 0xB4);
}
