#include "tasks.h"

#define DmaFill32(value, dest, size) \
    { \
        vu32 *dma; \
        fill = (value); \
        dma = (vu32 *)0x040000D4; \
        dma[0] = (vu32)&fill; \
        dma[1] = (vu32)(dest); \
        dma[2] = 0x85000000 | ((size) / 4); \
        dma[2]; \
    }

#define DmaCopy16(src, dest, size) \
    { \
        vu32 *dma = (vu32 *)0x040000D4; \
        dma[0] = (vu32)(src); \
        dma[1] = (vu32)(dest); \
        dma[2] = 0x80000000 | ((size) / 2); \
        dma[2]; \
    }

extern const u16 D_08663B88;
extern const u8 D_080000FC[];
extern u8 D_03000000[];
extern u16 D_03002352;
extern u16 D_03002354;
extern u16 D_03002356;
extern u32 D_03000204;
extern u8 D_03000201;
extern u8 D_03000202;
extern u8 D_03000203;
extern u8 D_03001F55;

void func_08000F44(void);
void func_0805BC1C(void);
void func_08000D1C(s32);
void func_08001524(s32, void *);
void func_08000F40(void);
void func_08003DF8(s32, void *);
void func_080035F0(void);
void func_0805BC94(void);
void wait_for_frame_updates(s32);

void run_main_loop(void)
{
    vu32 fill;

    *(vu16 *)0x04000204 = D_08663B88;
    D_03002352 = D_03002354 = D_03002356 = 0;
    DmaFill32(0, 0x02000000, 0x40000);
    DmaFill32(0, 0x03000000, 0x7D80);
    DmaFill32(0, 0x06000000, 0x18000);
    DmaFill32(0, 0x07000000, 0x400);
    DmaFill32(0, 0x05000000, 0x400);
    DmaCopy16(D_080000FC, D_03000000, 0x200);
    *(u32 *)0x03007FFC = (u32)D_03000000;
    func_08000F44();
    func_0805BC1C();
    func_08000D1C(0);
    initialize_tasks();
    D_03000204 = 0;
    func_08001524(0, func_08000F40);
    func_08003DF8(1, func_080035F0);
    D_03000202 = D_03000203 = 0;
    func_0805BC94();
    D_03000201 = 1;
    D_03001F55 = 0;
    for (;;)
    {
        run_scheduled_tasks();
        wait_for_frame_updates(1);
    }
}
