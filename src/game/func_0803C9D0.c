#include "types.h"

extern struct
{
    u16 field_0;
    u16 flags;
    u8 pad_4[0x21EC];
    u8 result;
} D_0200EB84;
extern void *D_08683AA4[];
extern void *D_08683B28[];

u8 func_0805D29C(void *);

u8 func_0803C9D0(u8 index, u8 mode)
{
    void *script;

    if (mode == 1)
        script = D_08683B28[index];
    else
        script = D_08683AA4[index];
    func_0805D29C(script);
    return D_0200EB84.result == 0xFF ? 0 : D_0200EB84.result;
}

void func_0803CA18(void)
{
    D_0200EB84.flags |= 1;
    D_0200EB84.result = 0xFF;
}

void func_0803CA34(void)
{
    D_0200EB84.flags |= 4;
    D_0200EB84.result = 0xFF;
}

void func_0803CA50(void)
{
    D_0200EB84.flags |= 2;
    D_0200EB84.result = 0xFF;
}
