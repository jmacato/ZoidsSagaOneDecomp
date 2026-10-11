#include "types.h"

#define DmaCopy16(src, dest, size) \
    { \
        vu32 *dma = (vu32 *)0x040000D4; \
        dma[0] = (vu32)(src); \
        dma[1] = (vu32)(dest); \
        dma[2] = 0x80000000 | ((size) / 2); \
        dma[2]; \
    }

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 done;
    u8 pad_10[8];
    u32 busy;
    u8 pad_1C[0xC];
    s16 timer;
    u8 pad_2A[0x5E];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u16 D_0300235A;
extern const u8 D_0805EEA8[];
extern const u8 D_0805EEC8[];
extern const u8 D_08061188[];
extern const void *D_08663D44;

void func_08000D1C();
void func_08001150(const void *, s32, s32, s32, s32, s32, s32);
void func_08001DE4(const void *);
void func_08003DF8(s32, void *);
void func_08004034(void);
void func_08003E3C(s32);
void func_0805EE78(s32);

void region_08001F8C(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_08000D1C();
            DmaCopy16(D_0805EEA8, 0x05000000, 0x20);
            func_08001150(D_08061188, 0x1E, 0x14, 0x20, 0, 0, 0);
            DmaCopy16(D_0805EEC8, 0x06008000, 0x22C0);
            func_08001DE4(D_08663D44);
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 0;
            D_02000034[10].done = 0;
            task->state = 100;
            break;
        case 100:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->timer = 0;
                task->busy = 0;
                task->state = 200;
            }
            break;
        case 200:
            task->timer++;
            if (task->timer > 299 || (D_0300235A & 8))
            {
                func_08003DF8(10, func_08004034);
                D_02000034[10].message = 1;
                D_02000034[10].done = 0;
                task->state = 300;
            }
            break;
        case 300:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->busy = 1;
                task->state = 310;
            }
            break;
        case 310:
            break;
        }
        func_0805EE78(1);
    }
}
