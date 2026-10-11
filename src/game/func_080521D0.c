#include "types.h"

#include "game/player_state.h"

struct Bonuses
{
    u8 pad_0[4];
    s16 hp;
    s16 speed;
    s16 attack;
    s16 defense;
    s16 accuracy;
};
struct Menu
{
    u8 pad_0[13];
    u8 cursor;
    u8 pad_E[0xA0B - 14];
    u8 arrows;
};
struct Task
{
    u8 pad_0[8];
    s32 message;
    u32 data;
    u8 pad_10[8];
    s32 busy;
    u8 pad_1C[0x6C];
};
extern PlayerState D_02000B5C;
extern struct Menu D_020075A0;
extern struct Task D_02000034[];
extern u8 D_02000030;
extern volatile u16 D_02007574;
extern volatile u16 D_02007576;
extern u16 D_02007588;
extern u8 D_0200E5F0[];
extern u8 D_0200E647;
extern u8 D_02007FA9;
extern u8 D_020078F9;
extern u8 D_02007C4D;
extern u8 D_02007FA1;
extern u8 D_0200904B[];
extern u8 D_03004BBC[];
extern const u8 D_0875B0D0[];
extern const u8 D_0875B0F8[];
extern const u8 D_0875B124[];
extern const u8 D_0875AFB8[];
extern const u8 D_0875B4F0[];
extern const u8 D_08675C5C[];
void func_0804E2B8(void);
void func_0804E37C(u8);
void func_0803E488(const void *, s32);
void func_08032818(u32);
void func_08032800(u8);
struct Bonuses *func_080334F8(u8);
void func_08001848(s32, s32, s32);
void func_080019EC(u16);
void func_0805EE78(u32);
void func_0804E350(const PlayerZoid *);
void func_0804D654(u32, u32, u32);
void func_0804DFB8(u8, s16);
void func_0804E094(u8, s16);
void func_08003DF8(u8, void (*)(void));
void func_08004034(void);
void func_08003E3C(u8);

