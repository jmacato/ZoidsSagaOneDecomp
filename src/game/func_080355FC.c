#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 data;
    u32 size;
    u32 field_14;
    u32 busy;
    u32 field_1C;
    u32 mode;
    u32 field_24;
    u8 pad_28[0x60];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u16 D_03001F56[];

void func_0805EE78(s32);

void func_080355FC(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            D_02000034[3].message = 1;
            D_02000034[3].mode = 0xC003;
            task->state = 1000;
            break;
        case 1000:
            switch (D_02000034[3].busy)
            {
            case 5:
            case 0xFC:
            case 0xFE:
            case 0xFF:
                task->state = 9500;
                break;
            case 4:
                task->state = 1100;
                break;
            }
            break;
        case 1100:
            if (task->message == 1)
            {
                D_03001F56[0] = task->data;
                D_03001F56[1] = task->size;
                D_03001F56[2] = task->field_14;
                D_02000034[3].message = 2;
                D_02000034[3].data = (u32)D_03001F56;
                D_02000034[3].size = 0x14;
                D_02000034[3].mode = 0xC003;
                task->state = 2000;
            }
            else
            {
                D_02000034[3].message = 3;
                D_02000034[3].data = (u32)D_03001F56;
                D_02000034[3].mode = 0xC003;
                task->state = 3000;
            }
            break;
        case 2000:
            if (D_02000034[3].busy == 3)
                task->state = 9000;
            break;
        case 3000:
            if (D_02000034[3].busy == 3)
            {
                task->field_1C = D_03001F56[0];
                task->mode = D_03001F56[1];
                task->field_24 = D_03001F56[2];
                task->state = 9000;
            }
            break;
        case 9000:
            task->busy = 1;
            task->state = 9010;
            break;
        case 9010:
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
