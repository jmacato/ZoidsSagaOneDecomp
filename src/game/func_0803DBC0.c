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
    s32 busy;
    u8 pad_1C[0x6C];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u16 D_0200EB84;
extern u16 D_0300235A;

void func_0803DCC0(u32);
void func_0803DE74(u32);
void func_08003DF8(s32, void *);
void func_0802BC98(void);
void func_08003E3C(s32);
void func_0803DFE8(void);
void func_0800196C(void);
void func_08041E1C(void);
void func_0805EE78(s32);

void func_0803DBC0(void)
{
    struct Task *task = &D_02000034[D_02000030];
    u32 message;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            message = task->message;
            func_0803DCC0(message);
            func_0803DE74(message);
            if (task->size == 1)
                D_0200EB84 |= 0x10;
            task->state = 1000;
            break;
        case 1000:
            func_08003DF8(5, func_0802BC98);
            task->state = 1100;
        case 1100:
            if (D_02000034[5].busy == 1)
            {
                func_08003E3C(5);
                task->state = 9000;
            }
            else if ((D_0300235A & 8) && task->data == 1)
            {
                func_0803DFE8();
                func_0800196C();
                func_08003E3C(5);
                func_08041E1C();
                task->state = 9100;
            }
            break;
        case 9000:
            task->busy = 1;
            task->state = 9900;
            break;
        case 9100:
            task->busy = 2;
            task->state = 9900;
            break;
        case 9900:
            break;
        }
        func_0805EE78(1);
    }
}
