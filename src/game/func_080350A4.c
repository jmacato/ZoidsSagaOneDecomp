#include "types.h"

struct BattleState
{
    u16 flags;
    u8 pad_2[0x21EA];
    u8 mode;
};

struct TaskState
{
    u8 pad_0[8];
    u32 message;
    u32 data;
    u8 pad_10[8];
    u32 busy;
    u8 pad_1C[0x6C];
};

extern struct BattleState D_0200EB84;
extern struct TaskState D_02000034[];

void func_08034AA0(void);
void func_0803520C(void);
void func_0803519C(void);
void func_08003DF8(u8, void (*)(void));
void func_08003E3C(u8);
void func_0805EE78(u32);

void func_080350A4(void)
{
    register u8 *base asm("r4");
    register u8 *saved_base asm("r5");
    register u32 *busy asm("r6");
    u32 *data;
    register u32 status asm("r4");

    if (D_0200EB84.flags & 0x20)
    {
        if (D_0200EB84.mode == 0)
        {
            register u32 offset asm("r0");
            register u32 second_offset asm("r1");
            register u32 *message asm("r1");
            register u32 *second_message asm("r0");

            func_08003DF8(7, func_08034AA0);
            base = (u8 *)D_02000034;
            offset = 0x3C0;
            asm("" : "+r"(base), "+r"(offset));
            message = (u32 *)(base + offset);
            *message = 0xFD07;
            func_0805EE78(1);
            saved_base = base;
            second_offset = 0x3C4;
            data = (u32 *)(saved_base + second_offset);
            asm("" : : "r"(saved_base), "r"(second_offset), "r"(data));
            while (1)
            {
                offset = 0x3D0;
                asm("" : "+r"(offset));
                busy = (u32 *)(saved_base + offset);
                status = *busy;
                if (status == 1)
                    break;
                func_0805EE78(1);
            }
            asm("" : "+r"(status));
            func_08003E3C(7);
            {
                register u32 slot asm("r0") = 7;

                asm("" : : "r"(slot));
                func_08003DF8(slot, func_0803520C);
            }
            second_offset = 0x3C0;
            asm("" : "+r"(second_offset));
            second_message = (u32 *)(saved_base + second_offset);
            *second_message = status;
            *data = 0;
            func_0805EE78(1);
            base = (u8 *)busy;
            asm("" : : "r"(base));
            while (*(u32 *)base != 1)
                func_0805EE78(1);
            func_08003E3C(7);
            func_0805EE78(1);
            func_08003DF8(7, func_08034AA0);
            base = (u8 *)D_02000034;
            offset = 0x3C0;
            asm("" : "+r"(base), "+r"(offset));
            message = (u32 *)(base + offset);
            *message = 0xFD0C;
            func_0805EE78(1);
            second_offset = 0x3D0;
            asm("" : "+r"(second_offset));
            base += second_offset;
            while (*(u32 *)base != 1)
                func_0805EE78(1);
            func_08003E3C(7);
            func_0805EE78(1);
        }
        else
            func_0803519C();
    }
}
