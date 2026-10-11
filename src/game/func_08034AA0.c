#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 data;
    u32 size;
    u8 pad_14[4];
    u32 busy;
    u8 pad_1C[4];
    u32 mode;
    u8 pad_24[0x64];
};

extern u8 D_02000030;
extern struct Task D_02000034[];

void func_0805EE78(s32);

void func_08034AA0(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            D_02000034[3].message = 5;
            D_02000034[3].size = task->message;
            D_02000034[3].mode = 0xC003;
            task->state = 300;
            break;
        case 300:
            switch (D_02000034[3].busy)
            {
            case 5:
            case 0xFC:
            case 0xFE:
            case 0xFF:
                task->state = 9500;
                break;
            case 3:
                task->busy = 1;
                task->state = 9000;
                break;
            }
            break;
        case 9000:
            break;
        case 9500:
            task->busy = D_02000034[3].busy;
            task->state = 9510;
            break;
        case 9510:
            break;
        }
        func_0805EE78(1);
    }
}
