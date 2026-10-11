#include "types.h"

struct SelectionTask {
    u8 pad0[4];
    s16 state;
    u8 pad6[18];
    u32 busy;
    u8 pad1C[108];
};
extern u8 D_02000030;
extern struct SelectionTask D_02000034[];
extern u16 D_0200DA74;
extern const u16 *D_0200DA78;
extern u8 D_0200DA7C;
extern u8 D_0200DA80[2][8];
extern u8 D_0200DA88[8];
extern u8 D_0200E24A, D_0200E24B, D_0200E24C, D_0200E24D;
extern u8 D_0200E24E[6];
extern u16 D_0200E254[6], D_0200E260[6];
extern u8 D_0200EB84[], D_02010D71;
extern u16 D_02007574[8];
extern u8 D_03004BBC[];
struct SelectionSprites { u8 padding[0xD8]; u16 cursor; };
extern struct SelectionSprites selection_sprites asm("D_03004BBC");
extern u16 D_03004C98, D_03004C9A;
extern volatile u16 D_03004C44;
extern const u8 D_0866634C[];
u16 func_0800175C(u32, u32);
s32 func_080019EC(u16);
s32 func_0803E454(u16);
s32 func_0803E488(const void *, u16);
u8 func_08047D18(const u16 *, u8);
u8 func_08047D44(const u16 *, u8);
s32 func_08048140(u32, u32, u32);
u16 func_08045B10(u8, u8, u8);
u8 func_080458A8(u8, u8);
void func_080451A4(const u16 *, u8);
u8 func_08047044(u8);
void func_08046940(u32, u32);
void func_080466F0(u8);
void func_080452C4(const u16 *, u32);
void func_08045960(u32, u32);
u8 func_080476C0(u32, u32, u32);
u8 func_080470F0(u8);
u32 func_08000BD8(u32, u32);
void func_08000DF4(u32);
void func_0805EE78(u32);

#define CHILD(index) (D_03004BBC + (index) * 136)
#define PART(index) (D_0200EB84 + D_02010D71 * 716 + (index) * 20)

