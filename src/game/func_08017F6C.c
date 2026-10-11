#include "types.h"

void func_08011F18(s32, s32, s32, s32, s32, s32);
void func_08000BD8(s32, s32);
void func_0805EE78(s32);

void func_08017F6C(void)
{
    for (;;)
    {
        func_08011F18(2, 0x180, 0x160, 0x20, 4, 1);
        func_08011F18(2, 0x160, 0x160, 0x20, 4, 1);
        func_08000BD8(3, 1);
        func_0805EE78(10);
        func_08011F18(2, 0x140, 0x160, 0x20, 4, 1);
        func_08011F18(2, 0x140, 0x180, 0x20, 4, 1);
        func_08000BD8(3, 3);
        func_0805EE78(10);
        func_08011F18(2, 0x140, 0x1A0, 0x20, 4, 1);
        func_08011F18(2, 0x160, 0x1A0, 0x20, 4, 1);
        func_08000BD8(3, 0);
        func_0805EE78(10);
        func_08011F18(2, 0x180, 0x1A0, 0x20, 4, 1);
        func_08011F18(2, 0x180, 0x180, 0x20, 4, 1);
        func_08000BD8(3, 2);
        func_0805EE78(10);
    }
}
