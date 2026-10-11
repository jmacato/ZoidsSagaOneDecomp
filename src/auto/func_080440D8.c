#include "m2c.h"

extern u8 D_0200E22C[];
extern u8 D_0200E234[];
extern u8 D_0200E235[];

void func_080440D8(s8 arg0)
{
    *(s8 *)D_0200E235 = arg0;
    *(s8 *)D_0200E22C = 1;
    *(s8 *)D_0200E234 = 0;
}
