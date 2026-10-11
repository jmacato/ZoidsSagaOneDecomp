#include "types.h"

extern u8 D_03004BBC[];
extern u16 D_02000000[];
extern u16 D_0200000C[];
u32 func_08001040(u16);
void func_08000F88(u16);
void func_0805EE78(u32);
void func_08008B58(u32);
void func_08003DD8(u32);
void func_08008024(void);

void func_0801114C(void)
{
    {
        register u32 event asm("r4") = 300;
        asm("" : : "r"(event));
        if (!func_08001040(event))
        {
            register u32 ready asm("r4");
            func_08000F88(event);
            {
                register u8 *actor asm("r12") = D_03004BBC;
                register u16 *state asm("r3");
                u16 *waiting;
                asm("" : : "r"(actor));
                state = (u16 *)(actor + 0xE8);
                ready = 1;
                asm("" : : "r"(state), "r"(ready));
                {
                    register u16 *flags asm("r2") = D_02000000;
                    register u32 value asm("r1") = flags[4];
                    register u32 mask asm("r0") = 2;
                    mask |= value;
                    asm("" : : "r"(flags), "r"(value), "r"(mask));
                    flags[4] = mask;
                }
                *state = 10;
                {
                    register u16 *address asm("r1") = (u16 *)(actor + 0xF2);
                    *address = 4;
                    address++;
                    asm("" : : "r"(address));
                    *address = 2;
                }
                *(u32 *)(actor + 0x104) = 0x10000;
                {
                    register u32 value asm("r0") = D_0200000C[12] * 8;
                    register u16 *address asm("r1");
                    asm("" : : "r"(value));
                    address = (u16 *)(actor + 0xF6);
                    *address = value;
                }
                *(u16 *)(actor + 0xC0) = ready;
                asm("" : : "r"(state));
                waiting = state;
                asm("" : "+l"(waiting));
                do
                {
                    func_0805EE78(1);
                    ready = *waiting;
                    asm("" : : "r"(ready));
                } while (ready != 1);
            }
            {
                register u8 *actor asm("r3") = D_03004BBC;
                register u16 *state asm("r2");
                u16 *waiting;
                asm("" : : "r"(actor));
                state = (u16 *)(actor + 0xE8);
                *state = 10;
                {
                    register u16 *address asm("r1") = (u16 *)(actor + 0xF2);
                    *address = 14;
                    address++;
                    asm("" : : "r"(address));
                    *address = 2;
                }
                *(u32 *)(actor + 0x104) = 0x10000;
                {
                    register u32 value asm("r0") = D_0200000C[12] * 8;
                    register u16 *address asm("r1");
                    asm("" : : "r"(value));
                    address = (u16 *)(actor + 0xF6);
                    *address = value;
                }
                {
                    register u16 *address asm("r0") = (u16 *)(actor + 0xC0);
                    asm("" : : "r"(address));
                    *address = ready;
                }
                asm("" : : "r"(state));
                waiting = state;
                asm("" : "+l"(waiting));
                do
                    func_0805EE78(1);
                while (*waiting != 1);
            }
            func_0805EE78(60);
            func_08008B58(0x57);
            func_0805EE78(60);
        }
    }
    {
    u8 *initial_actor = D_03004BBC;
    asm("" : "+l"(initial_actor));
    {
        register u16 *state asm("r1") = (u16 *)(initial_actor + 0xE8);
        *state = 0;
    }
    {
        register u16 *flags asm("r2") = D_02000000;
        register u32 value asm("r1") = flags[4];
        register u32 mask asm("r0") = 0xFFFD;
        mask &= value;
        asm("" : : "r"(flags), "r"(value), "r"(mask));
        flags[4] = mask;
    }
    if (!func_08001040(301))
    {
        register u8 *check asm("r0");
        {
            register u32 x asm("r0") = *(u16 *)(initial_actor + 0xD6);
            asm("" : : "r"(x));
            if (x != 37)
                goto wait_for_position;
        }
        check = initial_actor;
        asm("" : : "r"(check));
        goto check_y;
wait_for_position:
        func_0805EE78(1);
        {
            register u8 *base asm("r1") = D_03004BBC;
            register u32 x asm("r0") = *(u16 *)(base + 0xD6);
            asm("" : : "r"(base), "r"(x));
            if (x != 37)
                goto wait_for_position;
            check = base;
        }
check_y:
        check += 0xD8;
        asm("" : : "r"(check));
        {
            register u32 y asm("r0") = *(u16 *)check;
            asm("" : : "r"(y));
            if (y != 1)
                goto wait_for_position;
        }
        {
            register u8 *actor asm("r3") = D_03004BBC;
            register u16 *state asm("r1");
            asm("" : "+r"(actor) : : "r0");
            state = (u16 *)(actor + 0xE8);
            *state = 1;
            {
                register u16 *flags asm("r2") = D_02000000;
                register u32 value asm("r1") = flags[4];
                register u32 mask asm("r0") = 2;
                mask |= value;
                asm("" : : "r"(flags), "r"(value), "r"(mask));
                flags[4] = mask;
            }
            actor += 0xD2;
            asm("" : : "r"(actor));
            if (*(u16 *)actor)
            {
                u16 *waiting = (u16 *)actor;
                asm("" : "+l"(waiting));
                do
                    func_0805EE78(1);
                while (*waiting);
            }
        }
        func_08000F88(301);
        func_08008B58(0x59);
        func_0805EE78(60);
        {
            register u16 *flags asm("r2") = D_02000000;
            register u32 value asm("r1") = flags[4];
            register u32 mask asm("r0") = 0xFFFD;
            mask &= value;
            asm("" : : "r"(flags), "r"(value), "r"(mask));
            value = 0;
            asm("" : : "r"(value));
            flags[4] = mask;
            {
                register u8 *actor asm("r0") = D_03004BBC;
                asm("" : "+r"(actor));
                actor += 0xE8;
                *(u16 *)actor = value;
            }
        }
        func_08003DD8(8);
    }
    }
    *(void **)D_02000000 = func_08008024;
    func_08003DD8(3);
}

