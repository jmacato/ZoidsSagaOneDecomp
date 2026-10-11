#include "types.h"

s32 func_08004C80(u16 id, u16 *data)
{
    s32 result = 0;

    if (data[0] == id && data[11] == data[0])
        result = 1;
    return result;
}

s32 func_08004C98(u16 code, u16 *data)
{
    s32 result = 0;
    u16 expected;

    switch (code)
    {
    case 0xC001:
        expected = 0xC002;
        break;
    case 0xC002:
        expected = 0xC001;
        break;
    case 0xC003:
        expected = code;
        break;
    }
    if (data[1] == expected)
        result = 1;
    return result;
}
