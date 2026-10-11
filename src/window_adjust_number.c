#include "text.h"

u16 window_adjust_number(u16 value, u16 direction, u8 digit, u8 width)
{
    register s32 sum asm("r0");
    s32 next;

    switch (direction) {
    case 0x40:
        switch (digit) {
        case 0:
            next = 10000;
add_increment:
            sum = value + next;
            break;
        case 1:
            next = 1000;
            goto add_increment;
        case 2:
            sum = value + 100;
            break;
        case 3:
            sum = value + 10;
            break;
        case 4:
            sum = value + 1;
            break;
        default:
            goto clamp;
        }
        if (sum > value)
            goto normalize_sum;
        else
            value = 0xFFFF;
        break;
    case 0x80:
        /* Some native underflow checks compare only the low byte. */
        switch (digit) {
        case 0:
            if ((u8)(value - 10000) >= value)
                goto zero;
            sum = value - 10000;
            goto normalize_sum;
        case 1:
            sum = value - 1000;
            if (sum <= 0)
                goto zero;
normalize_sum:
            /* The original branches share their result in r0. */
            asm volatile("" : "+r"(sum));
            value = sum;
            break;
        case 2:
            next = value - 100;
check_next:
            if ((u8)next < value)
                goto normalize_next;
            goto zero;
        case 3:
            next = value - 10;
            goto check_next;
        case 4:
            next = value - 1;
            if ((u8)next >= value)
                goto zero;
normalize_next:
            value = next;
            break;
        }
        break;
zero:
        value = 0;
        break;
    }
clamp:
    switch (width) {
    case 4:
        if (value > 9999)
            value = 9999;
        break;
    case 3:
        if (value > 999)
            value = 999;
        break;
    case 2:
        if (value > 99)
            value = 99;
        break;
    case 1:
        if (value > 9)
            value = 9;
        break;
    case 5:
        break;
    }
    return value;
}