void func_080112E4(void)
{
    if (D_0200000C[1] == 17)
    {
        register u8 *actor asm("r4") = D_03004BBC;
        register u16 *flags asm("r6") = D_02000000;
        u16 *state = (u16 *)(actor + 0xE8);
        register u16 *animation asm("r8");
        asm("" : "+l"(state) : "r"(actor), "r"(flags));
        {
            register u32 offset asm("r0") = 0xC0;
            asm("" : : "r"(offset));
            offset += (u32)actor;
            animation = (u16 *)offset;
            asm("" : : "r"(animation));
        }
        do
        {
            if (*(u16 *)(actor + 0xD6) == 13 && (*(u16 *)(actor + 0xB8) & 3) == 2)
            {
                {
                    register u32 value asm("r1") = flags[4];
                    register u32 mask asm("r0") = 2;
                    mask |= value;
                    asm("" : : "r"(value), "r"(mask));
                    flags[4] = mask;
                }
                *state = 10;
                *(u16 *)(actor + 0xF2) = 14;
                {
                    register u16 *address asm("r0") = (u16 *)(actor + 0xD8);
                    register u32 value asm("r1") = *address;
                    asm("" : : "r"(address), "r"(value));
                    address += 14;
                    asm("" : : "r"(address));
                    *address = value;
                }
                *(u32 *)(actor + 0x104) = 0x40000;
                {
                    register u32 value asm("r0") = D_0200000C[12] * 2;
                    register u16 *address asm("r1");
                    asm("" : : "r"(value));
                    address = (u16 *)(actor + 0xF6);
                    *address = value;
                }
                *animation = 3;
                {
                    register u8 *base asm("r5") = actor;
                    u16 *waiting;
                    asm("" : "+r"(base));
                    base += 0xE8;
                    waiting = (u16 *)base;
                    do
                        func_0805EE78(1);
                    while (*waiting != 1);
                }
                func_08008B58(0x58);
                {
                    register u32 value asm("r0") = flags[4] & 0xFFFD;
                    register u32 zero asm("r1") = 0;
                    asm("" : : "r"(value), "r"(zero));
                    flags[4] = value;
                    *state = zero;
                }
            }
            func_0805EE78(1);
        } while (D_0200000C[1] == 17);
    }
    func_08003DD8(8);
}
