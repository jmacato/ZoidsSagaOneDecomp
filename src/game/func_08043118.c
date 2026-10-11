#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 data;
    u8 pad_10[8];
    s32 busy;
    u8 pad_1C[0x6C];
};

struct Window
{
    u16 id;
    u8 open;
};

struct Info
{
    u8 pad_0[4];
    u8 kind;
    u8 pad_5[0x47];
};

extern struct
{
    u8 pad_0[0x33E2];
    u8 seen[1];
} D_02000B5C;
extern u8 D_02000030;
extern struct Task D_02000034[];
extern struct Window D_0200D920;
extern u16 D_0200DA74;
extern struct
{
    u16 choice;
    u8 pad_2[8];
    u16 id;
    u8 index;
    u8 pad_D;
    u16 category;
} D_02007574;
extern u16 D_03002356;
extern u16 D_03002358;
extern u16 D_0300235A;
extern struct Info D_0867006C[];
extern const u8 D_086D3BF0[];
extern u8 D_0870067C[];
extern u8 *D_0870068C[][20];
extern u8 *D_08700CCC[][20];
extern u8 *D_0870130C[][20];
extern u8 *D_0870194C[][20];

void func_08003DF8(s32, void *);
void func_08004034(void);
void func_08003E3C(s32);
void func_0803E024(s32, s32, s32);
void func_0803E454(s32);
void func_0803E488(u8 *, s32);
void func_08042FB4(void);
void func_08043E18(struct Window *, s32, s32);
void func_08044DE8(s32, s32, s32);
void func_08044E04(u32, u32);
void func_08000D1C(s32);
void func_080430D0(struct Window *);
void func_080457F8(struct Window *, s32);
void func_08043058(void);
void func_08044F54(void);
u16 func_0800175C(s32, s32);
void func_0804206C(void);
u8 func_08042094(void);
void func_08041E1C(void);
void func_0805EE78(s32);

u8 func_08043118(u16 id)
{
    if (D_02000B5C.seen[id])
        return 1;
    else
        return 0;
}

