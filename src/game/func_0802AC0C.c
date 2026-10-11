#include "types.h"

struct BattleTask {
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 flags;
    u8 pad_C[12];
    u32 busy;
    u32 result;
    u8 pad_20[0x68];
};
struct BattleUnit {
    u16 flags;
    u8 pad_2[6];
    u16 status;
    u8 pad_A[0x38];
    u8 slot;
    u8 pad_43[0xB1];
    u8 hidden;
    u8 pad_F5[0x1D7];
};
struct BattleSide { struct BattleUnit units[6]; u8 pad_10C8[16]; };
struct BattleTurn { u8 side, slot; u8 pad_2[2]; };
extern u8 D_02000030;
struct BattleFields {
    u8 pad_0[0x2C0];
    u32 child_busy;
    u32 child_result;
    u8 pad_2C8[0x290];
    u32 fade;
};
extern union { struct BattleTask tasks[16]; struct BattleFields fields; } D_02000034;
extern struct {
    u8 pad_0[0x21B4];
    u8 turn_count, turn_index;
    u8 pad_21B6[2];
    struct BattleTurn turns[12];
    u8 mode;
} D_0200EB84;
extern struct BattleSide D_0200EB8C[];
extern u16 D_02005C70[];
extern u32 D_020002E4, D_0200036C, D_02000514, D_02000590, D_0200059C;
extern u16 D_02007574[];
extern u8 D_08675BEC[], D_08675C5C[];
extern u32 D_08663D44[];
extern s32 D_03004B9C[];
void func_0805D270(const void *, void *, u32);
void func_0802B528(void);
void func_08000DB8(void);
void func_0802F07C(void);
void func_08003DF8(u32, void (*)(void));
void func_08003E3C(u32);
void func_0802E9CC(void);
void func_0802F8F8(void);
void func_08033D6C(void);
void func_080337F0(void);
void func_08033718(void);
void func_080338A8(u32);
void func_08032684(void);
void func_0802FA94(void);
void func_0802F5B8(void);
void func_0802F09C(void);
void func_0802FD4C(void);
void func_08032410(void);
void func_08033D94(u32);
void func_0802F8AC(void);
void func_0802FAA8(void);
void func_08031598(u32);
void func_0802E814(void);
void func_0802E9C0(void);
void func_0803E488(u8 *, u32);
void func_080339C4(struct BattleUnit *);
void func_08004018(void);
void func_08004034(void);
void func_0802FA3C(void);
void func_0802BBC8(void);
void func_0802BC98(void);
void func_08000D1C(u32);
void func_08001DE4(u32);
void func_08031074(void);
void func_080317D0(void);
void func_0802BCA4(void);
void func_08038F30(void);
void func_08031C64(void);
void func_08031618(struct BattleUnit *, u32);
void func_0802F8E8(void);
void func_0802F5C4(void);
s32 func_08033DC8(void);
void func_0802F04C(void);
void func_0803B73C(void);
void func_08035778(void);
void func_0805EE78(u32);
struct BattleUnit *func_0802B504(u8, u8);

#define TURN_COUNT D_0200EB84.turn_count
#define TURN_INDEX D_0200EB84.turn_index
#define TURNS D_0200EB84.turns
#define TEXT_A(index) func_0803E488(D_08675BEC, (index))
#define TEXT_B(index) func_0803E488(D_08675C5C, (index))

#define CHILD_REPLY(reg) ({ \
    register u32 *field asm(reg) = child_busy; \
    register u32 reply asm("r0") = *field; \
    reply; \
})

#define LOAD_GLOBAL(reg, symbol) ({ \
    register u32 *pointer asm(reg) = &(symbol); \
    register u32 value asm("r0") = *pointer; \
    value; \
})
#define ZERO_GLOBAL(reg, symbol) { \
    register u32 zero asm("r0") = 0; \
    register u32 *pointer asm(reg) = &(symbol); \
    *pointer = zero; \
}
#define STATUS_MASK(reg, number) ({ \
    u32 status = unit->status; \
    register u32 mask asm(reg) = (number); \
    register u32 value asm("r0") = mask; \
    mask &= status; \
    value = mask; \
    value; \
})
#define WRITE_WORD(ptrreg, valreg, target, number) { \
    register u32 *pointer asm(ptrreg) = &(target); \
    register u32 value asm(valreg) = (number); \
    *pointer = value; \
}

