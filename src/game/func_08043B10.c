#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[0x12];
    u32 busy;
    u8 pad_1C[0x6C];
};

struct Window
{
    u16 id;
    u8 open;
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern struct Window D_0200D920;

void func_08043640(void);
void func_08043E18(struct Window *, s32, s32);
void func_080490C0(s32, s32, s32, s32, s32, s32, s32);
void func_08043784(void);
void func_08043874(s32, s32);
u8 func_0804394C(u8);
void func_080019B4(s32);
void func_08003E3C(s32);
void func_08041E1C(void);
void func_0805EE78(s32);

void func_08043B10(void)
{
    struct Task *task = &D_02000034[D_02000030];
    u8 frames;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            task->state = 0x10;
            *(vu16 *)0x05000000 = 0;
            break;
        case 0x10:
            func_08043640();
            D_0200D920.id = 0x8F;
            D_0200D920.open = 1;
            func_08043E18(&D_0200D920, 0x11, 0xFF);
            func_080490C0(0x1C, 0x7E, 0, 0, 0xA0, 0x90, 0x13);
            func_080490C0(0x1D, 0x7F, 1, 0, 0xA0, 0x90, 0);
            func_0805EE78(1);
            func_08043784();
            func_0805EE78(1);
            func_08043874(0x1000, 0);
            func_0805EE78(1);
            func_08043874(0x1600, 0);
            frames = 0;
            task->state = 0x30;
            break;
        case 0x30:
            if (func_0804394C(frames++))
            {
                func_08043874(0x2000, 0xA);
                task->state = 0x1900;
            }
            break;
        case 0x1900:
            func_08043874(0x1100, 0);
            func_08043874(0x1600, 0);
            func_08043874(0x2000, 3);
            task->state = 0x1400;
            break;
        case 0x1400:
            func_080019B4(0);
            func_08003E3C(8);
            func_08041E1C();
            task->state = 0x1401;
            task->busy = 1;
            func_08003E3C(6);
            task->busy = 1;
            break;
        }
        func_0805EE78(1);
    }
}
