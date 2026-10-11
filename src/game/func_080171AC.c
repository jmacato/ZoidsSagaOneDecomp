#include "types.h"

extern struct
{
    void *first;
} D_02000000;

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08017208(void);
void func_08017264(void);

void func_080171AC(void)
{
    func_0800BEE4();
    if (func_08001040(0x175) != 0 && func_08001040(0x176) == 0)
        D_02000000.first = func_08017208;
    else if (func_08001040(0x176) != 0 && func_08001040(0x177) == 0)
        D_02000000.first = func_08017264;
}
