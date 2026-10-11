#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern u16 D_02000B54;
extern u8 D_0866A19C[];

void func_08001A08(s32);
void func_080019B4(s32);
void func_08008B58(s32);
void func_08011E08(void);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08003D78(s32, void *);
void func_080202D4(void);
void func_080202E0(void);
void func_080202FC(void);
void func_0802031C(void);
void func_08020208(void);
void func_08011F18(s32, s32, s32, s32, s32, s32);
void func_08008B70(s32, s32, s32);
void func_0805EE78(s32);
void func_08000BD8(s32, s32);
void func_08008024(void);
void func_08003DD8(s32);

void func_08020118(void)
{
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08008B58(0x205);
    func_08011E08();
    func_080076C0(0xE0, 8, 4, 4, D_0866A19C);
    func_08003D78(4, func_080202D4);
    D_02000000.counter &= 0xFFFD;
    func_08003D78(5, func_080202E0);
    func_08003D78(6, func_080202FC);
    func_08011F18(0, 0x140, 0x80, 0x20, 1, 1);
    func_08008B58(0x206);
    func_08008B70(3, 0xC, 3);
    func_0805EE78(0xF);
    func_08011F18(3, 0x180, 0x80, 0x20, 1, 1);
    func_0805EE78(0xF);
    func_08000BD8(4, 2);
    func_08003D78(4, func_0802031C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08003DD8(4);
    D_02000000.first = func_08020208;
    for (;;)
        func_0805EE78(1);
}
