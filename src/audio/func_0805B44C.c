#include "types.h"

register u32 script_address asm("r0");
register u8 *goto_track asm("r1");
register u8 *goto_command asm("r2");
register u32 guarded_byte asm("r3");

void func_0805B424(void);

void func_0805B44C(void)
{
    goto_command = *(u8 **)(goto_track + 0x40);
    script_address = goto_command[3];
    script_address <<= 8;
    guarded_byte = goto_command[2];
    script_address |= guarded_byte;
    script_address <<= 8;
    guarded_byte = goto_command[1];
    script_address |= guarded_byte;
    script_address <<= 8;
    func_0805B424();
    script_address |= guarded_byte;
    *(u32 *)(goto_track + 0x40) = script_address;
}
