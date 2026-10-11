#include "types.h"

extern u16 D_0300235A;

void func_080019EC(s32);

void func_0803832C(u8 *cursor, u8 mode)
{
    u8 old = *cursor;

    if (mode != 2)
    {
        switch (old)
        {
        case 0:
            if (D_0300235A & 0x80)
                *cursor = 1;
            else if (D_0300235A & 0x10)
                *cursor = 3;
            break;
        case 1:
            if (D_0300235A & 0x80)
                *cursor = 2;
            else if (D_0300235A & 0x40)
                *cursor = 0;
            else if (D_0300235A & 0x10)
                *cursor = 4;
            break;
        case 2:
            if (D_0300235A & 0x40)
                *cursor = 1;
            else if (D_0300235A & 0x10)
                *cursor = 5;
            break;
        case 3:
            if (D_0300235A & 0x80)
                *cursor = 4;
            else if (D_0300235A & 0x20)
                *cursor = 0;
            break;
        case 4:
            if (D_0300235A & 0x80)
                *cursor = 5;
            else if (D_0300235A & 0x40)
                *cursor = 3;
            else if (D_0300235A & 0x20)
                *cursor = 1;
            break;
        case 5:
            if (D_0300235A & 0x40)
                *cursor = 4;
            else if (D_0300235A & 0x20)
                *cursor = 2;
            break;
        }
    }
    else
    {
        switch (old)
        {
        case 1:
            if (D_0300235A & 0x10)
                *cursor = 4;
            break;
        case 4:
            if (D_0300235A & 0x20)
                *cursor = 1;
            break;
        }
    }
    if (old != *cursor)
        func_080019EC(0x40);
}
