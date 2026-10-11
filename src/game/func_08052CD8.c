#include "types.h"

struct Task
{
    u8 pad_0[8];
    u32 message;
    u32 data;
    u8 pad_10[8];
    s32 busy;
    u32 result;
    u8 pad_20[0x68];
};
struct Menu
{
    u8 pad_0[0x6B5];
    u8 cursor;
    u8 pad_6B6;
    u8 arrows;
};
struct Definition
{
    u8 pad_0[4];
    u32 cost;
    u8 pad_8[4];
    volatile u8 zoid;
    u8 weapons[2];
    u8 pad_F[0x3D];
};
extern u8 D_02000030;
extern struct Task D_02000034[];
extern volatile u16 D_02007574;
extern u16 D_02007588;
extern struct Menu D_020075A0;
extern u8 D_0200E6DF[];
extern u8 D_0200E778;
extern struct Definition D_0867008C[];
extern const u8 D_08675C5C[];
extern const u8 D_08676254[];
extern const u8 D_0875AFB8[];
extern const u8 D_0875B068[];
extern const u8 D_0875B168[];
extern const u8 D_0875B320[];
void func_08000DB8(void);
void func_08000D1C(u8);
void func_0803E024(u8, u8, u8);
void func_08003DF8(u8, void (*)(void));
void func_08003E3C(u8);
void func_08004034(void);
void func_0804E30C(void);
void func_0803E488(const void *, s32);
void func_080019EC(u16);
void func_0805EE78(u32);
void func_08032800(u8);
void func_08001848(u32, s32, s32);

