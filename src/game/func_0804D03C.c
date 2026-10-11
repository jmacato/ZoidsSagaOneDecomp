#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[18];
    u32 complete;
    u8 pad_1C[108];
};

struct Sprite
{
    u8 pad_0[6];
    u16 attr2;
    u32 x;
    u32 y;
    u8 pad_10[120];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern struct Sprite D_03004BBC[];
extern vu16 D_03002356;
extern vu16 D_03002358;
extern vu16 D_0300235A;
extern u16 D_02007574[];
extern u8 D_02000B5C[];
extern s32 D_08705548[][20];
extern s32 D_08705868[][20];
extern s32 D_08705B88[][20];
extern s32 D_08705EA8[][20];
extern s32 D_087061C8[][20];
extern u8 D_0870553C[];

void func_0804CC20(void);
void func_08003DF8(u16, void (*)(void));
void func_08004034(void);
void func_08000D1C(u16);
void func_0804CF68(void);
void func_0803E454(u16);
u16 func_0804CD18(u8);
u16 func_0804CDA8(u8, u8);
void func_0803E024(u16, u16, u16);
void func_0803E488(const void *, u32);
u16 func_0804CCF0(s32);
u16 func_0804CFFC(const s32 *, u32);
u16 func_0804D018(const s32 *, u32);
void func_08009EA8(u16);
u32 func_08009D94(u32, u32, u32);
u16 func_0800175C(u16, u16);
void func_08003E3C(u16);
void func_0804206C(void);
u8 func_08042094(void);
void func_08041E1C(void);
void func_0805EE78(u32);

#define PILOT_FLAGS_R2(value) \
    ({ register u32 selected asm("r0") = (value); \
       register u8 *base asm("r1") = D_02000B5C; \
       register u8 *field asm("r0"); \
       register u32 bias asm("r2"); \
       asm("" : : "r"(selected), "r"(base)); \
       field = (u8 *)(selected * 4 + (u32)base); \
       asm("" : : "r"(field)); \
       bias = 0x34A4; \
       asm("" : : "r"(field), "r"(bias)); \
       *(u16 *)(field + bias); })

#define PILOT_FLAGS_R1(value) \
    ({ register u32 selected asm("r0") = (value); \
       register u8 *base asm("r1") = D_02000B5C; \
       register u8 *field asm("r0"); \
       register u32 bias asm("r1"); \
       asm("" : : "r"(selected), "r"(base)); \
       field = (u8 *)(selected * 4 + (u32)base); \
       asm("" : : "r"(field)); \
       bias = 0x34A4; \
       asm("" : : "r"(field), "r"(bias)); \
       *(u16 *)(field + bias); })

void func_0804D03C(void)
{
    register struct Task *task asm("r6");
    s32 *list;
    register u32 pilot asm("r8");
    register u32 position asm("r9");
    register u32 variant asm("r10");
    struct
    {
        u32 scan;
        u32 next;
        u32 kind;
    } local;

    {
        register u32 slot asm("r1") = D_02000030;
        register u32 offset asm("r0");
        register struct Task *base asm("r1");
        asm("" : : "r"(slot));
        offset = slot * 136;
        asm("" : : "r"(offset));
        base = D_02000034;
        asm("" : : "r"(offset), "r"(base));
        task = (struct Task *)(offset + (u32)base);
    }
    asm("" : "+r"(list), "+r"(pilot), "+r"(position), "+r"(variant));

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            *(vu16 *)0x05000000 = 0;
            {
                register u32 next asm("r1") = 1;
                asm("" : : "r"(next));
                local.next = next;
            }
            task->state = 0x1001;
        case 1:
            func_0804CC20();
            task->state = 2;
            break;
        case 2:
            func_08003DF8(10, func_08004034);
            {
                register u8 *base asm("r0") = (u8 *)D_02000034;
                register u32 offset asm("r2") = 0x558;
                register u32 *field asm("r1");
                asm("" : : "r"(base), "r"(offset));
                field = (u32 *)(base + offset);
                offset = 0;
                asm("" : : "r"(field), "r"(offset));
                *field = offset;
                field = (u32 *)0x55C;
                asm("" : "+r"(field));
                base += (u32)field;
                *(u32 *)base = offset;
            }
            func_08000D1C(0);
            func_0804CF68();
            func_0803E454(4);
            if (D_02007574[7] != 255)
            {
                local.kind = (u8)func_0804CD18((u8)D_02007574[7]);
                variant = (u8)func_0804CDA8(local.kind, *((u8 *)D_02007574 + 12));
            }
            {
                register u32 next asm("r2") = 0x20;
                asm("" : : "r"(next));
                local.next = next;
            }
            task->state = 0x1020;
            break;
        case 0x20:
            if (D_02007574[7] == 255)
                task->state = 0x50;
            else
                task->state++;
            break;
        case 0x21:
            local.next = 0x22;
            task->state = 0x1001;
            break;
        case 0x22:
            func_0803E024(3, 0, 50);
            func_0803E488(D_0870553C, 0);
            position = 0;
            task->state = 0x10;
            break;
        case 0x10:
        {
            u32 kind = local.kind;
            register u32 offset asm("r0");
            register s32 *base asm("r1");
            asm("" : "+l"(kind) : : "r0", "r1");
            switch (kind)
            {
            case 0:
            {
                register u32 selected asm("r1") = variant;
                asm("" : "+r"(selected));
                offset = (selected * 4 + variant) * 16;
                asm("" : : "r"(offset));
                base = (s32 *)D_08705548;
                break;
            }
            case 1:
            {
                register u32 selected asm("r2") = variant;
                asm("" : "+r"(selected));
                offset = (selected * 4 + variant) * 16;
                asm("" : : "r"(offset));
                base = (s32 *)D_08705868;
                break;
            }
            case 2:
            {
                register u32 selected asm("r1") = variant;
                asm("" : "+r"(selected));
                offset = (selected * 4 + variant) * 16;
                asm("" : : "r"(offset));
                base = (s32 *)D_08705B88;
                break;
            }
            case 3:
            {
                register u32 selected asm("r2") = variant;
                asm("" : "+r"(selected));
                offset = (selected * 4 + variant) * 16;
                asm("" : : "r"(offset));
                base = (s32 *)D_08705EA8;
                break;
            }
            case 4:
            {
                register u32 selected asm("r1") = variant;
                asm("" : "+r"(selected));
                offset = (selected * 4 + variant) * 16;
                asm("" : : "r"(offset));
                base = (s32 *)D_087061C8;
                break;
            }
            default:
                goto keep_list;
            }
            asm("" : : "r"(offset), "r"(base));
            list = (s32 *)(offset + (u32)base);
        keep_list:
            {
                register u32 zero asm("r2") = 0;
                asm("" : : "r"(zero));
                local.scan = zero;
            }
            task->state = 0x1050;
            break;
        }
        case 0x1050:
            if (local.scan > 19)
            {
                task->state = 0;
                break;
            }
            {
                register u32 current asm("r1") = position;
                register s32 *field asm("r0");
                asm("" : : "r"(current));
                field = (s32 *)(current * 4 + (u32)list);
                asm("" : : "r"(field));
                pilot = func_0804CCF0(*field);
            }
            if (!(PILOT_FLAGS_R2(pilot) & 0x20))
            {
                local.scan = (u16)(local.scan + 1);
                position = func_0804CFFC(list, position);
                task->state = 0x1050;
                break;
            }
            func_0803E488(D_0870553C, 0);
            func_0803E488(list, position);
            func_08009EA8(1);
            func_08009D94(1, pilot + 0x98, 1);
            D_03004BBC[1].attr2 = 0;
            D_03004BBC[1].x = 0x500000;
            D_03004BBC[1].y = 0x100000;
            *(vu16 *)0x04000000 = 0x1140;
            local.next = 0x1010;
            task->state = 0x1000;
            break;
        case 0x1010:
        {
            u16 keys = func_0800175C(16, 6);
            register u16 *menu asm("r0");
            register u32 response asm("r1");
            if (keys & 1)
            {
                func_0803E488(D_0870553C, 2);
                goto menu_transition;
            }
            else if (keys & 0x200)
            {
                menu = D_02007574;
                response = 2;
                asm("" : : "r"(menu), "r"(response));
                goto menu_response;
            }
            else if (keys & 0x100)
            {
                menu = D_02007574;
                asm("" : : "r"(menu));
                *menu = 1;
                goto menu_transition;
            }
            else if (keys & 2)
            {
                menu = D_02007574;
                response = 255;
                asm("" : : "r"(menu), "r"(response));
                goto menu_response;
            }
            else
                goto animation_keys;
        menu_response:
            *menu = response;
        menu_transition:
            task->state = 0x1011;
            break;
        animation_keys:
        {
                if (D_0300235A & 0x40)
                    func_08009D94(1, pilot + 0x98, 4);
                if (D_0300235A & 0x80)
                    func_08009D94(1, pilot + 0x98, 5);
                if (D_0300235A & 0x20)
                    func_08009D94(1, pilot + 0x98, 6);
                if (D_0300235A & 0x10)
                    func_08009D94(1, pilot + 0x98, 7);
        }
            break;
        }
        case 0x1011:
            switch (D_02007574[0])
            {
            case 0:
                task->state = 0x1010;
                break;
            case 255:
                {
                    register u32 zero asm("r1") = 0;
                    asm("" : : "r"(zero));
                    local.next = zero;
                }
                task->state = 0x1001;
                break;
            case 1:
            {
                register u32 result asm("r2");
                do
                {
                    asm volatile("" : : : "memory");
                    position = func_0804CFFC(list, position);
                    if (position == 0)
                    {
                        result = 0;
                        asm("" : : "r"(result));
                        goto record_position;
                    }
                    pilot = func_0804CCF0(list[position]);
                } while (!(PILOT_FLAGS_R1(pilot) & 0x20));
                result = position;
                asm("" : : "r"(result));
            record_position:
                local.scan = result;
                asm volatile("" : : : "memory");
                {
                    register u32 reloaded asm("r0") = local.scan;
                    asm("" : : "r"(reloaded));
                    position = reloaded;
                }
                {
                    register u32 next asm("r1") = 0x1050;
                    asm("" : : "r"(next));
                    local.next = next;
                }
                task->state = 0x1001;
                break;
            }
            case 2:
            {
                u8 *flags = D_02000B5C;
                asm("" : "+l"(flags));
                do
                {
                    register u8 *field asm("r0");
                    register u32 bias asm("r2");
                    position = func_0804D018(list, position);
                    pilot = func_0804CCF0(list[position]);
                    field = (u8 *)(pilot * 4 + (u32)flags);
                    asm("" : : "r"(field));
                    bias = 0x34A4;
                    asm("" : : "r"(field), "r"(bias));
                    if (*(u16 *)(field + bias) & 0x20)
                        break;
                } while (1);
                local.next = 0x1050;
                task->state = 0x1001;
                break;
            }
            }
            {
                register u32 zero asm("r1") = 0;
                asm("" : : "r"(zero));
                local.scan = zero;
            }
            break;
        case 0x1020:
        {
            register u8 *base asm("r0") = (u8 *)D_02000034;
            register u32 offset asm("r2") = 0x568;
            asm("" : : "r"(base), "r"(offset));
            if (*(u32 *)(base + offset) == 1)
            {
                register vu16 *palette asm("r1") = (vu16 *)0x05000000;
                register u32 zero asm("r0") = 0;
                asm("" : : "r"(palette), "r"(zero));
                *palette = zero;
                func_08003E3C(10);
                {
                    register vu16 *next asm("r0") = (vu16 *)&local;
                    asm("" : : "r"(next));
                    task->state = next[2];
                }
            }
            break;
        }
        case 0x30:
            D_03002356 = 16;
            task->state = 0x40;
            break;
        case 0x40:
        {
            register vu16 *field asm("r2") = &D_03002356;
            register u32 current asm("r1") = *field;
            asm("" : : "r"(current));
            if (current & 15)
            {
                register u32 reduced asm("r0") = current - 1;
                asm("" : : "r"(reduced));
                *field = reduced;
            }
            else
                goto restore_next;
            break;
        }
        case 0x1000:
            func_0804206C();
            task->state = 0x1002;
            break;
        case 0x1001:
            func_08003DF8(10, func_08004034);
            {
                register u8 *base asm("r1") = (u8 *)D_02000034;
                register u32 offset asm("r0") = 0x558;
                register u32 *field asm("r2");
                asm("" : : "r"(base), "r"(offset));
                field = (u32 *)(base + offset);
                offset = 1;
                asm("" : : "r"(field), "r"(offset));
                *field = offset;
                field = (u32 *)0x55C;
                asm("" : "+r"(field));
                base += (u32)field;
                offset = 0;
                asm("" : : "r"(base), "r"(offset));
                *(u32 *)base = offset;
            }
            task->state = 0x1020;
            break;
        case 0x1003:
            func_08003E3C(10);
            task->state = 0x1001;
            {
                register u32 next asm("r0") = 0x2000;
                asm("" : : "r"(next));
                local.next = next;
            }
            break;
        case 0x1002:
            if (func_08042094())
            {
            restore_next:
            {
                register vu16 *next asm("r1") = (vu16 *)&local;
                register u32 state asm("r1");
                asm("" : : "r"(next));
                state = next[2];
                asm("" : : "r"(state));
                task->state = state;
            }
            }
            break;
        case 0x1005:
            if (D_0300235A & 8)
            {
                local.next = 0x2000;
                task->state = 0x1001;
            }
            if (D_0300235A & 1)
                task->state = 0x1001;
            if (D_03002358 & 2)
                task->state = 0x1001;
            break;
        case 0x50:
            func_08003E3C(10);
            task->state = 0x1001;
            {
                register u32 next asm("r1") = 0x2000;
                asm("" : : "r"(next));
                local.next = next;
            }
            break;
        case 0x2000:
            func_08000D1C(0);
            func_08003E3C(8);
            func_08041E1C();
            task->state = 0x2001;
            task->complete = 1;
            func_08003E3C(6);
            task->complete = 1;
            break;
        }
        func_0805EE78(1);
    }
}
