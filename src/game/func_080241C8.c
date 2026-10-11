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

extern const u8 D_0866B060[];

s32 func_08001040(s32);
void func_08037450(s32);
void func_0802436C(void);

void func_080241C8(void)
{
    u32 i;

    func_08008B70(0, 0xC, 0x10);
    func_08011E24();
    func_08008B58(0x25B);
    func_08011E08();
    func_080076C0(0xEC, 4, 0xE, 4, D_0866B060);
    func_08008B70(0, 9, 0xE);
    func_08011E24();
    func_08011F18(0, 0xA0, 0x1C0, 0x20, 1, 0);
    func_08008B58(0x25C);
    func_080019EC(0x66);
    do
        func_0805EE78(1);
    while (!func_08001A28(0x66));
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08008B58(0x25D);
    i = 0;
    for (;;)
    {
        func_08008B70(1, 0xFF, 0xFF);
        func_0805EE78(3);
        if (i > 3)
            break;
        func_08008B70(1, 4, 0xE);
        func_0805EE78(3);
        i++;
    }
    func_08008B70(2, 0, 0xE);
    func_08011F18(2, 0x60, 0x1C0, 0x20, 1, 1);
    func_08008B58(0x25E);
    func_08011F18(2, 0, 0x1C0, 0x20, 1, 1);
    func_08008B70(2, 0xFF, 0xFF);
    func_08008B58(0x25F);
    if (func_08001040(0x1BB))
    {
        func_08008B58(0x260);
        func_08008B70(3, 5, 0xE);
        func_08011F18(3, 0xA0, 0x1A0, 0x20, 1, 1);
        func_08011F18(3, 0x80, 0x1A0, 0x20, 1, 1);
        func_0805EE78(1);
        func_08011F18(3, 0, 0x1A0, 0x20, 2, 1);
        func_08008B70(3, 0xFF, 0xFF);
        func_08037450(0x1F);
        func_08037450(0x20);
    }
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0802436C;
    for (;;)
        func_0805EE78(1);
}
