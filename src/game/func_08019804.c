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
void func_080197B0(void);
void func_08000FD8(s32);

void func_08019804(void)
{
    func_08008B58(0x170);
    if (D_02007574.confirmed == 0 || D_02007574.choice == 1)
    {
        func_08011E08();
        D_02000000.first = func_08008024;
        func_08003DD8(3);
        func_08007188(0x95, 0x17, 0x1A, 0xFFFF);
        func_080014A8(1, func_0800BEA4);
        D_02000000.first = func_080197B0;
    }
    else
    {
        func_08000FD8(0x189);
        func_08000FD8(0x18A);
        func_08000FD8(0x18B);
        func_08000FD8(0x18C);
        func_08000FD8(0x18D);
        func_08000FD8(0x18E);
        func_08011E08();
        D_02000000.first = func_08008024;
        func_08003DD8(3);
        func_08007188(0x85, 7, 3, 0xFFFF);
        func_080014A8(1, func_0800BEA4);
    }
}
