#include "types.h"

struct TaskState
{
    u8 pad_0[8];
    u32 field_8;
    u32 field_C;
    u8 pad_10[8];
    u32 field_18;
    u8 pad_1C[0x6C];
};

extern struct TaskState D_02000034[];

void func_08003DF8(s32, void *);
void func_08004034(void);
void func_0805EE78(s32);
void func_08003E3C(s32);

s32 func_08043874(u16 command, u32 count)
{
    u16 i;

    switch (command)
    {
    case 0x1000:
        func_08003DF8(10, func_08004034);
        D_02000034[10].field_8 = 0;
        D_02000034[10].field_C = 0;
        break;
    case 0x1100:
        func_08003DF8(10, func_08004034);
        D_02000034[10].field_8 = 1;
        D_02000034[10].field_C = 0;
        break;
    case 0x1600:
        while (D_02000034[10].field_18 != 1)
            func_0805EE78(1);
        *(vu16 *)0x05000000 = 0;
        func_08003E3C(10);
        break;
    case 0x2000:
        for (i = 0; i < count; i++)
            func_0805EE78(0x3C);
        break;
    }
    return 1;
}
