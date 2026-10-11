#include "types.h"

extern struct
{
    void *first;
} D_02000000;

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_0801BED8(void);
void func_0801BF30(void);

void func_0801BE94(void)
{
    func_0800BEE4();
    if (func_08001040(0x1A6) != 0 && func_08001040(0x1A7) == 0)
        D_02000000.first = func_0801BED8;
    else
        D_02000000.first = func_0801BF30;
}
