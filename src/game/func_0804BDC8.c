#include "types.h"

#define REG_DISPCNT (*(vu16 *)0x04000000)
#define REG_BG0CNT (*(vu16 *)0x04000008)
#define REG_BG1CNT (*(vu16 *)0x0400000A)
#define REG_BG2CNT (*(vu16 *)0x0400000C)
#define REG_BG3CNT (*(vu16 *)0x0400000E)

extern u8 D_030022E4;
extern u8 D_030022E5;
extern u8 D_030022E6;
extern u8 D_030022E7;
extern u16 D_0200DA74;

void func_08000DB8(void);
void func_0803E024(s32, s32, s32);
void func_0804BCDC(void);
void func_0804BDA0(void);
void func_080019B4(s32);

void func_0804BDC8(void)
{
    u16 i;

    func_08000DB8();
    REG_DISPCNT = 0x1540;
    REG_BG0CNT = 1;
    REG_BG3CNT = 0x81;
    REG_BG1CNT = 0x4082;
    REG_BG2CNT = 0x83;
    REG_BG2CNT = (REG_BG2CNT & 0xFFF3) | 8;
    REG_BG1CNT = (REG_BG1CNT & 0xFFF3) | 4;
    REG_BG3CNT = (REG_BG3CNT & 0xFFF3) | 8;
    REG_BG2CNT = (REG_BG2CNT & 0xE0FF) | 0x300;
    REG_BG1CNT = (REG_BG1CNT & 0xE0FF) | 0x100;
    REG_BG3CNT = (REG_BG3CNT & 0xE0FF) | 0x300;
    for (i = 0; i < 16; i++)
        ((u16 *)0x050001C0)[i] = 0;
    func_0803E024(3, 0, 0x32);
    D_030022E4 = 1;
    D_030022E5 = 4;
    D_0200DA74 = 0;
    D_030022E6 = D_030022E7 = 0;
    func_0804BCDC();
    func_0804BDA0();
    func_080019B4(3);
}
