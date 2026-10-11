#include "text.h"

extern u8 D_0875AFB8[];
extern u8 D_0875B270[];
extern u8 D_08675C5C[];

void func_0803E488(u8 *, s32);
void func_08001848(s32, s32, s32);
void func_0804D604(u8 *, s32, s32);

void func_0804D8AC(u32 flags, s32 value, u32 incoming_bonus, u32 incoming_cost, u32 incoming_level, u32 incoming_compact)
{
    s16 bonus = (s16)incoming_bonus;
    s16 cost = (s16)incoming_cost;
    u8 level = (u8)incoming_level;
    u8 compact = (u8)incoming_compact;
    if (!compact)
        func_0803E488(D_0875AFB8, 0x2A);
    func_0803E488(D_0875B270, 0);
    if (flags & 0x4000)
    {
        func_0803E488(D_0875B270, 1);
        func_08001848(value, 3, 1);
        func_0803E488(D_0875AFB8, 0x27);
        if (!compact)
            func_0803E488(D_08675C5C, 0);
        if (bonus != 0)
        {
            if (!compact)
                func_0803E488(D_0875B270, 2);
            else
                func_0803E488(D_0875B270, 3);
            func_08001848(bonus, 3, 1);
            func_0803E488(D_0875AFB8, 0x27);
        }
    }
    else if (flags & 0x8000)
    {
        func_0803E488(D_0875B270, 4);
        func_08001848(value, 3, 1);
        func_0803E488(D_0875AFB8, 0x27);
        if (!compact)
            func_0803E488(D_08675C5C, 0);
        if (bonus != 0)
        {
            if (!compact)
                func_0803E488(D_0875B270, 5);
            else
                func_0803E488(D_0875B270, 6);
            func_08001848(bonus, 3, 1);
            func_0803E488(D_0875AFB8, 0x27);
        }
    }
    else if (flags & 0x10000)
    {
        func_0803E488(D_0875B270, 7);
        func_08001848(value, 4, 1);
        if (!compact)
            func_0803E488(D_08675C5C, 0);
    }
    else if (flags & 0x20000)
    {
        func_0803E488(D_0875B270, 8);
        func_08001848(value, 4, 1);
        if (!compact)
            func_0803E488(D_08675C5C, 0);
    }
    else if (flags & 0x40000)
    {
        func_0803E488(D_0875B270, 9);
        func_08001848(value, 3, 1);
        func_0803E488(D_0875AFB8, 0x27);
        if (!compact)
            func_0803E488(D_08675C5C, 0);
    }
    else if (flags & 0x80000)
    {
        func_0803E488(D_0875B270, 0xA);
        func_08001848(value, 3, 1);
        func_0803E488(D_0875B270, 0xB);
        if (!compact)
            func_0803E488(D_08675C5C, 0);
    }
    else if (flags & 0x100000)
    {
        func_0803E488(D_0875B270, 0xC);
        if (!compact)
            func_0803E488(D_08675C5C, 0);
    }
    else if (flags & 0x200000)
    {
        if (value == 4)
            func_0803E488(D_0875B270, 0xE);
        else if (value == 8)
            func_0803E488(D_0875B270, 0xF);
        func_0803E488(D_0875B270, 0xD);
        if (!compact)
            func_0803E488(D_08675C5C, 0);
    }
    else if (flags & 0x400000)
    {
        if (!compact)
            func_0803E488(D_0875B270, 0x10);
        else
            func_0803E488(D_0875B270, 0x11);
    }
    else if (flags & 0x1800000)
    {
        if (flags & 0x800000)
        {
            func_0803E488(D_0875B270, 0x12);
            func_08001848(value, 4, 1);
            if (!compact)
                func_0803E488(D_08675C5C, 0);
        }
        if (flags & 0x1000000)
        {
            if (flags & 0x800000)
            {
                if (!compact)
                {
                    func_0803E488(D_0875AFB8, 0x2A);
                    func_0803E488(D_0875AFB8, 0x2A);
                    func_0803E488(D_0875AFB8, 0x2A);
                    func_0803E488(D_0875AFB8, 0x2A);
                }
                else
                {
                    func_0803E488(D_0875AFB8, 0x2B);
                }
            }
            func_0803E488(D_0875B270, 0x13);
            func_08001848(value, 3, 1);
            if (!compact && !(flags & 0x800000))
                func_0803E488(D_08675C5C, 0);
        }
    }
    if (!compact)
    {
        func_0803E488(D_08675C5C, 0);
        func_0803E488(D_0875AFB8, 0x2A);
    }
    else
    {
        text_current_window->cursor_x = 0x16;
    }
    func_0803E488(D_0875B270, 0x14);
    func_08001848(cost, 3, 0);
    if (!compact)
    {
        func_0803E488(D_0875AFB8, 0x2A);
        func_0803E488(D_0875AFB8, 0x2A);
        func_0803E488(D_0875AFB8, 0x2A);
    }
    else
    {
        func_0803E488(D_08675C5C, 0);
    }
    func_0803E488(D_0875B270, 0x15);
    if (flags & 2)
        func_0803E488(D_0875B270, 0x16);
    else if (flags & 4)
        func_0803E488(D_0875B270, 0x17);
    if (!compact)
    {
        func_0803E488(D_08675C5C, 0);
        func_0803E488(D_0875AFB8, 0x2A);
    }
    else
    {
        func_0803E488(D_0875AFB8, 0x2A);
    }
    func_0803E488(D_0875B270, 0x18);
    if (flags & 0x80000)
    {
        func_0803E488(D_0875B270, 0x1B);
        if (compact)
            func_0804D604(D_0875B270, 0x1B, 9);
    }
    else if (!(flags & 0x20000000))
    {
        if (level == 0)
        {
            func_0803E488(D_0875B270, 0x19);
            if (compact)
                func_0804D604(D_0875B270, 0x19, 9);
        }
        else
        {
            func_08001848(level, 1, 0);
            func_0803E488(D_0875B270, 0x1A);
            if (compact)
                func_0804D604(D_0875B270, 0x1A, 8);
        }
    }
    else
    {
        func_0803E488(D_0875B270, 0x1C);
        if (compact)
            func_0804D604(D_0875B270, 0x1C, 9);
    }
    if (!compact)
    {
        func_0803E488(D_08675C5C, 0);
        func_0803E488(D_0875AFB8, 0x2A);
    }
    if (flags & 0x80000000)
        func_0803E488(D_0875B270, 0x1E);
    else
        func_0803E488(D_0875B270, 0x1D);
}
