#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u8 pad_C[0xC];
    s32 busy;
    u8 pad_1C[0xC];
    u16 values[5];
    s16 result;
    u16 choice;
    s16 tries;
    u8 pad_38[0x50];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern const u8 D_08675BEC[];
extern const u8 D_08675C5C[];
extern u16 D_0300235A;
extern u16 D_02001838[];

extern struct
{
    u8 pad_0[0xCDC];
    u16 field_CDC;
    u16 field_CDE;
    u16 field_CE0;
    u16 field_CE2;
    u16 field_CE4;
} D_02000B5C;

extern struct
{
    u8 pad_0[2];
    u16 cursor;
} D_02007574;

void func_0803E488(const u8 *, s32);
void func_08036270(struct Task *);
void func_0803641C(struct Task *);
s16 func_08036460(u16 *, s32);
u8 func_08036480(void);
void func_0805EE78(s32);

void func_080360A0(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            task->tries = task->message * 10;
            func_0803E488(D_08675BEC, 0x16);
            func_0803E488(D_08675BEC, 0x17);
            task->values[0] = D_02000B5C.field_CDC;
            task->values[1] = D_02000B5C.field_CE2;
            task->values[2] = D_02000B5C.field_CE0;
            task->values[3] = D_02000B5C.field_CDE;
            task->values[4] = D_02000B5C.field_CE4;
            task->state = 1000;
        case 1000:
            func_08036270(task);
            func_0803E488(D_08675BEC, 0xA);
            func_0803641C(task);
            func_0803E488(D_08675BEC, 5);
            task->state = 1100;
        case 1100:
            func_0803E488(D_08675BEC, 0xF);
            if (D_0300235A & 1)
            {
                task->choice = D_02007574.cursor;
                switch (D_02007574.cursor)
                {
                case 0:
                    task->result = func_08036460(&D_02001838[0], 1);
                    break;
                case 1:
                    task->result = func_08036460(&D_02001838[3], 1);
                    break;
                case 2:
                    task->result = func_08036460(&D_02001838[2], 1);
                    break;
                case 3:
                    task->result = func_08036460(&D_02001838[1], 1);
                    break;
                case 4:
                    task->result = func_08036460(&D_02001838[4], 1);
                    break;
                }
                if (task->result == 0)
                {
                    task->tries--;
                    task->state = 1000;
                }
            }
            if (task->tries == 0)
                task->state = 9000;
            else if (func_08036480())
                task->state = 9000;
            break;
        case 9000:
            func_08036270(task);
            func_0803E488(D_08675BEC, 0xA);
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x31);
            func_0803E488(D_08675BEC, 5);
            func_0803E488(D_08675BEC, 0x14);
            task->busy = 1;
            task->state = 0x238C;
            break;
        case 0x238C:
            break;
        }
        func_0805EE78(1);
    }
}
