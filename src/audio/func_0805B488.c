#include "types.h"

register u8 *return_track asm("r1");

void func_0805B488(void)
{
    register u32 value asm("r2") = return_track[2];
    asm("" : : "r"(value));
    if (value != 0)
    {
        register u8 *record asm("r3");
        value--;
        asm("" : "+r"(value));
        return_track[2] = value;
        value <<= 2;
        asm("" : "+r"(value));
        record = return_track + value;
        asm("" : : "r"(record));
        value = *(u32 *)(record + 0x44);
        asm("" : : "r"(value));
        *(u32 *)(return_track + 0x40) = value;
    }
}
