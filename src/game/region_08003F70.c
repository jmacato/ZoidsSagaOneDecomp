#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    s32 ready;
    u8 pad_C[0xC];
    s32 done;
    u8 pad_1C[0xC];
    s16 timer;
    u8 pad_2A[0x5E];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern struct
{
    u8 pad_0[0x3618];
    u8 choice;
} D_02000B5C;
extern u16 D_086644C4[];
extern u16 D_0300235A;

void func_0805EE78(s32);

void region_08003F70(void)
{
    struct Task *task = &D_02000034[D_02000030];

    while (1)
    {
        switch (task->state)
        {
        case 0:
            if (task->ready == 1)
            {
                if (D_02000B5C.choice == 5)
                {
                    task->state = 100;
                }
                else
                {
                    task->timer = D_086644C4[D_02000B5C.choice];
                    task->state = 200;
                }
            }
            break;
        case 100:
            if (D_0300235A & 1)
            {
                task->done = 1;
                task->ready = 0;
                task->state = 0;
            }
            break;
        case 200:
            if (--task->timer == 0)
            {
                task->done = 1;
                task->ready = 0;
                task->state = 0;
            }
            break;
        }
        func_0805EE78(1);
    }
}
