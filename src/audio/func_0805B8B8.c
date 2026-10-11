#include "types.h"

register u8 *note_channel asm("r4");
register u8 *note_track asm("r5");

void func_0805B8B8(void)
{
    register s32 volume asm("r1") = note_channel[0x12];
    register s32 note_pan asm("r2");
    register u32 pan_offset asm("r0");
    register s32 factor asm("r3");
    register u32 output asm("r0");

    asm("" : : "r"(volume));
    pan_offset = 0x14;
    asm("" : "+r"(pan_offset));
    note_pan = *(s8 *)(note_channel + pan_offset);
    asm("" : : "r"(volume), "r"(note_pan));
    factor = 128;
    asm("" : "+r"(factor));
    factor += note_pan;
    factor *= volume;
    output = note_track[0x10];
    asm("" : : "r"(output));
    output *= factor;
    output = (s32)output >> 14;
    if (output > 255)
        output = 255;
    asm("" : "+r"(output));
    note_channel[2] = output;
    factor = 127;
    asm("" : "+r"(factor));
    factor -= note_pan;
    factor *= volume;
    output = note_track[0x11];
    asm("" : : "r"(output));
    output *= factor;
    output = (s32)output >> 14;
    if (output > 255)
        output = 255;
    asm("" : "+r"(output));
    note_channel[3] = output;
}
