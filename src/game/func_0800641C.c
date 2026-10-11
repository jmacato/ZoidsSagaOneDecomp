#include "types.h"

struct Link
{
    u8 type;
    u8 state;
    u8 connected;
    u8 received;
    u8 pad_4[0x10];
    u32 field_14;
    u32 field_18;
    u8 *buffers[5];
};

extern struct Link D_030021A8;

void func_0805D270(void *, void *, u32);

u32 func_0800641C(u8 *dest)
{
    u8 (*check)(void) = (u8 (*)(void))0x03001FA8;
    vu32 unused = 0;
    u32 zero;
    u8 changed;
    s32 i;

    changed = check();
    D_030021A8.received = 0;
    if (changed)
    {
        for (i = 0; i < 2; i++)
        {
            u16 *packet = (u16 *)(D_030021A8.buffers[4] + i * 32);
            s32 sum = 0;
            u32 j;

            for (j = 0; j < 14; j++)
                sum += packet[j];
            if ((s16)sum == -1)
            {
                func_0805D270(packet + 2, dest + i * 24, 0x04000006);
                D_030021A8.received |= 1 << i;
            }
            zero = 0;
            func_0805D270(&zero, packet + 2, 0x05000006);
        }
    }
    D_030021A8.connected |= D_030021A8.received;
    return D_030021A8.received;
}
