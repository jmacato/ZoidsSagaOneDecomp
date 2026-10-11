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
    vu16 delay;
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

extern u16 D_02007560[];

void func_08008324(s32, s32);
s32 func_08008D28(s32);
void func_08006E08(void);
void func_080079E8(s32, s32, s32, s32, const void *);
void func_080089A0(s32, s32);
void func_08008E4C(s32);
void func_08009938(void);
void func_0803785C(s32);
void func_08001524(s32, void *);
void func_08037990(s32);
void func_08037920(s32);
void func_08006DFC(s32);
s32 func_08001040(s32);
void func_08000FD8(s32);
void func_0800BEC8(void);

struct Obj
{

};

extern struct Obj D_03004BBC;

extern u32 D_08668F08[];
extern const u8 D_08668F44[];
extern const u8 D_08668FBC[];
void func_08008024(void);
void func_0800BEA4(void);
void func_0801B030(void);

extern u8 D_030022E0;
void func_08037424(s32);

void func_0801A904(void)
{
    func_08011E24();
    switch (D_030022E0)
    {
    case 4:
        func_08008B58(D_08668F08[D_030022E0]);
        if (!func_08001040(0x191))
        {
            func_08000F88(0x191);
            func_08011E08();
            func_080076C0(0x90, 0xB, 9, 6, D_08668F44);
            func_08001A08(0x12);
            D_02000B54 = 0;
            func_080019B4(0x12);
            func_08011E24();
            func_08008B58(0x149);
            if (func_08001040(0x17C))
            {
                func_08008B70(5, 9, 0xD);
                func_08011F18(5, 0x80, 0xA0, 0x10, 1, 1);
                func_08008B58(0x14A);
                func_08011F18(4, 0x70, 0x30, 0x10, 1, 1);
                func_08008B70(4, 0xFF, 0xFF);
                func_08008B58(0x14B);
            }
            else
            {
                func_08008B58(0x14C);
                func_08000F88(0x182);
                func_08037424(0x10);
            }
        }
        break;
    case 9:
        func_08008B58(D_08668F08[D_030022E0]);
        if (!func_08001040(0x192))
        {
            func_08000F88(0x192);
            func_08011E08();
            func_080076C0(0x93, 9, 9, 9, D_08668FBC);
            func_08001A08(0x12);
            D_02000B54 = 0;
            func_080019B4(0x12);
            func_08008B70(0, 0xFF, 0xFF);
            func_08011E24();
            func_08008B58(0x167);
            func_08008B70(0, 9, 0xD);
            func_08011F18(0, 0x90, 0xC0, 0x10, 1, 0);
            func_08011F18(0, 0xA0, 0xA0, 0x10, 1, 0);
            func_08000BD8(1, 0);
            func_08008B70(4, 9, 0xD);
            func_08011F18(4, 0x90, 0xC0, 0x10, 1, 1);
            func_08011F18(4, 0x90, 0xA0, 0x10, 1, 1);
            func_08000BD8(5, 0);
            func_08008B70(5, 9, 0xD);
            func_08011F18(5, 0x90, 0xC0, 0x10, 1, 1);
            func_08011F18(5, 0x80, 0xA0, 0x10, 1, 1);
            func_08000BD8(6, 0);
            func_08008B70(1, 9, 0xD);
            func_08011F18(1, 0x90, 0xC0, 0x10, 1, 1);
            func_08011F18(1, 0x90, 0xB0, 0x10, 1, 1);
            func_08000BD8(2, 0);
            func_08008B70(2, 9, 0xD);
            func_08011F18(2, 0x90, 0xC0, 0x10, 1, 1);
            func_08011F18(2, 0x80, 0xB0, 0x10, 1, 1);
            func_08000BD8(3, 0);
            func_08008B70(3, 9, 0xD);
            func_08011F18(3, 0x90, 0xC0, 0x10, 1, 1);
            func_08011F18(3, 0x70, 0xC0, 0x10, 1, 1);
            func_08011F18(3, 0x70, 0xB0, 0x10, 1, 1);
            func_08000BD8(4, 0);
            func_0805EE78(0xF);
            func_08000BD8(7, 1);
            func_08000BD8(8, 1);
            func_08000BD8(9, 1);
            func_0805EE78(0xF);
            func_08008B58(0x168);
            if (func_08001040(0x182))
            {
                func_08008B58(0x169);
                func_08011F18(1, 0x90, 0xC0, 0x10, 1, 1);
                func_08011F18(1, 0xA0, 0xC0, 0x10, 1, 1);
                func_08000BD8(2, 2);
                func_08011F18(2, 0x80, 0xC0, 0x10, 1, 1);
                func_08011F18(2, 0x70, 0xC0, 0x10, 1, 1);
                func_08000BD8(3, 3);
                func_08011F18(4, 0x90, 0xB0, 0x10, 1, 1);
                func_08011F18(4, 0xA0, 0xB0, 0x10, 1, 1);
                func_08000BD8(5, 2);
                func_08011F18(5, 0x70, 0xA0, 0x10, 1, 1);
                func_08000BD8(6, 3);
                func_08000BD8(1, 2);
                func_08000BD8(4, 3);
                func_08011F18(7, 0x80, 0xD0, 0x10, 1, 1);
                func_08008B70(7, 0xFF, 0xFF);
                func_08011F18(6, 0x90, 0xD0, 0x10, 1, 1);
                func_08008B70(6, 0xFF, 0xFF);
                func_08011F18(8, 0x80, 0x90, 0x10, 1, 1);
                func_08011F18(8, 0x80, 0xD0, 0x10, 1, 1);
                func_08008B70(8, 0xFF, 0xFF);
                func_08008B58(0x16A);
            }
            else
            {
                func_08008B58(0x16B);
                func_08037424(0x11);
                func_08037424(0x12);
                func_08037424(0x13);
                func_08000F88(0x17C);
            }
        }
        break;
    case 14:
        func_08001A08(1);
        D_02000B54 = 0;
        func_080019B4(1);
        func_08008B58(0x187);
        func_08008B58(0x188);
        func_08008B58(0x189);
        func_08011F18(1, 0x80, 0xC0, 0x10, 2, 1);
        func_08008B70(1, 0xFF, 0xFF);
        D_02000000.first = func_08008024;
        func_08003DD8(3);
        D_02000000.first = func_0801B030;
        for (;;)
            func_0805EE78(1);
    default:
        func_08008B58(D_08668F08[D_030022E0]);
        break;
    }
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    if (D_030022E0 <= 4)
    {
        func_08000BD8(1, 0);
        func_08007188(0x90, 0xB, 8, 0xFFFF);
        func_080014A8(1, func_0800BEA4);
    }
    else if (D_030022E0 <= 9)
    {
        func_08000BD8(1, 0);
        func_08007188(0x93, 0xB, 8, 0xFFFF);
        func_080014A8(1, func_0800BEA4);
    }
    else
    {
        func_08000BD8(1, 3);
        func_08007188(0x96, 8, 4, 0xFFFF);
        func_080014A8(1, func_0800BEA4);
    }
}
