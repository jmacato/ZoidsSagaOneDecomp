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
    u8 pad_1C[0xC];
    u16 timer;
    s16 level;
    u16 speed;
    u8 pad_2E[0x5A];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u16 D_03002356;

void func_0805EE78(s32);

void func_08004034(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            switch (task->message)
            {
            case 0:
                *(vu16 *)0x04000050 = 0x3FFF;
                task->state = 1000;
                break;
            case 1:
                *(vu16 *)0x04000050 = 0x3FFF;
                task->state = 2000;
                break;
            case 2:
                *(vu16 *)0x04000050 = 0x3FBF;
                task->state = 1000;
                break;
            case 3:
                *(vu16 *)0x04000050 = 0x3FBF;
                task->state = 2000;
                break;
            }
            break;
        case 1000:
            task->timer = 0;
            task->level = 0x1F;
            task->speed = task->done;
            task->state = 1010;
            if (task->done == 0xFFFF)
            {
                D_03002356 = 0;
                task->state = 9000;
            }
            D_03002356 = task->level;
            break;
        case 1010:
            task->timer++;
            if (!(task->timer & task->speed))
            {
                D_03002356 = task->level;
                task->level--;
                if (task->level < 0)
                    task->state = 9000;
            }
            break;
        case 2000:
            *(vu16 *)0x04000050 = 0x3FFF;
            task->timer = 0;
            task->level = 0;
            task->speed = task->done;
            task->state = 2010;
            if (task->done == 0xFFFF)
            {
                D_03002356 = 0x1F;
                task->state = 9000;
            }
            D_03002356 = task->level;
            break;
        case 2010:
            task->timer++;
            if (!(task->timer & task->speed))
            {
                D_03002356 = task->level;
                task->level++;
                if (task->level > 31)
                    task->state = 9000;
            }
            break;
        case 9000:
            task->busy = 1;
            task->state = 9010;
            break;
        }
        func_0805EE78(1);
    }
}
