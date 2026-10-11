#include "types.h"

struct Link
{
    u8 pad_0[0x14];
    u32 field_14;
    u32 field_18;
    u8 *buffers[5];
    u8 buffer_0[0x20];
    u8 buffer_1[0x20];
    u8 buffer_2[0x40];
    u8 buffer_3[0x40];
    u8 buffer_4[0x40];
};

extern struct Link D_030021A8;
extern u8 D_03001FA8[];
extern u8 D_03001FE8[];

void func_0805D270(void *, void *, u32);

void func_080061BC(void)
{
    u32 zero;

    *(vu16 *)0x04000208 = 0;
    *(vu16 *)0x04000200 &= 0xFF3F;
    *(vu16 *)0x04000208 = 1;
    *(vu16 *)0x04000134 = 0;
    *(vu16 *)0x04000128 = 0x2000;
    *(vu16 *)0x04000128 |= 0x4003;
    zero = 0;
    func_0805D270(&zero, &D_030021A8, 0x0500004C);
    func_0805D270((void *)0x08000424, D_03001FA8, 0x04000010);
    func_0805D270((void *)0x0800652D, D_03001FE8, 0x04000070);
    D_030021A8.field_14 = 16;
    D_030021A8.field_18 = 16;
    D_030021A8.buffers[0] = D_030021A8.buffer_0;
    D_030021A8.buffers[1] = D_030021A8.buffer_1;
    D_030021A8.buffers[2] = D_030021A8.buffer_2;
    D_030021A8.buffers[3] = D_030021A8.buffer_3;
    D_030021A8.buffers[4] = D_030021A8.buffer_4;
    *(vu16 *)0x04000208 = 0;
    *(vu16 *)0x04000200 |= 0x80;
    *(vu16 *)0x04000208 = 1;
}
