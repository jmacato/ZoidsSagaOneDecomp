#include "types.h"

struct SioHi
{
    u8 low;
    u8 pad:6;
    u8 irq:1;
    u8 top:1;
};

struct Link
{
    u8 type;
    u8 state;
    u8 connected;
    u8 received;
    u8 pad_4[3];
    u8 error;
    u8 pad_8[3];
    u8 frames;
    u8 pad_C[8];
    u32 field_14;
};

extern struct Link D_030021A8;

u32 func_0800641C(u8 *dest);

u32 func_080062E8(u8 *dest)
{
    vu32 *sio = (vu32 *)0x04000128;
    u32 control = *sio;
    u32 result;
    u32 received;
    u32 connected;

    switch (D_030021A8.state)
    {
    case 0:
        if (!((u16)control & 0x30))
        {
            u32 mode = (u16)control & 0x88;

            if (mode != 8)
                break;
            if (!(u8)(control & 4) && D_030021A8.field_14 == 16)
            {
                *(vu16 *)0x04000208 = 0;
                *(vu16 *)0x04000200 &= 0xFF7F;
                *(vu16 *)0x04000200 |= 0x40;
                *(vu16 *)0x04000208 = 1;
                ((volatile struct SioHi *)sio)->irq = 0;
                *(vu32 *)0x0400010C = 0xBFC0;
                *(vu16 *)0x04000202 = 0xC0;
                D_030021A8.type = mode;
            }
        }
        D_030021A8.state = 1;
    case 1:
        func_0800641C(dest);
        break;
    }
    D_030021A8.frames++;
    return (D_030021A8.type == 8 ? 0x80 : 0) | D_030021A8.received | (D_030021A8.connected << 8) | (D_030021A8.error ? 0x1000 : 0) | (((control << 26) >> 30) > 1 ? 0x2000 : 0);
}
