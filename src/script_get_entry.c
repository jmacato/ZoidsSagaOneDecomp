#include "text.h"

const u8 *script_get_entry(u16 index)
{
    return (*(const u8 ***)0x02007584)[index];
}
