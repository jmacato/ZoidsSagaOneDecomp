#include "text.h"

void window_print_number(u8 window, u16 value, u8 width, u8 format)
{
    u8 digits[5];
    u8 i;
    u8 first;
    u8 count;

    for (i = 0; i < 5; i++)
        digits[i] = 0;
    first = 4;
    switch (format)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        while (value > 9999)
        {
            digits[0]++;
            value -= 10000;
            first = 0;
        }
        while (value > 999)
        {
            digits[1]++;
            value -= 1000;
            if (first > 0)
                first = 1;
        }
        while (value > 99)
        {
            digits[2]++;
            value -= 100;
            if (first > 1)
                first = 2;
        }
        while (value > 9)
        {
            digits[3]++;
            value -= 10;
            if (first > 2)
                first = 3;
        }
        digits[4] = value;
        break;
    }
    switch (format)
    {
    case 2:
        count = 0;
        for (i = 5 - width; i <= 4; i++)
        {
            if (format == 2 && first <= i)
            {
                window_emit_character(window, 0x824F + digits[i]);
                count++;
            }
        }
        for (i = count; i < width; i++)
            window_emit_character(window, 0x8140);
        break;
    case 0:
    case 1:
    case 3:
        for (i = 5 - width; i <= 4; i++)
        {
            switch (format)
            {
            case 0:
                if (first <= i)
                    window_emit_character(window, 0x824F + digits[i]);
                break;
            case 1:
                window_emit_character(window, 0x824F + digits[i]);
                break;
            case 3:
                if (first <= i)
                    window_emit_character(window, 0x824F + digits[i]);
                else
                    window_emit_character(window, 0x8140);
                break;
            }
        }
        break;
    }
}