void func_08052CD8(void)
{
    volatile u32 frame[3];
    register u32 last asm("r9");
    s32 page;
    s32 previous;
    register u32 working asm("r8");
    register u32 old_selection_shift asm("r10");
    struct Definition *definition;
    register u32 i asm("r5");
    s32 selection;
    register u8 *global_count asm("r4");
    register s32 previous_selection asm("r1");
    register u32 update_shift asm("r0");

    {
    register struct Task *tasks asm("r5");
    register u32 *fade_data asm("r7");
    func_08000DB8();
    func_08000D1C(0);
    *(volatile u16 *)0x04000000 = 0x1140;
    func_0803E024(3, 0, 255);
    old_selection_shift = (u32)func_08004034;
    asm("" : "+r"(old_selection_shift));
    func_08003DF8(10, (void (*)(void))old_selection_shift);
    tasks = D_02000034;
    asm("" : "+r"(tasks));
    {
        register u32 pointer asm("r0") = 0x558;
        asm("" : "+r"(pointer));
        pointer += (u32)tasks;
        asm("" : "+r"(pointer));
        working = pointer;
    }
    asm("" : "+r"(working));
    {
        register u32 zero asm("r0") = 0;
        asm("" : "+r"(zero));
        *(u32 *)working = zero;
        {
            register u32 offset asm("r2") = 0x55C;
            asm("" : "+r"(offset));
            fade_data = (u32 *)((u8 *)tasks + offset);
            asm("" : "+r"(fade_data));
        }
        *fade_data = zero;
    }
    func_0804E30C();
    func_0803E488(D_0875B168, 5);
    func_0803E488(D_0875AFB8, 24);
    if (D_0200E778 == 0)
        goto empty;
    func_0803E488(D_0875B168, 6);
    {
        register u32 zero asm("r3") = 0;
        register u32 previous asm("r5");
        asm("" : "+r"(zero));
        frame[0] = zero;
        asm("" : "=r"(previous) : "0"(65535), "m"(frame[0]));
        frame[2] = previous;
        frame[1] = previous;
        D_02007588 = zero;
    }
    goto loop;

empty:
    func_0803E488(D_0875B068, 15);
    func_080019EC(65);
    func_08003DF8(10, (void (*)(void))old_selection_shift);
    {
        register u32 one asm("r0") = 1;
        register u32 *message asm("r2");
        asm("" : "+r"(one));
        message = (u32 *)working;
        asm("" : "+r"(message));
        *message = one;
    }
    *fade_data = 0;
    {
        register u32 offset asm("r3") = 0x568;
        register s32 *pointer asm("r1");
        s32 *busy;
        asm("" : "+r"(offset));
        pointer = (s32 *)((u8 *)tasks + offset);
        asm("" : "+r"(pointer));
        if (*pointer != 1)
        {
            busy = pointer;
            asm("" : "+r"(busy));
            do
                func_0805EE78(1);
            while (*busy != 1);
        }
    }
    func_08003E3C(10);
    goto cancel;
    }

loop:
    {
        register u32 word asm("r5") = frame[0];
        register u32 shifted asm("r1");
        register s32 current asm("r4");
        register s32 previous_word asm("r2");
        register u32 previous_shift asm("r0");
        register u32 selected_word asm("r3");
        asm("" : "+r"(word));
        shifted = word << 16;
        asm("" : "+r"(shifted));
        current = (s32)shifted >> 16;
        asm("" : "+r"(current));
        previous_word = frame[1];
        asm("" : "+r"(previous_word));
        previous_shift = previous_word << 16;
        asm("" : "+r"(previous_shift));
        previous_word = (s32)previous_shift >> 16;
        asm("" : "+r"(previous_word));
        working = shifted;
        selected_word = frame[2];
        asm("" : "+r"(selected_word));
        selected_word <<= 16;
        asm("" : "+r"(selected_word));
        old_selection_shift = selected_word;
        page = current;
        previous = previous_word;
    }
    if (page != previous)
    {
        if (previous != -1)
            func_0803E488(D_0875AFB8, 2);
        {
            register u32 base asm("r7");
            register u32 doubled asm("r2");
            register u8 *count asm("r6");
            s32 signed_last;
            i = 0;
            {
                register u32 triple asm("r0") = page * 3;
                register u32 normalized asm("r1");
                doubled = triple << 1;
                asm("" : "+r"(triple), "+r"(doubled));
                triple <<= 17;
                normalized = triple >> 16;
                asm("" : "+r"(triple), "+r"(normalized));
                last = normalized;
                signed_last = (s32)triple >> 16;
            }
            {
                register u8 *pointer asm("r1") = &D_0200E778;
                register s32 size asm("r3");
                asm("" : "+r"(pointer));
                global_count = pointer;
                size = *global_count;
                asm("" : "+r"(size));
                if (signed_last >= size)
                    goto list_done;
            }
            count = global_count;
            base = doubled;
            asm("" : "+r"(count), "+r"(base));
list_loop:
            {
                s32 row;
                s32 count_signed;
                {
                    u8 *pointer = D_0200E6DF;
                    register u32 saved asm("r2");
                    register u32 shifted asm("r0");
                    register s32 signed_row asm("r4");
                    saved = last;
                    asm("" : "+r"(pointer), "+r"(saved));
                    shifted = saved << 16;
                    signed_row = (s32)shifted >> 16;
                    asm("" : "+r"(shifted), "+r"(signed_row));
                    row = signed_row;
                    {
                        u8 *address = (u8 *)((u32)row + (u32)pointer);
                        asm("" : "+r"(address));
                        func_08032800(*address);
                    }
                }
                if ((s16)i <= 4 && row < *count - 1)
                    func_0803E488(D_08675C5C, 0);
                {
                    register u32 shifted asm("r0") = (u32)i << 16;
                    register u32 step asm("r3");
                    step = 0x10000;
                    asm("" : "+r"(shifted), "+r"(step));
                    shifted += step;
                    i = shifted >> 16;
                    count_signed = (s32)shifted >> 16;
                }
                global_count = &D_0200E778;
                asm("" : "+r"(global_count));
                if (count_signed > 5)
                    goto list_done;
                {
                    register u32 shifted asm("r0") = (count_signed + base) << 16;
                    register u32 normalized asm("r1");
                    register s32 size asm("r2");
                    normalized = shifted >> 16;
                    asm("" : "+r"(shifted), "+r"(normalized));
                    last = normalized;
                    signed_last = (s32)shifted >> 16;
                    size = *count;
                    asm("" : "+r"(size));
                    if (signed_last < size)
                        goto list_loop;
                }
            }
list_done:
        }
        {
            register u32 count_shift asm("r0") = i << 16;
            register s32 count_signed asm("r0");
            register u16 *choice asm("r3");
            register struct Menu *window asm("r2");
            register u32 current_choice asm("r1");
            register u8 *arrows asm("r2");
            count_signed = (s32)count_shift >> 16;
            asm("" : "+r"(count_signed));
            choice = &D_02007588;
            window = &D_020075A0;
            asm("" : "+r"(choice), "+r"(window));
            current_choice = *choice;
            asm("" : "+r"(current_choice));
            if (count_signed <= (s32)current_choice)
            {
                register u32 clamped asm("r0") = i - 1;
                register u32 offset asm("r5");
                register u8 *cursor asm("r1");
                asm("" : "+r"(clamped));
                offset = 0x6B5;
                cursor = (u8 *)window + offset;
                asm("" : "+r"(offset), "+r"(cursor));
                *cursor = clamped;
                clamped = (u8)clamped;
                *choice = clamped;
            }
            {
                register u32 offset asm("r0") = 0x6B7;
                register u32 flags asm("r3");
                register u32 zero asm("r0");
                asm("" : "+r"(offset));
                arrows = (u8 *)window + offset;
                asm("" : "+r"(arrows));
                flags = 0;
                asm volatile("" : "+r"(flags));
                zero = 0;
                asm("" : "+r"(zero));
                *arrows = zero;
            }
            {
                register s32 saved asm("r1") = working;
                asm("" : "+r"(saved));
                if (saved > 0)
                    *arrows = 1;
            }
            {
                register u32 saved asm("r5") = last;
                register u32 shifted asm("r1");
                register s32 signed_last asm("r1");
                register s32 end asm("r0");
                shifted = saved << 16;
                asm("" : "+r"(saved), "+r"(shifted));
                signed_last = (s32)shifted >> 16;
                end = *global_count - 1;
                asm("" : "+r"(signed_last), "+r"(end));
                if (signed_last < end)
                    *arrows |= 2;
            }
            {
                register u32 saved asm("r0") = working;
                asm("" : "+r"(saved));
                frame[1] = saved >> 16;
            }
        }
    }
    asm("" : "+r"(working));
    {
        register u32 shifted asm("r1") = (((s32)working >> 16) * 6 + D_02007588) << 16;
        register u32 normalized asm("r2") = shifted >> 16;
        asm("" : "+r"(shifted), "+r"(normalized));
        working = normalized;
        selection = (s32)shifted >> 16;
    }
    {
        register u32 saved asm("r3") = old_selection_shift;
        asm("" : "+r"(saved));
        previous_selection = (s32)saved >> 16;
    }
    asm("" : "+r"(previous_selection));
    if (selection != previous_selection)
    {
        if (previous_selection != -1)
            func_0803E488(D_0875AFB8, 1);
        definition = &D_0867008C[D_0200E6DF[selection]];
        func_0803E488(D_0875AFB8, 26);
        func_0803E488(D_0875B168, 1);
        func_08001848(definition->cost, 7, 1);
        func_0803E488(D_0875B168, 2);
        func_0803E488(D_0875AFB8, 42);
        {
            register u32 zoid asm("r0") = definition->zoid;
            if (zoid == 0)
                goto no_zoid;
            if (zoid > 249)
                goto special_zoid;
            func_08032800(zoid);
            goto zoid_done;
special_zoid:
            func_0803E488(D_0875B320, definition->zoid - 250);
            goto zoid_done;
no_zoid:
            func_0803E488(D_0875B168, 4);
zoid_done:
            ;
        }
        func_0803E488(D_08675C5C, 0);
        func_0803E488(D_0875B168, 3);
        func_0803E488(D_0875AFB8, 42);
        if (definition->weapons[0] != 255)
        {
            func_0803E488(D_08676254, definition->weapons[0]);
            func_0803E488(D_08675C5C, 0);
            if (definition->weapons[1] != 255)
            {
                func_0803E488(D_0875AFB8, 42);
                func_0803E488(D_08676254, definition->weapons[1]);
            }
        }
        else if (definition->weapons[1] != 255)
            func_0803E488(D_08676254, definition->weapons[1]);
        else
            func_0803E488(D_0875B168, 4);
        func_0803E488(D_0875AFB8, 24);
        {
            register u32 base asm("r0") = (u32)D_02000034;
            register u32 offset asm("r5");
            register s32 *pointer asm("r1");
            register s32 state asm("r0");
            register u32 saved asm("r2");
            register u32 selected_shift asm("r5");
            asm("" : "+r"(base));
            offset = 0x568;
            asm("" : "+r"(offset));
            pointer = (s32 *)(base + offset);
            asm("" : "+r"(pointer));
            state = *pointer;
            asm("" : "+r"(state));
            saved = working;
            selected_shift = saved << 16;
            asm("" : "+r"(saved), "+r"(selected_shift));
            if (state != 1)
            {
                s32 *busy = pointer;
                asm("" : "+r"(busy));
                do
                    func_0805EE78(1);
                while (*busy != 1);
            }
            func_0803E488(D_0875AFB8, 27);
            selected_shift >>= 16;
            asm("" : "+r"(selected_shift));
            frame[2] = selected_shift;
        }
    }
    func_0803E488(D_0875AFB8, 35);
    {
        register volatile u16 *pointer asm("r1") = &D_02007574;
        register u32 choice asm("r0");
        asm("" : "+r"(pointer));
        choice = *pointer;
        asm("" : "+r"(choice));
        if (choice <= 1)
            goto choice_done;
        if (choice == 2)
            goto previous_page;
        if (choice == 4)
            goto next_page;
        goto loop;
    }
previous_page:
    {
        register u32 saved asm("r3") = frame[0];
        register s32 current asm("r4");
        asm("" : "+r"(saved));
        update_shift = saved << 16;
        asm("" : "+r"(update_shift));
        current = (s32)update_shift >> 16;
        asm("" : "+r"(current));
        if (current <= 0)
            goto loop;
        func_080019EC(64);
        update_shift = (current - 1) << 16;
        asm("" : "+r"(update_shift));
        goto update_page;
    }
next_page:
    {
        register u32 saved asm("r5") = last;
        register u32 shifted asm("r1");
        register s32 row asm("r1");
        register u8 *pointer asm("r0");
        register s32 stop asm("r0");
        asm("" : "+r"(saved));
        shifted = saved << 16;
        asm("" : "+r"(shifted));
        row = (s32)shifted >> 16;
        asm("" : "+r"(row));
        pointer = &D_0200E778;
        asm("" : "+r"(pointer));
        stop = *pointer - 1;
        asm("" : "+r"(stop));
        if (row >= stop)
            goto loop;
        func_080019EC(64);
        {
            register u32 page asm("r1") = frame[0];
            register u32 step asm("r2");
            asm("" : "+r"(page));
            update_shift = page << 16;
            asm("" : "+r"(update_shift));
            step = 0x10000;
            asm("" : "+r"(step));
            update_shift += step;
            asm("" : "+r"(update_shift));
        }
    }
update_page:
    update_shift >>= 16;
    frame[0] = update_shift;
    goto loop;
choice_done:
    if (D_02007574 == 1)
        D_02000034[D_02000030].result = D_0200E6DF[(s16)working];
    else
        func_080019EC(63);
    func_08003DF8(10, func_08004034);
    {
        register u8 *base asm("r1") = (u8 *)D_02000034;
        register u32 message_offset asm("r5");
        register u32 *message asm("r2");
        register u32 value asm("r0");
        register u32 busy_offset asm("r2");
        register s32 *pointer asm("r1");
        asm("" : "+r"(base));
        message_offset = 0x558;
        asm("" : "+r"(message_offset));
        message = (u32 *)(base + message_offset);
        asm("" : "+r"(message));
        value = 1;
        asm("" : "+r"(value));
        *message = value;
        value = 0x55C;
        asm("" : "+r"(value));
        message = (u32 *)(base + value);
        asm("" : "+r"(message));
        value = 0;
        asm("" : "+r"(value));
        *message = value;
        busy_offset = 0x568;
        asm("" : "+r"(busy_offset));
        pointer = (s32 *)(base + busy_offset);
        asm("" : "+r"(pointer));
        {
            s32 *busy;
            if (*pointer != 1)
            {
                busy = pointer;
                asm("" : "+r"(busy));
                do
                    func_0805EE78(1);
                while (*busy != 1);
            }
        }
    }
    func_08003E3C(10);
    {
        register volatile u16 *pointer asm("r0") = &D_02007574;
        register u32 choice asm("r3");
        asm("" : "+r"(pointer));
        choice = *pointer;
        asm("" : "+r"(choice));
        if (choice == 1)
        {
            D_02000034[D_02000030].busy = choice;
            return;
        }
    }
cancel:
    D_02000034[D_02000030].busy = 2;
}
