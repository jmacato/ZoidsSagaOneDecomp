#include "types.h"

struct SioCnt
{
    u32 baud:2;
    u32 si:1;
    u32 sd:1;
    u32 id:2;
    u32 error:1;
    u32 pad:25;
};

struct Sio
{
    u16 cnt;
    u16 send;
};

union Multi
{
    unsigned long long raw;
    u16 data[4];
};

extern struct
{
    u8 master;
    u8 pad_1[3];
    u8 swap_send;
    u8 complete;
    u8 pad_6;
    u8 error;
    u8 pad_8[0xC];
    s32 send_count;
    s32 recv_count;
    u16 *send_next;
    u16 *send;
    u16 (*recv_next)[16];
    u16 (*recv)[16];
} D_030021A8;

extern u16 D_03007FF8;

void func_0800652C(void)
{
    struct Sio
{
    u16 cnt;
    u16 send;
};

union Multi multi;
    s32 i;
    u16 *tmp;
    u16 (*rtmp)[16];

    multi.raw = *(unsigned long long *)0x04000120;
    D_030021A8.error = ((struct SioCnt *)0x04000128)->error;
    if (multi.data[0] == 0xFEFE && D_030021A8.recv_count > 13)
    {
        D_030021A8.recv_count = -1;
        rtmp = D_030021A8.recv;
        D_030021A8.recv = D_030021A8.recv_next;
        D_030021A8.recv_next = rtmp;
        if (D_030021A8.swap_send)
        {
            tmp = D_030021A8.send;
            D_030021A8.send = D_030021A8.send_next;
            D_030021A8.send_next = tmp;
            D_030021A8.swap_send = 0;
            D_030021A8.send_count = 0;
        }
        *(vu16 *)0x04000208 = 0;
        D_03007FF8 |= 0x80;
        *(vu16 *)0x04000208 = 1;
    }
    if (D_030021A8.send_count < 14)
        ((struct Sio *)0x04000128)->send = D_030021A8.send[D_030021A8.send_count];
    if (D_030021A8.send_count < 15)
        D_030021A8.send_count++;
    if (D_030021A8.recv_count >= 0)
    {
        u16 *src;
        u16 *dst;

        dst = D_030021A8.recv_next[0];
        src = multi.data;
        dst += D_030021A8.recv_count;

        for (i = 0; i < 2; i++)
        {
            *dst = *src;
            src++;
            dst += 16;
        }
        if (D_030021A8.recv_count == 13)
            D_030021A8.complete = 1;
    }
    if (D_030021A8.recv_count < 15)
        D_030021A8.recv_count++;
    if (D_030021A8.master)
        *(vu16 *)0x0400010E = 0;
    if (D_030021A8.send_count < 15 && D_030021A8.master)
    {
        *(vu16 *)0x04000128 |= 0x80;
        *(vu16 *)0x0400010E = 0xC0;
    }
}
