#include "types.h"

struct Entry
{
    u8 pad_0[0x2C];
};

struct TaskState
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u8 pad_14[4];
    u32 field_18;
    u8 pad_1C[0xC];
    s16 field_28;
    u8 pad_2A[0x5E];
};

extern u8 D_02000030;
extern struct TaskState D_02000034[];
extern struct Entry D_08663F98[][4];

void func_08003DF8(s32, void *);
void func_0803DBC0(void);
void func_08003E3C(s32);
void func_0805EE78(s32);

void func_080034AC(void)
{
    struct TaskState *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            task->field_28 = 0;
        case 100:
            func_08003DF8(4, func_0803DBC0);
            D_02000034[4].field_8 = (u32)&D_08663F98[task->field_8][task->field_28];
            D_02000034[4].field_C = 1;
            D_02000034[4].field_10 = 1;
            task->state = 1000;
        case 1000:
            if (D_02000034[4].field_18 == 1)
            {
                func_08003E3C(4);
                if (++task->field_28 > 3)
                {
                    task->field_28 = 0;
                    task->state = 9000;
                }
                else
                {
                    task->state = 100;
                }
            }
            else if (D_02000034[4].field_18 == 2)
            {
                func_08003E3C(4);
                task->state = 9000;
            }
            break;
        case 9000:
            task->field_18 = 1;
            break;
        }
        func_0805EE78(1);
    }
}
