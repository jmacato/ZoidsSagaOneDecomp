#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 done;
    u8 pad_10[8];
    u32 busy;
    u8 pad_1C[0x6C];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u16 D_02000B5C;
extern u16 D_0300235A;

void func_08031A10(void);
void func_08031B10(void);
void func_08003E3C(u8);
void func_0805EE78(s32);

void func_0802F8F8(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        task->busy = 0;
        switch (task->state)
        {
        case 0:
            task->state = 100;
            if (D_02000B5C & 0x1000)
                task->message = 3;
        case 100:
            if (task->message == 2)
            {
                task->message = 0;
                task->state = 1000;
            }
            else if (D_0300235A & 0x200)
            {
                D_02000B5C |= 0x1000;
                func_08031A10();
                task->state = 200;
            }
            break;
        case 200:
            task->busy = 1;
            if (task->message == 4)
            {
                task->message = 0;
                D_02000B5C |= 0x1000;
                func_08031A10();
            }
            else if (task->message == 2)
            {
                task->message = 0;
                D_02000B5C &= 0xEFFF;
                func_08031B10();
                task->state = 2000;
            }
            else if (D_0300235A & 0x200)
            {
                D_02000B5C &= 0xEFFF;
                func_08031B10();
                task->state = 100;
            }
            break;
        case 1000:
            if (task->message == 1)
            {
                task->message = 0;
                task->state = 100;
            }
            break;
        case 2000:
            if (task->message == 1)
            {
                task->message = 0;
                D_02000B5C |= 0x1000;
                func_08031A10();
                task->state = 200;
            }
            break;
        }
        if (task->message == 3)
        {
            task->message = 0;
            D_02000B5C |= 0x1000;
            func_08031A10();
            task->state = 200;
        }
        if (task->done == 1)
        {
            func_08031B10();
            func_08003E3C(D_02000030);
        }
        func_0805EE78(1);
    }
}
