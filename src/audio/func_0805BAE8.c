#include "types.h"

register u8 *release_track asm("r1");
register u32 active_mask asm("r4");
register u32 release_mask asm("r5");

__attribute__((optimize("no-reorder-blocks"))) void func_0805BAE8(void)
{
    /* Save the two scratch registers without adding an LR stack slot. */
    asm volatile("push {r4, r5}" : : : "memory");
    register u8 *cursor asm("r2") = *(u8 **)(release_track + 0x40);
    register u32 note asm("r3") = *cursor;
    register u8 *channel asm("r1");

    asm("" : "+r"(cursor), "+r"(note));
    asm goto("cmp %0, #0x80\n\tbcs %l[remembered_note]" : : "r"(note) : "cc" : remembered_note);
    release_track[5] = note;
    asm("" : "+r"(cursor) : : "memory");
    cursor++;
    asm("" : "+r"(cursor));
    *(u8 **)(release_track + 0x40) = cursor;
    goto channels;

remembered_note:
    note = release_track[5];

channels:
    channel = *(u8 **)(release_track + 0x20);
    asm("" : "+r"(channel));
    if (channel == 0)
        goto done;
    active_mask = 0x83;
    release_mask = 0x40;
    asm("" : "+r"(active_mask), "+r"(release_mask));

next_channel:
{
    asm("" : "+r"(channel));
    register u32 flags asm("r2") = channel[0];
    register u32 value asm("r0");

    asm("" : : "r"(flags));
    asm goto("tst %0, %1\n\tbeq %l[advance]" : : "r"(flags), "r"(active_mask) : "cc" : advance);
    asm goto("tst %0, %1\n\tbne %l[advance]" : : "r"(flags), "r"(release_mask) : "cc" : advance);
    value = channel[0x11];
    asm("" : : "r"(value));
    if (value != note)
        goto advance;
    value = 0x40;
    asm("" : "+r"(value));
    flags |= value;
    channel[0] = flags;
    goto done;
}

advance:
    channel = *(u8 **)(channel + 0x34);
    asm("" : "+r"(channel));
    if (channel != 0)
        goto next_channel;
done:
    asm volatile("pop {r4, r5}" : : : "memory");
}