void func_0804313C(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct
    {
        s32 category;
        u8 **table;
    } local;
    u8 index;
    u32 cursor;
    register u32 next asm("r5");
    u16 keys;
    u8 kind;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            *(vu16 *)0x05000000 = 0;
            task->state = 0x1001;
        case 1:
            *(vu16 *)0x04000000 = 0x100;
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 0;
            D_02000034[10].data = 0;
            func_0803E024(3, 0, 0x32);
            func_0803E454(2);
            local.category = (u8)D_02007574.category;
            asm("" : : : "r1", "r2", "r3");
            index = D_02007574.index;
            asm("" : : : "r5");
            next = 0x20;
            task->state = 0x1020;
            break;
        case 0x20:
            if (D_02007574.category == 0xFF)
                task->state = 0x50;
            else
                task->state++;
            break;
        case 0x21:
            next = 0x22;
            goto set_navigation_state;
        case 0x22:
        {
            register u32 zero asm("r1");
            func_08042FB4();
            func_0803E024(3, 0, 0x32);
            func_0803E488(D_0870067C, 0);
            asm("" : : : "r9");
            zero = 0;
            asm("" : "+r"(zero));
            cursor = zero;
            task->state = 0x10;
            break;
        }
        case 0x10:
        {
            register s32 selected asm("r2") = local.category;
            register u8 **selected_table asm("r0");
            asm("" : "+r"(selected));
            if (selected == 1)
                goto table_one;
            if (selected > 1)
                goto more_tables;
            if (selected == 0)
                goto table_zero;
            goto table_ready;
        more_tables:
            {
            s32 more = local.category;
            if (more == 2)
                goto table_two;
            if (more == 3)
                goto table_three;
            goto table_ready;
            }
        table_zero:
            selected_table = D_0870068C[index];
            goto table_store;
        table_one:
            selected_table = D_08700CCC[index];
            goto table_store;
        table_two:
            selected_table = D_0870130C[index];
            goto table_store;
        table_three:
            selected_table = D_0870194C[index];
        table_store:
            asm("" : : "r"(selected_table));
            local.table = selected_table;
        table_ready:
            task->state = 0x1050;
            break;
        }
        case 0x1050:
        {
            register u32 delta asm("r1");
            func_0803E488(D_0870067C, 1);
            func_0803E488((u8 *)local.table, cursor);
            D_0200D920.id = D_02007574.id;
            kind = D_086D3BF0[D_0200D920.id];
            D_0200D920.open = D_0867006C[D_0200D920.id].kind;
            func_08043E18(&D_0200D920, kind, 0);
            delta = 0xFF500000;
            asm("" : : "r"(delta));
            next = 0;
            func_08044DE8(1, delta, 0);
            func_08044E04(D_0200D920.id, 0);
            func_08000D1C(0);
            D_0200DA74 = next;
            func_0805EE78(1);
            func_080430D0(&D_0200D920);
            func_080457F8(&D_0200D920, 0);
            func_0805EE78(1);
            if (!func_08043118(D_0200D920.id))
            {
                func_0803E488(D_0870067C, 1);
                func_0803E488(D_0870067C, 3);
                func_08043058();
            }
            *(vu16 *)0x04000000 = 0x1740;
            func_08003DF8(8, func_08044F54);
            next = 0x1010;
            task->state = 0x1000;
            break;
        }
        case 0x1010:
            keys = func_0800175C(0x10, 6);
            if (keys & 1)
            {
                func_0803E488(D_0870067C, 2);
                task->state = 0x1011;
            }
            else if (keys & 0x200)
            {
                D_02007574.choice = 2;
                task->state = 0x1011;
            }
            else if (keys & 0x100)
            {
                D_02007574.choice = 1;
                task->state = 0x1011;
            }
            else if (keys & 2)
            {
                D_02007574.choice = 0xFF;
                task->state = 0x1011;
            }
            break;
        case 0x1011:
            switch (D_02007574.choice)
            {
            case 0:
                task->state = 0x1010;
                break;
            case 0xFF:
                next = 0;
                task->state = 0x1001;
                break;
            case 1:
            {
                register u32 selected_cursor asm("r0") = local.table[cursor + 1] ? (u16)(cursor + 1) : 0;
                asm("" : : "r"(selected_cursor));
                cursor = selected_cursor;
                next = 0x1050;
                goto set_choice_state;
            }
            case 2:
            {
                register u32 previous_cursor asm("r2") = cursor;
                asm("" : "+r"(previous_cursor));
                if (previous_cursor != 0)
                {
                    cursor = (u16)(cursor - 1);
                }
                else
                {
                search_last:
                    asm volatile("" : : : "memory");
                    if (!local.table[cursor + 1])
                        goto cursor_ready;
                    cursor = (u16)(cursor + 1);
                    goto search_last;
                }
            cursor_ready:
                next = 0x1050;
            set_navigation_state:
                task->state = 0x1001;
                break;
            }
            }
            break;
        case 0x1012:
            next = 0x1013;
        set_choice_state:
            task->state = 0x1001;
            break;
        case 0x1013:
            func_08003E3C(8);
            task->state = 0x1050;
            break;
        case 0x1020:
            if (D_02000034[10].busy == 1)
            {
                *(vu16 *)0x05000000 = 0;
                func_08003E3C(10);
                task->state = next;
            }
            break;
        case 0x30:
            D_03002356 = 0x10;
            task->state = 0x40;
            break;
        case 0x40:
            if (D_03002356 & 0xF)
                D_03002356--;
            else
                task->state = next;
            break;
        case 0x1000:
            func_0804206C();
            task->state = 0x1002;
            break;
        case 0x1001:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 1;
            D_02000034[10].data = 0;
            task->state = 0x1020;
            break;
        case 0x1003:
            func_08003E3C(10);
            task->state = 0x1001;
            next = 0x2000;
            break;
        case 0x1002:
            if (func_08042094())
                task->state = next;
            break;
        case 0x1005:
            if (D_0300235A & 8)
            {
                next = 0x2000;
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
            next = 0x2000;
            break;
        case 0x2000:
            func_08003E3C(8);
            func_08041E1C();
            task->state = 0x2001;
            task->busy = 1;
            func_08003E3C(6);
            task->busy = 1;
            break;
        }
        asm("" : : "r"(next));
        func_0805EE78(1);
    }
}
