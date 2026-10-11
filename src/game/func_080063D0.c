#include "types.h"

struct Packet
{
    u8 frame;
    u8 errors;
    u16 checksum;
    u32 data[6];
};

struct Link
{
    u8 pad_0[2];
    u8 connected;
    u8 received;
    u8 ready;
    u8 pad_5[6];
    u8 frame;
    u8 pad_C[0x10];
    struct Packet *send;
};

extern struct Link D_030021A8;

void func_0805D270(const void *, void *, u32);

void func_080063D0(const void *data)
{
    s32 sum = 0;
    struct Link *link = &D_030021A8;
    u32 i;
    u16 *p;

    link->send->frame = link->frame;
    link->send->errors = link->connected ^ link->received;
    link->send->checksum = 0;
    func_0805D270(data, link->send->data, 0x04000006);
    for (i = 0, p = (u16 *)link->send; i <= 13; i++)
        sum += *p++;
    link->send->checksum = ~sum;
    link->ready = 1;
}
