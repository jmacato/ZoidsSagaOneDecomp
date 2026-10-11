#include "types.h"

extern u16 D_02000B54;
extern struct
{
    u8 pad_0[0x238];
    u32 state;
} D_02000034;
extern struct
{
    u8 pad_0[0x21E8];
    u8 result;
} D_0200EB84;

void func_08003DF8(s32, void *);
void func_0802AC0C(void);
void func_0805EE78(s32);
void func_08003E3C(s32);

s32 func_0800C3AC(void)
{
    u16 saved = D_02000B54;
    u8 result;

    func_08003DF8(4, func_0802AC0C);
    while (D_02000034.state != 1)
        func_0805EE78(1);
    func_08003E3C(4);
    D_02000B54 = saved;
    result = D_0200EB84.result;
    if (result <= 2)
        return 0;
    if (result == 3)
        return 1;
    return 2;
}