void func_0802AC0C(void)
{
    register struct BattleTask *task asm("r4");
    register struct BattleFields *tasks asm("sl");
    register u32 *child_busy asm("sb");
    register u8 *script asm("r8");
    struct BattleUnit *unit;
    u32 cleanup_slot;
    {
        register u32 current asm("r1") = D_02000030;
        register u32 offset asm("r0");
        register struct BattleTask *base asm("r1");
        asm("" : "+r"(current));
        offset = current * 136;
        asm("" : "+r"(offset));
        base = D_02000034.tasks;
        asm("" : "+r"(base) : "r"(offset));
        task = (struct BattleTask *)(offset + (u32)base);
        asm("" : : "r"(task), "r"(base));
        tasks = (struct BattleFields *)base;
        asm("" : : "r"(tasks));
    }
    {
        register u32 offset asm("r0") = 0x2C0;
        asm("" : "+r"(offset));
        offset += (u32)tasks;
        asm("" : "+r"(offset));
        child_busy = (u32 *)offset;
        asm("" : : "r"(child_busy));
    }
    {
        register u8 *source asm("r1") = D_08675BEC;
        asm("" : "+r"(source));
        script = source;
        asm("" : : "r"(script));
    }
    for (;;)
    {
        register s32 state asm("r1");
        {
            register u32 held asm("r0");
            asm volatile("" : "=r"(held));
            state = task->state;
            asm("" : "+r"(state) : "r"(held));
        }
        if (state == 4300) goto state_4300;
        if (state > 4300) goto dispatch_high;
        if (state == 2500) goto state_2500;
        if (state > 2500) goto dispatch_middle;
        if (state == 1900) goto state_1900;
        if (state > 1900) goto dispatch_2000;
        if (state == 100) goto state_100;
        if (state > 100) goto dispatch_1000;
        if (state == 0) goto state_0;
        goto dispatch_done;
dispatch_1000:
        if (state == 1000) goto state_1000;
        if (state == 1010) goto state_1010;
        goto dispatch_done;
dispatch_2000:
        if (state == 2010) goto state_2010;
        if (state > 2010) goto dispatch_2300;
        if (state == 2000) goto state_2000;
        goto dispatch_done;
dispatch_2300:
        if (state == 2300) goto state_2300;
        if (state == 2310) goto state_2310;
        goto dispatch_done;
dispatch_middle:
        if (state == 3800) goto state_3800;
        if (state > 3800) goto dispatch_4000;
        if (state == 3030) goto state_3030;
        if (state > 3030) goto dispatch_3050;
        if (state == 3000) goto state_3000;
        goto dispatch_done;
dispatch_3050:
        {
            register s32 compare asm("r5") = 3050;
            if (state == compare) goto state_3050;
        }
        if (state == 3100) goto state_3100;
        goto dispatch_done;
dispatch_4000:
        if (state == 4000) goto state_4000;
        if (state > 4000) goto dispatch_4100;
        if (state == 3810) goto state_3810;
        goto dispatch_done;
dispatch_4100:
        if (state == 4100) goto state_4100;
        if (state == 4200) goto state_4200;
        goto dispatch_done;
dispatch_high:
        if (state == 7000) goto state_7000;
        if (state > 7000) goto dispatch_8000;
        if (state == 5000) goto state_5000;
        if (state > 5000) goto dispatch_5500;
        if (state == 4410) goto state_4410;
        if (state > 4410) goto dispatch_4500;
        if (state == 4400) goto state_4400;
        goto dispatch_done;
dispatch_4500:
        if (state == 4500) goto state_4500;
        if (state == 4510) goto state_4510;
        goto dispatch_done;
dispatch_5500:
        if (state == 5500) goto state_5500;
        if (state > 5500) goto dispatch_5600;
        if (state == 5100) goto state_5100;
        goto dispatch_done;
dispatch_5600:
        if (state == 5600) goto state_5600;
        if (state == 6000) goto state_6000;
        goto dispatch_done;
dispatch_8000:
        if (state == 9100) goto state_9100;
        if (state > 9100) goto dispatch_9500;
        if (state == 8000) goto state_8000;
        if (state > 8000) goto dispatch_8100;
        if (state == 7100) goto state_7100;
        goto dispatch_done;
dispatch_8100:
        if (state == 8100) goto state_8100;
        {
            register s32 compare asm("r2") = 9000;
            if (state == compare) goto state_9000;
        }
        goto dispatch_done;
dispatch_9500:
        if (state == 9510) goto state_9510;
        if (state > 9510) goto dispatch_9520;
        if (state == 9500) goto state_9500;
        goto dispatch_done;
dispatch_9520:
        if (state == 9520) goto state_9520;
        goto dispatch_done;
        switch (state)
        {
        case 0:
state_0:
            {
                u16 zero = state;
                func_0805D270(&zero, &D_0200EB84, 0x010015F6);
            }
            func_0802B528();
            task->state = 100;
        case 100:
state_100:
            func_08000DB8(); func_0802F07C();
            task->state = 1000;
            break;
        case 1000:
state_1000:
            func_08003DF8(5, func_0802E9CC);
            func_08003DF8(8, func_0802F8F8);
            task->state = 1010;
            break;
        case 1010:
state_1010:
        {
            register u32 reply asm("r0") = CHILD_REPLY("r1");
            if (reply == 1)
            {
                func_08003E3C(5); func_08033D6C();
                task->state = 1900;
            }
            else if (reply == 2)
            {
                func_08003E3C(5);
                goto end_battle;
            }
            break;
        }
        case 1900:
state_1900:
            if (D_02005C70[0] & 4) func_080337F0();
            func_08033718(); func_080338A8(0); func_08032684();
            if (({
                register u32 base asm("r0") = (u32)&D_0200EB84;
                register u32 offset asm("r5");
                offset = 0x21E8;
                asm("" : "+r"(base), "+r"(offset));
                base += offset;
                *(u8 *)base;
            }))
            {
                register u32 state asm("r0") = 9000;
                task->state = state;
            }
            else task->state = 7000;
            break;
        case 2000:
state_2000:
            func_0802FA94(); func_0802F5B8();
            func_08003DF8(5, func_0802F09C);
            task->state = 2010;
            break;
        case 2010:
state_2010:
            if (CHILD_REPLY("r1") == 1)
            { func_08003E3C(5); task->state = 2300; }
            break;
        case 2300:
state_2300:
            func_08003DF8(5, func_0802FD4C);
            task->state = 2310;
            break;
        case 2310:
state_2310:
            if (CHILD_REPLY("r2") == 1)
            { func_08003E3C(5); task->state = 2500; }
            break;
        case 2500:
state_2500:
            func_08032410();
        case 3000:
state_3000:
            func_08033D94(100); func_0802FA94();
            {
                register u32 base asm("r2") = (u32)&D_0200EB84;
                register u32 offset asm("r5") = 0x21B5;
                register u32 turn asm("r1");
                register u32 side asm("r0");
                turn = *(u8 *)(base + offset);
                turn = turn * 4 + base;
                side = *(u8 *)(turn + 0x21B8);
                asm("" : : "r"(side), "r"(turn), "r"(offset));
                offset += 4;
                turn = *(u8 *)(turn + offset);
                unit = func_0802B504(side, turn);
            }
            func_0802F8AC();
            func_08003DF8(5, func_0802FAA8);
            ZERO_GLOBAL("r1", D_020002E4);
            task->state = 3030;
            break;
        case 3030:
state_3030:
            if (CHILD_REPLY("r2") == 1)
            { cleanup_slot = 5; goto remove_child; }
            break;
        case 3050:
state_3050:
            if (STATUS_MASK("r1", 0x2000))
                goto finish_unit;
            else if ((unit->flags & 1) || (STATUS_MASK("r5", 0x4000)))
                task->state = 3800;
            else
            {
                if (!unit->hidden) func_08031598(unit->slot);
                func_08003DF8(5, func_0802E814);
                func_08003DF8(6, func_0802E9C0);
                D_020002E4 = (u32)unit;
                {
                    register u32 *pointer asm("r1") = &D_0200036C;
                    *pointer = (u32)unit;
                }
                task->state = 3100;
            }
            break;
        case 3100:
state_3100:
        {
            register struct BattleFields *fields asm("r1") = &D_02000034.fields;
            if (CHILD_REPLY("r2") == 1)
            {
                register u32 offset asm("r5") = 0x2C4;
                switch (({
                    register u32 result asm("r0") = (u32)fields + offset;
                    asm("" : "+r"(result) : "r"(fields), "r"(offset));
                    result = *(u32 *)result;
                    result;
                }))
                {
                case 0: task->state = 4000; break;
                case 1: task->state = 4500; break;
                case 2: task->state = 5500; break;
                }
                func_08003E3C(5); func_08003E3C(6);
            }
            break;
        }
        case 3800:
state_3800:
            func_0803E488(script, 6); func_0803E488(script, 7);
            func_080339C4(unit); TEXT_B(0x20); func_0803E488(script, 5);
            func_08004018(); task->state = 3810;
        case 3810:
state_3810:
            if (LOAD_GLOBAL("r1", D_02000514) != 1) break;
            goto finish_unit;
            break;
        case 4000:
state_4000:
            func_08003DF8(10, func_08004034);
            WRITE_WORD("r1", "r0", tasks->fade, 1); ZERO_GLOBAL("r5", D_02000590);
            func_0802FA3C(); task->state = 4100;
            break;
        case 4100:
state_4100:
            if (LOAD_GLOBAL("r1", D_0200059C) == 1)
            { func_08003E3C(10); task->state = 4200; }
            break;
        case 4200:
state_4200:
            func_0802BBC8(); func_08003DF8(5, func_0802BC98);
            task->state = 4300;
            break;
        case 4300:
state_4300:
        {
            register u32 reply asm("r0") = CHILD_REPLY("r2");
            if (reply == 1) { func_08003E3C(5); task->state = 5000; }
            else if (reply == 2) { func_08003E3C(5); func_08003DF8(8, func_0802F8F8); task->state = 4400; }
            break;
        }
        case 4400:
state_4400:
            func_08000DB8(); func_08000D1C(0);
            func_08001DE4(D_08663D44[24]); func_08031074(); func_080317D0();
            D_03004B9C[5] = -0xC0000;
            func_0802F07C(); TEXT_A(2);
            func_08003DF8(8, func_0802F8F8); func_08003DF8(10, func_08004034);
            {
                register u32 *pointer asm("r1") = &tasks->fade;
                register u32 zero asm("r0");
                zero = 0;
                *pointer = zero;
                D_02000590 = zero;
            }
            task->state = 4410;
            break;
        case 4410:
state_4410:
            if (LOAD_GLOBAL("r2", D_0200059C) != 1) break;
            cleanup_slot = 10;
remove_child:
            func_08003E3C(cleanup_slot);
            {
                register u32 state asm("r5") = 3050;
                task->state = state;
            }
            break;
        case 4500:
state_4500:
            func_0803E488(script, 6); func_0803E488(script, 7);
            func_080339C4(unit); TEXT_B(0x1A); func_0803E488(script, 5);
            {
                register u32 status asm("r0") = unit->status;
                register u32 mask asm("r2");
                register u32 value asm("r1");
                mask = 0x100;
                value = mask;
                asm("" : "+r"(status), "+r"(mask), "+r"(value));
                unit->status = status | value;
            }
            func_08004018(); task->state = 4510;
        case 4510:
state_4510:
            if (LOAD_GLOBAL("r5", D_02000514) == 1) task->state = 6000;
            break;
        case 5000:
state_5000:
            func_08003DF8(5, func_0802BCA4); task->state = 5100;
            break;
        case 5100:
state_5100:
            if (CHILD_REPLY("r1") == 1)
            {
                func_08003E3C(5); func_08003DF8(8, func_0802F8F8);
finish_unit:
                {
                    register u32 state asm("r2") = 6000;
                    task->state = state;
                }
            }
            break;
        case 5500:
state_5500:
            func_08003DF8(5, func_08038F30); task->state = 5600;
            break;
        case 5600:
state_5600:
        {
            register u32 reply asm("r0") = CHILD_REPLY("r5");
            if (reply == 1) { func_08003E3C(5); func_08031C64(); task->state = 6000; }
            else if (reply == 2)
            {
                register u32 state asm("r1");
                func_08003E3C(5);
                state = 3050;
                task->state = state;
            }
            break;
        }
        case 6000:
state_6000:
            if (!unit->hidden)
            { func_08031618(unit, 16); func_08031598(unit->slot); }
            func_0802FA94(); func_0802F8E8(); func_08032684();
            {
                register u32 base asm("r1") = (u32)&D_0200EB84;
                register u32 offset asm("r2");
                register u32 address asm("r0");
                register u32 mode asm("r3");
                offset = 0x21E8;
                address = base + offset;
                mode = *(u8 *)address;
                if (mode)
                {
                    register u32 state asm("r5") = 9000;
                    task->state = state;
                }
                else
                {
                    register u32 index asm("r0") = 0x21B5;
                    register u8 *pointer asm("r2");
                    register u32 count_offset asm("r5");
                    pointer = (u8 *)(base + index);
                    index = *pointer;
                    ++index;
                    *pointer = index;
                    count_offset = 0x21B4;
                    base += count_offset;
                    asm("" : "+r"(base) : "r"(count_offset), "r"(index), "r"(pointer), "r"(mode));
                    base = *(u8 *)base;
                    if ((u8)index >= base)
                    {
                        *pointer = mode;
                        func_0802F5C4();
                        task->state = 7000;
                    }
                    else task->state = 3000;
                }
            }
            break;
        case 7000:
state_7000:
            func_08031C64(); TEXT_A(6); TEXT_A(7); TEXT_B(0x3B); TEXT_A(5);
            if (D_02005C70[0] & 1) TEXT_A(0x19); else TEXT_A(3);
            switch ((u32)D_02007574[1])
            {
            case 0: task->state = 2000; break;
            case 1: task->state = 8000; break;
            case 2:
                if (func_08033DC8()) func_0802F04C();
                func_08032684();
                if (D_0200EB84.mode)
                {
end_battle:
                    {
                        register u32 state asm("r2") = 9000;
                        task->state = state;
                    }
                }
                else task->state = 7100;
                break;
            }
            break;
        case 7100:
state_7100:
            func_0803E488(script, 6); func_0803E488(script, 7); TEXT_B(14);
            func_0803E488(script, 5); func_0803E488(script, 20);
            task->state = 2000;
            break;
        case 8000:
state_8000:
            func_08003DF8(5, func_0803B73C); task->state = 8100;
            break;
        case 8100:
state_8100:
        {
            register u32 reply asm("r0") = CHILD_REPLY("r5");
            if (reply == 1) { func_08003E3C(5); task->state = 2000; }
            else if (reply == 2) { func_08003E3C(5); task->state = 7000; }
            break;
        }
        case 9000:
state_9000:
            func_0802FA94(); func_08003DF8(5, func_08035778); task->state = 9100;
            break;
        case 9100:
state_9100:
            if (CHILD_REPLY("r1") == 1)
            { func_08003E3C(5); task->state = 9500; }
            break;
        case 9500:
state_9500:
            func_08003DF8(10, func_08004034); WRITE_WORD("r0", "r1", tasks->fade, 1);
            ZERO_GLOBAL("r2", D_02000590); task->state = 9510;
        case 9510:
state_9510:
            if (LOAD_GLOBAL("r5", D_0200059C) == 1)
            { func_08003E3C(10); task->state = 9520; }
            break;
        case 9520:
state_9520:
            func_0802FA3C(); TEXT_A(1); task->busy = 1; task->state = 9900;
            break;
        case 9900:
state_9900:
            break;
        }
dispatch_done:
        func_0805EE78(1);
    }
}

struct BattleUnit *func_0802B504(u8 side, u8 slot)
{
    register u32 first asm("r0") = side * 4312;
    register u32 base asm("r2");
    asm("" : "+r"(first) : "r"(slot));
    base = (u32)D_0200EB8C;
    asm("" : "+r"(base) : "r"(first));
    first = first + base;
    asm("" : "+r"(first) : "r"(slot));
    return (struct BattleUnit *)(first + slot * 716);
}
