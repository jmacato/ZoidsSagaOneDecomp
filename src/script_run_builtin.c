#include "text.h"

int script_run_builtin(u16 index)
{
    *(u16 *)0x04000008 = *(u16 *)0x0200D91C;
    *(const u8 ***)0x02007584 = (const u8 **)0x086D06DC;
    script_interpret(script_get_entry(index));
    return 0;
}
