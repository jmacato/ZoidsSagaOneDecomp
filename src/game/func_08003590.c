#include "types.h"

struct Entry
{
    u8 pad_0[0x2C];
};

struct TaskState
{
    u8 pad_0[8];
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u8 pad_14[4];
    u32 field_18;
    u8 pad_1C[0x6C];
};

extern struct TaskState D_02000034[];
extern struct Entry D_086640F8[];

void func_08003DF8(s32, void *);
void func_0803DBC0(void);
void func_0805EE78(s32);
void func_08003E3C(s32);

void func_08003590(u8 index)
{
    u32 *state;

    func_08003DF8(4, func_0803DBC0);
    D_02000034[4].field_8 = (u32)&D_086640F8[index];
    D_02000034[4].field_C = 0;
    D_02000034[4].field_10 = 0;
    state = &D_02000034[4].field_18;
    while (*state != 1)
        func_0805EE78(1);
    func_08003E3C(4);
}
