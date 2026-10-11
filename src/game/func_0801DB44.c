#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
    u16 music;
} D_0200000C;

extern u16 D_02000B54;

void func_0805EE78(s32);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_08008B70(s32, s32, s32);
void func_08008B58(s32);
void func_08011E08(void);
void func_08011E24(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08003D78(s32, void *);
void func_08007188(s32, s32, s32, s32);
void func_080076C0(s32, s32, s32, s32, const void *);
void func_0800BEA4(void);
void func_080014A8(s32, void *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08011F18(s32, s32, s32, s32, s32, s32);
s32 func_08001A28(s32);
void func_08000F88(s32);

struct Obj
{
    u8 pad_0[0x15E];
    u16 x_2;
    u16 y_2;
    u8 pad_162[0x84];
    u16 x_3;
    u16 y_3;
    u8 pad_1EA[0x84];
    u16 x_4;
    u16 y_4;
};

extern struct Obj D_03004BBC;
extern u16 D_03002356;

s32 func_08001040(s32);
void func_08016CA8(s32, u16, u16);
void func_08037990(s32);
void func_08037450(s32);
void func_08008324(s32, s32);
void func_0801D93C(void);
void func_0801D968(void);
void func_0801DD74(void);

void func_0801DB44(void)
{
    struct Obj *obj;
    u32 i;

    func_0805EE78(0x20);
    obj = &D_03004BBC;
    func_08016CA8(7, obj->x_2, obj->y_2);
    func_08008B70(1, 0xFF, 0xFF);
    func_08016CA8(7, obj->x_3, obj->y_3);
    func_08008B70(2, 0xFF, 0xFF);
    func_08016CA8(7, obj->x_4, obj->y_4);
    func_08008B70(3, 0xFF, 0xFF);
    func_08008B58(0x1BD);
    func_08011F18(0, 0x320, 0x160, 0x20, 1, 1);
    func_08000BD8(1, 2);
    func_08008B58(0x1BE);
    if (func_08001040(0x1A4))
    {
        func_08008B58(0x1BF);
        func_08037990(0x5B);
        func_08037450(0x16);
        func_08037450(0x17);
    }
    else
    {
        func_08003D78(4, func_0801D93C);
        func_080019EC(0x81);
        do
            func_0805EE78(1);
        while (!func_08001A28(0x81));
        func_08003D78(4, func_0801D968);
        while (D_03002356 != 0)
            func_0805EE78(1);
        func_08008B58(0x1C1);
    }
    func_08011F18(4, 0x300, 0x200, 0x20, 2, 1);
    func_08008B70(4, 0xFF, 0xFF);
    if (func_08001040(0x1A4))
    {
        func_08008B58(0x1C0);
        func_08003D78(4, func_0801D93C);
        func_080019EC(0x81);
        do
            func_0805EE78(1);
        while (!func_08001A28(0x81));
        func_08003D78(4, func_0801D968);
        while (D_03002356 != 0)
            func_0805EE78(1);
    }
    func_08001A08(5);
    D_02000B54 = 0;
    func_080019B4(5);
    func_08008B58(0x1C2);
    for (i = 0; i <= 0x11F; i++)
    {
        func_08008324(-0x10000, 0);
        func_0805EE78(1);
    }
    for (i = 0; i <= 0x3F; i++)
    {
        func_08008324(0, -0x10000);
        func_0805EE78(1);
    }
    func_08008B70(0, 0x14, 9);
    func_08011F18(0, 0x260, 0x120, 0x20, 1, 0);
    func_08008B58(0x1C3);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0801DD74;
    for (;;)
        func_0805EE78(1);
}
