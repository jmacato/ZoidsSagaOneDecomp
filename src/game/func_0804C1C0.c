#include "types.h"

extern u16 D_030022E8[];
extern u16 D_0200758A[];

u8 func_0804C054(u16, u16);
u16 func_0804C0B0(u8, u16, u16);
void func_0804C134(u8, u16);
u8 func_0804C124(u8);

u8 func_0804C1C0(u8 pos, u8 mode, u16 ch)
{
    u16 prev;

    switch (ch)
    {
    case 0xFFFE:
    case 0xFFFF:
        prev = *(D_030022E8 + pos);
        if (pos)
        {
            if (func_0804C054(ch, D_0200758A[pos]))
            {
                func_0804C134(pos, ch);
                pos = func_0804C124(pos);
            }
            else if (func_0804C054(ch, (D_0200758A + 1)[pos]) && func_0804C0B0(mode, (D_030022E8 - 1)[pos], ch) != (D_030022E8 - 1)[pos])
                func_0804C134(pos - 1, ch);
            else if (prev != 0x8140)
            {
                func_0804C134(pos, ch);
                pos = func_0804C124(pos);
            }
            else if (func_0804C0B0(mode, (D_030022E8 - 1)[pos], ch) == (D_030022E8 - 1)[pos])
            {
                func_0804C134(pos, ch);
                pos = func_0804C124(pos);
            }
            else
                func_0804C134(pos - 1, ch);
        }
        else
        {
            func_0804C134(0, ch);
            pos = func_0804C124(0);
        }
        break;
    }
    return pos;
}
