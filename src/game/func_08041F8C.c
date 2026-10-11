#include "types.h"

extern u16 D_03002342;
extern u16 D_03002344;
extern u16 D_03002346;
extern u16 D_03002348;

void func_08041F8C(u8 which, u8 left, u8 top, u8 right, u8 bottom)
{
    switch (which)
    {
    case 0:
        D_03002342 = (left << 8) | right;
        D_03002346 = (top << 8) | bottom;
        break;
    case 1:
        D_03002344 = (left << 8) | right;
        D_03002348 = (top << 8) | bottom;
        break;
    }
}
