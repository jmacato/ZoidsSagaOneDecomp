#include "types.h"

__attribute__((naked)) void func_0805D36C(void)
{
    register void *return_address asm("lr");
    asm("" : "=r"(return_address));
    goto *return_address;
}
