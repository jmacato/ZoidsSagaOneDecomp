#include "types.h"

struct Entry
{
    u8 kind;
    u8 a;
    u8 b;
    u8 pad_3;
    u16 c;
    u8 pad_6[2];
};

extern struct Entry D_0866B868[];

void func_0803225C(u8, u8, u16, u8, s32, s32);
void func_080322F0(u8, u8, u16, u8, s32, s32);

void func_08032164(u8 index, u8 value, s32 arg2, s32 arg3)
{
    if (D_0866B868[index].kind == 0)
        func_0803225C(D_0866B868[index].a, value, D_0866B868[index].c, D_0866B868[index].b, arg2, arg3);
    else
        func_080322F0(D_0866B868[index].a, value, D_0866B868[index].c, D_0866B868[index].b, arg2, arg3);
}
