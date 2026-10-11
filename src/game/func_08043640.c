#include "types.h"

#define REG_DISPCNT (*(vu16 *)0x04000000)
#define REG_BG0CNT (*(vu16 *)0x04000008)
#define REG_BG1CNT (*(vu16 *)0x0400000A)
#define REG_BG2CNT (*(vu16 *)0x0400000C)
#define REG_BG3CNT (*(vu16 *)0x0400000E)

extern struct
{
    u8 pad_0[0x14];
    u32 scroll;
} D_03004B9C;

extern u16 D_0200DA74;
extern u32 D_0200E284;
extern u32 D_0200E288;
extern u8 D_0200DA71;
extern u16 D_03002350;
extern u16 D_0300234A;

void func_08000DB8(void);
void func_08000D1C(s32);
void func_0805EE78(s32);
void func_080019B4(s32);
void func_08041F8C(s32, s32, s32, s32, s32);
void func_08003DF8(s32, void *);
void func_08043F64(void);

void func_08043640(void)
{
    u16 i;

    func_08000DB8();
    REG_DISPCNT = 0x1440;
    REG_BG0CNT = 1;
    REG_BG1CNT = 0x4082;
    REG_BG2CNT = 0x83;
    REG_BG3CNT = 0x81;
    REG_BG2CNT = (REG_BG2CNT & 0xFFF3) | 8;
    REG_BG1CNT = (REG_BG1CNT & 0xFFF3) | 4;
    REG_BG3CNT = (REG_BG3CNT & 0xFFF3) | 8;
    REG_BG2CNT = (REG_BG2CNT & 0xE0FF) | 0x300;
    REG_BG1CNT = (REG_BG1CNT & 0xE0FF) | 0x100;
    REG_BG3CNT = (REG_BG3CNT & 0xE0FF) | 0x300;
    D_03004B9C.scroll = 0xFFF00000;
    func_08000D1C(0);
    D_0200DA74 = 0;
    for (i = 0; i < 16; i++)
        ((u16 *)0x050003E0)[i] = 0;
    func_0805EE78(1);
    D_0200E284 = 0;
    D_0200E288 = 0;
    D_0200DA71 = 0;
    func_080019B4(2);
    func_08041F8C(0, 0, 0x10, 0xF0, 0x90);
    REG_DISPCNT = (REG_DISPCNT & 0xDFFF) | 0x2000;
    D_03002350 = 0;
    D_0300234A = 0x3E;
    func_0805EE78(1);
    func_08003DF8(6, func_08043F64);
}
