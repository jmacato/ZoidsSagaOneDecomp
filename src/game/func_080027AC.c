#include "types.h"

struct Task
{
    u8 pad_0[8];
    u32 message;
    u32 done;
    u8 pad_10[8];
    u32 busy;
    u8 pad_1C[0x6C];
};

extern struct
{
    u8 pad_0[8];
    s32 x;
    s32 y;
    s32 scroll_x;
    s32 scroll_y;
    s32 x2;
    s32 y2;
} D_03004B9C;

extern u8 D_0200E8A8;
extern u8 D_02000030;
extern struct Task D_02000034[];
extern u16 D_0300235A;
extern void *D_03000204;
extern u16 D_0300239C[][32];
extern const u16 D_08663F30[];
extern const u8 D_08663E20[];

void func_08003DD8(s32);
void func_0805EE78(s32);
void func_0800292C(void);
void func_08002450(s32);
void func_080029DC(void);
void func_08002404(s32, s32);
void func_08002E94(void);
void func_08000CEC(s32, const void *, s32);
void func_08003DF8(s32, void *);
void func_08004034(void);

void func_080027AC(void)
{
    u32 i;

    do
    {
        if (D_0200E8A8 & 8)
            func_08003DD8(D_02000030);
        func_0805EE78(1);
    } while (!(D_0300235A & 8));
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    D_03000204 = func_0800292C;
    func_0805EE78(1);
    *(vu16 *)0x04000200 &= 0xFFFD;
    func_08002450(0x413);
    for (i = 0; i <= 8; i++)
    {
        D_0300239C[0x20][10 + i] = 0xB102 + D_08663F30[i];
        D_0300239C[0x25][10 + i] = 0xB102 + D_08663F30[i + 9];
    }
    func_080029DC();
    D_03004B9C.x = 0xFFFC0000;
    D_03004B9C.y = 0xFFE80000;
    func_08002404(0, 0xB);
    D_03004B9C.x2 = 0xFFB40000;
    D_03004B9C.y2 = 0xFFE00000;
    func_08002E94();
    D_03004B9C.scroll_y = 0;
    D_03004B9C.scroll_x = 0;
    *(vu16 *)0x0400000C &= 0xFF70;
    *(vu16 *)0x0400000C |= 0x82;
    func_08000CEC(1, D_08663E20, 0);
    func_08003DF8(10, func_08004034);
    D_02000034[10].message = 0;
    D_02000034[10].done = 0;
    func_0805EE78(1);
    *(vu16 *)0x04000000 |= 0x1E00;
    do
        func_0805EE78(1);
    while (D_02000034[10].busy != 1);
    D_0200E8A8 |= 8;
    func_08003DD8(D_02000030);
}
