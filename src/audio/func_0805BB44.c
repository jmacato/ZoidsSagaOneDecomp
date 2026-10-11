#include "types.h"

struct InputReader
{
    u8 unknown00[0x40];
    const u8 *cursor;
};

void func_0805BB44(void *unused, struct InputReader *reader)
{
    register const u8 *cursor asm("r2") = reader->cursor;
    register u32 value asm("r3");

    value = (u32)(cursor + 1);
    asm("" : : "r"(value));
    reader->cursor = (const u8 *)value;
    value = *cursor;
    /* The callers consume this helper's byte through r3. */
    asm volatile("" : : "r"(value));
}
