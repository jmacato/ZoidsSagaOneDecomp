#include "text.h"

extern const u8 *D_08675DD4[];
extern s32 D_08663B8C[];

void print_signed_number(s32 value, u8 width, u16 flags)
{
    u8 digits[7];
    s32 rest = value;
    u8 i;
    u8 printed;
    u8 skip;

    if (width > 7)
        width = 7;
    if (value < 0)
        rest = -value;
    for (i = 0; i < 7; i++)
    {
        digits[i] = rest / D_08663B8C[i];
        rest = rest % D_08663B8C[i];
    }
    if (digits[0] > 9)
    {
        for (i = 0; i < 7; i++)
            digits[i] = 9;
    }
    if (value < 0)
        script_run_table(D_08675DD4, 0xB);
    else if (flags & 4)
        script_run_table(D_08675DD4, 0xA);
    printed = 0;
    skip = 7 - width;
    for (i = 0; i < 7; i++)
    {
        if (i >= skip)
        {
            if (digits[i] == 0 && !printed && i != 6)
            {
                if (!(flags & 1))
                {
                    if (!(flags & 2))
                        script_run_table(D_08675DD4, 0xC);
                    else
                        script_run_table(D_08675DD4, digits[i]);
                }
            }
            else
            {
                script_run_table(D_08675DD4, digits[i]);
                printed = 1;
            }
        }
    }
}
