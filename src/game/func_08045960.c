#include "types.h"

void func_08000BD8(s32, s32);

void func_08045960(u32 incoming_group, u32 incoming_kind)
{
    u8 group = (u8)incoming_group;
    u8 kind = (u8)incoming_kind;
    switch (group)
    {
    case 0:
        switch (kind)
        {
        case 0:
            func_08000BD8(0x17, 0x1);
            break;
        case 1:
            func_08000BD8(0x17, 0x2);
            break;
        case 2:
            func_08000BD8(0x17, 0x3);
            break;
        case 3:
            func_08000BD8(0x17, 0x4);
            break;
        case 4:
            func_08000BD8(0x17, 0x5);
            break;
        case 5:
            func_08000BD8(0x17, 0x6);
            break;
        }
        break;
    case 5:
        switch (kind)
        {
        case 0:
            func_08000BD8(0x17, 0x7);
            break;
        case 1:
            func_08000BD8(0x17, 0x8);
            break;
        case 2:
            func_08000BD8(0x17, 0x9);
            break;
        }
        break;
    case 7:
        switch (kind)
        {
        case 3:
            func_08000BD8(0x17, 0xA);
            break;
        case 4:
            func_08000BD8(0x17, 0xB);
            break;
        case 5:
            func_08000BD8(0x17, 0xC);
            break;
        }
        break;
    case 1:
        switch (kind)
        {
        case 6:
            func_08000BD8(0x17, 0xF);
            break;
        case 7:
            func_08000BD8(0x17, 0xE);
            break;
        case 8:
            func_08000BD8(0x17, 0xD);
            break;
        }
        break;
    case 2:
        switch (kind)
        {
        case 9:
            func_08000BD8(0x17, 0x15);
            break;
        case 10:
            func_08000BD8(0x17, 0x16);
            break;
        }
        break;
    case 10:
        func_08000BD8(0x17, 0x10);
        break;
    case 12:
        func_08000BD8(0x17, 0x11);
        break;
    case 3:
        switch (kind)
        {
        case 11:
            func_08000BD8(0x17, 0x18);
            break;
        case 12:
            func_08000BD8(0x17, 0x17);
            break;
        }
        break;
    case 4:
        func_08000BD8(0x17, 0x14);
        break;
    }
}
