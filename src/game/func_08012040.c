#include "types.h"

extern u16 D_02000B54;

void func_080019B4(u16);
void func_08008E4C(u32);
void func_08001A08(u16);

void func_08012040(u8 *text, u16 sound)
{
    u16 saved = D_02000B54;

    func_080019B4(sound);
    if ((u32)text > 0x02FFFFFF)
    {
        while (*text != 0xFF)
        {
            func_08008E4C(*text);
            text++;
        }
    }
    else
    {
        func_08008E4C((u32)text);
    }
    func_08001A08(sound);
    func_080019B4(saved);
}
