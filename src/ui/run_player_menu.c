#include "ui/player_menu.h"
#include "ui/player_selection.h"
#include "zoids/stats.h"

union RegisterHalf
{
    u32 word;
    s16 halves[2];
};
register const u8 *menu_stack asm("sp");

#define U8_AT(address) (*(u8 *)(address))
#define U16_AT(address) (*(u16 *)(address))
#define S16_AT(address) (*(s16 *)(address))
#define U32_AT(address) (*(u32 *)(address))
#define S32_AT(address) (*(s32 *)(address))
#define PLAYER8(offset) U8_AT((u8 *)&player_state + (offset))
#define PLAYER32(offset) U32_AT((u8 *)&player_state + (offset))
#define RUN(address, index) script_run_table((const u8 **)(address), (index))
#define RUN_UNCACHED(address, index)                                                               \
    do                                                                                             \
    {                                                                                              \
        register const u8 **table asm("r0");                                                       \
        ((const u8 **volatile)table) = (const u8 **)(address);                                     \
        script_run_table((const u8 **volatile)table, (index));                                     \
    } while (0)
#define LAYOUT(index) script_run_table(menu_layout_scripts, (index))
#define STATUS(index) script_run_table(menu_status_scripts, (index))
#define ACTION U16_AT(0x02007574)
#define REPLY U16_AT(0x02007576)
#define CURSOR U16_AT(0x02007588)

void func_0804E37C(u32);
void func_08001848(s32, u32, u32);
void func_08032818(u32);
void func_08032800(u32);
s32 func_080019EC(u16);
void func_0805EE78(u32);
void func_0804D654(u32, u32, u32);
void func_0804DFB8(u8, s16);
void func_0804E094(u8, s16);
s32 func_08009A2C(void);
void func_080394EC(u32, void *, u32, u32);
extern const u8 equipment_records[];
void func_0804D604(const void *, u32, u32);
s32 func_0804DD28(u32 *, u8);
void func_0804D8AC(u32, s32, u32, u32, u32, u32);
void func_0804E0A8(u8, s16);
void build_equipment_stats(u8, u16, void *);
void func_0804DDB4(void *);
void func_08003DF8(u32, void (*)(void));
void func_08003E3C(u32);
void func_08004034(void);
void func_08044E04(u32, u32);
s32 func_0804D6D4(u32, u32, u32);
void func_0804D85C(void);
void func_08053150(u32, u32, u32, u32);
void func_08037AF0(void);
u8 func_080592F0(void);