void func_080521D0(void)
{
    volatile struct
    {
        struct { u16 fields[4]; } saved_cursor, saved_page;
        u32 page;
        u32 selected;
        u32 previous_selected;
        u32 selected_zoid;
        u32 previous_zoid;
        u32 previous_shift;
        u32 row_index;
    } frame;
    register u32 last asm("r10");
    register u32 page_shift asm("r8");
    register s32 state asm("r5");
    register const u8 *equipment_layout asm("r4");
    register u32 state_bits asm("r0");
    register u32 exit_bits asm("r6");
    func_0804E2B8();
    func_0804E37C(7);
    state = 0x1100;
    state_bits = (u32)state << 16;
    do
    {
        switch ((s32)state_bits >> 16)
        {
        case 0x1100:
        {
            register const u8 *table asm("r4") = D_0875B0D0;
            func_0803E488(table, 9);
            func_0803E488(table, 0);
            frame.page = 0;
            D_02007588 = 0;
            state = 0x1102;
            break;
        }
        case 0x1101:
            func_0803E488(D_0875B0D0, 0);
            {
                volatile u16 *saved_page = frame.saved_page.fields;
                asm("" : "+r"(saved_page));
                frame.page = saved_page[2];
            }
            {
                register u16 *cursor_destination asm("r1") = &D_02007588;
                register u8 *cursor_flag asm("r3");
                register u32 cursor asm("r0");
                cursor = frame.saved_cursor.fields[2];
                cursor_flag = &D_02007FA9;
                asm("" : "+r"(cursor_flag), "+r"(cursor_destination) : "r"(cursor));
                *cursor_flag = cursor;
                *cursor_destination = (u8)cursor;
            }
        case 0x1102:
        {
            register s32 previous_page asm("r7");
            register const u8 *layout asm("r9");
            register u32 new_page_bits asm("r0");
            register u32 initial asm("r5") = 65535;
            frame.previous_selected = initial;
            previous_page = initial;
            frame.previous_zoid = initial;
            {
                register const u8 *initial_layout asm("r0") = D_0875AFB8;
                layout = initial_layout;
                asm("" : "+r"(layout) : "r"(initial_layout), "r"(initial));
            }
        list_loop:
            {
                register s32 current_page asm("r4");
                register s32 previous asm("r2");
                register s32 old_selection asm("r0");
                register s32 current_selection asm("r4");
                {
                    register u32 saved asm("r2") = frame.page;
                    register u32 shifted asm("r1");
                    register u32 old_shift asm("r0");
                    asm("" : "+r"(saved));
                    shifted = saved << 16;
                    current_page = (s32)shifted >> 16;
                    old_shift = previous_page << 16;
                    previous = (s32)old_shift >> 16;
                    page_shift = shifted;
                }
                {
                    register u32 old asm("r3") = frame.previous_selected;
                    old <<= 16;
                    frame.previous_shift = old;
                    asm("" : "+r"(page_shift), "+r"(current_page), "+r"(previous), "+r"(old));
                }
                if (current_page != previous)
                {
                    register u32 count asm("r5");
                    register s32 base asm("r2");
                    register u8 *limit_for_end asm("r4");
                    register s32 initial_index asm("r0");
                    register s32 initial_count asm("r3");
                    if (previous != -1)
                        func_0803E488(D_0875AFB8, 3);
                    count = 0;
                    {
                        register u32 partial asm("r0") = current_page * 3;
                        register u32 shifted asm("r0");
                        register u32 low asm("r1");
                        register u8 *initial_limit asm("r1");
                        base = partial << 1;
                        shifted = partial << 17;
                        low = shifted >> 16;
                        last = low;
                        asm("" : "+r"(last) : "r"(base), "r"(low));
                        initial_index = (s32)shifted >> 16;
                        initial_limit = &D_0200E647;
                        limit_for_end = initial_limit;
                        initial_count = *limit_for_end;
                        asm("" : "+r"(initial_index), "+r"(limit_for_end) : "r"(initial_limit), "r"(initial_count));
                    }
                    if (initial_index >= initial_count)
                        goto rows_done;
                    {
                        u8 *limit = limit_for_end;
                        register s32 base_cache asm("r6") = base;
                    row_loop:
                        {
                        register u32 saved_index asm("r1") = last;
                        register u32 index_shift asm("r0");
                        register s32 index asm("r4");
                        register u8 *ids asm("r2");
                        register u8 *address asm("r0");
                        register s32 next_index asm("r0");
                        index_shift = saved_index << 16;
                        asm("" : "+r"(index_shift) : "r"(saved_index));
                        index = (s32)index_shift >> 16;
                        ids = D_0200E5F0;
                        address = (u8 *)((u32)index + (u32)ids);
                        asm("" : "+r"(address) : "r"(index), "r"(ids));
                        func_08032818(*address);
                        if ((s16)count <= 4 && index < *limit - 1)
                            func_0803E488(D_08675C5C, 0);
                        {
                            register u32 shifted asm("r0") = count << 16;
                            register u32 increment asm("r3") = 65536;
                            s32 signed_count;
                            asm("" : "+r"(shifted) : "r"(increment));
                            shifted += increment;
                            count = shifted >> 16;
                            signed_count = (s32)shifted >> 16;
                            limit_for_end = &D_0200E647;
                            if (signed_count > 5)
                                goto rows_done;
                            {
                                register u32 total asm("r0") = signed_count;
                                register u32 low asm("r1");
                                total += base_cache;
                                total <<= 16;
                                low = total >> 16;
                                last = low;
                                next_index = (s32)total >> 16;
                                asm("" : "+r"(next_index), "+r"(last) : "r"(low));
                            }
                        }
                        {
                            register u32 bound asm("r2");
                            bound = *limit;
                            asm("" : : "r"(bound));
                            if (next_index < (s32)bound)
                                goto row_loop;
                        }
                        }
                    }
                rows_done:
                    {
                        register s32 final_count asm("r0") = (s16)count;
                        register u16 *cursor asm("r1") = &D_02007588;
                        register struct Menu *menus asm("r2") = &D_020075A0;
                        asm("" : "+r"(final_count), "+r"(cursor), "+r"(menus));
                        if (final_count <= *cursor)
                        {
                            register u32 clamped asm("r0") = count - 1;
                            register u8 *flag asm("r5") = &D_02007FA9;
                            *flag = clamped;
                            *cursor = (u8)clamped;
                        }
                        {
                            register u32 offset asm("r0") = 0xA0B;
                            register u8 *arrows asm("r2");
                            register u32 cleared asm("r3");
                            arrows = (u8 *)menus + offset;
                            cleared = 0;
                            asm volatile("" : "+r"(arrows), "+r"(cleared) : "r"(offset));
                            *arrows = 0;
                            {
                            register s32 visible_page asm("r1") = (s32)page_shift;
                            asm("" : "+r"(visible_page));
                            if (visible_page > 0)
                                *arrows = 1;
                            }
                            {
                            register u32 final_last asm("r5") = last;
                            register s32 last_signed asm("r1");
                            last_signed = (s16)final_last;
                            asm("" : "+r"(last_signed) : "r"(final_last));
                            if (last_signed < *limit_for_end - 1)
                                *arrows |= 2;
                            }
                        }
                    }
                    {
                        register u32 saved_shift asm("r0") = page_shift;
                        asm("" : : "r"(saved_shift));
                        previous_page = saved_shift >> 16;
                    }
                }
                {
                    register u32 selected_shift asm("r1") = page_shift;
                    register s32 page asm("r0");
                    register u16 *cursor asm("r0");
                    register u32 cursor_value asm("r0");
                    register u32 low asm("r2");
                    asm("" : : "r"(selected_shift));
                    page = (s32)selected_shift >> 16;
                    selected_shift = page * 3;
                    cursor = &D_02007588;
                    selected_shift <<= 1;
                    cursor_value = *cursor;
                    selected_shift += cursor_value;
                    selected_shift <<= 16;
                    low = selected_shift >> 16;
                    frame.selected = low;
                    current_selection = (s32)selected_shift >> 16;
                    asm("" : "+r"(current_selection) : "r"(selected_shift), "r"(low));
                }
                {
                    register u32 saved_shift asm("r3") = frame.previous_shift;
                    old_selection = (s32)saved_shift >> 16;
                }
                if (current_selection != old_selection)
                {
                    register struct Bonuses *bonuses asm("r4");
                    register u8 *pilot asm("r5");
                    register u32 selected_bits asm("r6");
                    register u32 selected_zoid asm("r4");
                    register PlayerState *player asm("r6");
                    if (old_selection != -1)
                    {
                        func_0803E488(layout, 1);
                        func_0803E488(layout, 2);
                    }
                    {
                        register u8 *ids asm("r1");
                        register u8 *member asm("r0");
                        register u32 pilot_index asm("r0");
                        register u32 slot_offset asm("r2");
                        register u32 loaded_zoid asm("r0");
                        player = &D_02000B5C;
                        ids = D_0200E5F0;
                        member = (u8 *)((u32)current_selection + (u32)ids);
                        pilot_index = *member;
                        pilot_index <<= 2;
                        member = (u8 *)(pilot_index + (u32)player);
                        slot_offset = (u8 *)&((PlayerState *)0)->pilots[0].zoid_slot - (u8 *)0;
                        asm("" : "+r"(member), "+r"(slot_offset), "+r"(player) : "r"(ids));
                        member += slot_offset;
                        loaded_zoid = *member;
                        frame.selected_zoid = loaded_zoid;
                        selected_zoid = loaded_zoid;
                    }
                    if (selected_zoid != 255)
                    {
                        register u32 previous_zoid asm("r3") = frame.previous_zoid;
                        register s32 old_zoid asm("r0");
                        old_zoid = (s16)previous_zoid;
                        if (old_zoid == -1 || old_zoid != selected_zoid)
                        {
                            func_0803E488(layout, 0);
                            func_0803E488(layout, 25);
                            func_0803E488(D_0875B0D0, 6);
                            {
                                register u32 stride asm("r0") = selected_zoid * sizeof(PlayerZoid);
                                register u8 *model asm("r0");
                                register u32 model_offset asm("r5");
                                model = (u8 *)(stride + (u32)player);
                                model_offset = (u8 *)&((PlayerState *)0)->zoids[0].model_id - (u8 *)0;
                                model += model_offset;
                                asm("" : "+r"(model) : "r"(model_offset));
                                func_08032800(*model);
                            }
                            func_0803E488(D_0875B0D0, 7);
                        }
                    }
                    else if (frame.previous_zoid != 255)
                    {
                        func_0803E488(layout, 0);
                        func_0803E488(layout, 25);
                        func_0803E488(D_0875B0D0, 8);
                    }
                    {
                        register u32 saved_selection asm("r1") = frame.selected;
                        register u8 *ids asm("r2");
                        register s32 index asm("r5");
                        selected_bits = saved_selection << 16;
                        index = (s32)selected_bits >> 16;
                        ids = D_0200E5F0;
                        pilot = (u8 *)((u32)index + (u32)ids);
                        asm("" : "+r"(pilot), "+r"(selected_bits) : "r"(ids), "r"(saved_selection));
                    }
                    bonuses = func_080334F8(*pilot);
                    func_0803E488(layout, 26);
                    func_08032818(*pilot);
                    {
                        register const u8 *separator asm("r0") = D_08675C5C;
                        func_0803E488(separator, 0);
                    }
                    func_0803E488(D_0875B0D0, 1);
                    {
                        register u32 held_one asm("r1");
                        register u32 held_two asm("r2");
                        register s32 value asm("r0");
                        asm("" : "=r"(held_one), "=r"(held_two));
                        value = bonuses->hp;
                        asm("" : "+r"(value) : "r"(held_one), "r"(held_two));
                        func_08001848(value, 3, 4);
                    }
                    func_0803E488(layout, 39);
                    {
                        register const u8 *separator asm("r0") = D_08675C5C;
                        func_0803E488(separator, 0);
                    }
                    func_0803E488(D_0875B0D0, 2);
                    func_08001848(bonuses->defense, 3, 4);
                    func_0803E488(layout, 39);
                    {
                        register const u8 *separator asm("r0") = D_08675C5C;
                        func_0803E488(separator, 0);
                    }
                    func_0803E488(D_0875B0D0, 3);
                    {
                        register u32 held_one asm("r1");
                        register u32 held_three asm("r3");
                        register s32 value asm("r0");
                        asm("" : "=r"(held_one), "=r"(held_three));
                        value = bonuses->attack;
                        asm("" : "+r"(value) : "r"(held_one), "r"(held_three));
                        func_08001848(value, 3, 4);
                    }
                    func_0803E488(layout, 39);
                    {
                        register const u8 *separator asm("r0") = D_08675C5C;
                        func_0803E488(separator, 0);
                    }
                    func_0803E488(D_0875B0D0, 4);
                    func_08001848(bonuses->speed, 3, 4);
                    func_0803E488(layout, 39);
                    {
                        register const u8 *separator asm("r0") = D_08675C5C;
                        func_0803E488(separator, 0);
                    }
                    func_0803E488(D_0875B0D0, 5);
                    func_08001848(bonuses->accuracy, 3, 4);
                    func_0803E488(layout, 39);
                    func_0803E488(D_0875B4F0, *pilot);
                    func_0803E488(layout, 24);
                    {
                        register u8 *tasks asm("r0") = (u8 *)D_02000034;
                        register u32 offset asm("r2") = 10 * sizeof(struct Task) + 24;
                        register s32 *current_task asm("r1");
                        register s32 ready asm("r0");
                        register u32 value asm("r3");
                        register u32 zoid_bits asm("r5");
                        current_task = (s32 *)((u32)tasks + offset);
                        ready = *current_task;
                        value = frame.selected_zoid;
                        zoid_bits = value << 16;
                        asm("" : "+r"(zoid_bits), "+r"(ready) : "r"(value), "r"(current_task));
                        if (ready != 1)
                        {
                            register s32 *busy asm("r4") = current_task;
                            do
                            {
                                func_0805EE78(1);
                                ready = *busy;
                            } while (ready != 1);
                        }
                        func_0803E488(D_0875AFB8, 28);
                        frame.previous_zoid = zoid_bits >> 16;
                    }
                    frame.previous_selected = selected_bits >> 16;
                }
                {
                    register const u8 *script asm("r0") = D_0875AFB8;
                    asm("" : "+r"(script) : "r"(page_shift), "r"(previous_page), "r"(last));
                    func_0803E488(script, 35);
                }
                {
                    register volatile u16 *menu asm("r1") = &D_02007574;
                    register u32 choice asm("r0");
                    choice = *menu;
                    asm("" : "+r"(choice) : "r"(menu));
                    if (choice <= 1)
                        goto choose_done;
                    if (choice == 2)
                        goto previous_page;
                    if (choice == 4)
                        goto next_page;
                    goto list_loop;
                }
            }
        previous_page:
            {
                register u32 saved asm("r5") = frame.page;
                register u32 shifted asm("r0");
                register s32 current asm("r4");
                shifted = saved << 16;
                current = (s32)shifted >> 16;
                if (current <= 0)
                    goto list_loop;
                func_080019EC(64);
                new_page_bits = current - 1;
                new_page_bits <<= 16;
                goto store_page;
            }
        next_page:
            {
                register u32 current_last asm("r0") = last;
                register u32 shifted asm("r1");
                register s32 index asm("r1");
                register s32 limit asm("r0");
                shifted = current_last << 16;
                asm("" : "+r"(shifted) : "r"(current_last));
                index = (s32)shifted >> 16;
                limit = D_0200E647;
                if (index >= limit - 1)
                    goto list_loop;
            }
            func_080019EC(64);
            {
                register u32 saved asm("r1") = frame.page;
                register u32 step asm("r2");
                new_page_bits = saved << 16;
                step = 65536;
                asm("" : "+r"(new_page_bits), "+r"(step) : "r"(saved));
                new_page_bits += step;
            }
        store_page:
            frame.page = new_page_bits >> 16;
                goto list_loop;
        choose_done:
            {
                register volatile u16 *menu asm("r1") = &D_02007574;
                register u32 choice asm("r0");
                choice = *menu;
                asm("" : "+r"(choice) : "r"(menu));
                if (choice == 1)
                {
                    register u32 selected_zoid asm("r3");
                    state = 65535;
                            selected_zoid = frame.selected_zoid;
                    if (selected_zoid == 255)
                        break;
                    state = 0x1110;
                            {
                        register volatile u16 *saved_cursor asm("r0") = frame.saved_cursor.fields;
                        register u32 cursor asm("r1") = menu[1];
                        asm("" : "+r"(saved_cursor), "+r"(cursor));
                        saved_cursor[2] = cursor;
                    }
                    {
                        register volatile u16 *saved_page asm("r0") = frame.saved_page.fields;
                        register volatile u16 *frame_start asm("r1") = frame.saved_cursor.fields;
                        asm("" : "+r"(saved_page) : "r"(frame_start));
                        saved_page[2] = *(volatile u16 *)&frame.page;
                    }
                    {
                        register const u8 *script asm("r0") = D_0875AFB8;
                        func_0803E488(script, 11);
                    }
                    {
                        register const u8 *script asm("r0") = D_0875AFB8;
                        func_0803E488(script, 10);
                    }
                    {
                        register const u8 *script asm("r0") = D_0875AFB8;
                        func_0803E488(script, 9);
                    }
                    {
                        register const u8 *script asm("r0") = D_0875AFB8;
                        func_0803E488(script, 0);
                    }
                }
                else
                {
                    func_080019EC(63);
                    state = 65535;
                }
            }
            break;
        }
        case 0x1110:
        {
            register PlayerState *player asm("r5");
            register u32 offset asm("r4");
            register u8 *relative asm("r6");
            register u16 *model asm("r9");
            register const u8 *separator asm("r8");
            func_0803E488(D_0875B0F8, 0);
            func_0803E488(D_0875AFB8, 26);
            player = &D_02000B5C;
            {
                register u32 selected asm("r2") = frame.selected_zoid;
                offset = selected * sizeof(PlayerZoid);
                relative = (u8 *)(offset + (u32)player);
                asm("" : "+r"(relative) : "r"(offset), "r"(player), "r"(selected));
            }
            {
                register u32 model_offset asm("r3") = 0xD32;
                register u16 *address asm("r3");
                asm("" : "+r"(model_offset));
                address = (u16 *)(model_offset + (u32)relative);
                model = address;
                asm("" : "+r"(model) : "r"(address));
                func_08032800(*(u8 *)address);
            }
            {
                register u32 field_offset asm("r1") = 0xD61;
                register u8 *address asm("r0");
                register s32 mode asm("r1");
                address = (u8 *)((u32)relative + field_offset);
                asm("" : "+r"(address) : "r"(field_offset));
                mode = *address + 8;
                func_0803E488(D_0875B0F8, mode);
            }
            {
                register const u8 *low_separator asm("r2") = D_08675C5C;
                separator = low_separator;
                asm("" : "+r"(separator) : "r"(low_separator));
            }
            func_0803E488(separator, 0);
            func_0803E488(D_0875B0F8, 1);
            {
                register u32 field_offset asm("r3") = 0xD2C;
                register u8 *address asm("r0");
                address = (u8 *)((u32)player + field_offset);
                asm("" : "+r"(address) : "r"(field_offset));
                address = (u8 *)(offset + (u32)address);
                func_0804E350((PlayerZoid *)address);
            }
            func_0803E488(D_0875B0F8, 6);
            {
                register u32 field_offset asm("r1") = 0xD54;
                register u8 *address asm("r0");
                address = (u8 *)((u32)player + field_offset);
                asm("" : "+r"(address) : "r"(field_offset));
                address = (u8 *)(offset + (u32)address);
                func_08001848(*(u32 *)address, 4, 0);
            }
            func_0803E488(separator, 0);
            func_0803E488(D_0875B0F8, 2);
            {
                register u32 field_offset asm("r2") = 0xD38;
                register u8 *address asm("r0");
                address = (u8 *)((u32)player + field_offset);
                asm("" : "+r"(address) : "r"(field_offset));
                address = (u8 *)(offset + (u32)address);
                func_08001848(*(u32 *)address, 4, 0);
            }
            func_0803E488(D_0875B0F8, 6);
            {
                register u32 field_offset asm("r3") = 0xD58;
                player = (PlayerState *)((u32)player + field_offset);
                asm("" : "+r"(player) : "r"(field_offset));
            }
            offset += (u32)player;
            func_08001848(*(u32 *)offset, 4, 0);
            func_0803E488(separator, 0);
            func_0803E488(D_0875B0F8, 3);
            {
                register u32 field_offset asm("r5") = 0xD5C;
                {
                    register u8 *address asm("r0");
                    register u32 held_two asm("r2");
                    register u32 held_three asm("r3");
                    register u32 held_four asm("r4");
                    register s32 value asm("r0");
                    address = (u8 *)((u32)relative + field_offset);
                    asm("" : "+r"(address), "=r"(held_two), "=r"(held_three), "=r"(held_four) : "r"(field_offset));
                    value = *(s16 *)address;
                    asm("" : "+r"(value) : "r"(held_two), "r"(held_three), "r"(held_four));
                    func_08001848(value, 4, 0);
                }
                func_0803E488(separator, 0);
                func_0803E488(D_0875B0F8, 4);
                {
                    register u32 defense_offset asm("r2") = 0xD5E;
                    register u8 *address asm("r0");
                    register u32 held_one asm("r1");
                    register u32 held_two asm("r2");
                    register s32 value asm("r0");
                    address = (u8 *)((u32)relative + defense_offset);
                    asm("" : "+r"(address), "=r"(held_one), "=r"(held_two) : "r"(defense_offset));
                    value = *(s16 *)address;
                    asm("" : "+r"(value) : "r"(held_one), "r"(held_two));
                    func_08001848(value, 3, 0);
                }
                func_0803E488(D_0875AFB8, 39);
                func_0803E488(separator, 0);
                func_0803E488(D_0875B0F8, 5);
                field_offset += 4;
                relative = (u8 *)((u32)relative + field_offset);
                func_08001848(*relative, 3, 0);
            }
            {
                register u16 *address asm("r1") = model;
                func_0804D654(*address, 40, 88);
            }
            func_0803E488(D_0875AFB8, 24);
            func_0803E488(D_0875AFB8, 37);
            if (D_02007574 == 1)
                state = 0x1120;
            else
            {
                register s32 cancel_state asm("r7") = 0x1101;
                func_080019EC(63);
                state = cancel_state;
            }
            {
                register u8 *actor asm("r0") = D_03004BBC;
                register u32 flags asm("r1");
                register u32 mask asm("r3");
                register u32 low_mask asm("r2");
                asm("" : "+r"(actor));
                actor += 0x88;
                flags = *(u16 *)actor;
                mask = 0x7FFF;
                low_mask = mask;
                asm("" : "+r"(low_mask), "+r"(flags), "+r"(mask) : "r"(actor));
                flags &= low_mask;
                *(u16 *)actor = flags;
            }
            func_0803E488(D_0875AFB8, 9);
            func_0803E488(D_0875AFB8, 0);
            break;
        }
        case 0x1120:
            func_0803E488(D_0875B124, 10);
            func_0803E488(D_0875B124, 0);
            state = frame.selected;
            {
                register s32 index asm("r0") = (s16)state;
                register u8 *ids asm("r1");
                register u8 *pilot asm("r0");
                ids = D_0200E5F0;
                pilot = (u8 *)((u32)index + (u32)ids);
                func_0804DFB8(*pilot, 0);
            }
            equipment_layout = D_0875AFB8;
            func_0803E488(equipment_layout, 24);
            func_0803E488(equipment_layout, 37);
            if (D_02007574 == 1)
                state = 0x1130;
            else
            {
                func_080019EC(63);
                state = 0x1101;
                goto clear_nine;
            }
            break;
        case 0x1130:
            func_0803E488(D_0875B124, 1);
            {
                register u32 selected asm("r2") = frame.selected;
                register s32 index asm("r0");
                register u8 *ids asm("r3");
                register u8 *pilot asm("r0");
                index = (s16)selected;
                ids = D_0200E5F0;
                pilot = (u8 *)((u32)index + (u32)ids);
                asm("" : "+r"(pilot) : "r"(ids));
                func_0804DFB8(*pilot, 1);
            }
            equipment_layout = D_0875AFB8;
            func_0803E488(equipment_layout, 18);
            func_0803E488(equipment_layout, 37);
            if (D_02007574 == 1)
                state = 0x1140;
            else
            {
                func_080019EC(63);
                state = 0x1101;
                goto clear_ten;
            }
            break;
        case 0x1140:
        {
            register u32 row asm("r5") = 0;
            register u8 *menus asm("r2") = (u8 *)&D_020075A0;
            register u32 selected_value asm("r0") = frame.selected;
            register u32 selected_shift asm("r6") = selected_value << 16;
            register s32 initial_limit asm("r1");
            initial_limit = (s32)&D_020078F9;
            initial_limit = *(u8 *)initial_limit;
            asm("" : "+r"(row), "+r"(menus), "+r"(selected_shift), "+r"(initial_limit) : "r"(selected_value));
            if ((s32)row < initial_limit)
            {
                register u8 *flags asm("r12");
                register u8 *count asm("r8");
                register u8 *entries asm("r9");
                u32 mask;
                register u32 column asm("r10");
                {
                    register u8 *literal asm("r3") = D_0200904B;
                    flags = literal;
                    asm("" : "+r"(flags) : "r"(literal));
                }
                {
                    register u32 offset asm("r0") = 0x359;
                    register u8 *address asm("r0");
                    asm("" : "+r"(offset));
                            address = (u8 *)(offset + (u32)menus);
                    count = address;
                }
                {
                    register u32 offset asm("r1") = 0x368;
                    register u8 *address asm("r1");
                    asm("" : "+r"(offset));
                            address = (u8 *)(offset + (u32)menus);
                    entries = address;
                    asm("" : "+r"(entries) : "r"(address));
                }
                mask = 255;
                do
                {
                    register u32 row_shift asm("r4");
                    register s32 signed_row asm("r3");
                    register s32 signed_column asm("r2");
                    register s32 next_row asm("r0");
                        menus = (u8 *)1;
                    column = (u32)menus;
                    asm("" : "+l"(mask), "+r"(menus), "+r"(row) : "r"(flags), "r"(count), "r"(entries), "r"(column));
                    row_shift = row << 16;
                    signed_row = (s32)row_shift >> 16;
                    frame.row_index = signed_row;
                    do
                    {
                        register u8 *entry asm("r1");
                        register u8 *flag asm("r3");
                        register u32 record asm("r0");
                        register u8 *address asm("r1");
                        register u32 size asm("r0");
                        register s32 product asm("r1");
                        register s32 saved_row asm("r3");
                        row = column;
                        signed_column = (s16)row;
                        address = count;
                        size = *address;
                        product = signed_column * size;
                        saved_row = frame.row_index;
                        entry = entries + (saved_row + product);
                        record = *entry;
                        row = (u32)flags;
                        flag = (u8 *)(record + row);
                        record |= mask;
                        *entry = record;
                        record = *flag;
                        record |= mask;
                        *flag = record;
                        signed_column = (u32)(signed_column + 1) << 16;
                        column = (u32)signed_column >> 16;
                        signed_column >>= 16;
                    } while (signed_column <= 2);
                    next_row = row_shift + 65536;
                    row = (u32)next_row >> 16;
                    next_row >>= 16;
                    menus = count;
                    menus = (u8 *)(u32)*menus;
                    if (next_row >= (s32)menus)
                        break;
                } while (1);
            }
            func_0803E488(D_0875B124, 2);
            {
                register s32 selected_index asm("r0") = (s32)selected_shift >> 16;
                register u8 *ids asm("r3");
                ids = D_0200E5F0;
                asm("" : : "r"(ids));
                func_0804DFB8(*(u8 *)((u32)selected_index + (u32)ids), 2);
            }
            {
                equipment_layout = D_0875AFB8;
                func_0803E488(equipment_layout, 19);
            func_0803E488(equipment_layout, 37);
            }
            if (D_02007574 == 1)
                state = 0x1150;
            else
                goto cancel_equipment;
            break;
        }
        case 0x1150:
        {
            register u32 row asm("r5") = 0;
            register u8 *menus asm("r2") = (u8 *)&D_020075A0;
            register u32 selected_shift asm("r6");
            register s32 initial_limit asm("r1");
            {
                register u32 selected_value asm("r0") = frame.selected;
                asm("" : "+r"(selected_value));
                selected_shift = selected_value << 16;
            }
            asm("" : "+r"(row), "+r"(menus), "+r"(selected_shift));
            {
                register u8 *address asm("r1") = &D_02007C4D;
                asm("" : : "r"(address));
                initial_limit = *address;
                asm("" : : "r"(initial_limit));
            }
            if ((s32)row < initial_limit)
            {
                register u8 *flags asm("r12");
                register u8 *count asm("r8");
                register u8 *entries asm("r9");
                u32 mask;
                register u32 column asm("r10");
                {
                    register u8 *literal asm("r3") = D_0200904B;
                    asm("" : "+r"(literal));
                    flags = literal;
                    asm("" : : "r"(flags));
                }
                {
                    register u32 offset asm("r0") = 0x6AD;
                    register u8 *address asm("r0");
                    asm("" : "+r"(offset));
                    address = (u8 *)(offset + (u32)menus);
                    asm("" : "+r"(address));
                    count = address;
                    asm("" : : "r"(count));
                }
                {
                    register u32 offset asm("r1") = 0x6BC;
                    register u8 *address asm("r1");
                    asm("" : "+r"(offset));
                    address = (u8 *)(offset + (u32)menus);
                    asm("" : "+r"(address));
                    entries = address;
                    asm("" : : "r"(entries));
                }
                mask = 255;
                asm("" : "+r"(flags), "+r"(count), "+r"(entries), "+l"(mask));
                do
                {
                    register u32 row_shift asm("r4");
                    register s32 signed_row asm("r3");
                    register s32 signed_column asm("r2");
                    register s32 next_row asm("r0");
                        menus = (u8 *)1;
                    column = (u32)menus;
                    asm("" : "+l"(mask), "+r"(menus), "+r"(row) : "r"(flags), "r"(count), "r"(entries), "r"(column));
                    row_shift = row << 16;
                    signed_row = (s32)row_shift >> 16;
                    frame.row_index = signed_row;
                    do
                    {
                        register u8 *entry asm("r1");
                        register u8 *flag asm("r3");
                        register u32 record asm("r0");
                        register u8 *address asm("r1");
                        register u32 size asm("r0");
                        register s32 product asm("r1");
                        register s32 saved_row asm("r3");
                        row = column;
                        asm("" : "+r"(row) : "r"(column));
                        signed_column = (s16)row;
                        address = count;
                        size = *address;
                        product = signed_column * size;
                        saved_row = frame.row_index;
                        entry = entries + (saved_row + product);
                        record = *entry;
                        row = (u32)flags;
                        flag = (u8 *)(record + row);
                        record |= mask;
                        *entry = record;
                        record = *flag;
                        record |= mask;
                        *flag = record;
                        signed_column = (u32)(signed_column + 1) << 16;
                        column = (u32)signed_column >> 16;
                        signed_column >>= 16;
                    } while (signed_column <= 2);
                    next_row = row_shift + 65536;
                    row = (u32)next_row >> 16;
                    next_row >>= 16;
                    menus = count;
                    menus = (u8 *)(u32)*menus;
                    if (next_row >= (s32)menus)
                        break;
                } while (1);
            }
            func_0803E488(D_0875B124, 7);
            {
                register s32 selected_index asm("r0") = (s32)selected_shift >> 16;
                register u8 *ids asm("r3");
                asm("" : "+r"(selected_index));
                ids = D_0200E5F0;
                asm("" : : "r"(ids));
                func_0804E094(*(u8 *)((u32)selected_index + (u32)ids), 3);
            }
            {
                equipment_layout = D_0875AFB8;
                asm("" : "+r"(equipment_layout));
            func_0803E488(equipment_layout, 17);
            func_0803E488(equipment_layout, 37);
            }
            if (D_02007574 == 1)
                state = 0x1160;
            else
                goto cancel_equipment;
            break;
        }
        case 0x1160:
        {
            register u32 row asm("r5") = 0;
            register u8 *menus asm("r2") = (u8 *)&D_020075A0;
            register u32 selected_value asm("r0") = frame.selected;
            register u32 selected_shift asm("r6") = selected_value << 16;
            register u32 shared asm("r1");

            shared = (u32)&D_02007FA1;
            shared = *(u8 *)shared;
            if ((s32)row < (s32)shared)
            {
                register u8 *flags asm("r12");
                register u8 *count asm("r8");
                register u8 *entries asm("r9");
                register u8 *literal asm("r3") = D_0200904B;
                register u8 *count_address asm("r0");
                register u32 column asm("r10");
                register u32 mask asm("r7");
                flags = literal;
                count_address = (u8 *)0xA01;

                count_address = (u8 *)((u32)count_address + (u32)menus);
                count = count_address;
                asm("" : "+r"(count_address) : "r"(flags), "r"(literal), "r"(count));
                shared = 0xA1;

                shared <<= 4;
                entries = (u8 *)shared;
                entries = (u8 *)((u32)entries + (u32)menus);
                shared = (u32)entries;
                mask = 255;
                do
                {
                    register u32 row_shift asm("r4");
                    register s32 signed_row asm("r3");
                    register s32 signed_column asm("r2");
                    register s32 next_row asm("r0");
                    register s32 bound asm("r2");
                    menus = 0;
                    column = (u32)menus;

                    row_shift = row << 16;
                    signed_row = (s32)row_shift >> 16;
                    frame.row_index = signed_row;
                    do
                    {
                        register u8 *entry asm("r1");
                        register u8 *flag asm("r3");
                        register u32 record asm("r0");
                        register u8 *address asm("r1");
                        register u32 size asm("r0");
                        register s32 product asm("r1");
                        register s32 saved_row asm("r3");
                        row = column;
                        asm("" : "+r"(row), "+r"(mask) : "r"(column), "r"(flags), "r"(count), "r"(entries));
                        signed_column = (s16)row;
                        address = count;
                        size = *address;
                        product = signed_column * size;
                        saved_row = frame.row_index;
                        entry = entries + (saved_row + product);
                        record = *entry;
                        row = (u32)flags;
                        flag = (u8 *)(record + row);
                        record |= mask;
                        *entry = record;
                        record = *flag;
                        record |= mask;
                        *flag = record;
                        signed_column = (u32)(signed_column + 1) << 16;
                        column = (u32)signed_column >> 16;
                        signed_column >>= 16;
                    } while (signed_column <= 1);
                    next_row = row_shift + 65536;
                    row = (u32)next_row >> 16;
                    next_row >>= 16;
                    {
                        register u8 *bound_address asm("r2") = count;

                        bound = *bound_address;
                    }
                    if (next_row >= bound)
                        break;
                } while (1);
            }
            func_0803E488(D_0875B124, 8);
            {
                register s32 selected_index asm("r0") = (s32)selected_shift >> 16;
                register u8 *ids asm("r3");
                ids = D_0200E5F0;

                func_0804E094(*(u8 *)((u32)selected_index + (u32)ids), 4);
            }
            equipment_layout = D_0875AFB8;
            func_0803E488(equipment_layout, 18);
            func_0803E488(equipment_layout, 37);
            if (D_02007574 == 1)
                state = 0x1170;
            else
                goto cancel_equipment;
            break;
        }
        cancel_equipment:
            func_080019EC(63);
            state = 0x1101;
        clear_eleven:
            func_0803E488(equipment_layout, 11);
        clear_ten:
            func_0803E488(equipment_layout, 10);
        clear_nine:
            func_0803E488(equipment_layout, 9);
            func_0803E488(equipment_layout, 0);

            break;
        case 0x1170:
        {
            register u32 row asm("r5");
            register u8 *menus asm("r2");
            register u32 selected_shift asm("r6");
            register s32 initial_limit asm("r1");
            func_0803E488(D_0875B124, 11);
            asm("" : : : "r5");
            row = 0;
            {
                register u32 selected_value asm("r0") = frame.selected;
                asm("" : "+r"(selected_value));
                selected_shift = selected_value << 16;
            }
            asm("" : "+r"(row), "+r"(selected_shift));
            {
                register u8 *address asm("r1") = &D_020078F9;
                asm("" : : "r"(address));
                initial_limit = *address;
                asm("" : : "r"(initial_limit));
            }
            if ((s32)row < initial_limit)
            {
                register u8 *flags asm("r12");
                register u8 *count asm("r8");
                register u8 *entries asm("r9");
                u32 mask;
                register u32 column asm("r10");
                register s32 bound asm("r2");
                register s32 next_row asm("r0");
                menus = (u8 *)&D_020075A0;
                asm("" : : "r"(menus));
                {
                    register u8 *literal asm("r3") = D_0200904B;
                    asm("" : "+r"(literal));
                    flags = literal;
                    asm("" : : "r"(flags));
                }
                {
                    register u32 offset asm("r0") = 0x359;
                    register u8 *address asm("r0");
                    asm("" : "+r"(offset));
                    address = (u8 *)(offset + (u32)menus);
                    asm("" : "+r"(address));
                    count = address;
                    asm("" : : "r"(count));
                }
                {
                    register u32 offset asm("r1") = 0x368;
                    register u8 *address asm("r1");
                    asm("" : "+r"(offset));
                    address = (u8 *)(offset + (u32)menus);
                    asm("" : "+r"(address));
                    entries = address;
                    asm("" : : "r"(entries));
                }
                mask = 255;
                asm("" : "+r"(flags), "+r"(count), "+r"(entries), "+l"(mask));
                do
                {
                    register u32 row_shift asm("r4");
                    register s32 signed_column asm("r2");
                    {
                        register u32 first_column asm("r2") = 1;
                        asm("" : "+r"(first_column));
                        column = first_column;
                    }
                    row_shift = row << 16;
                    asm("" : "+r"(row_shift));
                    {
                        register s32 signed_row asm("r3") = (s32)row_shift >> 16;
                        asm("" : : "r"(signed_row));
                        frame.row_index = signed_row;
                    }
                    do
                    {
                        register u32 column_copy asm("r5") = column;
                        register s32 product asm("r1");
                        register u8 *entry asm("r1");
                        register u8 *flag asm("r3");
                        asm("" : : "r"(column_copy));
                        signed_column = (s16)column_copy;
                        asm("" : "+r"(signed_column));
                        {
                            register u8 *count_address asm("r1") = count;
                            register u32 count_value asm("r0");
                            asm("" : : "r"(count_address));
                            count_value = *count_address;
                            asm("" : : "r"(count_value));
                            product = signed_column;
                            asm("" : "+r"(product));
                            product *= count_value;
                        }
                        {
                            register s32 saved_row asm("r3") = frame.row_index;
                            asm("" : : "r"(saved_row));
                            entry = entries + (saved_row + product);
                            asm("" : "+r"(entry));
                        }
                        {
                            register u32 record asm("r0") = *entry;
                            register u8 *flags_copy asm("r5") = flags;
                            asm("" : : "r"(record), "r"(flags_copy));
                            flag = (u8 *)(record + (u32)flags_copy);
                            asm("" : : "r"(flag));
                            record |= mask;
                            asm("" : "+r"(record));
                            *entry = record;
                        }
                        {
                            register u32 value asm("r0") = *flag;
                            value |= mask;
                            asm("" : "+r"(value));
                            *flag = value;
                        }
                        signed_column = (u32)(signed_column + 1) << 16;
                        asm("" : "+r"(signed_column));
                        {
                            register u32 next_column asm("r0") = (u32)signed_column >> 16;
                            asm("" : : "r"(next_column));
                            column = next_column;
                        }
                        signed_column >>= 16;
                        asm("" : : "r"(signed_column));
                    } while (signed_column <= 2);
                    {
                        register u32 step asm("r1") = 65536;
                        asm("" : "+r"(step));
                        next_row = row_shift + step;
                    }
                    asm("" : "+r"(next_row));
                    row = (u32)next_row >> 16;
                    next_row >>= 16;
                    asm("" : "+r"(next_row));
                    {
                        register u8 *bound_address asm("r2") = count;
                        asm("" : : "r"(bound_address));
                        bound = *bound_address;
                    }
                    asm("" : : "r"(next_row), "r"(bound));
                } while (next_row < bound);
            }
            func_0803E488(D_0875B124, 9);
            {
                register s32 selected_index asm("r0") = (s32)selected_shift >> 16;
                register u8 *ids asm("r3");
                asm("" : "+r"(selected_index));
                ids = D_0200E5F0;
                asm("" : : "r"(ids));
                func_0804E094(*(u8 *)((u32)selected_index + (u32)ids), 5);
            }
            {
                register const u8 *layout asm("r4") = D_0875AFB8;
                asm("" : : "r"(layout));
                func_0803E488(layout, 19);
                func_0803E488(layout, 37);
                if (D_02007574 == 0)
                    func_080019EC(63);
                func_0803E488(layout, 11);
                func_0803E488(layout, 10);
                func_0803E488(layout, 9);
                func_0803E488(layout, 0);
            }
            asm("" : : : "r5");
            state = 0x1101;
            asm("" : "+r"(state));
            break;
        }
        }
        state_bits = (u32)state << 16;
        asm("" : "+r"(state_bits));
        exit_bits = state_bits;
        asm("" : : "r"(exit_bits));
    } while ((s32)state_bits >= 0);
    func_08003DF8(10, func_08004034);
    {
        register u8 *tasks asm("r1") = (u8 *)D_02000034;
        register u32 message_offset asm("r5") = 10 * sizeof(struct Task) + 8;
        register u8 *address asm("r2");
        asm("" : : "r"(tasks), "r"(message_offset));
        address = (u8 *)((u32)tasks + message_offset);
        {
            register u32 value asm("r0") = 1;
            asm("" : : "r"(address), "r"(value));
            *(u32 *)address = value;
        }
        {
            register u32 data_offset asm("r0") = 10 * sizeof(struct Task) + 12;
            asm("" : "+r"(data_offset));
            address = (u8 *)((u32)tasks + data_offset);
        }
        {
            register u32 value asm("r0") = 0;
            asm("" : : "r"(address), "r"(value));
            *(u32 *)address = value;
        }
        {
            register u32 busy_offset asm("r2") = 10 * sizeof(struct Task) + 24;
            register u32 *busy asm("r1");
            register u32 ready asm("r0");
            asm("" : "+r"(busy_offset));
            busy = (u32 *)((u32)tasks + busy_offset);
            asm("" : : "r"(busy));
            ready = *busy;
            asm("" : : "r"(ready));
            if (ready != 1)
            {
                register u32 *waiting asm("r4") = busy;
                asm("" : "+r"(waiting));
                do
                    func_0805EE78(1);
                while (*waiting != 1);
            }
        }
    }
    func_08003E3C(10);
    func_08003E3C(7);
    {
        register u8 *tasks asm("r2") = (u8 *)D_02000034;
        register u8 *current asm("r0") = &D_02000030;
        register u32 index asm("r1");
        register u32 offset asm("r0");
        register s32 *destination asm("r0");
        register s32 message asm("r1");
        asm("" : "+r"(tasks) : "r"(current));
        index = *current;
        asm("" : : "r"(index));
        offset = index * sizeof(struct Task);
        asm("" : "+r"(offset) : "r"(tasks));
        tasks += 8;
        asm("" : "+r"(tasks));
        destination = (s32 *)(offset + (u32)tasks);
        asm("" : "+r"(destination), "+r"(exit_bits));
        message = (s32)exit_bits >> 16;
        asm("" : : "r"(message));
        *destination = message;
    }
}
