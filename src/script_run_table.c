#include "text.h"

int script_run_table(const u8 **table, u32 index_word)
{
    u16 index = index_word;
    *(u16 *)0x04000008 = *(u16 *)0x0200D91C;
    *(const u8 ***)0x02007584 = table;
    script_interpret(script_get_entry(index));
    return 0;
}