void func_08045B64(void)
{
    struct SelectionState {
        u32 previous_part;
        u32 route;
        union { u32 word; u16 halfword; } saved_cursor;
        u32 mode;
        union { u32 word; u16 halfword; } message_active;
    } state;
    u8 remembered_slot;
    struct SelectionTask *task;
    register u32 target asm("r8");
    register u32 buttons asm("r5");
    u8 index;
    u8 count;
    u8 slot;
    u8 next;
    u32 flags;
    const u16 *commands;
    u8 *part;

    {
        register u32 incoming asm("r8");
        asm("" : "=r"(incoming) : : "r9", "r10");
        target = incoming;
    }
    {
        register u32 task_address asm("r0");
        register u32 task_index asm("r1");
        register struct SelectionTask *task_table asm("r1");
        task_address = (u32)&D_02000030;
        asm("" : : "r"(task_address));
        task_index = *(u8 *)task_address;
        asm("" : : "r"(task_index));
        task_address = task_index * 136;
        task_table = D_02000034;
        asm("" : : "r"(task_address), "r"(task_table));
        task = (struct SelectionTask *)(task_address + (u32)task_table);
    }
    {
        register u8 previous asm("r0") = 255;
        asm("" : : "r"(previous));
        state.previous_part = previous;
    }
    state.saved_cursor.word = D_0200DA74;
    {
        register u8 remembered asm("r1") = 255;
        asm("" : : "r"(remembered));
        remembered_slot = remembered;
    }
    {
        register const u16 *first asm("r1");
        register u32 selected asm("r0");
        register u32 selected_index asm("r2");
        register u32 half_offset asm("r3");
        register const u16 *list asm("r4");
        first = D_0200E254;
        selected = D_0200DA7C;
        selected_index = 15;
        selected_index &= selected;
        half_offset = selected_index * 2;
        first = (const u16 *)(half_offset + (u32)first);
        list = D_0200DA78;
        if (*first == list[0])
        {
            register const u16 *second asm("r1");
            register const u8 *selected_part asm("r0");
            register u32 remembered asm("r3");
            register u32 index_offset asm("r2");
            register const u16 *part_address asm("r0");
            second = (const u16 *)(half_offset + (u32)D_0200E260);
            selected_part = (const u8 *)(selected_index + (u32)D_0200E24E);
            remembered = *selected_part;
            index_offset = remembered * 2;
            part_address = list + 2;
            part_address = (const u16 *)((u32)part_address + index_offset);
            if (*second == *part_address)
                remembered_slot = remembered;
        }
    }

    for (;;)
    {
        buttons = (u16)func_0800175C(16, 6);
        switch (task->state)
        {
        case 0:
        {
            register u32 remembered asm("r4");
            {
                register u32 initial_message asm("r3");
                ((u32 volatile)initial_message) = 0;
                state.message_active.word = (u32 volatile)initial_message;
            }
            remembered = remembered_slot;
            asm("" : : "r"(remembered));
            if (remembered == 255)
            {
                register u32 choice asm("r0");
                register u16 *selection asm("r1");
                choice = func_08047D18(D_0200DA78, 0);
                selection = D_02007574;
                asm("" : : "r"(selection));
                selection[7] = choice;
            }
            else
            {
                register u32 choice asm("r0");
                register u16 *selection asm("r2");
                choice = func_08047D18(D_0200DA78, remembered_slot);
                selection = D_02007574;
                asm("" : : "r"(selection));
                selection[7] = choice;
            }
            {
                register u16 *shared asm("r3") = D_02007574;
                register u32 value asm("r0");
                register u16 *cursor asm("r4");
                value = shared[7];
                asm("" : : "r"(shared), "r"(value));
                cursor = &D_03004C98;
                asm("" : : "r"(cursor));
                *cursor = value;
                value = 0;
                asm("" : : "r"(value));
                shared[5] = value;
            }
            func_080019EC(100);
            task->state = 9;
            break;
        }
        case 9:
        {
            register u32 zero asm("r1");
            register u16 *shared asm("r2");
            register u32 ready asm("r0");
            zero = 0;
            asm("" : "+r"(zero));
            state.mode = zero;
            shared = D_02007574;
            ready = shared[5];
            asm("" : : "r"(shared), "r"(ready));
            if (ready)
            {
                register u32 next_state asm("r3");
                func_0803E454(12);
                func_0803E454(16);
                next_state = 1;
                asm("" : : "r"(next_state));
                task->state = next_state;
            }
            break;
        }
        case 10:
        {
            register u32 zero asm("r4");
            register u32 next_state asm("r0");
            zero = 0;
            asm("" : "+r"(zero));
            state.mode = zero;
            next_state = 1;
            asm("" : : "r"(next_state));
            task->state = next_state;
            break;
        }
        case 1:
        {
            register u32 back_value asm("r6");
            register u32 confirmation asm("r1");
            if (buttons & 64)
            {
                if (({
                    register u32 active asm("r1") = state.message_active.word;
                    asm("" : : "r"(active));
                    active;
                }))
                {
                    register u32 zero asm("r2");
                    func_0803E454(12);
                    zero = 0;
                    asm("" : "+r"(zero));
                    state.message_active.word = zero;
                }
                func_080019EC(64);
                {
                register const u16 **command_address asm("r6");
                register const u16 *list asm("r0");
                register u16 *selection asm("r4");
                register u32 selected asm("r1");
                u32 previous_choice;
                command_address = &D_0200DA78;
                asm("" : : "r"(command_address));
                list = *command_address;
                selection = D_02007574;
                asm("" : : "r"(list), "r"(selection));
                previous_choice = (u32)func_08047D44(list, (u8)(*(u8 *)&selection[7] - 1)) << 24;
                selected = selection[7];
                asm("" : : "r"(previous_choice), "r"(selected));
                previous_choice >>= 24;
                if (previous_choice != selected)
                {
                    list = *command_address;
                    asm("" : : "r"(list));
                    {
                    register u32 choice asm("r0");
                    choice = func_08047D44(list, (u8)(selected - 1));
                    selection[7] = choice;
                    {
                        register u16 *cursor asm("r3");
                        register struct SelectionSprites *sprites asm("r0");
                        register u16 zero asm("r4");
                        register u16 *animation asm("r0");
                        register u32 reset_mode asm("r1");
                        cursor = &D_03004C98;
                        asm("" : : "r"(cursor));
                        *cursor = choice;
                        sprites = &selection_sprites;
                        asm("" : : "r"(sprites));
                        animation = &sprites->cursor;
                        asm("" : : "r"(animation));
                        zero = 0;
                        asm("" : "+r"(zero));
                        *animation = zero;
                        animation = &D_03004C9A;
                        *animation = zero;
                        ((u32 volatile)reset_mode) = 0;
                        state.mode = (u32 volatile)reset_mode;
                        asm("" : : "r"(animation));
                    }
                    }
                }
                }
            }
            if (buttons & 128)
            {
                if (({
                    register u32 active asm("r2") = state.message_active.word;
                    asm("" : : "r"(active));
                    active;
                }))
                {
                    register u32 zero asm("r3");
                    func_0803E454(12);
                    zero = 0;
                    asm("" : "+r"(zero));
                    state.message_active.word = zero;
                }
                func_080019EC(64);
                {
                register const u16 **command_address asm("r6");
                register const u16 *list asm("r0");
                register u16 *selection asm("r4");
                register u32 selected asm("r1");
                u32 following_choice;
                command_address = &D_0200DA78;
                asm("" : : "r"(command_address));
                list = *command_address;
                selection = D_02007574;
                asm("" : : "r"(list), "r"(selection));
                following_choice = (u32)func_08047D18(list, (u8)(*(u8 *)&selection[7] + 1)) << 24;
                selected = selection[7];
                asm("" : : "r"(following_choice), "r"(selected));
                following_choice >>= 24;
                if (following_choice != selected)
                {
                    list = *command_address;
                    asm("" : : "r"(list));
                    {
                    register u32 choice asm("r0");
                    choice = func_08047D18(list, (u8)(selected + 1));
                    selection[7] = choice;
                    {
                        register u16 *cursor asm("r4");
                        register struct SelectionSprites *sprites asm("r0");
                        register u16 zero asm("r1");
                        register u16 *animation asm("r0");
                        register u16 *second_animation asm("r2");
                        register u32 reset_mode asm("r3");
                        cursor = &D_03004C98;
                        asm("" : : "r"(cursor));
                        *cursor = choice;
                        sprites = &selection_sprites;
                        asm("" : : "r"(sprites));
                        animation = &sprites->cursor;
                        asm("" : : "r"(animation));
                        zero = 0;
                        asm("" : "+r"(zero));
                        *animation = zero;
                        second_animation = &D_03004C9A;
                        asm("" : : "r"(second_animation));
                        *second_animation = zero;
                        reset_mode = 0;
                        asm("" : "+r"(reset_mode));
                        state.mode = reset_mode;
                    }
                    }
                }
                }
            }
            if (({
                register const u16 *display asm("r4") = D_02007574;
                asm("" : : "r"(display));
                display[7];
            }) != 2)
                {
                register u32 animation_action asm("r0");
                ((u32 volatile)animation_action) = 0;
                state.mode = (u8)func_08048140((u32 volatile)animation_action, state.mode, 1);
            }
            else if (({
                register u32 tested_mode asm("r0") = state.mode;
                asm("" : "+r"(tested_mode));
                tested_mode;
            }) != 255)
            {
                {
                register u32 animation_action asm("r0");
                ((u32 volatile)animation_action) = 0;
                state.mode = (u8)func_08048140((u32 volatile)animation_action, (u32 volatile)state.mode, 0);
            }
                if (!state.mode)
                {
                    register u32 sentinel asm("r1") = 255;
                    asm("" : "+r"(sentinel));
                    state.mode = sentinel;
                }
            }
            {
            register u32 confirm_mask asm("r2");
            confirmation = buttons;
            confirm_mask = 1;
            asm("" : : "r"(confirmation), "r"(confirm_mask));
            confirmation &= confirm_mask;
            if (confirmation)
            {
                union CommandAddress { u32 word; const u8 *pointer; };
                register const u8 *battle_base asm("r3");
                register u32 header_offset asm("r4");
                register union CommandAddress header asm("r0");
                register const u8 *unit_address asm("r2");
                register u32 unit asm("r1");
                register u16 *command_display asm("r5");
                register u32 selected asm("r2");
                register u32 error asm("r4");
                battle_base = D_0200EB84;
                header_offset = 0x21EC;
                asm("" : : "r"(battle_base), "r"(header_offset));
                header.word = (u32)battle_base + header_offset;
                header.word = *header.pointer;
                unit_address = &D_02010D71;
                (void)((u32 volatile)unit_address);
                unit = *unit_address;
                command_display = D_02007574;
                asm("" : : "r"(command_display));
                selected = *(u8 *)&command_display[7];
                error = func_08045B10(header.word, unit, selected);
                (void)((u32 volatile)error);
                if (error)
                {
                    func_080019EC(79);
                    {
                        register u32 shown asm("r0") = error - 1;
                        (void)((u32 volatile)shown);
                        command_display[6] = shown;
                    }
                    func_0803E454(20);
                    {
                        register u32 active asm("r3") = 1;
                        asm("" : "+r"(active));
                        state.message_active.word = active;
                    }
                    break;
                }
                {
                    register u32 active asm("r4") = state.message_active.word;
                    register u16 *display asm("r3");
                    register u32 reset asm("r0");
                    if (active)
                    {
                        register u32 following asm("r0") = command_display[7] + 1;
                        register u32 previous asm("r1") = state.previous_part;
                        asm("" : : "r"(active), "r"(following), "r"(previous));
                        if (previous != following)
                        {
                            register u32 zero asm("r2");
                            func_0803E454(12);
                            zero = 0;
                            asm("" : "+r"(zero));
                            state.message_active.word = zero;
                        }
                    }
                    active = 0;
                    asm("" : "+r"(active));
                    display = D_02007574;
                    asm("" : : "r"(display));
                    display[5] = active;
                    reset = 0;
                    asm("" : "+r"(reset));
                    state.mode = reset;
                }
                task->state = 100;
                break;
            }
            }
            {
                register u32 pressed asm("r0");
                pressed = 2;
                asm("" : : "r"(pressed), "r"(buttons));
                pressed &= buttons;
                asm("" : "+r"(pressed));
                back_value = (u16)pressed;
                asm("" : : "r"(back_value));
            }
            if (back_value)
            {
                register u16 *display asm("r2");
                register u32 reset asm("r3");
                display = D_02007574;
                asm("" : : "r"(display));
                display[5] = confirmation;
                func_080019EC(63);
                reset = 0;
                asm("" : "+r"(reset));
                state.mode = reset;
                task->state = 101;
                break;
            }
            {
                register u16 *detail_display asm("r4") = D_02007574;
                (void)((u32 volatile)detail_display);
            if (detail_display[5])
            {
                func_0803E454(13);
                {
                    register u32 selected asm("r0");
                    register const u16 *list asm("r1");
                    selected = (u32)&D_0200DA78;
                    (void)((u32 volatile)selected);
                    list = *(const u16 **)selected;
                    selected = detail_display[7];
                    selected *= 2;
                    list += 2;
                    list = (const u16 *)((u32)list + selected);
                    (void)((u32 volatile)list);
                    selected = *list;
                    detail_display[6] = selected;
                }
                func_0803E488(D_0866634C, detail_display[6]);
                {
                union StatWord { u32 word; u8 *pointer; };
                register u8 *detail_base asm("r5");
                register u32 selected asm("r3");
                register u32 offset asm("r0");
                register u32 unit_offset asm("r2");
                register union StatWord value asm("r1");
                detail_base = D_0200EB84;
                (void)((u32 volatile)detail_base);
                selected = detail_display[7];
                offset = selected * 20;
                (void)((u32 volatile)selected); (void)((u32 volatile)offset);
                value.pointer = &D_02010D71;
                (void)((u32 volatile)value.word);
                unit_offset = *value.pointer;
                value.word = 716;
                (void)((u32 volatile)value.word); (void)((u32 volatile)unit_offset);
                unit_offset *= value.word;
                offset += unit_offset;
                value.pointer = detail_base;
                value.word += 0x60;
                offset += value.word;
                (void)((u32 volatile)offset);
                value.word = *(u32 *)offset;
                if ((s32)value.word > 65535)
                {
                    offset = selected * 8 + unit_offset;
                    unit_offset = 0x11C;
                    asm("" : "+r"(unit_offset));
                    value.word = (u32)detail_base + unit_offset;
                    offset += value.word;
                    (void)((u32 volatile)offset);
                    value.word = *(u32 *)offset;
                    {
                        register u32 shown asm("r0");
                        if (value.word & 32768)
                            shown = ((s32)value.word >> 16) + 1;
                        else
                            shown = value.word >> 16;
                        (void)((u32 volatile)shown);
                        detail_display[2] = shown;
                    }
                    {
                        register u32 display_address asm("r0");
                        register u32 shown asm("r1");
                        register u32 maximum asm("r2");
                        display_address = (u32)D_02007574;
                        (void)((u32 volatile)display_address);
                        shown = *(u16 *)(display_address + 4);
                        maximum = 999;
                        (void)((u32 volatile)shown); (void)((u32 volatile)maximum);
                        if (shown > maximum)
                        {
                            register u16 *store_address asm("r3");
                            store_address = (u16 *)display_address;
                            asm("" : : "r"(store_address));
                            store_address[2] = maximum;
                        }
                    }
                }
                else detail_display[2] = back_value;
                }
                {
                    union DetailAddress { u32 word; u8 *pointer; };
                    register u8 *detail_base asm("r3");
                    register u32 offset asm("r1");
                    register u32 unit asm("r2");
                    register union DetailAddress address asm("r0");
                    register u32 detail_flags asm("r2");
                    register u32 mask asm("r0");
                    register u16 *detail_display asm("r4");
                    detail_base = D_0200EB84;
                    asm("" : "+r"(detail_base));
                    detail_display = D_02007574;
                    asm("" : "+r"(detail_display));
                    address.word = detail_display[7];
                    offset = address.word * 20;
                    (void)((u32 volatile)offset);
                    address.word = (u32)&D_02010D71;
                    asm("" : "+r"(address.word));
                    unit = *address.pointer;
                    address.word = 716;
                    (void)((u32 volatile)unit); (void)((u32 volatile)address.word);
                    address.word *= unit;
                    offset += address.word;
                    address.pointer = detail_base;
                    address.word += 0x58;
                    address.word = offset + address.word;
                    detail_flags = *(u32 *)address.pointer;
                    mask = 2;
                    (void)((u32 volatile)mask); (void)((u32 volatile)detail_flags);
                    mask &= detail_flags;
                    if (mask || ({
                        mask = 4;
                        (void)((u32 volatile)mask);
                        detail_flags &= mask;
                        detail_flags;
                    }))
                    {
                        register u16 zero asm("r2") = 0;
                        register u32 display_address asm("r1");
                        display_address = (u32)D_02007574;
                        asm("" : "+r"(zero) : "r"(display_address));
                        ((u16 *)display_address)[3] = zero;
                    }
                    else
                    {
                        register u8 *field_base asm("r3");
                        register u16 *field_display asm("r4");
                        register u32 shown asm("r0");
                        field_base = D_0200EB84;
                        asm("" : : "r"(field_base));
                        address.word = offset + (u32)field_base;
                        address.word += 0x5C;
                        shown = *(u16 *)address.pointer;
                        field_display = D_02007574;
                        asm("" : : "r"(field_display));
                        field_display[3] = shown;
                        asm("" : "+r"(shown));
                        shown = (u16)shown;
                        if (shown > 99) field_display[3] = 99;
                    }
                }
                {
                    union PartFieldAddress { u32 word; u8 *pointer; u16 *halfwords; };
                    register union PartFieldAddress address asm("r0");
                    register u32 selected asm("r1");
                    register u8 *first_unit_address asm("r2");
                    register u32 unit asm("r1");
                    register u32 stride asm("r2");
                    register u8 *first_base asm("r3");
                    register u16 *first_display asm("r4");
                    register u8 *second_unit_address asm("r3");
                    register u8 *second_base asm("r4");
                    register u16 *second_display asm("r1");
                    address.word = (u32)D_02007574;
                    (void)((u32 volatile)address.word);
                    selected = address.halfwords[7];
                    address.word = selected * 20;
                    (void)((u32 volatile)address.word);
                    first_unit_address = &D_02010D71;
                    asm("" : "+r"(first_unit_address));
                    unit = *first_unit_address;
                    stride = 716;
                    (void)((u32 volatile)unit); (void)((u32 volatile)stride);
                    unit *= stride;
                    address.word += unit;
                    first_base = D_0200EB84;
                    asm("" : "+r"(first_base));
                    address.word += (u32)first_base;
                    address.word += 0x67;
                    (void)((u32 volatile)address.word);
                    address.word = *address.pointer;
                    first_display = D_02007574;
                    (void)((u32 volatile)first_display);
                    first_display[4] = address.word;
                    selected = first_display[7];
                    address.word = selected * 20;
                    (void)((u32 volatile)address.word);
                    second_unit_address = &D_02010D71;
                    (void)((u32 volatile)second_unit_address);
                    unit = *second_unit_address;
                    unit *= stride;
                    address.word += unit;
                    second_base = D_0200EB84;
                    (void)((u32 volatile)second_base);
                    address.word += (u32)second_base;
                    address.word += 0x64;
                    (void)((u32 volatile)address.word);
                    address.word = *address.halfwords;
                    second_display = D_02007574;
                    (void)((u32 volatile)second_display);
                    second_display[6] = address.word;
                }
                func_0803E454(17);
                func_0803E454(14);
                {
                    register u16 zero asm("r3") = 0;
                    register u16 *display asm("r2") = D_02007574;
                    asm("" : "+r"(zero) : "r"(display));
                    display[5] = zero;
                }
            }
            }
            break;
        }
        case 100:
            {
                register u32 animation_action asm("r0");
                ((u32 volatile)animation_action) = 0;
                state.mode = (u8)func_08048140((u32 volatile)animation_action, state.mode, 1);
            }
            if (!state.mode) task->state = 2;
            break;
        case 101:
            {
                register u32 animation_action asm("r0");
                ((u32 volatile)animation_action) = 0;
                state.mode = (u8)func_08048140((u32 volatile)animation_action, state.mode, 1);
            }
            if (!state.mode) task->state = 7;
            break;
        case 200:
            func_0803E454(19);
            task->state = 10;
            break;
        case 2:
        {
            u32 cached_address;
            register const u16 *commands asm("r5");
            register u32 selection_mask asm("r9");
            register u32 selected_index asm("r3");
            register u32 flags asm("r1");
            register u32 flags_copy asm("r2");
            register u32 table_or_zero asm("r10");
            register u8 *control_flag asm("r12");
            register u8 *enabled_flag asm("r4");
            register u8 *layer_flag asm("r6");
            index = 0;
            {
                register u16 *table_address asm("r4") = D_0200E254;
                register u8 *control_address asm("r0");
                table_or_zero = (u32)table_address;
                asm("" : : "r"(table_address), "r"(table_or_zero), "r"(task));
                control_address = &D_0200E24D;
                control_flag = control_address;
                asm("" : : "r"(control_address), "r"(control_flag), "r"(task));
            }
            {
                union ClearAddress { u32 word; u8 *pointer; };
                register union ClearAddress first_flags asm("r2");
                register union ClearAddress second_flags asm("r3");
                register u32 zero asm("r1");
                first_flags.word = (u32)D_0200DA80;
                zero = 0;
                second_flags.word = first_flags.word;
                second_flags.word += 8;
                for (; index <= 5; index++)
                {
                    u32 offset = index;
                    *(u8 *)(offset + first_flags.word) = zero;
                    *(u8 *)(offset + second_flags.word) = zero;
                }
            }
            {
                register u32 part_offset asm("r1");
                register u32 selected asm("r0");
                register u8 *part_base asm("r4");
                {
                    register const u16 *display_address asm("r1") = D_02007574;
                    (void)((u32 volatile)display_address);
                    part_offset = display_address[7] * 20;
                }
                {
                    register const u8 *selector asm("r2") = &D_0200DA7C;
                    asm("" : : "r"(selector));
                    selected = *selector;
                }
                selected_index = 15;
                selection_mask = selected_index;
                asm("" : : "r"(selection_mask), "r"(selected_index), "r"(part_offset), "r"(selected), "r"(task));
                selected_index &= selected;
                part_offset += selected_index * 716;
                part_base = D_0200EB84;
                asm("" : "+r"(part_base) : "r"(task));
                part_offset += part_base[0x21EC] * 4312;
                {
                    register u32 head asm("r0") = (u32)part_base;
                    asm("" : "+r"(head) : "r"(task));
                    head += 0x58;
                    part_offset += head;
                    flags = *(u16 *)part_offset;
                }
            }
            {
                register u8 *clear_control asm("r4");
                register u32 zero asm("r0");
                flags_copy = flags;
                zero = 0;
                clear_control = control_flag;
                (void)((u32 volatile)flags); (void)((u32 volatile)flags_copy); (void)((u32 volatile)zero); (void)((u32 volatile)clear_control);
                *clear_control = zero;
                enabled_flag = &D_0200E24B;
                *enabled_flag = zero;
                layer_flag = &D_0200E24C;
                *layer_flag = zero;
            }
            {
                register const u16 **commands_address asm("r3");
                register u32 first_command asm("r0");
                register u32 zero asm("r3");
                cached_address = table_or_zero + selected_index * 2;
                commands_address = &D_0200DA78;
                (void)((u32 volatile)commands_address);
                commands = *commands_address;
                (void)((u32 volatile)commands);
                first_command = commands[0];
                zero = 0;
                (void)((u32 volatile)zero); (void)((u32 volatile)first_command);
                table_or_zero = zero;
                (void)((u32 volatile)table_or_zero); (void)((u32 volatile)first_command);
                *(u16 *)cached_address = first_command;
            }
            if (flags & 4)
            {
                func_0803E454(15);
                func_080019EC(66);
                {
                    register u8 *destination asm("r2") = D_0200DA80[0];
                    register const u8 *selector asm("r0") = &D_0200DA7C;
                    register u32 selected asm("r1");
                    register u32 masked asm("r0");
                    asm("" : : "r"(destination), "r"(selector));
                    selected = *selector;
                    masked = selection_mask;
                    asm("" : : "r"(destination), "r"(selected), "r"(masked));
                    masked &= selected;
                    *(u8 *)(masked + (u32)destination) = 1;
                }
                D_0200E24A = table_or_zero;
                *enabled_flag = 1;
                *layer_flag = 1;
                {
                    register const u16 *display_address asm("r3") = D_02007574;
                    (void)((u32 volatile)display_address);
                    state.previous_part = (u8)(*(u8 *)(display_address + 7) + 1);
                }
                task->state = 14;
                break;
            }
            {
            register u32 enabled asm("r4");
            register u32 tested_flags asm("r0");
            register u32 mask asm("r3");
            enabled = 1;
            asm("" : "+r"(enabled));
            tested_flags = flags;
            mask = 1;
            asm("" : : "r"(enabled), "r"(tested_flags), "r"(mask));
            if (tested_flags & mask)
            {
                D_0200E24A = enabled;
                *control_flag = enabled;
                {
                register const u16 *display asm("r1");
                register u32 selected_part asm("r3");
                register u32 part_offset asm("r1");
                register const u16 *entry asm("r0");
                display = D_02007574;
                (void)((u32 volatile)display);
                selected_part = display[7];
                part_offset = selected_part * 2;
                entry = commands + 2;
                (void)((u32 volatile)part_offset); (void)((u32 volatile)entry); (void)((u32 volatile)selected_part);
                entry = (const u16 *)((u32)entry + part_offset);
                if (*entry == 112)
                    *layer_flag = enabled;
                else
                {
                    register u8 *remembered asm("r2");
                    register const u8 *selector asm("r4");
                    register u32 selected asm("r1");
                    register u32 masked asm("r0");
                    remembered = D_0200E24E;
                    selector = &D_0200DA7C;
                    (void)((u32 volatile)remembered); (void)((u32 volatile)selector);
                    selected = *selector;
                    masked = selection_mask;
                    (void)((u32 volatile)selected); (void)((u32 volatile)masked);
                    masked &= selected;
                    *(u8 *)(masked + (u32)remembered) = selected_part;
                    {
                        register u16 *saved_commands asm("r1");
                        register u32 command_index asm("r2");
                        index = 0;
                    saved_commands = D_0200E260;
                        (void)((u32 volatile)saved_commands);
                        masked = *selector;
                        command_index = selection_mask;
                        (void)((u32 volatile)masked); (void)((u32 volatile)command_index); (void)((u32 volatile)saved_commands);
                        command_index &= masked;
                        command_index *= 2;
                        command_index += (u32)saved_commands;
                        {
                            register const u16 **command_address asm("r0");
                            register const u16 *current_commands asm("r1");
                            register const u16 *display_address asm("r3");
                            register u32 current_part asm("r0");
                            command_address = &D_0200DA78;
                            (void)((u32 volatile)command_address);
                            current_commands = *command_address;
                            display_address = D_02007574;
                            (void)((u32 volatile)current_commands); (void)((u32 volatile)display_address);
                            current_part = display_address[7];
                            current_part *= 2;
                            current_commands += 2;
                            current_commands = (const u16 *)((u32)current_commands + current_part);
                            *(u16 *)command_index = *current_commands;
                        }
                    }
                }
            }
            }
            else if (({
                register u32 mask asm("r0") = 2;
                flags &= mask;
                (void)((u32 volatile)flags);
                flags;
            }))
            {
                {
                    register u8 *active_address asm("r0");
                    register u32 inactive asm("r1");
                    active_address = &D_0200E24A;
                    (void)((u32 volatile)active_address);
                    inactive = table_or_zero;
                    (void)((u32 volatile)inactive);
                    *active_address = inactive;
                }
                {
                    register u8 *layer_address asm("r2");
                    register u8 *enabled_address asm("r3");
                    layer_address = &D_0200E24C;
                    (void)((u32 volatile)layer_address);
                    *layer_address = enabled;
                    enabled_address = &D_0200E24B;
                    (void)((u32 volatile)enabled_address);
                    *enabled_address = enabled;
                }
            }
            else if (({
                register u32 mask asm("r0") = 8;
                flags_copy &= mask;
                (void)((u32 volatile)flags_copy);
                flags_copy;
            }))
            {
                func_0803E454(15);
                func_080019EC(66);
                for (index = 0; index <= 5; index++) D_0200DA80[0][index] = 1;
                {
                    register u16 *saved_commands asm("r6");
                    register u8 *remembered asm("r4");
                    register u8 *control_address asm("r0");
                    register u8 *active asm("r3");
                    register u8 *second_flags asm("r2");
                    register u32 one asm("r1");
                    index = 0;
                    saved_commands = D_0200E260;
                    remembered = D_0200E24E;
                    control_address = &D_0200E24D;
                    asm("" : : "r"(control_address));
                    control_flag = control_address;
                    asm("" : : "r"(control_flag));
                    (void)((u32 volatile)saved_commands); (void)((u32 volatile)remembered);
                    active = &D_0200E24A;
                    second_flags = D_0200DA88;
                    one = 1;
                    (void)((u32 volatile)active); (void)((u32 volatile)second_flags); (void)((u32 volatile)one);
                    for (; index <= 5; index++)
                        *(u8 *)(index + (u32)second_flags) = one;
                    asm("" : "+r"(one));
                    one = 1;
                    *active = one;
                    {
                        register u8 *control_copy asm("r2") = control_flag;
                        (void)((u32 volatile)control_copy);
                        *control_copy = one;
                    }
                    {
                        register const u16 *display asm("r0");
                        register u32 selected_part asm("r3");
                        register const u8 *selector asm("r2");
                        register u32 selected asm("r1");
                        register u32 mask asm("r2");
                        register u32 masked asm("r0");
                        display = D_02007574;
                        (void)((u32 volatile)display);
                        selected_part = display[7];
                        state.previous_part = (u8)(selected_part + 1);
                        selector = &D_0200DA7C;
                        (void)((u32 volatile)selector); (void)((u32 volatile)selected_part);
                        selected = *selector;
                        mask = 15;
                        masked = mask;
                        (void)((u32 volatile)selected); (void)((u32 volatile)mask); (void)((u32 volatile)masked);
                        masked &= selected;
                        *(u8 *)(masked + (u32)remembered) = selected_part;
                        {
                            register const u8 *selector_again asm("r3");
                            register const u16 **commands_address asm("r4");
                            register const u16 *current_commands asm("r1");
                            register const u16 *display_again asm("r3");
                            selector_again = &D_0200DA7C;
                            (void)((u32 volatile)selector_again);
                            masked = *selector_again;
                            mask &= masked;
                            mask *= 2;
                            mask += (u32)saved_commands;
                            commands_address = &D_0200DA78;
                            (void)((u32 volatile)commands_address); (void)((u32 volatile)mask);
                            current_commands = *commands_address;
                            display_again = D_02007574;
                            (void)((u32 volatile)current_commands); (void)((u32 volatile)display_again);
                            masked = display_again[7];
                            masked *= 2;
                            current_commands += 2;
                            current_commands = (const u16 *)((u32)current_commands + masked);
                            *(u16 *)mask = *current_commands;
                        }
                    }
                }
                task->state = 14;
                break;
            }
            }
            {
            register u16 *display asm("r5");
            register u32 part_index asm("r1");
            register u32 part_offset asm("r0");
            register const u8 *selector asm("r4");
            register u32 selected_slot asm("r2");
            register u32 unit_offset asm("r1");
            display = D_02007574;
            asm("" : : "r"(display));
            part_index = display[7];
            part_offset = part_index * 20;
            selector = &D_0200DA7C;
            (void)((u32 volatile)part_offset); (void)((u32 volatile)selector);
            part_index = *selector;
            selected_slot = 15;
            selected_slot &= part_index;
            unit_offset = 716;
            (void)((u32 volatile)selected_slot); (void)((u32 volatile)unit_offset);
            unit_offset *= selected_slot;
            part_offset += unit_offset;
            unit_offset = (u32)D_0200EB84;
            (void)((u32 volatile)part_offset); (void)((u32 volatile)unit_offset);
            part_offset += unit_offset;
            part_offset += 0x67;
            next = func_080458A8(*(u8 *)part_offset, selected_slot > 2);
            {
                register u16 *cursor_destination asm("r0") = &D_0200DA74;
                register struct SelectionState *saved_state asm("r2");
                register u32 restored_cursor asm("r2");
                asm("" : : "r"(cursor_destination));
                saved_state = &state;
                asm("" : "+r"(saved_state));
                restored_cursor = saved_state->saved_cursor.halfword;
                (void)((u32 volatile)restored_cursor);
                *cursor_destination = restored_cursor;
            }
            func_080451A4(D_0200DA78, D_0200E24A);
            state.route = next;
            {
                register u32 following_part asm("r0");
                register u32 previous asm("r3");
                following_part = display[7];
                following_part += 1;
                (void)((u32 volatile)following_part);
                previous = state.previous_part;
                asm("" : : "r"(previous));
                if (previous != following_part)
                    target = func_08047044(next);
            }
            state.previous_part = (u8)(*(u8 *)&display[7] + 1);
            {
            register u32 compared asm("r4") = target;
            asm("" : : "r"(compared));
            if (compared == 255)
            {
                register u32 active asm("r0") = 1;
                asm("" : : "r"(active));
                state.message_active.word = active;
                func_080019EC(79);
                {
                    register struct SelectionState *message_state asm("r1") = &state;
                    register u32 message asm("r1");
                    asm("" : "+r"(message_state));
                    message = message_state->message_active.halfword;
                    (void)((u32 volatile)message);
                    display[0] = message;
                }
                task->state = 200;
                break;
            }
            }
            {
            register u32 compared asm("r2") = target;
            asm("" : : "r"(compared));
            if (compared == 254)
            {
                register u32 active asm("r3") = 1;
                register u32 zero asm("r4");
                asm("" : : "r"(active));
                state.message_active.word = active;
                func_080019EC(79);
                zero = 0;
                asm("" : : "r"(zero));
                display[0] = zero;
                task->state = 200;
                break;
            }
            }
            }
            func_0803E454(15);
            func_080019EC(67);
            func_08046940(state.route, target);
            {
                register const u16 *display_address asm("r1") = D_02007574;
                (void)((u32 volatile)display_address);
                func_080466F0(*(u8 *)(display_address + 7));
            }
            func_080452C4(D_0200DA78, 0);
            func_08045960(state.route, target);
            asm("" : : "g"(cached_address));
            task->state = 3;
            break;
        }
        case 104:
        {
            register u32 count asm("r2") = 0;
            register u8 *task_base asm("r3");
            index = 0;
            task_base = D_03004BBC;
            asm("" : : "r"(count), "r"(task_base));
            for (; index <= 6;)
            {
                union ChildAddress { u32 word; u8 *pointer; };
                register u32 child_index asm("r0") = index + 1;
                register union ChildAddress child asm("r1");
                asm("" : : "r"(child_index));
                child.word = child_index * 136 + (u32)task_base;
                child.word += 0x4C;
                child.word = *child.pointer;
                child.word = count + child.word;
                child.word <<= 24;
                count = child.word >> 24;
                asm("" : : "r"(count), "r"(child_index));
                index = (u8)child_index;
            }
            if (!count) task->state = 3;
            break;
        }
        case 3:
            if (buttons & 64)
            {
                next = func_080476C0(state.route, target, 64);
                if (next != target && func_080470F0(next))
                {
                    func_080019EC(72);
                    target = next;
                    func_08046940(state.route, target);
                    {
                        register const u16 *display_address asm("r2");
                        display_address = D_02007574;
                        asm("" : : "r"(display_address));
                        func_080466F0(*(u8 *)(display_address + 7));
                    }
                    func_08045960(state.route, target);
                }
            }
            if (buttons & 128)
            {
                next = func_080476C0(state.route, target, 128);
                if (next != target && func_080470F0(next))
                {
                    func_080019EC(72);
                    target = next;
                    func_08046940(state.route, target);
                    {
                        register const u16 *display_address asm("r3");
                        display_address = D_02007574;
                        asm("" : : "r"(display_address));
                        func_080466F0(*(u8 *)(display_address + 7));
                    }
                    func_08045960(state.route, target);
                }
            }
            if (buttons & 32)
            {
                next = func_080476C0(state.route, target, 32);
                if (next != target && func_080470F0(next))
                {
                    func_080019EC(72);
                    target = next;
                    func_08046940(state.route, target);
                    {
                        register const u16 *display_address asm("r4");
                        display_address = D_02007574;
                        asm("" : : "r"(display_address));
                        func_080466F0(*(u8 *)(display_address + 7));
                    }
                    func_08045960(state.route, target);
                }
            }
            if (buttons & 16)
            {
                next = func_080476C0(state.route, target, 16);
                if (next != target && func_080470F0(next))
                {
                    func_080019EC(72);
                    target = next;
                    func_08046940(state.route, target);
                    {
                        register const u16 *display_address asm("r1");
                        display_address = D_02007574;
                        asm("" : : "r"(display_address));
                        func_080466F0(*(u8 *)(display_address + 7));
                    }
                    func_08045960(state.route, target);
                }
            }
            if (buttons & 2)
            {
                func_080019EC(63);
                {
                    register u8 *task_base asm("r3");
                    register u32 zero asm("r2");
                    index = 0;
                    task_base = D_03004BBC;
                    zero = 0;
                    asm("" : : "r"(task_base), "r"(zero));
                    for (; index <= 5; index++)
                    {
                        register u32 child_index asm("r1") = index + 2;
                        register u32 address asm("r0");
                        register u32 first_address asm("r1");
                        asm("" : : "r"(child_index));
                        address = child_index * 136 + (u32)task_base;
                        first_address = address;
                        first_address += 0x50;
                        asm("" : : "r"(first_address), "r"(address));
                        *(u16 *)first_address = zero;
                        address += 0x56;
                        *(u16 *)address = zero;
                    }
                }
                func_080452C4(D_0200DA78, 2);
                func_0803E454(16);
                {
                    register u32 ready asm("r3");
                    register u16 *display asm("r2");
                    ready = 1;
                    asm("" : : "r"(ready));
                    display = D_02007574;
                    asm("" : : "r"(display));
                    display[5] = ready;
                }
                task->state = 10;
                func_08000BD8(23, 0);
            }
            else
            {
                register u32 pressed asm("r0") = buttons;
                register u32 mask asm("r4") = 1;
                asm("" : : "r"(pressed), "r"(mask));
                pressed &= mask;
                if (pressed)
                {
                    func_080019EC(66);
                    task->state++;
                }
            }
            break;
        case 4:
            for (index = 0; index <= 5; index++)
            {
                register u32 first_index asm("r0") = index + 8;
                register u16 *first asm("r1");
                register u32 flags asm("r3");
                register u32 mask asm("r2");
                register u32 first_mask asm("r0");
                asm("" : : "r"(first_index), "r"(task));
                first = (u16 *)(first_index * 136);
                first_index = (u32)D_03004BBC;
                asm("" : : "r"(first), "r"(first_index));
                first = (u16 *)((u32)first + first_index);
                flags = *first;
                mask = 32767;
                first_mask = mask;
                asm("" : : "r"(flags), "r"(mask), "r"(first_mask));
                first_mask &= flags;
                *first = first_mask;
                {
                    register u32 second_index asm("r1") = index + 24;
                    register u16 *second asm("r0");
                    register u32 second_base asm("r1");
                    asm("" : : "r"(second_index));
                    second = (u16 *)(second_index * 136);
                    second_base = (u32)D_03004BBC;
                    asm("" : : "r"(second), "r"(second_base));
                    second = (u16 *)((u32)second + second_base);
                    second_base = *second;
                    mask &= second_base;
                    asm("" : : "r"(mask));
                    *second = mask;
                }
            }
        {
            register u32 count asm("r2") = 0;
            register u8 *task_base asm("r3");
            index = 0;
            task_base = D_03004BBC;
            asm("" : : "r"(count), "r"(task_base));
            for (; index <= 6;)
            {
                union ChildAddress { u32 word; u8 *pointer; };
                register u32 child_index asm("r0") = index + 1;
                register union ChildAddress child asm("r1");
                asm("" : : "r"(child_index));
                child.word = child_index * 136 + (u32)task_base;
                child.word += 0x4C;
                child.word = *child.pointer;
                child.word = count + child.word;
                child.word <<= 24;
                count = child.word >> 24;
                asm("" : : "r"(count), "r"(child_index));
                index = (u8)child_index;
            }
            if (!count) task->state++;
            break;
        }

        case 14:
        {
            register u32 count asm("r2") = 0;
            register u8 *task_base asm("r3");
            index = 0;
            task_base = D_03004BBC;
            asm("" : : "r"(count), "r"(task_base));
            for (; index <= 6;)
            {
                union ChildAddress { u32 word; u8 *pointer; };
                register u32 child_index asm("r0") = index + 1;
                register union ChildAddress child asm("r1");
                asm("" : : "r"(child_index));
                child.word = child_index * 136 + (u32)task_base;
                child.word += 0x4C;
                child.word = *child.pointer;
                child.word = count + child.word;
                child.word <<= 24;
                count = child.word >> 24;
                asm("" : : "r"(count), "r"(child_index));
                index = (u8)child_index;
            }
            if (!count) task->state = 6;
            break;
        }

        case 5:
            {
                register u8 *task_base asm("r6");
                index = 0;
                task_base = D_03004BBC;
                asm("" : : "r"(task_base));
                for (; index <= 6;)
                {
                    register u32 child_index asm("r4") = index + 1;
                    asm("" : : "r"(child_index));
                    if (index)
                    {
                        register u32 address asm("r0") = child_index * 136 + (u32)task_base;
                        asm("" : : "r"(address));
                        address += 0x50;
                        if (*(u16 *)address == 1)
                            func_08000BD8(child_index, 2);
                    }
                    {
                        register u16 *address asm("r0") = (u16 *)(child_index * 136 + (u32)task_base);
                        register u32 value asm("r1");
                        register u32 mask asm("r3");
                        register u32 mask_copy asm("r2");
                        value = *address;
                        mask = 3072;
                        mask_copy = mask;
                        asm("" : : "r"(address), "r"(value), "r"(mask), "r"(mask_copy));
                        value |= mask_copy;
                        *address = value;
                    }
                    {
                        register u32 next_index asm("r0");
                        next_index = child_index << 24;
                        asm("" : : "r"(next_index));
                        index = next_index >> 24;
                    }
                }
            }
            func_080452C4(D_0200DA78, 1);
            {
                register volatile u16 *frame_flags asm("r4") = &D_03004C44;
                register u32 flags asm("r1");
                u32 mask;
                asm("" : : "r"(frame_flags));
                flags = *frame_flags;
                asm("" : : "r"(flags));
                mask = 4;
                mask &= flags;
                if (!mask)
                {
                    register u32 waiting_mask asm("r5") = 4;
                    asm("" : : "r"(waiting_mask));
                    for (;;)
                    {
                        func_0805EE78(1);
                        flags = *frame_flags;
                        asm("" : : "r"(flags));
                        mask = waiting_mask;
                        mask &= flags;
                        if (mask) break;
                    }
                }
            }
            {
                register u8 *task_base asm("r2");
                register u32 zero asm("r1");
                index = 1;
                task_base = D_03004BBC;
                zero = 0;
                asm("" : : "r"(task_base), "r"(zero));
                for (; index <= 18; index++)
                {
                    register u32 address asm("r0") = index * 136 + (u32)task_base;
                    asm("" : : "r"(address));
                    *(u16 *)address = zero;
                    address += 0x4C;
                    *(u16 *)address = zero;
                }
            }
            {
                register u8 *task_base asm("r2");
                register u32 zero asm("r1");
                index = 24;
                task_base = D_03004BBC;
                zero = 0;
                asm("" : : "r"(task_base), "r"(zero));
                for (; index <= 29; index++)
                {
                    register u32 address asm("r0") = index * 136 + (u32)task_base;
                    asm("" : : "r"(address));
                    *(u16 *)address = zero;
                    address += 0x4C;
                    *(u16 *)address = zero;
                }
            }
            task->state++;
            break;
        case 6:
            {
                register u8 *task_base asm("r2");
                register u32 zero asm("r1");
                index = 1;
                task_base = D_03004BBC;
                zero = 0;
                asm("" : : "r"(task_base), "r"(zero));
                for (; index <= 18; index++)
                {
                    register u32 address asm("r0") = index * 136 + (u32)task_base;
                    asm("" : : "r"(address));
                    *(u16 *)address = zero;
                    address += 0x4C;
                    *(u16 *)address = zero;
                }
            }
            {
                register u8 *task_base asm("r2");
                register u32 zero asm("r1");
                index = 24;
                task_base = D_03004BBC;
                zero = 0;
                asm("" : : "r"(task_base), "r"(zero));
                for (; index <= 29; index++)
                {
                    register u32 address asm("r0") = index * 136 + (u32)task_base;
                    asm("" : : "r"(address));
                    *(u16 *)address = zero;
                    address += 0x4C;
                    *(u16 *)address = zero;
                }
            }
            task->busy = 1;
            break;
        case 7:
            task->busy = 2;
            break;
        }
        index = 7;
        do { func_08000DF4(index); } while (--index);
        func_0805EE78(1);
    }
}

#undef CHILD
#undef PART
