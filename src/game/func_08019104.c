#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u16 confirmed;
    u16 choice;
} D_02007574;

void func_08008B58(s32);
void func_08011E08(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08007188(s32, s32, s32, s32);
void func_0800BEA4(void);
void func_080014A8(s32, void *);
void func_080190B0(void);
void func_08000FD8(s32);

void func_08019104(void)
{
    func_08008B58(0x132);
    if (D_02007574.confirmed == 0 || D_02007574.choice == 1)
    {
        func_08011E08();
        D_02000000.first = func_08008024;
        func_08003DD8(3);
        func_08007188(0x8F, 0x17, 0x1A, 0xFFFF);
        func_080014A8(1, func_0800BEA4);
        D_02000000.first = func_080190B0;
    }
    else
    {
        func_08000FD8(0x17B);
        func_08000FD8(0x17D);
        func_08000FD8(0x17E);
        func_08000FD8(0x17F);
        func_08000FD8(0x180);
        func_08000FD8(0x181);
        func_08011E08();
        D_02000000.first = func_08008024;
        func_08003DD8(3);
        func_08007188(0x85, 0xC, 0xD, 0xFFFF);
        func_080014A8(1, func_0800BEA4);
    }
}
