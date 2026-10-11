#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    const void *data;
    u32 size;
    u8 pad_14[4];
    u32 busy;
    u32 field_1C;
    u32 mode;
    u8 pad_24[0x64];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u8 D_020143BC[];
extern u8 D_020128AC[];

u32 func_08034A78(s32);
void func_0805D270(const void *, void *, u32);
void func_0805EE78(s32);

void func_08034F24(void)
{
    struct Task *task = &D_02000034[D_02000030];
    u32 size;
    u32 len;

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
            len = 0x20;
            size = func_08034A78(len);
            if (D_02000034[3].field_1C == 0)
            {
                D_02000034[3].message = 2;
                D_02000034[3].data = D_020143BC;
                D_02000034[3].size = size;
                D_02000034[3].mode = 0xC003;
                task->state = 2000;
            }
            else
            {
                D_02000034[3].message = 3;
                D_02000034[3].data = D_020128AC;
                D_02000034[3].mode = 0xC003;
                task->state = 4000;
            }
            break;
        case 2000:
            if (D_02000034[3].busy == 3)
                task->state = 9000;
            break;
        case 4000:
            if (D_02000034[3].busy == 3)
            {
                func_0805D270(D_020128AC, D_020143BC, len / 2);
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
