#include "types.h"

extern u8 D_03001F55;
extern u32 D_03001F4C;
extern u8 D_03000200;
extern void (*D_03000204)(void);
extern u16 D_0300233A;
extern u16 D_03002338;
extern u8 D_02005C7C[];
extern u16 D_0300239C[];
extern u16 D_0300233E;
extern u16 D_03002340;
extern u16 D_03002342;
extern u16 D_03002344;
extern u16 D_03002346;
extern u16 D_03002348;
extern u16 D_0300234A;
extern u16 D_03002350;
extern u16 D_03002356;

extern u32 D_03004B9C[8];

void func_080064CC(void);
void func_0805B5D0(void);
void read_keys(void);
void func_0805BC94(void);

void handle_vblank(void)
{
    if (D_03001F55 == 2 && (D_03001F4C & 0x80))
        func_080064CC();
    func_0805B5D0();
    D_0300233A = 0;
    if (D_03000200)
    {
        if (D_03001F55 == 0)
        {
            vu32 *dma = (vu32 *)0x040000D4;

            dma[0] = (u32)D_02005C7C;
            dma[1] = 0x07000000;
            dma[2] = 0x84000100;
            dma[2];
            dma[0] = (u32)D_0300239C;
            dma[1] = 0x06000000;
            dma[2] = 0x84000A00;
            dma[2];
        }
        if (D_03000204)
        {
            D_03000204();
            D_03000204 = 0;
        }
        *(vu16 *)0x04000010 = D_03004B9C[0] >> 16;
        *(vu16 *)0x04000012 = D_03004B9C[1] >> 16;
        *(vu16 *)0x04000014 = D_03004B9C[2] >> 16;
        *(vu16 *)0x04000016 = D_03004B9C[3] >> 16;
        *(vu16 *)0x04000018 = D_03004B9C[4] >> 16;
        *(vu16 *)0x0400001A = D_03004B9C[5] >> 16;
        *(vu16 *)0x0400001C = D_03004B9C[6] >> 16;
        *(vu16 *)0x0400001E = D_03004B9C[7] >> 16;
        *(vu16 *)0x0400004C = D_0300233E;
        *(vu16 *)0x04000040 = D_03002340;
        *(vu16 *)0x04000040 = D_03002342;
        *(vu16 *)0x04000042 = D_03002344;
        *(vu16 *)0x04000044 = D_03002346;
        *(vu16 *)0x04000046 = D_03002348;
        *(vu16 *)0x04000048 = D_0300234A;
        *(vu16 *)0x0400004A = D_03002350;
        *(vu16 *)0x04000054 = D_03002356;
        read_keys();
    }
    D_03002338++;
    *(vu16 *)0x03007FF8 = 1;
    D_03000200 = 0;
    func_0805BC94();
}
