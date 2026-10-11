#include "text.h"

extern struct
{
    u8 pad_0[0x3305];
    u8 names[1];
} D_02000B5C;

extern u8 D_08675DD4[];

void func_08032840(u8);
void func_0803E488(u8 *, s32);
void func_08001848(u8, s32, s32);

void func_08039484(u8 id)
{
    if (id != 0xFF)
    {
        u8 cursor;

        func_08032840(id);
        cursor = text_windows[2].cursor_x;
        if (cursor <= 9)
        {
            u8 count = 9 - cursor;
            u8 i;

            for (i = 0; i < count; i++)
                func_0803E488(D_08675DD4, 0xC);
        }
        func_08001848(D_02000B5C.names[id], 2, 0);
    }
}
