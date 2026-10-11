#include "types.h"

u8 func_080470F0(u8);

#define TRY_SLOT(slot) if (func_080470F0(slot)) return slot

#define HORIZONTAL(first, second) \
    if (buttons & 0x40) \
    { \
        TRY_SLOT(first); \
        TRY_SLOT(second); \
    } \
    if (buttons & 0x80) \
    { \
        TRY_SLOT(second); \
        TRY_SLOT(first); \
    }

#define CROSS_ROW(first, second, third) \
    if (buttons & 0x30) \
    { \
        TRY_SLOT(first); \
        TRY_SLOT(second); \
        TRY_SLOT(third); \
    }

u8 func_080476C0(u32 incoming_mode, u32 incoming_cursor, u32 incoming_buttons)
{
    u8 mode = (u8)incoming_mode;
    u8 cursor = (u8)incoming_cursor;
    u16 buttons = (u16)incoming_buttons;
    switch (mode)
    {
    case 0:
        switch (cursor)
        {
        case 0:
            HORIZONTAL(1, 2);
            CROSS_ROW(3, 5, 4);
            return 0;
        case 1:
            HORIZONTAL(2, 0);
            CROSS_ROW(4, 5, 3);
            return 1;
        case 2:
            HORIZONTAL(0, 1);
            CROSS_ROW(5, 4, 3);
            return 2;
        case 3:
            HORIZONTAL(4, 5);
            CROSS_ROW(0, 2, 1);
            return 3;
        case 4:
            HORIZONTAL(5, 3);
            CROSS_ROW(1, 2, 0);
            return 4;
        case 5:
            HORIZONTAL(3, 4);
            CROSS_ROW(2, 1, 0);
            return 5;
        }
        break;
    case 5:
        switch (cursor)
        {
        case 0:
            HORIZONTAL(1, 2);
            return 0;
        case 1:
            HORIZONTAL(2, 0);
            return 1;
        case 2:
            HORIZONTAL(0, 1);
            return 2;
        }
        break;
    case 7:
        switch (cursor)
        {
        case 3:
            HORIZONTAL(4, 5);
            return 3;
        case 4:
            HORIZONTAL(5, 3);
            return 4;
        case 5:
            HORIZONTAL(3, 4);
            return 5;
        }
        break;
    case 4:
        return 13;
    case 3:
        if (buttons & 0xC0)
        {
            if (cursor == 11)
                return 12;
            if (cursor == 12)
                return 11;
        }
        break;
    case 2:
        if (buttons & 0x30)
        {
            if (cursor == 9)
                return 10;
            if (cursor == 10)
                return 9;
        }
        break;
    case 12:
        return 10;
    case 10:
        return 9;
    case 1:
        switch (cursor)
        {
        case 6:
            HORIZONTAL(7, 8);
            break;
        case 7:
            HORIZONTAL(8, 6);
            break;
        case 8:
            HORIZONTAL(6, 7);
            break;
        }
        break;
    }
    return cursor;
}
