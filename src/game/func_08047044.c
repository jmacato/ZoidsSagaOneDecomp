#include "types.h"

extern u8 D_0200E26C;

u8 func_0804727C(u8, s32);

u8 func_08047044(u8 code)
{
    u8 result = code;

    switch (code)
    {
    case 0:
        result = func_0804727C(code, 2);
        break;
    case 5:
        result = func_0804727C(code, 2);
        break;
    case 7:
        result = func_0804727C(code, 5);
        break;
    case 1:
        result = func_0804727C(code, 8);
        break;
    case 2:
        result = func_0804727C(code, 9);
        break;
    case 10:
        result = func_0804727C(code, 9);
        break;
    case 12:
        result = func_0804727C(code, 10);
        break;
    case 3:
        result = func_0804727C(code, 11);
        break;
    case 4:
        result = func_0804727C(code, 13);
        break;
    }
    if ((u8)(result + 2) > 1)
        D_0200E26C = result | 0x10;
    return result;
}
