#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern u16 D_02000B54;
extern u8 D_0866711C[];

void func_08011E08(void);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08008B70(s32, s32, s32);
void func_08011E24(void);
void func_08008B58(s32);
void func_08011F18(s32, s32, s32, s32, s32, s32);
void func_08008024(void);
void func_0801328C(void);
void func_08003DD8(s32);

void func_080131EC(void)
{
    func_08011E08();
    func_080076C0(0x1E, 0x1A, 4, 4, D_0866711C);
    func_08001A08(5);
    D_02000B54 = 0;
    func_080019B4(5);
    func_08008B70(0, 0x1D, 4);
    func_08011E24();
    func_08008B58(0x7C);
    func_08011F18(1, 0x2A0, 0xA0, 0x20, 2, 1);
    func_08008B70(1, 0xFFFF, 0xFFFF);
    func_08008B58(0x7D);
    D_02000000.counter &= 0xFFFD;
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0801328C;
}
