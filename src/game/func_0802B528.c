#include "types.h"

struct Side
{
    u8 pad_0[0x10CC];
    u32 field_10CC;
    u8 pad_10D0[8];
};

extern struct Side D_0200EB88[];
extern u32 D_02005C74[];
extern u16 D_02005C70;

void func_0802B5A0(struct Side *);
void func_0802BC6C(struct Side *);
void func_0802B728(struct Side *);
void func_0802F480(struct Side *);
void func_080338A8(s32);

void func_0802B528(void)
{
    u8 i;

    for (i = 0; i <= 1; i++)
        D_0200EB88[i].field_10CC = D_02005C74[i];
    func_0802B5A0(D_0200EB88);
    func_0802BC6C(D_0200EB88);
    if (!(D_02005C70 & 0x8000))
        func_0802B728(&D_0200EB88[1]);
    else
        func_0802F480(&D_0200EB88[1]);
    func_080338A8(1);
}