void run_player_menu(void)
{
    u8 *saved_selection = (u8 *)0x02007FA9;
    u16 selected[4];
    u16 pages[4];
    u32 dma_fill;
    u32 page;
    u32 previous_page;
    u32 selected_index;
    u32 previous_index;
    u32 selected_zoid;
    u32 previous_zoid;
    u32 equipment_index;
    u32 core_index;
    u32 previous_equipment_index;
    u32 previous_core_index;
    u32 item_index;
    u32 previous_item_index;
    u32 slot_index;
    u32 last_row;
    const u8 *model;
    u8 *chosen_item;
    u8 *recovery_item;
    s32 equipment_zoid;
    u32 *dma_source;
    u32 previous_equipment_shift;
    u32 previous_item_shift;
    u32 slot_shift;
    union
    {
        const u8 *count;
        u32 item;
    } call_scratch;
    register u16 state asm("r4");
    register const u8 **return_table asm("r0");
    register u32 return_index asm("r1");
    u16 return_sound;
    register union RegisterHalf finished_state asm("r5");
    u16 row;
    u16 slot;
    u16 column;
    u32 base;
    u32 value;
    u8 *bonuses;

    asm(""
        : "=m"(dma_fill), "=m"(page), "=m"(previous_page), "=m"(selected_index),
          "=m"(previous_index), "=m"(selected_zoid), "=m"(previous_zoid),
          "=m"(previous_equipment_index));
    asm(""
        : "=m"(previous_core_index), "=m"(item_index), "=m"(previous_item_index), "=m"(slot_index),
          "=m"(last_row), "=m"(model), "=m"(chosen_item), "=m"(recovery_item));
    asm(""
        : "=m"(equipment_zoid), "=m"(dma_source), "=m"(previous_equipment_shift),
          "=m"(previous_item_shift), "=m"(slot_shift), "=m"(call_scratch));

    build_player_pilot_selection();
    build_zoid_core_selection();
    build_construction_part_selection();
    func_0804E37C(5);
    state = 0;
    do
    {
    menu_dispatch:
        switch ((s16)state)
        {
        case 0:
            RUN(0x08675BEC, 1);
            RUN_UNCACHED(0x0875B068, 2);
            RUN_UNCACHED(0x0875B068, 0);
            LAYOUT(0x2A);
            func_08001848(player_state.money, 7, 0);
            RUN_UNCACHED(0x0875B068, 1);
            RUN(0x0875B0B8, 0);
            func_08032818(0);
            RUN(0x0875B0B8, 1);
            U8_AT(U32_AT(0x02009118) + 10) = 15;
            if (PLAYER8(0xCD2) <= 98)
            {
                func_08001848(PLAYER8(0xCD2), 2, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(0x0875B0B8, 2);
                func_08001848(PLAYER32(0xCD4), 7, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(0x0875B0B8, 3);
                func_08001848(get_pilot_bonus_threshold() - PLAYER32(0xCD4), 7, 0);
            }
            else
            {
                func_08001848(99, 2, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(0x0875B0B8, 2);
                func_08001848(0, 7, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(0x0875B0B8, 3);
                func_08001848(0, 7, 0);
            }
            LAYOUT(0x18);
            {
                register u32 tasks asm("r0") = 0x02000034;
                register u32 ready_offset asm("r4") = 0x568;
                register u32 *initial_ready asm("r1");
                asm("" : : "r"(tasks), "r"(ready_offset));
                initial_ready = (u32 *)(tasks + ready_offset);
                asm("" : : "r"(initial_ready));
                if (*initial_ready != 1)
                {
                    u32 *ready = initial_ready;
                    do
                        func_0805EE78(1);
                    while (*ready != 1);
                }
            }
            goto menu_main_state;
        case 1:
        {
            register u8 *party asm("r4");
            register union RegisterHalf level_offset asm("r7");
            RUN_UNCACHED(0x0875B068, 2);
            RUN_UNCACHED(0x0875B068, 0);
            LAYOUT(0x2A);
            ((u8 *volatile)party) = (u8 *)&player_state;
            {
                register u32 money_offset asm("r6");
                money_offset = 0xD28;
                asm("" : : "r"(money_offset));
                {
                    register u32 money_address asm("r0") = (u32)party + money_offset;
                    asm("" : : "r"(money_address));
                    func_08001848(U32_AT(money_address), 7, 0);
                }
            }
            RUN_UNCACHED(0x0875B068, 1);
            RUN(0x0875B0B8, 0);
            func_08032818(0);
            RUN(0x0875B0B8, 1);
            U8_AT(U32_AT(0x02009118) + 10) = 15;
            level_offset.word = 0xCD2;
            {
                register u8 *level_address asm("r1") = party + level_offset.word;
                u32 level;
                asm("" : : "r"(level_address));
                level = *level_address;
                if (level <= 98)
                {
                    func_08001848(level, 2, 0);
                    RUN_UNCACHED(0x08675C5C, 0);
                    RUN(0x0875B0B8, 2);
                    {
                        register u32 bonus_offset asm("r0");
                        bonus_offset = 0xCD4;
                        asm("" : : "r"(bonus_offset));
                        party += bonus_offset;
                    }
                    func_08001848(U32_AT(party), 7, 0);
                    RUN_UNCACHED(0x08675C5C, 0);
                    RUN(0x0875B0B8, 3);
                    func_08001848(get_pilot_bonus_threshold() - U32_AT(party), 7, 0);
                }
                else
                {
                    func_08001848(99, 2, 0);
                    RUN_UNCACHED(0x08675C5C, 0);
                    RUN(0x0875B0B8, 2);
                    func_08001848(0, 7, 0);
                    RUN_UNCACHED(0x08675C5C, 0);
                    RUN(0x0875B0B8, 3);
                    func_08001848(0, 7, 0);
                }
            }
            LAYOUT(0x18);
            {
                register u32 tasks asm("r0") = 0x02000034;
                register u32 ready_offset asm("r2") = 0x568;
                register u32 *initial_ready asm("r1");
                asm("" : : "r"(tasks), "r"(ready_offset));
                initial_ready = (u32 *)(tasks + ready_offset);
                asm("" : : "r"(initial_ready));
                if (*initial_ready != 1)
                {
                    u32 *ready = initial_ready;
                    do
                        func_0805EE78(1);
                    while (*ready != 1);
                }
            }
            {
                register u16 selection asm("r0");
                register u8 *cursor asm("r3");
                ((volatile u16)selection) = selected[0];
                ((u8 *volatile)cursor) = saved_selection;
                asm("" : "+r"(cursor));
                *((u8 *volatile)cursor) = (volatile u16)selection;
            }
        }
        case 2:
        {
            register u16 *action asm("r1");
            RUN(0x0875B068, 3);
            ((u16 *volatile)action) = (u16 *)0x02007574;
            if (*((u16 *volatile)action) == 0)
            {
                func_080019EC(0x3F);
                {
                    register u32 next asm("r4") = 0xFFFF;
                    asm("" : : "r"(next));
                    state = next;
                }
                break;
            }
            if (((u16 *volatile)action)[1] == 1)
            {
                build_recovery_item_selection();
                if (!recovery_selection_count)
                {
                    func_080019EC(0x4F);
                    return_table = (const u8 **)0x0875B068;
                    return_index = 0xC;
                    goto return_main_call;
                }
            }
            {
                register u16 *choices asm("r4") = (u16 *)0x02007574;
                asm("" : : "r"(choices));
                if (choices[1] != 3)
                    RUN_UNCACHED(menu_layout_scripts, 0);
                selected[0] = choices[1];
                {
                    register u32 shifted asm("r0") = (u32)choices[1] << 28;
                    register u32 addition asm("r4") = 0x10000000;
                    asm("" : : "r"(shifted), "r"(addition));
                    state = (shifted + addition) >> 16;
                }
            }
            break;
        }
        case 0x1000:
            RUN(0x0875B068, 4);
            {
                register u32 next asm("r4") = 0x1002;
                asm("" : : "r"(next));
                state = next;
            }
            break;
        case 0x1001:
            RUN(0x0875B068, 4);
            {
                register u16 selection asm("r0");
                register u8 *cursor asm("r6");
                ((volatile u16)selection) = selected[1];
                ((u8 *volatile)cursor) = (u8 *)0x020082FD;
                *((u8 *volatile)cursor) = (volatile u16)selection;
            }
        case 0x1002:
        {
            register u16 *action asm("r1");
            u32 choice;
            RUN(0x0875B068, 5);
            ((u16 *volatile)action) = (u16 *)0x02007574;
            if (*((u16 *volatile)action) == 0)
            {
                RUN_UNCACHED(menu_layout_scripts, 0xC);
                RUN_UNCACHED(menu_layout_scripts, 0);
                func_080019EC(0x3F);
                {
                    register u16 selection asm("r0") = selected[0];
                    asm("" : : "r"(selection));
                    {
                        register u32 held1 asm("r1");
                        register u32 held2 asm("r2");
                        register u32 held3 asm("r3");
                        register u32 held4 asm("r4");
                        register u32 held5 asm("r5");
                        register u32 held6 asm("r6");
                        u8 *cursor;
                        asm(""
                            : "=r"(held1), "=r"(held2), "=r"(held3), "=r"(held4), "=r"(held5),
                              "=r"(held6));
                        cursor = saved_selection;
                        *cursor = selection;
                        asm(""
                            :
                            : "r"(held1), "r"(held2), "r"(held3), "r"(held4), "r"(held5),
                              "r"(held6));
                    }
                }
                goto menu_main_state;
            }
            choice = ((u16 *volatile)action)[1];
            if (choice == 2)
            {
                build_player_equipment_selection(15);
                if (!equipment_selection_count)
                {
                    func_080019EC(0x4F);
                    return_table = (const u8 **)0x0875B068;
                    return_index = 0xD;
                    goto return_submenu_call;
                }
            }
            else if (choice == 3)
            {
                if (!core_selection_count)
                {
                    func_080019EC(0x4F);
                    return_table = (const u8 **)0x0875B068;
                    return_index = 0xE;
                    goto return_submenu_call;
                }
            }
            else if (choice == 4)
            {
                if (!part_selection_count)
                {
                    func_080019EC(0x4F);
                    return_table = (const u8 **)0x0875B068;
                    return_index = 0x10;
                return_submenu_call:
                    ((int (*)(const u8 **, u32))script_run_table)(return_table, return_index);
                    func_080019EC(0x41);
                    {
                        register u32 next asm("r4") = 0x1002;
                        asm("" : : "r"(next));
                        state = next;
                    }
                    break;
                }
            }
            {
                register u16 *choices asm("r4") = (u16 *)0x02007574;
                asm("" : : "r"(choices));
                if (choices[1] <= 4)
                {
                    RUN_UNCACHED(menu_layout_scripts, 0xC);
                    RUN_UNCACHED(menu_layout_scripts, 0xB);
                    RUN_UNCACHED(menu_layout_scripts, 0xA);
                    RUN_UNCACHED(menu_layout_scripts, 9);
                }
                RUN_UNCACHED(menu_layout_scripts, 0);
                selected[1] = choices[1];
                {
                    register u32 shifted asm("r0") = (u32)choices[1] << 24;
                    register u32 addition asm("r1") = 0x11000000;
                    asm("" : : "r"(shifted), "r"(addition));
                    state = (shifted + addition) >> 16;
                }
            }
            break;
        }
        case 0x1100:
        {
            register u32 party asm("r7");
            register const u8 **status asm("r8");
            register u32 ep_base asm("r9");
            register u32 line asm("r6");
            register u32 line_shift asm("r5");
            RUN(0x0875B0C8, 0);
            line = 0;
            party = (u32)&player_state;
            asm("" : : "r"(line), "r"(party));
            {
                register const u8 **initial_status asm("r2") = menu_status_scripts;
                asm("" : : "r"(initial_status));
                ((const u8 **volatile)status) = initial_status;
            }
            {
                register u32 offset asm("r3") = 0xD58;
                asm("" : : "r"(offset));
                ((volatile u32)ep_base) = offset + party;
            }
        overview_line:
        {
            register u32 shifted asm("r0") = line << 16;
            register s32 scaled asm("r1") = (s32)shifted >> 14;
            register u32 entry_base asm("r2") = scaled + party;
            register u32 teams_offset asm("r6") = 0x3600;
            register u8 *entry asm("r4");
            register u32 occupied asm("r1");
            asm("" : : "r"(teams_offset), "r"(entry_base), "r"(shifted));
            entry = (u8 *)(entry_base + teams_offset);
            occupied = *entry;
            line_shift = shifted;
            if (occupied != 255)
            {
                {
                    register u32 pilot_offset asm("r1") = 0x3601;
                    register u32 pilot_address asm("r0");
                    asm("" : : "r"(pilot_offset));
                    ((volatile u32)pilot_address) = entry_base + pilot_offset;
                    func_08032818(U8_AT((volatile u32)pilot_address));
                }
                U8_AT(U32_AT(0x02009118) + 10) = 11;
                {
                    register u32 unit asm("r1") = *entry;
                    register u32 shifted_unit asm("r0") = unit * 56;
                    register u32 offset asm("r2") = 0xD2C;
                    register u32 address asm("r1");
                    asm("" : : "r"(unit), "r"(shifted_unit), "r"(offset));
                    ((volatile u32)address) = party + offset;
                    render_player_zoid_hp((PlayerZoid *)(shifted_unit + (volatile u32)address));
                }
                script_run_table((const u8 **volatile)status, 6);
                {
                    register u32 unit asm("r1") = *entry;
                    register u32 shifted_unit asm("r0") = unit * 56;
                    register u32 offset asm("r3") = 0xD54;
                    register u32 address asm("r1");
                    asm("" : : "r"(unit), "r"(shifted_unit), "r"(offset));
                    ((volatile u32)address) = party + offset;
                    func_08001848(U32_AT(shifted_unit + (volatile u32)address), 4, 0);
                }
                RUN_UNCACHED(menu_layout_scripts, 0x2A);
                {
                    register u32 unit asm("r1") = *entry;
                    register u32 shifted_unit asm("r0") = unit * 56;
                    register u32 offset asm("r6") = 0xD38;
                    register u32 address asm("r1");
                    asm("" : : "r"(unit), "r"(shifted_unit), "r"(offset));
                    ((volatile u32)address) = party + offset;
                    func_08001848(U32_AT(shifted_unit + (volatile u32)address), 3, 0);
                }
                script_run_table((const u8 **volatile)status, 6);
                {
                    register u32 unit asm("r1") = *entry;
                    register u32 shifted_unit asm("r0") = unit * 56;
                    asm("" : : "r"(unit), "r"(shifted_unit));
                    func_08001848(U32_AT(shifted_unit + (volatile u32)ep_base), 3, 0);
                }
                RUN_UNCACHED(0x08675C5C, 0);
            }
            else
                RUN(0x0875B0C8, 1);
        }
            {
                register u32 increment asm("r1") = 0x10000;
                register u32 next asm("r0");
                asm("" : : "r"(increment));
                next = line_shift + increment;
                line = next >> 16;
                if ((s32)next >> 16 <= 5)
                    goto overview_line;
            }
            RUN_UNCACHED(menu_layout_scripts, 0x18);
            RUN_UNCACHED(menu_layout_scripts, 0x25);
            func_080019EC(0x41);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
        menu_inventory_return:
        {
            register u32 next asm("r4") = 0x1FFF;
            asm("" : : "r"(next));
            state = next;
        }
        break;
        }
        case 0x1200:
        {
            register u32 zero asm("r2");
            register u16 *cursor asm("r3");
            register u32 next asm("r4");
            RUN(0x0875B0D0, 0);
            ((volatile u32)zero) = 0;
            page = (volatile u32)zero;
            ((u16 *volatile)cursor) = (u16 *)0x02007588;
            *(u16 *volatile)cursor = zero;
            next = 0x1202;
            asm("" : : "r"(next));
            state = next;
            break;
        }
        case 0x1201:
        {
            register u16 selection asm("r0");
            register u8 *cursor_byte asm("r4");
            register u16 *cursor asm("r6");
            RUN(0x0875B0D0, 0);
            page = pages[2];
            ((volatile u16)selection) = selected[2];
            ((u8 *volatile)cursor_byte) = saved_selection;
            asm("" : "+r"(cursor_byte));
            *(u8 *volatile)cursor_byte = (volatile u16)selection;
            ((volatile u16)selection) = (u8)(volatile u16)selection;
            ((u16 *volatile)cursor) = (u16 *)0x02007588;
            *(u16 *volatile)cursor = (volatile u16)selection;
        }
        case 0x1202:
        {
            register const u8 **layout asm("r9");
            register u16 pilot_row asm("r6");
            {
                register u32 invalid asm("r7") = 0xFFFF;
                register u32 invalid_zoid asm("r0");
                asm("" : : "r"(invalid));
                previous_index = invalid;
                previous_page = invalid;
                ((volatile u32)invalid_zoid) = invalid;
                asm("" : : "r"(invalid_zoid));
                previous_zoid = (volatile u32)invalid_zoid;
            }
            {
                register const u8 **initial_layout asm("r1");
                ((const u8 **volatile)initial_layout) = menu_layout_scripts;
                asm("" : : "r"(initial_layout));
                layout = initial_layout;
            }
        pilot_refresh:
        {
            register union RegisterHalf page_copy asm("r7");
            register union RegisterHalf previous_copy asm("r10");
            register u32 page_load asm("r2") = page;
            register u32 page_shift asm("r1") = page_load << 16;
            register s32 current_page asm("r4") = (s32)page_shift >> 16;
            register u32 prior_page_load asm("r3") = previous_page;
            register s32 prior_page asm("r0") = (s16)prior_page_load;
            asm(""
                :
                : "r"(page_load), "r"(page_shift), "r"(current_page), "r"(prior_page_load),
                  "r"(prior_page));
            page_copy.word = page_shift;
            asm("" : "+r"(page_copy.word));
            {
                register u32 prior_index asm("r6");
                ((volatile u32)prior_index) = previous_index;
                asm("" : : "r"(prior_index));
                ((volatile u32)prior_index) <<= 16;
                asm("" : : "r"(prior_index));
                previous_copy.word = prior_index;
            }
            if (current_page != prior_page)
            {
                register u32 page_rows asm("r8");
                register u32 row_start asm("r2");
                register const u8 *count asm("r5");
                register const u8 *limit asm("r4");
                if (prior_page != -1)
                    RUN_UNCACHED(menu_layout_scripts, 3);
                pilot_row = 0;
                {
                    register u32 scaled_page asm("r0") = current_page * 3;
                    register u32 narrow_row asm("r3");
                    register const u8 *count_address asm("r1");
                    row_start = scaled_page << 1;
                    asm("" : : "r"(row_start));
                    scaled_page <<= 17;
                    narrow_row = scaled_page >> 16;
                    asm("" : : "r"(narrow_row));
                    last_row = narrow_row;
                    ((volatile u32)scaled_page) = (s32)scaled_page >> 16;
                    ((const u8 *volatile)count_address) = &pilot_selection_count;
                    asm("" : : "r"(count_address));
                    limit = count_address;
                    asm("" : : "r"(limit));
                    {
                        register s32 count_value asm("r1") = *limit;
                        asm("" : : "r"(count_value));
                        if ((s32)scaled_page >= count_value)
                            goto pilot_rows_done;
                    }
                    count = limit;
                }
                page_rows = row_start;
            pilot_row_refresh:
            {
                register const u8 *names asm("r1") = pilot_selection_ids;
                register u32 row_load asm("r2") = last_row;
                register u32 row_shift asm("r0") = row_load << 16;
                register s32 row_index asm("r4") = (s32)row_shift >> 16;
                asm("" : : "r"(names), "r"(row_load), "r"(row_shift), "r"(row_index));
                func_08032818(U8_AT(row_index + (u32)names));
                if ((s16)pilot_row <= 4 && row_index < *(const u8 *volatile)count - 1)
                    RUN_UNCACHED(0x08675C5C, 0);
            }
                {
                    register u32 shifted asm("r0") = (u32)pilot_row << 16;
                    register u32 increment asm("r3") = 0x10000;
                    asm("" : : "r"(shifted), "r"(increment));
                    shifted += increment;
                    pilot_row = shifted >> 16;
                    ((volatile u32)shifted) = (s32)shifted >> 16;
                    ((const u8 *volatile)limit) = &pilot_selection_count;
                    if ((s32)shifted > 5)
                        goto pilot_rows_done;
                    shifted += page_rows;
                    shifted <<= 16;
                    {
                        register u32 narrow_row asm("r1") = shifted >> 16;
                        asm("" : : "r"(narrow_row));
                        last_row = narrow_row;
                    }
                    ((volatile u32)shifted) = (s32)shifted >> 16;
                    {
                        register s32 count_value asm("r2") = *(const u8 *volatile)count;
                        asm("" : : "r"(count_value));
                        if ((s32)shifted < count_value)
                            goto pilot_row_refresh;
                    }
                }
            pilot_rows_done:
            {
                register u32 row_shift asm("r0") = (u32)pilot_row << 16;
                register u16 *cursor asm("r2");
                register u8 *windows asm("r3");
                register s32 cursor_value asm("r1");
                register u8 *flags asm("r2");
                register u32 zero asm("r3");
                ((volatile u32)row_shift) = (s32)row_shift >> 16;
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                ((u8 *volatile)windows) = (u8 *)text_windows;
                asm("" : : "r"(row_shift), "r"(cursor), "r"(windows));
                cursor_value = *(u16 *volatile)cursor;
                asm("" : : "r"(cursor_value));
                if ((s32)row_shift <= cursor_value)
                {
                    register u16 clamped asm("r0") = pilot_row - 1;
                    register u8 *cursor_byte asm("r6");
                    ((u8 *volatile)cursor_byte) = saved_selection;
                    asm("" : : "r"(cursor_byte));
                    *(u8 *volatile)cursor_byte = clamped;
                    ((volatile u16)clamped) = (u8)(volatile u16)clamped;
                    *(u16 *volatile)cursor = (volatile u16)clamped;
                }
                {
                    register u32 offset asm("r0") = 0xA0B;
                    asm("" : : "r"(offset));
                    flags = windows + offset;
                }
                {
                    register u8 stored_zero asm("r0");
                    zero = 0;
                    asm("" : : "r"(zero));
                    ((volatile u8)stored_zero) = 0;
                    *(volatile u8 *)flags = (volatile u8)stored_zero;
                }
                if ((s32)page_copy.word > 0)
                    *(volatile u8 *)flags = 1;
                {
                    register u32 row_load asm("r6") = last_row;
                    register s32 signed_row asm("r1") = (s16)row_load;
                    asm("" : : "r"(row_load), "r"(signed_row));
                    if (signed_row < *(const u8 *volatile)limit - 1)
                        *(volatile u8 *)flags |= 2;
                }
            }
                asm("" : "+r"(page_copy.word));
                {
                    register u32 saved_page asm("r0") = page_copy.word >> 16;
                    asm("" : : "r"(saved_page));
                    previous_page = saved_page;
                }
            }
            {
                register s32 selected_signed asm("r4");
                register s32 prior_selected asm("r0");
                {
                    register s32 current_page asm("r1") = page_copy.halves[1];
                    register u32 page_rows asm("r0") = current_page * 6;
                    register u32 shifted_index asm("r0");
                    register u32 narrowed_index asm("r2");
                    asm("" : : "r"(page_rows));
                    {
                        register u32 cursor_value asm("r1");
                        ((volatile u32)cursor_value) = (u32)&CURSOR;
                        ((volatile u32)cursor_value) = U16_AT((volatile u32)cursor_value);
                        ((volatile u32)shifted_index) = (page_rows + (volatile u32)cursor_value)
                                                        << 16;
                    }
                    narrowed_index = (volatile u32)shifted_index >> 16;
                    asm("" : : "r"(narrowed_index));
                    selected_index = narrowed_index;
                    selected_signed = (s32)(volatile u32)shifted_index >> 16;
                    asm("" : : "r"(selected_signed));
                }
                {
                    register u32 prior_shift asm("r3") = previous_copy.word;
                    asm("" : : "r"(prior_shift));
                    ((volatile s32)prior_selected) = (s32)prior_shift >> 16;
                }
                if (selected_signed != (volatile s32)prior_selected)
                {
                    register union RegisterHalf invalid_shift asm("r6");
                    register s32 invalid_selected asm("r5");
                    register u32 selected_slot asm("r4");
                    register u8 *party asm("r6");
                    ((volatile u32)invalid_shift.word) = 0xFFFF0000;
                    asm("" : "+r"(invalid_shift.word));
                    invalid_selected = (s32)(volatile u32)invalid_shift.word >> 16;
                    asm("" : : "r"(invalid_selected));
                    if ((volatile s32)prior_selected != invalid_selected)
                    {
                        script_run_table((const u8 **volatile)layout, 1);
                        script_run_table((const u8 **volatile)layout, 2);
                    }
                    {
                        register u32 address asm("r0");
                        register u32 pilot_offset asm("r7");
                        ((u8 *volatile)party) = (u8 *)&player_state;
                        ((volatile u32)address) = (u32)pilot_selection_ids;
                        ((volatile u32)address) = selected_signed + (volatile u32)address;
                        ((volatile u32)address) = U8_AT((volatile u32)address);
                        ((volatile u32)address) <<= 2;
                        ((volatile u32)address) += (u32)(u8 *volatile)party;
                        ((volatile u32)pilot_offset) = 0x34A6;
                        ((volatile u32)address) += (volatile u32)pilot_offset;
                        ((volatile u32)address) = U8_AT((volatile u32)address);
                        selected_zoid = (volatile u32)address;
                        ((volatile u32)selected_slot) = (volatile u32)address;
                    }
                    if ((volatile u32)selected_slot != 255)
                    {
                        register u32 prior_slot_load asm("r1") = previous_zoid;
                        register s32 prior_slot asm("r0") = (s16)prior_slot_load;
                        asm("" : : "r"(prior_slot_load), "r"(prior_slot));
                        if (prior_slot == invalid_selected ||
                            prior_slot != (volatile u32)selected_slot)
                        {
                            script_run_table((const u8 **volatile)layout, 0);
                            script_run_table((const u8 **volatile)layout, 0x19);
                            RUN_UNCACHED(0x0875B0D0, 6);
                            {
                                register u32 name_address asm("r0");
                                register u32 name_offset asm("r2");
                                ((volatile u32)name_address) = (volatile u32)selected_slot * 56;
                                ((volatile u32)name_address) += (u32)(u8 *volatile)party;
                                name_offset = 0xD32;
                                asm("" : "+r"(name_offset));
                                ((volatile u32)name_address) += name_offset;
                                ((volatile u32)name_address) = U8_AT((volatile u32)name_address);
                                func_08032800((volatile u32)name_address);
                            }
                            RUN_UNCACHED(0x0875B0D0, 7);
                        }
                    }
                    else
                    {
                        register u32 prior_zoid asm("r3");
                        register s32 prior_signed asm("r0");
                        prior_zoid = previous_zoid;
                        asm("" : "+r"(prior_zoid));
                        prior_signed = (s16)prior_zoid;
                        asm("" : "+r"(prior_signed));
                        if (prior_signed != 255)
                        {
                            script_run_table((const u8 **volatile)layout, 0);
                            script_run_table((const u8 **volatile)layout, 0x19);
                            RUN_UNCACHED(0x0875B0D0, 8);
                        }
                    }
                    {
                        register u8 *pilot_address asm("r5");
                        register u32 selected_shift asm("r6");
                        register u8 *pilot_bonuses asm("r4");
                        {
                            register u32 names asm("r0");
                            register u32 selected_load asm("r4");
                            names = (u32)pilot_selection_ids;
                            selected_load = selected_index;
                            asm("" : : "r"(selected_load));
                            selected_shift = selected_load << 16;
                            ((u8 *volatile)pilot_address) = (u8 *)((s32)selected_shift >> 16);
                            ((u8 *volatile)pilot_address) += names;
                            pilot_bonuses = (u8 *)get_pilot_bonuses(*(u8 *volatile)pilot_address);
                        }
                        script_run_table((const u8 **volatile)layout, 0x1A);
                        func_08032818(*(u8 *volatile)pilot_address);
                        RUN_UNCACHED(0x08675C5C, 0);
                        RUN_UNCACHED(0x0875B0D0, 1);
                        {
                            register u32 held1 asm("r1");
                            register u32 held2 asm("r2");
                            register u32 held3 asm("r3");
                            register s32 bonus asm("r0");
                            asm("" : "=r"(held1), "=r"(held2), "=r"(held3));
                            bonus = S16_AT(pilot_bonuses + 4);
                            asm("" : : "r"(held1), "r"(held2), "r"(held3), "r"(bonus));
                            func_08001848(bonus, 3, 4);
                        }
                        script_run_table((const u8 **volatile)layout, 0x27);
                        RUN_UNCACHED(0x08675C5C, 0);
                        RUN_UNCACHED(0x0875B0D0, 2);
                        func_08001848(S16_AT(pilot_bonuses + 10), 3, 4);
                        script_run_table((const u8 **volatile)layout, 0x27);
                        RUN_UNCACHED(0x08675C5C, 0);
                        RUN_UNCACHED(0x0875B0D0, 3);
                        func_08001848(S16_AT(pilot_bonuses + 8), 3, 4);
                        script_run_table((const u8 **volatile)layout, 0x27);
                        RUN_UNCACHED(0x08675C5C, 0);
                        RUN_UNCACHED(0x0875B0D0, 4);
                        func_08001848(S16_AT(pilot_bonuses + 6), 3, 4);
                        script_run_table((const u8 **volatile)layout, 0x27);
                        RUN_UNCACHED(0x08675C5C, 0);
                        RUN_UNCACHED(0x0875B0D0, 5);
                        func_08001848(S16_AT(pilot_bonuses + 12), 3, 4);
                        script_run_table((const u8 **volatile)layout, 0x27);
                        RUN(0x0875B4F0, *(u8 *volatile)pilot_address);
                        script_run_table((const u8 **volatile)layout, 0x18);
                        script_run_table((const u8 **volatile)layout, 0x1C);
                        {
                            register u32 completed_unit asm("r1");
                            register u32 completed_half asm("r0");
                            ((volatile u32)completed_unit) = selected_zoid;
                            asm("" : "+r"(completed_unit));
                            completed_half = (u16)(volatile u32)completed_unit;
                            asm("" : : "r"(completed_half));
                            previous_zoid = completed_half;
                        }
                        ((volatile u32)selected_shift) >>= 16;
                        previous_index = (volatile u32)selected_shift;
                    }
                }
            }
            {
                register u16 *input asm("r1");
                register u32 action asm("r0");
                register u32 next_page asm("r0");
                RUN_UNCACHED(menu_layout_scripts, 0x23);
                ((u16 *volatile)input) = (u16 *)0x02007574;
                ((volatile u32)action) = *(u16 *volatile)input;
                if ((volatile u32)action <= 1)
                    goto pilot_selection_done;
                if ((volatile u32)action == 2)
                    goto pilot_page_left;
                if ((volatile u32)action == 4)
                    goto pilot_page_right;
                goto pilot_refresh;
            pilot_page_left:
            {
                register u32 page_load asm("r2") = page;
                register u32 page_shift asm("r0") = page_load << 16;
                register s32 current_page asm("r4") = (s32)page_shift >> 16;
                asm("" : : "r"(page_load), "r"(page_shift), "r"(current_page));
                if (current_page <= 0)
                    goto pilot_refresh;
                func_080019EC(0x40);
                ((volatile u32)next_page) = (current_page - 1) << 16;
                goto pilot_page_save;
            }
            pilot_page_right:
            {
                register u32 last_row_load asm("r3") = last_row;
                register s32 last_row_signed asm("r1") = (s16)last_row_load;
                asm("" : : "r"(last_row_load), "r"(last_row_signed));
                if (last_row_signed >= pilot_selection_count - 1)
                    goto pilot_refresh;
                func_080019EC(0x40);
                {
                    register u32 page_load asm("r4") = page;
                    register u32 increment asm("r6");
                    asm("" : : "r"(page_load));
                    ((volatile u32)next_page) = page_load << 16;
                    increment = 0x10000;
                    asm("" : "+r"(increment));
                    ((volatile u32)next_page) += increment;
                }
            }
            pilot_page_save:
                page = (volatile u32)next_page >> 16;
            }
        }
            goto pilot_refresh;
        pilot_selection_done:
        {
            register u16 *choice asm("r1") = (u16 *)0x02007574;
            asm("" : "+r"(choice));
            if (*(u16 *volatile)choice == 1)
            {
                register union
                {
                    unsigned long long whole;
                    struct
                    {
                        u32 low, high;
                    } part;
                } selected_load asm("r6");
                register s32 selected_signed asm("r0");
                selected_load.part.high = selected_zoid;
                selected_signed = (s16)selected_load.part.high;
                asm("" : : "r"(selected_load.part.high), "r"(selected_signed));
                {
                    register u32 next asm("r4") = 0x1FFF;
                    asm("" : : "r"(next));
                    state = next;
                }
                if (selected_signed != 255)
                {
                    register u32 next asm("r4") = 0x1210;
                    asm("" : : "r"(next));
                    state = next;
                    {
                        register u16 *selection_values asm("r0") = selected;
                        register u16 selection_value asm("r1") = choice[1];
                        asm("" : : "r"(selection_values), "r"(selection_value));
                        selection_values[2] = selection_value;
                    }
                    {
                        register u16 *page_values asm("r0") = pages;
                        register const u16 *page_source asm("r1") = (const u16 *)menu_stack;
                        register u16 page_value asm("r1");
                        asm("" : : "r"(page_values), "r"(page_source));
                        page_value = page_source[14];
                        asm("" : : "r"(page_value));
                        page_values[2] = page_value;
                    }
                }
            }
            else
            {
                register u32 next asm("r4");
                func_080019EC(0x3F);
                next = 0x1FFF;
                asm("" : : "r"(next));
                state = next;
            }
        }
            RUN_UNCACHED(menu_layout_scripts, 0xB);
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            ((const u8 **volatile)return_table) = menu_layout_scripts;
            goto close_primary_window;
        }
        case 0x1210:
        {
            register const u8 **status asm("r6") = menu_status_scripts;
            register u8 *party asm("r5");
            register u32 zoid_offset asm("r4");
            register u32 zoid asm("r8");
            register u32 zoid_id asm("r9");
            script_run_table(status, 0);
            RUN_UNCACHED(menu_layout_scripts, 0x1A);
            ((u8 *volatile)party) = (u8 *)&player_state;
            {
                register u32 selected_load asm("r2") = selected_zoid;
                register s32 selected_signed asm("r0") = (s16)selected_load;
                register u32 address asm("r3");
                asm("" : : "r"(selected_load), "r"(selected_signed));
                zoid_offset = selected_signed * 56;
                ((volatile u32)address) = zoid_offset + (u32)(u8 *volatile)party;
                asm("" : : "r"(address));
                zoid = address;
            }
            {
                register u32 address asm("r0");
                ((volatile u32)address) = 0xD32;
                ((volatile u32)address) += (volatile u32)zoid;
                zoid_id = (volatile u32)address;
                func_08032800(U8_AT((volatile u32)address));
            }
            script_run_table(status, U8_AT(zoid + 0xD61) + 8);
            RUN_UNCACHED(0x08675C5C, 0);
            script_run_table(status, 1);
            {
                register u32 field asm("r1");
                register u32 address asm("r0");
                ((volatile u32)field) = 0xD2C;
                ((volatile u32)address) = (u32)(u8 *volatile)party + (volatile u32)field;
                ((volatile u32)address) = zoid_offset + (volatile u32)address;
                render_player_zoid_hp((PlayerZoid *)(volatile u32)address);
            }
            script_run_table(status, 6);
            {
                register u32 field asm("r2");
                register u32 address asm("r0");
                ((volatile u32)field) = 0xD54;
                ((volatile u32)address) = (u32)(u8 *volatile)party + (volatile u32)field;
                ((volatile u32)address) = zoid_offset + (volatile u32)address;
                func_08001848(U32_AT((volatile u32)address), 4, 0);
            }
            RUN_UNCACHED(0x08675C5C, 0);
            script_run_table(status, 2);
            {
                register u32 field asm("r3");
                register u32 address asm("r0");
                ((volatile u32)field) = 0xD38;
                ((volatile u32)address) = (u32)(u8 *volatile)party + (volatile u32)field;
                ((volatile u32)address) = zoid_offset + (volatile u32)address;
                func_08001848(U32_AT((volatile u32)address), 4, 0);
            }
            script_run_table(status, 6);
            {
                register u32 field asm("r0");
                ((volatile u32)field) = 0xD58;
                ((u8 *volatile)party) += (volatile u32)field;
                ((volatile u32)zoid_offset) += (u32)(u8 *volatile)party;
                func_08001848(U32_AT((volatile u32)zoid_offset), 4, 0);
            }
            RUN_UNCACHED(0x08675C5C, 0);
            script_run_table(status, 3);
            func_08001848(S16_AT(zoid + 0xD5C), 4, 0);
            RUN_UNCACHED(0x08675C5C, 0);
            script_run_table(status, 4);
            func_08001848(S16_AT(zoid + 0xD5E), 3, 0);
            RUN_UNCACHED(menu_layout_scripts, 0x27);
            RUN_UNCACHED(0x08675C5C, 0);
            script_run_table(status, 5);
            {
                register u32 field asm("r3");
                register u8 *address asm("r4");
                field = 0xD60;
                ((volatile u32)zoid) += field;
                asm("" : : "r"(zoid));
                ((u8 *volatile)address) = (u8 *)(volatile u32)zoid;
                func_08001848(*(u8 *volatile)address, 3, 0);
            }
            {
                register u16 *address asm("r6");
                ((u16 *volatile)address) = (u16 *)(volatile u32)zoid_id;
                func_0804D654(*(u16 *volatile)address, 0x28, 0x58);
            }
            RUN_UNCACHED(menu_layout_scripts, 0x18);
            RUN_UNCACHED(menu_layout_scripts, 0x25);
            if (ACTION == 1)
                state = 0x1220;
            else
            {
                func_080019EC(0x3F);
                {
                    register u32 next_state asm("r4");
                    next_state = 0x1201;
                    state = next_state;
                }
            }
            {
                register u32 address asm("r0");
                register u32 flags asm("r1");
                register u32 mask asm("r7");
                register u32 mask_copy asm("r2");
                ((volatile u32)address) = 0x03004BBC;
                asm("" : : "r"(address));
                ((volatile u32)address) += 0x88;
                ((volatile u32)flags) = U16_AT((volatile u32)address);
                ((volatile u32)mask) = 0x7FFF;
                asm("" : "+r"(mask));
                ((volatile u32)mask_copy) = mask;
                asm("" : : "r"(mask_copy));
                ((volatile u32)flags) &= (volatile u32)mask_copy;
                U16_AT((volatile u32)address) = (volatile u32)flags;
            }
            {
                register const u8 **table asm("r0");
                register int result asm("r0");
                ((const u8 **volatile)table) = menu_layout_scripts;
                result = script_run_table((const u8 **volatile)table, 9);
                asm("" : : "r"(result));
            }
            RUN_UNCACHED(menu_layout_scripts, 0);
            break;
        }
        case 0x1220:
        {
            register const u8 **layout asm("r5");
            RUN(0x0875B124, 0xA);
            RUN(0x0875B124, 0);
            {
                register u32 names asm("r1");
                register u32 selected_load asm("r2");
                register u32 address asm("r0");
                ((volatile u32)names) = (u32)pilot_selection_ids;
                asm("" : : "r"(names));
                ((volatile u32)selected_load) = selected_index;
                asm("" : : "r"(selected_load));
                ((volatile u32)address) = selected_load << 16;
                ((volatile u32)address) = (s32)(volatile u32)address >> 16;
                ((volatile u32)address) += names;
                func_0804DFB8(U8_AT((volatile u32)address), 0);
            }
            ((const u8 **volatile)layout) = menu_layout_scripts;
            script_run_table((const u8 **volatile)layout, 0x18);
            script_run_table((const u8 **volatile)layout, 0x25);
            if (ACTION == 1)
            {
                register u32 next_state asm("r4") = 0x1230;
                asm("" : : "r"(next_state));
                state = next_state;
                break;
            }
            func_080019EC(0x3F);
            {
                register u32 next_state asm("r4") = 0x1201;
                asm("" : : "r"(next_state));
                state = next_state;
            }
            {
                register int result asm("r0");
                result = script_run_table((const u8 **volatile)layout, 9);
                asm("" : : "r"(result));
            }
            script_run_table((const u8 **volatile)layout, 0);
            break;
        }
        case 0x1230:
        {
            register const u8 **layout asm("r5");
            RUN(0x0875B124, 1);
            {
                register u32 names asm("r1");
                register u32 selected_load asm("r3");
                register u32 address asm("r0");
                ((volatile u32)names) = (u32)pilot_selection_ids;
                asm("" : : "r"(names));
                ((volatile u32)selected_load) = selected_index;
                asm("" : : "r"(selected_load));
                ((volatile u32)address) = selected_load << 16;
                ((volatile u32)address) = (s32)(volatile u32)address >> 16;
                ((volatile u32)address) += names;
                func_0804DFB8(U8_AT((volatile u32)address), 1);
            }
            ((const u8 **volatile)layout) = menu_layout_scripts;
            script_run_table((const u8 **volatile)layout, 0x12);
            script_run_table((const u8 **volatile)layout, 0x25);
            if (ACTION == 1)
            {
                register u32 next_state asm("r4");
                next_state = 0x1240;
                state = next_state;
                break;
            }
            func_080019EC(0x3F);
            {
                register u32 next_state asm("r4") = 0x1201;
                asm("" : : "r"(next_state));
                state = next_state;
            }
            script_run_table((const u8 **volatile)layout, 0xA);
            {
                register int result asm("r0");
                result = script_run_table((const u8 **volatile)layout, 9);
                asm("" : : "r"(result));
            }
            script_run_table((const u8 **volatile)layout, 0);
            break;
        }
        case 0x1240:
        {
            register u32 clear_row asm("r6");
            register union RegisterHalf selected_copy asm("r9");
            register u8 *count asm("r8");
            register u8 *tiles asm("r10");
            register u8 *lookup asm("r12");
            u32 mask;
            register const u8 **layout asm("r5");
            {
                register u8 *windows asm("r3");
                register u32 selected_load asm("r4");
                row = 0;
                clear_row = row;
                asm("" : "+r"(clear_row));
                ((u8 *volatile)windows) = (u8 *)text_windows;
                ((volatile u32)selected_load) = selected_index;
                asm("" : : "r"(selected_load));
                ((volatile u32)selected_load) <<= 16;
                asm("" : : "r"(windows), "r"(selected_load));
                selected_copy.word = selected_load;
                mask = 0x020078F9;
                asm("" : "+l"(mask));
                mask = U8_AT(mask);
                if ((s32)clear_row >= (s32)mask)
                    goto pilot_clear_first_done;
                {
                    register u8 *initial_lookup asm("r0");
                    register u32 count_address asm("r1");
                    register u32 tiles_address asm("r2");
                    ((u8 *volatile)initial_lookup) = (u8 *)0x0200904B;
                    asm("" : : "r"(initial_lookup));
                    lookup = initial_lookup;
                    ((volatile u32)count_address) = 0x359;
                    asm("" : : "r"(count_address));
                    ((volatile u32)count_address) += (u32)(u8 *volatile)windows;
                    asm("" : : "r"(count_address));
                    count = (u8 *)count_address;
                    ((volatile u32)tiles_address) = 0x368;
                    asm("" : : "r"(tiles_address));
                    ((volatile u32)tiles_address) += (u32)(u8 *volatile)windows;
                    asm("" : : "r"(tiles_address));
                    tiles = (u8 *)tiles_address;
                    mask = 255;
                    asm("" : "+r"(mask));
                }
            }
        pilot_clear_first_row:
        {
            register u32 row_shift asm("r5");
            register s32 row_signed asm("r4");
            {
                register u32 first_column asm("r3") = 1;
                asm("" : : "r"(first_column));
                last_row = first_column;
            }
            row = (u16)clear_row;
            row_shift = (u32)row << 16;
            row_signed = (s32)row_shift >> 16;
        pilot_clear_first_column:
        {
            register u32 column_load asm("r6") = last_row;
            register s32 column_signed asm("r2") = (s16)column_load;
            register u32 address asm("r1");
            register u32 tile asm("r0");
            register u8 *lookup_copy asm("r6");
            register u8 *flags_address asm("r3");
            asm("" : : "r"(column_load), "r"(column_signed));
            ((volatile u32)address) = (u32)(u8 *volatile)count;
            tile = U8_AT((volatile u32)address);
            ((volatile u32)address) = column_signed;
            asm("" : : "r"(address));
            ((volatile u32)address) *= tile;
            ((volatile u32)address) = row_signed + (volatile u32)address;
            ((volatile u32)address) += (u32)(u8 *volatile)tiles;
            ((volatile u32)tile) = U8_AT((volatile u32)address);
            ((u8 *volatile)lookup_copy) = (u8 *volatile)lookup;
            ((u8 *volatile)flags_address) =
                (u8 *)((volatile u32)tile + (u32)(u8 *volatile)lookup_copy);
            ((volatile u32)tile) |= mask;
            U8_AT((volatile u32)address) = (volatile u32)tile;
            ((volatile u32)tile) = *(u8 *volatile)flags_address;
            ((volatile u32)tile) |= mask;
            *(u8 *volatile)flags_address = (volatile u32)tile;
            ((volatile s32)column_signed) += 1;
            ((volatile s32)column_signed) <<= 16;
            {
                register u32 narrowed asm("r0") = (u32)(volatile s32)column_signed >> 16;
                asm("" : : "r"(narrowed));
                last_row = narrowed;
            }
            ((volatile s32)column_signed) >>= 16;
            if ((volatile s32)column_signed <= 2)
                goto pilot_clear_first_column;
        }
            {
                register u32 increment asm("r1");
                register u32 next asm("r0");
                register u8 *count_copy asm("r2");
                increment = 0x10000;
                ((volatile u32)next) = row_shift + increment;
                row = (u16)((volatile u32)next >> 16);
                clear_row = row;
                ((volatile u32)next) = (s32)(volatile u32)next >> 16;
                ((u8 *volatile)count_copy) = (u8 *volatile)count;
                if ((s32)(volatile u32)next < *(u8 *volatile)count_copy)
                    goto pilot_clear_first_row;
            }
        }
        pilot_clear_first_done:
            RUN_UNCACHED(0x0875B124, 2);
            {
                register u32 names asm("r1");
                register u32 selected_shift asm("r3");
                register u32 address asm("r0");
                ((volatile u32)names) = (u32)pilot_selection_ids;
                asm("" : : "r"(names));
                selected_shift = selected_copy.word;
                asm("" : : "r"(selected_shift));
                ((volatile u32)address) = (s32)selected_shift >> 16;
                ((volatile u32)address) += names;
                func_0804DFB8(U8_AT((volatile u32)address), 2);
            }
            ((const u8 **volatile)layout) = menu_layout_scripts;
            script_run_table((const u8 **volatile)layout, 0x13);
            script_run_table((const u8 **volatile)layout, 0x25);
            if (ACTION == 1)
            {
                register u32 next_state asm("r4") = 0x1250;
                asm("" : : "r"(next_state));
                state = next_state;
                break;
            }
            func_080019EC(0x3F);
            {
                register u32 next_state asm("r4") = 0x1201;
                asm("" : : "r"(next_state));
                state = next_state;
            }
            script_run_table((const u8 **volatile)layout, 0xB);
            script_run_table((const u8 **volatile)layout, 0xA);
            {
                register int result asm("r0");
                result = script_run_table((const u8 **volatile)layout, 9);
                asm("" : : "r"(result));
            }
            script_run_table((const u8 **volatile)layout, 0);
            break;
        }
        case 0x1250:
        {
            register u32 clear_row asm("r6");
            register union RegisterHalf selected_copy asm("r9");
            register u8 *count asm("r8");
            register u8 *tiles asm("r10");
            register u8 *lookup asm("r12");
            u32 mask;
            register const u8 **layout asm("r5");
            {
                register u8 *windows asm("r3");
                register u32 selected_load asm("r4");
                row = 0;
                clear_row = row;
                asm("" : "+r"(clear_row));
                ((u8 *volatile)windows) = (u8 *)text_windows;
                ((volatile u32)selected_load) = selected_index;
                asm("" : : "r"(selected_load));
                ((volatile u32)selected_load) <<= 16;
                asm("" : : "r"(windows), "r"(selected_load));
                selected_copy.word = selected_load;
                mask = 0x02007C4D;
                asm("" : "+l"(mask));
                mask = U8_AT(mask);
                if ((s32)clear_row >= (s32)mask)
                    goto pilot_clear_second_done;
                {
                    register u8 *initial_lookup asm("r0");
                    register u32 count_address asm("r1");
                    register u32 tiles_address asm("r2");
                    ((u8 *volatile)initial_lookup) = (u8 *)0x0200904B;
                    asm("" : : "r"(initial_lookup));
                    lookup = initial_lookup;
                    ((volatile u32)count_address) = 0x6AD;
                    asm("" : : "r"(count_address));
                    ((volatile u32)count_address) += (u32)(u8 *volatile)windows;
                    asm("" : : "r"(count_address));
                    count = (u8 *)count_address;
                    ((volatile u32)tiles_address) = 0x6BC;
                    asm("" : : "r"(tiles_address));
                    ((volatile u32)tiles_address) += (u32)(u8 *volatile)windows;
                    asm("" : : "r"(tiles_address));
                    tiles = (u8 *)tiles_address;
                    mask = 255;
                    asm("" : "+r"(mask));
                }
            }
        pilot_clear_second_row:
        {
            register u32 row_shift asm("r5");
            register s32 row_signed asm("r4");
            {
                register u32 first_column asm("r3") = 1;
                asm("" : : "r"(first_column));
                last_row = first_column;
            }
            row = (u16)clear_row;
            row_shift = (u32)row << 16;
            row_signed = (s32)row_shift >> 16;
        pilot_clear_second_column:
        {
            register u32 column_load asm("r6") = last_row;
            register s32 column_signed asm("r2") = (s16)column_load;
            register u32 address asm("r1");
            register u32 tile asm("r0");
            register u8 *lookup_copy asm("r6");
            register u8 *flags_address asm("r3");
            asm("" : : "r"(column_load), "r"(column_signed));
            ((volatile u32)address) = (u32)(u8 *volatile)count;
            tile = U8_AT((volatile u32)address);
            ((volatile u32)address) = column_signed;
            asm("" : : "r"(address));
            ((volatile u32)address) *= tile;
            ((volatile u32)address) = row_signed + (volatile u32)address;
            ((volatile u32)address) += (u32)(u8 *volatile)tiles;
            ((volatile u32)tile) = U8_AT((volatile u32)address);
            ((u8 *volatile)lookup_copy) = (u8 *volatile)lookup;
            ((u8 *volatile)flags_address) =
                (u8 *)((volatile u32)tile + (u32)(u8 *volatile)lookup_copy);
            ((volatile u32)tile) |= mask;
            U8_AT((volatile u32)address) = (volatile u32)tile;
            ((volatile u32)tile) = *(u8 *volatile)flags_address;
            ((volatile u32)tile) |= mask;
            *(u8 *volatile)flags_address = (volatile u32)tile;
            ((volatile s32)column_signed) += 1;
            ((volatile s32)column_signed) <<= 16;
            {
                register u32 narrowed asm("r0") = (u32)(volatile s32)column_signed >> 16;
                asm("" : : "r"(narrowed));
                last_row = narrowed;
            }
            ((volatile s32)column_signed) >>= 16;
            if ((volatile s32)column_signed <= 2)
                goto pilot_clear_second_column;
        }
            {
                register u32 increment asm("r1");
                register u32 next asm("r0");
                register u8 *count_copy asm("r2");
                increment = 0x10000;
                ((volatile u32)next) = row_shift + increment;
                row = (u16)((volatile u32)next >> 16);
                clear_row = row;
                ((volatile u32)next) = (s32)(volatile u32)next >> 16;
                ((u8 *volatile)count_copy) = (u8 *volatile)count;
                if ((s32)(volatile u32)next < *(u8 *volatile)count_copy)
                    goto pilot_clear_second_row;
            }
        }
        pilot_clear_second_done:
            RUN_UNCACHED(0x0875B124, 7);
            {
                register u32 names asm("r1");
                register u32 selected_shift asm("r3");
                register u32 address asm("r0");
                ((volatile u32)names) = (u32)pilot_selection_ids;
                asm("" : : "r"(names));
                selected_shift = selected_copy.word;
                asm("" : : "r"(selected_shift));
                ((volatile u32)address) = (s32)selected_shift >> 16;
                ((volatile u32)address) += names;
                func_0804E094(U8_AT((volatile u32)address), 3);
            }
            ((const u8 **volatile)layout) = menu_layout_scripts;
            script_run_table((const u8 **volatile)layout, 0x11);
            script_run_table((const u8 **volatile)layout, 0x25);
            if (ACTION == 1)
            {
                register u32 next_state asm("r4") = 0x1260;
                asm("" : : "r"(next_state));
                state = next_state;
                break;
            }
            func_080019EC(0x3F);
            {
                register u32 next_state asm("r4") = 0x1201;
                asm("" : : "r"(next_state));
                state = next_state;
            }
            script_run_table((const u8 **volatile)layout, 0xB);
            script_run_table((const u8 **volatile)layout, 0xA);
            {
                register int result asm("r0");
                result = script_run_table((const u8 **volatile)layout, 9);
                asm("" : : "r"(result));
            }
            script_run_table((const u8 **volatile)layout, 0);
            break;
        }
        case 0x1260:
        {
            register u32 clear_row asm("r6");
            register union RegisterHalf selected_copy asm("r9");
            register u8 *count asm("r8");
            register u8 *tiles asm("r10");
            register u8 *lookup asm("r12");
            u32 mask;
            register const u8 **layout asm("r5");
            {
                register u8 *windows asm("r3");
                register u32 selected_load asm("r4");
                row = 0;
                clear_row = row;
                asm("" : "+r"(clear_row));
                ((u8 *volatile)windows) = (u8 *)text_windows;
                ((volatile u32)selected_load) = selected_index;
                asm("" : : "r"(selected_load));
                ((volatile u32)selected_load) <<= 16;
                asm("" : : "r"(windows), "r"(selected_load));
                selected_copy.word = selected_load;
                mask = 0x02007FA1;
                asm("" : "+l"(mask));
                mask = U8_AT(mask);
                if ((s32)clear_row >= (s32)mask)
                    goto pilot_clear_third_done;
                {
                    register u8 *initial_lookup asm("r0");
                    register u32 count_address asm("r1");
                    register u32 tiles_address asm("r2");
                    ((u8 *volatile)initial_lookup) = (u8 *)0x0200904B;
                    asm("" : : "r"(initial_lookup));
                    lookup = initial_lookup;
                    ((volatile u32)count_address) = 0xA01;
                    asm("" : : "r"(count_address));
                    ((volatile u32)count_address) += (u32)(u8 *volatile)windows;
                    asm("" : : "r"(count_address));
                    count = (u8 *)count_address;
                    ((volatile u32)tiles_address) = 0xA10;
                    asm("" : : "r"(tiles_address));
                    ((volatile u32)tiles_address) += (u32)(u8 *volatile)windows;
                    asm("" : : "r"(tiles_address));
                    tiles = (u8 *)tiles_address;
                    mask = 255;
                    asm("" : "+r"(mask));
                }
            }
        pilot_clear_third_row:
        {
            register u32 row_shift asm("r5");
            register s32 row_signed asm("r4");
            {
                register u32 first_column asm("r3") = 0;
                asm("" : : "r"(first_column));
                last_row = first_column;
            }
            row = (u16)clear_row;
            row_shift = (u32)row << 16;
            row_signed = (s32)row_shift >> 16;
        pilot_clear_third_column:
        {
            register u32 column_load asm("r6") = last_row;
            register s32 column_signed asm("r2") = (s16)column_load;
            register u32 address asm("r1");
            register u32 tile asm("r0");
            register u8 *lookup_copy asm("r6");
            register u8 *flags_address asm("r3");
            asm("" : : "r"(column_load), "r"(column_signed));
            ((volatile u32)address) = (u32)(u8 *volatile)count;
            tile = U8_AT((volatile u32)address);
            ((volatile u32)address) = column_signed;
            asm("" : : "r"(address));
            ((volatile u32)address) *= tile;
            ((volatile u32)address) = row_signed + (volatile u32)address;
            ((volatile u32)address) += (u32)(u8 *volatile)tiles;
            ((volatile u32)tile) = U8_AT((volatile u32)address);
            ((u8 *volatile)lookup_copy) = (u8 *volatile)lookup;
            ((u8 *volatile)flags_address) =
                (u8 *)((volatile u32)tile + (u32)(u8 *volatile)lookup_copy);
            ((volatile u32)tile) |= mask;
            U8_AT((volatile u32)address) = (volatile u32)tile;
            ((volatile u32)tile) = *(u8 *volatile)flags_address;
            ((volatile u32)tile) |= mask;
            *(u8 *volatile)flags_address = (volatile u32)tile;
            ((volatile s32)column_signed) += 1;
            ((volatile s32)column_signed) <<= 16;
            {
                register u32 narrowed asm("r0") = (u32)(volatile s32)column_signed >> 16;
                asm("" : : "r"(narrowed));
                last_row = narrowed;
            }
            ((volatile s32)column_signed) >>= 16;
            if ((volatile s32)column_signed <= 1)
                goto pilot_clear_third_column;
        }
            {
                register u32 increment asm("r1");
                register u32 next asm("r0");
                register u8 *count_copy asm("r2");
                increment = 0x10000;
                ((volatile u32)next) = row_shift + increment;
                row = (u16)((volatile u32)next >> 16);
                clear_row = row;
                ((volatile u32)next) = (s32)(volatile u32)next >> 16;
                ((u8 *volatile)count_copy) = (u8 *volatile)count;
                if ((s32)(volatile u32)next < *(u8 *volatile)count_copy)
                    goto pilot_clear_third_row;
            }
        }
        pilot_clear_third_done:
            RUN_UNCACHED(0x0875B124, 8);
            {
                register u32 names asm("r1");
                register u32 selected_shift asm("r3");
                register u32 address asm("r0");
                ((volatile u32)names) = (u32)pilot_selection_ids;
                asm("" : : "r"(names));
                selected_shift = selected_copy.word;
                asm("" : : "r"(selected_shift));
                ((volatile u32)address) = (s32)selected_shift >> 16;
                ((volatile u32)address) += names;
                func_0804E094(U8_AT((volatile u32)address), 4);
            }
            ((const u8 **volatile)layout) = menu_layout_scripts;
            script_run_table((const u8 **volatile)layout, 0x12);
            script_run_table((const u8 **volatile)layout, 0x25);
            if (ACTION == 1)
            {
                register u32 next_state asm("r4") = 0x1270;
                asm("" : : "r"(next_state));
                state = next_state;
                break;
            }
            func_080019EC(0x3F);
            {
                register u32 next_state asm("r4") = 0x1201;
                asm("" : : "r"(next_state));
                state = next_state;
            }
            script_run_table((const u8 **volatile)layout, 0xB);
            script_run_table((const u8 **volatile)layout, 0xA);
            {
                register int result asm("r0");
                result = script_run_table((const u8 **volatile)layout, 9);
                asm("" : : "r"(result));
            }
            script_run_table((const u8 **volatile)layout, 0);
            break;
        }
        case 0x1270:
        {
            register u32 clear_row asm("r6");
            register union RegisterHalf selected_copy asm("r9");
            register u8 *count asm("r8");
            register u8 *tiles asm("r10");
            register u8 *lookup asm("r12");
            u32 mask;
            register const u8 **layout asm("r4");
            RUN_UNCACHED(0x0875B124, 0xB);
            {
                register u8 *windows asm("r3");
                register u32 selected_load asm("r4");
                row = 0;
                clear_row = row;
                asm("" : "+r"(clear_row));
                ((volatile u32)selected_load) = selected_index;
                asm("" : : "r"(selected_load));
                ((volatile u32)selected_load) <<= 16;
                asm("" : : "r"(selected_load));
                selected_copy.word = selected_load;
                mask = 0x020078F9;
                asm("" : "+l"(mask));
                mask = U8_AT(mask);
                if ((s32)clear_row >= (s32)mask)
                    goto pilot_clear_fourth_done;
                {
                    register u8 *initial_lookup asm("r0");
                    register u32 count_address asm("r1");
                    register u32 tiles_address asm("r2");
                    ((u8 *volatile)windows) = (u8 *)text_windows;
                    asm("" : : "r"(windows));
                    ((u8 *volatile)initial_lookup) = (u8 *)0x0200904B;
                    asm("" : : "r"(initial_lookup));
                    lookup = initial_lookup;
                    ((volatile u32)count_address) = 0x359;
                    asm("" : : "r"(count_address));
                    ((volatile u32)count_address) += (u32)(u8 *volatile)windows;
                    asm("" : : "r"(count_address));
                    count = (u8 *)count_address;
                    ((volatile u32)tiles_address) = 0x368;
                    asm("" : : "r"(tiles_address));
                    ((volatile u32)tiles_address) += (u32)(u8 *volatile)windows;
                    asm("" : : "r"(tiles_address));
                    tiles = (u8 *)tiles_address;
                    mask = 255;
                    asm("" : "+r"(mask));
                }
            }
        pilot_clear_fourth_row:
        {
            register u32 row_shift asm("r5");
            register s32 row_signed asm("r4");
            {
                register u32 first_column asm("r3") = 1;
                asm("" : : "r"(first_column));
                last_row = first_column;
            }
            row = (u16)clear_row;
            row_shift = (u32)row << 16;
            row_signed = (s32)row_shift >> 16;
        pilot_clear_fourth_column:
        {
            register u32 column_load asm("r6") = last_row;
            register s32 column_signed asm("r2") = (s16)column_load;
            register u32 address asm("r1");
            register u32 tile asm("r0");
            register u8 *lookup_copy asm("r6");
            register u8 *flags_address asm("r3");
            asm("" : : "r"(column_load), "r"(column_signed));
            ((volatile u32)address) = (u32)(u8 *volatile)count;
            tile = U8_AT((volatile u32)address);
            ((volatile u32)address) = column_signed;
            asm("" : : "r"(address));
            ((volatile u32)address) *= tile;
            ((volatile u32)address) = row_signed + (volatile u32)address;
            ((volatile u32)address) += (u32)(u8 *volatile)tiles;
            ((volatile u32)tile) = U8_AT((volatile u32)address);
            ((u8 *volatile)lookup_copy) = (u8 *volatile)lookup;
            ((u8 *volatile)flags_address) =
                (u8 *)((volatile u32)tile + (u32)(u8 *volatile)lookup_copy);
            ((volatile u32)tile) |= mask;
            U8_AT((volatile u32)address) = (volatile u32)tile;
            ((volatile u32)tile) = *(u8 *volatile)flags_address;
            ((volatile u32)tile) |= mask;
            *(u8 *volatile)flags_address = (volatile u32)tile;
            ((volatile s32)column_signed) += 1;
            ((volatile s32)column_signed) <<= 16;
            {
                register u32 narrowed asm("r0") = (u32)(volatile s32)column_signed >> 16;
                asm("" : : "r"(narrowed));
                last_row = narrowed;
            }
            ((volatile s32)column_signed) >>= 16;
            if ((volatile s32)column_signed <= 2)
                goto pilot_clear_fourth_column;
        }
            {
                register u32 increment asm("r1");
                register u32 next asm("r0");
                register u8 *count_copy asm("r2");
                increment = 0x10000;
                ((volatile u32)next) = row_shift + increment;
                row = (u16)((volatile u32)next >> 16);
                clear_row = row;
                ((volatile u32)next) = (s32)(volatile u32)next >> 16;
                ((u8 *volatile)count_copy) = (u8 *volatile)count;
                if ((s32)(volatile u32)next < *(u8 *volatile)count_copy)
                    goto pilot_clear_fourth_row;
            }
        }
        pilot_clear_fourth_done:
            RUN_UNCACHED(0x0875B124, 9);
            {
                register u32 names asm("r1");
                register u32 selected_shift asm("r3");
                register u32 address asm("r0");
                ((volatile u32)names) = (u32)pilot_selection_ids;
                asm("" : : "r"(names));
                selected_shift = selected_copy.word;
                asm("" : : "r"(selected_shift));
                ((volatile u32)address) = (s32)selected_shift >> 16;
                ((volatile u32)address) += names;
                func_0804E094(U8_AT((volatile u32)address), 5);
            }
            ((const u8 **volatile)layout) = menu_layout_scripts;
            script_run_table((const u8 **volatile)layout, 0x13);
            script_run_table((const u8 **volatile)layout, 0x25);
            if (ACTION == 0)
                func_080019EC(0x3F);
            script_run_table((const u8 **volatile)layout, 0xB);
            script_run_table((const u8 **volatile)layout, 0xA);
            script_run_table((const u8 **volatile)layout, 9);
            script_run_table((const u8 **volatile)layout, 0);
            {
                register u32 next_state asm("r4") = 0x1201;
                asm("" : : "r"(next_state));
                state = next_state;
            }
            break;
        }
        case 0x1300:
        {
            register u32 list_row asm("r6");
            register union
            {
                u32 word;
                s16 signed_halves[2];
                u16 unsigned_halves[2];
            } page_word asm("r7");
            register u32 cached_index asm("r8");
            register const u8 **names asm("r9");
            register const u8 *quantities asm("r10");
            register const u8 *count asm("r12");
            RUN(0x0875B154, 0);
            {
                register u32 zero asm("r4") = 0;
                asm("" : : "r"(zero));
                page = zero;
                list_row = 0xFFFF;
                asm("" : : "r"(list_row));
                previous_page = list_row;
                previous_equipment_index = list_row;
                {
                    register u32 held0 asm("r0"), held1 asm("r1");
                    register u32 held2 asm("r2"), held3 asm("r3");
                    register u32 held5 asm("r5");
                    u16 *cursor;
                    asm(""
                        : "=&l"(cursor), "=r"(held0), "=r"(held1), "=r"(held2), "=r"(held3),
                          "=r"(held5)
                        : "0"((u16 *)0x02007588), "r"(zero), "r"(list_row));
                    *cursor = zero;
                }
            }
        equipment_inventory_refresh:
        {
            register s32 current_page asm("r4");
            register s32 old_page asm("r0");
            {
                register u32 page_load asm("r0") = page;
                register u32 shifted_page asm("r1") = page_load << 16;
                register u32 old_load asm("r2");
                current_page = (s32)shifted_page >> 16;
                asm("" : : "r"(page_load), "r"(shifted_page), "r"(current_page));
                old_load = previous_page;
                asm("" : : "r"(old_load));
                old_page = old_load << 16;
                old_page >>= 16;
                page_word.word = shifted_page;
                {
                    register union
                    {
                        unsigned long long whole;
                        struct
                        {
                            u32 low, high;
                        } part;
                    } guard asm("r6");
                    guard.part.low = list_row;
                    list_row = guard.part.low;
                }
                asm("" : "+r"(page_word.word) : "r"(old_page));
            }
            {
                register u32 previous_load asm("r3") = previous_equipment_index;
                asm("" : : "r"(previous_load));
                previous_load <<= 16;
                asm("" : : "r"(previous_load));
                previous_equipment_shift = previous_load;
            }
            if (current_page != old_page)
            {
                ((volatile u32)list_row) = -1;
                if (old_page != (s32)list_row)
                    RUN_UNCACHED(menu_layout_scripts, 2);
                ((volatile u32)list_row) = 0;
                {
                    register u32 row_word asm("r0");
                    register u32 row_value asm("r1");
                    register const u8 *initial_count asm("r1");
                    register s32 count_value asm("r2");
                    row_word = current_page * 3;
                    row_word <<= 17;
                    ((volatile u32)row_value) = row_word >> 16;
                    last_row = row_value;
                    row_word = (s32)row_word >> 16;
                    ((const u8 *volatile)initial_count) = &equipment_selection_count;
                    count = initial_count;
                    count_value = *initial_count;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r1");
                        guard.part.high = count_value;
                        count_value = guard.part.high;
                    }

                    if ((s32)row_word < count_value)
                    {
                        {
                            register const u8 **initial_names asm("r3");
                            register const u8 *initial_quantities asm("r0");
                            ((const u8 **volatile)initial_names) = (const u8 **)0x0866634C;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r2");
                                guard.part.high = (u32)initial_names;
                                initial_names = (const u8 **)guard.part.high;
                            }
                            names = initial_names;
                            ((const u8 *volatile)initial_quantities) = equipment_quantities;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = (u32)initial_quantities;
                                initial_quantities = (const u8 *)guard.part.low;
                            }

                            quantities = initial_quantities;
                            cached_index = current_page;
                        }
                    equipment_inventory_row:
                    {
                        register const u8 *entry asm("r4");
                        register u32 row_load asm("r1");
                        register u32 row_word asm("r0");
                        register s32 row_index asm("r5");
                        ((const u8 *volatile)entry) = equipment_selection_ids;
                        ((volatile u32)row_load) = last_row;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r0");
                            guard.part.high = (u32)row_load;
                            row_load = guard.part.high;
                        }
                        row_word = row_load << 16;
                        row_index = (s32)row_word >> 16;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r4");
                            guard.part.high = row_index;
                            row_index = guard.part.high;
                        }
                        entry = (const u8 *)((u32)row_index + (u32)entry);
                        script_run_table(names, *entry);
                        func_0804D604(names, *entry, 8);
                        RUN_UNCACHED(menu_layout_scripts, 0x28);
                        func_08001848(quantities[*entry], 1, 2);
                        if ((s16)list_row <= 4 && row_index < equipment_selection_count - 1)
                            RUN_UNCACHED(0x08675C5C, 0);
                    }
                        {
                            register u32 row_word asm("r0") = list_row << 16;
                            register u32 increment asm("r2") = 0x10000;
                            register s32 row_index asm("r1");
                            register const u8 *count_address asm("r3");
                            asm("" : "+r"(row_word) : "r"(increment));
                            row_word += increment;
                            list_row = row_word >> 16;
                            row_index = (s32)row_word >> 16;
                            ((const u8 *volatile)count_address) = &equipment_selection_count;
                            count = count_address;
                            if (row_index <= 5)
                            {
                                register u32 page_copy asm("r4") = cached_index;
                                register u32 narrowed asm("r1");
                                asm("" : "+r"(cached_index) : "r"(page_copy));
                                row_word = page_copy << 1;
                                row_word += cached_index;
                                row_word <<= 1;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = row_index;
                                    row_index = guard.part.high;
                                }
                                row_word = row_index + row_word;
                                row_word <<= 16;
                                ((volatile u32)narrowed) = row_word >> 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = (u32)narrowed;
                                    narrowed = guard.part.high;
                                }
                                last_row = narrowed;
                                row_word = (s32)row_word >> 16;
                                {
                                    register u32 next_count asm("r1");
                                    ((volatile u32)next_count) = *count_address;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.high = (u32)next_count;
                                        next_count = guard.part.high;
                                    }
                                    narrowed = next_count;
                                }
                                if ((s32)row_word < (s32)narrowed)
                                    goto equipment_inventory_row;
                            }
                        }
                    }
                }
                {
                    register s32 rows asm("r0") = (s16)list_row;
                    register u16 *cursor asm("r2");
                    register u8 *window asm("r3");
                    register u32 cursor_value asm("r4");
                    ((u16 *volatile)cursor) = (u16 *)0x02007588;
                    ((u8 *volatile)window) = (u8 *)text_windows;

                    ((volatile u32)cursor_value) = *cursor;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r3");
                        guard.part.high = (u32)cursor_value;
                        cursor_value = guard.part.high;
                    }
                    if (rows <= (s32)cursor_value)
                    {
                        register u32 clamped asm("r0");
                        register u8 *cursor_byte asm("r6");
                        ((volatile u32)clamped) = list_row - 1;
                        ((u8 *volatile)cursor_byte) = (u8 *)0x02007C55;
                        *cursor_byte = clamped;
                        clamped <<= 24;
                        clamped >>= 24;
                        *cursor = clamped;
                    }
                    {
                        register u32 offset asm("r0");
                        register u8 *flags asm("r2");
                        register u32 spare asm("r3");
                        register u32 zero asm("r0");
                        ((volatile u32)offset) = 0x6B7;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r0");
                            guard.part.low = (u32)offset;
                            offset = guard.part.low;
                        }
                        flags = window + offset;
                        ((volatile u32)spare) = 0;
                        ((volatile u32)zero) = 0;
                        asm("" : : "r"(spare), "r"(zero));
                        *flags = zero;
                        if ((s32)(volatile u32)page_word.word > 0)
                        {
                            register u32 one asm("r0") = 1;
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r0");
                            guard.part.low = one;
                            one = guard.part.low;
                            *flags = one;
                        }
                        {
                            register u32 row_load asm("r4");
                            register s32 last asm("r1");
                            register const u8 *count_copy asm("r6");
                            row_load = last_row;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r3");
                                guard.part.high = (u32)row_load;
                                row_load = guard.part.high;
                            }
                            last = (s16)row_load;
                            asm("" : : "r"(row_load), "r"(last));
                            ((const u8 *volatile)count_copy) = count;

                            {
                                register u32 limit asm("r0") = *count_copy;
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = limit;
                                limit = guard.part.low;
                                if (last < (s32)limit - 1)
                                {
                                    register u32 flags_value asm("r0");
                                    register u32 bits asm("r1");
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    flags_value = *flags;
                                    guard.part.low = flags_value;
                                    flags_value = guard.part.low;
                                    bits = 2;
                                    guard.part.high = bits;
                                    bits = guard.part.high;
                                    *flags = flags_value | bits;
                                }
                            }
                        }
                    }
                }
                asm("" : "+r"(page_word.word));
                {
                    register u32 stored_page asm("r0");
                    ((volatile u32)stored_page) = page_word.word >> 16;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r0");
                        guard.part.low = stored_page;
                        stored_page = guard.part.low;
                    }
                    previous_page = stored_page;
                }
            }
        }
            {
                register u32 selected_word asm("r0");
                register s32 selected_signed asm("r2");
                register const u8 *entry asm("r4");
                register const u8 *record asm("r5");
                register u32 previous_load asm("r3");
                register s32 previous asm("r0");
                {
                    register s32 current_page asm("r1");
                    register u32 cursor_value asm("r1");
                    asm("" : "+r"(page_word.word));
                    current_page = page_word.signed_halves[1];
                    selected_word = current_page * 6;
                    asm("" : : "r"(selected_word));
                    cursor_value = CURSOR;
                    selected_word += cursor_value;
                    {
                        register const u8 *ids asm("r1") = equipment_selection_ids;
                        asm("" : : "r"(ids));
                        selected_word <<= 16;
                        cached_index = selected_word;
                        selected_signed = (s32)selected_word >> 16;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r0");
                            guard.part.high = (u32)ids;
                            ids = (const u8 *)guard.part.high;
                        }
                        entry = (const u8 *)((u32)selected_signed + (u32)ids);
                    }
                    {
                        register u32 id asm("r1") = *entry;
                        register u32 bytes asm("r0") = id * 24;
                        register const u8 *records asm("r1") = equipment_records;
                        asm("" : : "r"(bytes), "r"(records));
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r0");
                            guard.part.high = (u32)records;
                            records = (const u8 *)guard.part.high;
                        }
                        record = (const u8 *)(bytes + (u32)records);
                    }
                }
                previous_load = previous_equipment_shift;
                asm("" : : "r"(previous_load));
                previous = (s32)previous_load >> 16;
                if (selected_signed != previous)
                {
                    register s32 missing asm("r6") = -1;
                    register const u8 **layout asm("r9");
                    register const u8 **separator asm("r7");
                    register u32 attributes asm("r4");
                    register u32 weapon asm("r6");
                    asm("" : : "r"(missing));
                    if (previous != missing)
                    {
                        RUN_UNCACHED(menu_layout_scripts, 0);
                        RUN_UNCACHED(menu_layout_scripts, 1);
                    }
                    {
                        register const u8 **initial_layout asm("r7");
                        ((const u8 **volatile)initial_layout) = menu_layout_scripts;
                        asm("" : : "r"(initial_layout));
                        layout = initial_layout;
                    }
                    script_run_table(layout, 0x19);
                    RUN(0x0875B64C, *entry);
                    script_run_table(layout, 0x1A);
                    RUN(0x0866634C, *entry);
                    ((const u8 **volatile)separator) = (const u8 **)0x08675C5C;
                    script_run_table((const u8 **volatile)separator, 0);
                    attributes = U32_AT(record);
                    weapon = 1;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r5");
                        guard.part.low = (u32)record;
                        record = (const u8 *)guard.part.low;
                    }
                    weapon &= attributes;
                    asm("" : : "r"(attributes), "r"(weapon));
                    if (weapon)
                    {
                        register const u8 **details asm("r4") = (const u8 **)0x0875B154;
                        register s32 fixed asm("r0");
                        script_run_table(details, 1);
                        fixed = S32_AT(record + 12);
                        if (fixed < 0)
                        {
                            register u32 adjustment asm("r1") = 0xFFFF;
                            asm("" : : "r"(adjustment));
                            fixed += adjustment;
                        }
                        func_08001848(fixed >> 16, 3, 0);
                        script_run_table(details, 2);
                        {
                            register u32 held1 asm("r1"), held3 asm("r3");
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } held asm("r6");
                            register s32 power asm("r0");
                            asm("" : "=r"(held1), "=r"(held3), "=r"(held.whole));
                            power = S16_AT(record + 8);
                            asm("" : : "r"(held1), "r"(held3), "r"(held.whole), "r"(power));
                            func_08001848(power, 3, 0);
                        }
                        script_run_table(layout, 0x27);
                        script_run_table((const u8 **volatile)separator, 0);
                        script_run_table(details, 3);
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } held12 asm("r1"), held67 asm("r6");
                            register s32 range asm("r0");
                            asm("" : "=r"(held12.whole), "=r"(held67.whole));
                            range = S16_AT(record + 16);
                            asm("" : : "r"(held12.whole), "r"(held67.whole), "r"(range));
                            func_08001848(range, 3, 0);
                        }
                        script_run_table(details, 4);
                        RUN(0x0875B244, U8_AT(record + 18));
                        RUN(0x0875B25C, U8_AT(record + 19));
                        script_run_table((const u8 **volatile)separator, 0);
                        RUN(0x0875B2EC, 0);
                        script_run_table((const u8 **volatile)separator, 0);
                        script_run_table(layout, 0x2A);
                        {
                            register u32 shown asm("r4") = 0;
                            register u32 column asm("r6") = 0;
                            page_word.word = cached_index;
                            asm("" : : "r"(shown), "r"(column), "r"(page_word.word));
                            do
                            {
                                if ((u8)func_0804DD28((u32 *)record, (u8)column))
                                {
                                    {
                                        register s32 shifted asm("r0") = shown << 16;
                                        shown = shifted >> 16;
                                        asm("" : : "r"(shown), "r"(shifted));
                                    }
                                    if (shown & 1)
                                        RUN_UNCACHED(0x08675C5C, 0);
                                    RUN_UNCACHED(menu_layout_scripts, 0x2A);
                                    {
                                        register u32 shifted asm("r0") = shown + 1;
                                        shifted <<= 16;
                                        shown = shifted >> 16;
                                        asm("" : : "r"(shifted), "r"(shown));
                                    }
                                }
                                {
                                    register u32 shifted asm("r0") = column << 16;
                                    register u32 increment asm("r6") = 0x10000;
                                    asm("" : "+r"(shifted) : "r"(increment));
                                    shifted += increment;
                                    column = shifted >> 16;
                                    if ((s32)shifted >> 16 > 3)
                                        break;
                                }
                            } while (1);
                            if (!shown)
                                RUN(0x0875B2EC, 1);
                        }
                    }
                    else
                    {
                        register u32 mask asm("r0") = attributes & 14;
                        page_word.word = cached_index;
                        asm("" : : "r"(mask), "r"(page_word.word));
                        if (mask)
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } held asm("r6");
                            register s32 fixed asm("r1");
                            register s32 power asm("r2");
                            register s32 range asm("r3");
                            held.part.low = weapon;
                            held.part.high = page_word.word;
                            asm("" : : "r"(held.whole));
                            fixed = S32_AT(record + 12);
                            power = S16_AT(record + 8);
                            range = S16_AT(record + 16);
                            asm("" : "+r"(held.whole) : "r"(fixed), "r"(power), "r"(range));
                            weapon = held.part.low;
                            page_word.word = held.part.high;
                            func_0804D8AC(attributes, fixed, power, range, U8_AT(record + 20),
                                          weapon);
                        }
                    }
                    RUN_UNCACHED(menu_layout_scripts, 0x18);
                    RUN_UNCACHED(menu_layout_scripts, 0x1B);
                    asm("" : "+r"(page_word.word));
                    {
                        register u32 stored_index asm("r1") = page_word.word >> 16;
                        asm("" : : "r"(stored_index));
                        previous_equipment_index = stored_index;
                    }
                }
            }
            RUN_UNCACHED(menu_layout_scripts, 0x23);
            {
                register const u16 *input asm("r1") = (const u16 *)0x02007574;
                register u32 action asm("r0");
                register u32 result asm("r0");
                asm("" : "+r"(input));
                action = *input;
                if (action <= 1)
                    goto equipment_inventory_done;
                if (action == 2)
                    goto equipment_inventory_left;
                if (action == 4)
                    goto equipment_inventory_right;
                goto equipment_inventory_refresh;
            equipment_inventory_left:
            {
                register u32 page_load asm("r2") = page;
                register s32 current_page asm("r4");
                asm("" : : "r"(page_load));
                result = page_load << 16;
                current_page = (s32)result >> 16;
                if (current_page <= 0)
                    goto equipment_inventory_refresh;
                func_080019EC(0x40);
                result = (current_page - 1) << 16;
                goto equipment_inventory_page;
            }
            equipment_inventory_right:
            {
                register u32 row_load asm("r3") = last_row;
                register s32 last asm("r1") = (s16)row_load;
                asm("" : : "r"(row_load), "r"(last));
                if (last >= equipment_selection_count - 1)
                    goto equipment_inventory_refresh;
                func_080019EC(0x40);
                {
                    register u32 page_load asm("r4") = page;
                    register u32 increment asm("r6");
                    asm("" : : "r"(page_load));
                    result = page_load << 16;
                    asm("" : "+r"(result));
                    increment = 0x10000;
                    asm("" : : "r"(increment));
                    result += increment;
                }
            equipment_inventory_page:
                page = result >> 16;
            }
            }
            goto equipment_inventory_refresh;
        equipment_inventory_done:
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
            asm("" : : "r"(list_row));
            if (ACTION != 0)
                goto menu_inventory_return;
            func_080019EC(0x3F);
            asm("" : : "r"(list_row));
            goto menu_inventory_return;
        }
        case 0x1400:
        {
            register const u8 **core_layout asm("r10");
            register u32 core_row asm("r6");
            RUN(0x0875B168, 0);
            {
                union CoreInitialPage
                {
                    u32 word;
                    u16 halves[2];
                };
                register union CoreInitialPage initial_page asm("r7");
                register u32 invalid_index asm("r0");
                register u16 *initial_cursor asm("r1");
                initial_page.word = 0;
                asm("" : "+r"(initial_page.word));
                page = initial_page.word;
                invalid_index = 0xFFFF;
                asm("" : : "r"(invalid_index));
                previous_page = invalid_index;
                previous_core_index = invalid_index;
                initial_cursor = (u16 *)0x02007588;
                *initial_cursor = initial_page.halves[0];
            }
            {
                register const u8 **initial_layout asm("r2");
                ((const u8 **volatile)initial_layout) = menu_layout_scripts;
                asm("" : : "r"(initial_layout));
                core_layout = initial_layout;
            }
        core_inventory_refresh:
        {
            register union RegisterHalf core_page asm("r7");
            register union RegisterHalf core_previous asm("r9");
            register union RegisterHalf core_value asm("r8");
            u32 core_index;
            union CoreModelPhase
            {
                s32 index;
                u32 address;
            };
            register union CoreModelPhase core_model asm("r4");
            register s32 current_page asm("r4");
            register s32 old_page asm("r0");
            register u32 core_row_index asm("r2");
            {
                register u32 page_load asm("r3") = page;
                register u32 page_word asm("r1") = page_load << 16;
                register u32 old_load asm("r6");
                current_page = (s32)page_word >> 16;
                asm("" : : "r"(page_load), "r"(page_word), "r"(current_page));
                old_load = previous_page;
                asm("" : : "r"(old_load));
                ((volatile s32)old_page) = old_load << 16;
                ((volatile s32)old_page) >>= 16;
                core_page.word = page_word;
                asm("" : "+r"(core_page.word));
            }
            {
                register u32 previous_core_word asm("r1") = previous_core_index;
                asm("" : : "r"(previous_core_word));
                ((volatile u32)previous_core_word) <<= 16;
                asm("" : : "r"(previous_core_word));
                core_previous.word = previous_core_word;
            }
            if (current_page != old_page)
            {
                union CoreRowPhase
                {
                    const u8 *count;
                    s32 index;
                };
                register union CoreRowPhase row_phase asm("r4");
                register u32 initial_index_word asm("r0");
                {
                    register s32 invalid_page asm("r2");
                    ((volatile s32)invalid_page) = -1;
                    asm("" : : "r"(invalid_page));
                    if (old_page != (volatile s32)invalid_page)
                        RUN_UNCACHED(menu_layout_scripts, 2);
                }
                core_row = 0;
                asm("" : "+r"(core_row));
                initial_index_word = current_page * 3;
                core_row_index = initial_index_word << 1;
                initial_index_word <<= 17;
                {
                    register u32 initial_row asm("r3") = initial_index_word >> 16;
                    asm("" : : "r"(core_row_index), "r"(initial_row));
                    last_row = initial_row;
                }
                initial_index_word = (s32)initial_index_word >> 16;
                {
                    register const u8 *count_address asm("r1");
                    ((const u8 *volatile)count_address) = &core_selection_count;
                    asm("" : : "r"(count_address));
                    row_phase.count = count_address;
                }
                {
                    register s32 initial_count asm("r1") = *row_phase.count;
                    asm("" : : "r"(initial_count));
                    if ((s32)initial_index_word < initial_count)
                    {
                        register const u8 *core_count asm("r5");
                        ((const u8 *volatile)core_count) = row_phase.count;
                        asm("" : : "r"(core_count));
                        core_value.word = core_row_index;
                    core_list_row:
                    {
                        {
                            union CoreEntryAddress
                            {
                                const u8 *ids;
                                u32 word;
                            };
                            register union CoreEntryAddress row_address asm("r1");
                            register u32 row_load asm("r2");
                            register u32 row_word asm("r0");
                            row_address.ids = core_selection_ids;
                            asm("" : : "r"(row_address.ids));
                            row_load = last_row;
                            row_word = row_load << 16;
                            row_phase.index = (s32)row_word >> 16;
                            asm("" : : "r"(row_load), "r"(row_word), "r"(row_phase.index));
                            row_address.word = row_phase.index + (u32)row_address.ids;
                            func_08032800(*(const u8 *)row_address.word);
                        }
                        if ((s16)core_row <= 4 &&
                            row_phase.index < *(const u8 *volatile)core_count - 1)
                            RUN(0x08675C5C, 0);
                        {
                            register u32 row_word asm("r0") = (u32)core_row << 16;
                            register u32 increment asm("r3") = 0x10000;
                            asm("" : "+r"(row_word) : "r"(increment));
                            row_word += increment;
                            core_row = row_word >> 16;
                            asm("" : : "r"(core_row), "r"(row_word));
                            ((volatile u32)row_word) = (s32)row_word >> 16;
                            ((const u8 *volatile)row_phase.count) = &core_selection_count;
                            asm("" : : "r"(row_phase.count));
                            if ((s32)(volatile u32)row_word > 5)
                                goto core_list_done;
                            row_word = (volatile u32)core_value.word + (s32)(volatile u32)row_word;
                            row_word <<= 16;
                            {
                                register u32 narrowed_row asm("r1") = row_word >> 16;
                                asm("" : : "r"(narrowed_row));
                                last_row = narrowed_row;
                            }
                            row_word = (s32)row_word >> 16;
                            {
                                register s32 count_value asm("r2") =
                                    *(const u8 *volatile)core_count;
                                asm("" : : "r"(count_value));
                                if ((s32)row_word < count_value)
                                    goto core_list_row;
                            }
                        }
                    }
                    core_list_done:;
                    }
                }
                {
                    register u32 row_word asm("r0");
                    register u16 *cursor asm("r2");
                    register u8 *window_base asm("r3");
                    register s32 cursor_value asm("r1");
                    ((volatile u32)row_word) = (u32)core_row << 16;
                    ((volatile u32)row_word) = (s32)row_word >> 16;
                    ((u16 *volatile)cursor) = (u16 *)0x02007588;
                    ((u8 *volatile)window_base) = (u8 *)text_windows;
                    asm("" : : "r"(cursor), "r"(window_base));
                    cursor_value = *cursor;
                    asm("" : : "r"(cursor_value));
                    if ((s32)(volatile u32)row_word <= cursor_value)
                    {
                        register u32 clamped asm("r0") = core_row - 1;
                        register u8 *cursor_byte asm("r6");
                        asm("" : : "r"(clamped));
                        ((u8 *volatile)cursor_byte) = (u8 *)0x02007C55;
                        asm("" : : "r"(cursor_byte));
                        *cursor_byte = clamped;
                        ((volatile u32)clamped) <<= 24;
                        ((volatile u32)clamped) >>= 24;
                        *cursor = (volatile u32)clamped;
                    }
                    {
                        register u32 flags_offset asm("r0");
                        register u8 *page_flags asm("r2");
                        ((volatile u32)flags_offset) = 0x6B7;
                        asm("" : : "r"(flags_offset));
                        ((u8 *volatile)page_flags) =
                            (u8 *volatile)window_base + (volatile u32)flags_offset;
                        {
                            register u32 spare asm("r3") = 0;
                            register u32 zero asm("r0") = 0;
                            asm("" : : "r"(spare), "r"(zero));
                            *page_flags = zero;
                        }
                        if ((s32)core_page.word > 0)
                            *page_flags = 1;
                        {
                            register u32 last_row_load asm("r6") = last_row;
                            register union RegisterHalf row_bound asm("r1");
                            row_bound.word = last_row_load << 16;
                            asm("" : : "r"(last_row_load), "r"(row_bound.word));
                            if (row_bound.halves[1] < *row_phase.count - 1)
                                *page_flags |= 2;
                        }
                    }
                }
                asm("" : "+r"(core_page.word));
                {
                    register u32 stored_page asm("r0") = core_page.word >> 16;
                    asm("" : : "r"(stored_page));
                    previous_page = stored_page;
                }
            }
            {
                register u32 index_word asm("r0");
                {
                    register u32 cursor_value asm("r1");
                    index_word = core_page.halves[1] * 6;
                    asm("" : : "r"(index_word));
                    cursor_value = CURSOR;
                    asm("" : : "r"(cursor_value));
                    index_word += cursor_value;
                }
                ((volatile u32)index_word) <<= 16;
                core_row_index = (volatile u32)index_word >> 16;
                core_value.word = core_row_index;
                core_model.index = (s32)(volatile u32)index_word >> 16;
                asm("" : : "r"(core_row_index), "r"(core_value.word), "r"(core_model.index));
            }
            {
                register u32 previous_core_word asm("r3") = core_previous.word;
                register s32 previous_core asm("r0");
                asm("" : : "r"(previous_core_word));
                previous_core = (s32)previous_core_word >> 16;
                asm("" : : "r"(previous_core));
                if (core_model.index != previous_core)
                {
                    register s32 no_core asm("r6") = -1;
                    asm("" : : "r"(no_core));
                    if (previous_core != no_core)
                        RUN_UNCACHED(menu_layout_scripts, 1);
                    {
                        register const u8 *id_address asm("r0");
                        register u32 model_id asm("r1");
                        ((const u8 *volatile)id_address) = core_selection_ids;
                        ((const u8 *volatile)id_address) =
                            (const u8 *)(core_model.index + (u32)(const u8 *volatile)id_address);
                        ((volatile u32)model_id) = *(const u8 *volatile)id_address;
                        ((volatile u32)model_id) *= 76;
                        ((const u8 *volatile)id_address) = (const u8 *)0x0867008C;
                        asm("" : "+r"(id_address) : "r"(model_id));
                        core_model.address =
                            (volatile u32)model_id + (u32)(const u8 *volatile)id_address;
                    }
                    script_run_table((const u8 **volatile)core_layout, 0x1A);
                    RUN(0x0875B168, 1);
                    func_08001848(U32_AT(core_model.address + 4), 7, 1);
                    RUN(0x0875B168, 2);
                    script_run_table((const u8 **volatile)core_layout, 0x2A);
                    if (U8_AT(core_model.address + 12) != 0)
                    {
                        if (U8_AT(core_model.address + 12) <= 249)
                            func_08032800(U8_AT(core_model.address + 12));
                        else
                            RUN(0x0875B320, U8_AT(core_model.address + 12) - 250);
                    }
                    else
                        RUN(0x0875B168, 4);
                    {
                        register const u8 **separator asm("r6");
                        ((const u8 **volatile)separator) = (const u8 **)0x08675C5C;
                        script_run_table((const u8 **volatile)separator, 0);
                        RUN(0x0875B168, 3);
                        {
                            register const u8 **details asm("r7");
                            ((const u8 **volatile)details) = menu_layout_scripts;
                            asm("" : : "r"(details));
                            script_run_table((const u8 **volatile)details, 0x2A);
                            if (U8_AT(core_model.address + 13) != 255)
                            {
                                register const u8 **names asm("r5");
                                ((const u8 **volatile)names) = (const u8 **)0x08676254;
                                script_run_table((const u8 **volatile)names,
                                                 U8_AT(core_model.address + 13));
                                script_run_table((const u8 **volatile)separator, 0);
                                if (U8_AT(core_model.address + 14) != 255)
                                {
                                    script_run_table((const u8 **volatile)details, 0x2A);
                                    script_run_table((const u8 **volatile)names,
                                                     U8_AT(core_model.address + 14));
                                }
                            }
                            else if (U8_AT(core_model.address + 14) != 255)
                                RUN(0x08676254, U8_AT(core_model.address + 14));
                            else
                                RUN(0x0875B168, 4);
                            script_run_table((const u8 **volatile)core_layout, 0x18);
                            script_run_table((const u8 **volatile)core_layout, 0x1B);
                            {
                                register u32 stored_index asm("r7") = core_value.word;
                                asm("" : : "r"(stored_index));
                                previous_core_index = stored_index;
                            }
                        }
                    }
                }
            }
            RUN_UNCACHED(menu_layout_scripts, 0x23);
            {
                register u32 action asm("r0");
                register u32 result asm("r0");
                register const u16 *action_address asm("r1") = (const u16 *)0x02007574;
                asm("" : "+r"(action_address));
                action = *action_address;
                if (action <= 1)
                    goto core_inventory_done;
                if (action == 2)
                    goto core_inventory_left;
                if (action == 4)
                    goto core_inventory_right;
                goto core_inventory_refresh;
            core_inventory_left:
            {
                register u32 page_load asm("r1") = page;
                register s32 page_signed asm("r4");
                asm("" : : "r"(page_load));
                result = page_load << 16;
                page_signed = (s32)result >> 16;
                if (page_signed <= 0)
                    goto core_inventory_refresh;
                func_080019EC(0x40);
                result = (page_signed - 1) << 16;
                goto core_inventory_page;
            }
            core_inventory_right:
            {
                register u32 row_load asm("r2") = last_row;
                register s32 last asm("r1") = (s16)row_load;
                asm("" : : "r"(row_load), "r"(last));
                if (last >= core_selection_count - 1)
                    goto core_inventory_refresh;
                func_080019EC(0x40);
                {
                    register u32 page_load asm("r3") = page;
                    register u32 increment asm("r4");
                    asm("" : : "r"(page_load));
                    result = page_load << 16;
                    asm("" : "+r"(result));
                    increment = 0x10000;
                    asm("" : : "r"(increment));
                    result += increment;
                }
            core_inventory_page:
                page = result >> 16;
            }
            }
        }
            goto core_inventory_refresh;
        core_inventory_done:
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
            asm("" : : "r"(core_layout));
            if (ACTION != 0)
                goto menu_inventory_return;
            func_080019EC(0x3F);
            asm("" : : "r"(core_layout));
            goto menu_inventory_return;
        }
        case 0x1500:
        {
            register u16 part_row asm("r6");
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
            RUN_UNCACHED(0x0875B068, 0xB);
            {
                register u32 initial_page asm("r6") = 0;
                register u32 initial_previous asm("r7");
                register u16 *cursor asm("r0");
                asm("" : "+r"(initial_page));
                page = initial_page;
                initial_previous = 0xFFFF;
                asm("" : "+r"(initial_previous));
                previous_page = initial_previous;
                previous_item_index = initial_previous;
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                *cursor = initial_page;
            }
        part_inventory_refresh:
        {
            register union RegisterHalf part_page asm("r7");
            register s32 current_page asm("r4");
            register s32 old_page asm("r0");
            {
                register u32 page_load asm("r2") = page;
                register u32 page_word asm("r1") = page_load << 16;
                register u32 old_load asm("r3");
                current_page = (s32)page_word >> 16;
                asm("" : : "r"(page_load), "r"(page_word), "r"(current_page));
                old_load = previous_page;
                asm("" : : "r"(old_load));
                ((volatile s32)old_page) = old_load << 16;
                ((volatile s32)old_page) >>= 16;
                part_page.word = page_word;
                asm("" : "+r"(part_page.word));
                {
                    register u32 old_item asm("r6") = previous_item_index;
                    asm("" : : "r"(old_item));
                    ((volatile u32)old_item) <<= 16;
                    asm("" : : "r"(old_item));
                    previous_item_shift = old_item;
                }
            }
            if (current_page != old_page)
            {
                register const u8 **part_names asm("r9");
                register const u8 *quantities asm("r10");
                register s32 page_rows asm("r8");
                register const u8 *count asm("r5");
                if (old_page != -1)
                    RUN_UNCACHED(menu_layout_scripts, 2);
                part_row = 0;
                {
                    register u32 row_word asm("r0") = (current_page * 6) << 16;
                    register u32 row_narrow asm("r2") = row_word >> 16;
                    register const u8 *count_address asm("r1");
                    register s32 count_value asm("r3");
                    last_row = row_narrow;
                    ((volatile u32)row_word) = (s32)row_word >> 16;
                    ((const u8 *volatile)count_address) = &part_selection_count;
                    count = count_address;
                    count_value = *(const u8 *volatile)count;
                    asm("" : : "r"(row_narrow), "r"(count_address), "r"(count), "r"(count_value));
                    if ((s32)row_word >= count_value)
                        goto part_inventory_rows_done;
                }
                {
                    {
                        register const u8 **names asm("r0");
                        register const u8 *quantity_base asm("r1");
                        ((const u8 **volatile)names) = (const u8 **)0x08676254;

                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r0");
                            guard.part.low = (u32)names;
                            names = (const u8 **)guard.part.low;
                        }
                        part_names = names;
                        ((const u8 *volatile)quantity_base) = part_quantities;

                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r0");
                            guard.part.high = (u32)quantity_base;
                            quantity_base = (const u8 *)guard.part.high;
                        }
                        quantities = quantity_base;
                    }
                    page_rows = current_page;
                part_inventory_row:
                {
                    register const u8 *part_id asm("r4");
                    register s32 row_index asm("r5");
                    ((const u8 *volatile)part_id) = part_selection_ids;
                    {
                        register u32 row_load asm("r2");
                        register u32 row_word asm("r0");
                        ((volatile u32)row_load) = last_row;

                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r1");
                            guard.part.high = (u32)row_load;
                            row_load = guard.part.high;
                        }
                        ((volatile u32)row_word) = row_load << 16;
                        ((volatile s32)row_index) = (s32)row_word >> 16;
                    }
                    ((const u8 *volatile)part_id) =
                        (const u8 *)(row_index + (u32)(const u8 *volatile)part_id);
                    script_run_table((const u8 **volatile)part_names, *(const u8 *volatile)part_id);
                    func_0804D604((const void *)part_names, *(const u8 *volatile)part_id, 8);
                    RUN_UNCACHED(menu_layout_scripts, 0x28);
                    func_08001848(quantities[*(const u8 *volatile)part_id], 2, 2);
                    if ((s16)part_row <= 4 && row_index < part_selection_count - 1)
                        RUN_UNCACHED(0x08675C5C, 0);
                }
                    {
                        register u32 shifted_row asm("r0") = (u32)part_row << 16;
                        register u32 increment asm("r3") = 0x10000;
                        register s32 signed_row asm("r1");
                        asm("" : : "r"(shifted_row), "r"(increment));
                        shifted_row += increment;
                        part_row = shifted_row >> 16;
                        signed_row = (s32)shifted_row >> 16;
                        ((const u8 *volatile)count) = &part_selection_count;
                        if (signed_row > 5)
                            goto part_inventory_rows_done;
                        {
                            register s32 page_copy asm("r4") = page_rows;
                            asm("" : : "r"(page_copy));
                            shifted_row = signed_row + (page_copy * 2 + page_rows) * 2;
                        }
                        shifted_row <<= 16;
                        {
                            register u32 narrowed_row asm("r1") = shifted_row >> 16;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.high = narrowed_row;
                                narrowed_row = guard.part.high;
                            }
                            last_row = narrowed_row;
                        }
                        ((volatile u32)shifted_row) = (s32)shifted_row >> 16;
                        {
                            register s32 count_value asm("r1") = *(const u8 *volatile)count;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.high = count_value;
                                count_value = guard.part.high;
                            }
                            if ((s32)shifted_row < count_value)
                                goto part_inventory_row;
                        }
                    }
                }
            part_inventory_rows_done:
            {
                register u32 row_word asm("r0") = (u32)part_row << 16;
                register u16 *cursor asm("r2");
                register u8 *windows asm("r3");
                register s32 cursor_row asm("r4");
                register u8 *flags asm("r2");
                ((volatile u32)row_word) = (s32)row_word >> 16;
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                ((u8 *volatile)windows) = (u8 *)text_windows;
                cursor_row = *(u16 *volatile)cursor;
                asm("" : : "r"(row_word), "r"(cursor), "r"(windows), "r"(cursor_row));
                if ((s32)row_word <= cursor_row)
                {
                    register u16 clamped asm("r0") = part_row - 1;
                    register u8 *cursor_byte asm("r6");
                    ((u8 *volatile)cursor_byte) = (u8 *)0x02007C55;
                    *(u8 *volatile)cursor_byte = clamped;
                    ((volatile u16)clamped) = (u8)(volatile u16)clamped;
                    *(u16 *volatile)cursor = (volatile u16)clamped;
                }
                {
                    register u32 offset asm("r0");
                    register u32 flag_zero asm("r3");
                    register u32 zero asm("r0");
                    ((volatile u32)offset) = 0x6B7;
                    asm("" : : "r"(offset));
                    flags = windows + (volatile u32)offset;
                    ((volatile u32)flag_zero) = 0;
                    ((volatile u32)zero) = 0;
                    asm("" : : "r"(flag_zero), "r"(zero));
                    *(volatile u8 *)flags = (volatile u8)zero;
                }
                if ((s32)part_page.word > 0)
                    *(volatile u8 *)flags = 1;
                {
                    register u32 row_load asm("r4") = last_row;
                    register s32 signed_row asm("r1") = (s16)row_load;
                    asm("" : : "r"(row_load), "r"(signed_row));
                    if (signed_row < *(const u8 *volatile)count - 1)
                        *(volatile u8 *)flags |= 2;
                }
            }
                asm("" : "+r"(part_page.word));
                {
                    register union
                    {
                        unsigned long long whole;
                        struct
                        {
                            u32 low, high;
                        } part;
                    } guard asm("r6");
                    guard.part.low = part_page.word >> 16;
                    previous_page = guard.part.low;
                }
            }
            {
                register u32 item_word asm("r6");
                register s32 current_item asm("r5");
                u32 cursor;
                {
                    register s32 signed_page asm("r1") = part_page.halves[1];
                    register u32 rows asm("r0") = signed_page * 6;
                    register u32 held1 asm("r1"), held2 asm("r2"), held3 asm("r3");
                    register u32 held4 asm("r4"), held5 asm("r5"), held6 asm("r6");
                    asm("" : : "r"(signed_page), "r"(rows));
                    asm(""
                        : "=&l"(cursor), "=r"(held1), "=r"(held2), "=r"(held3), "=r"(held4),
                          "=r"(held5), "=r"(held6)
                        : "0"((u32)&CURSOR), "r"(rows));
                    cursor = U16_AT(cursor);
                    rows = (u16)(rows + cursor);
                    asm(""
                        :
                        : "r"(held1), "r"(held2), "r"(held3), "r"(held4), "r"(held5), "r"(held6),
                          "r"(rows));
                    item_index = rows;
                    item_word = rows << 16;
                    current_item = (s32)item_word >> 16;
                }
                {
                    register s32 old_item asm("r0");
                    {
                        register u32 old_word asm("r1") = previous_item_shift;
                        asm("" : : "r"(old_word));
                        old_item = (s32)old_word >> 16;
                        asm("" : : "r"(old_item));
                    }
                    if (current_item != old_item)
                    {
                        register const u8 *part_id asm("r4");
                        register s32 no_item asm("r2") = -1;
                        asm("" : : "l"(cursor));
                        asm("" : : "r"(no_item));
                        if (old_item != no_item)
                            RUN_UNCACHED(menu_layout_scripts, 1);
                        RUN_UNCACHED(menu_layout_scripts, 0x1A);
                        ((const u8 *volatile)part_id) = part_selection_ids;
                        ((const u8 *volatile)part_id) =
                            (const u8 *)(current_item + (u32)(const u8 *volatile)part_id);
                        {
                            register u32 selected_part asm("r1") = *(const u8 *volatile)part_id;
                            asm("" : : "r"(selected_part));
                            RUN_UNCACHED(0x08676254, selected_part);
                        }
                        RUN_UNCACHED(0x08675C5C, 0);
                        {
                            register u32 selected_part asm("r1") = *(const u8 *volatile)part_id;
                            asm("" : : "r"(selected_part));
                            RUN_UNCACHED(0x0875B9A0, selected_part);
                        }
                        RUN_UNCACHED(menu_layout_scripts, 0x18);
                        RUN_UNCACHED(menu_layout_scripts, 0x1B);
                        ((volatile u32)item_word) >>= 16;
                        previous_item_index = item_word;
                    }
                }
            }
        }
            {
                register u16 *input asm("r1");
                register u32 action asm("r0");
                register u32 next_page asm("r0");
                RUN_UNCACHED(menu_layout_scripts, 0x23);
                ((u16 *volatile)input) = (u16 *)0x02007574;
                ((volatile u32)action) = *(u16 *volatile)input;
                if ((volatile u32)action <= 1)
                    goto part_inventory_done;
                if ((volatile u32)action == 2)
                    goto part_inventory_left;
                if ((volatile u32)action == 4)
                    goto part_inventory_right;
                goto part_inventory_refresh;
            part_inventory_left:
            {
                register u32 page_load asm("r3") = page;
                register u32 shifted asm("r0") = page_load << 16;
                register s32 signed_page asm("r4") = (s32)shifted >> 16;
                asm("" : : "r"(page_load), "r"(shifted), "r"(signed_page));
                if (signed_page <= 0)
                    goto part_inventory_refresh;
                func_080019EC(0x40);
                ((volatile u32)next_page) = (signed_page - 1) << 16;
                goto part_inventory_save_page;
            }
            part_inventory_right:
            {
                register u32 row_load asm("r4") = last_row;
                register s32 signed_row asm("r1") = (s16)row_load;
                asm("" : : "r"(row_load), "r"(signed_row));
                if (signed_row >= part_selection_count - 1)
                    goto part_inventory_refresh;
                func_080019EC(0x40);
                {
                    register u32 page_load asm("r6") = page;
                    register u32 shifted asm("r0") = page_load << 16;
                    register u32 increment asm("r7") = 0x10000;
                    asm("" : : "r"(page_load), "r"(shifted), "r"(increment));
                    next_page = shifted + increment;
                }
            }
            part_inventory_save_page:
                ((volatile u32)next_page) >>= 16;
                page = (volatile u32)next_page;
                goto part_inventory_refresh;
            }
        part_inventory_done:
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
            asm("" : : "r"(part_row));
            if (ACTION != 0)
                goto menu_inventory_return;
            func_080019EC(0x3F);
            asm("" : : "r"(part_row));
            goto menu_inventory_return;
        }
        case 0x1600:
            RUN(0x0875B184, 0);
            {
                register u32 next_state asm("r4") = 0x1602;
                asm("" : "+r"(next_state));
                state = next_state;
            }
            break;
        case 0x1601:
            RUN(0x0875B184, 0);
            {
                register u32 restored_selection asm("r0") = selected[3];
                register u8 *cursor asm("r1");
                asm("" : : "r"(restored_selection));
                ((u8 *volatile)cursor) = (u8 *)0x02008651;
                *cursor = restored_selection;
            }
            LAYOUT(0x18);
            {
                register u32 tasks asm("r0") = 0x02000034;
                register u32 ready_offset asm("r2") = 0x568;
                register u32 *initial_ready asm("r1");
                asm("" : : "r"(tasks), "r"(ready_offset));
                initial_ready = (u32 *)(tasks + ready_offset);
                asm("" : : "r"(initial_ready));
                if (*initial_ready != 1)
                {
                    u32 *ready = initial_ready;
                    do
                        func_0805EE78(1);
                    while (*ready != 1);
                }
            }
        case 0x1602:
            RUN(0x0875B184, 1);
            {
                register const u16 *input asm("r2");
                ((const u16 *volatile)input) = (const u16 *)0x02007574;
                asm("" : : "r"(input));
                if (*input == 1)
                {
                    register u16 *selections asm("r1") = selected;
                    register u32 reply asm("r0");
                    asm("" : : "r"(selections));
                    reply = input[1];
                    asm("" : "+r"(reply));
                    selections[3] = reply;
                    ((volatile u32)reply) = input[1];
                    ((volatile u32)reply) <<= 20;
                    {
                        register u32 state_base asm("r3") = 0x16100000;
                        asm("" : : "r"(state_base));
                        ((volatile u32)reply) += state_base;
                    }
                    state = (volatile u32)reply >> 16;
                }
                else
                {
                    func_080019EC(0x3F);
                    RUN_UNCACHED(menu_layout_scripts, 0xD);
                    RUN_UNCACHED(menu_layout_scripts, 0);
                return_main_menu:
                {
                    register u32 next_state asm("r4") = 0x1001;
                    asm("" : "+r"(next_state));
                    state = next_state;
                }
                }
            }
            break;
        case 0x1610:
            func_08003E3C(5);
            func_08003DF8(10, func_08004034);
            {
                register u32 tasks asm("r2") = 0x02000034;
                register u32 resume_offset asm("r4") = 0x558;
                register u32 clear_offset asm("r6");
                register u32 ready_offset asm("r7");
                register u32 *task_word asm("r1");
                register u32 *initial_ready asm("r2");
                asm("" : : "r"(tasks), "r"(resume_offset));
                task_word = (u32 *)(tasks + resume_offset);
                *task_word = 1;
                clear_offset = 0x55C;
                asm("" : : "r"(clear_offset));
                task_word = (u32 *)(tasks + clear_offset);
                *task_word = 0;
                ready_offset = 0x568;
                asm("" : : "r"(ready_offset));
                initial_ready = (u32 *)(tasks + ready_offset);
                asm("" : : "r"(initial_ready));
                if (*initial_ready != 1)
                {
                    u32 *ready = initial_ready;
                    do
                        func_0805EE78(1);
                    while (*ready != 1);
                }
            }
            func_08003E3C(10);
            func_08003DF8(7, (void (*)(void))0x0804313D);
            do
                func_0805EE78(1);
            while (U32_AT(0x02000404) != 1);
            func_08003E3C(7);
            func_0804E37C(5);
            RUN(0x08675BEC, 1);
            {
                register u32 next_state asm("r4") = 0x16FF;
                asm("" : "+r"(next_state));
                state = next_state;
            }
            break;
        case 0x1620:
            func_08003E3C(5);
            func_08003DF8(10, func_08004034);
            {
                register u32 tasks asm("r2") = 0x02000034;
                register u32 *task_word asm("r1");
                register u32 *initial_ready asm("r2");
                {
                    register u32 resume_offset asm("r0") = 0x558;
                    asm("" : : "r"(tasks), "r"(resume_offset));
                    task_word = (u32 *)(tasks + resume_offset);
                    *task_word = 1;
                }
                {
                    register u32 clear_offset asm("r3") = 0x55C;
                    asm("" : : "r"(clear_offset));
                    task_word = (u32 *)(tasks + clear_offset);
                    *task_word = 0;
                }
                {
                    register u32 ready_offset asm("r4") = 0x568;
                    asm("" : : "r"(ready_offset));
                    initial_ready = (u32 *)(tasks + ready_offset);
                    asm("" : : "r"(initial_ready));
                }
                if (*initial_ready != 1)
                {
                    u32 *ready = initial_ready;
                    do
                        func_0805EE78(1);
                    while (*ready != 1);
                }
            }
            func_08003E3C(10);
            func_08003DF8(7, (void (*)(void))0x0804D03D);
            do
                func_0805EE78(1);
            while (U32_AT(0x02000404) != 1);
            func_08003E3C(7);
            func_0804E37C(5);
            RUN(0x08675BEC, 1);
        case 0x16FF:
        {
            register u32 bonus_level_offset asm("r7");
            register u8 *party_address asm("r4");
            register u8 *level_address asm("r1");
            u32 bonus_level;
            RUN_UNCACHED(0x0875B068, 2);
            RUN_UNCACHED(0x0875B068, 0);
            LAYOUT(0x2A);
            ((u8 *volatile)party_address) = (u8 *)&player_state;
            {
                register u32 money_offset asm("r6");
                ((volatile u32)money_offset) = 0xD28;
                asm("" : : "r"(money_offset));
                {
                    register u32 money_address asm("r0");
                    ((volatile u32)money_address) =
                        (u32)(u8 *volatile)party_address + (volatile u32)money_offset;
                    func_08001848(U32_AT((volatile u32)money_address), 7, 0);
                }
            }
            RUN_UNCACHED(0x0875B068, 1);
            RUN(0x0875B0B8, 0);
            func_08032818(0);
            RUN(0x0875B0B8, 1);
            U8_AT(U32_AT(0x02009118) + 10) = 15;
            bonus_level_offset = 0xCD2;
            asm("" : : "r"(bonus_level_offset));
            ((u8 *volatile)level_address) = party_address + bonus_level_offset;
            bonus_level = *level_address;
            if (bonus_level <= 98)
            {
                func_08001848(bonus_level, 2, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(0x0875B0B8, 2);
                {
                    register u32 bonus_points_offset asm("r0");
                    bonus_points_offset = 0xCD4;
                    asm("" : : "r"(bonus_points_offset));
                    ((u8 *volatile)party_address) += bonus_points_offset;
                    func_08001848(U32_AT(party_address), 7, 0);
                    RUN_UNCACHED(0x08675C5C, 0);
                    RUN(0x0875B0B8, 3);
                    func_08001848(get_pilot_bonus_threshold() - U32_AT(party_address), 7, 0);
                    asm("" : : "r"(party_address));
                }
            }
            else
            {
                func_08001848(99, 2, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(0x0875B0B8, 2);
                func_08001848(0, 7, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(0x0875B0B8, 3);
                func_08001848(0, 7, 0);
            }
            RUN_UNCACHED(0x0875B068, 4);
            {
                register u32 next_state asm("r4") = 0x1601;
                asm("" : "+r"(next_state));
                state = next_state;
            }
            break;
        }
        case 0x1FFF:
        {
            register u8 *party_address asm("r4");
            register const u8 **bonus_scripts asm("r5");
            register u8 *level_address asm("r1");
            u32 bonus_level;
            RUN_UNCACHED(0x0875B068, 2);
            RUN_UNCACHED(0x0875B068, 0);
            RUN_UNCACHED(menu_layout_scripts, 0x2A);
            party_address = (u8 *)&player_state;
            asm("" : "+r"(party_address));
            {
                register u32 money_offset asm("r1") = 0xD28;
                register u32 money_address asm("r0");
                asm("" : "+r"(money_offset));
                money_address = (u32)party_address + money_offset;
                asm("" : "+r"(money_address));
                func_08001848(U32_AT(money_address), 7, 0);
            }
            RUN_UNCACHED(0x0875B068, 1);
            bonus_scripts = (const u8 **)0x0875B0B8;
            asm("" : "+r"(bonus_scripts));
            script_run_table(bonus_scripts, 0);
            func_08032818(0);
            script_run_table(bonus_scripts, 1);
            U8_AT(U32_AT(0x02009118) + 10) = 15;
            {
                register u32 level_offset asm("r2") = 0xCD2;
                asm("" : "+r"(level_offset));
                level_address = party_address + level_offset;
                bonus_level = *level_address;
            }
            if (bonus_level <= 98)
            {
                func_08001848(bonus_level, 2, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                script_run_table(bonus_scripts, 2);
                {
                    register u32 points_offset asm("r3") = 0xCD4;
                    asm("" : "+r"(points_offset));
                    party_address += points_offset;
                    func_08001848(U32_AT(party_address), 7, 0);
                    RUN_UNCACHED(0x08675C5C, 0);
                    script_run_table(bonus_scripts, 3);
                    func_08001848(get_pilot_bonus_threshold() - U32_AT(party_address), 7, 0);
                    asm("" : : "r"(party_address));
                }
            }
            else
            {
                func_08001848(99, 2, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                script_run_table(bonus_scripts, 2);
                func_08001848(0, 7, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                script_run_table(bonus_scripts, 3);
                func_08001848(0, 7, 0);
            }
            goto return_main_menu;
        }
        case 0x2000:
            RUN_UNCACHED(menu_layout_scripts, 0xB);
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
            RUN(0x0875B068, 6);
            {
                register u32 initial_page asm("r4") = 0;
                register u16 *cursor asm("r6");
                asm("" : : "r"(initial_page));
                page = (volatile u32)initial_page;
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                *(u16 *volatile)cursor = (volatile u16)initial_page;
            }
            {
                register u32 next_state asm("r4") = 0x2002;
                asm("" : : "r"(next_state));
                state = (u16)next_state;
            }
            break;
        case 0x2001:
        {
            register u16 selection asm("r0");
            register u16 *cursor asm("r1");
            u8 *cursor_byte;
            RUN(0x0875B068, 6);
            page = pages[1];
            ((volatile u16)selection) = selected[1];
            {
                register u32 held1 asm("r1"), held2 asm("r2"), held3 asm("r3");
                register u32 held4 asm("r4"), held5 asm("r5"), held6 asm("r6");
                asm(""
                    : "=&l"(cursor_byte), "=r"(held1), "=r"(held2), "=r"(held3), "=r"(held4),
                      "=r"(held5), "=r"(held6)
                    : "0"((u8 *)0x02007C55), "r"(selection));
                *cursor_byte = selection;
                asm("" : : "r"(held1), "r"(held2), "r"(held3), "r"(held4), "r"(held5), "r"(held6));
            }
            ((volatile u16)selection) = (u8)(volatile u16)selection;
            ((u16 *volatile)cursor) = (u16 *)0x02007588;
            *(u16 *volatile)cursor = (volatile u16)selection;
        }
        case 0x2002:
        {
            register union RegisterHalf recovery_page_word asm("r7");
            {
                register u32 invalid asm("r2") = 0xFFFF;
                asm("" : : "r"(invalid));
                previous_page = invalid;
                previous_item_index = invalid;
            }
        recovery_inventory_refresh:
        {
            register u32 previous_page_word asm("r0");
            register s32 old_page asm("r2");
            {
                register u32 page_load asm("r3") = page;
                register u32 page_shift asm("r1") = page_load << 16;
                register u32 previous_load asm("r4");
                register u32 previous_item_load asm("r6");
                asm("" : : "r"(page_load), "r"(page_shift));
                previous_load = previous_page;
                asm("" : : "r"(previous_load));
                ((volatile u32)previous_page_word) = previous_load << 16;
                ((volatile s32)old_page) = (s32)previous_page_word >> 16;
                recovery_page_word.word = page_shift;
                asm("" : "+r"(recovery_page_word.word) : "r"(previous_page_word), "r"(old_page));
                previous_item_load = previous_item_index;
                asm("" : : "r"(previous_item_load));
                ((volatile u32)previous_item_load) <<= 16;
                previous_item_shift = previous_item_load;
            }
            if (recovery_page_word.word != previous_page_word)
            {
                register u8 *recovery_cursor asm("r10");
                register u16 recovery_row asm("r6");
                register const u8 *count asm("r4");
                register u8 *windows asm("r3");
                if (old_page != -1)
                    LAYOUT(2);
                ((const u8 *volatile)count) = &recovery_selection_count;
                asm("" : : "r"(count));
                {
                    register u8 *cursor_address asm("r1");
                    ((u8 *volatile)cursor_address) = (u8 *)0x02007C55;
                    asm("" : : "r"(cursor_address));
                    recovery_cursor = (u8 *volatile)cursor_address;
                }
            recovery_inventory_page_rows:
            {
                register u32 initial_row_shift asm("r0");
                register u32 narrowed_row asm("r2");
                register u32 initial_count asm("r3");
                recovery_row = 0;
                asm("" : : "r"(recovery_row));
                initial_row_shift = (u32)(recovery_page_word.halves[1] * 6) << 16;
                narrowed_row = initial_row_shift >> 16;
                asm("" : : "r"(narrowed_row));
                last_row = narrowed_row;
                initial_row_shift = (s32)initial_row_shift >> 16;
                initial_count = *(const u8 *volatile)count;
                asm("" : : "r"(initial_row_shift), "r"(initial_count));
                if ((s32)initial_row_shift < (s32)initial_count)
                {
                    register const u8 **recovery_names asm("r8");
                    register const u8 *quantity_base asm("r9");
                    s32 recovery_page;
                    register s32 page_carry asm("r1");
                    register u32 quantity_address asm("r7");
                    page_carry = recovery_page_word.halves[1];
                    asm("" : : "r"(page_carry));
                    {
                        register const u8 **initial_names asm("r4");
                        ((const u8 **volatile)initial_names) = (const u8 **)0x08676238;
                        asm("" : : "r"(initial_names));
                        ((const u8 **volatile)recovery_names) = initial_names;
                    }
                    quantity_address = (u32)recovery_quantities;
                    asm("" : : "r"(quantity_address));
                    ((const u8 *volatile)quantity_base) = (const u8 *)quantity_address;
                    asm("" : : "r"(page_carry));
                    recovery_page = page_carry;
                    asm("" : : "r"(recovery_names), "r"(quantity_base), "l"(recovery_page));
                recovery_inventory_row:
                {
                    register const u8 *id_address asm("r2");
                    register const u8 *row_entry asm("r4");
                    register u32 row_load asm("r1") = last_row;
                    register u32 row_word asm("r0");
                    register s32 recovery_row_index asm("r5");
                    asm("" : : "r"(row_load));
                    row_word = row_load << 16;
                    recovery_row_index = (s32)row_word >> 16;
                    asm("" : : "r"(row_word), "r"(recovery_row_index));
                    ((const u8 *volatile)id_address) = recovery_selection_ids;
                    asm("" : : "r"(id_address));
                    row_entry = (const u8 *)((u32)recovery_row_index + (u32)id_address);
                    asm("" : "+r"(row_entry));
                    script_run_table((const u8 **volatile)recovery_names,
                                     *(const u8 *volatile)row_entry);
                    func_0804D604((const u8 **volatile)recovery_names,
                                  *(const u8 *volatile)row_entry, 8);
                    LAYOUT(0x28);
                    func_08001848(
                        ((const u8 *volatile)quantity_base)[*(const u8 *volatile)row_entry], 2, 2);
                    if ((s16)recovery_row <= 4 && recovery_row_index < recovery_selection_count - 1)
                        RUN(0x08675C5C, 0);
                    {
                        register u32 shifted_row asm("r0") = (u32)recovery_row << 16;
                        register u32 increment asm("r3") = 0x10000;
                        register s32 signed_row asm("r1");
                        asm("" : : "r"(shifted_row), "r"(increment));
                        shifted_row += increment;
                        recovery_row = shifted_row >> 16;
                        signed_row = (s32)shifted_row >> 16;
                        ((const u8 *volatile)count) = &recovery_selection_count;
                        asm("" : : "r"(count));
                        if (signed_row > 5)
                            goto recovery_inventory_rows_done;
                        shifted_row = signed_row + recovery_page * 6;
                        shifted_row <<= 16;
                        {
                            register u32 narrowed_row asm("r1") = shifted_row >> 16;
                            asm("" : : "r"(narrowed_row));
                            last_row = narrowed_row;
                        }
                        ((volatile u32)shifted_row) = (s32)shifted_row >> 16;
                        {
                            register s32 count_value asm("r1") = *(const u8 *volatile)count;
                            asm("" : : "r"(count_value), "r"(shifted_row));
                            if ((s32)shifted_row < count_value)
                                goto recovery_inventory_row;
                        }
                    }
                }
                recovery_inventory_rows_done:;
                }
                {
                    register u32 row_word asm("r0") = (u32)recovery_row << 16;
                    ((volatile u32)row_word) = (s32)row_word >> 16;
                    asm("" : : "r"(row_word));
                    if ((s32)row_word != 0)
                    {
                        register u16 *cursor asm("r2");
                        register union RegisterHalf selected_row asm("r7");
                        ((u16 *volatile)cursor) = (u16 *)0x02007588;
                        ((u8 *volatile)windows) = (u8 *)text_windows;
                        asm("" : : "r"(cursor), "r"(windows));
                        selected_row.word = *(u16 *volatile)cursor;
                        asm("" : : "r"(selected_row.word));
                        if ((s32)row_word <= (u16)selected_row.halves[0])
                        {
                            register u16 clamped asm("r0") = recovery_row - 1;
                            register u8 *cursor_byte asm("r1");
                            ((u8 *volatile)cursor_byte) = (u8 *volatile)recovery_cursor;
                            asm("" : : "r"(clamped), "r"(cursor_byte));
                            *(u8 *volatile)cursor_byte = (volatile u16)clamped;
                            ((volatile u16)clamped) = (u8)(volatile u16)clamped;
                            *(u16 *volatile)cursor = (volatile u16)clamped;
                        }
                        goto recovery_inventory_page_rows_done;
                    }
                }
                {
                    register u32 page_load asm("r2") = page;
                    register u32 result asm("r0");
                    register u32 decrement asm("r3");
                    register u32 shifted asm("r1");
                    register s32 missing asm("r6");
                    asm("" : : "r"(page_load));
                    result = page_load << 16;
                    asm("" : "+r"(result));
                    decrement = 0xFFFF0000;
                    asm("" : : "r"(decrement));
                    result += decrement;
                    result >>= 16;
                    page = result;
                    shifted = result << 16;
                    result = (s32)shifted >> 16;
                    ((u8 *volatile)windows) = (u8 *)text_windows;
                    missing = -1;
                    asm("" : : "r"(shifted), "r"(windows), "r"(missing));
                    if ((s32)result == missing)
                        goto recovery_inventory_page_rows_done;
                    {
                        register u32 five asm("r0") = 5;
                        register u32 held2 asm("r2"), held4 asm("r4"), held5 asm("r5");
                        u8 *cursor_byte;
                        asm(""
                            : "=&l"(cursor_byte), "=r"(held2), "=r"(held4), "=r"(held5)
                            : "0"(recovery_cursor), "r"(five), "r"(shifted), "r"(windows),
                              "r"(missing));
                        *cursor_byte = five;
                        asm(""
                            :
                            : "r"(held2), "r"(held4), "r"(held5), "r"(five), "r"(shifted),
                              "r"(windows), "r"(missing));
                        {
                            register u16 *cursor asm("r2") = (u16 *)0x02007588;
                            asm("" : : "r"(cursor), "r"(five));
                            *cursor = five;
                        }
                    }
                    recovery_page_word.word = shifted;
                    asm("" : : "r"(recovery_page_word.word));
                }
                goto recovery_inventory_page_rows;
            }
            recovery_inventory_page_rows_done:
            {
                register u32 offset asm("r6") = 0x6B7;
                register u8 *flags asm("r2");
                register u8 zero asm("r3");
                asm("" : : "r"(offset), "r"(windows));
                flags = windows + offset;
                zero = 0;
                asm("" : : "r"(flags), "r"(zero));
                {
                    register u32 stored_zero asm("r0") = (u32)zero;
                    asm("" : : "r"(stored_zero));
                    *(u8 *volatile)flags = (u8)stored_zero;
                }
                recovery_page_word.word = page;
                asm("" : "+r"(recovery_page_word.word));
                {
                    register u32 shifted_page asm("r0") = recovery_page_word.word << 16;
                    asm("" : : "r"(shifted_page));
                    recovery_page_word.word = shifted_page;
                }
                asm("" : "+r"(recovery_page_word.word));
                if ((s32)recovery_page_word.word > 0)
                    *(u8 *volatile)flags = 1;
                {
                    register u32 row_load asm("r0") = last_row;
                    register s32 signed_row asm("r1") = (s16)row_load;
                    asm("" : : "r"(row_load), "r"(signed_row));
                    if (signed_row < *(const u8 *volatile)count - 1)
                        *(u8 *volatile)flags |= 2;
                }
                {
                    register u32 saved_page asm("r1") = (u16)recovery_page_word.halves[1];
                    asm("" : : "r"(saved_page));
                    previous_page = saved_page;
                }
            }
            }
            {
                register s32 signed_page asm("r1") = recovery_page_word.halves[1];
                register u32 current_index asm("r0");
                register u16 *cursor asm("r2");
                register union RegisterHalf detail_shift asm("r5");
                register s32 detail_index asm("r4");
                register u32 previous_load asm("r3");
                register s32 old_index asm("r0");
                asm("" : : "r"(signed_page));
                ((volatile u32)current_index) = signed_page * 6;
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                asm("" : : "r"(current_index), "r"(cursor));
                {
                    register u32 cursor_value asm("r2") = *(u16 *volatile)cursor;
                    asm("" : : "r"(cursor_value));
                    ((volatile u32)current_index) += cursor_value;
                }
                ((volatile u32)current_index) = (u16)(volatile u32)current_index;
                item_index = (volatile u32)current_index;
                detail_shift.word = current_index << 16;
                asm("" : "+r"(detail_shift.word));
                detail_index = detail_shift.halves[1];
                asm("" : : "r"(detail_index));
                previous_load = previous_item_shift;
                asm("" : : "r"(previous_load));
                old_index = (s32)previous_load >> 16;
                asm("" : : "r"(old_index));
                if (detail_index != old_index)
                {
                    register s32 empty_index asm("r6") = -1;
                    asm("" : : "r"(empty_index));
                    if (old_index != empty_index)
                        RUN_UNCACHED(menu_layout_scripts, 1);
                    RUN_UNCACHED(menu_layout_scripts, 0x1A);
                    {
                        register const u8 *ids asm("r0");
                        register u32 entry_address asm("r4") = detail_index;
                        ((const u8 *volatile)ids) = recovery_selection_ids;
                        asm("" : : "r"(ids));
                        ((volatile u32)entry_address) += (u32)ids;
                        {
                            register u32 item_id asm("r1") = *(const u8 *volatile)entry_address;
                            asm("" : : "r"(item_id));
                            RUN_UNCACHED(0x08676238, item_id);
                        }
                        RUN_UNCACHED(0x08675C5C, 0);
                        {
                            register u32 item_id asm("r1") = *(const u8 *volatile)entry_address;
                            asm("" : : "r"(item_id));
                            RUN_UNCACHED(0x08676350, item_id);
                        }
                    }
                    RUN_UNCACHED(menu_layout_scripts, 0x18);
                    RUN_UNCACHED(menu_layout_scripts, 0x1B);
                    ((volatile u32)detail_shift.word) >>= 16;
                    previous_item_index = (volatile u32)detail_shift.word;
                }
            }
            {
                register const u8 **input_layout asm("r5");
                register u16 *action_address asm("r1");
                register u32 action asm("r0");
                ((const u8 **volatile)input_layout) = menu_layout_scripts;
                script_run_table((const u8 **volatile)input_layout, 0x23);
                ((u16 *volatile)action_address) = (u16 *)0x02007574;
                asm("" : : "r"(action_address));
                action = *(u16 *volatile)action_address;
                asm("" : : "r"(action));
                if (action <= 1)
                {
                    if (action == 1)
                    {
                        register union RegisterHalf guarded_item asm("r4");
                        register u32 item_id asm("r1");
                        register u32 shifted_item asm("r0");
                        register const u8 *ids asm("r2");
                        (item_id) = item_index;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r0");
                            guard.part.high = item_id;
                            item_id = guard.part.high;
                        }
                        (shifted_item) = item_id << 16;
                        (item_id) = (s32)shifted_item >> 16;
                        (ids) = recovery_selection_ids;
                        (item_id) += (u32)ids;
                        (item_id) = *(const u8 *volatile)item_id;
                        (guarded_item.word) = shifted_item;
                        if (item_id == 6 && func_08009A2C() == 0)
                        {
                            func_080019EC(0x4F);
                            RUN_UNCACHED(0x0875B068, 9);
                            func_080019EC(0x41);
                            RUN_UNCACHED(0x0875B068, 7);
                            script_run_table((const u8 **volatile)input_layout, 0x1B);
                            goto recovery_inventory_refresh;
                        }
                        {
                            register u32 item_id asm("r0");
                            register const u8 *ids asm("r3");
                            (item_id) = guarded_item.halves[1];
                            (ids) = recovery_selection_ids;
                            (item_id) += (u32)ids;
                            (item_id) = *(const u8 *volatile)item_id;
                            if (item_id == 3)
                            {
                                func_080019EC(0x4F);
                                RUN_UNCACHED(0x0875B068, 0xA);
                                func_080019EC(0x41);
                                RUN_UNCACHED(0x0875B068, 7);
                                RUN_UNCACHED(menu_layout_scripts, 0x1B);
                                goto recovery_inventory_refresh;
                            }
                        }
                    }
                    goto recovery_inventory_input_done;
                }
                action = *(u16 *volatile)action_address;
                if (action == 2)
                    goto recovery_inventory_left;
                if (action == 4)
                    goto recovery_inventory_right;
                goto recovery_inventory_refresh;
            }
        recovery_inventory_left:
        {
            register u32 next_page asm("r0");
            register u32 loaded_page asm("r4") = page;
            register s32 signed_page asm("r4");
            {
                register union
                {
                    unsigned long long whole;
                    struct
                    {
                        u32 low, high;
                    } part;
                } guard asm("r3");
                guard.part.high = loaded_page;
                loaded_page = guard.part.high;
            }
            ((volatile u32)next_page) = loaded_page << 16;
            ((volatile s32)signed_page) = (s32)(volatile u32)next_page >> 16;
            if (signed_page <= 0)
                goto recovery_inventory_refresh;
            func_080019EC(0x40);
            ((volatile u32)next_page) = (signed_page - 1) << 16;
            goto recovery_inventory_save_page;
        recovery_inventory_right:
        {
            register u32 row_load asm("r6") = last_row;
            register s32 signed_row asm("r1");
            register s32 count_value asm("r0");
            {
                register union
                {
                    unsigned long long whole;
                    struct
                    {
                        u32 low, high;
                    } part;
                } guard asm("r5");
                guard.part.high = row_load;
                row_load = guard.part.high;
            }
            ((volatile s32)signed_row) = (s16)row_load;
            ((volatile s32)count_value) = recovery_selection_count;
            ((volatile s32)count_value) -= 1;
            if (signed_row >= count_value)
                goto recovery_inventory_refresh;
            func_080019EC(0x40);
            {
                register u32 page_load asm("r7") = page;
                register u32 increment asm("r1");
                ((volatile u32)next_page) = page_load << 16;
                {
                    register union
                    {
                        unsigned long long whole;
                        struct
                        {
                            u32 low, high;
                        } part;
                    } guard asm("r0");
                    guard.part.low = next_page;
                    next_page = guard.part.low;
                }
                ((volatile u32)increment) = 0x10000;
                {
                    register union
                    {
                        unsigned long long whole;
                        struct
                        {
                            u32 low, high;
                        } part;
                    } guard asm("r0");
                    guard.part.high = increment;
                    increment = guard.part.high;
                }
                ((volatile u32)next_page) += (volatile u32)increment;
            }
        }
        recovery_inventory_save_page:
            ((volatile u32)next_page) >>= 16;
            page = (volatile u32)next_page;
            goto recovery_inventory_refresh;
        }
        }
        recovery_inventory_input_done:
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
            asm("" : "+r"(recovery_page_word.word));
            {
                register const u16 *exit_action asm("r4");
                ((const u16 *volatile)exit_action) = (const u16 *)0x02007574;
                asm("" : : "r"(exit_action));
                if (*(const u16 *volatile)exit_action == 0)
                    goto recovery_inventory_cancel;
                {
                    register s32 signed_page asm("r0") = (volatile s16)recovery_page_word.halves[1];
                    register s32 empty_page asm("r2") = -1;
                    asm("" : : "r"(signed_page), "r"(empty_page));
                    if (signed_page == empty_page)
                    {
                    recovery_inventory_cancel:
                        func_080019EC(0x3F);
                        state = 1;
                        break;
                    }
                }
                {
                    register u16 *saved_selections asm("r1") = selected;
                    register u32 reply asm("r0");
                    asm("" : : "r"(saved_selections));
                    reply = *(const u16 *volatile)(exit_action + 1);
                    asm("" : : "r"(reply));
                    saved_selections[1] = reply;
                }
                {
                    register u16 *saved_pages asm("r0") = pages;
                    register u16 saved_page asm("r3");
                    asm("" : : "r"(saved_pages));
                    {
                        register const u16 *source asm("r3") = (const u16 *)menu_stack;
                        asm("" : : "r"(source));
                        saved_page = source[14];
                    }
                    asm("" : : "r"(saved_page));
                    saved_pages[1] = saved_page;
                }
                {
                    register const u8 *ids asm("r1");
                    register u32 selected_item asm("r6");
                    register u32 item_id asm("r0");
                    ((const u8 *volatile)ids) = recovery_selection_ids;
                    asm("" : : "r"(ids));
                    selected_item = item_index;
                    asm("" : : "r"(selected_item));
                    ((volatile u32)item_id) = (s16)selected_item;
                    ((volatile u32)item_id) += (u32)(const u8 *volatile)ids;
                    ((volatile u32)item_id) = *(const u8 *volatile)(volatile u32)item_id;
                    if (item_id == 6)
                    {
                        RUN_UNCACHED(0x0875B068, 8);
                        RUN_UNCACHED(0x0875B068, 0x11);
                        if (*(const u16 *volatile)exit_action == 1 &&
                            *(const u16 *volatile)(exit_action + 1) == 0)
                        {
                            register u32 next_state asm("r4");
                            {
                                u8 *quantity;
                                register u32 amount asm("r0");
                                register u32 held1 asm("r1"), held2 asm("r2"), held3 asm("r3");
                                register u32 held4 asm("r4"), held5 asm("r5"), held6 asm("r6");
                                asm("" : "=r"(amount));
                                asm(""
                                    : "=&l"(quantity), "=r"(held1), "=r"(held2), "=r"(held3),
                                      "=r"(held4), "=r"(held5), "=r"(held6)
                                    : "0"((u8 *)0x02003E67), "r"(amount));
                                amount = *quantity;
                                amount -= 1;
                                *quantity = amount;
                                asm(""
                                    :
                                    : "r"(held1), "r"(held2), "r"(held3), "r"(held4), "r"(held5),
                                      "r"(held6));
                            }
                            next_state = 0xFFFE;
                            asm("" : : "r"(next_state));
                            state = (u16)next_state;
                            break;
                        }
                        if (ACTION == 0)
                            func_080019EC(0x3F);
                        RUN_UNCACHED(menu_layout_scripts, 0);
                        {
                            register u32 next_state asm("r4") = 0x2001;
                            asm("" : : "r"(next_state));
                            state = (u16)next_state;
                        }
                    }
                    else
                    {
                        register u32 next_state asm("r4") = 0x2100;
                        asm("" : : "r"(next_state));
                        state = (u16)next_state;
                    }
                }
            }
            break;
        }
        case 0x2100:
        {
            register const u8 **recovery_layout asm("r8");
            RUN_UNCACHED(0x0875B18C, 0);
            {
                register u32 initial_page asm("r0") = 0;
                register u32 invalid_index asm("r1");
                register u16 *cursor asm("r2");
                asm("" : : "r"(initial_page));
                page = (volatile u32)initial_page;
                invalid_index = 0xFFFF;
                asm("" : : "r"(invalid_index));
                previous_index = invalid_index;
                previous_page = invalid_index;
                previous_zoid = invalid_index;
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                asm("" : : "r"(cursor));
                *(u16 *volatile)cursor = (volatile u16)initial_page;
            }
            {
                register u32 item_load asm("r3") = item_index;
                register u32 item_shift asm("r4");
                register const u8 **initial_layout asm("r6");
                register const u8 *ids asm("r1");
                register u32 item_address asm("r0");
                asm("" : : "r"(item_load));
                item_shift = item_load << 16;
                asm("" : : "r"(item_shift));
                ((const u8 **volatile)initial_layout) = menu_layout_scripts;
                asm("" : : "r"(initial_layout));
                recovery_layout = initial_layout;
                ((const u8 *volatile)ids) = recovery_selection_ids;
                {
                    register union
                    {
                        unsigned long long whole;
                        struct
                        {
                            u32 low, high;
                        } part;
                    } guard asm("r0");
                    guard.part.high = (u32)ids;
                    ids = (const u8 *)guard.part.high;
                }
                ((volatile u32)item_address) = (s32)item_shift >> 16;
                ((volatile u32)item_address) += (u32)(const u8 *volatile)ids;
                asm("" : : "r"(item_address));
                recovery_item = (u8 *)(volatile u32)item_address;
            }
        refresh_recovery_target:
            script_run_table((const u8 **volatile)recovery_layout, 0x19);
            {
                const u8 *item;
                register u32 item_id asm("r1");
                register u32 held0 asm("r0"), held2 asm("r2"), held3 asm("r3");
                register u32 held4 asm("r4"), held5 asm("r5"), held6 asm("r6");
                asm("" : "=r"(item_id));
                asm(""
                    : "=&l"(item), "=r"(held0), "=r"(held2), "=r"(held3), "=r"(held4), "=r"(held5),
                      "=r"(held6)
                    : "0"(recovery_item), "r"(item_id));
                item_id = *item;
                asm(""
                    :
                    : "l"(item), "r"(item_id), "r"(held0), "r"(held2), "r"(held3), "r"(held4),
                      "r"(held5), "r"(held6));
                RUN(0x08676238, item_id);
            }
            RUN_UNCACHED(0x0875B18C, 6);
            script_run_table((const u8 **volatile)recovery_layout, 0x1C);
        recovery_target_list_refresh:
        {
            register union RegisterHalf recovery_page asm("r7");
            register union RegisterHalf recovery_previous asm("r10");
            register s32 current_page asm("r4");
            register s32 old_page asm("r0");
            {
                register u32 page_load asm("r0") = page;
                register u32 page_shift asm("r1");
                register u32 previous_load asm("r2");
                register u32 index_load asm("r3");
                asm("" : : "r"(page_load));
                page_shift = page_load << 16;
                current_page = (s32)page_shift >> 16;
                asm("" : : "r"(page_shift), "r"(current_page));
                previous_load = previous_page;
                asm("" : : "r"(previous_load));
                ((volatile s32)old_page) = previous_load << 16;
                ((volatile s32)old_page) >>= 16;
                recovery_page.word = page_shift;
                asm("" : "+r"(recovery_page.word));
                index_load = previous_index;
                asm("" : : "r"(index_load));
                ((volatile u32)index_load) <<= 16;
                recovery_previous.word = index_load;
                asm("" : "+r"(recovery_previous.word));
            }
            if (current_page != old_page)
            {
                register u16 recovery_target_row asm("r6");
                register s32 page_rows asm("r5");
                register u32 calculated_rows asm("r2");
                register const u8 *count_address asm("r4");
                register const u8 *row_count asm("r3");
                register u8 *windows asm("r3");
                {
                    register s32 empty_page asm("r6") = -1;
                    asm("" : : "r"(empty_page));
                    if (old_page != empty_page)
                        RUN_UNCACHED(menu_layout_scripts, 3);
                }
                recovery_target_row = 0;
                asm("" : : "r"(recovery_target_row));
                {
                    register u32 tripled_page asm("r0") = current_page * 3;
                    register u32 narrowed_row asm("r1");
                    register const u8 *initial_count asm("r1");
                    register s32 count_value asm("r3");
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r0");
                        guard.part.low = (u32)tripled_page;
                        tripled_page = (u32)guard.part.low;
                    }
                    calculated_rows = tripled_page << 1;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r1");
                        guard.part.high = (u32)calculated_rows;
                        calculated_rows = (u32)guard.part.high;
                    }
                    ((volatile u32)tripled_page) <<= 17;
                    narrowed_row = tripled_page >> 16;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r0");
                        guard.part.high = (u32)narrowed_row;
                        narrowed_row = (u32)guard.part.high;
                    }
                    last_row = narrowed_row;
                    ((volatile u32)tripled_page) = (s32)tripled_page >> 16;
                    ((const u8 *volatile)initial_count) = &pilot_selection_count;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r0");
                        guard.part.high = (u32)initial_count;
                        initial_count = (const u8 *)guard.part.high;
                    }
                    count_address = initial_count;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r3");
                        guard.part.high = (u32)count_address;
                        count_address = (const u8 *)guard.part.high;
                    }
                    count_value = *(const u8 *volatile)count_address;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r2");
                        guard.part.high = (u32)count_value;
                        count_value = (s32)guard.part.high;
                    }
                    if ((s32)tripled_page >= count_value)
                        goto recovery_target_rows_done;
                }
                row_count = count_address;
                asm("" : : "r"(row_count));
                page_rows = calculated_rows;
                {
                    register union
                    {
                        unsigned long long whole;
                        struct
                        {
                            u32 low, high;
                        } part;
                    } guard asm("r4");
                    guard.part.high = (u32)page_rows;
                    page_rows = (s32)guard.part.high;
                }
                {
                recovery_target_row_body:
                {
                    register const u8 *ids asm("r1");
                    register u32 row_load asm("r4");
                    register u32 row_shift asm("r0");
                    register s32 row_index asm("r4");
                    ((const u8 *volatile)ids) = pilot_selection_ids;
                    asm("" : : "r"(ids));
                    row_load = last_row;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r3");
                        guard.part.high = (u32)row_load;
                        row_load = (u32)guard.part.high;
                    }
                    row_shift = row_load << 16;
                    row_index = (s32)row_shift >> 16;
                    asm("" : : "r"(row_shift), "r"(row_index));
                    ids = (const u8 *)((u32)row_index + (u32)ids);
                    {
                        register u32 pilot_id asm("r0") = *(const u8 *volatile)ids;
                        register s32 signed_row asm("r0");
                        asm("" : : "r"(pilot_id), "r"(row_count));
                        call_scratch.count = row_count;
                        func_08032818(pilot_id);
                        signed_row = (s16)recovery_target_row;
                        asm("" : : "r"(signed_row));
                        row_count = call_scratch.count;
                        asm("" : : "r"(row_count));
                        if (signed_row <= 4 && row_index < *(const u8 *volatile)row_count - 1)
                        {
                            RUN(0x08675C5C, 0);
                            row_count = call_scratch.count;
                            asm("" : : "r"(row_count));
                        }
                    }
                    {
                        register u32 shifted_row asm("r0") = (u32)recovery_target_row << 16;
                        register u32 increment asm("r6");
                        asm("" : : "r"(shifted_row));
                        increment = 0x10000;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r5");
                            guard.part.high = (u32)increment;
                            increment = (u32)guard.part.high;
                        }
                        ((volatile u32)shifted_row) += increment;
                        recovery_target_row = shifted_row >> 16;
                        ((volatile u32)shifted_row) = (s32)shifted_row >> 16;
                        ((const u8 *volatile)count_address) = &pilot_selection_count;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r3");
                            guard.part.high = (u32)count_address;
                            count_address = (const u8 *)guard.part.high;
                        }
                        if ((s32)shifted_row > 5)
                            goto recovery_target_rows_done;
                        ((volatile u32)shifted_row) += (volatile s32)page_rows;
                        ((volatile u32)shifted_row) <<= 16;
                        {
                            register u32 narrowed_row asm("r1") = shifted_row >> 16;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.high = (u32)narrowed_row;
                                narrowed_row = (u32)guard.part.high;
                            }
                            last_row = narrowed_row;
                        }
                        ((volatile u32)shifted_row) = (s32)shifted_row >> 16;
                        {
                            register s32 count_value asm("r2") = *(const u8 *volatile)row_count;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r1");
                                guard.part.high = (u32)count_value;
                                count_value = (s32)guard.part.high;
                            }
                            if ((s32)shifted_row < count_value)
                                goto recovery_target_row_body;
                        }
                    }
                }
                }
            recovery_target_rows_done:
            {
                register u32 row_word asm("r0") = (u32)recovery_target_row << 16;
                register u16 *cursor asm("r2");
                register s32 cursor_value asm("r1");
                ((volatile u32)row_word) = (s32)row_word >> 16;
                asm("" : : "r"(row_word));
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                asm("" : : "r"(cursor));
                ((u8 *volatile)windows) = (u8 *)text_windows;
                asm("" : : "r"(windows));
                cursor_value = *(u16 *volatile)cursor;
                asm("" : : "r"(cursor_value));
                if ((s32)row_word <= cursor_value)
                {
                    register u16 clamped asm("r0") = recovery_target_row - 1;
                    register u8 *cursor_byte asm("r6");
                    asm("" : : "r"(clamped));
                    ((u8 *volatile)cursor_byte) = saved_selection;
                    asm("" : : "r"(cursor_byte));
                    *(u8 *volatile)cursor_byte = (volatile u16)clamped;
                    ((volatile u16)clamped) = (u8)(volatile u16)clamped;
                    *(u16 *volatile)cursor = (volatile u16)clamped;
                }
            }
                asm("" : "+r"(recovery_page.word));
                {
                    register u32 offset asm("r0") = 0xA0B;
                    register u8 *flags asm("r2");
                    register u8 zero asm("r3");
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r0");
                        guard.part.low = (u32)offset;
                        offset = (u32)guard.part.low;
                    }
                    flags = windows + offset;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r1");
                        guard.part.high = (u32)flags;
                        flags = (u8 *)guard.part.high;
                    }
                    zero = 0;
                    asm("" : : "r"(zero));
                    {
                        register u32 stored_zero asm("r0") = (u32)zero;
                        asm("" : : "r"(stored_zero));
                        *(u8 *volatile)flags = stored_zero;
                    }
                    if ((s32)recovery_page.word > 0)
                        *(u8 *volatile)flags = 1;
                    {
                        register u32 row_load asm("r6") = last_row;
                        register s32 signed_row asm("r1") = (s16)row_load;
                        asm("" : : "r"(row_load), "r"(signed_row));
                        if (signed_row < *(const u8 *volatile)(const u8 *volatile)count_address - 1)
                        {
                            register u32 old_flags asm("r1") = *(u8 *volatile)flags;
                            register u32 right_flag asm("r0") = 2;
                            asm("" : : "r"(old_flags), "r"(right_flag));
                            ((volatile u32)old_flags) |= right_flag;
                            *(u8 *volatile)flags = (volatile u32)old_flags;
                        }
                    }
                    {
                        register u32 saved_page asm("r0") = recovery_page.word >> 16;
                        asm("" : : "r"(saved_page));
                        previous_page = saved_page;
                    }
                }
            }
            {
                register s32 signed_page asm("r1") = recovery_page.halves[1];
                register u32 selected_shift asm("r0");
                register s32 signed_selection asm("r1");
                asm("" : : "r"(signed_page));
                ((volatile u32)selected_shift) = signed_page * 6;
                asm("" : : "r"(selected_shift));
                {
                    register u16 *cursor asm("r1");
                    register u32 cursor_value asm("r1");
                    ((u16 *volatile)cursor) = (u16 *)0x02007588;
                    asm("" : : "r"(cursor));
                    cursor_value = *(u16 *volatile)cursor;
                    asm("" : : "r"(cursor_value));
                    ((volatile u32)selected_shift) += cursor_value;
                }
                ((volatile u32)selected_shift) <<= 16;
                {
                    register u32 narrowed_selection asm("r2") = selected_shift >> 16;
                    asm("" : : "r"(narrowed_selection));
                    selected_index = narrowed_selection;
                }
                signed_selection = (s32)selected_shift >> 16;
                asm("" : : "r"(signed_selection));
                if (selected_shift != recovery_previous.word)
                {
                    {
                        u32 party_address;
                        register u32 pilot_address asm("r0");
                        register u32 zoid_address asm("r5");
                        ((volatile u32)party_address) = (u32)&player_state;
                        asm("" : "+l"(party_address));
                        pilot_address = (u32)pilot_selection_ids;
                        asm("" : : "r"(pilot_address));
                        ((volatile u32)pilot_address) = signed_selection + pilot_address;
                        ((volatile u32)pilot_address) = U8_AT((volatile u32)pilot_address);
                        ((volatile u32)pilot_address) <<= 2;
                        ((volatile u32)pilot_address) += party_address;
                        {
                            register u32 slot_offset asm("r3") = 0x34A6;
                            asm("" : : "r"(slot_offset));
                            ((volatile u32)pilot_address) += slot_offset;
                        }
                        ((volatile u32)pilot_address) = U8_AT((volatile u32)pilot_address);
                        selected_zoid = pilot_address;
                        zoid_address = pilot_address;
                        asm("" : : "r"(zoid_address));
                        if (zoid_address != 255)
                        {
                            register u32 zoid_offset asm("r4");
                            register u8 *zoid_type asm("r6");
                            {
                                register u16 *flags asm("r4") = (u16 *)0x03004C44;
                                register u32 old_flags asm("r1");
                                register u32 mask asm("r6");
                                register u32 mask_copy asm("r0");
                                asm("" : : "r"(flags));
                                old_flags = *(u16 *volatile)flags;
                                asm("" : : "r"(old_flags));
                                mask = 0x7FFF;
                                asm("" : : "r"(mask));
                                mask_copy = mask;
                                asm("" : : "r"(mask_copy));
                                ((volatile u32)old_flags) &= mask_copy;
                                *(u16 *volatile)flags = old_flags;
                            }
                            script_run_table((const u8 **volatile)recovery_layout, 1);
                            script_run_table((const u8 **volatile)recovery_layout, 0x1A);
                            zoid_offset = (zoid_address * 7) << 3;
                            asm("" : : "r"(zoid_offset));
                            ((volatile u32)zoid_address) = zoid_offset + party_address;
                            {
                                register u32 type_offset asm("r0");
                                ((volatile u32)type_offset) = 0xD32;
                                asm("" : : "r"(type_offset));
                                zoid_type = (u8 *)(zoid_address + (volatile u32)type_offset);
                                asm("" : : "r"(zoid_type));
                            }
                            func_08032800(*(u8 *volatile)zoid_type);
                            RUN_UNCACHED(0x08675C5C, 0);
                            RUN_UNCACHED(0x0875B18C, 2);
                            script_run_table((const u8 **volatile)recovery_layout, 0x2A);
                            {
                                register u32 field_offset asm("r1") = 0xD2C;
                                register u32 address asm("r0");
                                asm("" : : "r"(field_offset));
                                ((volatile u32)address) = party_address + field_offset;
                                ((volatile u32)address) = zoid_offset + address;
                                render_player_zoid_hp((PlayerZoid *)address);
                            }
                            RUN_UNCACHED(0x08675C5C, 0);
                            RUN_UNCACHED(0x0875B18C, 0xA);
                            {
                                register u32 field_offset asm("r2") = 0xD54;
                                register u32 address asm("r0");
                                asm("" : : "r"(field_offset));
                                ((volatile u32)address) = party_address + field_offset;
                                ((volatile u32)address) = zoid_offset + address;
                                func_08001848(U32_AT(address), 4, 0);
                            }
                            RUN_UNCACHED(0x08675C5C, 0);
                            RUN_UNCACHED(0x0875B18C, 3);
                            {
                                register u32 field_offset asm("r3") = 0xD38;
                                register u32 address asm("r0");
                                asm("" : : "r"(field_offset));
                                ((volatile u32)address) = party_address + field_offset;
                                ((volatile u32)address) = zoid_offset + address;
                                func_08001848(U32_AT(address), 5, 0);
                            }
                            RUN_UNCACHED(0x08675C5C, 0);
                            RUN_UNCACHED(0x0875B18C, 0xA);
                            {
                                register u32 field_offset asm("r1") = 0xD58;
                                register u32 address asm("r0");
                                asm("" : : "r"(field_offset));
                                ((volatile u32)address) = party_address + field_offset;
                                ((volatile u32)zoid_offset) += address;
                                func_08001848(U32_AT(zoid_offset), 4, 0);
                            }
                            RUN_UNCACHED(0x08675C5C, 0);
                            RUN_UNCACHED(0x0875B18C, 4);
                            {
                                register u32 field_offset asm("r2") = 0xD5C;
                                register u32 address asm("r0");
                                asm("" : : "r"(field_offset));
                                ((volatile u32)address) = zoid_address + field_offset;
                                {
                                    register u32 held1 asm("r1"), held2 asm("r2");
                                    register s32 field_value asm("r0");
                                    asm("" : "=r"(held1), "=r"(held2));
                                    field_value = S16_AT(address);
                                    asm("" : : "r"(held1), "r"(held2), "r"(field_value));
                                    func_08001848(field_value, 4, 0);
                                }
                            }
                            RUN_UNCACHED(0x0875B18C, 5);
                            {
                                register u32 field_offset asm("r4") = 0xD5E;
                                asm("" : : "r"(field_offset));
                                ((volatile u32)zoid_address) += field_offset;
                            }
                            {
                                register u32 held1 asm("r1"), held2 asm("r2"), held3 asm("r3"),
                                    held4 asm("r4");
                                register s32 field_value asm("r0");
                                asm("" : "=r"(held1), "=r"(held2), "=r"(held3), "=r"(held4));
                                field_value = S16_AT(zoid_address);
                                asm(""
                                    :
                                    : "r"(held1), "r"(held2), "r"(held3), "r"(held4),
                                      "r"(field_value), "r"(zoid_type));
                                func_08001848(field_value, 3, 0);
                            }
                            script_run_table((const u8 **volatile)recovery_layout, 0x27);
                            func_0804D654(*(u16 *volatile)zoid_type, 0x28, 0x58);
                            script_run_table((const u8 **volatile)recovery_layout, 0x18);
                        }
                        else
                        {
                            register u32 prior_zoid asm("r1") = previous_zoid;
                            register s32 signed_prior asm("r0") = (s16)prior_zoid;
                            asm("" : : "r"(prior_zoid), "r"(signed_prior));
                            if (signed_prior != 255)
                            {
                                register u16 *flags asm("r2") = (u16 *)0x03004C44;
                                register u32 old_flags asm("r1");
                                register u32 mask asm("r3");
                                register u32 mask_copy asm("r0");
                                asm("" : : "r"(flags));
                                old_flags = *(u16 *volatile)flags;
                                asm("" : : "r"(old_flags));
                                mask = 0x7FFF;
                                asm("" : : "r"(mask));
                                mask_copy = mask;
                                asm("" : : "r"(mask_copy));
                                ((volatile u32)old_flags) &= mask_copy;
                                *(u16 *volatile)flags = old_flags;
                                script_run_table((const u8 **volatile)recovery_layout, 1);
                                script_run_table((const u8 **volatile)recovery_layout, 0x1A);
                                RUN_UNCACHED(0x0875B18C, 1);
                                script_run_table((const u8 **volatile)recovery_layout, 0x18);
                            }
                        }
                        RUN_UNCACHED(menu_layout_scripts, 0x1C);
                        {
                            register u32 saved_zoid asm("r4") = selected_zoid;
                            register u32 narrowed asm("r0");
                            asm("" : : "r"(saved_zoid));
                            narrowed = (u16)saved_zoid;
                            asm("" : : "r"(narrowed));
                            previous_zoid = narrowed;
                        }
                        {
                            register u32 saved_index asm("r6") = selected_index;
                            register u32 narrowed asm("r0");
                            asm("" : : "r"(saved_index));
                            narrowed = (u16)saved_index;
                            asm("" : : "r"(narrowed));
                            previous_index = narrowed;
                        }
                    }
                }
                else
                {
                    script_run_table((const u8 **volatile)recovery_layout, 0x10);
                    script_run_table((const u8 **volatile)recovery_layout, 0x1C);
                }
            }
            RUN_UNCACHED(menu_layout_scripts, 0x23);
            {
                register const u16 *action_address asm("r1") = (const u16 *)0x02007574;
                register u32 action asm("r0");
                asm("" : : "r"(action_address));
                action = *(const u16 *volatile)action_address;
                asm("" : : "r"(action));
                if (action <= 1)
                    goto recovery_target_accept;
                if (action == 2)
                    goto recovery_target_page_left;
                if (action == 4)
                    goto recovery_target_page_right;
                goto recovery_target_list_refresh;
            }
        recovery_target_page_left:
        {
            register u32 page_load asm("r7") = page;
            register s32 signed_page asm("r4");
            register u32 next_page asm("r0");
            asm("" : : "r"(page_load));
            ((volatile u32)next_page) = page_load << 16;
            ((volatile s32)signed_page) = (s32)(volatile u32)next_page >> 16;
            if (signed_page <= 0)
                goto recovery_target_list_refresh;
            func_080019EC(0x40);
            ((volatile u32)next_page) = (signed_page - 1) << 16;
            goto recovery_target_page_save;
        recovery_target_page_right:
        {
            register u32 row_load asm("r0") = last_row;
            register s32 signed_row asm("r1");
            register s32 count asm("r0");
            asm("" : : "r"(row_load));
            ((volatile s32)signed_row) = row_load << 16;
            ((volatile s32)signed_row) >>= 16;
            ((volatile s32)count) = pilot_selection_count;
            ((volatile s32)count) -= 1;
            if (signed_row >= count)
                goto recovery_target_list_refresh;
            func_080019EC(0x40);
            {
                register u32 page_load asm("r1") = page;
                register u32 increment asm("r2");
                asm("" : : "r"(page_load));
                ((volatile u32)next_page) = page_load << 16;
                asm("" : : "r"(next_page));
                increment = 0x10000;
                asm("" : : "r"(increment));
                ((volatile u32)next_page) += increment;
            }
        }
        recovery_target_page_save:
            ((volatile u32)next_page) >>= 16;
            page = next_page;
            goto recovery_target_list_refresh;
        }
        recovery_target_accept:
        {
            if (ACTION == 1)
            {
                u32 healing_party;
                register u32 zoid_offset asm("r6");
                register u32 zoid_address asm("r4");
                register u32 zoid_base asm("r9");
                register u8 *zoid_type asm("r5");
                register s32 target_slot asm("r1");
                {
                    register u32 slot_load asm("r3") = selected_zoid;
                    register u32 slot_shift asm("r0");
                    asm("" : : "r"(slot_load));
                    ((volatile u32)slot_shift) = slot_load << 16;
                    ((volatile s32)target_slot) = (s32)slot_shift >> 16;
                }
                if (target_slot == 255)
                {
                    func_080019EC(0x4F);
                    RUN_UNCACHED(0x0875B18C, 7);
                    script_run_table((const u8 **volatile)recovery_layout, 0x25);
                    func_080019EC(0x41);
                    script_run_table((const u8 **volatile)recovery_layout, 0);
                    goto refresh_recovery_target;
                }
                healing_party = (u32)&player_state;
                asm("" : "+l"(healing_party));
                {
                    register u32 multiplied asm("r0");
                    ((volatile u32)multiplied) = target_slot * 7;
                    ((volatile u32)zoid_offset) = multiplied << 3;
                }
                ((volatile u32)zoid_address) = zoid_offset + healing_party;
                asm("" : : "r"(zoid_address));
                zoid_base = zoid_address;
                {
                    register u32 flags_address asm("r0") = 0xD2C;
                    register u32 mask asm("r2");
                    register u32 mask_copy asm("r1");
                    ((volatile u32)flags_address) += zoid_base;
                    ((volatile u32)flags_address) = U16_AT(flags_address);
                    ((volatile u32)mask) = 0x800;
                    asm("" : : "r"(mask));
                    mask_copy = mask;
                    asm("" : : "r"(mask_copy));
                    ((volatile u32)flags_address) &= mask_copy;
                    if (flags_address != 0)
                    {
                        func_080019EC(0x4F);
                        RUN_UNCACHED(0x0875B18C, 9);
                        script_run_table((const u8 **volatile)recovery_layout, 0x25);
                        func_080019EC(0x41);
                        script_run_table((const u8 **volatile)recovery_layout, 0);
                        goto refresh_recovery_target;
                    }
                }
                {
                    register u32 sound_side asm("r2");
                    register u8 *item asm("r3");
                    register u32 item_id asm("r0");
                    register u32 unit_offset asm("r1");
                    func_080019EC(0x50);
                    asm("" : "=r"(sound_side));
                    item = recovery_item;
                    item_id = *item;
                    asm("" : : "r"(item_id));
                    unit_offset = 0xD2C;
                    asm("" : : "r"(unit_offset));
                    ((volatile u32)zoid_address) = healing_party + unit_offset;
                    ((volatile u32)zoid_address) = zoid_offset + zoid_address;
                    func_080394EC(item_id, (PlayerZoid *)zoid_address, sound_side, (u32)item);
                }
                {
                    register u32 quantities_offset asm("r2") = 0x3305;
                    register u32 quantity_address asm("r1");
                    register u32 item_value asm("r3");
                    register u32 quantity asm("r0");
                    asm("" : : "r"(quantities_offset));
                    ((volatile u32)quantity_address) = healing_party + quantities_offset;
                    item_value = (u32)recovery_item;
                    asm("" : "+r"(item_value));
                    ((volatile u32)item_value) = U8_AT(item_value);
                    ((volatile u32)quantity_address) += item_value;
                    ((volatile u32)quantity) = U8_AT(quantity_address);
                    ((volatile u32)quantity) -= 1;
                    U8_AT(quantity_address) = quantity;
                }
                {
                    register u16 *flags_address asm("r1") = (u16 *)0x03004C44;
                    register u32 flags asm("r0");
                    register u32 mask asm("r2");
                    asm("" : : "r"(flags_address));
                    flags = *(u16 *volatile)flags_address;
                    asm("" : : "r"(flags));
                    mask = 0x7FFF;
                    asm("" : : "r"(mask));
                    {
                        register u32 mask_copy asm("r1") = mask;
                        register u16 *flags_store asm("r3");
                        asm("" : : "r"(mask_copy));
                        ((volatile u32)flags) &= mask_copy;
                        ((u16 *volatile)flags_store) = (u16 *)0x03004C44;
                        *(u16 *volatile)flags_store = flags;
                    }
                }
                script_run_table((const u8 **volatile)recovery_layout, 1);
                script_run_table((const u8 **volatile)recovery_layout, 0x1A);
                ((u8 *volatile)zoid_type) = (u8 *)0xD32;
                ((u8 *volatile)zoid_type) += zoid_base;
                func_08032800(*(u8 *volatile)zoid_type);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN_UNCACHED(0x0875B18C, 2);
                script_run_table((const u8 **volatile)recovery_layout, 0x2A);
                render_player_zoid_hp((PlayerZoid *)(volatile u32)zoid_address);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN_UNCACHED(0x0875B18C, 0xA);
                {
                    register u32 field_offset asm("r4") = 0xD54;
                    register u32 address asm("r0");
                    asm("" : : "r"(field_offset));
                    ((volatile u32)address) = healing_party + field_offset;
                    ((volatile u32)address) = zoid_offset + address;
                    func_08001848(U32_AT(address), 4, 0);
                }
                RUN_UNCACHED(0x08675C5C, 0);
                RUN_UNCACHED(0x0875B18C, 3);
                {
                    register u32 field_offset asm("r1") = 0xD38;
                    register u32 address asm("r0");
                    asm("" : : "r"(field_offset));
                    ((volatile u32)address) = healing_party + field_offset;
                    ((volatile u32)address) = zoid_offset + address;
                    func_08001848(U32_AT(address), 5, 0);
                }
                RUN_UNCACHED(0x08675C5C, 0);
                RUN_UNCACHED(0x0875B18C, 0xA);
                {
                    register u32 field_offset asm("r2") = 0xD58;
                    register u32 address asm("r0");
                    asm("" : : "r"(field_offset));
                    ((volatile u32)address) = healing_party + field_offset;
                    ((volatile u32)address) = zoid_offset + address;
                    func_08001848(U32_AT(address), 4, 0);
                }
                RUN_UNCACHED(0x08675C5C, 0);
                RUN_UNCACHED(0x0875B18C, 4);
                {
                    register u32 address asm("r0");
                    ((volatile u32)address) = 0xD5C;
                    ((volatile u32)address) += zoid_base;
                    {
                        register u32 held1 asm("r1"), held2 asm("r2");
                        register s32 field_value asm("r0");
                        asm("" : "=r"(held1), "=r"(held2));
                        field_value = S16_AT(address);
                        asm("" : : "r"(held1), "r"(held2), "r"(field_value));
                        func_08001848(field_value, 4, 0);
                    }
                }
                RUN_UNCACHED(0x0875B18C, 5);
                {
                    register u32 address asm("r0");
                    ((volatile u32)address) = 0xD5E;
                    ((volatile u32)address) += zoid_base;
                    {
                        register u32 held1 asm("r1"), held2 asm("r2"), held3 asm("r3");
                        register s32 field_value asm("r0");
                        asm("" : "=r"(held1), "=r"(held2), "=r"(held3));
                        field_value = S16_AT(address);
                        asm("" : : "r"(held1), "r"(held2), "r"(held3), "r"(field_value));
                        func_08001848(field_value, 3, 0);
                    }
                }
                script_run_table((const u8 **volatile)recovery_layout, 0x27);
                func_0804D654(*(u16 *volatile)zoid_type, 0x28, 0x58);
                script_run_table((const u8 **volatile)recovery_layout, 0x18);
                script_run_table((const u8 **volatile)recovery_layout, 0);
                script_run_table((const u8 **volatile)recovery_layout, 0x19);
                {
                    register u8 *completion_item asm("r6") = recovery_item;
                    register u32 item_id asm("r1");
                    asm("" : : "r"(completion_item));
                    item_id = *(u8 *volatile)completion_item;
                    asm("" : : "r"(item_id));
                    RUN_UNCACHED(0x08676238, item_id);
                    RUN_UNCACHED(0x0875B18C, 8);
                    RUN_UNCACHED(0x08675C5C, 0);
                    func_08032800(*(u8 *volatile)zoid_type);
                    item_id = *(u8 *volatile)completion_item;
                    asm("" : : "r"(item_id));
                    RUN_UNCACHED(0x0867636C, item_id);
                }
                script_run_table((const u8 **volatile)recovery_layout, 0x10);
                script_run_table((const u8 **volatile)recovery_layout, 0x25);
                func_080019EC(0x41);
                build_recovery_item_selection();
            }
            else
                func_080019EC(0x3F);
            goto recovery_target_list_done;
        }
        }
        recovery_target_list_done:
        {
            register u32 next_state asm("r4") = 0x2001;
            register const u8 **exit_layout asm("r5");
            asm("" : : "r"(next_state));
            state = next_state;
            ((const u8 **volatile)exit_layout) = menu_layout_scripts;
            asm("" : : "r"(exit_layout));
            script_run_table((const u8 **volatile)exit_layout, 0xB);
            {
                register u16 *flags_address asm("r2") = (u16 *)0x03004BBC;
                register u32 flags asm("r0");
                register u32 mask asm("r7");
                register u32 mask_copy asm("r1");
                asm("" : : "r"(flags_address));
                ((u16 *volatile)flags_address) = (u16 *)((u8 *)flags_address + 0x88);
                flags = *(u16 *volatile)flags_address;
                asm("" : : "r"(flags));
                mask = 0x7FFF;
                asm("" : : "r"(mask));
                mask_copy = mask;
                asm("" : : "r"(mask_copy));
                ((volatile u32)flags) &= mask_copy;
                *(u16 *volatile)flags_address = flags;
            }
            script_run_table((const u8 **volatile)exit_layout, 9);
            if (recovery_selection_count != 0)
                goto recovery_target_close_window;
            RUN_UNCACHED(0x0875B068, 0xC);
            state = 1;
        recovery_target_close_window:
            return_table = (const u8 **volatile)exit_layout;
            asm("" : "+r"(return_table));
            goto close_primary_window;
        }
        }
        case 0x3000:
            RUN_UNCACHED(menu_layout_scripts, 0xB);
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
            RUN_UNCACHED(0x0875B1B8, 0);
            {
                register u32 zero asm("r0") = 0;
                register u32 invalid asm("r1");
                register u16 *cursor asm("r2");
                asm("" : : "r"(zero));
                page = zero;
                invalid = 0xFFFF;
                asm("" : : "r"(invalid));
                previous_index = invalid;
                previous_page = invalid;
                previous_zoid = invalid;
                cursor = (u16 *)0x02007588;
                asm("" : : "r"(cursor));
                *(u16 *volatile)cursor = zero;
            }
        case 0x3001:
        {
            union
            {
                u32 word;
                s16 halves[2];
                u16 *flags;
            } page_copy;
            register u8 *party asm("r9");
            register const u8 **layout asm("r8");
            register union RegisterHalf previous_copy asm("r10");
            register u32 equipment_pilot_row asm("r6");
            {
                register u8 *initial_party asm("r3");
                register const u8 **initial_layout asm("r4");
                ((u8 *volatile)initial_party) = (u8 *)&player_state;
                asm("" : : "r"(initial_party));
                party = initial_party;
                ((const u8 **volatile)initial_layout) = menu_layout_scripts;
                asm("" : : "r"(initial_layout));
                layout = initial_layout;
            }
        refresh_equipment_pilot:
            for (;;)
            {
                RUN_UNCACHED(0x0875B1B8, 5);
                RUN_UNCACHED(menu_layout_scripts, 0x1C);
                for (;;)
                {
                equipment_pilot_refresh:
                {
                    register s32 current_page asm("r4");
                    register s32 old_page asm("r0");
                    {
                        register u32 page_load asm("r6") = page;
                        register u32 page_shift asm("r1");
                        register u32 index_shift asm("r1");
                        asm("" : : "r"(page_load));
                        page_shift = page_load << 16;
                        current_page = (s32)page_shift >> 16;
                        asm("" : : "r"(page_shift), "r"(current_page));
                        page_copy.word = previous_page;
                        asm("" : "+r"(page_copy.word));
                        ((volatile s32)old_page) = page_copy.word << 16;
                        ((volatile s32)old_page) >>= 16;
                        page_copy.word = page_shift;
                        asm("" : "+r"(page_copy.word));
                        index_shift = previous_index;
                        asm("" : : "r"(index_shift));
                        ((volatile u32)index_shift) <<= 16;
                        previous_copy.word = index_shift;
                    }
                    if (current_page != old_page)
                    {
                        register s32 page_rows asm("r5");
                        register u32 initial_page_rows asm("r2");
                        register u32 initial_row_shift asm("r0");
                        register const u8 *limit_count asm("r4");
                        register const u8 *row_count asm("r3");
                        {
                            register s32 invalid asm("r2") = -1;
                            asm("" : : "r"(invalid));
                            if (old_page != invalid)
                                RUN_UNCACHED(menu_layout_scripts, 3);
                        }
                        equipment_pilot_row = 0;
                        ((volatile u32)initial_row_shift) = current_page * 3;
                        initial_page_rows = initial_row_shift << 1;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r1");
                            guard.part.high = (u32)initial_page_rows;
                            initial_page_rows = (u32)guard.part.high;
                        }
                        ((volatile u32)initial_row_shift) <<= 17;
                        {
                            register u32 narrowed_row asm("r3") = initial_row_shift >> 16;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r2");
                                guard.part.high = (u32)narrowed_row;
                                narrowed_row = (u32)guard.part.high;
                            }
                            last_row = narrowed_row;
                        }
                        ((volatile u32)initial_row_shift) = (s32)initial_row_shift >> 16;
                        {
                            register const u8 *initial_count asm("r1");
                            register s32 count_value asm("r1");
                            ((const u8 *volatile)initial_count) = &pilot_selection_count;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.high = (u32)initial_count;
                                initial_count = (const u8 *)guard.part.high;
                            }
                            limit_count = initial_count;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r3");
                                guard.part.high = (u32)limit_count;
                                limit_count = (const u8 *)guard.part.high;
                            }
                            count_value = *(const u8 *volatile)limit_count;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.high = (u32)count_value;
                                count_value = (s32)guard.part.high;
                            }
                            if ((s32)initial_row_shift >= count_value)
                                goto equipment_pilot_rows_done;
                        }
                        {
                            row_count = limit_count;
                            page_rows = initial_page_rows;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r4");
                                guard.part.high = (u32)page_rows;
                                page_rows = (s32)guard.part.high;
                            }
                            for (;;)
                            {
                                {
                                    register const u8 *names asm("r1") = pilot_selection_ids;
                                    register u32 row_load asm("r2") = last_row;
                                    register u32 row_shift asm("r0");
                                    register s32 row_index asm("r4");
                                    asm("" : : "r"(names), "r"(row_load));
                                    row_shift = row_load << 16;
                                    row_index = (s32)row_shift >> 16;
                                    asm("" : : "r"(row_shift), "r"(row_index));
                                    ((const u8 *volatile)names) =
                                        (const u8 *)((u32)row_index + (u32)names);
                                    {
                                        register u32 pilot_id asm("r0") =
                                            *(const u8 *volatile)names;
                                        register s32 signed_row asm("r0");
                                        asm("" : : "r"(pilot_id), "r"(row_count));
                                        call_scratch.count = row_count;
                                        func_08032818(pilot_id);
                                        signed_row = (s16)equipment_pilot_row;
                                        asm("" : : "r"(signed_row));
                                        row_count = call_scratch.count;
                                        asm("" : : "r"(row_count));
                                        if (signed_row <= 4 &&
                                            row_index < *(const u8 *volatile)row_count - 1)
                                        {
                                            RUN(0x08675C5C, 0);
                                            row_count = call_scratch.count;
                                            asm("" : : "r"(row_count));
                                        }
                                    }
                                }
                                {
                                    register u32 next_row asm("r0");
                                    register u32 increment asm("r4");
                                    ((volatile u32)next_row) = equipment_pilot_row << 16;
                                    asm("" : : "r"(next_row));
                                    increment = 0x10000;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r3");
                                        guard.part.high = (u32)increment;
                                        increment = (u32)guard.part.high;
                                    }
                                    ((volatile u32)next_row) += increment;
                                    equipment_pilot_row = (volatile u32)next_row >> 16;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r5");
                                        guard.part.high = (u32)equipment_pilot_row;
                                        equipment_pilot_row = (u32)guard.part.high;
                                    }
                                    ((volatile u32)next_row) = (s32)next_row >> 16;
                                    ((const u8 *volatile)limit_count) = &pilot_selection_count;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r3");
                                        guard.part.high = (u32)limit_count;
                                        limit_count = (const u8 *)guard.part.high;
                                    }
                                    if ((s32)next_row > 5)
                                        goto equipment_pilot_rows_done;
                                    ((volatile u32)next_row) += page_rows;
                                    ((volatile u32)next_row) <<= 16;
                                    {
                                        register u32 narrowed_row asm("r1") = next_row >> 16;
                                        {
                                            register union
                                            {
                                                unsigned long long whole;
                                                struct
                                                {
                                                    u32 low, high;
                                                } part;
                                            } guard asm("r0");
                                            guard.part.high = (u32)narrowed_row;
                                            narrowed_row = (u32)guard.part.high;
                                        }
                                        last_row = narrowed_row;
                                    }
                                    ((volatile u32)next_row) = (s32)next_row >> 16;
                                    {
                                        register s32 count_value asm("r2") =
                                            *(const u8 *volatile)row_count;
                                        {
                                            register union
                                            {
                                                unsigned long long whole;
                                                struct
                                                {
                                                    u32 low, high;
                                                } part;
                                            } guard asm("r1");
                                            guard.part.high = (u32)count_value;
                                            count_value = (s32)guard.part.high;
                                        }
                                        if ((s32)next_row >= count_value)
                                            break;
                                    }
                                }
                            }
                        }
                    equipment_pilot_rows_done:
                    {
                        register u8 *windows asm("r3");
                        {
                            register u32 row_word asm("r0") = equipment_pilot_row << 16;
                            register u16 *cursor asm("r2");
                            register s32 cursor_value asm("r1");
                            ((volatile u32)row_word) = (s32)row_word >> 16;
                            asm("" : : "r"(row_word));
                            ((u16 *volatile)cursor) = (u16 *)0x02007588;
                            asm("" : : "r"(cursor));
                            ((u8 *volatile)windows) = (u8 *)text_windows;
                            asm("" : : "r"(windows));
                            cursor_value = *(u16 *volatile)cursor;
                            asm("" : : "r"(cursor_value));
                            if ((s32)row_word <= cursor_value)
                            {
                                register u16 clamped asm("r0") = equipment_pilot_row - 1;
                                register u8 *cursor_byte asm("r6");
                                asm("" : : "r"(clamped));
                                ((u8 *volatile)cursor_byte) = saved_selection;
                                asm("" : : "r"(cursor_byte));
                                *(u8 *volatile)cursor_byte = (volatile u16)clamped;
                                ((volatile u16)clamped) = (u8)(volatile u16)clamped;
                                *(u16 *volatile)cursor = (volatile u16)clamped;
                            }
                        }
                        asm volatile("" : "+r"(page_copy.word));
                        {
                            register u32 offset asm("r0") = 0xA0B;
                            register u8 *flags asm("r2");
                            register u8 zero asm("r3");
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = (u32)offset;
                                offset = (u32)guard.part.low;
                            }
                            flags = windows + offset;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r1");
                                guard.part.high = (u32)flags;
                                flags = (u8 *)guard.part.high;
                            }
                            zero = 0;
                            asm("" : : "r"(zero));
                            {
                                register u32 stored_zero asm("r0") = (u32)zero;
                                asm("" : : "r"(stored_zero));
                                *(u8 *volatile)flags = stored_zero;
                            }
                            if ((s32)page_copy.word > 0)
                                *(u8 *volatile)flags = 1;
                            {
                                register u32 row_load asm("r6") = last_row;
                                register s32 signed_row asm("r1") = (s16)row_load;
                                register s32 count_value asm("r0");
                                asm("" : : "r"(row_load), "r"(signed_row));
                                ((volatile s32)count_value) = *(const u8 *volatile)limit_count;
                                ((volatile s32)count_value) -= 1;
                                if (signed_row < count_value)
                                {
                                    register u32 old_flags asm("r1") = *(u8 *volatile)flags;
                                    register u32 right_flag asm("r0") = 2;
                                    asm("" : : "r"(old_flags), "r"(right_flag));
                                    ((volatile u32)old_flags) |= right_flag;
                                    *(u8 *volatile)flags = (volatile u32)old_flags;
                                }
                            }
                            {
                                register u32 saved_page asm("r0") = page_copy.word >> 16;
                                asm("" : : "r"(saved_page));
                                previous_page = saved_page;
                            }
                        }
                    }
                    }
                    {
                        register s32 signed_page asm("r1") = page_copy.halves[1];
                        register u32 selected_shift asm("r0");
                        register s32 signed_selection asm("r1");
                        asm("" : : "r"(signed_page));
                        ((volatile u32)selected_shift) = signed_page * 6;
                        asm("" : : "r"(selected_shift));
                        {
                            register u16 *cursor asm("r1");
                            register u32 cursor_value asm("r1");
                            ((u16 *volatile)cursor) = (u16 *)0x02007588;
                            asm("" : : "r"(cursor));
                            cursor_value = *(u16 *volatile)cursor;
                            asm("" : : "r"(cursor_value));
                            ((volatile u32)selected_shift) += cursor_value;
                        }
                        ((volatile u32)selected_shift) <<= 16;
                        {
                            register u32 narrowed_selection asm("r2") = selected_shift >> 16;
                            asm("" : : "r"(narrowed_selection));
                            selected_index = narrowed_selection;
                        }
                        signed_selection = (s32)selected_shift >> 16;
                        asm("" : : "r"(signed_selection));
                        if (selected_shift != previous_copy.word)
                        {
                            register u32 zoid_address asm("r5");
                            register union RegisterHalf zoid_copy asm("r5");
                            register u32 type_address asm("r4");
                            register s32 signed_slot asm("r2");
                            register u32 zoid_shift asm("r3");
                            {
                                register u32 pilot_address asm("r0") = (u32)pilot_selection_ids;
                                asm("" : : "r"(pilot_address));
                                ((volatile u32)pilot_address) = signed_selection + pilot_address;
                                ((volatile u32)pilot_address) = U8_AT((volatile u32)pilot_address);
                                ((volatile u32)pilot_address) <<= 2;
                                ((volatile u32)pilot_address) += (u32)(u8 *volatile)party;
                                {
                                    register u32 slot_offset asm("r3") = 0x34A6;
                                    asm("" : : "r"(slot_offset));
                                    ((volatile u32)pilot_address) += slot_offset;
                                }
                                ((volatile u32)pilot_address) = U8_AT((volatile u32)pilot_address);
                                selected_zoid = pilot_address;
                                zoid_shift = pilot_address << 16;
                                asm("" : : "r"(zoid_shift));
                                signed_slot = (s32)zoid_shift >> 16;
                                asm("" : : "r"(signed_slot));
                                ((volatile u32)pilot_address) = signed_slot * 56;
                                type_address = (u32)(u8 *volatile)party;
                                asm("" : : "r"(type_address));
                                zoid_address = pilot_address + type_address;
                                asm("" : : "r"(zoid_address));
                                {
                                    register u32 type_offset asm("r6") = 0xD32;
                                    asm("" : : "r"(type_offset));
                                    type_address = zoid_address + type_offset;
                                    asm("" : : "r"(type_address));
                                }
                                {
                                    register u32 model_address asm("r1") = U16_AT(type_address);
                                    register u32 model_stride asm("r0") = 76;
                                    asm("" : : "r"(model_address), "r"(model_stride));
                                    ((volatile u32)model_address) *= model_stride;
                                    {
                                        register u32 models_base asm("r0") = (u32)zoid_models;
                                        asm("" : : "r"(models_base));
                                        ((volatile u32)model_address) += models_base;
                                    }
                                    asm("" : : "r"(model_address));
                                    model = (const u8 *)model_address;
                                }
                            }
                            if (signed_slot != 255)
                            {
                                {
                                    register u32 old_flags asm("r1");
                                    register u32 mask asm("r2");
                                    register u32 mask_copy asm("r0");
                                    page_copy.flags = (u16 *)0x03004C44;
                                    old_flags = *(u16 *volatile)page_copy.flags;
                                    mask = 0x7FFF;
                                    asm("" : : "r"(old_flags), "r"(mask));
                                    mask_copy = mask;
                                    asm("" : : "r"(mask_copy));
                                    ((volatile u32)old_flags) &= mask_copy;
                                    *(u16 *volatile)page_copy.flags = old_flags;
                                }
                                script_run_table((const u8 **volatile)layout, 1);
                                script_run_table((const u8 **volatile)layout, 0x1A);
                                func_08032800(U8_AT(type_address));
                                RUN(0x08675C5C, 0);
                                RUN(0x0875B1B8, 2);
                                {
                                    register const u8 *model_pointer asm("r3") = model;
                                    register u32 model_value asm("r1");
                                    register u32 support_mask asm("r0");
                                    asm("" : : "r"(model_pointer));
                                    model_value = U32_AT(model_pointer + 8);
                                    asm("" : : "r"(model_value));
                                    support_mask = 0xFFFF0003;
                                    asm("" : : "r"(support_mask));
                                    ((volatile u32)model_value) &= support_mask;
                                    ((volatile u32)support_mask) -= 3;
                                    if (model_value != support_mask)
                                    {
                                        register u32 weapon_offset asm("r4") = 0xD3E;
                                        register u32 weapon_address asm("r2");
                                        register u32 equipped asm("r1");
                                        asm("" : : "r"(weapon_offset));
                                        weapon_address = zoid_address + weapon_offset;
                                        asm("" : : "r"(weapon_address));
                                        equipped = U16_AT(weapon_address);
                                        asm("" : : "r"(equipped));
                                        ((volatile u32)support_mask) >>= 16;
                                        if (equipped != support_mask)
                                            RUN(0x0866634C, equipped);
                                        else
                                            RUN(0x0875B304, 1);
                                    }
                                    else
                                        RUN(0x0875B304, 0);
                                }
                                RUN(0x08675C5C, 0);
                                RUN(0x0875B1B8, 3);
                                {
                                    {
                                        register const u8 *model_pointer asm("r6") = model;
                                        register u32 model_value asm("r1");
                                        register u32 support_mask asm("r0");
                                        register u32 unsupported asm("r3");
                                        asm("" : : "r"(model_pointer));
                                        model_value = U32_AT(model_pointer + 12);
                                        asm("" : : "r"(model_value));
                                        support_mask = 0xFFFF0003;
                                        asm("" : : "r"(support_mask));
                                        ((volatile u32)model_value) &= support_mask;
                                        unsupported = 0xFFFF0000;
                                        asm("" : : "r"(unsupported));
                                        if (model_value != unsupported)
                                        {
                                            register u32 slot_load asm("r7") = selected_zoid;
                                            register u32 slot_shift asm("r2");
                                            register s32 signed_slot asm("r1");
                                            register u32 zoid_address asm("r0");
                                            register u32 weapon_address asm("r4");
                                            asm("" : : "r"(slot_load));
                                            slot_shift = slot_load << 16;
                                            signed_slot = (s32)slot_shift >> 16;
                                            asm("" : : "r"(slot_shift), "r"(signed_slot));
                                            ((volatile u32)zoid_address) = signed_slot * 56;
                                            ((volatile u32)zoid_address) +=
                                                (u32)(u8 *volatile)party;
                                            {
                                                register u32 weapon_offset asm("r1") = 0xD42;
                                                asm("" : : "r"(weapon_offset));
                                                weapon_address = zoid_address + weapon_offset;
                                                asm("" : : "r"(weapon_address));
                                            }
                                            {
                                                register u32 equipped asm("r1") =
                                                    U16_AT(weapon_address);
                                                register u32 empty asm("r0") = unsupported >> 16;
                                                asm("" : : "r"(equipped), "r"(empty));
                                                zoid_copy.word = slot_shift;
                                                asm("" : : "r"(zoid_copy.word));
                                                if (equipped != empty)
                                                    RUN(0x0866634C, equipped);
                                                else
                                                    RUN(0x0875B304, 1);
                                            }
                                        }
                                        else
                                        {
                                            RUN(0x0875B304, 0);
                                            {
                                                register u32 slot_load asm("r2") = selected_zoid;
                                                asm("" : : "r"(slot_load));
                                                zoid_copy.word = slot_load << 16;
                                            }
                                        }
                                    }
                                    RUN(0x08675C5C, 0);
                                    RUN(0x0875B1B8, 4);
                                    {
                                        register const u8 *model_pointer asm("r3") = model;
                                        register u32 model_value asm("r1");
                                        register u32 support_mask asm("r0");
                                        register u32 unsupported asm("r3");
                                        asm("" : : "r"(model_pointer));
                                        model_value = U32_AT(model_pointer + 16);
                                        asm("" : : "r"(model_value));
                                        support_mask = 0xFFFF0003;
                                        asm("" : : "r"(support_mask));
                                        ((volatile u32)model_value) &= support_mask;
                                        unsupported = 0xFFFF0000;
                                        asm("" : : "r"(unsupported));
                                        if (model_value != unsupported)
                                        {
                                            register s32 signed_slot asm("r1") =
                                                zoid_copy.halves[1];
                                            register u32 zoid_address asm("r0");
                                            register u32 weapon_offset asm("r4");
                                            register u32 weapon_address asm("r2");
                                            asm("" : : "r"(signed_slot));
                                            ((volatile u32)zoid_address) = signed_slot * 56;
                                            ((volatile u32)zoid_address) +=
                                                (u32)(u8 *volatile)party;
                                            weapon_offset = 0xD46;
                                            asm("" : : "r"(weapon_offset));
                                            weapon_address = zoid_address + weapon_offset;
                                            asm("" : : "r"(weapon_address));
                                            {
                                                register u32 equipped asm("r1") =
                                                    U16_AT(weapon_address);
                                                register u32 empty asm("r0") = unsupported >> 16;
                                                asm("" : : "r"(equipped), "r"(empty));
                                                if (equipped != empty)
                                                    RUN(0x0866634C, equipped);
                                                else
                                                    RUN(0x0875B304, 1);
                                            }
                                        }
                                        else
                                            RUN(0x0875B304, 0);
                                    }
                                    asm("" : "+r"(zoid_copy.word));
                                    {
                                        register s32 signed_slot asm("r0") = zoid_copy.halves[1];
                                        register u32 type_address asm("r1");
                                        register u32 type_offset asm("r6");
                                        asm("" : : "r"(signed_slot));
                                        ((volatile u32)type_address) = signed_slot * 56;
                                        ((volatile u32)type_address) += (u32)(u8 *volatile)party;
                                        type_offset = 0xD32;
                                        asm("" : : "r"(type_offset));
                                        ((volatile u32)type_address) += type_offset;
                                        func_0804D654(U16_AT(type_address), 0x28, 0x58);
                                    }
                                }
                            }
                            else
                            {
                                register u32 previous_load asm("r7") = previous_zoid;
                                register s32 signed_previous asm("r0");
                                asm("" : : "r"(previous_load));
                                ((volatile s32)signed_previous) = previous_load << 16;
                                ((volatile s32)signed_previous) >>= 16;
                                zoid_copy.word = zoid_shift;
                                asm("" : : "r"(zoid_copy.word));
                                if (signed_previous != 255)
                                {
                                    register u16 *flags_address asm("r0");
                                    register u32 old_flags asm("r1");
                                    register u32 mask asm("r2");
                                    register u32 mask_copy asm("r0");
                                    register u16 *flags_store asm("r3");
                                    ((u16 *volatile)flags_address) = (u16 *)0x03004C44;
                                    asm("" : : "r"(flags_address));
                                    old_flags = *(u16 *volatile)flags_address;
                                    asm("" : : "r"(old_flags));
                                    mask = 0x7FFF;
                                    asm("" : : "r"(mask));
                                    mask_copy = mask;
                                    asm("" : : "r"(mask_copy));
                                    ((volatile u32)old_flags) &= mask_copy;
                                    ((u16 *volatile)flags_store) = (u16 *)0x03004C44;
                                    asm("" : : "r"(flags_store));
                                    *(u16 *volatile)flags_store = old_flags;
                                    script_run_table((const u8 **volatile)layout, 1);
                                    script_run_table((const u8 **volatile)layout, 0x1A);
                                    RUN(0x0875B1B8, 1);
                                }
                            }
                            script_run_table((const u8 **volatile)layout, 0x18);
                            script_run_table((const u8 **volatile)layout, 0x1C);
                            ((volatile u32)zoid_copy.word) >>= 16;
                            previous_zoid = zoid_copy.word;
                            {
                                register u32 selection_load asm("r4") = selected_index;
                                register u32 narrowed_selection asm("r0");
                                asm("" : : "r"(selection_load));
                                ((volatile u32)narrowed_selection) = selection_load << 16;
                                ((volatile u32)narrowed_selection) >>= 16;
                                previous_index = narrowed_selection;
                            }
                        }
                        else
                        {
                            script_run_table((const u8 **volatile)layout, 0x10);
                            script_run_table((const u8 **volatile)layout, 0x1C);
                        }
                    }
                    RUN_UNCACHED(menu_layout_scripts, 0x23);
                    {
                        register const u16 *action_address asm("r1") = (const u16 *)0x02007574;
                        register u32 action asm("r0");
                        asm("" : : "r"(action_address));
                        action = *(const u16 *volatile)action_address;
                        asm("" : : "r"(action));
                        if (action <= 1)
                            goto equipment_pilot_accept;
                        if (action == 2)
                            goto equipment_pilot_page_left;
                        if (action == 4)
                            goto equipment_pilot_page_right;
                        goto equipment_pilot_refresh;
                    }
                equipment_pilot_page_left:
                {
                    register u32 page_load asm("r6") = page;
                    register s32 signed_page asm("r4");
                    register u32 next_page asm("r0");
                    asm("" : : "r"(page_load));
                    ((volatile u32)next_page) = page_load << 16;
                    signed_page = (s32)next_page >> 16;
                    asm("" : : "r"(signed_page));
                    if (signed_page <= 0)
                        goto equipment_pilot_refresh;
                    func_080019EC(0x40);
                    ((volatile u32)next_page) = (signed_page - 1) << 16;
                    goto equipment_pilot_page_save;
                equipment_pilot_page_right:
                {
                    register u32 row_load asm("r7") = last_row;
                    register s32 signed_row asm("r1");
                    register s32 count asm("r0");
                    asm("" : : "r"(row_load));
                    ((volatile s32)signed_row) = row_load << 16;
                    ((volatile s32)signed_row) >>= 16;
                    ((volatile s32)count) = pilot_selection_count;
                    ((volatile s32)count) -= 1;
                    if (signed_row >= count)
                        goto equipment_pilot_refresh;
                    func_080019EC(0x40);
                    {
                        register u32 page_load asm("r1") = page;
                        register u32 increment asm("r2");
                        asm("" : : "r"(page_load));
                        ((volatile u32)next_page) = page_load << 16;
                        increment = 0x10000;
                        asm("" : : "r"(increment));
                        ((volatile u32)next_page) += increment;
                    }
                }
                equipment_pilot_page_save:
                    ((volatile u32)next_page) >>= 16;
                    page = next_page;
                    goto equipment_pilot_refresh;
                }
                }
                }
            equipment_pilot_accept:
            {
                register const u16 *accepted_action asm("r0");
                ((const u16 *volatile)accepted_action) = (const u16 *)0x02007574;
                if (*(const volatile u16 *)accepted_action == 1)
                {
                    {
                        register u32 zoid_load asm("r3") = selected_zoid;
                        register s32 signed_zoid asm("r0");
                        asm("" : : "r"(zoid_load));
                        ((volatile s32)signed_zoid) = zoid_load << 16;
                        ((volatile s32)signed_zoid) >>= 16;
                        if (signed_zoid == 255)
                        {
                            func_080019EC(0x4F);
                            RUN(0x0875B1B8, 6);
                            script_run_table((const u8 **volatile)layout, 0x25);
                            func_080019EC(0x41);
                            script_run_table((const u8 **volatile)layout, 0);
                            continue;
                        }
                    }
                    {
                        register u32 name_address asm("r4");
                        register u32 pilot_address asm("r0");
                        {
                            register const u8 *names asm("r1") = pilot_selection_ids;
                            register u32 selected_load asm("r4") = selected_index;
                            asm("" : : "r"(names), "r"(selected_load));
                            ((volatile u32)pilot_address) = selected_load << 16;
                            ((volatile u32)pilot_address) = (s32)pilot_address >> 16;
                            name_address = pilot_address + (u32)names;
                            asm("" : : "r"(name_address));
                        }
                        ((volatile u32)pilot_address) = U8_AT(name_address);
                        ((volatile u32)pilot_address) <<= 2;
                        ((volatile u32)pilot_address) += (u32)(u8 *volatile)party;
                        {
                            register u32 flags_offset asm("r6") = 0x34A4;
                            asm("" : : "r"(flags_offset));
                            ((volatile u32)pilot_address) += flags_offset;
                        }
                        {
                            register u32 pilot_flags asm("r1") = U16_AT(pilot_address);
                            register u32 rejected asm("r0") = 8;
                            asm("" : : "r"(pilot_flags), "r"(rejected));
                            ((volatile u32)rejected) &= pilot_flags;
                            if (rejected != 0)
                            {
                                func_080019EC(0x4F);
                                script_run_table((const u8 **volatile)layout, 0);
                                script_run_table((const u8 **volatile)layout, 0x19);
                                func_08032818(U8_AT(name_address));
                                RUN(0x0875B1B8, 7);
                                script_run_table((const u8 **volatile)layout, 0x25);
                                func_080019EC(0x41);
                                script_run_table((const u8 **volatile)layout, 0);
                                continue;
                            }
                        }
                    }
                    RUN_UNCACHED(menu_layout_scripts, 0);
                    {
                        register u16 *selections asm("r0") = selected;
                        register u32 selected_value asm("r1");
                        asm("" : : "r"(selections));
                        page_copy.flags = (u16 *)0x02007588;
                        selected_value = *(const u16 *volatile)page_copy.flags;
                        asm("" : : "r"(selected_value));
                        selections[1] = selected_value;
                    }
                    {
                        register u16 *page_values asm("r0") = pages;
                        register const u16 *page_source asm("r1") = (const u16 *)menu_stack;
                        register u16 page_value asm("r1");
                        asm("" : : "r"(page_values), "r"(page_source));
                        page_value = page_source[14];
                        asm("" : : "r"(page_value));
                        page_values[1] = page_value;
                    }
                    {
                        register u32 next_state asm("r4") = 0x3100;
                        asm("" : : "r"(next_state));
                        state = next_state;
                    }
                }
                else
                {
                    func_080019EC(0x3F);
                    state = 1;
                    script_run_table((const u8 **volatile)layout, 0xB);
                    {
                        register u16 *flags_address asm("r2") = (u16 *)0x03004C44;
                        register u32 old_flags asm("r0") = *(u16 *volatile)flags_address;
                        register u32 disabled asm("r3") = 0x7FFF;
                        register u16 mask asm("r1");
                        asm("" : : "r"(old_flags), "r"(disabled));
                        mask = disabled;
                        asm("" : : "r"(mask));
                        ((volatile u32)old_flags) &= mask;
                        *(u16 *volatile)flags_address = old_flags;
                    }
                    script_run_table((const u8 **volatile)layout, 9);
                    return_table = (const u8 **volatile)layout;
                close_primary_window:
                    script_run_table(return_table, 0);
                }
                goto equipment_pilot_done;
            }
            }
        equipment_pilot_done:
            break;
        }
        case 0x3100:
            RUN(0x0875B1D8, 0);
            {
                register u32 zero asm("r4") = 0;
                register u16 *cursor asm("r6");
                asm("" : : "r"(zero));
                slot_index = zero;
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                asm("" : : "r"(cursor));
                *(u16 *volatile)cursor = zero;
            }
            state = 0x3102;
            break;
        case 0x3101:
        {
            u8 *byte_address;
            register u32 selected_slot asm("r0");
            register u32 held1 asm("r1"), held2 asm("r2"), held3 asm("r3");
            register u32 held4 asm("r4"), held5 asm("r5"), held6 asm("r6");
            register u32 stack_address asm("r7") = (u32)menu_stack + 68;
            asm("" : : "r"(stack_address));
            asm("" : "=r"(selected_slot));
            asm(""
                : "=&l"(byte_address), "=r"(held1), "=r"(held2), "=r"(held3), "=r"(held4),
                  "=r"(held5), "=r"(held6)
                : "0"((u8 *)stack_address), "r"(selected_slot));
            selected_slot = *byte_address;
            asm(""
                :
                : "l"(byte_address), "r"(selected_slot), "r"(held1), "r"(held2), "r"(held3),
                  "r"(held4), "r"(held5), "r"(held6));
            asm(""
                : "=&l"(byte_address), "=r"(held1), "=r"(held2), "=r"(held3), "=r"(held4),
                  "=r"(held5), "=r"(held6)
                : "0"((u8 *)0x020082FD), "r"(selected_slot));
            *byte_address = selected_slot;
            asm("" : : "r"(held1), "r"(held2), "r"(held3), "r"(held4), "r"(held5), "r"(held6));
        }
            {
                register u32 slot_word asm("r1") = slot_index;
                register u32 selected_slot asm("r0");
                register u16 *cursor asm("r2");
                asm("" : : "r"(slot_word));
                ((volatile u32)selected_slot) = slot_word << 24;
                ((volatile u32)selected_slot) >>= 24;
                ((u16 *volatile)cursor) = (u16 *)0x02007588;
                *(u16 *volatile)cursor = selected_slot;
            }
        case 0x3102:
        {
            register union RegisterHalf slot_previous asm("r5");
            register u32 empty_slot asm("r6");
            register s32 current_slot asm("r4");
            register const u8 **slot_layout asm("r4");
            u32 cursor_word;
            RUN_UNCACHED(menu_layout_scripts, 0x1D);
            {
                register const u8 **details asm("r5") = (const u8 **)0x0875B1D8;
                register u32 zoid asm("r4");
                register u32 selected_value asm("r3");
                RUN(details, 1);
                selected_value = selected_zoid;
                asm("" : : "r"(selected_value));
                zoid = selected_value << 24;
                asm("" : "+r"(zoid));
                zoid >>= 24;
                func_0804E0A8(zoid, 0);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(details, 2);
                func_0804E0A8(zoid, 1);
                RUN_UNCACHED(0x08675C5C, 0);
                RUN(details, 3);
                func_0804E0A8(zoid, 2);
            }
            {
                register u16 *display asm("r2") = (u16 *)0x04000000;
                register u32 flags asm("r0");
                register u32 enabled asm("r4");
                register u16 mask asm("r1");
                flags = *display;
                asm("" : "+r"(flags));
                enabled = 0x2000;
                asm("" : : "r"(enabled));
                mask = enabled;
                asm("" : : "r"(mask));
                *display = flags | mask;
            }
            {
                register u16 *palette asm("r1");
                ((u16 *volatile)palette) = (u16 *)0x0300234A;
                asm("" : "+r"(palette));
                *(u16 *volatile)palette = 15;
                ((u16 *volatile)palette) = (u16 *)0x03002350;
                asm("" : "+r"(palette));
                *(u16 *volatile)palette = 31;
            }
            slot_previous.word = 0xFFFF;
            asm("" : "+r"(slot_previous.word));
            empty_slot = slot_previous.word;
            asm("" : : "r"(empty_slot));
        slot_refresh:
        {
            {
                register u32 held0 asm("r0"), held1 asm("r1"), held2 asm("r2");
                register u32 held3 asm("r3"), held4 asm("r4");
                asm(""
                    : "=&l"(cursor_word), "=r"(held0), "=r"(held1), "=r"(held2), "=r"(held3),
                      "=r"(held4)
                    : "0"((u32)&CURSOR), "r"(slot_previous.word), "r"(empty_slot));
                cursor_word = U16_AT(cursor_word);
                slot_index = cursor_word;
                asm(""
                    :
                    : "r"(held0), "r"(held1), "r"(held2), "r"(held3), "r"(held4),
                      "r"(slot_previous.word), "r"(empty_slot));
            }
            {
                register s16 *cursor asm("r0");
                ((s16 *volatile)cursor) = (s16 *)0x02007588;
                current_slot = *(s16 *volatile)cursor;
            }
            {
                register s32 previous asm("r0");
                previous = (s16)slot_previous.word;
                asm("" : "+r"(previous));
                if (current_slot != previous)
                {
                    register s32 negative_one asm("r2");
                    asm("" : : "l"(cursor_word));
                    negative_one = -1;
                    asm("" : : "r"(negative_one));
                    slot_previous.word = (u32)negative_one << 16;
                    asm("" : "+r"(slot_previous.word));
                    if (previous != negative_one)
                        RUN_UNCACHED(menu_layout_scripts, 0);
                    RUN_UNCACHED(menu_layout_scripts, 0x19);
                    {
                        register u32 row_offset asm("r3") = current_slot * 4;
                        register u32 model_base asm("r4") = (u32)model;
                        register u32 entry asm("r2");
                        register u32 flags asm("r0");
                        register u32 missing asm("r4");
                        asm("" : : "r"(row_offset), "r"(model_base));
                        entry = model_base + row_offset;
                        asm("" : : "r"(entry));
                        {
                            register u32 stored_flags asm("r1") = U16_AT(entry + 8);
                            asm("" : : "r"(stored_flags));
                            flags = 3;
                            flags &= stored_flags;
                        }
                        asm("" : "+r"(flags));
                        missing = slot_previous.word >> 16;
                        asm("" : : "r"(missing));
                        if (flags || U16_AT(entry + 10) != empty_slot)
                        {
                            register u32 party asm("r2") = (u32)&player_state;
                            register union RegisterHalf selected_copy asm("r7");
                            register s32 selected_signed asm("r1");
                            register u32 address asm("r0");
                            register u32 field_offset asm("r1");
                            register u32 equipped asm("r2");
                            selected_copy.word = selected_zoid;
                            asm("" : : "r"(party), "r"(selected_copy.word));
                            selected_signed = selected_copy.word << 16;
                            asm("" : "+r"(selected_signed));
                            selected_signed >>= 16;
                            address = selected_signed * 56;
                            address = row_offset + address;
                            address += party;
                            asm("" : "+r"(address));
                            field_offset = 0xD3E;
                            asm("" : : "r"(field_offset));
                            equipped = address + field_offset;
                            asm("" : : "r"(equipped));
                            if (U16_AT(equipped) != missing)
                            {
                                register const u8 *pilot_ids asm("r1");
                                register u32 selected_load asm("r3");
                                register s32 pilot_index asm("r0");
                                ((const u8 *volatile)pilot_ids) = pilot_selection_ids;
                                selected_load = selected_index;
                                asm("" : : "r"(pilot_ids), "r"(selected_load));
                                ((volatile s32)pilot_index) = selected_load << 16;
                                ((volatile s32)pilot_index) >>= 16;
                                ((volatile s32)pilot_index) += (u32)(const u8 *volatile)pilot_ids;
                                build_equipment_stats(U8_AT((volatile u32)pilot_index),
                                                      U16_AT(equipped), (void *)0x0200E7C4);
                                func_0804DDB4((void *)0x0200E7C4);
                            }
                            else
                                RUN(0x0875B304, 1);
                        }
                        else
                            RUN(0x0875B304, 0);
                    }
                    RUN_UNCACHED(menu_layout_scripts, 0x18);
                    {
                        register u32 current_copy asm("r4") = slot_index;
                        register u32 shifted asm("r0");
                        asm("" : : "r"(current_copy));
                        shifted = current_copy << 16;
                        asm("" : "+r"(shifted));
                        slot_previous.word = shifted >> 16;
                    }
                }
            }
            ((const u8 **volatile)slot_layout) = menu_layout_scripts;
            script_run_table((const u8 **volatile)slot_layout, 0x22);
            {
                register u16 *reply asm("r1");
                register u32 action asm("r0");
                ((u16 *volatile)reply) = (u16 *)0x02007574;
                action = *reply;
                asm("" : "+r"(action));
                if (action == 1)
                {
                    register u32 entry asm("r2");
                    register union RegisterHalf model_base asm("r7");
                    register u32 selected_offset asm("r0") = reply[1] * 4;
                    register u32 flags asm("r0");
                    register u32 stored_flags asm("r1");
                    model_base.word = (u32)model;
                    asm("" : : "r"(selected_offset), "r"(model_base.word));
                    entry = model_base.word + selected_offset;
                    asm("" : : "r"(entry));
                    stored_flags = U16_AT(entry + 8);
                    asm("" : : "r"(stored_flags));
                    flags = 3;
                    flags &= stored_flags;
                    if (flags)
                        goto slot_accepted;
                    if (U16_AT(entry + 10) == empty_slot)
                    {
                        func_080019EC(0x4F);
                        RUN_UNCACHED(0x0875B1D8, 4);
                        func_080019EC(0x41);
                    }
                    else
                    {
                        func_080019EC(0x4F);
                        RUN_UNCACHED(0x0875B1D8, 5);
                        func_080019EC(0x41);
                    }
                    slot_previous.word = 0xFFFF;
                }
                else if (action == 0)
                {
                    func_080019EC(0x3F);
                    {
                        register u16 *palette asm("r0") = (u16 *)0x0300234A;
                        register u16 level asm("r1") = 31;
                        asm("" : "+r"(palette) : "r"(level));
                        *palette = level;
                        ((u16 *volatile)palette) = (u16 *)0x03002350;
                        *palette = level;
                    }
                    script_run_table((const u8 **volatile)slot_layout, 0xC);
                    {
                        register u16 *display asm("r2");
                        ((u16 *volatile)display) = (u16 *)0x04000000;
                        {
                            register u32 flags asm("r0") = *(u16 *volatile)display;
                            register u32 disabled asm("r3");
                            register u16 mask asm("r1");
                            asm("" : "+r"(flags));
                            disabled = 0xDFFF;
                            asm("" : : "r"(disabled));
                            mask = disabled;
                            asm("" : : "r"(mask));
                            *display = flags & mask;
                        }
                    }
                    script_run_table((const u8 **volatile)slot_layout, 0);
                    {
                        register u16 selected_slot asm("r0") = selected[1];
                        register u16 *cursor asm("r4");
                        asm("" : : "r"(selected_slot));
                        ((u16 *volatile)cursor) = (u16 *)0x02007588;
                        *cursor = selected_slot;
                    }
                    {
                        register u32 next_state asm("r4") = 0x3001;
                        asm("" : : "r"(next_state));
                        state = next_state;
                    }
                    goto slot_done;
                }
            }
        }
            goto slot_refresh;
        slot_done:
            break;
        case 0x3200:
        {
            register u32 selected_unit_shift asm("r5");
            register u32 selected_unit_sevens asm("r4");
            register u16 attachment_row asm("r6");
            register s32 selected_attachment_slot asm("r1");
            register s32 attachment_slot asm("r4");
            register u32 attachment_unit_sevens asm("r9");
            register u32 empty_attachment asm("r8");
            {
                register u16 *display asm("r2");
                register u32 flags asm("r0");
                register u32 disabled asm("r6");
                register u16 mask asm("r1");
                ((u16 *volatile)display) = (u16 *)0x04000000;
                flags = *(u16 *volatile)display;
                asm("" : "+r"(flags));
                disabled = 0xEDFF;
                asm("" : "+r"(disabled));
                mask = disabled;
                asm("" : : "r"(mask));
                *display = flags & mask;
            }
            {
                register u32 slot_load asm("r7") = slot_index;
                register u32 shifted asm("r0");
                asm("" : : "r"(slot_load));
                shifted = slot_load << 16;
                selected_attachment_slot = (s32)shifted >> 16;
                asm("" : : "r"(selected_attachment_slot));
                slot_shift = shifted;
            }
            if (selected_attachment_slot == 2)
            {
                register u16 *blend_register asm("r1");
                register u32 blend_control asm("r2");
                register u32 blend_alpha asm("r3");
                register u32 blend_value asm("r0");
                ((u16 *volatile)blend_register) = (u16 *)0x04000050;
                ((u32 volatile)blend_control) = 0x1C42;
                asm("" : "+r"(blend_control));
                ((u32 volatile)blend_value) = (u32 volatile)blend_control;
                *(u16 *volatile)blend_register = (u32 volatile)blend_value;
                ((u16 *volatile)blend_register) += 1;
                ((u32 volatile)blend_alpha) = 0x0808;
                asm("" : "+r"(blend_alpha));
                ((u32 volatile)blend_value) = (u32 volatile)blend_alpha;
                *(u16 *volatile)blend_register = (u32 volatile)blend_value;
            }
            else
                U16_AT(0x04000050) = 0;
            {
                register const u8 *model_party asm("r1") = (const u8 *)&player_state;
                register u32 selected_load asm("r4");
                register u32 model_address asm("r0");
                register u32 field_offset asm("r6");
                asm("" : : "r"(model_party));
                selected_load = selected_zoid;
                asm("" : : "r"(selected_load));
                selected_unit_shift = selected_load << 16;
                asm("" : : "r"(selected_unit_shift));
                model_address = (s32)selected_unit_shift >> 16;
                selected_unit_sevens = (model_address << 3) - model_address;
                model_address = selected_unit_sevens << 3;
                model_address += (u32)model_party;
                field_offset = 0xD32;
                asm("" : : "r"(model_address), "r"(field_offset));
                model_address += field_offset;
                func_08044E04(U16_AT(model_address), 0);
            }
            attachment_row = 0;
            asm("" : : "r"(attachment_row));
            {
                register u32 fill_address asm("r7") = (u32)menu_stack;
                register u32 invalid asm("r0");
                asm("" : : "r"(fill_address));
                fill_address += 24;
                dma_source = (u32 *)fill_address;
                invalid = 65535;
                asm("" : : "r"(invalid));
                empty_attachment = invalid;
                attachment_unit_sevens = selected_unit_sevens;
            }
            do
            {
                register u32 row_shift asm("r0") = (u32)attachment_row << 16;
                register s32 row_index asm("r2") = (s32)row_shift >> 16;
                register u32 selected_slot_shift asm("r1");
                asm("" : : "r"(row_shift), "r"(row_index));
                selected_slot_shift = slot_shift;
                asm("" : : "r"(selected_slot_shift));
                if (row_shift != selected_slot_shift)
                {
                    register u32 party asm("r4") = (u32)&player_state;
                    register u32 address asm("r0");
                    register u32 unit_sevens asm("r3");
                    register u32 unit_bytes asm("r1");
                    register u32 field_offset asm("r7");
                    register u32 item_address asm("r3");
                    asm("" : : "r"(party));
                    address = (u32)row_index << 2;
                    unit_sevens = attachment_unit_sevens;
                    asm("" : : "r"(address), "r"(unit_sevens));
                    unit_bytes = unit_sevens << 3;
                    address += unit_bytes;
                    address += party;
                    field_offset = 0xD3E;
                    asm("" : : "r"(address), "r"(field_offset));
                    item_address = address + field_offset;
                    address = U16_AT(item_address);
                    asm("" : : "r"(address));
                    if (address != empty_attachment)
                    {
                        register s32 model_id asm("r0");
                        register s32 equipment_id asm("r1");
                        register u32 held1 asm("r1"), held4 asm("r4");
                        address = unit_bytes + party;
                        unit_bytes = 0xD32;
                        asm("" : : "r"(address), "r"(unit_bytes));
                        address += unit_bytes;
                        asm("" : "=r"(held1));
                        model_id = S16_AT(address);
                        asm(""
                            :
                            : "r"(held1), "r"(model_id), "r"(row_index), "r"(item_address),
                              "r"(selected_unit_shift), "r"(attachment_row));
                        asm("" : "=r"(held4));
                        equipment_id = S16_AT(item_address);
                        asm(""
                            :
                            : "r"(held4), "r"(model_id), "r"(equipment_id), "r"(row_index),
                              "r"(selected_unit_shift), "r"(attachment_row));
                        func_0804D6D4(model_id, equipment_id, row_index);
                    }
                }
                {
                    register u32 next_row_shift asm("r0") = (u32)attachment_row << 16;
                    register u32 row_step asm("r1") = 0x10000;
                    asm("" : : "r"(next_row_shift), "r"(row_step));
                    next_row_shift += row_step;
                    attachment_row = next_row_shift >> 16;
                    next_row_shift = (s32)next_row_shift >> 16;
                    if ((s32)next_row_shift > 1)
                        break;
                }
            } while (1);
            func_0805EE78(1);
            func_08053150(1, 1, 10, 1);
            {
                register u32 window_base asm("r4");
                register u32 mask asm("r7");
                attachment_row = 0;
                window_base = 0x03004BBC;
                mask = 0x7FFF;
                asm("" : : "r"(attachment_row), "r"(window_base), "r"(mask));
                do
                {
                    register s32 window_index asm("r2") = (s16)attachment_row;
                    register u32 entry_index asm("r0");
                    register u32 entry_address asm("r1");
                    register u32 flags asm("r3");
                    asm("" : : "r"(window_index));
                    entry_index = window_index + 2;
                    entry_address = ((entry_index << 4) + entry_index) << 3;
                    entry_address += window_base;
                    flags = U16_AT(entry_address);
                    entry_index = mask;
                    asm("" : : "r"(entry_index), "r"(flags));
                    entry_index &= flags;
                    U16_AT(entry_address) = entry_index;
                    window_index += 1;
                    window_index <<= 16;
                    attachment_row = (u32)window_index >> 16;
                    window_index >>= 16;
                    if (window_index > 1)
                        break;
                } while (1);
            }
            {
                register u32 selected_slot_shift asm("r2") = slot_shift;
                register s32 selected_slot asm("r0") = (s32)selected_slot_shift >> 16;
                asm("" : : "r"(selected_slot_shift), "r"(selected_slot));
                if (selected_slot != 2)
                {
                    register u32 party asm("r2") = (u32)&player_state;
                    register s32 selected_unit asm("r1");
                    register u32 unit_bytes asm("r0");
                    register u32 field_offset asm("r4");
                    register u32 item_address asm("r3");
                    register u32 item_id asm("r1");
                    register u32 invalid_shift asm("r6");
                    register u32 invalid asm("r0");
                    asm("" : : "r"(party));
                    asm("" : "+r"(selected_unit_shift));
                    selected_unit = (s32)selected_unit_shift >> 16;
                    asm("" : : "r"(selected_unit));
                    unit_bytes = (((u32)selected_unit << 3) - selected_unit) << 3;
                    party = unit_bytes + party;
                    field_offset = 0xD46;
                    asm("" : : "r"(party), "r"(field_offset));
                    item_address = party + field_offset;
                    item_id = U16_AT(item_address);
                    invalid_shift = 0xFFFF0000;
                    asm("" : : "r"(item_id), "r"(invalid_shift));
                    invalid = invalid_shift >> 16;
                    asm("" : : "r"(invalid));
                    if (item_id != invalid)
                    {
                        register u32 model_offset asm("r7") = 0xD32;
                        register u32 model_address asm("r0");
                        register s32 model_id asm("r0");
                        register s32 equipment_id asm("r1");
                        register u32 held1 asm("r1"), held2 asm("r2"), held4 asm("r4");
                        asm("" : : "r"(model_offset));
                        model_address = party + model_offset;
                        asm("" : "=r"(held2), "=r"(held4));
                        model_id = S16_AT(model_address);
                        asm(""
                            :
                            : "r"(model_id), "r"(held2), "r"(item_address), "r"(held4),
                              "r"(selected_unit_shift), "r"(invalid_shift), "r"(model_offset));
                        equipment_id = S16_AT(item_address);
                        asm(""
                            :
                            : "r"(model_id), "r"(equipment_id), "r"(item_address), "r"(held4),
                              "r"(selected_unit_shift), "r"(invalid_shift), "r"(model_offset));
                        func_0804D6D4(model_id, equipment_id, 2);
                    }
                }
            }
            func_0805EE78(1);
            {
                register u16 *display asm("r2") = (u16 *)0x04000000;
                register u32 flags asm("r0");
                register u32 enabled asm("r3");
                register u32 mask asm("r1");
                flags = *(u16 *volatile)display;
                asm("" : : "r"(flags));
                enabled = 0x1200;
                asm("" : : "r"(enabled));
                mask = enabled;
                asm("" : : "r"(mask));
                flags |= mask;
                *display = flags;
            }
            RUN(0x0875B1F0, 0);
            {
                register u32 slot_load asm("r6") = slot_shift;
                attachment_slot = (s32)slot_load >> 16;
                asm("" : : "r"(slot_load), "r"(attachment_slot));
                func_08001848(attachment_slot + 1, 1, 0);
            }
            {
                register const u8 *slot_definition asm("r4");
                register s32 slot_kind asm("r1");
                {
                    register const u8 *model_load asm("r7");
                    attachment_slot <<= 2;
                    asm("" : : "r"(attachment_slot));
                    model_load = model;
                    asm("" : : "r"(model_load));
                    slot_definition = model_load + attachment_slot;
                }
                ((s32 volatile)slot_kind) = U16_AT((const u8 *volatile)slot_definition + 8);
                switch ((s32 volatile)slot_kind)
                {
                case 1:
                    RUN(0x0875B304, 2);
                    build_player_equipment_selection(1);
                    break;
                case 2:
                    RUN(0x0875B304, 3);
                    build_player_equipment_selection(14);
                    break;
                case 3:
                    RUN(0x0875B304, 4);
                    build_player_equipment_selection(15);
                    break;
                }
            }
            LAYOUT(0x1B);
            {
                register u32 initial_page asm("r0");
                register u16 *initial_cursor asm("r3");
                register u32 invalid_page asm("r1"), invalid_item asm("r2");
                ((u32 volatile)initial_page) = 0;
                page = (u32 volatile)initial_page;
                invalid_page = 0xFFFF;
                asm("" : : "r"(invalid_page));
                previous_page = invalid_page;
                invalid_item = 0xFFFE;
                asm("" : : "r"(invalid_item));
                previous_equipment_index = invalid_item;
                ((u16 *volatile)initial_cursor) = (u16 *)0x02007588;
                *(u16 *volatile)initial_cursor = (u32 volatile)initial_page;
            }
            asm("" : "+r"(selected_unit_shift));
            selected_unit_shift = (s32)selected_unit_shift >> 16;
            asm("" : : "r"(selected_unit_shift));
            equipment_zoid = selected_unit_shift;
            for (;;)
            {
                u32 party_value;
                register u32 item_choice asm("r9");
                register u32 item_choice_shift asm("r10");
                register s32 item_choice_index asm("r8");
                register s32 prior_item_index asm("r7");
                register union RegisterHalf item_page asm("r7");
                register s32 current_page asm("r4"), old_page asm("r0");
                register const u8 **input_layout asm("r6");
                register u16 *equipment_reply asm("r5");
                register u32 input_action asm("r0");
                {
                    register u32 page_load asm("r4") = page;
                    register u32 page_shift asm("r1");
                    register u32 previous_load asm("r6");
                    register u32 prior_item asm("r1");
                    asm("" : : "r"(page_load));
                    page_shift = page_load << 16;
                    current_page = (s32)page_shift >> 16;
                    asm("" : : "r"(page_shift), "r"(current_page));
                    previous_load = previous_page;
                    asm("" : : "r"(previous_load));
                    old_page = previous_load << 16;
                    old_page >>= 16;
                    item_page.word = page_shift;
                    asm("" : "+r"(item_page.word));
                    prior_item = previous_equipment_index;
                    asm("" : : "r"(prior_item));
                    prior_item <<= 16;
                    previous_equipment_shift = prior_item;
                }
                if (current_page != old_page)
                {
                    register u32 item_row asm("r6");
                    register u32 first_row_shift asm("r0");
                    register u32 first_row_word asm("r4");
                    register s32 first_row_index asm("r0");
                    register u8 *item_count asm("r12");
                    register u8 *count_address asm("r1");
                    {
                        register s32 invalid asm("r2") = -1;
                        asm("" : : "r"(invalid));
                        if (old_page != invalid)
                            LAYOUT(2);
                    }
                    item_row = 0;
                    first_row_shift = (u32)current_page << 18;
                    {
                        register u32 decrement asm("r3") = 0xFFFF0000;
                        asm("" : : "r"(first_row_shift), "r"(decrement));
                        first_row_shift += decrement;
                    }
                    first_row_word = first_row_shift >> 16;
                    asm("" : : "r"(first_row_word));
                    last_row = first_row_word;
                    first_row_index = (s32)first_row_shift >> 16;
                    asm("" : : "r"(first_row_index));
                    count_address = &equipment_selection_count;
                    asm("" : : "r"(count_address));
                    item_count = count_address;
                    asm("" : : "r"(item_count));
                    if (first_row_index < *count_address)
                    {
                        register s32 unequip_index asm("r8");
                        register const u8 **item_names asm("r5");
                        {
                            register s32 invalid asm("r2") = -1;
                            asm("" : : "r"(invalid));
                            unequip_index = invalid;
                        }
                        item_names = (const u8 **)0x0866634C;
                        asm("" : : "r"(item_names));
                    equipment_item_row:
                    {
                        register u32 row_load asm("r3") = last_row;
                        register s32 row_index asm("r0");
                        asm("" : : "r"(row_load));
                        row_index = row_load << 16;
                        row_index >>= 16;
                        asm("" : : "r"(row_index));
                        if (row_index == unequip_index)
                            RUN(0x0875B1F0, 5);
                        else
                        {
                            register const u8 *id_address asm("r4") = equipment_selection_ids;
                            asm("" : : "r"(id_address));
                            id_address = (const u8 *)((u32)row_index + (u32)id_address);
                            asm("" : "+r"(id_address));
                            script_run_table(item_names, *id_address);
                            func_0804D604((void *)item_names, *id_address, 8);
                            LAYOUT(0x28);
                            {
                                register u32 quantity_item asm("r0") = *id_address;
                                register const u8 *quantity_values asm("r4");
                                asm("" : : "r"(quantity_item));
                                quantity_values = equipment_quantities;
                                asm("" : : "r"(quantity_values));
                                func_08001848(*(const u8 *)(quantity_item + (u32)quantity_values),
                                              1, 2);
                            }
                        }
                        {
                            register s32 signed_row asm("r0") = (s16)item_row;
                            asm("" : : "r"(signed_row));
                            if (signed_row <= 2)
                            {
                                register u32 last_load asm("r0") = last_row;
                                register s32 last_index asm("r1") = (s16)last_load;
                                register const u8 *count_pointer asm("r0");
                                register s32 count_value asm("r0");
                                asm("" : : "r"(last_load), "r"(last_index));
                                count_pointer = &equipment_selection_count;
                                count_value = *count_pointer;
                                count_value -= 1;
                                if (last_index < count_value)
                                    RUN(0x08675C5C, 0);
                            }
                        }
                        {
                            register u32 next_row_shift asm("r0") = (u32)item_row << 16;
                            register u32 row_step asm("r1");
                            register s32 next_row asm("r1");
                            register u8 *next_count asm("r2");
                            asm("" : "+r"(next_row_shift));
                            row_step = 0x10000;
                            asm("" : : "r"(row_step));
                            next_row_shift += row_step;
                            item_row = next_row_shift >> 16;
                            next_row = (s32)next_row_shift >> 16;
                            asm("" : : "r"(next_row));
                            next_count = &equipment_selection_count;
                            asm("" : : "r"(next_count));
                            item_count = next_count;
                            asm("" : : "r"(item_count));
                            if (next_row <= 3)
                            {
                                register u32 next_index asm("r0") = (s32)item_page.word >> 14;
                                register u32 narrowed_index asm("r3");
                                register s32 count_value asm("r1");
                                next_index = next_row + next_index;
                                next_index -= 1;
                                next_index <<= 16;
                                narrowed_index = next_index >> 16;
                                asm("" : : "r"(narrowed_index));
                                last_row = narrowed_index;
                                next_index = (s32)next_index >> 16;
                                count_value = *next_count;
                                asm("" : : "r"(count_value));
                                if ((s32)next_index < count_value)
                                    goto equipment_item_row;
                            }
                        }
                    }
                    }
                    {
                        register s32 current_row asm("r0");
                        register u16 *cursor_destination asm("r2");
                        register u8 *page_windows asm("r3");
                        register s32 current_cursor asm("r4");
                        current_row = (s16)item_row;
                        asm("" : : "r"(current_row));
                        cursor_destination = (u16 *)0x02007588;
                        asm("" : : "r"(cursor_destination));
                        page_windows = (u8 *)text_windows;
                        asm("" : "+r"(page_windows));
                        current_cursor = *cursor_destination;
                        asm("" : : "r"(current_cursor));
                        if (current_row <= current_cursor)
                        {
                            register u32 clamped_cursor asm("r0");
                            register u8 *cursor_byte asm("r6");
                            clamped_cursor = item_row - 1;
                            asm("" : "+r"(clamped_cursor));
                            cursor_byte = (u8 *)0x02007C55;
                            asm("" : : "r"(cursor_byte));
                            *cursor_byte = clamped_cursor;
                            *cursor_destination = (u8)clamped_cursor;
                        }
                        {
                            register u32 flags_offset asm("r0") = 0x6B7;
                            register u8 *page_flags asm("r2");
                            asm("" : : "r"(flags_offset));
                            page_flags = page_windows + flags_offset;
                            asm("" : : "r"(page_flags));
                            {
                                register u32 spare_zero asm("r3") = 0;
                                register u32 stored_zero asm("r0") = 0;
                                asm("" : : "r"(spare_zero), "r"(stored_zero));
                                *page_flags = stored_zero;
                            }
                            asm("" : "+r"(item_page.word));
                            if ((s32)item_page.word > 0)
                                *page_flags = 1;
                            {
                                register u32 flags_row_word asm("r4");
                                register s32 flags_row asm("r1");
                                register u8 *flags_count asm("r6");
                                flags_row_word = last_row;
                                asm("" : : "r"(flags_row_word));
                                flags_row = (s16)flags_row_word;
                                asm("" : : "r"(flags_row));
                                flags_count = item_count;
                                asm("" : : "r"(flags_count));
                                if (flags_row < *flags_count - 1)
                                    *page_flags |= 2;
                            }
                        }
                    }
                    {
                        register u32 stored_page asm("r0") = item_page.word >> 16;
                        asm("" : : "r"(stored_page));
                        previous_page = stored_page;
                    }
                }
                {
                    register s32 row_index asm("r0") = (s32)item_page.word >> 14;
                    register const u16 *cursor asm("r1");
                    register u32 cursor_value asm("r1");
                    register u32 choice_load asm("r2");
                    register u32 prior_load asm("r3");
                    asm("" : : "r"(row_index));
                    cursor = (const u16 *)0x02007588;
                    cursor_value = *cursor;
                    asm("" : : "r"(cursor_value));
                    row_index += cursor_value;
                    row_index -= 1;
                    row_index <<= 16;
                    row_index = (u32)row_index >> 16;
                    item_choice = row_index;
                    asm("" : : "r"(item_choice));
                    choice_load = item_choice;
                    asm("" : : "r"(choice_load));
                    choice_load <<= 16;
                    item_choice_shift = choice_load;
                    asm("" : : "r"(item_choice_shift));
                    choice_load = (s32)choice_load >> 16;
                    item_choice_index = choice_load;
                    asm("" : : "r"(item_choice_index));
                    prior_load = previous_equipment_shift;
                    asm("" : : "r"(prior_load));
                    prior_item_index = (s32)prior_load >> 16;
                    asm("" : : "r"(prior_item_index));
                }
                if (item_choice_index != prior_item_index)
                {
                    register u32 empty_item_shift asm("r4");
                    register u32 equipment_unit_offset asm("r5");
                    register s32 equipment_slot asm("r6");
                    register u32 completed_choice_shift asm("r7");
                    register u32 empty_item asm("r3");
                    register u8 *initial_equipment asm("r1");
                    register u32 initial_equipment_id asm("r0");
                    register s32 empty_index asm("r0");
                    if (prior_item_index != -2)
                    {
                        register u32 windows asm("r2") = 0x03004BBC;
                        register u32 slot_load asm("r4");
                        register s32 window_index asm("r1");
                        register u32 window_address asm("r0");
                        register u32 flags asm("r1");
                        register u32 retained asm("r6");
                        asm("" : : "r"(windows));
                        slot_load = slot_shift;
                        asm("" : : "r"(slot_load));
                        window_index = (s32)slot_load >> 16;
                        window_index += 2;
                        asm("" : : "r"(window_index));
                        window_address = ((window_index << 4) + window_index) << 3;
                        window_address += windows;
                        flags = U16_AT(window_address);
                        retained = 0x7FFF;
                        asm("" : : "r"(flags), "r"(retained));
                        windows = retained;
                        asm("" : : "r"(windows));
                        flags &= windows;
                        U16_AT(window_address) = flags;
                        LAYOUT(0);
                    }
                    LAYOUT(0x19);
                    {
                        register u32 unit_index asm("r1");
                        register u32 unit_stride asm("r0");
                        unit_index = equipment_zoid;
                        asm("" : : "r"(unit_index));
                        unit_stride = (unit_index << 3) - unit_index;
                        asm("" : "+r"(unit_stride));
                        equipment_unit_offset = unit_stride << 3;
                        asm("" : "+r"(equipment_unit_offset));
                    }
                    initial_equipment = (u8 *)0x02001898;
                    asm("" : "+r"(initial_equipment));
                    initial_equipment = (u8 *)(equipment_unit_offset + (u32)initial_equipment);
                    asm("" : "+r"(initial_equipment));
                    {
                        register u32 slot_load asm("r2") = slot_shift;
                        asm("" : : "r"(slot_load));
                        equipment_slot = (s32)slot_load >> 16;
                        asm("" : : "r"(equipment_slot));
                    }
                    initial_equipment += equipment_slot * 4;
                    asm("" : : "r"(initial_equipment));
                    chosen_item = initial_equipment;
                    initial_equipment_id = U16_AT(initial_equipment + 2);
                    asm("" : : "r"(initial_equipment_id));
                    empty_item_shift = 0xFFFF0000;
                    asm("" : "+r"(empty_item_shift));
                    empty_item = empty_item_shift >> 16;
                    if (initial_equipment_id != empty_item)
                    {
                        register u32 current_pilot_selector asm("r1");
                        register s32 current_signed_selector asm("r0");
                        register const u8 *current_pilot_ids asm("r2");
                        register u32 current_pilot asm("r0");
                        current_pilot_selector = selected_index;
                        asm("" : : "r"(current_pilot_selector));
                        current_signed_selector = (s16)current_pilot_selector;
                        asm("" : "+r"(current_signed_selector));
                        current_pilot_ids = pilot_selection_ids;
                        asm("" : : "r"(current_pilot_ids));
                        current_pilot =
                            *(const u8 *)((u32)current_signed_selector + (u32)current_pilot_ids);
                        asm("" : : "r"(current_pilot));
                        {
                            register u8 *current_equipment asm("r2");
                            current_equipment = chosen_item;
                            asm("" : "+r"(current_equipment));
                            {
                                register u32 current_id asm("r1") = U16_AT(current_equipment + 2);
                                register void *stats asm("r2") = (void *)0x0200E7C4;
                                asm(""
                                    :
                                    : "r"(current_pilot), "r"(current_id), "r"(stats),
                                      "r"(empty_item));
                                call_scratch.item = empty_item;
                                build_equipment_stats(current_pilot, current_id, stats);
                                empty_item = call_scratch.item;
                                asm("" : : "r"(empty_item));
                            }
                        }
                    }
                    empty_index = (s32)empty_item_shift >> 16;
                    asm("" : : "r"(empty_index));
                    if (item_choice_index == empty_index)
                    {
                        register u8 *current_item asm("r4") = chosen_item;
                        asm("" : : "r"(current_item));
                        if (U16_AT(current_item + 2) == empty_item)
                            goto equipment_preview_empty;
                        {
                            {
                                register u32 held0 asm("r0"), held2 asm("r2");
                                register u32 address asm("r0");
                                register u32 field_offset asm("r1");
                                register s32 model_id asm("r0");
                                register s32 item_id asm("r1");
                                register s32 selected_slot asm("r2");
                                register u32 applied asm("r0");
                                register u32 held1 asm("r1");
                                asm(""
                                    : "=&l"(party_value), "=r"(held0), "=r"(held1), "=r"(held2)
                                    : "0"((u32)&player_state), "r"(empty_item), "r"(current_item),
                                      "r"(equipment_unit_offset), "r"(equipment_slot));
                                asm("" : : "l"(party_value), "r"(held0), "r"(held1), "r"(held2));
                                address = equipment_unit_offset + party_value;
                                field_offset = 0xD32;
                                asm("" : : "r"(address), "r"(field_offset));
                                address += field_offset;
                                asm("" : "=r"(held1));
                                model_id = S16_AT(address);
                                asm(""
                                    :
                                    : "r"(model_id), "r"(held1), "r"(empty_item), "r"(current_item),
                                      "l"(party_value));
                                asm("" : "=r"(selected_slot));
                                item_id = S16_AT(current_item + 2);
                                asm("" : : "r"(selected_slot));
                                asm(""
                                    :
                                    : "r"(model_id), "r"(item_id), "r"(empty_item),
                                      "r"(current_item), "r"(equipment_unit_offset),
                                      "r"(equipment_slot));
                                selected_slot = equipment_slot;
                                asm(""
                                    :
                                    : "r"(model_id), "r"(item_id), "r"(selected_slot),
                                      "r"(empty_item));
                                call_scratch.item = empty_item;
                                applied = (u32)func_0804D6D4(model_id, item_id, selected_slot)
                                          << 24;
                                asm("" : : "r"(applied));
                                empty_item = call_scratch.item;
                                asm("" : : "r"(empty_item));
                                if (applied != 0)
                                {
                                    func_08003DF8(6, func_0804D85C);
                                    U32_AT(0x0200036C) = equipment_slot;
                                    empty_item = call_scratch.item;
                                    asm("" : : "r"(empty_item));
                                }
                            }
                        }
                        {
                            register u8 *stored_item asm("r1") = chosen_item;
                            asm("" : : "r"(stored_item));
                            if (U16_AT(stored_item + 2) != empty_item)
                            {
                                func_0804DDB4((void *)0x0200E7C4);
                                completed_choice_shift = item_choice_shift;
                            }
                            else
                            {
                            equipment_preview_empty:
                                RUN(0x0875B304, 1);
                                {
                                    register u32 choice_copy asm("r2") = item_choice;
                                    asm("" : : "r"(choice_copy));
                                    completed_choice_shift = choice_copy << 16;
                                }
                            }
                        }
                    }
                    else
                    {
                        register s32 preview_model asm("r0");
                        register const u8 *preview_equipment asm("r4");
                        register const u8 *preview_equipment_ids asm("r1");
                        register u32 preview_choice_shift asm("r5");
                        register u32 preview_pilot_selector asm("r7");
                        register u32 preview_unit asm("r6");
                        register u32 preview_address asm("r0");

                        register u32 preview_offset asm("r1");
                        register u32 choice_copy asm("r3");
                        register u32 slot_copy asm("r6");
                        register s32 preview_slot asm("r2");
                        register s32 preview_signed_pilot asm("r0");
                        register const u8 *preview_pilot_ids asm("r1");
                        register u32 preview_pilot asm("r0");
                        if (prior_item_index == empty_index)
                        {
                            register u8 *current_item asm("r4") = chosen_item;
                            asm("" : : "r"(current_item));
                            if (U16_AT(current_item + 2) != empty_item)
                                func_08003E3C(6);
                        }
                        preview_unit = equipment_zoid;
                        asm("" : : "r"(preview_unit));
                        preview_address = ((preview_unit << 3) - preview_unit) << 3;
                        party_value = (u32)&player_state;
                        asm("" : : "r"(preview_address), "l"(party_value));
                        preview_address += party_value;
                        preview_offset = 0xD32;
                        asm("" : : "r"(preview_address), "r"(preview_offset));
                        preview_address += preview_offset;
                        {
                            register u32 held1 asm("r1"), held3 asm("r3"), held4 asm("r4");
                            register u32 held5 asm("r5"), held6 asm("r6");
                            asm(""
                                : "=r"(held1), "=r"(held3), "=r"(held4), "=r"(held5), "=r"(held6));
                            preview_model = S16_AT(preview_address);
                            asm(""
                                :
                                : "r"(preview_model), "r"(held1), "r"(held3), "r"(held4),
                                  "r"(held5), "r"(held6), "l"(party_value));
                        }
                        preview_equipment_ids = equipment_selection_ids;
                        asm("" : : "r"(preview_equipment_ids));
                        choice_copy = item_choice;
                        asm("" : : "r"(choice_copy));
                        preview_choice_shift = choice_copy << 16;
                        asm("" : "+r"(preview_choice_shift));
                        preview_equipment = (const u8 *)(((s32)preview_choice_shift >> 16) +
                                                         (u32)preview_equipment_ids);
                        asm("" : "+r"(preview_equipment));
                        {
                            register u32 preview_item asm("r1") = *preview_equipment;
                            asm("" : : "r"(preview_item));
                            slot_copy = slot_shift;
                            asm("" : : "r"(slot_copy));
                            preview_slot = (s32)slot_copy >> 16;
                            asm("" : : "r"(preview_slot));
                            func_0804D6D4(preview_model, preview_item, preview_slot);
                        }
                        preview_pilot_selector = selected_index;
                        asm("" : : "r"(preview_pilot_selector));
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } selected_pair asm("r6");
                            selected_pair.part.high = preview_pilot_selector;
                            preview_signed_pilot = (s16)selected_pair.part.high;
                            asm("" : : "r"(selected_pair.part.high), "r"(preview_signed_pilot));
                        }
                        asm("" : "+r"(preview_signed_pilot));
                        preview_pilot_ids = pilot_selection_ids;
                        asm("" : : "r"(preview_pilot_ids));
                        preview_pilot =
                            *(const u8 *)((u32)preview_signed_pilot + (u32)preview_pilot_ids);
                        asm("" : : "r"(preview_pilot));
                        build_equipment_stats(preview_pilot, *preview_equipment,
                                              (void *)0x0200E7DC);
                        func_0804DDB4((void *)0x0200E7DC);
                        completed_choice_shift = preview_choice_shift;
                    }
                    asm("" : "+r"(completed_choice_shift));
                    RUN_UNCACHED(menu_layout_scripts, 0x18);
                    RUN_UNCACHED(menu_layout_scripts, 0x1B);
                    {
                        register u32 completed_item_index asm("r2");
                        ((u32 volatile)completed_item_index) = (u16)(completed_choice_shift >> 16);
                        asm("" : : "r"(completed_item_index));
                        previous_equipment_index = (u32 volatile)completed_item_index;
                    }
                }
                input_layout = menu_layout_scripts;
                asm("" : "+r"(input_layout));
                script_run_table(input_layout, 0x23);
                equipment_reply = (u16 *)0x02007574;
                asm("" : "+r"(equipment_reply));
                input_action = equipment_reply[0];
                if (input_action == 0)
                {
                    register u32 cancel_choice_word asm("r3");
                    register s32 cancel_choice asm("r0");
                    register s32 unequip_choice asm("r4");
                    register u32 empty_part_shift asm("r2");
                    func_080019EC(0x3F);
                    cancel_choice_word = item_choice;
                    asm("" : "+r"(cancel_choice_word));
                    cancel_choice = (s16)cancel_choice_word;
                    asm("" : "+r"(cancel_choice));
                    unequip_choice = -1;
                    asm("" : : "r"(unequip_choice));
                    empty_part_shift = (u32)unequip_choice << 16;
                    asm("" : "+r"(empty_part_shift));
                    if (cancel_choice == unequip_choice)
                    {
                        register u8 *cancel_equipment asm("r6");
                        register u32 cancel_item_id asm("r1");
                        register u32 cancel_empty_id asm("r0");
                        ((u8 *volatile)cancel_equipment) = chosen_item;
                        asm("" : : "r"(cancel_equipment));
                        ((u32 volatile)cancel_item_id) = U16_AT((u8 *volatile)cancel_equipment + 2);
                        ((u32 volatile)cancel_empty_id) = empty_part_shift >> 16;
                        asm("" : : "r"(cancel_item_id), "r"(cancel_empty_id));
                        if ((u32 volatile)cancel_item_id != (u32 volatile)cancel_empty_id)
                            func_08003E3C(6);
                    }
                    goto equipment_list_done;
                }
                if (input_action == 1)
                {
                    register u32 accepted_choice_shift asm("r7");
                    register u32 acceptance_existing_id asm("r1");
                    {
                        u8 *existing;
                        register u32 held0 asm("r0"), held2 asm("r2"), held3 asm("r3"),
                            held4 asm("r4");
                        asm("" : "=r"(acceptance_existing_id));
                        asm(""
                            : "=&l"(existing), "=r"(held0), "=r"(held2), "=r"(held3), "=r"(held4)
                            : "0"(chosen_item), "r"(acceptance_existing_id), "r"(equipment_reply),
                              "r"(input_layout));
                        acceptance_existing_id = *(u16 *)(existing + 2);
                        asm(""
                            :
                            : "l"(existing), "r"(acceptance_existing_id), "r"(held0), "r"(held2),
                              "r"(held3), "r"(held4), "r"(equipment_reply), "r"(input_layout));
                    }
                    {
                        register u32 invalid_shift asm("r2") = 0xFFFF0000;
                        register u32 invalid asm("r0");
                        register u32 choice_copy asm("r3");
                        asm("" : : "r"(invalid_shift));
                        invalid = invalid_shift >> 16;
                        asm("" : : "r"(invalid));
                        choice_copy = item_choice;
                        asm("" : : "r"(choice_copy));
                        accepted_choice_shift = choice_copy << 16;
                        asm("" : : "r"(accepted_choice_shift));
                        if (acceptance_existing_id != invalid)
                        {
                            register u8 *returned_quantity asm("r4") = chosen_item;
                            register u32 returned_item_id asm("r2");
                            register const u8 *quantities asm("r0");
                            register u32 returned_count asm("r3");
                            asm("" : : "r"(returned_quantity));
                            returned_item_id = U16_AT(returned_quantity + 2);
                            quantities = equipment_quantities;
                            asm("" : : "r"(returned_item_id), "r"(quantities));
                            returned_quantity = (u8 *)(returned_item_id + (u32)quantities);
                            ((u32 volatile)returned_count) = *returned_quantity;
                            if (returned_count <= 8 ||
                                returned_item_id ==
                                    equipment_selection_ids[((s32)accepted_choice_shift >> 16)])
                            {
                                register u32 next_stock asm("r0");
                                ((u32 volatile)next_stock) = returned_count + 1;
                                *returned_quantity = (u32 volatile)next_stock;
                            }
                            else
                            {
                                script_run_table(input_layout, 0);
                                script_run_table(input_layout, 0x19);
                                RUN(0x0875B1F0, 7);
                                {
                                    register u8 *current_item asm("r2") = chosen_item;
                                    register u32 current_id asm("r1");
                                    asm("" : : "r"(current_item));
                                    current_id = U16_AT(current_item + 2);
                                    RUN(0x0866634C, current_id);
                                }
                                RUN(0x0875B1F0, 8);
                                {
                                    register u16 *overflow_snapshot asm("r1");
                                    register u16 *overflow_cursor asm("r3");
                                    ((u16 *volatile)overflow_snapshot) = selected;
                                    ((u16 *volatile)overflow_cursor) = (u16 *)0x02007588;
                                    overflow_snapshot[2] = *overflow_cursor;
                                }
                                RUN(0x0875B068, 0x11);
                                {
                                    register u32 restored_cursor asm("r0");
                                    register u16 *overflow_cursor asm("r4");
                                    ((u32 volatile)restored_cursor) = selected[2];
                                    ((u16 *volatile)overflow_cursor) = (u16 *)0x02007588;
                                    *overflow_cursor = (u32 volatile)restored_cursor;
                                }
                                {
                                    u32 confirmation_action = equipment_reply[0];
                                    asm("" : : "r"(confirmation_action));
                                    if (confirmation_action != 1 || equipment_reply[1] != 0)
                                    {
                                        if (confirmation_action == 0)
                                            func_080019EC(0x3F);
                                        script_run_table(input_layout, 0);
                                        {
                                            register u32 invalid_index asm("r6") = 0xFFFE;
                                            asm("" : : "r"(invalid_index));
                                            previous_equipment_index = invalid_index;
                                        }
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    {
                        register s32 accepted_choice asm("r0");
                        register s32 unequip_choice asm("r7");
                        register u32 empty_part_shift asm("r1");
                        accepted_choice = (s32)accepted_choice_shift >> 16;
                        asm("" : "+r"(accepted_choice));
                        unequip_choice = -1;
                        asm("" : "+r"(unequip_choice));
                        empty_part_shift = (u32)unequip_choice << 16;
                        asm("" : "+r"(empty_part_shift));
                        {
                            register s32 no_item asm("r2") = unequip_choice;
                            asm("" : : "r"(no_item));
                            if (accepted_choice == no_item)
                            {
                                register u8 *unequip_existing asm("r3");
                                register u32 existing_item_id asm("r0");
                                register u32 empty_part asm("r4");
                                unequip_existing = chosen_item;
                                asm("" : "+r"(unequip_existing));
                                existing_item_id = U16_AT(unequip_existing + 2);
                                asm("" : "+r"(existing_item_id));
                                empty_part = empty_part_shift >> 16;
                                asm("" : "+r"(empty_part));
                                if (existing_item_id != empty_part)
                                    func_08003E3C(6);
                                {
                                    register u8 *unequip_stored asm("r6");
                                    unequip_stored = chosen_item;
                                    asm("" : "+r"(unequip_stored));
                                    {
                                        register u32 existing asm("r1") =
                                            U16_AT(unequip_stored + 2);
                                        register u32 combined asm("r0") = empty_part;
                                        asm("" : : "r"(existing), "r"(combined));
                                        combined |= existing;
                                        U16_AT(unequip_stored + 2) = combined;
                                    }
                                }
                            }
                            else
                            {
                                register const u8 *accepted_selection asm("r1");
                                accepted_selection = equipment_selection_ids;
                                asm("" : "+r"(accepted_selection));
                                accepted_selection =
                                    (const u8 *)((u32)accepted_choice + (u32)accepted_selection);
                                {
                                    register u32 item_id asm("r0") = *accepted_selection;
                                    u8 *destination;
                                    register u32 held2 asm("r2"), held3 asm("r3"), held4 asm("r4");
                                    register u32 held5 asm("r5"), held6 asm("r6");
                                    asm(""
                                        : "=&l"(destination), "=r"(held2), "=r"(held3), "=r"(held4),
                                          "=r"(held5), "=r"(held6)
                                        : "0"(chosen_item), "r"(item_id), "r"(accepted_selection));
                                    U16_AT(destination + 2) = item_id;
                                    asm(""
                                        :
                                        : "r"(held2), "r"(held3), "r"(held4), "r"(held5),
                                          "r"(held6));
                                }
                                {
                                    register u32 accepted_item_id asm("r1") = *accepted_selection;
                                    u8 *accepted_quantity = equipment_quantities + accepted_item_id;
                                    --*accepted_quantity;
                                }
                            }
                        }
                    }
                    {
                        register u32 equipped_pilot asm("r0");
                        register u32 pilot_selector asm("r1");
                        register s32 signed_pilot_selector asm("r0");
                        register const u8 *pilot_ids asm("r2");
                        register u32 equipped_unit asm("r3");
                        register u32 equipped_unit_sevens asm("r1");
                        register u32 equipped_unit_offset asm("r5");
                        register u8 *stats_origin asm("r6");
                        register ZoidStats *updated_stats asm("r4");
                        s32 *current_hp;
                        register s32 *current_ep asm("r2");
                        register s32 *maximum_ep asm("r0");
                        pilot_selector = selected_index;
                        asm("" : : "r"(pilot_selector));
                        signed_pilot_selector = (s16)pilot_selector;
                        asm("" : "+r"(signed_pilot_selector));
                        pilot_ids = pilot_selection_ids;
                        asm("" : : "r"(pilot_ids));
                        equipped_pilot = *(const u8 *)((u32)signed_pilot_selector + (u32)pilot_ids);
                        asm("" : : "r"(equipped_pilot));
                        equipped_unit = equipment_zoid;
                        asm("" : : "r"(equipped_unit));
                        equipped_unit_sevens = equipped_unit * 7;
                        asm("" : "+r"(equipped_unit_sevens));
                        equipped_unit_offset = equipped_unit_sevens << 3;
                        asm("" : "+r"(equipped_unit_offset));
                        stats_origin = (u8 *)0x020018B0;
                        asm("" : "+r"(stats_origin));
                        updated_stats = (ZoidStats *)(equipped_unit_offset + (u32)stats_origin);
                        asm("" : "+r"(updated_stats));
                        recalculate_zoid_stats(equipped_pilot, equipped_unit, updated_stats);
                        {
                            register u8 *hp_field_base asm("r0") = stats_origin - 0x20;
                            asm("" : "+r"(hp_field_base));
                            current_hp = (s32 *)(equipped_unit_offset + (u32)hp_field_base);
                        }
                        {
                            s32 hp = *current_hp;
                            s32 maximum_hp = updated_stats->maximum_hp;
                            if (hp > maximum_hp)
                                *current_hp = maximum_hp;
                        }
                        {
                            register u8 *ep_field_base asm("r0") = stats_origin - 0x1C;
                            asm("" : "+r"(ep_field_base));
                            current_ep = (s32 *)(equipped_unit_offset + (u32)ep_field_base);
                            asm("" : "+r"(current_ep));
                        }
                        maximum_ep = (s32 *)(stats_origin + 4);
                        asm("" : "+r"(maximum_ep));
                        maximum_ep = (s32 *)(equipped_unit_offset + (u32)maximum_ep);
                        {
                            s32 ep = *current_ep;
                            s32 maximum_ep_value = *maximum_ep;
                            if (ep > maximum_ep_value)
                                *current_ep = maximum_ep_value;
                        }
                    }
                    func_080019EC(0x4E);
                    goto equipment_list_done;
                }
                input_action = *(u16 *volatile)equipment_reply;
                asm("" : : "r"(input_action));
                if (input_action == 2)
                    goto equipment_page_left;
                if (input_action == 4)
                    goto equipment_page_right;
                continue;
            equipment_page_left:
            {
                register u32 next_page asm("r0");
                register u32 loaded_page asm("r4") = page;
                register s32 signed_page asm("r4");
                asm("" : : "r"(loaded_page));
                next_page = loaded_page << 16;
                signed_page = (s32)next_page >> 16;
                if (signed_page <= 0)
                    continue;
                func_080019EC(0x40);
                next_page = (signed_page - 1) << 16;
                goto equipment_page_save;
            equipment_page_right:
            {
                register u32 row_load asm("r6") = last_row;
                register s32 signed_row asm("r1");
                register s32 count_value asm("r0");
                asm("" : : "r"(row_load));
                signed_row = (s16)row_load;
                count_value = equipment_selection_count;
                count_value -= 1;
                if (signed_row >= count_value)
                    continue;
                func_080019EC(0x40);
                {
                    register u32 page_load asm("r7") = page;
                    register u32 increment asm("r1");
                    next_page = page_load << 16;
                    asm("" : : "r"(next_page));
                    increment = 0x10000;
                    asm("" : : "r"(increment));
                    next_page += increment;
                }
            }
            equipment_page_save:
                next_page >>= 16;
                page = next_page;
            }
            }
        equipment_list_done:
        {
            register s32 cleanup_slot asm("r4");
            register u32 cleanup_zero asm("r5");
            register u8 *cleanup_window_base asm("r2");
            cleanup_window_base = (u8 *)0x03004BBC;
            asm("" : : "r"(cleanup_window_base));
            {
                register u32 slot_load asm("r3") = slot_shift;
                asm("" : : "r"(slot_load));
                cleanup_slot = (s32)slot_load >> 16;
                asm("" : : "r"(cleanup_slot));
            }
            {
                register u16 *cleanup_window asm("r0");
                register u32 window_flags asm("r2");
                register u32 window_mask asm("r1");
                cleanup_window = (u16 *)((cleanup_slot + 2) * 136 + (u32)cleanup_window_base);
                asm("" : "+r"(cleanup_window));
                window_flags = *cleanup_window;
                asm("" : : "r"(window_flags));
                window_mask = 0x7FFF;
                asm("" : : "r"(window_mask));
                window_mask &= window_flags;
                cleanup_zero = 0;
                asm("" : "+r"(cleanup_zero));
                *cleanup_window = window_mask;
            }
            {
                register u16 *cleanup_footer asm("r6") = (u16 *)0x03004DDC;
                asm("" : : "r"(cleanup_footer));
                {
                    register u32 flags asm("r1") = *cleanup_footer;
                    register u32 mask asm("r0") = 0x7FFF;
                    asm("" : : "r"(flags), "r"(mask));
                    mask &= flags;
                    *cleanup_footer = mask;
                }
            }
            dma_fill = 0x01340134;
            {
                register volatile u32 *dma_controller asm("r1") = (volatile u32 *)0x040000D4;
                asm("" : : "r"(dma_controller));
                {
                    register u32 *source asm("r7") = dma_source;
                    asm("" : : "r"(source));
                    dma_controller[0] = (u32)source;
                }
                dma_controller[1] = 0x03002B9C;
                dma_controller[2] = 0x85000400;
                (void)dma_controller[2];
            }
            RUN_UNCACHED(menu_layout_scripts, 0xA);
            RUN_UNCACHED(menu_layout_scripts, 9);
            RUN_UNCACHED(menu_layout_scripts, 0);
            if (cleanup_slot == 2)
                U16_AT(0x04000050) = cleanup_zero;
        }
        }
        case 0x3FFF:
        {
            register u32 final_row asm("r6");
            register u32 final_page_rows asm("r8");
            register const u8 *final_roster asm("r9");
            register u8 *party_address asm("r2");
            const u8 *final_count;
            register const u8 *initial_count asm("r1");
            register u32 initial_count_value asm("r7");
            register u32 initial_page_rows asm("r2");
            register u32 initial_shift asm("r0");
            RUN(0x0875B1B8, 0);
            page = pages[1];
            {
                register u32 selected_value asm("r0");
                register u32 byte_address asm("r1");
                register u32 cursor_address asm("r2");
                ((volatile u32)selected_value) = selected[1];
                ((volatile u32)byte_address) = (u32)saved_selection;
                asm("" : : "r"(selected_value), "r"(byte_address));
                U8_AT((volatile u32)byte_address) = (volatile u32)selected_value;
                ((volatile u32)selected_value) <<= 24;
                ((volatile u32)selected_value) >>= 24;
                ((volatile u32)cursor_address) = 0x02007588;
                U16_AT((volatile u32)cursor_address) = (volatile u32)selected_value;
            }
            LAYOUT(0x1C);
            final_row = 0;
            {
                register u32 page_load asm("r3");
                register s32 signed_page asm("r1");
                register u32 narrowed asm("r4");
                ((volatile u32)page_load) = page;
                asm("" : "+r"(page_load));
                ((volatile s32)signed_page) = page_load << 16;
                ((volatile s32)signed_page) >>= 16;
                ((volatile u32)initial_shift) = (volatile s32)signed_page * 3;
                initial_page_rows = (volatile u32)initial_shift << 1;
                asm("" : "+r"(initial_page_rows));
                ((volatile u32)initial_shift) <<= 17;
                narrowed = (volatile u32)initial_shift >> 16;
                asm("" : "+r"(narrowed));
                last_row = narrowed;
                ((volatile u32)initial_shift) = (s32)(volatile u32)initial_shift >> 16;
            }
            ((const u8 *volatile)initial_count) = &pilot_selection_count;
            initial_count_value = *(const u8 *volatile)initial_count;
            asm("" : : "r"(initial_count_value));
            if ((s32)(volatile u32)initial_shift < (s32)initial_count_value)
            {
                final_count = (const u8 *volatile)initial_count;
                asm("" : "+l"(final_count));
                {
                    register const u8 *initial_roster asm("r0");
                    ((const u8 *volatile)initial_roster) = pilot_selection_ids;
                    asm("" : "+r"(initial_roster));
                    final_roster = (const u8 *volatile)initial_roster;
                }
                final_page_rows = initial_page_rows;
            final_pilot_row:
            {
                register u32 final_row_shift asm("r5");
                register s32 final_index asm("r4");
                {
                    register u32 index_load asm("r1");
                    register u32 index_shift asm("r0");
                    register const u8 *roster_copy asm("r2");
                    ((volatile u32)index_load) = last_row;
                    asm("" : "+r"(index_load));
                    ((volatile u32)index_shift) = (volatile u32)index_load << 16;
                    final_index = (s32)(volatile u32)index_shift >> 16;
                    ((const u8 *volatile)roster_copy) = (const u8 *volatile)final_roster;
                    asm("" : "+r"(roster_copy));
                    ((volatile u32)index_shift) =
                        final_index + (u32)(const u8 *volatile)roster_copy;
                    func_08032818(U8_AT((volatile u32)index_shift));
                }
                {
                    register u32 raw_shift asm("r0");
                    register s32 signed_row asm("r1");
                    ((volatile u32)raw_shift) = final_row << 16;
                    ((volatile s32)signed_row) = (s32)(volatile u32)raw_shift >> 16;
                    final_row_shift = (volatile u32)raw_shift;
                    asm("" : : "r"(signed_row), "r"(final_row_shift));
                    if ((volatile s32)signed_row <= 4 && final_index < *final_count - 1)
                        RUN(0x08675C5C, 0);
                }
                {
                    register u32 increment asm("r3");
                    register u32 next_row asm("r0");
                    ((volatile u32)increment) = 0x10000;
                    asm("" : : "r"(increment));
                    ((volatile u32)next_row) =
                        (volatile u32)final_row_shift + (volatile u32)increment;
                    final_row = (volatile u32)next_row >> 16;
                    ((volatile u32)next_row) = (s32)(volatile u32)next_row >> 16;
                    if ((s32)(volatile u32)next_row > 5)
                        goto final_pilot_rows_done;
                    ((volatile u32)next_row) += (volatile u32)final_page_rows;
                    ((volatile u32)next_row) <<= 16;
                    {
                        register u32 narrowed asm("r4");
                        narrowed = (volatile u32)next_row >> 16;
                        asm("" : "+r"(narrowed));
                        last_row = narrowed;
                    }
                    ((volatile u32)next_row) = (s32)(volatile u32)next_row >> 16;
                    {
                        register u32 next_count asm("r1");
                        next_count = *final_count;
                        asm("" : "+r"(next_count));
                        if ((s32)(volatile u32)next_row < (s32)next_count)
                            goto final_pilot_row;
                    }
                }
            }
            }
        final_pilot_rows_done:
        {
            register u8 *arrow asm("r3");
            register u32 page_load asm("r6");
            register union RegisterHalf page_copy asm("r4");
            register s32 signed_page asm("r2");
            register u16 clear_value asm("r5");
            {
                register u8 *windows asm("r2");
                register u32 offset asm("r4");
                ((u8 *volatile)windows) = (u8 *)text_windows;
                ((volatile u32)offset) = 0xA0B;
                asm("" : : "r"(windows), "r"(offset));
                ((u8 *volatile)arrow) = (u8 *volatile)windows + (volatile u32)offset;
            }
            clear_value = 0;
            asm("" : : "r"(arrow), "r"(clear_value));
            {
                register u32 store_zero asm("r0");
                store_zero = clear_value;
                asm("" : "+r"(store_zero));
                *(volatile u8 *)(u8 *volatile)arrow = store_zero;
            }
            ((volatile u32)page_load) = page;
            asm("" : "+r"(page_load));
            page_copy.word = page_load << 16;
            signed_page = page_copy.halves[1];
            if ((volatile s32)signed_page > 0)
                *(volatile u8 *)(u8 *volatile)arrow = 1;
            {
                register u32 last_load asm("r7");
                register s32 last_signed asm("r1");
                ((volatile u32)last_load) = last_row;
                asm("" : "+r"(last_load));
                ((volatile s32)last_signed) = last_load << 16;
                ((volatile s32)last_signed) >>= 16;
                if ((volatile s32)last_signed < pilot_selection_count - 1)
                    *(volatile u8 *)(u8 *volatile)arrow |= 2;
            }
            previous_page = page_copy.word >> 16;
            {
                register u32 index_value asm("r0");
                register u32 cursor asm("r1");
                ((volatile u32)index_value) = (volatile s32)signed_page * 3;
                ((volatile u32)index_value) <<= 1;
                ((volatile u32)cursor) = 0x02007588;
                ((volatile u32)cursor) = U16_AT((volatile u32)cursor);
                ((volatile u32)index_value) += (volatile u32)cursor;
                ((volatile u32)index_value) <<= 16;
                {
                    register const u8 *ids asm("r1");
                    register u32 selected_word asm("r3");
                    ((u8 *volatile)party_address) = (u8 *)&player_state;
                    ((const u8 *volatile)ids) = pilot_selection_ids;
                    selected_word = (volatile u32)index_value >> 16;
                    asm("" : : "r"(party_address), "r"(ids), "r"(selected_word));
                    selected_index = selected_word;
                    ((volatile u32)index_value) = (s32)(volatile u32)index_value >> 16;
                    ((volatile u32)index_value) += (u32)ids;
                    ((volatile u32)index_value) = U8_AT((volatile u32)index_value);
                    ((volatile u32)index_value) <<= 2;
                    ((volatile u32)index_value) += (u32)(u8 *volatile)party_address;
                    ((volatile u32)page_copy.word) = 0x34A6;
                    asm("" : : "r"(page_copy.word));
                    ((volatile u32)index_value) += (volatile u32)page_copy.word;
                    ((volatile u32)index_value) = U8_AT((volatile u32)index_value);
                    selected_zoid = index_value;
                }
            }
        }
            {
                register u32 zoid_offset asm("r0");
                register u32 zoid_copy asm("r6");
                register u32 id_offset asm("r7");
                register u8 *zoid_id asm("r4");
                ((volatile u32)zoid_offset) = selected_zoid << 3;
                asm("" : "+m"(selected_zoid) : "r"(zoid_offset));
                ((volatile u32)zoid_copy) = selected_zoid;
                asm("" : "+r"(zoid_copy));
                ((volatile u32)zoid_offset) -= (volatile u32)zoid_copy;
                ((volatile u32)zoid_offset) <<= 3;
                base = (volatile u32)zoid_offset + (u32)(u8 *volatile)party_address;
                ((volatile u32)id_offset) = 0xD32;
                asm("" : "+r"(id_offset));
                ((u8 *volatile)zoid_id) = (u8 *)base + (volatile u32)id_offset;
                {
                    register u32 model_index asm("r1") = U16_AT((u8 *volatile)zoid_id);
                    register u32 model_size asm("r0") = 76;
                    register const u8 *models asm("r0");
                    asm("" : : "r"(model_index), "r"(model_size));
                    model_index *= model_size;
                    models = (const u8 *)zoid_models;
                    asm("" : : "r"(model_index), "r"(models));
                    model_index += (u32)models;
                    model = (const u8 *)model_index;
                }
                LAYOUT(0x1A);
                func_08032800(*(u8 *volatile)zoid_id);
            }
            RUN(0x08675C5C, 0);
            RUN(0x0875B1B8, 2);
            {
                register u32 flags asm("r1");
                register u32 model_mask asm("r0");
                {
                    register const u8 *model_address asm("r0");
                    ((const u8 *volatile)model_address) = model;
                    asm("" : "+r"(model_address));
                    flags = U32_AT((const u8 *volatile)model_address + 8);
                }
                ((volatile u32)model_mask) = 0xFFFF0003;
                asm("" : : "r"(flags), "r"(model_mask));
                ((volatile u32)flags) &= (volatile u32)model_mask;
                ((volatile u32)model_mask) -= 3;
                if ((volatile u32)flags == (volatile u32)model_mask)
                    goto final_first_model_absent;
                {
                    register u32 field_offset asm("r1");
                    register u8 *field_address asm("r4");
                    register u32 field_value asm("r1");
                    ((volatile u32)field_offset) = 0xD3E;
                    asm("" : : "r"(field_offset));
                    ((u8 *volatile)field_address) = (u8 *)base + (volatile u32)field_offset;
                    field_value = U16_AT((u8 *volatile)field_address);
                    asm("" : : "r"(field_value));
                    ((volatile u32)model_mask) >>= 16;
                    if (field_value == (volatile u32)model_mask)
                        goto final_first_item_absent;
                    RUN(0x0866634C, field_value);
                    goto final_first_model_done;
                }
            final_first_item_absent:
                RUN(0x0875B304, 1);
                goto final_first_model_done;
            final_first_model_absent:
                RUN(0x0875B304, 0);
            final_first_model_done:;
            }
            RUN(0x08675C5C, 0);
            RUN(0x0875B1B8, 3);
            {
                register union RegisterHalf final_zoid asm("r5");
                {
                    register u32 flags asm("r1");
                    register u32 model_mask asm("r0");
                    register u32 missing_model asm("r4");
                    {
                        register const u8 *model_address asm("r2");
                        ((const u8 *volatile)model_address) = model;
                        asm("" : : "r"(model_address));
                        flags = U32_AT((const u8 *volatile)model_address + 12);
                    }
                    ((volatile u32)model_mask) = 0xFFFF0003;
                    asm("" : : "r"(flags), "r"(model_mask));
                    ((volatile u32)flags) &= (volatile u32)model_mask;
                    ((volatile u32)missing_model) = 0xFFFF0000;
                    if ((volatile u32)flags == (volatile u32)missing_model)
                        goto final_second_model_absent;
                    {
                        register u32 party_base asm("r2");
                        register u32 selected_copy asm("r6");
                        register union RegisterHalf zoid_copy asm("r3");
                        register s32 zoid_signed asm("r1");
                        register u32 address asm("r0");
                        register u32 field_offset asm("r7");
                        register u8 *field_address asm("r2");
                        register u32 field_value asm("r1");
                        ((volatile u32)party_base) = (u32)&player_state;
                        asm("" : : "r"(party_base));
                        ((volatile u32)selected_copy) = selected_zoid;
                        asm("" : : "r"(selected_copy));
                        zoid_copy.word = (volatile u32)selected_copy << 16;
                        ((volatile s32)zoid_signed) = zoid_copy.halves[1];
                        ((volatile u32)address) = (volatile s32)zoid_signed * 56;
                        ((volatile u32)address) += (volatile u32)party_base;
                        ((volatile u32)field_offset) = 0xD42;
                        asm("" : : "r"(field_offset));
                        ((u8 *volatile)field_address) =
                            (u8 *)((volatile u32)address + (volatile u32)field_offset);
                        field_value = U16_AT((u8 *volatile)field_address);
                        asm("" : : "r"(field_value));
                        ((volatile u32)model_mask) = (volatile u32)missing_model >> 16;
                        final_zoid.word = zoid_copy.word;
                        if (field_value == (volatile u32)model_mask)
                            goto final_second_item_absent;
                        RUN(0x0866634C, field_value);
                        goto final_second_model_done;
                    }
                final_second_item_absent:
                    RUN(0x0875B304, 1);
                    goto final_second_model_done;
                final_second_model_absent:
                    RUN(0x0875B304, 0);
                    {
                        register u32 selected_copy asm("r0");
                        ((volatile u32)selected_copy) = selected_zoid;
                        asm("" : : "r"(selected_copy));
                        final_zoid.word = (volatile u32)selected_copy << 16;
                    }
                final_second_model_done:;
                }
                RUN(0x08675C5C, 0);
                RUN(0x0875B1B8, 4);
                {
                    register u32 flags asm("r1");
                    register u32 model_mask asm("r0");
                    register u32 missing_model asm("r3");
                    {
                        register const u8 *model_address asm("r2");
                        ((const u8 *volatile)model_address) = model;
                        asm("" : : "r"(model_address));
                        flags = U32_AT((const u8 *volatile)model_address + 16);
                    }
                    ((volatile u32)model_mask) = 0xFFFF0003;
                    asm("" : : "r"(flags), "r"(model_mask));
                    ((volatile u32)flags) &= (volatile u32)model_mask;
                    ((volatile u32)missing_model) = 0xFFFF0000;
                    if ((volatile u32)flags == (volatile u32)missing_model)
                        goto final_third_model_absent;
                    {
                        register u32 party_base asm("r2");
                        register s32 zoid_signed asm("r1");
                        register u32 address asm("r0");
                        register u32 field_offset asm("r4");
                        register u8 *field_address asm("r2");
                        register u32 field_value asm("r1");
                        ((volatile u32)party_base) = (u32)&player_state;
                        asm("" : : "r"(party_base));
                        ((volatile s32)zoid_signed) = ((s32)(volatile u32)final_zoid.word >> 16);
                        ((volatile u32)address) = (volatile s32)zoid_signed * 56;
                        ((volatile u32)address) += (volatile u32)party_base;
                        ((volatile u32)field_offset) = 0xD46;
                        asm("" : : "r"(field_offset));
                        ((u8 *volatile)field_address) =
                            (u8 *)((volatile u32)address + (volatile u32)field_offset);
                        field_value = U16_AT((u8 *volatile)field_address);
                        asm("" : : "r"(field_value));
                        ((volatile u32)model_mask) = (volatile u32)missing_model >> 16;
                        if (field_value == (volatile u32)model_mask)
                            goto final_third_item_absent;
                        RUN(0x0866634C, field_value);
                        goto final_third_model_done;
                    }
                final_third_item_absent:
                    RUN(0x0875B304, 1);
                    goto final_third_model_done;
                final_third_model_absent:
                    RUN(0x0875B304, 0);
                final_third_model_done:;
                }
                asm("" : "+r"(final_zoid.word));
                {
                    register u32 party_base asm("r2");
                    register s32 zoid_signed asm("r1");
                    register u32 address asm("r0");
                    register u32 id_offset asm("r6");
                    ((volatile u32)party_base) = (u32)&player_state;
                    asm("" : : "r"(party_base));
                    ((volatile s32)zoid_signed) = ((s32)(volatile u32)final_zoid.word >> 16);
                    ((volatile u32)address) = (volatile s32)zoid_signed * 56;
                    ((volatile u32)address) += (volatile u32)party_base;
                    ((volatile u32)id_offset) = 0xD32;
                    asm("" : : "r"(id_offset));
                    ((volatile u32)address) += (volatile u32)id_offset;
                    func_0804D654(U16_AT((volatile u32)address), 0x28, 0x58);
                }
                RUN_UNCACHED((u32)menu_layout_scripts, 0x18);
                RUN_UNCACHED((u32)menu_layout_scripts, 0x1C);
                previous_zoid = final_zoid.word >> 16;
            }
            {
                register union RegisterHalf selected_copy asm("r7");
                register u32 shifted asm("r0");
                selected_copy.word = selected_index;
                asm("" : : "r"(selected_copy.word));
                ((volatile u32)shifted) = selected_copy.word << 16;
                ((volatile u32)shifted) >>= 16;
                previous_index = (volatile u32)shifted;
            }
            RUN(0x0875B1D8, 0);
            {
                register u32 next_state asm("r4") = 0x3101;
                asm("" : : "r"(next_state));
                state = next_state;
            }
            break;
        }
        case 0x4000:
        {
            register u32 task_slot asm("r0");
            func_08003E3C(5);
            func_08003E3C(10);
            task_slot = 5;
            asm("" : : "r"(task_slot));
            func_08003DF8(task_slot, func_08037AF0);
            do
                func_0805EE78(1);
            while (U32_AT(0x020002F4) != 1);
            func_08003E3C(5);
            func_0804E37C(5);
            RUN(0x08675BEC, 1);
            state = 1;
            break;
        }
        case 0x5000:
        {
            register const u8 **option_scripts asm("r4") = (const u8 **)0x0875B214;
            register u8 *option asm("r5");
            asm("" : : "r"(option_scripts));
            script_run_table((const u8 **volatile)option_scripts, 0);
            {
                register u8 *party_address asm("r0");
                register u32 option_offset asm("r1");
                ((u8 *volatile)party_address) = (u8 *)&player_state;
                ((volatile u32)option_offset) = 0x3618;
                asm("" : : "r"(party_address), "r"(option_offset));
                ((u8 *volatile)option) = (u8 *volatile)party_address + (volatile u32)option_offset;
            }
            script_run_table((const u8 **volatile)option_scripts, *(u8 *volatile)option + 3);
            script_run_table((const u8 **volatile)option_scripts, 1);
            LAYOUT(0x18);
            {
                register u32 option_value asm("r0");
                register u8 *option_preview asm("r2");
                option_value = *(u8 *volatile)option;
                asm("" : : "r"(option_value));
                ((u8 *volatile)option_preview) = (u8 *)0x02008651;
                asm("" : : "r"(option_preview));
                *(u8 *volatile)option_preview = option_value;
            }
            script_run_table((const u8 **volatile)option_scripts, 2);
            {
                register u16 *option_reply asm("r1");
                ((u16 *volatile)option_reply) = (u16 *)0x02007574;
                asm("" : : "r"(option_reply));
                if (option_reply[0] == 1)
                    *(u8 *volatile)option = option_reply[1];
                else
                {
                    return_sound = 0x3F;
                    goto return_main_sound_call;
                }
            }
            goto menu_main_state;
        }
        case 0x6000:
        {
            register u16 *exit_reply asm("r1");
            RUN(0x0875B238, 0);
            RUN(0x0875B068, 0x11);
            ((u16 *volatile)exit_reply) = (u16 *)0x02007574;
            asm("" : : "r"(exit_reply));
            if (exit_reply[0] == 1 && exit_reply[1] == 0)
            {
                func_080592F0();
                return_table = (const u8 **)0x0875B238;
                return_index = 1;
            return_main_call:
                ((int (*)(const u8 **, u32))script_run_table)(return_table, return_index);
                func_080019EC(0x41);
                goto menu_main_state;
            }
            goto exit_reply_error;
        slot_accepted:
        {
            register u16 *palette asm("r0") = (u16 *)0x0300234A;
            register u16 level asm("r1") = 31;
            asm("" : "+r"(palette) : "r"(level));
            *palette = level;
            ((u16 *volatile)palette) = (u16 *)0x03002350;
            *palette = level;
        }
            script_run_table((const u8 **volatile)slot_layout, 0xC);
            {
                register u16 *display asm("r2");
                ((u16 *volatile)display) = (u16 *)0x04000000;
                {
                    register u32 flags asm("r0") = *(u16 *volatile)display;
                    register u32 disabled asm("r3");
                    register u16 mask asm("r1");
                    asm("" : "+r"(flags));
                    disabled = 0xDFFF;
                    asm("" : : "r"(disabled));
                    mask = disabled;
                    asm("" : : "r"(mask));
                    *display = flags & mask;
                }
            }
            script_run_table((const u8 **volatile)slot_layout, 0xB);
            {
                register u16 *cursor_flags asm("r2") = (u16 *)0x03004BBC;
                register u32 flags asm("r0");
                register u32 disabled asm("r6");
                register u16 mask asm("r1");
                asm("" : "+r"(cursor_flags));
                cursor_flags = (u16 *)((u8 *)cursor_flags + 0x88);
                flags = *cursor_flags;
                asm("" : "+r"(flags));
                disabled = 0x7FFF;
                asm("" : : "r"(disabled));
                mask = disabled;
                asm("" : : "r"(mask));
                *cursor_flags = flags & mask;
            }
            script_run_table((const u8 **volatile)slot_layout, 9);
            script_run_table((const u8 **volatile)slot_layout, 0);
            {
                register u32 next_state asm("r4") = 0x3200;
                asm("" : : "r"(next_state));
                state = next_state;
            }
            break;
        exit_reply_error:
            if (ACTION == 0)
                func_080019EC(0x3F);
            RUN(0x0875B238, 2);
        return_main:
            return_sound = 0x41;
        return_main_sound_call:
            func_080019EC(return_sound);
        menu_main_state:
            state = 2;
            break;
        }
        }
        }
        {
            register u32 state_copy asm("r0");
            state_copy = (u32)state << 16;
            asm("" : : "r"(state_copy));
            finished_state.word = state_copy;
            asm("" : "+r"(finished_state.word));
        }
    } while ((s32)finished_state.word >= 0);
    func_08003DF8(10, func_08004034);
    {
        register u8 *task_base asm("r1");
        register u32 pending_offset asm("r7");
        register u32 *flag asm("r2");
        register u32 clear_offset asm("r0");
        register u32 ready_offset asm("r2");
        ((u8 *volatile)task_base) = (u8 *)0x02000034;
        asm("" : : "r"(task_base));
        ((volatile u32)pending_offset) = 0x558;
        asm("" : : "r"(pending_offset));
        ((u32 *volatile)flag) = (u32 *)((u8 *volatile)task_base + (volatile u32)pending_offset);
        asm("" : : "r"(flag));
        *(u32 *volatile)flag = 1;
        ((volatile u32)clear_offset) = 0x55C;
        asm("" : : "r"(clear_offset));
        ((u32 *volatile)flag) = (u32 *)((u8 *volatile)task_base + (volatile u32)clear_offset);
        asm("" : : "r"(flag));
        *(u32 *volatile)flag = 0;
        ((volatile u32)ready_offset) = 0x568;
        asm("" : : "r"(ready_offset));
        ((u8 *volatile)task_base) += (volatile u32)ready_offset;
        if (U32_AT((u8 *volatile)task_base) != 1)
        {
            register u32 *ready asm("r4");
            ((u32 *volatile)ready) = (u32 *)(u8 *volatile)task_base;
            do
                func_0805EE78(1);
            while (*(u32 *volatile)ready != 1);
        }
    }
    func_08003E3C(10);
    func_08003E3C(5);
    asm("" : "+r"(finished_state.word));
    {
        register u8 *task_base asm("r2");
        register u8 *current_address asm("r0");
        register u32 current_index asm("r1");
        register u32 task_address asm("r0");
        register s32 task_result asm("r1");
        ((u8 *volatile)task_base) = (u8 *)0x02000034;
        asm("" : : "r"(task_base));
        ((u8 *volatile)current_address) = (u8 *)0x02000030;
        asm("" : : "r"(current_address));
        current_index = *(u8 *volatile)current_address;
        asm("" : : "r"(current_index));
        ((volatile u32)task_address) = current_index << 4;
        ((volatile u32)task_address) += current_index;
        ((volatile u32)task_address) <<= 3;
        ((u8 *volatile)task_base) += 8;
        ((volatile u32)task_address) += (u32)(u8 *volatile)task_base;
        ((volatile s32)task_result) = finished_state.halves[1];
        asm("" : : "r"(task_result));
        S32_AT((volatile u32)task_address) = (volatile s32)task_result;
    }
}
