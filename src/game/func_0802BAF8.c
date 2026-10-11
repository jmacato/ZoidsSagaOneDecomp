#include "types.h"

struct Zoid
{
    u32 flags;
    u8 pad_4[0xE];
    u8 pose;
    u8 kind;
};

u8 func_0802BAF8(struct Zoid *zoid)
{
    u8 result = zoid->kind;

    if (zoid->flags & 4)
    {
        result = 15;
    }
    else if (zoid->flags & 2)
    {
        switch (result)
        {
        case 0:
            result = 0x10;
            break;
        case 2:
            result = 0x11;
            break;
        case 4:
            result = 0x12;
            break;
        }
    }
    else
    {
        switch (result)
        {
        case 0:
            switch (zoid->pose)
            {
            case 0:
                result = 5;
                break;
            case 1:
                result = 6;
                break;
            case 2:
                result = 0;
                break;
            case 3:
                result = 7;
                break;
            case 4:
                result = 8;
                break;
            case 5:
                result = 9;
                break;
            }
            break;
        case 2:
            switch (zoid->pose)
            {
            case 0:
                result = 10;
                break;
            case 1:
                result = 11;
                break;
            case 2:
                result = 2;
                break;
            case 3:
                result = 12;
                break;
            case 4:
                result = 13;
                break;
            case 5:
                result = 14;
                break;
            }
            break;
        }
    }
    return result;
}
