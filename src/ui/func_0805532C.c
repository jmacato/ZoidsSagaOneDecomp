#include "types.h"

register const u8 *formation_stack asm("sp");

struct MenuStats553
{
    u32 hp, ep, third;
};
struct PilotRecord553
{
    u16 flags;
    u8 zoid, unknown_03;
};
struct FormationRecord553
{
    u8 unit, pilot;
    u16 unknown_02;
};
struct MenuSaveView553
{
    u8 preceding[0x34A4];
    struct PilotRecord553 pilots[87];
    struct FormationRecord553 formation[6];
};
struct MenuFrame553
{
    u16 remembered[4];
    u16 detail[4];
    struct MenuStats553 stats;
    u32 return_state;
    u32 page;
    u32 previous_page;
    u32 selected_core;
    u32 previous_core;
    u32 field_30;
    u32 selected;
    u32 previous_selected;
    u32 linked_slot;
    u32 first_item;
    u32 second_item;
    const u8 *core_definition;
    u32 field_4C;
    u32 active;
    u32 refresh;
    u32 row;
};
extern u8 D_02000030;
extern u8 D_02000034[];
extern u32 D_02001884;
extern u16 D_02007574[], D_02007588;
extern u8 D_02007FA9;
extern u8 D_02000B5C[], D_02003E60;
extern u8 D_0200E8A1, D_0200E778;
extern const u8 D_0875BA9C[], D_08675BEC[], D_0875B3B8[];
extern const u8 D_0875B068[], D_0875AFB8[], D_0875B4D4[];
void func_0804E2B8(void);
void func_0804E30C(void);
void func_08000DB8(void);
void func_08000D1C(u32);
void func_08001A54(const void *, u32, u32);
void func_0803E024(u32, u32, u32);
void func_08003DF8(u32, void (*)(void));
void func_08003E3C(u32);
void func_08053524(void);
void func_08004034(void);
void func_0803E488(const void *, u32);
void func_08001848(s32, u32, u32);
void func_080019EC(u32);
void func_0805EE78(s32);
void func_080371C4(u32);
void func_080551F4(void);

extern u8 D_020075A0[], D_0200E7F4[], D_03004BBC[];
extern u16 D_0300235A;
extern const u8 D_08675C5C[], D_0875B448[], D_0867006C[];
void func_08032800(u32);
void func_08032818(u32);
void func_0804D654(u16, u16, u16);
s32 func_080346C0(s32, s32);
s32 func_0805D484(s32, s32);

extern u8 D_0200E6DF[];
extern const u8 D_0875B3F4[], D_0875B168[], D_0875B320[], D_08676254[], D_0875B0F8[];
u8 func_08055260(u16);

extern const u8 D_0875B434[], D_0875B1F0[], D_0866634C[];
extern u8 D_02001898[], D_02003EA8[], D_02003E68[], D_020018B0[];
void func_08036B98(u8);
u8 func_0803699C(u8, u8);
void func_08036C1C(u32, u32, void *);
extern u8 D_0200E5F0[], D_0200E647;
extern const u8 D_0875B0D0[], D_0875B4F0[], D_0875B47C[];
u8 *func_080334F8(u8);
void func_0805506C(u16);
void func_08036B4C(s32, s32);
void func_08037118(u8, u8, void *);
s32 func_0805D3B4(s32, s32);
extern const u8 D_0875B4AC[], D_0875B124[];
void func_08054F70(u32, u32, u32);
void func_08055054(u32, u32, u32);

#define SAVE_BYTE553(field, base_reg, field_reg)                                                   \
    ({                                                                                             \
        register u8 *base asm(base_reg) = D_02000B5C;                                              \
        register u32 offset asm(field_reg) = (field);                                              \
        register u8 *address asm("r0");                                                            \
        asm("" : "+r"(offset) : "r"(base));                                                        \
        address = base + offset;                                                                   \
        asm("" : : "r"(base), "r"(address));                                                       \
        *address;                                                                                  \
    })

void func_0805532C(void)
{
    struct MenuFrame553 frame;
    u16 *volatile remembered_base;
    u32 frame_padding[12];
    register union
    {
        const u8 *definition;
        u16 *cursor;
        u8 *count;
        u32 selector;
        u8 *save;
        u32 offset;
    } menu_pointer;
    u8 *pilot_stock_roster;
    register u8 *stats_base asm("r8");
    register u32 state asm("r5");
    register u32 exit_bits asm("r6");
    register u32 state_shift asm("r0");
    s16 i;
    asm("" : "=m"(frame_padding[0]));
    func_0804E2B8();
    func_0804E30C();
    func_08000DB8();
    func_08000D1C(0);
    *(vu16 *)0x04000000 = 0x1D40;
    *(vu16 *)0x0400000C = 0x38B;
    *(vu16 *)0x0400000E = 0x48B;
    {
        register const u8 *resource asm("r4");
        ((const u8 *volatile)resource) = D_0875BA9C;
        func_08001A54((const u8 *volatile)resource, 0, 1);
        func_08001A54((const u8 *volatile)resource, 1, 1);
        func_08001A54((const u8 *volatile)resource, 2, 1);
        func_08001A54((const u8 *volatile)resource, 3, 1);
    }
    func_0803E024(3, 0, 255);
    func_08003DF8(5, func_08053524);
    func_08003DF8(10, func_08004034);
    {
        register u8 *base asm("r0") = D_02000034;
        register u32 offset asm("r5") = 0x558;
        register u32 zero asm("r2");
        register u32 *argument asm("r1");
        register u32 next_offset asm("r6");
        asm("" : : "r"(base), "r"(offset));
        argument = (u32 *)(base + offset);
        asm("" : : "r"(argument));
        zero = 0;
        *argument = zero;
        next_offset = 0x55C;
        asm("" : : "r"(base), "r"(zero), "r"(next_offset));
        *(u32 *)(base + next_offset) = zero;
    }
    state = 0;
    {
        register u16 *remembered asm("r7") = (u16 *)formation_stack;
        asm("" : "+r"(remembered));
        remembered_base = remembered;
    }
    for (;;)
    {
        switch ((s16)state)
        {
        case 0:
            func_0803E488(D_08675BEC, 1);
            func_0803E488(D_0875B3B8, 0);
            {
                register const u8 *prompt asm("r0");
                ((const u8 *volatile)prompt) = D_0875B068;
                func_0803E488((const u8 *volatile)prompt, 0);
            }
            func_0803E488(D_0875AFB8, 42);
            {
                register const u32 *money asm("r1") = &D_02001884;
                asm("" : : "r"(money));
                func_08001848(*money, 7, 0);
            }
            {
                register const u8 *prompt asm("r0");
                ((const u8 *volatile)prompt) = D_0875B068;
                func_0803E488((const u8 *volatile)prompt, 1);
            }
            func_0803E488(D_0875AFB8, 24);
            {
                register u8 *base asm("r0") = D_02000034;
                register u32 offset asm("r2") = 0x568;
                register u32 *initial asm("r1");
                u32 *waiting;
                asm("" : : "r"(base), "r"(offset));
                initial = (u32 *)(base + offset);
                asm("" : : "r"(initial));
                if (*initial != 1)
                {
                    waiting = initial;
                    asm("" : : "r"(waiting));
                    for (;;)
                    {
                        func_0805EE78(1);
                        if (*waiting == 1)
                            break;
                    }
                }
            }
            func_0803E488(D_0875B3B8, 1);
            state = 0x30;
            break;
        case 0x10:
            func_0803E488(D_0875B3B8, 0);
            {
                register const u8 *prompt asm("r0");
                ((const u8 *volatile)prompt) = D_0875B068;
                func_0803E488((const u8 *volatile)prompt, 0);
            }
            func_0803E488(D_0875AFB8, 42);
            {
                register const u32 *money asm("r3") = &D_02001884;
                asm("" : : "r"(money));
                func_08001848(*money, 7, 0);
            }
            {
                register const u8 *prompt asm("r0");
                ((const u8 *volatile)prompt) = D_0875B068;
                func_0803E488((const u8 *volatile)prompt, 1);
            }
        case 0x20:
        {
            register u16 *remembered asm("r4") = remembered_base;
            register u32 value asm("r0");
            register u8 *cursor asm("r5");
            asm("" : : "r"(remembered));
            value = *remembered;
            asm("" : : "r"(value));
            cursor = &D_02007FA9;
            asm("" : : "r"(cursor), "r"(value));
            *cursor = value;
        }
        case 0x30:
            func_0803E488(D_0875B3B8, 2);
            if (D_02007574[0] == 0)
            {
                register u8 *exit_save asm("r4") = D_02000B5C;
                asm("" : : "r"(exit_save));
                if (SAVE_BYTE553(0x34A6, "r4", "r6") == 255 ||
                    SAVE_BYTE553(0x34AA, "r4", "r7") == 255 ||
                    SAVE_BYTE553(0x34AE, "r4", "r1") == 255 ||
                    SAVE_BYTE553(0x34B2, "r4", "r2") == 255)
                {
                    func_080019EC(79);
                    func_0803E488(D_0875B3B8, 6);
                    if (SAVE_BYTE553(0x34A6, "r1", "r3") == 255)
                    {
                        if (SAVE_BYTE553(0x34AA, "r1", "r5") != 255 &&
                            SAVE_BYTE553(0x34AE, "r1", "r6") != 255 &&
                            SAVE_BYTE553(0x34B2, "r1", "r7") != 255)
                            func_0803E488(D_0875B3B8, 7);
                        else
                        {
                            func_0803E488(D_0875B3B8, 8);
                            func_0803E488(D_0875B3B8, 9);
                        }
                    }
                    else
                        func_0803E488(D_0875B3B8, 9);
                    func_0803E488(D_0875B3B8, 10);
                    func_080019EC(65);
                    state = 0x30;
                    break;
                }
                func_080019EC(63);
                {
                    register u8 *assignments asm("r8");
                    register u32 flags_offset asm("sl");
                    i = 0;
                    {
                        register u8 *base asm("r4") = exit_save;
                        register u32 offset asm("r0") = 0x3600;
                        register u32 flags asm("r1");
                        asm("" : : "r"(base), "r"(offset));
                        offset += (u32)base;
                        asm("" : : "r"(offset));
                        assignments = (u8 *)offset;
                        flags = 0xD2E;
                        asm("" : : "r"(assignments), "r"(flags));
                        flags_offset = flags;
                    }
                    for (; i <= 5;)
                    {
                        register u32 scaled asm("r0");
                        register u8 *copy asm("r4");
                        register u8 *assignment asm("r3");
                        register u32 assigned asm("r2");
                        scaled = (s16)i * 4;
                        copy = assignments;
                        asm("" : : "r"(scaled), "r"(copy));
                        assignment = (u8 *)(scaled + (u32)copy);
                        asm("" : : "r"(assignment));
                        assigned = assignment[0];
                        asm("" : : "r"(assigned));
                        if (assigned != 255)
                        {
                            register u8 *save asm("r4");
                            register u32 back asm("r4") = (u32)-0x3600;
                            register u32 pilot_offset asm("r5");
                            register u32 pilot_id asm("r1");
                            register u32 address asm("r0");
                            asm("" : : "r"(back));
                            save = assignments + back;
                            asm("" : : "r"(save));
                            address = assignment[1] * 4;
                            address += (u32)save;
                            asm("" : : "r"(address));
                            pilot_offset = 0x34A6;
                            asm("" : : "r"(pilot_offset), "r"(address));
                            address += pilot_offset;
                            pilot_id = *(u8 *)address;
                            asm("" : : "r"(pilot_id));
                            if (pilot_id != assigned)
                            {
                                if (pilot_id != 255)
                                {
                                    register u32 field asm("r7");
                                    register u32 mask asm("r2");
                                    register u32 low asm("r1");
                                    u32 flags;
                                    address = pilot_id * 56;
                                    address += (u32)save;
                                    asm("" : : "r"(address));
                                    field = 0xD2C;
                                    asm("" : : "r"(field), "r"(address));
                                    flags = *(u16 *)(address + field);
                                    mask = 0x800;
                                    asm("" : : "r"(mask));
                                    low = mask;
                                    asm("" : : "r"(low));
                                    if (flags & low)
                                    {
                                        func_080371C4((u8)i);
                                        asm("");
                                    }
                                    else
                                    {
                                        register u32 id asm("r1");
                                        register u32 flags asm("r1");
                                        register u32 mask asm("r7");
                                        register u32 low asm("r2");
                                        id = assignment[0];
                                        asm("" : : "r"(id));
                                        address = id * 56;
                                        address += (u32)save;
                                        asm("" : : "r"(address));
                                        address += flags_offset;
                                        asm("" : : "r"(address));
                                        flags = *(u16 *)address;
                                        mask = 0xFFFD;
                                        asm("" : : "r"(mask));
                                        low = mask;
                                        asm("" : : "r"(low), "r"(flags), "r"(address));
                                        *(u16 *)address = flags & low;
                                        address = assignment[1] * 4;
                                        address += (u32)save;
                                        asm("" : : "r"(address));
                                        address += pilot_offset;
                                        id = *(u8 *)address;
                                        asm("" : : "r"(id));
                                        address = id * 56;
                                        address += (u32)save;
                                        asm("" : : "r"(address));
                                        address += flags_offset;
                                        asm("" : : "r"(address));
                                        flags = *(u16 *)address;
                                        low = 2;
                                        asm("" : : "r"(low), "r"(flags));
                                        *(u16 *)address = flags | low;
                                        address = assignment[1] * 4;
                                        address += (u32)save;
                                        asm("" : : "r"(address));
                                        address += pilot_offset;
                                        asm("" : : "r"(address));
                                        address = *(u8 *)address;
                                        asm("" : : "r"(address));
                                        assignment[0] = address;
                                    }
                                }
                                else
                                    func_080371C4((u8)i);
                            }
                        }
                        {
                            register u32 shifted asm("r0") = (u32)(u16)i << 16;
                            register u32 step asm("r1") = 0x10000;
                            asm("" : "+r"(step) : "r"(shifted));
                            shifted += step;
                            asm("" : "+r"(shifted));
                            i = (u16)(shifted >> 16);
                        }
                    }
                    {
                        register u8 *save asm("r2");
                        register u32 mask asm("r5");
                        register u32 initial_offset asm("r3");
                        register u8 *stat_start asm("r4");
                        i = 0;
                        save = D_02000B5C;
                        mask = 0x800;
                        initial_offset = 0xD54;
                        asm("" : : "r"(save), "r"(mask), "r"(initial_offset));
                        stat_start = save + initial_offset;
                        asm("" : : "r"(stat_start));
                        for (; i <= 172;)
                        {
                            register u32 index asm("r1") = (s16)i;
                            register u32 address asm("r0");
                            register u32 scaled asm("r3");
                            register u32 value asm("r1");
                            register u32 field asm("r7");
                            asm("" : : "r"(index));
                            address = index * 7;
                            asm("" : : "r"(address));
                            scaled = address * 8;
                            asm("" : : "r"(scaled));
                            value = scaled + (u32)save;
                            asm("" : : "r"(value));
                            field = 0xD32;
                            asm("" : "+r"(field));
                            address = value + field;
                            asm("" : : "r"(address));
                            address = *(u16 *)address;
                            asm("" : : "r"(address));
                            if (address == 0)
                                goto next_resource553;
                            field -= 6;
                            asm("" : : "r"(field));
                            address = value + field;
                            asm("" : : "r"(address));
                            value = *(u16 *)address;
                            asm("" : : "r"(value));
                            address = mask;
                            asm("" : : "r"(address));
                            if (address & value)
                                goto next_resource553;
                            value = scaled + (u32)stat_start;
                            asm("" : : "r"(value));
                            field += 8;
                            asm("" : : "r"(field));
                            address = (u32)save + field;
                            asm("" : : "r"(address));
                            address = scaled + address;
                            asm("" : : "r"(address));
                            value = *(u32 *)value;
                            address = *(u32 *)address;
                            asm("" : : "r"(value), "r"(address));
                            if ((s32)value > (s32)address)
                                break;
                            address = 0xD58;
                            asm("" : : "r"(address));
                            value = (u32)save + address;
                            asm("" : : "r"(value));
                            value = scaled + value;
                            asm("" : : "r"(value));
                            field += 4;
                            asm("" : : "r"(field));
                            address = (u32)save + field;
                            asm("" : : "r"(address));
                            address = scaled + address;
                            asm("" : : "r"(address));
                            value = *(u32 *)value;
                            address = *(u32 *)address;
                            asm("" : : "r"(value), "r"(address));
                            if ((s32)value > (s32)address)
                                break;
                        next_resource553:
                        {
                            register u32 shifted asm("r0") = (u32)(u16)i << 16;
                            register u32 step asm("r1") = 0x10000;
                            asm("" : "+r"(step));
                            asm("" : : "r"(shifted), "r"(step));
                            shifted += step;
                            asm("" : : "r"(shifted));
                            i = (u16)(shifted >> 16);
                        }
                        }
                    }
                    if ((u16)i != 173)
                        func_0803E488(D_0875B3B8, 14);
                    state = 0xFFFF;
                    break;
                }
            }
            if (D_02007574[1] == 0)
            {
                func_080551F4();
                if (D_0200E8A1 == 0)
                {
                    func_080019EC(79);
                    func_0803E488(D_0875B3B8, 5);
                    func_080019EC(65);
                    state = 0x30;
                    break;
                }
            }
            if (D_02007574[1] == 1)
            {
                if (D_0200E778 == 0)
                {
                    func_080019EC(79);
                    func_0803E488(D_0875B3B8, 3);
                    func_080019EC(65);
                    state = 0x30;
                    break;
                }
                if (({
                        register u8 *count asm("r2") = &D_02003E60;
                        asm("" : : "r"(count));
                        *count;
                    }) > 172)
                {
                    func_080019EC(79);
                    func_0803E488(D_0875B3B8, 4);
                    func_080019EC(65);
                    state = 0x30;
                    break;
                }
            }
            func_0803E488(D_0875AFB8, 0);
            {
                register u16 *choices asm("r1") = D_02007574;
                register u32 value asm("r0");
                register u16 *remembered asm("r3");
                register u32 step asm("r4");
                asm("" : : "r"(choices));
                value = choices[1];
                asm("" : : "r"(value));
                remembered = remembered_base;
                asm("" : : "r"(remembered), "r"(value));
                *remembered = value;
                value = choices[1];
                asm("" : : "r"(value));
                value <<= 24;
                step = 0x01000000;
                asm("" : : "r"(step), "r"(value));
                value += step;
                asm("" : : "r"(value));
                state_shift = value;
                goto store_shifted_state553;
            }
            break;
        case 0x100:
            func_0803E488(D_0875AFB8, 11);
            func_0803E488(D_0875AFB8, 10);
            func_0803E488(D_0875AFB8, 0);
            func_0803E488(D_0875B4D4, 0);
            {
                register u32 zero asm("r5") = 0;
                register u16 *cursor asm("r6");
                asm("" : : "r"(zero));
                frame.page = zero;
                cursor = &D_02007588;
                asm("" : : "r"(cursor), "r"(zero));
                *cursor = zero;
            }
            state = 0x102;
            break;
        case 0x101:
        {
            register const u8 *prompt asm("r0");
            ((const u8 *volatile)prompt) = D_0875B068;
            func_0803E488((const u8 *volatile)prompt, 0);
        }
            func_0803E488(D_0875AFB8, 42);
            {
                register const u32 *money asm("r7") = &D_02001884;
                asm("" : : "r"(money));
                func_08001848(*money, 7, 0);
            }
            {
                register const u8 *prompt asm("r0");
                ((const u8 *volatile)prompt) = D_0875B068;
                func_0803E488((const u8 *volatile)prompt, 1);
            }
            func_0803E488(D_0875B4D4, 0);
            {
                register u16 *remembered asm("r1") = remembered_base;
                register u32 value asm("r0");
                register u8 *cursor_byte asm("r2");
                register u16 *cursor_half asm("r3");
                asm("" : : "r"(remembered));
                value = remembered[2];
                asm("" : : "r"(value));
                cursor_byte = &D_02007FA9;
                asm("" : : "r"(cursor_byte), "r"(value));
                *cursor_byte = value;
                value = (u8)value;
                asm("" : : "r"(value));
                cursor_half = &D_02007588;
                asm("" : : "r"(cursor_half), "r"(value));
                *cursor_half = value;
            }
            {
                u16 *pages = frame.detail;
                asm("" : "+l"(pages));
                frame.page = pages[2];
            }
        case 0x102:
        {
            register u32 previous asm("r4") = 0xFFFF;
            register u32 zero asm("r5");
            register u16 *details asm("r6");
            asm("" : : "r"(previous));
            frame.previous_selected = previous;
            frame.previous_page = previous;
            zero = 0;
            asm("" : : "r"(zero));
            frame.refresh = zero;
            details = frame.remembered;
            asm("" : "+r"(details));
            details += 4;
            asm("" : : "r"(details));
            (*(u16 **)(formation_stack + 128)) = details;
        }
        recover_open:
            func_0803E488(D_0875AFB8, 25);
            func_0803E488(D_0875B4D4, 1);
            func_0803E488(D_0875AFB8, 28);
            {
                register u32 active asm("r7") = 1;
                asm("" : : "r"(active));
                frame.active = active;
            }
        recover_update:
        {
            register u32 cached_page asm("r5");
            register u32 cached_previous asm("r8");
            register u32 previous_page asm("r0");
            register u32 refresh asm("r2");
            {
                register u32 loaded asm("r0") = frame.page;
                asm("" : : "r"(loaded));
                cached_page = loaded << 16;
                asm("" : : "r"(cached_page));
            }
            {
                register u32 loaded asm("r1") = frame.previous_page;
                asm("" : : "r"(loaded));
                previous_page = loaded << 16;
                asm("" : : "r"(previous_page));
            }
            refresh = frame.refresh;
            asm("" : : "r"(refresh), "r"(previous_page));
            if (refresh)
                goto recover_redraw553;
            {
                register u32 loaded asm("r3") = frame.previous_selected;
                asm("" : : "r"(loaded));
                loaded <<= 16;
                asm("" : : "r"(loaded));
                cached_previous = loaded;
                asm("" : : "r"(cached_previous));
            }
            if (cached_page == previous_page)
                goto recover_selected553;
        recover_redraw553:
        {
            register u32 shown asm("r6");
            u8 *roster;
            u8 *cursor_byte;
            u8 *limit;
            register u8 *count asm("r12");
            register s32 last asm("r9");
            register u8 *page_flags asm("r7");
            {
                register s32 value asm("r0") = (s32)previous_page >> 16;
                register s32 minus_one asm("r4") = -1;
                asm("" : : "r"(value), "r"(minus_one));
                if (value != minus_one)
                    func_0803E488(D_0875AFB8, 3);
            }
            {
                register u8 *initial_count asm("r6") = &D_0200E8A1;
                asm("" : : "r"(initial_count));
                count = initial_count;
                asm("" : : "r"(count));
            }
            {
                register u32 previous asm("r7") = frame.previous_selected;
                asm("" : : "r"(previous));
                previous <<= 16;
                asm("" : : "r"(previous));
                cached_previous = previous;
                asm("" : : "r"(cached_previous));
            }
            {
                register s32 minus_one asm("r0") = -1;
                asm("" : : "r"(minus_one));
                last = minus_one;
                asm("" : : "r"(last));
            }
            cursor_byte = &D_02007FA9;
            asm("" : : "r"(cursor_byte));
        recover_page553:
            shown = 0;
            {
                register u32 shifted asm("r0") = cached_page << 2;
                register u32 row asm("r1");
                register u32 count_value asm("r2");
                asm("" : : "r"(shifted));
                row = shifted >> 16;
                asm("" : : "r"(row));
                frame.row = row;
                shifted = (s32)shifted >> 16;
                asm("" : : "r"(shifted));
                {
                    register u8 *count_pointer asm("r2") = count;
                    asm("" : : "r"(count_pointer));
                    count_value = *count_pointer;
                    asm("" : : "r"(count_value));
                }
                if ((s32)shifted < (s32)count_value)
                {
                    roster = D_02000B5C;
                    limit = &D_0200E8A1;
                    asm("" : "+r"(roster), "+r"(limit));
                recover_row553:
                {
                    register s32 row_index asm("r4");
                    u8 entry;
                    {
                        register u32 loaded asm("r4") = frame.row;
                        register u32 shifted asm("r0");
                        asm("" : : "r"(loaded));
                        shifted = loaded << 16;
                        asm("" : : "r"(shifted));
                        row_index = (s32)shifted >> 16;
                        asm("" : : "r"(row_index), "r"(limit), "r"(roster), "r"(cursor_byte));
                    }
                    {
                        register const u8 *row_roster asm("r1") = D_0200E7F4;
                        register const u8 *row_address asm("r0");
                        register u32 row_entry asm("r1");
                        asm("" : : "r"(row_roster), "r"(row_index));
                        row_address = (const u8 *)((u32)row_index + (u32)row_roster);
                        asm("" : : "r"(row_address));
                        row_entry = *row_address;
                        asm("" : : "r"(row_entry));
                        entry = row_entry;
                    }
                    func_08032800(*(u16 *)(roster + entry * 56 + 0xD32));
                    if ((s16)shown <= 2 && row_index < *limit - 1)
                    {
                        func_0803E488(D_08675C5C, 0);
                    }
                    {
                        register u32 shifted asm("r0") = (u32)shown << 16;
                        register u32 step asm("r4") = 0x10000;
                        register s32 next asm("r1");
                        asm("" : : "r"(shifted), "r"(step));
                        shifted += step;
                        asm("" : : "r"(shifted));
                        shown = shifted >> 16;
                        asm("" : : "r"(shown));
                        next = (s32)shifted >> 16;
                        asm("" : : "r"(next));
                        {
                            register u8 *next_count asm("r0") = &D_0200E8A1;
                            asm("" : : "r"(next_count));
                            count = next_count;
                            asm("" : : "r"(count));
                        }
                        if (next > 3)
                            goto recover_rows_done553;
                        shifted = (s32)cached_page >> 14;
                        asm("" : : "r"(shifted), "r"(next));
                        shifted = next + shifted;
                        shifted <<= 16;
                        asm("" : : "r"(shifted));
                        next = shifted >> 16;
                        asm("" : : "r"(next));
                        frame.row = next;
                        shifted = (s32)shifted >> 16;
                        asm("" : : "r"(shifted));
                        {
                            register u32 count_value asm("r4") = *limit;
                            asm(""
                                :
                                : "r"(count_value), "r"(shifted), "r"(roster), "r"(cursor_byte));
                            if ((s32)shifted < (s32)count_value)
                                goto recover_row553;
                        }
                    }
                }
                recover_rows_done553:;
                }
            }
            {
                register s32 shown_value asm("r0") = (s16)shown;
                asm("" : : "r"(shown_value), "r"(shown));
                if (shown_value == 0)
                {
                    register u32 shifted asm("r0");
                    register u32 next_page asm("r1");
                    {
                        register u32 loaded asm("r5") = frame.page;
                        register u32 decrement asm("r6");
                        asm("" : : "r"(loaded));
                        shifted = loaded << 16;
                        asm("" : : "r"(shifted));
                        decrement = 0xFFFF0000;
                        asm("" : : "r"(decrement));
                        shifted += decrement;
                        asm("" : : "r"(shifted));
                        shifted >>= 16;
                        asm("" : : "r"(shifted));
                        frame.page = shifted;
                    }
                    next_page = shifted << 16;
                    asm("" : : "r"(next_page));
                    shifted = (s32)next_page >> 16;
                    asm("" : : "r"(shifted));
                    page_flags = D_020075A0;
                    asm("" : : "r"(page_flags), "r"(shifted), "r"(last));
                    if ((s32)shifted == last)
                        goto recover_page_end553;
                    shifted = 3;
                    asm("" : : "r"(shifted), "r"(cursor_byte));
                    *cursor_byte = shifted;
                    menu_pointer.cursor = &D_02007588;
                    asm("" : "+l"(menu_pointer.cursor) : "r"(shifted));
                    *menu_pointer.cursor = shifted;
                    cached_page = next_page;
                    asm("" : : "r"(cached_page));
                    goto recover_page553;
                }
                {
                    register u16 *cursor asm("r2") = &D_02007588;
                    register u32 cursor_value asm("r1");
                    asm("" : : "r"(cursor));
                    page_flags = D_020075A0;
                    asm("" : : "r"(page_flags), "r"(cursor), "r"(shown_value));
                    cursor_value = *cursor;
                    asm("" : : "r"(cursor_value));
                    if (shown_value <= (s32)cursor_value)
                    {
                        register u32 value asm("r0");
                        asm("" : "+r"(shown));
                        value = shown - 1;
                        asm("" : : "r"(value));
                        *cursor_byte = value;
                        value = (u8)value;
                        asm("" : : "r"(value));
                        *cursor = value;
                    }
                }
            }
        recover_page_end553:
        {
            register u32 offset asm("r3") = 0xA0B;
            register u8 *flags asm("r2");
            register u32 zero asm("r0");
            asm("" : : "r"(offset), "r"(page_flags));
            flags = page_flags + offset;
            asm("" : : "r"(flags));
            offset = 0;
            asm("" : : "r"(offset));
            zero = 0;
            asm("" : : "r"(zero));
            *flags = zero;
            {
                register u32 loaded asm("r4") = frame.page;
                asm("" : : "r"(loaded));
                zero = loaded << 16;
                asm("" : : "r"(zero));
                cached_page = zero;
                asm("" : : "r"(cached_page));
            }
            if ((s32)cached_page > 0)
            {
                zero = 1;
                asm("" : : "r"(zero), "r"(flags));
                *flags = zero;
            }
            {
                register u32 row asm("r6") = frame.row;
                register s32 signed_row asm("r1");
                asm("" : : "r"(row));
                signed_row = row << 16;
                asm("" : : "r"(signed_row));
                signed_row >>= 16;
                asm("" : : "r"(signed_row));
                menu_pointer.count = count;
                asm("" : : "r"(menu_pointer.count));
                zero = *menu_pointer.count;
                asm("" : : "r"(zero));
                zero -= 1;
                asm("" : : "r"(zero), "r"(signed_row));
                if (signed_row < (s32)zero)
                {
                    register u32 bits asm("r1") = *flags;
                    asm("" : : "r"(bits));
                    zero = 2;
                    asm("" : : "r"(zero));
                    bits |= zero;
                    asm("" : : "r"(bits));
                    *flags = bits;
                }
            }
            zero = cached_page >> 16;
            asm("" : : "r"(zero));
            frame.previous_page = zero;
        }
        }
        recover_selected553:
        {
            register u32 selected asm("r0") = (s32)cached_page >> 14;
            register u32 cursor asm("r1");
            register u32 refresh asm("r2");
            asm("" : : "r"(selected));
            {
                register u16 *address asm("r1") = &D_02007588;
                asm("" : : "r"(address), "r"(selected));
                cursor = *address;
                asm("" : : "r"(cursor), "r"(selected));
            }
            selected += cursor;
            asm("" : : "r"(selected));
            selected <<= 16;
            asm("" : : "r"(selected));
            selected >>= 16;
            asm("" : : "r"(selected));
            frame.selected = selected;
            refresh = frame.refresh;
            asm("" : : "r"(refresh), "r"(selected));
            if (refresh)
                goto recover_selected_redraw553;
            selected <<= 16;
            asm("" : : "r"(selected));
            (*(volatile u32 *)(formation_stack + 136)) = selected;
            if (selected == cached_previous)
                goto recover_selected_done553;
        }
        recover_selected_redraw553:
        {
            u8 entry;
            u8 *selected_entry;
            register u8 *linked_entry asm("r4");
            {
                register u32 loaded asm("r3") = cached_previous;
                register s32 previous asm("r0");
                register s32 minus_one asm("r4");
                asm("" : : "r"(loaded));
                previous = (s32)loaded >> 16;
                minus_one = -1;
                asm("" : : "r"(previous), "r"(minus_one));
                if (previous != minus_one)
                {
                    register u8 *sprite asm("r2") = D_03004BBC;
                    register u32 flags asm("r1");
                    register u32 mask asm("r5");
                    register u32 value asm("r0");
                    asm("" : "+r"(sprite));
                    sprite += 0x88;
                    asm("" : : "r"(sprite));
                    flags = *(u16 *)sprite;
                    asm("" : : "r"(flags));
                    mask = 0x7FFF;
                    asm("" : : "r"(mask));
                    value = mask;
                    asm("" : : "r"(value));
                    flags &= value;
                    asm("" : : "r"(flags));
                    *(u16 *)sprite = flags;
                    func_0803E488(D_0875AFB8, 2);
                }
            }
            i = 0;
            asm("" : : "r"(i));
            menu_pointer.selector = frame.selected;
            asm("" : : "r"(menu_pointer.selector));
            menu_pointer.selector <<= 16;
            asm("" : : "r"(menu_pointer.selector));
            (*(volatile u32 *)(formation_stack + 136)) = menu_pointer.selector;
            {
                register u8 *save asm("r5") = D_02000B5C;
                register s32 index asm("r0");
                register u8 *roster asm("r1");
                asm("" : "+r"(save));
                index = (s32)menu_pointer.selector >> 16;
                asm("" : "+r"(index));
                roster = D_0200E7F4;
                asm("" : "+r"(roster));
                linked_entry = (u8 *)(index + (u32)roster);
                asm("" : "+r"(linked_entry));
                for (; i <= 86; i++)
                {
                    register u32 scaled asm("r0") = i * 4;
                    register u8 *record asm("r2");
                    register u8 *address asm("r0");
                    register u32 flags asm("r1");
                    register u32 mask asm("r0");
                    asm("" : "+r"(scaled));
                    record = (u8 *)(scaled + (u32)save);
                    asm("" : "+r"(record));
                    {
                        register u32 field_offset asm("r7");
                        ((volatile u32)field_offset) = 0x34A4;
                        address = record + (volatile u32)field_offset;
                    }
                    asm("" : "+r"(address));
                    flags = *(u16 *)address;
                    asm("" : "+r"(flags));
                    mask = 2;
                    asm("" : "+r"(mask));
                    mask &= flags;
                    asm("" : "+r"(mask));
                    if (mask)
                    {
                        register u32 offset asm("r1") = 0x34A6;
                        register u8 *address asm("r0");
                        register u32 value asm("r0");
                        register u32 selected asm("r2");
                        asm("" : "+r"(offset));
                        address = record + offset;
                        asm("" : "+r"(address));
                        value = *address;
                        asm("" : "+r"(value));
                        selected = *linked_entry;
                        asm("" : "+r"(selected));
                        if (value == selected)
                            break;
                    }
                }
            }
            frame.linked_slot = (u16)i;
            func_0803E488(D_0875AFB8, 27);
            {
                register u32 loaded asm("r3") = (*(volatile u32 *)(formation_stack + 136));
                register s32 index asm("r4");
                register u8 *roster asm("r5");
                asm("" : : "r"(loaded));
                index = (s32)loaded >> 16;
                asm("" : : "r"(index));
                roster = D_0200E7F4;
                asm("" : : "r"(roster), "r"(index));
                selected_entry = (u8 *)(index + (u32)roster);
                asm("" : "+l"(selected_entry));
            }
            {
                register u8 *display_save asm("r6");
                u32 stride;
                entry = *selected_entry;
                stride = entry * 56;
                asm("" : "+l"(stride));
                display_save = D_02000B5C;
                asm("" : "+r"(display_save));
                stride += (u32)display_save;
                asm("" : "+l"(stride));
                menu_pointer.offset = 0xD32;
                asm("" : : "r"(menu_pointer.offset));
                func_08032800(*(u16 *)(stride + menu_pointer.offset));
                {
                    register const u8 *separator asm("r0");
                    ((const u8 *volatile)separator) = D_08675C5C;
                    func_0803E488((const u8 *volatile)separator, 0);
                }
                func_0803E488(D_0875B448, 7);
                entry = *selected_entry;
                {
                    register u32 hp_stride asm("r0") = entry * 56;
                    register u32 hp_offset asm("r2");
                    register u8 *hp_base asm("r1");
                    register const s32 *hp_value asm("r0");
                    asm("" : : "r"(hp_stride));
                    hp_offset = 0xD54;
                    asm("" : : "r"(hp_offset), "r"(display_save));
                    hp_base = display_save + hp_offset;
                    asm("" : : "r"(hp_base), "r"(hp_stride));
                    hp_value = (const s32 *)(hp_stride + (u32)hp_base);
                    asm("" : : "r"(hp_value));
                    func_08001848(*hp_value, 4, 0);
                }
            }
            {
                register const u8 *separator asm("r0");
                ((const u8 *volatile)separator) = D_08675C5C;
                func_0803E488((const u8 *volatile)separator, 0);
            }
            func_0803E488(D_0875B448, 8);
            entry = *selected_entry;
            {
                register u32 stride asm("r0") = entry * 56;
                register const s32 *base asm("r3");
                register const s32 *value asm("r0");
                asm("" : : "r"(stride));
                base = (const s32 *)(D_02000B5C + 0xD58);
                asm("" : : "r"(base), "r"(stride));
                value = (const s32 *)(stride + (u32)base);
                asm("" : : "r"(value));
                func_08001848(*value, 3, 0);
            }
            {
                register const u8 *separator asm("r0");
                ((const u8 *volatile)separator) = D_08675C5C;
                func_0803E488((const u8 *volatile)separator, 0);
            }
            func_0803E488(D_0875B448, 11);
            {
                register u32 loaded asm("r4") = frame.linked_slot;
                register s32 linked asm("r0");
                asm("" : : "r"(loaded));
                linked = (s16)loaded;
                asm("" : "+r"(linked));
                if (linked != 87)
                    func_08032818(linked);
                else
                    func_0803E488(D_0875B448, 12);
            }
            {
                register u32 selected asm("r5") = (*(volatile u32 *)(formation_stack + 136));
                register u8 *roster asm("r6");
                register s32 index asm("r0");
                register u32 stride asm("r0");
                register u32 offset asm("r1");
                register u32 previous asm("r2");
                register u32 active asm("r3");
                register u32 refresh asm("r4");
                asm("" : : "r"(selected));
                index = (s32)selected >> 16;
                asm("" : : "r"(index));
                roster = D_0200E7F4;
                asm("" : : "r"(roster), "r"(index));
                entry = *(u8 *)(index + (u32)roster);
                stride = entry * 56;
                asm("" : : "r"(stride));
                menu_pointer.save = D_02000B5C;
                asm("" : : "r"(menu_pointer.save), "r"(stride));
                stride += (u32)menu_pointer.save;
                asm("" : : "r"(stride));
                offset = 0xD32;
                asm("" : : "r"(offset), "r"(stride));
                func_0804D654(*(u16 *)(stride + offset), 40, 88);
                previous = selected >> 16;
                asm("" : : "r"(previous));
                frame.previous_selected = previous;
                active = 1;
                asm("" : : "r"(active));
                frame.active = active;
                refresh = 0;
                asm("" : : "r"(refresh));
                frame.refresh = refresh;
            }
        }
        recover_selected_done553:
        {
            register u32 active asm("r5") = frame.active;
            asm("" : : "r"(active));
            if (active)
            {
                func_0803E488(D_0875AFB8, 24);
                {
                    register u32 cleared asm("r6");
                    ((volatile u32)cleared) = 0;
                    frame.active = (volatile u32)cleared;
                }
            }
        }
            do
                func_0803E488(D_0875AFB8, 36);
            while (D_0300235A & 4);
            {
                register u16 *address asm("r0") = D_02007574;
                register u32 first asm("r1");
                asm("" : "+r"(address));
                first = *address;
                asm("" : "+r"(first) : "r"(address));
                if (first > 1 && first != 128)
                {
                    register u32 key asm("r0");
                    menu_pointer.cursor = address;
                    asm("" : "+l"(menu_pointer.cursor));
                    ((volatile u32)key) = *menu_pointer.cursor;
                    if (key == 2)
                        goto recover_page_left553;
                    if (key == 4)
                        goto recover_page_right553;
                    goto recover_update;
                recover_page_left553:
                {
                    register u32 loaded asm("r1") = frame.page;
                    register u32 shifted asm("r0");
                    register s32 page asm("r4");
                    asm("" : : "r"(loaded));
                    shifted = loaded << 16;
                    page = (s32)shifted >> 16;
                    asm("" : "+r"(page));
                    if (page > 0)
                    {
                        func_080019EC(64);
                        shifted = page - 1;
                        asm("" : "+r"(shifted));
                        shifted <<= 16;
                        asm("" : "+r"(shifted));
                        frame.page = shifted >> 16;
                    }
                    goto recover_update;
                }
                recover_page_right553:
                {
                    register u32 loaded asm("r2") = frame.row;
                    register s32 row asm("r1");
                    asm("" : : "r"(loaded));
                    row = (s16)loaded;
                    asm("" : "+r"(row));
                    if (row < D_0200E8A1 - 1)
                    {
                        register u32 loaded_page asm("r3");
                        register u32 shifted asm("r0");
                        register u32 increment asm("r4");
                        func_080019EC(64);
                        loaded_page = frame.page;
                        asm("" : : "r"(loaded_page));
                        shifted = loaded_page << 16;
                        increment = 0x10000;
                        asm("" : "+r"(increment));
                        shifted += increment;
                        asm("" : "+r"(shifted));
                        frame.page = shifted >> 16;
                    }
                    goto recover_update;
                }
                }
            }
            {
                register u16 *input asm("r5") = D_02007574;
                register u32 action asm("r0");
                asm("" : : "r"(input));
                {
                    register u32 cursor asm("r0") = input[1];
                    register u16 *slots asm("r6");
                    asm("" : "+r"(cursor));
                    slots = remembered_base;
                    asm("" : "+r"(slots));
                    slots[2] = cursor;
                }
                {
                    register u32 page asm("r0");
                    ((u16 *volatile)menu_pointer.cursor) = frame.remembered;
                    ((volatile u32)page) = ((u16 *volatile)menu_pointer.cursor)[16];
                    ((u16 *volatile)menu_pointer.cursor) = (*(u16 **)(formation_stack + 128));
                    asm("" : "+l"(menu_pointer.cursor) : "r"(page), "r"(input));
                    ((u16 *volatile)menu_pointer.cursor)[2] = (volatile u32)page;
                }
                action = input[0];
                asm("" : : "r"(action));
                if (action == 1)
                {
                    u8 entry;
                    register u8 *save asm("r6") = D_02000B5C;
                    register u8 *selected_entry asm("r5");
                    register u32 model_offset asm("r4");
                    register u32 cost asm("r9");
                    register const u8 *confirmation asm("r8");
                    register const u8 *navigation asm("r10");
                    {
                        register u32 selected asm("r1") =
                            (*(volatile u32 *)(formation_stack + 136));
                        register s32 index asm("r0");
                        register u8 *roster asm("r2");
                        register u32 stride asm("r1");
                        register u32 model asm("r2");
                        register u32 model_size asm("r0");
                        register u32 bonus_offset asm("r3");
                        register s32 base_cost asm("r0");
                        register s32 bonus asm("r1");
                        asm("" : : "r"(save), "r"(selected));
                        index = (s32)selected >> 16;
                        asm("" : : "r"(index));
                        roster = D_0200E7F4;
                        asm("" : : "r"(roster), "r"(index));
                        selected_entry = (u8 *)(index + (u32)roster);
                        asm("" : "+r"(selected_entry));
                        entry = *selected_entry;
                        stride = entry * 56;
                        asm("" : : "r"(stride));
                        stride += (u32)save;
                        asm("" : : "r"(stride));
                        model_offset = 0xD32;
                        asm("" : : "r"(model_offset), "r"(stride));
                        model = *(u16 *)(stride + model_offset);
                        asm("" : : "r"(model));
                        model_size = 76;
                        asm("" : : "r"(model_size), "r"(model));
                        model *= model_size;
                        asm("" : : "r"(model));
                        menu_pointer.definition = D_0867006C + model;
                        asm("" : "+l"(menu_pointer.definition));
                        base_cost = *(s32 *)(menu_pointer.definition + 40);
                        asm("" : : "r"(base_cost));
                        bonus_offset = 0xD60;
                        asm("" : : "r"(bonus_offset), "r"(stride), "r"(base_cost));
                        bonus = *(u8 *)(stride + bonus_offset);
                        asm("" : : "r"(bonus), "r"(base_cost));
                        bonus = func_080346C0(base_cost, bonus);
                        asm("" : : "r"(bonus));
                        base_cost = *(s32 *)(menu_pointer.definition + 40);
                        cost = func_0805D484(base_cost + bonus, 10);
                        asm("" : : "r"(cost));
                    }
                    menu_pointer.definition = D_0875AFB8;
                    asm("" : "+l"(menu_pointer.definition));
                    func_0803E488(menu_pointer.definition, 0);
                    func_0803E488(menu_pointer.definition, 25);
                    {
                        register u32 stride asm("r0");
                        entry = *selected_entry;
                        stride = entry * 56;
                        asm("" : : "r"(stride));
                        stride += (u32)save;
                        asm("" : : "r"(stride));
                        func_08032800(*(u16 *)(stride + model_offset));
                    }
                    {
                        register const u8 *message asm("r4") = D_0875B4D4;
                        asm("" : : "r"(message));
                        confirmation = message;
                        asm("" : : "r"(confirmation));
                    }
                    func_0803E488(confirmation, 2);
                    func_08001848(cost, 7, 1);
                    func_0803E488(confirmation, 3);
                    {
                        register const u8 *message asm("r0") = D_0875B068;
                        asm("" : : "r"(message));
                        navigation = message;
                        asm("" : : "r"(navigation), "r"(message));
                        func_0803E488(message, 17);
                    }
                    func_0803E488(menu_pointer.definition, 0);
                    {
                        register u16 *response asm("r1") = D_02007574;
                        register u32 accepted asm("r0");
                        asm("" : : "r"(response));
                        accepted = response[0];
                        asm("" : : "r"(accepted));
                        if (accepted == 1)
                        {
                            if (response[1] == 0)
                            {
                                register u32 money_offset asm("r2");
                                register u32 *money asm("r4");
                                ((volatile u32)money_offset) = 0xD28;
                                asm("" : "+r"(money_offset));
                                ((u32 *volatile)money) = (u32 *)(save + (volatile u32)money_offset);
                                if (cost <= *money)
                                {
                                    {
                                        register u32 stride asm("r0");
                                        register u32 offset asm("r3");
                                        register u16 *address asm("r0");
                                        register u32 flags asm("r1");
                                        register u32 mask asm("r2");
                                        entry = *selected_entry;
                                        ((volatile u32)stride) = entry * 56;
                                        ((volatile u32)stride) = (volatile u32)stride + (u32)save;
                                        ((volatile u32)offset) = 0xD2C;
                                        {
                                            register union
                                            {
                                                unsigned long long whole;
                                                struct
                                                {
                                                    u32 low, high;
                                                } part;
                                            } guard asm("r2");
                                            guard.part.high = offset;
                                            offset = guard.part.high;
                                        }
                                        ((u16 *volatile)address) =
                                            (u16 *)((volatile u32)stride + (volatile u32)offset);
                                        ((volatile u32)flags) = *(u16 *volatile)address;
                                        ((volatile u32)offset) = 0xF7FF;
                                        ((volatile u32)mask) = (volatile u32)offset;
                                        asm("" : "+r"(offset), "+r"(mask));
                                        ((volatile u32)flags) =
                                            (volatile u32)flags & (volatile u32)mask;
                                        *(u16 *volatile)address = (volatile u32)flags;
                                    }
                                    {
                                        register u32 stride asm("r0");
                                        register u32 offset asm("r1");
                                        register u32 maximum_offset asm("r3");
                                        register u32 *current asm("r2");
                                        register u32 *maximum asm("r1");
                                        register u32 value asm("r0");
                                        entry = *selected_entry;
                                        ((volatile u32)stride) = entry * 56;
                                        ((volatile u32)offset) = 0xD34;
                                        {
                                            register union
                                            {
                                                unsigned long long whole;
                                                struct
                                                {
                                                    u32 low, high;
                                                } part;
                                            } guard asm("r0");
                                            guard.part.high = offset;
                                            offset = guard.part.high;
                                        }
                                        ((u32 *volatile)current) =
                                            (u32 *)(save + (volatile u32)offset);
                                        ((u32 *volatile)current) =
                                            (u32 *)((volatile u32)stride +
                                                    (u32)(u32 *volatile)current);
                                        ((volatile u32)maximum_offset) = 0xD54;
                                        {
                                            register union
                                            {
                                                unsigned long long whole;
                                                struct
                                                {
                                                    u32 low, high;
                                                } part;
                                            } guard asm("r2");
                                            guard.part.high = maximum_offset;
                                            maximum_offset = guard.part.high;
                                        }
                                        ((u32 *volatile)maximum) =
                                            (u32 *)(save + (volatile u32)maximum_offset);
                                        ((volatile u32)value) =
                                            *(u32 *)((volatile u32)stride +
                                                     (u32)(u32 *volatile)maximum);
                                        *(u32 *volatile)current = (volatile u32)value;
                                    }
                                    {
                                        register u32 stride asm("r0");
                                        register u32 offset asm("r5");
                                        register u32 *current asm("r1");
                                        register u32 *maximum asm("r6");
                                        register u32 value asm("r0");
                                        entry = *selected_entry;
                                        ((volatile u32)stride) = entry * 56;
                                        ((volatile u32)offset) = 0xD38;
                                        {
                                            register union
                                            {
                                                unsigned long long whole;
                                                struct
                                                {
                                                    u32 low, high;
                                                } part;
                                            } guard asm("r4");
                                            guard.part.high = offset;
                                            offset = guard.part.high;
                                        }
                                        ((u32 *volatile)current) =
                                            (u32 *)(save + (volatile u32)offset);
                                        ((u32 *volatile)current) =
                                            (u32 *)((volatile u32)stride +
                                                    (u32)(u32 *volatile)current);
                                        ((u32 *volatile)maximum) = (u32 *)(D_02000B5C + 0xD58);
                                        ((volatile u32)value) =
                                            *(u32 *)((volatile u32)stride +
                                                     (u32)(u32 *volatile)maximum);
                                        *(u32 *volatile)current = (volatile u32)value;
                                    }
                                    {
                                        register u32 balance asm("r0") = *money;
                                        register u32 spent asm("r1");
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = balance;
                                        balance = guard.part.low;
                                        spent = cost;
                                        guard.part.high = spent;
                                        spent = guard.part.high;
                                        *money = balance - spent;
                                    }
                                    func_0803E488(menu_pointer.definition, 1);
                                    func_0803E488(menu_pointer.definition, 26);
                                    func_0803E488(menu_pointer.definition, 42);
                                    func_08001848(*money, 7, 0);
                                    func_0803E488(navigation, 1);
                                    func_0803E488(menu_pointer.definition, 17);
                                    func_0803E488(confirmation, 4);
                                    func_080019EC(65);
                                    func_080551F4();
                                    if (D_0200E8A1 == 0)
                                        goto recovery_empty;
                                    {
                                        register u32 refreshed asm("r2") = 1;
                                        asm("" : "+r"(refreshed));
                                        frame.refresh = refreshed;
                                    }
                                }
                                else
                                {
                                    func_0803E488(confirmation, 6);
                                    func_080019EC(65);
                                }
                            }
                            else
                            {
                                func_0803E488(confirmation, 5);
                                func_080019EC(65);
                            }
                        }
                        else
                            func_080019EC(63);
                    }
                    {
                        register u16 *slots asm("r3") = remembered_base;
                        register u32 cursor asm("r0");
                        register u16 *destination asm("r4");
                        asm("" : "+r"(slots));
                        cursor = slots[2];
                        asm("" : "+r"(cursor));
                        destination = &D_02007588;
                        asm("" : "+r"(destination) : "r"(cursor));
                        *destination = cursor;
                    }
                    goto recover_open;
                }
                if (action == 0)
                    goto cancel_submenu;
                {
                    register u32 loaded asm("r5") = frame.linked_slot;
                    register s32 linked asm("r0");
                    asm("" : "+r"(loaded));
                    linked = (s16)loaded;
                    asm("" : "+r"(linked));
                    if (linked != 87)
                    {
                        register u32 item asm("r0") = (u8)loaded;
                        asm("" : "+r"(item));
                        frame.first_item = item;
                    }
                    else
                    {
                        register u32 item asm("r6") = 255;
                        asm("" : "+r"(item));
                        frame.first_item = item;
                    }
                }
                {
                    register u32 loaded asm("r7") = (*(volatile u32 *)(formation_stack + 136));
                    register u32 address asm("r0");
                    register u8 *roster asm("r1");
                    asm("" : "+r"(loaded));
                    address = (s32)loaded >> 16;
                    asm("" : "+r"(address));
                    roster = D_0200E7F4;
                    asm("" : "+r"(roster));
                    address += (u32)roster;
                    asm("" : "+r"(address));
                    frame.second_item = *(u8 *)address;
                }
                {
                    register u32 return_state asm("r2") = 0x101;
                    asm("" : "+r"(return_state));
                    frame.return_state = return_state;
                }
                state = 0x500;
                func_0803E488(D_0875AFB8, 11);
                {
                    register u8 *address asm("r2") = D_03004BBC;
                    register u32 value asm("r0");
                    register u32 stored_mask asm("r3");
                    register u32 mask asm("r1");
                    asm("" : "+r"(address));
                    address += 0x88;
                    asm("" : "+r"(address));
                    value = *(u16 *)address;
                    asm("" : "+r"(value));
                    stored_mask = 0x7FFF;
                    asm("" : "+r"(stored_mask));
                    mask = stored_mask;
                    asm("" : "+r"(mask));
                    value &= mask;
                    asm("" : "+r"(value));
                    *(u16 *)address = value;
                }
                func_0803E488(D_0875AFB8, 10);
                func_0803E488(D_0875AFB8, 9);
                func_0803E488(D_0875AFB8, 0);
                break;
            }
        }
        case 0x200:
        {
            register const u8 *message asm("r0");
            ((const u8 *volatile)message) = D_0875AFB8;
            func_0803E488((const u8 *volatile)message, 11);
        }
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875AFB8;
                func_0803E488((const u8 *volatile)message, 10);
            }
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875AFB8;
                func_0803E488((const u8 *volatile)message, 0);
            }
            func_0803E488(D_0875B3F4, 0);
            {
                register u32 zero asm("r4") = 0;
                register u32 previous asm("r5");
                register u16 *cursor asm("r6");
                asm("" : : "r"(zero));
                frame.page = zero;
                previous = 0xFFFF;
                asm("" : : "r"(previous));
                frame.previous_page = previous;
                frame.previous_core = previous;
                cursor = &D_02007588;
                asm("" : : "r"(cursor), "r"(zero));
                *cursor = zero;
            }
            state = 0x202;
            break;
        case 0x201:
            func_0803E488(D_0875B3F4, 0);
            menu_pointer.offset = 0xFFFF;
            asm("" : : "r"(menu_pointer.offset));
            frame.previous_page = menu_pointer.offset;
            frame.previous_core = menu_pointer.offset;
            {
                register u16 *details asm("r0") = frame.detail;
                register u16 *remembered asm("r1");
                register u8 *byte_cursor asm("r2");
                register u16 *cursor asm("r3");
                register u32 value asm("r0");
                asm("" : : "r"(details));
                value = details[1];
                frame.page = value;
                remembered = remembered_base;
                asm("" : : "r"(remembered));
                value = remembered[1];
                asm("" : : "r"(value));
                byte_cursor = &D_02007FA9;
                asm("" : : "r"(byte_cursor), "r"(value));
                *byte_cursor = value;
                value <<= 24;
                asm("" : : "r"(value));
                value >>= 24;
                asm("" : : "r"(value));
                cursor = &D_02007588;
                asm("" : : "r"(cursor), "r"(value));
                *cursor = value;
            }
            func_0803E488(D_0875AFB8, 28);
        case 0x202:
        {
            register u32 cached_core asm("r10");
            register u32 page_shift asm("r5");
            register s32 page asm("r4");
            register s32 previous_page asm("r2");
            register s32 selected_core asm("r4");
            register s32 previous_core asm("r1");
            func_0803E488(D_0875B3F4, 1);
        core_update:
        {
            register u32 loaded asm("r4") = frame.page;
            register u32 shifted asm("r1");
            register u32 previous asm("r5");
            register u32 previous_shift asm("r0");
            register u32 core asm("r6");
            asm("" : : "r"(loaded));
            shifted = loaded << 16;
            asm("" : : "r"(shifted));
            page = (s32)shifted >> 16;
            asm("" : : "r"(page));
            previous = frame.previous_page;
            asm("" : : "r"(previous));
            previous_shift = previous << 16;
            asm("" : : "r"(previous_shift));
            previous_page = (s32)previous_shift >> 16;
            asm("" : : "r"(previous_page));
            page_shift = shifted;
            asm("" : : "r"(page_shift));
            core = frame.previous_core;
            asm("" : : "r"(core));
            core <<= 16;
            asm("" : : "r"(core));
            cached_core = core;
            asm("" : : "r"(cached_core));
        }
            if (page != previous_page)
            {
                register u32 shown asm("r6");
                if (previous_page != -1)
                    func_0803E488(D_0875AFB8, 3);
                ((volatile u32)shown) = 0;

                {
                    register s32 base asm("r2");
                    register u8 *count asm("r4");
                    register u32 row_shift asm("r1");
                    register s32 row_signed asm("r1");
                    register u32 limit asm("r0");
                    ((volatile s32)base) = page * 4;
                    ((volatile u32)row_shift) = (u32)page << 18;

                    ((volatile u32)menu_pointer.selector) = ((volatile u32)row_shift) >> 16;
                    frame.row = menu_pointer.selector;
                    ((volatile s32)row_signed) = (s32)((volatile u32)row_shift) >> 16;

                    {
                        register u8 *address asm("r0") = &D_0200E778;
                        asm("" : : "r"(address));
                        count = address;
                        asm("" : : "r"(count));
                    }
                    limit = *count;
                    asm("" : : "r"(limit), "r"(row_signed));
                    if (row_signed < (s32)limit)
                    {
                        register u8 *roster asm("r9");
                        register s32 page_base asm("r8");
                        menu_pointer.count = count;
                        asm("" : : "r"(menu_pointer.count));
                        {
                            register u8 *address asm("r1") = D_0200E6DF;
                            asm("" : : "r"(address));
                            roster = address;
                            asm("" : : "r"(roster));
                        }
                        page_base = base;
                        asm("" : : "r"(page_base));
                    core_row553:
                    {
                        register s32 row asm("r4");
                        {
                            register u32 stored asm("r2") = frame.row;
                            register u32 shifted asm("r0");
                            register u8 *address asm("r3");
                            asm("" : : "r"(stored));
                            shifted = stored << 16;
                            asm("" : : "r"(shifted));
                            row = (s32)shifted >> 16;
                            asm("" : : "r"(row));
                            address = roster;
                            asm("" : : "r"(address));
                            {
                                register u8 *model asm("r0") = (u8 *)((u32)row + (u32)address);
                                asm("" : : "r"(model));
                                func_08032800(*model);
                            }
                        }
                        if ((s16)shown <= 2 && row < (s32)*menu_pointer.count - 1)
                            func_0803E488(D_08675C5C, 0);
                        {
                            register u32 shifted asm("r0") = (u32)shown << 16;
                            register u32 increment asm("r4") = 0x10000;
                            register s32 next asm("r0");
                            asm("" : : "r"(shifted), "r"(increment));
                            shifted += increment;
                            asm("" : : "r"(shifted));
                            shown = shifted >> 16;
                            asm("" : : "r"(shown));
                            next = (s32)shifted >> 16;
                            asm("" : : "r"(next));
                            count = &D_0200E778;
                            asm("" : : "r"(count), "r"(next));
                            if (next > 3)
                                goto core_rows_done553;
                            next += page_base;
                            asm("" : : "r"(next));
                            next <<= 16;
                            asm("" : : "r"(next));
                            {
                                register u32 value asm("r1") = (u32)next >> 16;
                                register u32 limit asm("r2");
                                asm("" : : "r"(value));
                                frame.row = value;
                                next >>= 16;
                                asm("" : : "r"(next));
                                limit = *menu_pointer.count;
                                asm("" : : "r"(limit), "r"(next));
                                if (next < (s32)limit)
                                    goto core_row553;
                            }
                        }
                    }
                    core_rows_done553:
                        asm("" : : "r"(roster), "r"(page_base));
                    }
                    {
                        register s32 shown_signed asm("r0");
                        register u16 *cursor asm("r2");
                        register u32 current asm("r3");
                        ((volatile s32)shown_signed) = (s16)shown;
                        ((u16 *volatile)cursor) = &D_02007588;
                        menu_pointer.save = D_020075A0;
                        asm("" : : "r"(menu_pointer.save));
                        ((volatile u32)current) = *((u16 *volatile)cursor);
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r2");
                            guard.part.high = current;
                            current = guard.part.high;
                        }
                        if (shown_signed <= (s32)current)
                        {
                            register u32 value asm("r0");
                            register u8 *byte_cursor asm("r6");
                            ((volatile u32)value) = shown - 1;
                            ((u8 *volatile)byte_cursor) = &D_02007FA9;
                            *byte_cursor = value;
                            ((volatile u32)value) = ((volatile u32)value) << 24;
                            ((volatile u32)value) = ((volatile u32)value) >> 24;
                            *cursor = value;
                        }
                        {
                            u32 offset = 0xA0B;
                            register u8 *flags asm("r2");
                            register u32 value asm("r0");
                            register u32 row asm("r6");
                            register s32 row_signed asm("r1");
                            asm("" : : "r"(offset), "r"(menu_pointer.save));
                            flags = (u8 *)((u32)menu_pointer.save + offset);
                            asm("" : : "r"(flags), "r"(offset));
                            {
                                register const u32 zero asm("r3") = 0;
                                asm("" : : "r"(zero));
                                ((volatile u32)value) = zero;
                            }
                            *flags = value;
                            if ((s32)page_shift > 0)
                            {
                                ((volatile u32)value) = 1;
                                *flags = value;
                            }
                            ((volatile u32)row) = frame.row;
                            ((volatile s32)row_signed) = (s32)(((volatile u32)row) << 16) >> 16;
                            ((volatile u32)value) = *count;
                            ((volatile u32)value) = ((volatile u32)value) - 1;
                            if (row_signed < (s32)value)
                            {
                                register u32 mask asm("r1");
                                ((volatile u32)value) = *flags;
                                ((volatile u32)mask) = 2;
                                value |= mask;
                                *flags = value;
                            }
                        }
                    }
                    asm("" : "+r"(page_shift));
                    menu_pointer.selector = page_shift >> 16;
                    asm("" : : "r"(menu_pointer.selector));
                    frame.previous_page = menu_pointer.selector;
                }
            }
            {
                register s32 shifted asm("r0") = (s32)page_shift >> 14;
                register u16 *cursor asm("r1");
                register u32 current asm("r1");
                register u32 selected asm("r2");
                register u32 previous asm("r3");
                asm("" : : "r"(shifted));
                cursor = &D_02007588;
                asm("" : : "r"(cursor));
                current = *cursor;
                asm("" : : "r"(current));
                shifted += current;
                asm("" : : "r"(shifted));
                shifted <<= 16;
                asm("" : : "r"(shifted));
                selected = (u32)shifted >> 16;
                asm("" : : "r"(selected));
                frame.selected_core = selected;
                selected_core = shifted >> 16;
                asm("" : : "r"(selected_core));
                previous = cached_core;
                asm("" : : "r"(previous));
                previous_core = (s32)previous >> 16;
                asm("" : : "r"(previous_core));
            }
            if (selected_core != previous_core)
            {
                register const u8 *core_detail asm("r5");
                if (previous_core != -1)
                    func_0803E488(D_0875AFB8, 2);
                {
                    const u8 *roster = D_0200E6DF;
                    register const u8 *entry asm("r0");
                    register u32 kind asm("r1");
                    register u32 stride asm("r0");
                    const u8 *definitions;
                    register const u8 *definition asm("r1");
                    asm("" : : "r"(roster));
                    entry = roster + selected_core;
                    asm("" : : "r"(entry), "r"(selected_core));
                    kind = *entry;
                    asm("" : : "r"(kind));
                    stride = 76;
                    asm("" : : "r"(stride), "r"(kind));
                    kind *= stride;
                    asm("" : : "r"(kind));
                    definitions = D_0867006C + 32;
                    asm("" : : "r"(definitions));
                    definition = definitions + kind;
                    asm("" : : "r"(definition));
                    frame.core_definition = definition;
                }
                func_0803E488(D_0875AFB8, 27);
                func_0803E488(D_0875B168, 1);
                core_detail = frame.core_definition;
                asm("" : : "r"(core_detail));
                func_08001848(*(s32 *)(core_detail + 4), 7, 1);
                func_0803E488(D_0875B168, 2);
                func_0803E488(D_0875AFB8, 42);
                if (core_detail[12] != 0)
                {
                    if (core_detail[12] <= 249)
                        func_08032800(core_detail[12]);
                    else
                    {
                        register const u8 *current_definition asm("r6") = frame.core_definition;
                        register u32 kind asm("r1");
                        asm("" : : "r"(current_definition));
                        kind = current_definition[12];
                        asm("" : : "r"(kind));
                        kind -= 250;
                        asm("" : : "r"(kind));
                        func_0803E488(D_0875B320, kind);
                    }
                }
                else
                    func_0803E488(D_0875B168, 4);
                {
                    register const u8 *separator asm("r5") = D_08675C5C;
                    register const u8 *labels asm("r4");
                    register const u8 *messages asm("r6");
                    asm("" : : "r"(separator));
                    func_0803E488(separator, 0);
                    labels = D_0875B168;
                    asm("" : : "r"(labels));
                    func_0803E488(labels, 3);
                    messages = D_0875AFB8;
                    asm("" : : "r"(messages));
                    func_0803E488(messages, 42);
                    menu_pointer.definition = frame.core_definition;
                    asm("" : : "r"(menu_pointer.definition));
                    if (menu_pointer.definition[13] != 255)
                    {
                        labels = D_08676254;
                        asm("" : : "r"(labels));
                        func_0803E488(labels, menu_pointer.definition[13]);
                        func_0803E488(separator, 0);
                        if (menu_pointer.definition[14] != 255)
                        {
                            func_0803E488(messages, 42);
                            func_0803E488(labels, menu_pointer.definition[14]);
                        }
                    }
                    else
                    {
                        register const u8 *current_definition asm("r1") =
                            *(const u8 *volatile *)&frame.core_definition;
                        register u32 next asm("r0");
                        asm("" : : "r"(current_definition));
                        next = current_definition[14];
                        asm("" : : "r"(next));
                        if (next != 255)
                        {
                            register u32 name asm("r1") = next;
                            register const u8 *messages asm("r0");
                            asm("" : : "r"(name));
                            messages = D_08676254;
                            asm("" : : "r"(messages));
                            func_0803E488(messages, name);
                        }
                        else
                            func_0803E488(labels, 4);
                    }
                }
                {
                    register u32 current asm("r2") = frame.selected_core;
                    register u32 active asm("r3");
                    asm("" : : "r"(current));
                    frame.previous_core = current;
                    active = 1;
                    asm("" : : "r"(active));
                    frame.active = active;
                }
            }
            {
                register u32 active asm("r4") = frame.active;
                asm("" : : "r"(active));
                if (active)
                {
                    register u32 zero asm("r5");
                    func_0803E488(D_0875AFB8, 24);
                    zero = 0;
                    asm("" : : "r"(zero));
                    frame.active = zero;
                }
            }
            asm("" : : "r"(cached_core));
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875AFB8;
                func_0803E488((const u8 *volatile)message, 35);
            }
            {
                register u16 *response asm("r1") = D_02007574;
                register u32 choice asm("r0");
                register u32 next_page asm("r0");
                asm("" : : "r"(response));
                choice = *response;
                asm("" : : "r"(choice));
                if (choice <= 1)
                    goto core_choice553;
                if (choice == 2)
                    goto core_previous_page553;
                if (choice == 4)
                    goto core_next_page553;
                goto core_update;
            core_previous_page553:
            {
                register u32 loaded asm("r6") = frame.page;
                register u32 shifted asm("r0");
                register s32 page asm("r4");
                asm("" : : "r"(loaded));
                shifted = loaded << 16;
                asm("" : : "r"(shifted));
                page = (s32)shifted >> 16;
                asm("" : : "r"(page));
                if (page <= 0)
                    goto core_update;
                func_080019EC(64);
                next_page = page - 1;
                asm("" : : "r"(next_page));
                next_page <<= 16;
                asm("" : : "r"(next_page));
                goto core_page_store553;
            }
            core_next_page553:
            {
                register u32 shifted asm("r1");
                register s32 row asm("r1");
                register u8 *count asm("r0");
                register s32 limit asm("r0");
                menu_pointer.selector = frame.row;
                asm("" : : "r"(menu_pointer.selector));
                shifted = menu_pointer.selector << 16;
                asm("" : : "r"(shifted));
                row = (s32)shifted >> 16;
                asm("" : : "r"(row));
                count = &D_0200E778;
                asm("" : : "r"(count));
                limit = *count;
                asm("" : : "r"(limit));
                limit--;
                asm("" : : "r"(limit), "r"(row));
                if (row >= limit)
                    goto core_update;
                func_080019EC(64);
                {
                    register u32 current asm("r1") = frame.page;
                    register u32 increment asm("r2");
                    asm("" : : "r"(current));
                    next_page = current << 16;
                    asm("" : : "r"(next_page));
                    increment = 0x10000;
                    asm("" : : "r"(increment));
                    next_page += increment;
                    asm("" : : "r"(next_page));
                }
            }
            core_page_store553:
                next_page >>= 16;
                asm("" : : "r"(next_page));
                frame.page = next_page;
                goto core_update;
            }
        core_choice553:
            if (D_02007574[0] == 0)
            {
                func_080019EC(63);
                func_0803E488(D_0875AFB8, 11);
                func_0803E488(D_0875AFB8, 10);
                func_0803E488(D_0875AFB8, 0);
                func_0803E488(D_0875B3B8, 0);
                state = 0x20;
                break;
            }
            func_0803E488(D_0875AFB8, 11);
            func_0803E488(D_0875AFB8, 10);
            func_0803E488(D_0875AFB8, 9);
            func_0803E488(D_0875AFB8, 0);
            {
                register u32 response asm("r0") = D_02007574[1];
                register u16 *remembered asm("r3");
                register u16 *details asm("r0");
                register u8 *frame_base asm("r4");
                register u32 page asm("r4");
                asm("" : : "r"(response));
                remembered = remembered_base;
                asm("" : : "r"(remembered), "r"(response));
                remembered[1] = response;
                details = frame.detail;
                asm("" : : "r"(details));
                frame_base = (u8 *)&frame;
                asm("" : : "r"(frame_base));
                page = *(u16 *)(frame_base + 0x20);
                asm("" : : "r"(page));
                details[1] = page;
            }
            state = 0x205;
            break;
        }
        case 0x205:
        {
            register const u8 *separator asm("r4");
            register const u8 *messages asm("r5");
            register u8 *core_entry asm("r6");
            u8 requirement_error;
            u8 core_kind;
            {
                register const u8 *script asm("r0");
                ((const u8 *volatile)script) = D_0875B3F4;
                func_0803E488((const u8 *volatile)script, 2);
            }
            func_0803E488(D_0875AFB8, 26);
            {
                register u8 *roster asm("r0") = D_0200E6DF;
                register u32 shifted asm("r5") = frame.selected_core;
                asm("" : : "r"(roster), "r"(shifted));
                shifted <<= 16;
                asm("" : : "r"(shifted), "r"(roster));
                (*(volatile u32 *)(formation_stack + 100)) = shifted;
                {
                    register s32 index asm("r6") = (s32)shifted >> 16;
                    asm("" : : "r"(index), "r"(roster));
                    core_entry = (u8 *)(index + (u32)roster);
                }
                asm("" : "+r"(core_entry));
            }
            core_kind = *core_entry;
            menu_pointer.definition = D_0867006C + core_kind * 76;
            asm("" : "+l"(menu_pointer.definition));
            func_08032800(core_kind);
            messages = D_0875B0F8;
            asm("" : "+r"(messages));
            func_0803E488(messages, menu_pointer.definition[4] + 8);
            separator = D_08675C5C;
            asm("" : "+r"(separator));
            func_0803E488(separator, 0);
            func_0803E488(messages, 1);
            func_08001848(*(s32 *)(menu_pointer.definition + 64), 4, 0);
            func_0803E488(separator, 0);
            func_0803E488(messages, 2);
            func_08001848(*(s32 *)(menu_pointer.definition + 68), 4, 0);
            func_0803E488(separator, 0);
            func_0803E488(messages, 3);
            {
                register u32 held2 asm("r2");
                register u32 held3 asm("r3");
                register s32 value asm("r0");
                asm("" : "=r"(held2), "=r"(held3) : "l"(menu_pointer.definition));
                value = *(s16 *)(menu_pointer.definition + 72);
                asm("" : : "r"(value), "r"(held2), "r"(held3));
                func_08001848(value, 4, 0);
            }
            func_0803E488(separator, 0);
            func_0803E488(messages, 4);
            {
                register u32 held1 asm("r1");
                register u32 held3 asm("r3");
                register s32 value asm("r0");
                asm("" : "=r"(held1), "=r"(held3) : "l"(menu_pointer.definition));
                value = *(s16 *)(menu_pointer.definition + 74);
                asm("" : : "r"(value), "r"(held1), "r"(held3));
                func_08001848(value, 3, 0);
            }
            func_0803E488(D_0875AFB8, 39);
            func_0804D654(*core_entry, 40, 88);
            func_0803E488(D_0875AFB8, 24);
            func_0803E488(D_0875B3F4, 3);
            {
                register const u8 *response_messages asm("r6");
                register u16 *response asm("r5");
                register u32 answer asm("r4");
                menu_pointer.selector = (*(volatile u32 *)(formation_stack + 100));
                asm("" : "+l"(menu_pointer.selector));
                response_messages = D_0875AFB8;
                response = D_02007574;
                asm("" : "+r"(response_messages), "+r"(response));
                do
                {
                    func_0803E488(response_messages, 38);
                    answer = response[0];
                    asm("" : "+r"(answer));
                } while (answer > 1 && answer != 128);
                if (answer == 128)
                    goto core_confirmation_inspect553;
                if (answer == 1 && response[1] == 0)
                {
                    func_080019EC(65);
                    requirement_error =
                        func_08055260(D_0200E6DF[((s32)menu_pointer.selector >> 16)]);
                    if (requirement_error != 0)
                    {
                        func_080019EC(79);
                        func_0803E488(response_messages, 0);
                        func_0803E488(response_messages, 25);
                        answer &= requirement_error;
                        if (answer)
                        {
                            if (requirement_error & 6)
                                func_0803E488(D_0875B3F4, 9);
                            else
                                func_0803E488(D_0875B3F4, 10);
                        }
                        if (requirement_error & 2)
                        {
                            if (requirement_error & 4)
                                func_0803E488(D_0875B3F4, 11);
                            else
                                func_0803E488(D_0875B3F4, 12);
                        }
                        if (requirement_error & 4)
                            func_0803E488(D_0875B3F4, 13);
                        func_0803E488(D_0875B3F4, 14);
                        func_080019EC(65);
                    }
                    else
                    {
                        register const u8 *definition asm("r5") = frame.core_definition;
                        asm("" : : "r"(definition));
                        if (definition[12] != 0)
                        {
                            {
                                register u8 *address asm("r0");
                                register u32 flags asm("r1");
                                register u32 mask asm("r7");
                                register u32 bits asm("r2");
                                ((u8 *volatile)address) = D_03004BBC;
                                asm("" : "+r"(address));
                                ((u8 *volatile)address) += 0x88;
                                ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
                                ((volatile u32)mask) = 0x7FFF;
                                asm("" : "+r"(flags), "+r"(mask));
                                ((volatile u32)bits) = (volatile u32)mask;
                                asm("" : "+r"(bits));
                                ((volatile u32)flags) &= (volatile u32)bits;
                                *(u16 *)(u8 *volatile)address = (volatile u32)flags;
                            }
                            func_0803E488(response_messages, 9);
                            func_0803E488(response_messages, 0);
                            state = 0x210;
                        }
                        else
                            state = 0x221;
                        break;
                    }
                }
                else if (D_02007574[0] == 0)
                    func_080019EC(63);
                {
                    register u8 *address asm("r2");
                    register u32 flags asm("r0");
                    register u32 mask asm("r3");
                    register u32 bits asm("r1");
                    ((u8 *volatile)address) = D_03004BBC;
                    asm("" : "+r"(address));
                    ((u8 *volatile)address) += 0x88;
                    ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
                    ((volatile u32)mask) = 0x7FFF;
                    asm("" : "+r"(flags), "+r"(mask));
                    ((volatile u32)bits) = (volatile u32)mask;
                    asm("" : "+r"(bits));
                    ((volatile u32)flags) &= (volatile u32)bits;
                    *(u16 *)(u8 *volatile)address = (volatile u32)flags;
                }
                func_0803E488(D_0875AFB8, 9);
                func_0803E488(D_0875AFB8, 0);
                {
                    register const u8 *prompt asm("r0");
                    ((const u8 *volatile)prompt) = D_0875B068;
                    func_0803E488((const u8 *volatile)prompt, 0);
                }
                func_0803E488(D_0875AFB8, 42);
                {
                    register const u32 *cash asm("r4") = &D_02001884;
                    asm("" : : "r"(cash));
                    func_08001848(*cash, 7, 0);
                }
                {
                    register const u8 *prompt asm("r0");
                    ((const u8 *volatile)prompt) = D_0875B068;
                    func_0803E488((const u8 *volatile)prompt, 1);
                }
                state = 0x201;
                break;
            core_confirmation_inspect553:
            {
                register u8 *roster asm("r1");
                register u32 address asm("r0");
                ((u8 *volatile)roster) = D_0200E6DF;
                ((volatile u32)address) = (s32)menu_pointer.selector >> 16;
                ((volatile u32)address) += (u32)(u8 *volatile)roster;
                frame.first_item = *(u8 *)(volatile u32)address;
            }
                {
                    register u32 second asm("r5");
                    register u32 returning asm("r7");
                    ((volatile u32)second) = 255;
                    frame.second_item = (volatile u32)second;
                    ((volatile u32)returning) = 0x205;
                    frame.return_state = (volatile u32)returning;
                }
                state = 0x510;
                {
                    register u8 *address asm("r2");
                    register u32 flags asm("r0");
                    register u32 mask asm("r3");
                    register u32 bits asm("r1");
                    ((u8 *volatile)address) = D_03004BBC;
                    asm("" : "+r"(address));
                    ((u8 *volatile)address) += 0x88;
                    ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
                    ((volatile u32)mask) = 0x7FFF;
                    asm("" : "+r"(flags), "+r"(mask));
                    ((volatile u32)bits) = (volatile u32)mask;
                    asm("" : "+r"(bits));
                    ((volatile u32)flags) &= (volatile u32)bits;
                    *(u16 *)(u8 *volatile)address = (volatile u32)flags;
                }
                func_0803E488(response_messages, 9);
                func_0803E488(response_messages, 0);
                break;
            }
        }
        break;
        case 0x210:
            func_0803E488(D_0875B448, 0);
            {
                register u32 page asm("r4");
                register u16 *cursor asm("r5");
                ((volatile u32)page) = 0;
                frame.page = (volatile u32)page;
                ((u16 *volatile)cursor) = &D_02007588;
                *(u16 *volatile)cursor = (volatile u32)page;
            }
            state = 0x212;
            break;
        case 0x211:
            func_0803E488(D_0875B448, 0);
            {
                register u16 *details asm("r0") = frame.detail;
                asm("" : : "r"(details));
                frame.page = details[2];
            }
            {
                register u16 *remembered asm("r6") = remembered_base;
                register u32 value asm("r0");
                register u16 *cursor asm("r1");
                asm("" : : "r"(remembered));
                ((volatile u32)value) = remembered[2];
                menu_pointer.count = &D_02007FA9;
                asm("" : "+l"(menu_pointer.count) : "r"(value));
                *menu_pointer.count = (volatile u32)value;
                ((volatile u32)value) = (u8)(volatile u32)value;
                ((u16 *volatile)cursor) = &D_02007588;
                *(u16 *volatile)cursor = (volatile u32)value;
            }
        case 0x212:
        {
            register u32 core_previous asm("r8");
            register const u8 *messages asm("r9");
            register u16 *refresh_flags asm("r10");
            u32 selected_word;
            {
                register u32 previous asm("r2");
                ((volatile u32)previous) = 0xFFFF;
                frame.previous_selected = (volatile u32)previous;
                frame.previous_page = (volatile u32)previous;
            }
            {
                register u8 *details asm("r3") = (u8 *)&frame;
                register const u8 *script asm("r4");
                register u16 *flags asm("r5");
                asm("" : "+r"(details));
                details += 8;
                (*(u16 **)(formation_stack + 128)) = (u16 *)details;
                script = D_0875AFB8;
                asm("" : "+r"(script));
                messages = script;
                asm("" : "+r"(messages));
                flags = (u16 *)(D_03004BBC + 0x88);
                asm("" : "+r"(flags));
                refresh_flags = flags;
                asm("" : "+r"(refresh_flags));
            }
        core_stock_open:
            func_0803E488(messages, 25);
            func_0803E488(D_0875B3F4, 15);
            func_0803E488(messages, 28);
            {
                register u32 active asm("r6");
                ((volatile u32)active) = 1;
                frame.active = (volatile u32)active;
            }
        core_stock_update:
        {
            register u32 page_shift asm("r5");
            register s32 page asm("r4");
            register s32 previous_page asm("r2");
            {
                register u32 loaded asm("r7") = frame.page;
                register u32 shifted asm("r1");
                register u32 previous asm("r2");
                register u32 previous_shift asm("r0");
                register u32 previous_selected asm("r3");
                asm("" : "+r"(loaded));
                shifted = loaded << 16;
                asm("" : "+r"(shifted));
                page = (s32)shifted >> 16;
                asm("" : "+r"(page));
                previous = frame.previous_page;
                asm("" : "+r"(previous));
                previous_shift = previous << 16;
                asm("" : "+r"(previous_shift));
                previous_page = (s32)previous_shift >> 16;
                asm("" : "+r"(previous_page));
                page_shift = shifted;
                asm("" : "+r"(page_shift));
                previous_selected = frame.previous_selected;
                asm("" : "+r"(previous_selected));
                previous_selected <<= 16;
                asm("" : "+r"(previous_selected));
                core_previous = previous_selected;
                asm("" : "+r"(core_previous));
            }
            if (page != previous_page)
            {
                register u32 shown asm("r6");
                register u8 *count_address asm("r12");
                u8 *count;
                u8 *save;
                if (previous_page != -1)
                    func_0803E488(D_0875AFB8, 3);
                ((volatile u32)shown) = 0;
                {
                    register u32 value asm("r0");
                    register u8 *address asm("r1");
                    register u32 limit asm("r1");
                    ((volatile u32)value) = (u32)(page * 6) << 16;
                    ((volatile u32)menu_pointer.selector) = (volatile u32)value >> 16;
                    frame.row = menu_pointer.selector;
                    ((volatile u32)value) = (s32)(volatile u32)value >> 16;
                    ((u8 *volatile)address) = &D_0200E8A1;
                    ((u8 *volatile)count_address) = (u8 *volatile)address;
                    ((volatile u32)limit) = *(u8 *volatile)address;
                    if ((s32)(volatile u32)value >= (s32)(volatile u32)limit)
                        goto core_stock_rows_done;
                }
                {
                    register u8 *base asm("r3");
                    ((u8 *volatile)base) = D_02000B5C;
                    count = count_address;
                    asm("" : "+r"(count) : "r"(base));
                    save = base;
                    asm("" : "+r"(save) : "r"(count));
                }
                ((volatile u32)menu_pointer.selector) = page;
            core_stock_row:
            {
                register s32 row_index asm("r4");
                register u32 shifted asm("r0");
                register u8 *roster asm("r1");
                register u32 entry asm("r1");
                register u32 model_address asm("r0");
                register u32 offset asm("r1");
                register s32 signed_shown asm("r0");
                ((volatile s32)row_index) = frame.row;
                ((volatile u32)shifted) = (volatile s32)row_index << 16;
                ((volatile s32)row_index) = (s32)(volatile u32)shifted >> 16;
                ((u8 *volatile)roster) = D_0200E7F4;
                ((volatile u32)model_address) = (volatile s32)row_index + (u32)(u8 *volatile)roster;
                ((volatile u32)entry) = *(u8 *)(volatile u32)model_address;
                ((volatile u32)model_address) = (volatile u32)entry * 56;
                ((volatile u32)model_address) = (volatile u32)model_address + (u32)save;
                asm("" : "+r"(model_address) : "r"(save));
                ((volatile u32)offset) = 0xD32;
                ((volatile u32)model_address) = (volatile u32)model_address + (volatile u32)offset;
                func_08032800(*(u16 *)(volatile u32)model_address);
                ((volatile s32)signed_shown) = (s32)((volatile u32)shown << 16) >> 16;
                asm("" : : "r"(count), "r"(save));
                if ((volatile s32)signed_shown <= 4 && (volatile s32)row_index < *count - 1)
                {
                    func_0803E488(D_08675C5C, 0);
                    asm("" : : "r"(save));
                    asm("" : : "r"(count));
                }
            }
                {
                    register u32 value asm("r0");
                    register u32 step asm("r4");
                    register s32 signed_shown asm("r1");
                    register u32 limit asm("r4");
                    ((volatile u32)value) = (volatile u32)shown << 16;
                    ((volatile u32)step) = 0x10000;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r4");
                        guard.part.low = step;
                        step = guard.part.low;
                    }
                    ((volatile u32)value) = (volatile u32)value + (volatile u32)step;
                    ((volatile u32)shown) = (volatile u32)value >> 16;
                    ((volatile s32)signed_shown) = (s32)(volatile u32)value >> 16;
                    {
                        register u8 *address asm("r0");
                        ((u8 *volatile)address) = &D_0200E8A1;
                        asm("" : : "r"(address));
                        ((u8 *volatile)count_address) = (u8 *volatile)address;
                    }
                    if ((volatile s32)signed_shown > 5)
                        goto core_stock_rows_done;
                    ((volatile u32)value) = menu_pointer.selector * 6;
                    ((volatile u32)value) = (volatile s32)signed_shown + (volatile u32)value;
                    ((volatile u32)value) = (volatile u32)value << 16;
                    frame.row = (volatile u32)value >> 16;
                    ((volatile u32)value) = (s32)(volatile u32)value >> 16;
                    ((volatile u32)limit) = *count;
                    asm("" : : "r"(limit));
                    if ((s32)(volatile u32)value < (s32)(volatile u32)limit)
                        goto core_stock_row;
                }
            core_stock_rows_done:
            {
                register s32 signed_shown asm("r0");
                register u16 *cursor asm("r2");
                register u32 cursor_value asm("r1");
                ((volatile s32)signed_shown) = (s32)((volatile u32)shown << 16) >> 16;
                ((u16 *volatile)cursor) = &D_02007588;
                menu_pointer.save = D_020075A0;
                asm("" : "+l"(menu_pointer.save));
                ((volatile u32)cursor_value) = *(u16 *volatile)cursor;
                asm("" : : "r"(cursor_value));
                if ((volatile s32)signed_shown <= (s32)(volatile u32)cursor_value)
                {
                    register u32 value asm("r0");
                    register u8 *byte_cursor asm("r3");
                    ((volatile u32)value) = (volatile u32)shown - 1;
                    ((u8 *volatile)byte_cursor) = &D_02007FA9;
                    *(u8 *volatile)byte_cursor = (volatile u32)value;
                    ((volatile u32)value) = (u8)(volatile u32)value;
                    *(u16 *volatile)cursor = (volatile u32)value;
                }
            }
                {
                    register u32 offset asm("r4");
                    register u8 *flags asm("r2");
                    register u32 value asm("r0");
                    register u32 row asm("r6");
                    register s32 signed_row asm("r1");
                    ((volatile u32)offset) = 0xA0B;
                    asm("" : : "r"(offset));
                    ((u8 *volatile)flags) = menu_pointer.save + (volatile u32)offset;
                    {
                        register const u32 zero asm("r3") = 0;
                        asm("" : : "r"(zero));
                        ((volatile u32)value) = zero;
                    }
                    *(u8 *volatile)flags = value;
                    if ((s32)page_shift > 0)
                    {
                        ((volatile u32)value) = 1;
                        *(u8 *volatile)flags = (volatile u32)value;
                    }
                    ((volatile u32)row) = frame.row;
                    ((volatile s32)signed_row) = (s32)((volatile u32)row << 16) >> 16;
                    menu_pointer.count = count_address;
                    asm("" : "+l"(menu_pointer.count));
                    ((volatile u32)value) = *menu_pointer.count;
                    ((volatile u32)value) = (volatile u32)value - 1;
                    if ((volatile s32)signed_row < (s32)(volatile u32)value)
                    {
                        register u32 bits asm("r1");
                        ((volatile u32)bits) = *(u8 *volatile)flags;
                        ((volatile u32)value) = 2;
                        ((volatile u32)bits) = (volatile u32)bits | (volatile u32)value;
                        *(u8 *volatile)flags = (volatile u32)bits;
                    }
                }
                asm("" : "+r"(page_shift));
                frame.previous_page = (u16)(page_shift >> 16);
            }
            {
                register s32 page asm("r1") = (s32)page_shift >> 16;
                register u32 value asm("r0");
                asm("" : "+r"(page));
                value = page * 6;
                asm("" : "+r"(value));
                {
                    register u16 *cursor asm("r1") = &D_02007588;
                    register u32 selected asm("r1");
                    asm("" : "+r"(cursor));
                    selected = *cursor;
                    asm("" : "+r"(selected));
                    value += selected;
                    asm("" : "+r"(value));
                }
                value <<= 16;
                asm("" : "+r"(value));
                value >>= 16;
                asm("" : "+r"(value));
                selected_word = value;
                frame.selected = selected_word;
            }
        }
            {
                register u32 selected_shift asm("r4");
                register s32 selected_index asm("r5");
                register u32 previous_shift asm("r2");
                register s32 previous asm("r1");
                selected_shift = selected_word << 16;
                asm("" : : "r"(selected_shift));
                ((volatile s32)selected_index) = (s32)selected_shift >> 16;
                previous_shift = core_previous;
                asm("" : : "r"(previous_shift));
                ((volatile s32)previous) = (s32)previous_shift >> 16;
                if ((volatile s32)selected_index != (volatile s32)previous)
                {
                    u8 entry;
                    register u32 slot asm("r6");
                    if ((volatile s32)previous != -1)
                    {
                        {
                            register u16 *address asm("r3");
                            register u32 flags asm("r1");
                            register u32 mask asm("r6");
                            register u32 bits asm("r0");
                            ((u16 *volatile)address) = refresh_flags;
                            ((volatile u32)flags) = *(u16 *volatile)address;
                            ((volatile u32)mask) = 0x7FFF;
                            asm("" : "+r"(flags), "+r"(mask));
                            ((volatile u32)bits) = (volatile u32)mask;
                            asm("" : "+r"(bits));
                            ((volatile u32)flags) &= (volatile u32)bits;
                            *(u16 *volatile)address = (volatile u32)flags;
                        }
                        func_0803E488(D_0875AFB8, 1);
                    }
                    slot = 0;
                    asm("" : "+r"(slot));
                    (*(u32 *)(formation_stack + 136)) = (volatile u32)selected_shift;
                    menu_pointer.save = (u8 *)&frame.stats;
                    asm("" : "+l"(menu_pointer.save));
                    stats_base = menu_pointer.save;
                    asm("" : "+r"(stats_base));
                    {
                        register const u8 *selected_entry asm("r4");
                        menu_pointer.save = D_02000B5C;
                        asm("" : "+l"(menu_pointer.save));
                        {
                            register const u8 *roster asm("r0");
                            ((const u8 *volatile)roster) = D_0200E7F4;
                            asm("" : "+r"(roster));
                            selected_entry = (u8 *)(volatile s32)selected_index +
                                             (u32)(const u8 *volatile)roster;
                            asm("" : "+r"(selected_entry));
                        }
                        {
                        core_stock_pilot_scan:
                        {
                            register u32 shifted asm("r0") = slot << 16;
                            register s32 index asm("r3");
                            register u8 *record asm("r2");
                            asm("" : "+r"(shifted));
                            index = (s32)shifted >> 16;
                            asm("" : "+r"(index));
                            shifted = index * 4;
                            asm("" : "+r"(shifted) : "r"(index));
                            record = (u8 *)(shifted + (u32)menu_pointer.save);
                            asm("" : "+r"(record) : "r"(index), "r"(menu_pointer.save));
                            {
                                register u32 flags_offset asm("r1");
                                ((volatile u32)flags_offset) = 0x34A4;
                                asm("" : "+r"(flags_offset));
                                {
                                    register u8 *flags_address asm("r0");
                                    ((u8 *volatile)flags_address) =
                                        record + (volatile u32)flags_offset;
                                    asm("" : "+r"(flags_address));
                                    if (*(u16 *)(u8 *volatile)flags_address & 2)
                                    {
                                        register u32 field asm("r5") = 0x34A6;
                                        register u8 *address asm("r0");
                                        asm("" : "+r"(field) : "r"(record), "r"(index));
                                        address = record + field;
                                        asm("" : "+r"(address));
                                        {
                                            register u32 linked_model asm("r0") = *address;
                                            register u32 selected_model asm("r1");
                                            asm("" : "+r"(linked_model));
                                            selected_model = *selected_entry;
                                            asm("" : "+r"(selected_model));
                                            if (linked_model == selected_model)
                                                goto core_stock_pilot_found;
                                        }
                                    }
                                }
                            }
                            shifted = index + 1;
                            asm("" : "+r"(shifted));
                            shifted <<= 16;
                            slot = shifted >> 16;
                            if (((s32)shifted >> 16) <= 86)
                                goto core_stock_pilot_scan;
                        }
                        core_stock_pilot_found:
                            frame.linked_slot = slot;
                        }
                    }
                    {
                        register const u8 *selected_entry asm("r4");
                        register u8 *save asm("r5");
                        {
                            register u32 loaded asm("r2");
                            register const u8 *roster asm("r3");
                            ((volatile u32)loaded) = (*(u32 *)(formation_stack + 136));
                            asm("" : "+r"(loaded));
                            ((const u8 *volatile)selected_entry) =
                                (u8 *)((s32)(volatile u32)loaded >> 16);
                            ((const u8 *volatile)roster) = D_0200E7F4;
                            ((const u8 *volatile)selected_entry) =
                                (const u8 *volatile)selected_entry +
                                (u32)(const u8 *volatile)roster;
                        }
                        {
                            register u32 model asm("r1") = *selected_entry;
                            register u32 product asm("r0");
                            register u32 field asm("r6");
                            register u8 *source asm("r0");
                            register struct MenuStats553 *destination asm("r1");
                            asm("" : "+r"(model));
                            product = model * 56;
                            asm("" : "+r"(product));
                            save = D_02000B5C;
                            asm("" : "+r"(save) : "r"(product));
                            source = (u8 *)(product + (u32)save);
                            asm("" : "+r"(source));
                            destination = (struct MenuStats553 *)stats_base;
                            asm("" : "+r"(destination) : "r"(source));
                            field = 0xD54;
                            asm("" : "+r"(field) : "r"(source), "r"(destination));
                            source += field;
                            asm("" : "+r"(source));
                            *destination = *(struct MenuStats553 *)source;
                            asm("" : : "r"(save), "r"(selected_entry), "r"(field));
                        }
                        func_0803E488(D_0875AFB8, 26);
                        {
                            register u32 model asm("r1") = *selected_entry;
                            register u32 product asm("r0");
                            register u32 field asm("r4");
                            register u8 *source asm("r0");
                            asm("" : "+r"(model));
                            product = model * 56;
                            asm("" : "+r"(product));
                            source = (u8 *)(product + (u32)save);
                            asm("" : "+r"(source));
                            field = 0xD32;
                            asm("" : "+r"(field) : "r"(source));
                            source += field;
                            asm("" : "+r"(source));
                            func_08032800(*(u16 *)source);
                        }
                    }
                    {
                        register const u8 *separator asm("r4");
                        register const u8 *messages asm("r5");
                        ((const u8 *volatile)separator) = D_08675C5C;
                        func_0803E488((const u8 *volatile)separator, 0);
                        ((const u8 *volatile)messages) = D_0875B448;
                        func_0803E488((const u8 *volatile)messages, 7);
                        func_08001848(frame.stats.hp, 4, 0);
                        func_0803E488((const u8 *volatile)separator, 0);
                        func_0803E488((const u8 *volatile)messages, 8);
                        {
                            register const u8 *stats asm("r6");
                            ((const u8 *volatile)stats) = (u8 *volatile)stats_base;
                            func_08001848(*(s32 *)((const u8 *volatile)stats + 4), 3, 0);
                        }
                        func_0803E488((const u8 *volatile)separator, 0);
                        func_0803E488((const u8 *volatile)messages, 11);
                        {
                            register u32 linked asm("r7");
                            register u32 argument asm("r0");
                            ((volatile u32)linked) = frame.linked_slot;
                            ((volatile u32)argument) = (volatile u32)linked << 16;
                            ((volatile u32)argument) = (s32)(volatile u32)argument >> 16;
                            if ((volatile u32)argument != 87)
                                func_08032818((volatile u32)argument);
                            else
                                func_0803E488((const u8 *volatile)messages, 12);
                        }
                    }
                    {
                        register u32 selected asm("r1");
                        register u32 address asm("r0");
                        register const u8 *roster asm("r2");
                        register const u8 *save asm("r3");
                        register u32 offset asm("r4");
                        ((volatile u32)selected) = (*(u32 *)(formation_stack + 136));
                        asm("" : : "r"(selected));
                        ((volatile u32)address) = (s32)(volatile u32)selected >> 16;
                        ((const u8 *volatile)roster) = D_0200E7F4;
                        ((volatile u32)address) += (u32)(const u8 *volatile)roster;
                        ((volatile u32)selected) = *(u8 *)(volatile u32)address;
                        ((volatile u32)address) = (volatile u32)selected * 56;
                        ((const u8 *volatile)save) = D_02000B5C;
                        ((volatile u32)address) += (u32)(const u8 *volatile)save;
                        ((volatile u32)offset) = 0xD32;
                        asm("" : "+r"(offset));
                        ((volatile u32)address) += (volatile u32)offset;
                        func_0804D654(*(u16 *)(volatile u32)address, 40, 88);
                    }
                    {
                        register u32 previous asm("r5");
                        register u32 active asm("r6");
                        ((volatile u32)previous) = (*(u32 *)(formation_stack + 136));
                        asm("" : : "r"(previous));
                        ((volatile u32)previous) >>= 16;
                        frame.previous_selected = (volatile u32)previous;
                        ((volatile u32)active) = 1;
                        frame.active = (volatile u32)active;
                    }
                }
            }
            {
                register u32 active asm("r7") = frame.active;
                asm("" : : "r"(active));
                if (active)
                {
                    func_0803E488(D_0875AFB8, 24);
                    frame.active = 0;
                }
            }
            do
                func_0803E488(D_0875AFB8, 36);
            while (D_0300235A & 4);
            {
                register u16 *address asm("r0") = D_02007574;
                register u32 first asm("r1");
                asm("" : "+r"(address));
                first = *address;
                asm("" : "+r"(first) : "r"(address));
                if (first > 1 && first != 128)
                {
                    register u16 *keys asm("r1");
                    register u32 key asm("r0");
                    ((u16 *volatile)keys) = address;
                    asm("" : : "r"(keys));
                    key = *keys;
                    asm("" : "+r"(key));
                    if (key == 2)
                        goto core_stock_page_left553;
                    if (key == 4)
                        goto core_stock_page_right553;
                    goto core_stock_update;
                core_stock_page_left553:
                {
                    register u32 loaded asm("r2") = frame.page;
                    register u32 shifted asm("r0");
                    register s32 page asm("r4");
                    asm("" : : "r"(loaded));
                    ((volatile u32)shifted) = loaded << 16;
                    ((volatile s32)page) = (s32)(volatile u32)shifted >> 16;
                    asm("" : : "r"(page));
                    if (page > 0)
                    {
                        func_080019EC(64);
                        ((volatile u32)shifted) = page - 1;
                        ((volatile u32)shifted) <<= 16;
                        frame.page = (volatile u32)shifted >> 16;
                    }
                }
                    goto core_stock_update;
                core_stock_page_right553:
                {
                    register u32 loaded asm("r3") = frame.row;
                    register s32 row asm("r1");
                    asm("" : : "r"(loaded));
                    ((volatile s32)row) = (s16)loaded;
                    if ((volatile s32)row < D_0200E8A1 - 1)
                    {
                        register u32 loaded_page asm("r4");
                        register u32 shifted asm("r0");
                        register u32 increment asm("r5");
                        func_080019EC(64);
                        ((volatile u32)loaded_page) = frame.page;
                        asm("" : : "r"(loaded_page));
                        ((volatile u32)shifted) = (volatile u32)loaded_page << 16;
                        ((volatile u32)increment) = 0x10000;
                        asm("" : : "r"(increment));
                        ((volatile u32)shifted) += (volatile u32)increment;
                        frame.page = (volatile u32)shifted >> 16;
                    }
                }
                    goto core_stock_update;
                }
            }
            {
                register u32 action asm("r0");
                {
                    register u16 *input asm("r6") = D_02007574;
                    register u32 cursor asm("r0");
                    asm("" : "+r"(input));
                    cursor = input[1];
                    asm("" : "+r"(cursor));
                    menu_pointer.cursor = remembered_base;
                    asm("" : "+l"(menu_pointer.cursor));
                    menu_pointer.cursor[2] = cursor;
                    {
                        register u32 page asm("r1") = *(volatile u16 *)&frame.page;
                        register u16 *details asm("r0");
                        asm("" : "+r"(page));
                        details = (*(u16 **)(formation_stack + 128));
                        asm("" : "+r"(details));
                        details[2] = page;
                    }
                    action = input[0];
                    asm("" : "+r"(action));
                }
                if (action == 1)
                {
                    register s32 linked asm("r5");
                    {
                        register u32 loaded asm("r2") = frame.linked_slot;
                        register u32 shifted asm("r0");
                        asm("" : : "r"(loaded));
                        ((volatile u32)shifted) = loaded << 16;
                        ((volatile s32)linked) = (s32)(volatile u32)shifted >> 16;
                        asm("" : : "r"(linked));
                    }
                    if (linked != 87)
                    {
                        register u8 *save asm("r6");
                        register u32 address asm("r0");
                        register u32 field asm("r3");
                        ((const u8 *volatile)menu_pointer.definition) = D_0875AFB8;
                        func_0803E488((const u8 *volatile)menu_pointer.definition, 0);
                        func_0803E488((const u8 *volatile)menu_pointer.definition, 25);
                        ((u8 *volatile)save) = D_02000B5C;
                        asm("" : : "r"(save));
                        ((volatile u32)address) = linked * 4;
                        ((volatile u32)address) += (u32)(u8 *volatile)save;
                        ((volatile u32)field) = 0x34A4;
                        asm("" : : "r"(field));
                        ((volatile u32)address) += (volatile u32)field;
                        if (*(u16 *)(volatile u32)address & 8)
                        {
                            u8 entry;
                            func_080019EC(79);
                            func_08032818(linked);
                            func_0803E488(D_0875B434, 1);
                            {
                                register u32 selected asm("r5") = frame.selected;
                                register u32 address asm("r0");
                                register u32 model asm("r1");
                                register u32 offset asm("r1");
                                asm("" : : "r"(selected));
                                ((volatile u32)address) = selected << 16;
                                ((volatile u32)address) = (s32)(volatile u32)address >> 16;
                                ((u8 *volatile)menu_pointer.count) = D_0200E7F4;
                                ((volatile u32)address) += (u32)(u8 *volatile)menu_pointer.count;
                                ((volatile u32)model) = *(u8 *)(volatile u32)address;
                                ((volatile u32)address) = (volatile u32)model * 56;
                                ((volatile u32)address) += (u32)(u8 *volatile)save;
                                ((volatile u32)offset) = 0xD32;
                                asm("" : : "r"(offset));
                                ((volatile u32)address) += (volatile u32)offset;
                                func_08032800(*(u16 *)(volatile u32)address);
                            }
                            func_0803E488(D_0875B434, 3);
                            func_080019EC(65);
                            {
                                register u16 *remembered asm("r2") = remembered_base;
                                register u32 value asm("r0");
                                register u16 *cursor asm("r3");
                                ((volatile u32)value) = remembered[2];
                                cursor = &D_02007588;
                                asm("" : : "r"(remembered), "r"(cursor));
                                *cursor = value;
                            }
                            goto core_stock_open;
                        }
                        {
                            register u32 selected asm("r4") = frame.selected;
                            register u32 address asm("r0");
                            register const u8 *roster asm("r1");
                            register u32 model asm("r1");
                            register u32 offset asm("r2");
                            asm("" : : "r"(selected));
                            ((volatile u32)address) = selected << 16;
                            ((volatile u32)address) = (s32)(volatile u32)address >> 16;
                            ((const u8 *volatile)roster) = D_0200E7F4;
                            ((volatile u32)address) += (u32)(const u8 *volatile)roster;
                            ((volatile u32)model) = *(u8 *)(volatile u32)address;
                            ((volatile u32)address) = (volatile u32)model * 56;
                            ((volatile u32)address) += (u32)(u8 *volatile)save;
                            ((volatile u32)offset) = 0xD32;
                            asm("" : : "r"(offset));
                            ((volatile u32)address) += (volatile u32)offset;
                            func_08032800(*(u16 *)(volatile u32)address);
                        }
                        func_0803E488(D_0875B448, 2);
                        func_08032818(linked);
                        func_0803E488(D_0875B448, 3);
                        func_0803E488(D_0875B068, 17);
                        func_0803E488((const u8 *volatile)menu_pointer.definition, 0);
                        {
                            register u16 *response asm("r3") = D_02007574;
                            register u32 first asm("r0");
                            asm("" : "+r"(response));
                            first = response[0];
                            asm("" : "+r"(first));
                            if (first != 1)
                                goto core_stock_prompt_cancel553;
                            first = response[1];
                            asm("" : "+r"(first));
                            if (first != 0)
                                goto core_stock_prompt_cancel553;
                        }
                        state = 0x220;
                        goto core_stock_selected_commit553;
                    }
                    else
                    {
                        state = 0x220;
                        goto core_stock_selected_commit553;
                    }
                core_stock_prompt_cancel553:
                    if (*(volatile u16 *)D_02007574 == 0)
                        func_080019EC(63);
                    {
                        register u16 *remembered asm("r4") = remembered_base;
                        register u32 value asm("r0");
                        register u16 *cursor asm("r5");
                        asm("" : "+r"(remembered));
                        value = remembered[2];
                        asm("" : "+r"(value));
                        cursor = &D_02007588;
                        asm("" : "+r"(cursor));
                        *cursor = value;
                    }
                    goto core_stock_open;
                core_stock_selected_commit553:
                    func_0803E488(messages, 11);
                    {
                        register u16 *address asm("r6") = refresh_flags;
                        register u32 flags asm("r0");
                        register u32 mask asm("r7");
                        register u32 bits asm("r1");
                        asm("" : : "r"(address));
                        ((volatile u32)flags) = *address;
                        asm("" : : "r"(flags));
                        ((volatile u32)mask) = 0x7FFF;
                        asm("" : "+r"(mask));
                        ((volatile u32)bits) = mask;
                        asm("" : : "r"(bits));
                        ((volatile u32)flags) &= (volatile u32)bits;
                        *address = (volatile u32)flags;
                    }
                    func_0803E488(messages, 9);
                }
                else if (action == 0)
                {
                    func_080019EC(63);
                    state = 0x201;
                    func_0803E488(messages, 11);
                    {
                        register u32 flags asm("r0");
                        register u32 mask asm("r2");
                        register u32 bits asm("r1");
                        {
                            register u16 *address asm("r1") = refresh_flags;
                            asm("" : : "r"(address));
                            ((volatile u32)flags) = *address;
                            asm("" : : "r"(flags));
                        }
                        ((volatile u32)mask) = 0x7FFF;
                        asm("" : "+r"(mask));
                        ((volatile u32)bits) = mask;
                        asm("" : : "r"(bits));
                        ((volatile u32)flags) &= (volatile u32)bits;
                        {
                            register u16 *address asm("r3");
                            ((u16 *volatile)address) = refresh_flags;
                            asm("" : : "r"(address));
                            *address = (volatile u32)flags;
                        }
                    }
                    func_0803E488(messages, 9);
                    {
                        register const u8 *prompt asm("r0");
                        ((const u8 *volatile)prompt) = D_0875B068;
                        func_0803E488((const u8 *volatile)prompt, 0);
                    }
                    func_0803E488(messages, 42);
                    {
                        register const u32 *money asm("r4") = &D_02001884;
                        asm("" : : "r"(money));
                        func_08001848(*money, 7, 0);
                    }
                    {
                        register const u8 *prompt asm("r0");
                        ((const u8 *volatile)prompt) = D_0875B068;
                        func_0803E488((const u8 *volatile)prompt, 1);
                    }
                }
                else
                {
                    {
                        register u32 linked asm("r5") = frame.linked_slot;
                        register u32 value asm("r0");
                        asm("" : : "r"(linked));
                        ((volatile u32)value) = linked << 16;
                        ((volatile u32)value) = (s32)(volatile u32)value >> 16;
                        if ((s32)(volatile u32)value <= 86)
                        {
                            ((volatile u32)value) = (u8)linked;
                            frame.first_item = (volatile u32)value;
                        }
                        else
                        {
                            register u32 none asm("r6") = 255;
                            asm("" : : "r"(none));
                            frame.first_item = none;
                        }
                    }
                    {
                        register u32 selected asm("r7") = frame.selected;
                        register u32 address asm("r0");
                        register const u8 *roster asm("r1");
                        register u32 returning asm("r2");
                        asm("" : : "r"(selected));
                        ((volatile u32)address) = selected << 16;
                        ((volatile u32)address) = (s32)(volatile u32)address >> 16;
                        ((const u8 *volatile)roster) = D_0200E7F4;
                        ((volatile u32)address) += (u32)(const u8 *volatile)roster;
                        ((volatile u32)address) = *(u8 *)(volatile u32)address;
                        frame.second_item = (volatile u32)address;
                        ((volatile u32)returning) = 0x211;
                        asm("" : : "r"(returning));
                        frame.return_state = (volatile u32)returning;
                    }
                    state = 0x500;
                    func_0803E488(messages, 11);
                    {
                        register u16 *address asm("r3") = refresh_flags;
                        register u32 flags asm("r0");
                        register u32 mask asm("r4");
                        register u32 bits asm("r1");
                        asm("" : : "r"(address));
                        ((volatile u32)flags) = *address;
                        asm("" : : "r"(flags));
                        ((volatile u32)mask) = 0x7FFF;
                        asm("" : "+r"(mask));
                        ((volatile u32)bits) = mask;
                        asm("" : : "r"(bits));
                        ((volatile u32)flags) &= (volatile u32)bits;
                        *address = (volatile u32)flags;
                    }
                    func_0803E488(messages, 9);
                }
                func_0803E488(D_0875AFB8, 0);
            }
            break;
        }
        case 0x220:
        {
            register const u8 *separator asm("r4");
            register const u8 *messages asm("r5");
            register u8 *core_entry asm("r6");
            u8 core_kind;
            {
                register const u8 *script asm("r0");
                ((const u8 *volatile)script) = D_0875B3F4;
                func_0803E488((const u8 *volatile)script, 2);
            }
            {
                register const u8 *script asm("r0");
                ((const u8 *volatile)script) = D_0875AFB8;
                func_0803E488((const u8 *volatile)script, 26);
            }
            {
                register u8 *roster asm("r0") = D_0200E6DF;
                register u32 shifted asm("r5") = frame.selected_core;
                register s32 index asm("r6");
                asm("" : : "r"(roster), "r"(shifted));
                shifted <<= 16;
                asm("" : : "r"(shifted), "r"(roster));
                ((volatile u32)(*(volatile u32 *)(formation_stack + 108))) = shifted;
                index = (s32)shifted >> 16;
                asm("" : : "r"(index), "r"(roster));
                core_entry = (u8 *)(index + (u32)roster);
                asm("" : "+r"(core_entry));
            }
            core_kind = *core_entry;
            menu_pointer.definition = D_0867006C + core_kind * 76;
            asm("" : "+l"(menu_pointer.definition));
            func_08032800(core_kind);
            messages = D_0875B0F8;
            asm("" : "+r"(messages));
            func_0803E488(messages, menu_pointer.definition[4] + 8);
            separator = D_08675C5C;
            asm("" : "+r"(separator));
            func_0803E488(separator, 0);
            func_0803E488(messages, 1);
            func_08001848(*(s32 *)(menu_pointer.definition + 64), 4, 0);
            func_0803E488(separator, 0);
            func_0803E488(messages, 2);
            func_08001848(*(s32 *)(menu_pointer.definition + 68), 4, 0);
            func_0803E488(separator, 0);
            func_0803E488(messages, 3);
            func_08001848(*(s16 *)(menu_pointer.definition + 72), 4, 0);
            func_0803E488(separator, 0);
            func_0803E488(messages, 4);
            func_08001848(*(s16 *)(menu_pointer.definition + 74), 3, 0);
            {
                register const u8 *script asm("r0");
                ((const u8 *volatile)script) = D_0875AFB8;
                func_0803E488((const u8 *volatile)script, 39);
            }
            func_0804D654(*core_entry, 40, 88);
        }
        case 0x221:
        {
            register const u8 *messages asm("r4") = D_0875AFB8;
            register const u8 *core_messages asm("r5");
            register const u8 *prompt asm("r6");
            asm("" : "+r"(messages));
            func_0803E488(messages, 25);
            core_messages = D_0875B3F4;
            asm("" : "+r"(core_messages));
            func_0803E488(core_messages, 4);
            prompt = D_0875B068;
            asm("" : "+r"(prompt));
            func_0803E488(prompt, 17);
            if (D_02007574[0] == 1)
            {
                if (D_02007574[1] == 0)
                {
                    {
                        register const u8 *definition asm("r3") = frame.core_definition;
                        register u32 replaces_unit asm("r0");
                        asm("" : : "r"(definition));
                        ((volatile u32)replaces_unit) = definition[12];
                        if ((volatile u32)replaces_unit != 0)
                        {
                            register u32 core_part_index asm("r6") = 0;
                            register u32 selected_shift asm("r4") = frame.selected;
                            register u8 *parts asm("r3");
                            asm("" : : "r"(core_part_index));
                            asm("" : "+r"(selected_shift));
                            selected_shift <<= 16;
                            (*(u32 *)(formation_stack + 136)) = selected_shift;
                            asm("" : : "r"(selected_shift));
                            {
                                register const u8 *part_base asm("r2") = D_02001898;
                                register const u8 *roster asm("r1");
                                register u32 address asm("r0");
                                register u32 entry asm("r1");
                                asm("" : : "r"(part_base));
                                ((const u8 *volatile)roster) = D_0200E7F4;
                                asm("" : : "r"(roster));
                                ((volatile u32)address) = (s32)selected_shift >> 16;
                                ((volatile u32)address) += (u32)(const u8 *volatile)roster;
                                ((volatile u32)entry) = *(const u8 *)(volatile u32)address;
                                ((volatile u32)address) = (volatile u32)entry * 56;
                                ((u8 *volatile)parts) =
                                    (u8 *)((volatile u32)address + (u32)part_base);
                                asm("" : : "r"(parts));
                            }
                            {
                                register s32 signed_index asm("r2");
                                register u32 offset asm("r0");
                                register u16 *part asm("r5");
                                register u32 empty asm("r7");
                                register u32 flags asm("r1");
                            core_build_part_scan553:
                                ((volatile u32)offset) = (volatile u32)core_part_index << 16;
                                ((volatile s32)signed_index) = (s32)(volatile u32)offset >> 16;
                                asm("" : : "r"(signed_index));
                                ((volatile u32)offset) = (volatile s32)signed_index << 2;
                                ((u16 *volatile)part) =
                                    (u16 *)((u8 *volatile)parts + (volatile u32)offset);
                                asm("" : : "r"(part));
                                ((volatile u32)offset) = part[1];
                                asm("" : : "r"(offset));
                                ((volatile u32)empty) = 0xFFFF;
                                asm("" : : "r"(empty));
                                if ((volatile u32)offset == (volatile u32)empty)
                                    goto core_build_part_next553;
                                ((volatile u32)flags) = part[0];
                                ((volatile u32)offset) = 3;
                                ((volatile u32)offset) &= (volatile u32)flags;
                                if ((volatile u32)offset != 0)
                                    goto core_build_part_scan_done553;
                            core_build_part_next553:
                                ((volatile u32)offset) = (volatile s32)signed_index + 1;
                                core_part_index = (u16)(volatile u32)offset;
                                if ((s16)core_part_index <= 2)
                                    goto core_build_part_scan553;
                            core_build_part_scan_done553:;
                            }
                            if (core_part_index != 3)
                            {
                                {
                                    register const u8 *messages asm("r6") = D_0875AFB8;
                                    register const u8 *part_messages asm("r4");
                                    register const u8 *prompt asm("r7");
                                    asm("" : "+r"(messages));
                                    func_0803E488(messages, 0);
                                    part_messages = D_0875B3F4;
                                    asm("" : "+r"(part_messages));
                                    func_0803E488(part_messages, 7);
                                    prompt = D_0875B068;
                                    asm("" : "+r"(prompt));
                                    func_0803E488(prompt, 17);
                                    if (D_02007574[0] == 1 && D_02007574[1] == 0)
                                    {
                                        core_part_index = 0;
                                        {
                                            register const u8 *roster asm("r9");
                                            register u8 *stock_counts asm("r8");
                                            register const u8 *part_messages asm("r4");
                                            {
                                                register const u8 *loaded asm("r0") = D_0200E7F4;
                                                register u8 *base asm("r2");
                                                register u32 address asm("r1");
                                                asm("" : : "r"(loaded));
                                                roster = loaded;
                                                asm("" : : "r"(roster));
                                                ((u8 *volatile)base) = D_02001898;
                                                asm("" : : "r"(base));
                                                menu_pointer.save = base;
                                                asm("" : "+l"(menu_pointer.save));
                                                ((volatile u32)address) = 0x2610;
                                                asm("" : "+r"(address));
                                                ((volatile u32)address) += (u32)menu_pointer.save;
                                                stock_counts = (u8 *)(volatile u32)address;
                                                asm("" : : "r"(stock_counts));
                                                ((const u8 *volatile)part_messages) = D_0875B1F0;
                                                asm("" : : "r"(part_messages));
                                            }
                                        core_build_part_capacity553:
                                        {
                                            register u32 selected asm("r2") =
                                                (*(u32 *)(formation_stack + 136));
                                            register u32 address asm("r0");
                                            register u32 record asm("r1");
                                            register u16 *part asm("r5");
                                            register u32 empty asm("r3");
                                            asm("" : : "r"(selected));
                                            ((volatile u32)address) = (s32)selected >> 16;
                                            ((volatile u32)address) += (u32)roster;
                                            ((volatile u32)address) = *(u8 *)(volatile u32)address;
                                            ((volatile u32)record) = (volatile u32)address * 56;
                                            ((volatile u32)record) += (u32)menu_pointer.save;
                                            ((volatile u32)address) = (volatile u32)core_part_index
                                                                      << 16;
                                            ((volatile u32)address) =
                                                (s32)(volatile u32)address >> 14;
                                            ((u16 *volatile)part) = (u16 *)((volatile u32)record +
                                                                            (volatile u32)address);
                                            asm("" : : "r"(part));
                                            ((volatile u32)address) = ((volatile u16 *)part)[1];
                                            asm("" : : "r"(address));
                                            ((volatile u32)empty) = 0xFFFF;
                                            asm("" : : "r"(empty));
                                            if ((volatile u32)address != (volatile u32)empty)
                                            {
                                                ((volatile u32)record) = part[0];
                                                ((volatile u32)address) = 3;
                                                ((volatile u32)address) &= (volatile u32)record;
                                                if ((volatile u32)address != 0)
                                                {
                                                    ((volatile u32)address) =
                                                        ((volatile u16 *)part)[1];
                                                    ((volatile u32)address) += (u32)stock_counts;
                                                    ((volatile u32)address) =
                                                        *(u8 *)(volatile u32)address;
                                                    if ((volatile u32)address > 8)
                                                    {
                                                        {
                                                            register const u8 *script asm("r0");
                                                            ((const u8 *volatile)script) =
                                                                D_0875AFB8;
                                                            func_0803E488(
                                                                (const u8 *volatile)script, 0);
                                                        }
                                                        {
                                                            register const u8 *script asm("r0");
                                                            ((const u8 *volatile)script) =
                                                                D_0875AFB8;
                                                            func_0803E488(
                                                                (const u8 *volatile)script, 25);
                                                        }
                                                        func_0803E488(part_messages, 7);
                                                        func_0803E488(D_0866634C, part[1]);
                                                        func_0803E488(part_messages, 8);
                                                        {
                                                            register const u8 *script asm("r0");
                                                            ((const u8 *volatile)script) =
                                                                D_0875B068;
                                                            func_0803E488(
                                                                (const u8 *volatile)script, 17);
                                                        }
                                                        {
                                                            register u16 *response asm("r0");
                                                            u32 first;
                                                            register u32 second asm("r0");
                                                            ((u16 *volatile)response) = D_02007574;
                                                            ((volatile u32)first) = response[0];
                                                            asm("" : "+r"(first));
                                                            if ((volatile u32)first != 1)
                                                                goto core_build_part_capacity_cancel553;
                                                            ((volatile u32)second) = response[1];
                                                            asm("" : "+r"(first));
                                                            if ((volatile u32)second == 0)
                                                                goto core_build_part_check_next553;
                                                        core_build_part_capacity_cancel553:
                                                            if ((volatile u32)first == 0)
                                                                func_080019EC(63);
                                                            goto core_build_part_checks_done553;
                                                        }
                                                    }
                                                }
                                            }
                                        core_build_part_check_next553:
                                            asm("" : "+r"(core_part_index));
                                            {
                                                register u32 shifted asm("r0");
                                                register u32 increment asm("r5");
                                                ((volatile u32)shifted) =
                                                    (volatile u32)core_part_index << 16;
                                                ((volatile u32)increment) = 0x10000;
                                                asm("" : : "r"(increment));
                                                ((volatile u32)shifted) += (volatile u32)increment;
                                                core_part_index = (volatile u32)shifted >> 16;
                                                if ((s32)(volatile u32)shifted >> 16 <= 2)
                                                    goto core_build_part_capacity553;
                                            }
                                        }
                                        }
                                    core_build_part_checks_done553:;
                                        if (core_part_index == 3)
                                        {
                                            core_part_index = 0;
                                            {
                                                register const u8 *selected_entry asm("r4");
                                                register u8 *stock_counts asm("r8");
                                                register u32 empty asm("r3");
                                                {
                                                    register u8 *base asm("r2") = D_02001898;
                                                    register const u8 *roster asm("r1");
                                                    register u32 address asm("r0");
                                                    asm("" : : "r"(base));
                                                    ((const u8 *volatile)roster) = D_0200E7F4;
                                                    {
                                                        register u32 selected asm("r7") =
                                                            (*(u32 *)(formation_stack + 136));
                                                        asm("" : "+r"(selected));
                                                        ((volatile u32)address) =
                                                            (s32)selected >> 16;
                                                    }
                                                    ((const u8 *volatile)selected_entry) =
                                                        (const u8 *)((volatile u32)address +
                                                                     (u32)(const u8 *volatile)
                                                                         roster);
                                                    asm("" : "+r"(selected_entry));
                                                    menu_pointer.save = base;
                                                    asm("" : "+l"(menu_pointer.save));
                                                    ((volatile u32)empty) = 65535;
                                                    asm("" : "+r"(empty));
                                                    ((volatile u32)address) = 0x2610;
                                                    asm("" : "+r"(address));
                                                    ((volatile u32)address) +=
                                                        (u32)menu_pointer.save;
                                                    asm("" : "+r"(address));
                                                    ((u8 *volatile)stock_counts) =
                                                        (u8 *)(volatile u32)address;
                                                }
                                            core_build_part_return553:
                                            {
                                                register u32 address asm("r0");
                                                register u32 entry asm("r1");
                                                register u32 shifted asm("r2");
                                                register s32 offset asm("r1");
                                                register u16 *part asm("r5");
                                                ((volatile u32)entry) =
                                                    *(const u8 *volatile)selected_entry;
                                                ((volatile u32)address) = (volatile u32)entry * 56;
                                                ((volatile u32)address) += (u32)menu_pointer.save;
                                                ((volatile u32)shifted) =
                                                    (volatile u32)core_part_index << 16;
                                                ((volatile s32)offset) =
                                                    (s32)(volatile u32)shifted >> 14;
                                                ((u16 *volatile)part) =
                                                    (u16 *)((volatile u32)address +
                                                            (volatile s32)offset);
                                                ((volatile u32)address) = ((volatile u16 *)part)[1];
                                                if ((volatile u32)address != (volatile u32)empty)
                                                {
                                                    ((volatile u32)entry) = part[0];
                                                    ((volatile u32)address) = 3;
                                                    ((volatile u32)address) &= (volatile u32)entry;
                                                    if ((volatile u32)address != 0)
                                                    {
                                                        register u8 *inventory asm("r6");
                                                        ((volatile u32)address) =
                                                            ((volatile u16 *)part)[1];
                                                        asm("" : "+r"(address));
                                                        ((u8 *volatile)inventory) =
                                                            (u8 *volatile)stock_counts;
                                                        asm("" : "+r"(inventory) : "r"(address));
                                                        ((volatile u32)entry) =
                                                            (volatile u32)address +
                                                            (u32)(u8 *volatile)inventory;
                                                        ((volatile u32)address) =
                                                            *(u8 *)(volatile u32)entry;
                                                        if ((volatile u32)address <= 8)
                                                        {
                                                            ((volatile u32)address)++;
                                                            *(u8 *)(volatile u32)entry =
                                                                (volatile u32)address;
                                                        }
                                                        ((volatile u32)entry) =
                                                            ((volatile u16 *)part)[1];
                                                        asm("" : "+r"(entry));
                                                        ((volatile u32)address) =
                                                            (volatile u32)empty;
                                                        asm("" : "+r"(address) : "r"(entry));
                                                        ((volatile u32)address) |=
                                                            (volatile u32)entry;
                                                        ((volatile u16 *)part)[1] =
                                                            (volatile u32)address;
                                                    }
                                                }
                                                ((volatile u32)entry) = 0x10000;
                                                asm("" : "+r"(entry));
                                                ((volatile u32)address) =
                                                    (volatile u32)shifted + (volatile u32)entry;
                                                core_part_index = (volatile u32)address >> 16;
                                                if ((s32)(volatile u32)address >> 16 <= 2)
                                                    goto core_build_part_return553;
                                            }
                                            }
                                        }
                                        else
                                        {
                                            func_0803E488(D_0875B3F4, 8);
                                            {
                                                register const u8 *definition asm("r2") =
                                                    frame.core_definition;
                                                register u32 replaces asm("r0");
                                                asm("" : "+r"(definition));
                                                ((volatile u32)replaces) = definition[12];
                                                asm("" : "+r"(replaces));
                                                ((volatile u32)state) = 0x201;
                                                if ((volatile u32)replaces != 0)
                                                    ((volatile u32)state) += 0x10;
                                            }
                                            {
                                                register u16 *flags asm("r2");
                                                register u32 value asm("r0");
                                                register u32 mask asm("r3");
                                                register u32 bits asm("r1");
                                                ((u16 *volatile)flags) = (u16 *)D_03004BBC;
                                                asm("" : "+r"(flags));
                                                ((u16 *volatile)flags) =
                                                    (u16 *)((u8 *)(u16 *volatile)flags + 0x88);
                                                asm("" : "+r"(flags));
                                                ((volatile u32)value) = *(u16 *volatile)flags;
                                                ((volatile u32)mask) = 0x7FFF;
                                                asm("" : "+r"(mask) : "r"(value));
                                                ((volatile u32)bits) = (volatile u32)mask;
                                                asm("" : "+r"(bits));
                                                ((volatile u32)value) &= (volatile u32)bits;
                                                *(u16 *volatile)flags = (volatile u32)value;
                                            }
                                            func_0803E488(D_0875AFB8, 9);
                                            {
                                                register const u8 *script asm("r0");
                                                ((const u8 *volatile)script) = D_0875B068;
                                                func_0803E488((const u8 *volatile)script, 0);
                                            }
                                            func_0803E488(D_0875AFB8, 42);
                                            {
                                                register u32 *cash asm("r4") = &D_02001884;
                                                asm("" : "+r"(cash));
                                                func_08001848(*cash, 7, 0);
                                            }
                                            {
                                                register const u8 *script asm("r0");
                                                ((const u8 *volatile)script) = D_0875B068;
                                                func_0803E488((const u8 *volatile)script, 1);
                                            }
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if (D_02007574[0] != 1)
                                            func_080019EC(63);
                                        func_0803E488(part_messages, 8);
                                        {
                                            register const u8 *definition asm("r5") =
                                                frame.core_definition;
                                            register u32 replaces asm("r0");
                                            asm("" : "+r"(definition));
                                            ((volatile u32)replaces) = definition[12];
                                            asm("" : "+r"(replaces));
                                            ((volatile u32)state) = 0x201;
                                            if ((volatile u32)replaces != 0)
                                                ((volatile u32)state) += 0x10;
                                        }
                                        {
                                            register u16 *flags asm("r2");
                                            register u32 value asm("r0");
                                            register u32 mask asm("r3");
                                            register u32 bits asm("r1");
                                            ((u16 *volatile)flags) = (u16 *)D_03004BBC;
                                            asm("" : "+r"(flags));
                                            ((u16 *volatile)flags) =
                                                (u16 *)((u8 *)(u16 *volatile)flags + 0x88);
                                            asm("" : "+r"(flags));
                                            ((volatile u32)value) = *(u16 *volatile)flags;
                                            ((volatile u32)mask) = 0x7FFF;
                                            asm("" : "+r"(mask) : "r"(value));
                                            ((volatile u32)bits) = (volatile u32)mask;
                                            asm("" : "+r"(bits));
                                            ((volatile u32)value) &= (volatile u32)bits;
                                            *(u16 *volatile)flags = (volatile u32)value;
                                        }
                                        func_0803E488(messages, 9);
                                        func_0803E488(prompt, 0);
                                        func_0803E488(messages, 42);
                                        {
                                            register u32 *cash asm("r4") = &D_02001884;
                                            asm("" : "+r"(cash));
                                            func_08001848(*cash, 7, 0);
                                        }
                                        func_0803E488(prompt, 1);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    {
                        register u8 *save asm("r4") = D_02000B5C;
                        register u32 *cash asm("r5");
                        register const u8 *definition asm("r6");
                        register u32 value asm("r0");
                        register u32 cost asm("r1");
                        asm("" : "+r"(save));
                        ((u32 *volatile)cash) = &D_02001884;
                        asm("" : "+r"(cash));
                        ((volatile u32)value) = *(u32 *volatile)cash;
                        asm("" : "+r"(value));
                        ((const u8 *volatile)definition) = frame.core_definition;
                        asm("" : "+r"(definition));
                        ((volatile u32)cost) = *(u32 *)((const u8 *volatile)definition + 4);
                        ((volatile u32)value) -= (volatile u32)cost;
                        *(u32 *volatile)cash = (volatile u32)value;
                        ((volatile u32)value) = ((const u8 *volatile)definition)[12];
                        if ((volatile u32)value != 0)
                        {
                            {
                                menu_pointer.selector = frame.linked_slot;
                                asm("" : "+l"(menu_pointer.selector));
                                if ((s16)menu_pointer.selector != 87)
                                    func_08036B98((u8)menu_pointer.selector);
                            }
                            {
                                register const u8 *roster asm("r1") = D_0200E7F4;
                                register u32 selected asm("r2");
                                register u32 address asm("r0");
                                register u32 entry asm("r1");
                                register u32 offset asm("r3");
                                asm("" : "+r"(roster));
                                ((volatile u32)selected) = frame.selected;
                                asm("" : "+r"(selected));
                                ((volatile u32)address) = (s32)((volatile u32)selected << 16) >> 16;
                                ((volatile u32)address) += (u32)(const u8 *volatile)roster;
                                ((volatile u32)entry) = *(u8 *)(volatile u32)address;
                                ((volatile u32)address) = (volatile u32)entry * 56;
                                ((volatile u32)address) += (u32)save;
                                ((volatile u32)offset) = 0xD32;
                                asm("" : "+r"(offset));
                                ((volatile u32)address) += (volatile u32)offset;
                                ((volatile u32)entry) = 0;
                                *(u16 *)(volatile u32)address = (volatile u32)entry;
                            }
                        }
                    }
                    {
                        register const u8 *definition asm("r4") = frame.core_definition;
                        register u32 kind asm("r0");
                        asm("" : "+r"(definition));
                        ((volatile u32)kind) = definition[13];
                        asm("" : "+r"(kind));
                        if ((volatile u32)kind != 255)
                        {
                            register u32 address asm("r1");
                            register u8 *stock asm("r5");
                            ((volatile u32)address) = (volatile u32)kind;
                            asm("" : "+r"(address));
                            ((u8 *volatile)stock) = D_02003E68;
                            asm("" : "+r"(stock));
                            ((volatile u32)address) += (u32)(u8 *volatile)stock;
                            ((volatile u32)kind) = *(u8 *)(volatile u32)address;
                            ((volatile u32)kind)--;
                            *(u8 *)(volatile u32)address = (volatile u32)kind;
                        }
                    }
                    {
                        register const u8 *definition asm("r6") = frame.core_definition;
                        register u32 kind asm("r0");
                        asm("" : "+r"(definition));
                        ((volatile u32)kind) = definition[14];
                        asm("" : "+r"(kind));
                        if ((volatile u32)kind != 255)
                        {
                            register u32 address asm("r1");
                            register u8 *stock asm("r7");
                            ((volatile u32)address) = (volatile u32)kind;
                            asm("" : "+r"(address));
                            ((u8 *volatile)stock) = D_02003E68;
                            asm("" : "+r"(stock));
                            ((volatile u32)address) += (u32)(u8 *volatile)stock;
                            ((volatile u32)kind) = *(u8 *)(volatile u32)address;
                            ((volatile u32)kind)--;
                            *(u8 *)(volatile u32)address = (volatile u32)kind;
                        }
                    }
                    {
                        u8 new_entry;
                        {
                            register const u8 *roster asm("r1") = D_0200E6DF;
                            register u32 selected asm("r2");
                            register u32 address asm("r0");
                            asm("" : "+r"(roster));
                            ((volatile u32)selected) = frame.selected_core;
                            asm("" : "+r"(selected));
                            ((volatile u32)address) = (s32)((volatile u32)selected << 16) >> 16;
                            ((volatile u32)address) += (u32)(const u8 *volatile)roster;
                            new_entry = func_0803699C(*(u8 *)(volatile u32)address, 0);
                        }
                        func_08036C1C(255, new_entry, D_020018B0 + new_entry * 56);
                    }
                    func_0803E488(D_0875B3F4, 5);
                }
                else
                    func_0803E488(core_messages, 6);
                func_080019EC(65);
                state = 0x201;
                {
                    register u16 *flags asm("r2");
                    register u32 value asm("r0");
                    register u32 mask asm("r3");
                    register u32 bits asm("r1");
                    ((u16 *volatile)flags) = (u16 *)D_03004BBC;
                    asm("" : "+r"(flags));
                    ((u16 *volatile)flags) = (u16 *)((u8 *)(u16 *volatile)flags + 0x88);
                    asm("" : "+r"(flags));
                    ((volatile u32)value) = *(u16 *volatile)flags;
                    ((volatile u32)mask) = 0x7FFF;
                    asm("" : "+r"(mask) : "r"(value));
                    ((volatile u32)bits) = (volatile u32)mask;
                    asm("" : "+r"(bits));
                    ((volatile u32)value) &= (volatile u32)bits;
                    *(u16 *volatile)flags = (volatile u32)value;
                }
                {
                    register const u8 *footer_messages asm("r4") = D_0875AFB8;
                    register const u8 *count asm("r6");
                    register u32 value asm("r0");
                    asm("" : "+r"(footer_messages));
                    func_0803E488(footer_messages, 9);
                    ((const u8 *volatile)count) = &D_02003E60;
                    asm("" : "+r"(count));
                    ((volatile u32)value) = *(const u8 *volatile)count;
                    if ((volatile u32)value > 172)
                    {
                        func_0803E488(footer_messages, 0);
                        func_0803E488(D_0875B3B8, 4);
                        state = 0x10;
                    }
                    else
                    {
                        {
                            register const u8 *script asm("r0");
                            ((const u8 *volatile)script) = D_0875B068;
                            func_0803E488((const u8 *volatile)script, 0);
                        }
                        func_0803E488(footer_messages, 42);
                        menu_pointer.save = (u8 *)&D_02001884;
                        asm("" : "+l"(menu_pointer.save));
                        func_08001848(*(u32 *)menu_pointer.save, 7, 0);
                        {
                            register const u8 *script asm("r0");
                            ((const u8 *volatile)script) = D_0875B068;
                            func_0803E488((const u8 *volatile)script, 1);
                        }
                    }
                }
            }
            else
            {
                func_080019EC(63);
                {
                    register const u8 *definition asm("r1") = frame.core_definition;
                    register u32 replaces asm("r0");
                    asm("" : "+r"(definition));
                    ((volatile u32)replaces) = definition[12];
                    asm("" : "+r"(replaces));
                    ((volatile u32)state) = 0x201;
                    if ((volatile u32)replaces != 0)
                        ((volatile u32)state) += 0x10;
                }
                {
                    register u16 *flags asm("r2");
                    register u32 value asm("r0");
                    register u32 mask asm("r3");
                    register u32 bits asm("r1");
                    ((u16 *volatile)flags) = (u16 *)D_03004BBC;
                    asm("" : "+r"(flags));
                    ((u16 *volatile)flags) = (u16 *)((u8 *)(u16 *volatile)flags + 0x88);
                    asm("" : "+r"(flags));
                    ((volatile u32)value) = *(u16 *volatile)flags;
                    ((volatile u32)mask) = 0x7FFF;
                    asm("" : "+r"(mask) : "r"(value));
                    ((volatile u32)bits) = (volatile u32)mask;
                    asm("" : "+r"(bits));
                    ((volatile u32)value) &= (volatile u32)bits;
                    *(u16 *volatile)flags = (volatile u32)value;
                }
                func_0803E488(messages, 9);
                func_0803E488(prompt, 0);
                func_0803E488(messages, 42);
                {
                    register u32 *cash asm("r4") = &D_02001884;
                    asm("" : "+r"(cash));
                    func_08001848(*cash, 7, 0);
                }
                func_0803E488(prompt, 1);
            }
            func_0803E488(D_0875AFB8, 0);
            break;
        }
        case 0x300:
            func_0803E488(D_0875AFB8, 11);
            func_0803E488(D_0875AFB8, 10);
            func_0803E488(D_0875AFB8, 9);
            func_0803E488(D_0875AFB8, 0);
            func_0803E488(D_0875B0D0, 0);
            {
                register u32 zero asm("r5") = 0;
                register u16 *cursor asm("r6");
                asm("" : "+r"(zero));
                frame.page = zero;
                cursor = &D_02007588;
                asm("" : "+r"(cursor));
                *cursor = zero;
            }
            state = 0x302;
            break;
        case 0x301:
            func_0803E488(D_0875B0D0, 0);
            {
                register u16 *details asm("r0") = frame.detail;
                register u32 value asm("r0");
                register u8 *remembered_byte asm("r1");
                register u16 *cursor asm("r2");
                asm("" : "+r"(details));
                value = details[1];
                asm("" : "+r"(value));
                frame.page = value;
                menu_pointer.cursor = remembered_base;
                asm("" : "+r"(menu_pointer.cursor));
                value = menu_pointer.cursor[1];
                asm("" : "+r"(value));
                remembered_byte = &D_02007FA9;
                asm("" : "+r"(remembered_byte) : "r"(value));
                *remembered_byte = value;
                value = (u8)value;
                asm("" : "+r"(value));
                cursor = &D_02007588;
                asm("" : "+r"(cursor) : "r"(value));
                *cursor = value;
            }
        case 0x302:
        {
            register u32 previous_pilot asm("r9");
            register const u8 *pilot_messages asm("r10");
            register u32 cached_previous asm("r8");
            {
                register u32 previous asm("r3") = 0xFFFF;
                register const u8 *messages asm("r4");
                asm("" : "+r"(previous));
                frame.previous_page = previous;
                previous_pilot = previous;
                asm("" : "+r"(previous_pilot));
                messages = D_0875AFB8;
                asm("" : "+r"(messages));
                pilot_messages = messages;
                asm("" : "+r"(pilot_messages));
            }
        pilot_list_open:
        {
            register u32 active asm("r5") = 1;
            asm("" : "+r"(active));
            frame.active = active;
        }
        pilot_list_update:
        {
            register u32 page_shift asm("r5");
            register s32 page asm("r4");
            register s32 previous_page asm("r0");
            {
                register u32 loaded asm("r6") = frame.page;
                register u32 shifted asm("r1");
                register u32 previous asm("r7");
                register u32 previous_shift asm("r0");
                asm("" : "+r"(loaded));
                shifted = loaded << 16;
                asm("" : "+r"(shifted));
                page = (s32)shifted >> 16;
                asm("" : "+r"(page));
                previous = frame.previous_page;
                asm("" : "+r"(previous));
                previous_shift = previous << 16;
                asm("" : "+r"(previous_shift));
                previous_page = (s32)previous_shift >> 16;
                asm("" : "+r"(previous_page));
                page_shift = shifted;
                asm("" : "+r"(page_shift));
                shifted = previous_pilot;
                asm("" : "+r"(shifted));
                shifted <<= 16;
                asm("" : "+r"(shifted));
                cached_previous = shifted;
                asm("" : "+r"(cached_previous));
            }
            if (page != previous_page)
            {
                register u32 shown asm("r6");
                register u32 base asm("r2");
                register s32 first_row asm("r0");
                register u32 limit asm("r7");
                register u8 *footer_count asm("r4");
                {
                    register s32 none asm("r2");
                    ((volatile s32)none) = -1;
                    if (previous_page != (volatile s32)none)
                        func_0803E488(D_0875AFB8, 3);
                }
                ((volatile u32)shown) = 0;
                {
                    register u32 product asm("r0");
                    register u32 stored asm("r3");
                    register u8 *address asm("r1");
                    ((volatile u32)product) = page * 3;
                    ((volatile u32)base) = (volatile u32)product << 1;
                    ((volatile u32)product) = (volatile u32)product << 17;
                    ((volatile u32)stored) = (volatile u32)product >> 16;
                    frame.row = (volatile u32)stored;
                    ((volatile s32)first_row) = (s32)(volatile u32)product >> 16;
                    address = &D_0200E647;
                    asm("" : "+r"(address));
                    footer_count = address;
                    asm("" : "+r"(footer_count));
                    ((volatile u32)limit) = *(u8 *volatile)footer_count;
                }
                if (first_row < (s32)limit)
                {
                    u8 *count = footer_count;
                    asm("" : "+r"(count) : "r"(base));
                    menu_pointer.selector = base;
                    asm("" : "+l"(menu_pointer.selector) : "r"(count));
                pilot_list_row:
                {
                    register s32 row_index asm("r4");
                    {
                        register u8 *roster asm("r1") = D_0200E5F0;
                        register u32 loaded asm("r2");
                        register u32 shifted asm("r0");
                        loaded = frame.row;
                        shifted = loaded << 16;
                        row_index = (s32)shifted >> 16;
                        asm("" : "+r"(roster), "+r"(loaded), "+r"(shifted), "+r"(row_index));
                        roster = (u8 *)((u32)row_index + (u32)roster);
                        asm("" : "+r"(roster) : "r"(count));
                        func_08032818(*roster);
                    }
                    {
                        register s32 shown_signed asm("r0") = (s16)shown;
                        asm("" : "+r"(shown_signed) : "r"(count));
                        if (shown_signed <= 4 && row_index < (s32)*count - 1)
                        {
                            func_0803E488(D_08675C5C, 0);
                            asm("" : : "r"(count));
                        }
                    }
                    {
                        register u32 shifted asm("r0") = shown << 16;
                        register u32 increment asm("r4") = 0x10000;
                        register s32 next asm("r0");
                        asm("" : "+r"(shifted), "+r"(increment));
                        shifted += increment;
                        shown = shifted >> 16;
                        next = (s32)shifted >> 16;
                        footer_count = &D_0200E647;
                        asm("" : "+r"(footer_count));
                        if (next > 5)
                            goto pilot_list_rows_done;
                        next += menu_pointer.selector;
                        next <<= 16;
                        {
                            register u32 stored asm("r1") = (u32)next >> 16;
                            register u32 last asm("r2");
                            frame.row = stored;
                            next >>= 16;
                            last = *count;
                            asm("" : "+r"(last));
                            if (next < (s32)last)
                                goto pilot_list_row;
                        }
                    }
                }
                pilot_list_rows_done:;
                }
                {
                    register s32 shown_signed asm("r0") = (s16)shown;
                    register u16 *cursor asm("r2");
                    register u32 current asm("r3");
                    cursor = &D_02007588;
                    menu_pointer.save = D_020075A0;
                    current = *cursor;
                    asm(""
                        : "+r"(shown_signed), "+r"(cursor), "+l"(menu_pointer.save), "+r"(current));
                    if (shown_signed <= (s32)current)
                    {
                        register u32 value asm("r0") = shown - 1;
                        register u8 *byte_cursor asm("r6");
                        asm("" : "+r"(value));
                        byte_cursor = &D_02007FA9;
                        asm("" : "+r"(byte_cursor));
                        *byte_cursor = value;
                        value <<= 24;
                        asm("" : "+r"(value));
                        value >>= 24;
                        asm("" : "+r"(value));
                        *cursor = value;
                    }
                    {
                        register u32 offset asm("r0") = 0xA0B;
                        register u8 *flags asm("r2");
                        register u32 zero asm("r3");
                        register u32 value asm("r0");
                        register u32 row asm("r6");
                        register s32 row_signed asm("r1");
                        asm("" : "+r"(offset));
                        flags = menu_pointer.save + offset;
                        asm("" : "+r"(flags));
                        zero = 0;
                        value = 0;
                        asm volatile("" : "+r"(zero), "+r"(value));
                        *flags = value;
                        if ((s32)page_shift > 0)
                        {
                            value = 1;
                            asm("" : "+r"(value));
                            *flags = value;
                        }
                        row = frame.row;
                        row_signed = (s32)(row << 16) >> 16;
                        value = *footer_count;
                        asm("" : "+r"(row), "+r"(row_signed), "+r"(value));
                        value--;
                        asm("" : "+r"(value));
                        if (row_signed < (s32)value)
                        {
                            register u32 bits asm("r1") = *flags;
                            asm("" : "+r"(bits));
                            value = 2;
                            asm("" : "+r"(value));
                            bits |= value;
                            *flags = bits;
                        }
                    }
                }
                asm("" : "+r"(page_shift));
                menu_pointer.selector = page_shift >> 16;
                asm("" : "+l"(menu_pointer.selector));
                frame.previous_page = menu_pointer.selector;
            }
            {
                register s32 selected_page asm("r1") = (s32)page_shift >> 16;
                register u32 selected asm("r0");
                register u32 selected_shift asm("r2");
                register u32 old_shift asm("r3");
                register s32 old_index asm("r0");
                u8 assigned;
                register u16 *cursor asm("r1");
                asm("" : "+r"(selected_page));
                selected = selected_page * 6;
                asm("" : "+r"(selected));
                cursor = &D_02007588;
                asm("" : "+r"(cursor) : "r"(selected));
                selected += *cursor;
                asm("" : "+r"(selected));
                selected = (u16)selected;
                asm("" : "+r"(selected));
                frame.field_30 = selected;
                selected_shift = selected << 16;
                old_shift = cached_previous;
                asm("" : "+r"(selected_shift), "+r"(old_shift));
                old_index = (s32)old_shift >> 16;
                asm("" : "+r"(old_index));
                if (selected_shift == cached_previous)
                {
                    register u32 active asm("r4");
                    (*(u32 *)(formation_stack + 132)) = selected_shift;
                    active = frame.active;
                    asm("" : "+r"(active));
                    if (!active)
                        goto pilot_assigned_done;
                }
                {
                    register s32 none asm("r5") = -1;
                    asm("" : "+r"(none));
                    if (old_index != none)
                        goto pilot_clear_assigned;
                    {
                        register u32 active asm("r6") = frame.active;
                        asm("" : "+r"(active));
                        if (active)
                            goto pilot_clear_assigned;
                    }
                    goto pilot_show_assigned;
                }
            pilot_clear_assigned:
                func_0803E488(D_0875AFB8, 0);
            pilot_show_assigned:
                func_0803E488(D_0875AFB8, 25);
                func_0803E488(D_0875B434, 0);
                {
                    register u8 *save asm("r3") = D_02000B5C;
                    register u8 *roster asm("r1");
                    register u32 value asm("r0");
                    register u32 offset asm("r5");
                    register u8 *assigned_entry asm("r1");
                    asm("" : "+r"(save));
                    roster = D_0200E5F0;
                    asm("" : "+r"(roster));
                    menu_pointer.selector = frame.field_30;
                    asm("" : "+l"(menu_pointer.selector));
                    selected_shift = menu_pointer.selector << 16;
                    asm("" : "+r"(selected_shift));
                    value = (s32)selected_shift >> 16;
                    asm("" : "+r"(value));
                    value += (u32)roster;
                    asm("" : "+r"(value));
                    value = *(u8 *)value;
                    asm("" : "+r"(value));
                    value <<= 2;
                    asm("" : "+r"(value));
                    value += (u32)save;
                    asm("" : "+r"(value));
                    offset = 0x34A6;
                    asm("" : "+r"(offset));
                    assigned_entry = (u8 *)(value + offset);
                    asm("" : "+r"(assigned_entry));
                    value = *(volatile u8 *)assigned_entry;
                    asm("" : : "r"(value), "r"(selected_shift));
                    (*(u32 *)(formation_stack + 132)) = selected_shift;
                    if (value != 255)
                    {
                        register u32 model_offset asm("r6");
                        value = *(volatile u8 *)assigned_entry;
                        asm("" : "+r"(value));
                        assigned_entry = (u8 *)(value * 56);
                        asm("" : "+r"(assigned_entry));
                        assigned_entry = (u8 *)((u32)assigned_entry + (u32)save);
                        asm("" : "+r"(assigned_entry));
                        model_offset = 0xD32;
                        asm("" : "+r"(model_offset));
                        assigned_entry += model_offset;
                        asm("" : "+r"(assigned_entry));
                        func_08032800(*(u16 *)assigned_entry);
                    }
                    else
                        func_0803E488(D_0875B434, 4);
                }
            }
        }
        pilot_assigned_done:
        {
            register s32 selected_index asm("r5");
            register u32 old_shift asm("r1");
            register s32 old_index asm("r0");
            menu_pointer.selector = (*(u32 *)(formation_stack + 132));
            asm("" : "+l"(menu_pointer.selector));
            selected_index = (s32)menu_pointer.selector >> 16;
            asm("" : "+r"(selected_index));
            old_shift = cached_previous;
            asm("" : "+r"(old_shift));
            old_index = (s32)old_shift >> 16;
            asm("" : "+r"(old_index));
            if (selected_index != old_index)
            {
                register u8 *stats asm("r9");
                register u8 *pilot_roster asm("r4");
                register const u8 *low_stats asm("r6");
                {
                    register s32 none asm("r2");
                    ((volatile s32)none) = -1;
                    if (old_index != (volatile s32)none)
                    {
                        func_0803E488(pilot_messages, 1);
                        func_0803E488(pilot_messages, 2);
                    }
                }
                ((u8 *volatile)pilot_roster) = D_0200E5F0;
                ((u8 *volatile)pilot_roster) =
                    (u8 *)((u32)selected_index + (u32)(u8 *volatile)pilot_roster);
                ((u8 *volatile)stats) = func_080334F8(*(u8 *volatile)pilot_roster);
                func_0803E488(pilot_messages, 26);
                func_08032818(*(u8 *volatile)pilot_roster);
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_08675C5C;
                    func_0803E488((const u8 *volatile)message, 0);
                }
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_0875B0D0;
                    func_0803E488((const u8 *volatile)message, 1);
                }
                {
                    register const u8 *base asm("r3");
                    ((const u8 *volatile)base) = (u8 *volatile)stats;
                    func_08001848(*(s16 *)((const u8 *volatile)base + 4), 3, 4);
                }
                func_0803E488(pilot_messages, 39);
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_08675C5C;
                    func_0803E488((const u8 *volatile)message, 0);
                }
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_0875B0D0;
                    func_0803E488((const u8 *volatile)message, 2);
                }
                ((const u8 *volatile)low_stats) = (u8 *volatile)stats;
                func_08001848(*(s16 *)((const u8 *volatile)low_stats + 10), 3, 4);
                func_0803E488(pilot_messages, 39);
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_08675C5C;
                    func_0803E488((const u8 *volatile)message, 0);
                }
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_0875B0D0;
                    func_0803E488((const u8 *volatile)message, 3);
                }
                func_08001848(*(s16 *)((const u8 *volatile)low_stats + 8), 3, 4);
                func_0803E488(pilot_messages, 39);
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_08675C5C;
                    func_0803E488((const u8 *volatile)message, 0);
                }
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_0875B0D0;
                    func_0803E488((const u8 *volatile)message, 4);
                }
                func_08001848(*(s16 *)((const u8 *volatile)low_stats + 6), 3, 4);
                func_0803E488(pilot_messages, 39);
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_08675C5C;
                    func_0803E488((const u8 *volatile)message, 0);
                }
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_0875B0D0;
                    func_0803E488((const u8 *volatile)message, 5);
                }
                func_08001848(*(s16 *)((const u8 *volatile)low_stats + 12), 3, 4);
                func_0803E488(pilot_messages, 39);
                func_0803E488(D_0875B4F0, *(u8 *volatile)pilot_roster);
                {
                    register u32 loaded asm("r4") = (*(u32 *)(formation_stack + 132));
                    register union
                    {
                        unsigned long long whole;
                        struct
                        {
                            u32 low, high;
                        } part;
                    } guard asm("r3");
                    guard.part.high = loaded;
                    loaded = guard.part.high;
                    loaded >>= 16;
                    guard.part.high = loaded;
                    loaded = guard.part.high;
                    previous_pilot = loaded;
                }
                {
                    register u32 active asm("r5");
                    ((volatile u32)active) = 1;
                    frame.active = (volatile u32)active;
                }
            }
        }
            {
                register u32 active asm("r6") = frame.active;
                asm("" : "+r"(active));
                if (active)
                {
                    func_0803E488(D_0875AFB8, 24);
                    {
                        register u32 active asm("r7") = 0;
                        asm("" : "+r"(active));
                        frame.active = active;
                    }
                }
            }
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875AFB8;
                func_0803E488((const u8 *volatile)message, 35);
            }
            {
                register u16 *key_pointer asm("r1") = D_02007574;
                register u32 key asm("r0");
                asm("" : "+r"(key_pointer));
                key = *key_pointer;
                asm("" : "+r"(key));
                if (key > 1)
                {
                    register u32 next_page asm("r0");
                    if (key == 2)
                        goto pilot_page_left553;
                    if (key == 4)
                        goto pilot_page_right553;
                    goto pilot_list_update;
                pilot_page_left553:
                {
                    register u32 loaded asm("r1") = frame.page;
                    register s32 page asm("r4");
                    asm("" : "+r"(loaded));
                    ((volatile u32)next_page) = loaded << 16;
                    ((volatile s32)page) = (s32)(volatile u32)next_page >> 16;
                    asm("" : "+r"(page));
                    if ((volatile s32)page <= 0)
                        goto pilot_list_update;
                    func_080019EC(64);
                    ((volatile u32)next_page) = (volatile s32)page - 1;
                    ((volatile u32)next_page) <<= 16;
                    goto pilot_page_store553;
                }
                pilot_page_right553:
                {
                    register u32 loaded asm("r2") = frame.row;
                    register s32 row asm("r1");
                    asm("" : "+r"(loaded));
                    ((volatile s32)row) = (s32)(loaded << 16) >> 16;
                    asm("" : "+r"(row));
                    if ((volatile s32)row >= D_0200E647 - 1)
                        goto pilot_list_update;
                    func_080019EC(64);
                    {
                        register u32 loaded asm("r3") = frame.page;
                        register u32 increment asm("r4");
                        asm("" : "+r"(loaded));
                        ((volatile u32)next_page) = loaded << 16;
                        ((volatile u32)increment) = 0x10000;
                        asm("" : "+r"(increment));
                        ((volatile u32)next_page) += (volatile u32)increment;
                    pilot_page_store553:
                        ((volatile u32)next_page) >>= 16;
                        frame.page = (volatile u32)next_page;
                    }
                }
                    goto pilot_list_update;
                }
            }
            {
                register u16 *input asm("r5") = D_02007574;
                register u16 *response asm("r8");
                asm("" : : "r"(input));
                response = input;
                asm("" : : "r"(response));
                if (input[0] == 1)
                {
                    u8 assigned;
                    register u32 assignment_address asm("r0");
                    register u32 assignment asm("r0");
                    register u8 *pilot asm("r4");
                    register u8 *save asm("r5");
                    register const u8 *prompt_messages asm("r6");
                    {
                        register u32 remembered asm("r0") = input[1];
                        register u16 *slots asm("r6");
                        asm("" : "+r"(remembered));
                        slots = remembered_base;
                        asm("" : "+r"(slots));
                        slots[1] = remembered;
                    }
                    {
                        register u16 *detail asm("r0") = frame.detail;
                        asm("" : "+r"(detail));
                        {
                            register u16 page asm("r7");
                            menu_pointer.cursor = frame.remembered;
                            asm("" : "+l"(menu_pointer.cursor));
                            page = ((volatile u16 *)menu_pointer.cursor)[16];
                            asm("" : "+r"(page));
                            detail[1] = page;
                        }
                    }
                    save = D_02000B5C;
                    asm("" : "+r"(save));
                    {
                        register u8 *roster asm("r1") = D_0200E5F0;
                        register u32 loaded asm("r2");
                        register s32 index asm("r0");
                        asm("" : "+r"(roster));
                        loaded = (*(u32 *)(formation_stack + 132));
                        asm("" : "+r"(loaded));
                        index = (s32)loaded >> 16;
                        asm("" : "+r"(index));
                        pilot = (u8 *)(index + (u32)roster);
                        asm("" : "+r"(pilot));
                    }
                    assignment_address = *pilot;
                    asm("" : "+r"(assignment_address));
                    assignment_address <<= 2;
                    asm("" : "+r"(assignment_address));
                    assignment_address += (u32)save;
                    asm("" : "+r"(assignment_address));
                    menu_pointer.offset = 0x34A6;
                    asm("" : "+l"(menu_pointer.offset));
                    assignment_address += menu_pointer.offset;
                    asm("" : "+r"(assignment_address));
                    assignment = *(u8 *)assignment_address;
                    asm("" : : "r"(assignment));
                    if (assignment != 255)
                    {
                        prompt_messages = D_0875AFB8;
                        asm("" : "+r"(prompt_messages));
                        func_0803E488(prompt_messages, 0);
                        func_0803E488(prompt_messages, 25);
                        {
                            register u32 pilot_kind asm("r2") = *pilot;
                            register u32 address asm("r0");
                            register u32 offset asm("r3");
                            register u32 flags asm("r1");
                            register u32 mask asm("r0");
                            asm("" : "+r"(pilot_kind));
                            address = pilot_kind * 4;
                            asm("" : "+r"(address));
                            address += (u32)save;
                            asm("" : "+r"(address));
                            offset = 0x34A4;
                            asm("" : "+r"(offset));
                            address += offset;
                            asm("" : "+r"(address));
                            flags = *(u16 *)address;
                            asm("" : "+r"(flags));
                            mask = 8;
                            asm("" : "+r"(mask));
                            mask &= flags;
                            asm("" : "+r"(mask));
                            if (mask)
                            {
                                func_080019EC(79);
                                func_08032818(*pilot);
                                {
                                    register const u8 *message asm("r0");
                                    ((const u8 *volatile)message) = D_0875B434;
                                    func_0803E488((const u8 *volatile)message, 1);
                                }
                                {
                                    register u32 address asm("r0");
                                    register u32 entry asm("r1");
                                    register u32 model_offset asm("r4");
                                    ((volatile u32)address) = *pilot;
                                    ((volatile u32)address) = (volatile u32)address << 2;
                                    ((volatile u32)address) = (volatile u32)address + (u32)save;
                                    ((volatile u32)address) =
                                        (volatile u32)address + menu_pointer.offset;
                                    ((volatile u32)entry) = *(u8 *volatile)(volatile u32)address;
                                    ((volatile u32)address) = (volatile u32)entry * 56;
                                    ((volatile u32)address) = (volatile u32)address + (u32)save;
                                    model_offset = 0xD32;
                                    asm("" : "+r"(model_offset));
                                    ((volatile u32)address) = (volatile u32)address + model_offset;
                                    func_08032800(*(u16 *)(volatile u32)address);
                                }
                                {
                                    register const u8 *message asm("r0");
                                    ((const u8 *volatile)message) = D_0875B434;
                                    func_0803E488((const u8 *volatile)message, 3);
                                }
                                func_080019EC(65);
                                {
                                    register u16 *slots asm("r5");
                                    register u32 previous asm("r0");
                                    register u16 *cursor asm("r6");
                                    ((u16 *volatile)slots) = remembered_base;
                                    ((volatile u32)previous) = ((u16 *volatile)slots)[1];
                                    ((u16 *volatile)cursor) = &D_02007588;
                                    *((u16 *volatile)cursor) = (volatile u32)previous;
                                }
                                goto pilot_list_open;
                            }
                            func_08032818(pilot_kind);
                            func_0803E488(D_0875B434, 1);
                            {
                                register u32 address asm("r0");
                                register u32 entry asm("r1");
                                ((volatile u32)address) = *pilot;
                                ((volatile u32)address) = (volatile u32)address << 2;
                                ((volatile u32)address) = (volatile u32)address + (u32)save;
                                ((volatile u32)address) =
                                    (volatile u32)address + menu_pointer.offset;
                                ((volatile u32)entry) = *(u8 *volatile)(volatile u32)address;
                                ((volatile u32)address) = (volatile u32)entry * 56;
                                ((volatile u32)address) = (volatile u32)address + (u32)save;
                                menu_pointer.offset = 0xD32;
                                asm("" : "+l"(menu_pointer.offset));
                                ((volatile u32)address) =
                                    (volatile u32)address + menu_pointer.offset;
                                func_08032800(*(u16 *)(volatile u32)address);
                            }
                            func_0803E488(D_0875B434, 2);
                            func_0803E488(D_0875B068, 17);
                            func_0803E488(prompt_messages, 0);
                            {
                                register u16 *answer asm("r1") = response;
                                asm("" : "+r"(answer));
                                if (answer[0] != 1 || answer[1] != 0)
                                    goto pilot_prompt_cancel553;
                            }
                        }
                    }
                    state = 0x310;
                    goto pilot_prompt_finish553;
                pilot_prompt_cancel553:
                    if (D_02007574[0] == 0)
                        func_080019EC(63);
                    {
                        register u16 *slots asm("r2") = remembered_base;
                        register u32 previous asm("r0");
                        register u16 *cursor asm("r3");
                        asm("" : "+r"(slots));
                        ((volatile u32)previous) = slots[1];
                        ((u16 *volatile)cursor) = &D_02007588;
                        asm("" : "+r"(cursor) : "r"(previous));
                        *(u16 *volatile)cursor = (volatile u32)previous;
                    }
                    goto pilot_list_open;
                pilot_prompt_finish553:;
                }
                else
                {
                    func_080019EC(63);
                    state = 0x10;
                }
            }
            func_0803E488(pilot_messages, 11);
            func_0803E488(pilot_messages, 10);
            func_0803E488(pilot_messages, 9);
            func_0803E488(pilot_messages, 0);
            break;
        }
        case 0x310:
        {
            register u8 *roster asm("r0") = D_0200E5F0;
            register u32 selected asm("r4");
            register u32 shifted asm("r1");
            register u8 *entry asm("r1");
            asm("" : "+r"(roster));
            selected = frame.field_30;
            asm("" : "+r"(selected));
            shifted = selected << 16;
            asm("" : "+r"(shifted));
            shifted = (s32)shifted >> 16;
            asm("" : "+r"(shifted));
            entry = (u8 *)(shifted + (u32)roster);
            asm("" : "+r"(entry));
            func_0805506C(*entry);
        }
            func_0803E488(D_0875B448, 0);
            {
                register u32 zero asm("r5") = 0;
                register u16 *cursor asm("r6");
                asm("" : "+r"(zero));
                frame.page = zero;
                cursor = &D_02007588;
                asm("" : "+r"(cursor));
                *cursor = zero;
            }
            state = 0x312;
            break;
        case 0x311:
            func_0803E488(D_0875B448, 0);
            {
                register u16 *details asm("r0") = frame.detail;
                register u32 value asm("r0");
                register u8 *remembered_byte asm("r1");
                register u16 *cursor asm("r2");
                asm("" : "+r"(details));
                value = details[2];
                asm("" : "+r"(value));
                frame.page = value;
                menu_pointer.cursor = remembered_base;
                asm("" : "+r"(menu_pointer.cursor));
                value = menu_pointer.cursor[2];
                asm("" : "+r"(value));
                remembered_byte = &D_02007FA9;
                asm("" : "+r"(remembered_byte) : "r"(value));
                *remembered_byte = value;
                value = (u8)value;
                asm("" : "+r"(value));
                cursor = &D_02007588;
                asm("" : "+r"(cursor) : "r"(value));
                *cursor = value;
            }
        case 0x312:
        {
            register u32 stock_previous asm("r8");
            register u16 *pilot_stock_cursor asm("r10");
            {
                register u32 previous asm("r3") = 0xFFFF;
                register u8 *details asm("r4");
                register u32 shifted asm("r5");
                register u8 *roster asm("r0");
                register u8 *stock asm("r6");
                register u16 *cursor asm("r0");
                asm("" : "+r"(previous));
                frame.previous_selected = previous;
                frame.previous_page = previous;
                details = (u8 *)&frame;
                asm("" : "+r"(details));
                details += 8;
                asm("" : "+r"(details));
                (*(u16 **)(formation_stack + 128)) = (u16 *)details;
                asm("" : : "l"((*(u16 **)(formation_stack + 128))));
                shifted = frame.field_30;
                asm("" : "+r"(shifted));
                shifted <<= 16;
                asm("" : "+r"(shifted));
                (*(u32 *)(formation_stack + 132)) = shifted;
                roster = D_0200E5F0;
                asm("" : "+r"(roster));
                stock = D_0200E7F4;
                asm("" : "+r"(stock));
                pilot_stock_roster = stock;
                asm("" : "+r"(pilot_stock_roster));
                menu_pointer.selector = (s32)shifted >> 16;
                asm("" : "+l"(menu_pointer.selector) : "r"(shifted));
                (*(s32 *)(formation_stack + 112)) = menu_pointer.selector;
                (*(u8 **)(formation_stack + 116)) = (u8 *)(menu_pointer.selector + (u32)roster);
                asm("" : : "l"((*(u8 **)(formation_stack + 116))));
                cursor = &D_02007588;
                asm("" : "+r"(cursor));
                pilot_stock_cursor = cursor;
                asm("" : "+r"(pilot_stock_cursor));
            }
        pilot_stock_open:
            func_0803E488(D_0875AFB8, 25);
            {
                register u8 *entry asm("r1") = (*(u8 **)(formation_stack + 116));
                asm("" : "+r"(entry));
                func_08032818(*entry);
            }
            func_0803E488(D_0875B448, 1);
            func_0803E488(D_0875AFB8, 28);
            {
                register u32 active asm("r2");
                ((volatile u32)active) = 1;
                frame.active = (volatile u32)active;
            }
        pilot_stock_update:
        {
            register u32 page_shift asm("r5");
            register s32 page asm("r4");
            register s32 previous_page asm("r2");
            {
                register u32 loaded asm("r3") = frame.page;
                register u32 shifted asm("r1");
                register u32 previous asm("r5");
                register u32 previous_shift asm("r0");
                register u32 previous_selected asm("r6");
                asm("" : "+r"(loaded));
                shifted = loaded << 16;
                asm("" : "+r"(shifted));
                page = (s32)shifted >> 16;
                asm("" : "+r"(page));
                previous = frame.previous_page;
                asm("" : "+r"(previous));
                previous_shift = previous << 16;
                asm("" : "+r"(previous_shift));
                previous_page = (s32)previous_shift >> 16;
                asm("" : "+r"(previous_page));
                page_shift = shifted;
                asm("" : "+r"(page_shift));
                previous_selected = frame.previous_selected;
                asm("" : "+r"(previous_selected));
                previous_selected <<= 16;
                asm("" : "+r"(previous_selected));
                stock_previous = previous_selected;
                asm("" : "+r"(stock_previous));
            }
            if (page != previous_page)
            {
                register u32 shown asm("r6");
                register u8 *count_address asm("r12");
                u8 *count;
                u8 *save;
                if (previous_page != -1)
                    func_0803E488(D_0875AFB8, 3);
                ((volatile u32)shown) = 0;
                {
                    register u32 value asm("r0");
                    register u8 *address asm("r1");
                    register u32 limit asm("r1");
                    ((volatile u32)value) = (u32)(page * 6) << 16;
                    menu_pointer.selector = (volatile u32)value >> 16;
                    asm("" : "+l"(menu_pointer.selector));
                    frame.row = menu_pointer.selector;
                    ((volatile u32)value) = (s32)(volatile u32)value >> 16;
                    ((u8 *volatile)address) = &D_0200E8A1;
                    ((u8 *volatile)count_address) = (u8 *volatile)address;
                    ((volatile u32)limit) = *(u8 *volatile)address;
                    if ((s32)(volatile u32)value >= (s32)(volatile u32)limit)
                        goto pilot_stock_rows_done;
                }
                {
                    register u8 *base asm("r3") = D_02000B5C;
                    asm("" : "+r"(base));
                    count = count_address;
                    asm("" : "+r"(count) : "r"(base));
                    save = base;
                    asm("" : "+r"(save) : "r"(count));
                }
                menu_pointer.selector = page;
                asm("" : "+l"(menu_pointer.selector) : "r"(page_shift));
            pilot_stock_row:
            {
                register s32 row_index asm("r4");
                register u32 shifted asm("r0");
                register u8 *roster asm("r1");
                register u32 entry asm("r1");
                register u32 model_address asm("r0");
                register u32 offset asm("r1");
                register s32 signed_shown asm("r0");
                ((volatile s32)row_index) = frame.row;
                ((volatile u32)shifted) = (volatile s32)row_index << 16;
                ((volatile s32)row_index) = (s32)(volatile u32)shifted >> 16;
                ((u8 *volatile)roster) = pilot_stock_roster;
                ((volatile u32)model_address) = (volatile s32)row_index + (u32)(u8 *volatile)roster;
                ((volatile u32)entry) = *(u8 *)(volatile u32)model_address;
                ((volatile u32)model_address) = (volatile u32)entry * 56;
                ((volatile u32)model_address) = (volatile u32)model_address + (u32)save;
                asm("" : "+r"(model_address) : "r"(save));
                ((volatile u32)offset) = 0xD32;
                ((volatile u32)model_address) = (volatile u32)model_address + (volatile u32)offset;
                func_08032800(*(u16 *)(volatile u32)model_address);
                ((volatile s32)signed_shown) = (s32)((volatile u32)shown << 16) >> 16;
                asm("" : : "r"(count), "r"(save));
                if ((volatile s32)signed_shown <= 4 && (volatile s32)row_index < *count - 1)
                {
                    func_0803E488(D_08675C5C, 0);
                    asm("" : : "r"(save));
                    asm("" : : "r"(count));
                }
            }
                {
                    register u32 value asm("r0");
                    register u32 step asm("r4");
                    register s32 signed_shown asm("r1");
                    register u32 limit asm("r4");
                    ((volatile u32)value) = (volatile u32)shown << 16;
                    ((volatile u32)step) = 0x10000;
                    ((volatile u32)value) = (volatile u32)value + (volatile u32)step;
                    ((volatile u32)shown) = (volatile u32)value >> 16;
                    ((volatile s32)signed_shown) = (s32)(volatile u32)value >> 16;
                    {
                        register u8 *address asm("r0");
                        ((u8 *volatile)address) = &D_0200E8A1;
                        ((u8 *volatile)count_address) = (u8 *volatile)address;
                    }
                    if ((volatile s32)signed_shown > 5)
                        goto pilot_stock_rows_done;
                    ((volatile u32)value) = menu_pointer.selector * 6;
                    ((volatile u32)value) = (volatile s32)signed_shown + (volatile u32)value;
                    ((volatile u32)value) = (volatile u32)value << 16;
                    frame.row = (volatile u32)value >> 16;
                    ((volatile u32)value) = (s32)(volatile u32)value >> 16;
                    ((volatile u32)limit) = *count;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r4");
                        guard.part.low = limit;
                        limit = guard.part.low;
                    }
                    if ((s32)(volatile u32)value < (s32)(volatile u32)limit)
                        goto pilot_stock_row;
                }
            pilot_stock_rows_done:
            {
                register s32 signed_shown asm("r0");
                register u16 *cursor asm("r2");
                register u32 cursor_value asm("r1");
                ((volatile s32)signed_shown) = (s32)((volatile u32)shown << 16) >> 16;
                ((u16 *volatile)cursor) = &D_02007588;
                menu_pointer.save = D_020075A0;
                asm("" : "+l"(menu_pointer.save));
                ((volatile u32)cursor_value) = *(u16 *volatile)cursor;
                {
                    register union
                    {
                        unsigned long long whole;
                        struct
                        {
                            u32 low, high;
                        } part;
                    } guard asm("r0");
                    guard.part.high = cursor_value;
                    cursor_value = guard.part.high;
                }
                if ((volatile s32)signed_shown <= (s32)(volatile u32)cursor_value)
                {
                    register u32 value asm("r0");
                    register u8 *byte_cursor asm("r3");
                    ((volatile u32)value) = (volatile u32)shown - 1;
                    ((u8 *volatile)byte_cursor) = &D_02007FA9;
                    *(u8 *volatile)byte_cursor = (volatile u32)value;
                    ((volatile u32)value) = (u8)(volatile u32)value;
                    *(u16 *volatile)cursor = (volatile u32)value;
                }
            }
                {
                    register u32 offset asm("r4");
                    register u8 *flags asm("r2");
                    register u32 zero asm("r3");
                    register u32 value asm("r0");
                    register u32 row asm("r6");
                    register s32 signed_row asm("r1");
                    ((volatile u32)offset) = 0xA0B;
                    asm("" : : "r"(offset));
                    ((u8 *volatile)flags) = menu_pointer.save + (volatile u32)offset;
                    zero = 0;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } guard asm("r2");
                        guard.part.high = zero;
                        zero = guard.part.high;
                    }
                    value = 0;
                    asm("" : "+r"(value) : "r"(zero));
                    *(u8 *volatile)flags = value;
                    if ((s32)page_shift > 0)
                    {
                        ((volatile u32)value) = 1;
                        *(u8 *volatile)flags = (volatile u32)value;
                    }
                    ((volatile u32)row) = frame.row;
                    ((volatile s32)signed_row) = (s32)((volatile u32)row << 16) >> 16;
                    menu_pointer.count = count_address;
                    asm("" : "+l"(menu_pointer.count));
                    ((volatile u32)value) = *menu_pointer.count;
                    ((volatile u32)value) = (volatile u32)value - 1;
                    if ((volatile s32)signed_row < (s32)(volatile u32)value)
                    {
                        register u32 bits asm("r1");
                        ((volatile u32)bits) = *(u8 *volatile)flags;
                        ((volatile u32)value) = 2;
                        ((volatile u32)bits) = (volatile u32)bits | (volatile u32)value;
                        *(u8 *volatile)flags = (volatile u32)bits;
                    }
                }
                asm("" : "+r"(page_shift));
                frame.previous_page = (u16)(page_shift >> 16);
            }
            {
                register s32 page asm("r1") = (s32)page_shift >> 16;
                register u32 value asm("r0");
                asm("" : "+r"(page));
                value = page * 6;
                ((__typeof__(value) volatile)value) = (__typeof__(value) volatile)value;
                {
                    register u16 *cursor asm("r1") = pilot_stock_cursor;
                    register u32 selected asm("r1");
                    ((__typeof__(cursor) volatile)cursor) = (__typeof__(cursor) volatile)cursor;
                    selected = *cursor;
                    asm("" : "+r"(selected));
                    value += selected;
                    ((__typeof__(value) volatile)value) = (__typeof__(value) volatile)value;
                }
                value <<= 16;
                ((__typeof__(value) volatile)value) = (__typeof__(value) volatile)value;
                value >>= 16;
                ((__typeof__(value) volatile)value) = (__typeof__(value) volatile)value;
                frame.selected = value;
            }
        }
            {
                register u32 selected_shift asm("r4");
                register s32 selected_index asm("r5");
                register u32 previous_shift asm("r2");
                register s32 previous asm("r1");
                {
                    register u32 selected asm("r0") = frame.selected;
                    asm("" : : "r"(selected));
                    selected_shift = selected << 16;
                }
                asm("" : "+r"(selected_shift));
                selected_index = (s32)selected_shift >> 16;
                asm("" : "+r"(selected_index));
                previous_shift = stock_previous;
                asm("" : "+r"(previous_shift));
                previous = (s32)previous_shift >> 16;
                asm("" : "+r"(previous));
                if (selected_index != previous)
                {
                    u8 entry;
                    register u8 *selected_entry asm("r4");
                    if (previous != -1)
                    {
                        {
                            register u8 *address asm("r2") = D_03004BBC;
                            register u32 flags asm("r1");
                            register u32 mask asm("r3");
                            register u32 bits asm("r0");
                            asm("" : "+r"(address));
                            address += 0x88;
                            flags = *(u16 *)address;
                            mask = 0x7FFF;
                            asm("" : "+r"(mask) : "r"(flags));
                            bits = mask;
                            asm("" : "+r"(bits));
                            flags &= bits;
                            *(u16 *)address = flags;
                        }
                        func_0803E488(D_0875AFB8, 1);
                    }
                    i = 0;
                    asm("" : : "r"(i));
                    (*(u32 *)(formation_stack + 136)) = selected_shift;
                    {
                        register u8 *stats asm("r4") = (u8 *)&frame.stats;
                        asm("" : "+r"(stats));
                        stats_base = stats;
                        asm("" : "+r"(stats_base));
                    }
                    menu_pointer.save = D_02000B5C;
                    asm("" : "+l"(menu_pointer.save));
                    {
                        register u8 *roster asm("r0") = D_0200E7F4;
                        asm("" : "+r"(roster));
                        selected_entry = (u8 *)(selected_index + (u32)roster);
                        asm("" : "+r"(selected_entry));
                    }
                    for (; i <= 86; i++)
                    {
                        register u32 scaled asm("r0") = i * 4;
                        register u8 *record asm("r2");
                        register u32 offset asm("r5");
                        register u8 *address asm("r0");
                        register u32 flags asm("r1");
                        register u32 mask asm("r0");
                        asm("" : "+r"(scaled));
                        record = (u8 *)(scaled + (u32)menu_pointer.save);
                        asm("" : "+r"(record));
                        offset = 0x34A4;
                        asm("" : "+r"(offset));
                        address = record + offset;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        flags = *(u16 *)address;
                        asm("" : "+r"(flags));
                        mask = 2;
                        asm("" : "+r"(mask));
                        mask &= flags;
                        asm("" : "+r"(mask));
                        if (mask)
                        {
                            register u32 offset asm("r1") = 0x34A6;
                            register u8 *address asm("r0");
                            register u32 value asm("r0");
                            register u32 selected asm("r2");
                            asm("" : "+r"(offset));
                            address = record + offset;
                            ((__typeof__(address) volatile)address) =
                                (__typeof__(address) volatile)address;
                            value = *address;
                            ((__typeof__(value) volatile)value) = (__typeof__(value) volatile)value;
                            selected = *selected_entry;
                            asm("" : "+r"(selected));
                            if (value == selected)
                                break;
                        }
                    }
                    frame.linked_slot = (u16)i;
                    {
                        register u32 loaded asm("r3") = (*(u32 *)(formation_stack + 136));
                        ((__typeof__(loaded) volatile)loaded) = (__typeof__(loaded) volatile)loaded;
                        selected_entry = (u8 *)((s32)loaded >> 16);
                        ((__typeof__(selected_entry) volatile)selected_entry) =
                            (__typeof__(selected_entry) volatile)selected_entry;
                        selected_entry = (u8 *)((u32)selected_entry + (u32)pilot_stock_roster);
                        ((__typeof__(selected_entry) volatile)selected_entry) =
                            (__typeof__(selected_entry) volatile)selected_entry;
                        entry = *selected_entry;
                    }
                    {
                        register u8 *save asm("r5");
                        register u32 address asm("r0");
                        register u8 *target asm("r1");
                        register u32 offset asm("r6");
                        address = entry * 56;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        save = D_02000B5C;
                        ((__typeof__(save) volatile)save) = (__typeof__(save) volatile)save;
                        address += (u32)save;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        target = stats_base;
                        asm("" : "+r"(target));
                        offset = 0xD54;
                        asm("" : "+r"(offset));
                        *(struct MenuStats553 *)target = *(struct MenuStats553 *)(address + offset);
                        asm("" : : "r"(offset));
                        func_0803E488(D_0875AFB8, 26);
                        entry = *selected_entry;
                        address = entry * 56;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        address += (u32)save;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        {
                            register u32 model_offset asm("r4") = 0xD32;
                            asm("" : "+r"(model_offset));
                            address += model_offset;
                            func_08032800(*(u16 *)address);
                        }
                    }
                    {
                        register const u8 *separator asm("r4");
                        register const u8 *messages asm("r5");
                        ((const u8 *volatile)separator) = D_08675C5C;
                        func_0803E488((const u8 *volatile)separator, 0);
                        ((const u8 *volatile)messages) = D_0875B448;
                        func_0803E488((const u8 *volatile)messages, 7);
                        func_08001848(frame.stats.hp, 4, 0);
                        func_0803E488((const u8 *volatile)separator, 0);
                        func_0803E488((const u8 *volatile)messages, 8);
                        {
                            register const u8 *stats asm("r6");
                            ((const u8 *volatile)stats) = (u8 *volatile)stats_base;
                            func_08001848(*(s32 *)((const u8 *volatile)stats + 4), 3, 0);
                        }
                        func_0803E488((const u8 *volatile)separator, 0);
                        func_0803E488((const u8 *volatile)messages, 11);
                        {
                            register u32 linked asm("r7");
                            register u32 argument asm("r0");
                            ((volatile u32)linked) = frame.linked_slot;
                            ((volatile u32)argument) = (volatile u32)linked << 16;
                            ((volatile u32)argument) = (s32)(volatile u32)argument >> 16;
                            if ((volatile u32)argument != 87)
                                func_08032818((volatile u32)argument);
                            else
                                func_0803E488((const u8 *volatile)messages, 12);
                        }
                    }
                    {
                        register u32 loaded asm("r1") = (*(u32 *)(formation_stack + 136));
                        register u32 address asm("r0");
                        register u32 entry_value asm("r1");
                        register u8 *save asm("r2");
                        register u32 offset asm("r3");
                        asm("" : "+r"(loaded));
                        address = (s32)loaded >> 16;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        address += (u32)pilot_stock_roster;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        entry_value = *(u8 *)address;
                        ((__typeof__(entry_value) volatile)entry_value) =
                            (__typeof__(entry_value) volatile)entry_value;
                        address = entry_value * 56;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        save = D_02000B5C;
                        asm("" : "+r"(save));
                        address += (u32)save;
                        ((__typeof__(address) volatile)address) =
                            (__typeof__(address) volatile)address;
                        offset = 0xD32;
                        asm("" : "+r"(offset));
                        address += offset;
                        func_0804D654(*(u16 *)address, 40, 88);
                    }
                    {
                        register u32 previous asm("r4") = (*(u32 *)(formation_stack + 136));
                        asm("" : "+r"(previous));
                        previous >>= 16;
                        frame.previous_selected = previous;
                    }
                    {
                        register u32 active asm("r5") = 1;
                        asm("" : "+r"(active));
                        frame.active = active;
                    }
                }
            }
            {
                register u32 active asm("r6") = frame.active;
                asm("" : "+r"(active));
                if (active)
                {
                    func_0803E488(D_0875AFB8, 24);
                    {
                        register u32 inactive asm("r7") = 0;
                        asm("" : "+r"(inactive));
                        frame.active = inactive;
                    }
                }
            }
            do
                func_0803E488(D_0875AFB8, 36);
            while (D_0300235A & 4);
            {
                register u16 *address asm("r0") = D_02007574;
                register u32 first asm("r1");
                ((__typeof__(address) volatile)address) = (__typeof__(address) volatile)address;
                first = *address;
                asm("" : "+r"(first) : "r"(address));
                if (first > 1 && first != 128)
                {
                    register u16 *keys asm("r1") = address;
                    register u32 key asm("r0");
                    register u32 next_page asm("r0");
                    asm("" : "+r"(keys));
                    key = *keys;
                    asm("" : "+r"(key));
                    if (key == 2)
                        goto pilot_stock_page_left553;
                    if (key == 4)
                        goto pilot_stock_page_right553;
                    goto pilot_stock_update;
                pilot_stock_page_left553:
                {
                    register u32 loaded asm("r2") = frame.page;
                    register s32 page asm("r4");
                    asm("" : "+r"(loaded));
                    next_page = loaded << 16;
                    ((__typeof__(next_page) volatile)next_page) =
                        (__typeof__(next_page) volatile)next_page;
                    page = (s32)next_page >> 16;
                    asm("" : "+r"(page));
                    if (page <= 0)
                        goto pilot_stock_update;
                    func_080019EC(64);
                    next_page = page - 1;
                    next_page <<= 16;
                    goto pilot_stock_page_store553;
                }
                pilot_stock_page_right553:
                {
                    register u32 loaded asm("r3") = frame.row;
                    register s32 row asm("r1");
                    asm("" : "+r"(loaded));
                    row = (s32)(loaded << 16) >> 16;
                    asm("" : "+r"(row));
                    if (row >= D_0200E8A1 - 1)
                        goto pilot_stock_update;
                    func_080019EC(64);
                    {
                        register u32 page asm("r4") = frame.page;
                        register u32 increment asm("r5");
                        asm("" : "+r"(page));
                        next_page = page << 16;
                        ((__typeof__(next_page) volatile)next_page) =
                            (__typeof__(next_page) volatile)next_page;
                        increment = 0x10000;
                        asm("" : "+r"(increment));
                        next_page += increment;
                    }
                }
                pilot_stock_page_store553:
                    next_page >>= 16;
                    frame.page = next_page;
                    goto pilot_stock_update;
                }
            }
            {
                u32 action;
                {
                    register u16 *input asm("r6") = D_02007574;
                    register u32 cursor asm("r0");
                    register u32 page asm("r1");
                    asm("" : "+r"(input));
                    cursor = input[1];
                    ((__typeof__(cursor) volatile)cursor) = (__typeof__(cursor) volatile)cursor;
                    menu_pointer.cursor = remembered_base;
                    asm("" : "+l"(menu_pointer.cursor) : "r"(cursor), "r"(input));
                    menu_pointer.cursor[2] = cursor;
                    page = *(volatile u16 *)&frame.page;
                    asm("" : "+r"(page));
                    (*(u16 **)(formation_stack + 128))[2] = page;
                    action = input[0];
                }
                if (action == 1)
                {
                    {
                        register s32 linked asm("r5");
                        register u8 *save asm("r6");
                        {
                            register u32 loaded asm("r2") = frame.linked_slot;
                            register u32 shifted asm("r0");
                            asm("" : "+r"(loaded));
                            shifted = loaded << 16;
                            ((__typeof__(shifted) volatile)shifted) =
                                (__typeof__(shifted) volatile)shifted;
                            linked = (s32)shifted >> 16;
                            asm("" : "+r"(linked));
                        }
                        if (linked != 87)
                        {
                            func_0803E488(D_0875AFB8, 0);
                            func_0803E488(D_0875AFB8, 25);
                            if (({
                                    register u32 address asm("r0");
                                    register u32 flags_offset asm("r3");
                                    save = D_02000B5C;
                                    asm("" : "+r"(save));
                                    address = linked * 4;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    address += (u32)save;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    flags_offset = 0x34A4;
                                    asm("" : "+r"(flags_offset));
                                    address += flags_offset;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    *(u16 *)address;
                                }) &
                                8)
                            {
                                func_080019EC(79);
                                func_08032818(linked);
                                func_0803E488(D_0875B434, 1);
                                {
                                    register u32 selected asm("r5") = frame.selected;
                                    register u32 address asm("r0");
                                    register u32 model_entry asm("r1");
                                    register u32 field asm("r6");
                                    asm("" : "+r"(selected));
                                    address = selected << 16;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    address = (s32)address >> 16;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    address += (u32)pilot_stock_roster;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    model_entry = *(u8 *)address;
                                    ((__typeof__(model_entry) volatile)model_entry) =
                                        (__typeof__(model_entry) volatile)model_entry;
                                    address = model_entry * 56;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    address += (u32)save;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    field = 0xD32;
                                    asm("" : "+r"(field));
                                    address += field;
                                    ((__typeof__(address) volatile)address) =
                                        (__typeof__(address) volatile)address;
                                    func_08032800(*(u16 *)address);
                                }
                                func_0803E488(D_0875B434, 3);
                                func_080019EC(65);
                                {
                                    register u32 cursor asm("r0");
                                    menu_pointer.cursor = remembered_base;
                                    asm("" : "+l"(menu_pointer.cursor));
                                    cursor = menu_pointer.cursor[2];
                                    ((__typeof__(cursor) volatile)cursor) =
                                        (__typeof__(cursor) volatile)cursor;
                                    *pilot_stock_cursor = cursor;
                                }
                                goto pilot_stock_open;
                            }
                            {
                                register u32 selected asm("r2") = frame.selected;
                                register u32 address asm("r0");
                                register u32 model_entry asm("r1");
                                register u32 field asm("r3");
                                asm("" : "+r"(selected));
                                address = selected << 16;
                                ((__typeof__(address) volatile)address) =
                                    (__typeof__(address) volatile)address;
                                address = (s32)address >> 16;
                                ((__typeof__(address) volatile)address) =
                                    (__typeof__(address) volatile)address;
                                address += (u32)pilot_stock_roster;
                                ((__typeof__(address) volatile)address) =
                                    (__typeof__(address) volatile)address;
                                model_entry = *(u8 *)address;
                                ((__typeof__(model_entry) volatile)model_entry) =
                                    (__typeof__(model_entry) volatile)model_entry;
                                address = model_entry * 56;
                                ((__typeof__(address) volatile)address) =
                                    (__typeof__(address) volatile)address;
                                address += (u32)save;
                                ((__typeof__(address) volatile)address) =
                                    (__typeof__(address) volatile)address;
                                field = 0xD32;
                                asm("" : "+r"(field));
                                address += field;
                                ((__typeof__(address) volatile)address) =
                                    (__typeof__(address) volatile)address;
                                func_08032800(*(u16 *)address);
                            }
                            func_0803E488(D_0875B448, 2);
                            func_08032818(linked);
                            func_0803E488(D_0875B448, 3);
                            func_0803E488(D_0875B068, 17);
                            func_0803E488(D_0875AFB8, 0);
                            {
                                register u16 *response asm("r4") = D_02007574;
                                register u32 first asm("r1");
                                asm("" : "+r"(response));
                                first = response[0];
                                ((__typeof__(first) volatile)first) =
                                    (__typeof__(first) volatile)first;
                                if (first != 1)
                                    goto pilot_stock_assigned_cancel553;
                                {
                                    register u32 second asm("r0") = response[1];
                                    asm("" : "+r"(second));
                                    if (second == 0)
                                        goto pilot_stock_assigned_accept553;
                                }
                            pilot_stock_assigned_cancel553:
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } condition asm("r0");
                                condition.part.high = first;
                                if (condition.part.high == 0)
                                    func_080019EC(63);
                            }
                                {
                                    register u16 *remembered asm("r5") = remembered_base;
                                    register u32 cursor asm("r0");
                                    register u16 *destination asm("r6");
                                    asm("" : "+r"(remembered));
                                    cursor = remembered[2];
                                    ((__typeof__(cursor) volatile)cursor) =
                                        (__typeof__(cursor) volatile)cursor;
                                    destination = pilot_stock_cursor;
                                    asm("" : "+r"(destination));
                                    *destination = cursor;
                                }
                                goto pilot_stock_open;
                            pilot_stock_assigned_accept553:;
                            }
                        }
                    }
                    {
                        register u32 selected_pilot asm("r3");
                        register u8 *formation_save asm("r4");
                        {
                            register u32 zero asm("r7") = 0;
                            asm("" : : "r"(zero));
                            frame.field_4C = zero;
                        }
                        if (({
                                register u8 *save asm("r2") = D_02000B5C;
                                register u8 *entry asm("r0");
                                register u32 address asm("r0");
                                register u32 offset asm("r1");
                                register u32 flags asm("r1");
                                register u32 value asm("r0");
                                asm("" : : "r"(save));
                                entry = (*(u8 **)(formation_stack + 116));
                                asm("" : : "r"(entry));
                                selected_pilot = *entry;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r2");
                                    guard.part.high = selected_pilot;
                                    selected_pilot = guard.part.high;
                                }
                                address = selected_pilot << 2;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                address += (u32)save;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                offset = 0x34A4;
                                asm("" : "+r"(offset));
                                address += offset;
                                flags = *(u16 *)address;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = flags;
                                    flags = guard.part.high;
                                }
                                value = 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = value;
                                    value = guard.part.low;
                                }
                                value &= flags;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = value;
                                    value = guard.part.low;
                                }
                                value;
                            }) &&
                            ({
                                register u32 selected asm("r2") = frame.selected;
                                register u32 address asm("r0");
                                register u32 entry asm("r1");
                                register u32 offset asm("r5");
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r2");
                                    guard.part.low = selected;
                                    selected = guard.part.low;
                                }
                                address = selected << 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                address = (s32)address >> 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                address += (u32)pilot_stock_roster;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                entry = *(u8 *)address;
                                asm("" : : "r"(entry));
                                address = entry * 56;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                formation_save = D_02000B5C;
                                asm("" : : "r"(formation_save));
                                address += (u32)formation_save;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                offset = 0xD61;
                                asm("" : "+r"(offset));
                                address += offset;
                                *(u8 *)address;
                            }) == 2)
                        {
                            register u32 slot asm("r6");
                            register u32 other asm("r5");
                            register u32 slot_shift asm("r2");
                            register s32 signed_slot asm("r1");
                            register u32 record_bits asm("r0");
                            {
                                register u32 value asm("r0");
                                register u32 offset asm("r7");
                                slot = 0;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r6");
                                    guard.part.low = slot;
                                    slot = guard.part.low;
                                }
                                offset = 0x3601;
                                asm("" : : "r"(offset));
                                value = (u32)formation_save + offset;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = value;
                                    value = guard.part.low;
                                }
                                value = *(u8 *)value;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = value;
                                    value = guard.part.low;
                                }
                                if (value != selected_pilot)
                                {
                                    register u8 *save asm("r2") = formation_save;
                                    register u8 *roster asm("r0");
                                    register s32 index asm("r3");
                                    register u8 *pilot asm("r1");
                                    asm("" : : "r"(save));
                                    roster = D_0200E5F0;
                                    asm("" : : "r"(roster));
                                    index = (*(s32 *)(formation_stack + 112));
                                    asm("" : : "r"(index));
                                    pilot = (u8 *)((u32)index + (u32)roster);
                                    asm("" : : "r"(pilot));
                                pilot_slot_scan553:
                                {
                                    register u32 shifted asm("r0") = (u32)slot << 16;
                                    register u32 step asm("r4");
                                    register u32 field asm("r5");
                                    register u32 pilot_value asm("r7");
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = shifted;
                                        shifted = guard.part.low;
                                    }
                                    step = 0x10000;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r4");
                                        guard.part.low = step;
                                        step = guard.part.low;
                                    }
                                    shifted += step;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = shifted;
                                        shifted = guard.part.low;
                                    }
                                    slot = shifted >> 16;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r6");
                                        guard.part.low = slot;
                                        slot = guard.part.low;
                                    }
                                    shifted = (s32)shifted >> 16;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = shifted;
                                        shifted = guard.part.low;
                                    }
                                    if ((s32)shifted > 5)
                                        goto pilot_slot_scanned553;
                                    shifted <<= 2;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = shifted;
                                        shifted = guard.part.low;
                                    }
                                    shifted += (u32)save;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = shifted;
                                        shifted = guard.part.low;
                                    }
                                    field = 0x3601;
                                    asm("" : : "r"(field));
                                    shifted += field;
                                    shifted = *(u8 *)shifted;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low, high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = shifted;
                                        shifted = guard.part.low;
                                    }
                                    pilot_value = *pilot;
                                    asm("" : : "r"(pilot_value));
                                    if (shifted != pilot_value)
                                        goto pilot_slot_scan553;
                                }
                                }
                            }
                        pilot_slot_scanned553:
                        {
                            register u32 shifted asm("r0") = (u32)slot << 16;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = shifted;
                                shifted = guard.part.low;
                            }
                            signed_slot = (s32)shifted >> 16;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.high = signed_slot;
                                signed_slot = guard.part.high;
                            }
                            slot_shift = shifted;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r2");
                                guard.part.low = slot_shift;
                                slot_shift = guard.part.low;
                            }
                        }
                            if (signed_slot > 2)
                                goto pilot_other_back_start553;
                            {
                                register u32 address asm("r0");
                                register s32 row asm("r1");
                                other = 0;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(other) high;
                                        } part;
                                    } guard asm("r4");
                                    guard.part.high = other;
                                    other = guard.part.high;
                                }
                                if ((s32)other == signed_slot)
                                    goto pilot_other_front_next553;
                                {
                                    register u8 *save asm("r1") = D_02000B5C;
                                    register u32 offset asm("r3") = 0x3600;
                                    asm("" : : "r"(save), "r"(offset));
                                    address = (u32)save + offset;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                __typeof__(address) low;
                                                u32 high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = address;
                                        address = guard.part.low;
                                    }
                                    goto pilot_other_front_row553;
                                }
                            pilot_other_front_next553:
                            {
                                register u32 shifted asm("r0") = (u32)other << 16;
                                register u32 step asm("r4") = 0x10000;
                                asm("" : : "r"(shifted), "r"(step));
                                shifted += step;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(shifted) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = shifted;
                                    shifted = guard.part.low;
                                }
                                other = shifted >> 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(other) high;
                                        } part;
                                    } guard asm("r4");
                                    guard.part.high = other;
                                    other = guard.part.high;
                                }
                                row = (s32)shifted >> 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(row) high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = row;
                                    row = guard.part.high;
                                }
                            }
                                if (row > 2)
                                    goto pilot_other_front_done553;
                                address = (s32)slot_shift >> 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(address) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                if (row == (s32)address)
                                    goto pilot_other_front_next553;
                                address = (u32)row << 2;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(address) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                {
                                    register u8 *save asm("r7") = D_02000B5C;
                                    register u32 offset asm("r1");
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low;
                                                __typeof__(save) high;
                                            } part;
                                        } guard asm("r6");
                                        guard.part.high = save;
                                        save = guard.part.high;
                                    }
                                    address += (u32)save;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                __typeof__(address) low;
                                                u32 high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.low = address;
                                        address = guard.part.low;
                                    }
                                    offset = 0x3600;
                                    {
                                        register union
                                        {
                                            unsigned long long whole;
                                            struct
                                            {
                                                u32 low;
                                                __typeof__(offset) high;
                                            } part;
                                        } guard asm("r0");
                                        guard.part.high = offset;
                                        offset = guard.part.high;
                                    }
                                    address += offset;
                                }
                            pilot_other_front_row553:
                                address = *(u8 *)address;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(address) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                if (address == 255)
                                    goto pilot_other_front_next553;
                            pilot_other_front_done553:;
                            }
                            if (other != 3)
                                goto pilot_assignment_front_linked553;
                            {
                                register s32 selected_slot asm("r0") = (s32)slot_shift >> 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(selected_slot) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = selected_slot;
                                    selected_slot = guard.part.low;
                                }
                                if (selected_slot == 1)
                                    goto pilot_assignment_done553;
                            }
                            {
                                register const u8 *script asm("r4") = D_0875B448;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(script) high;
                                        } part;
                                    } guard asm("r3");
                                    guard.part.high = script;
                                    script = guard.part.high;
                                }
                                func_0803E488(script, 4);
                                func_0803E488(script, 6);
                                func_0803E488(D_0875B068, 17);
                                func_0803E488(D_0875AFB8, 0);
                            }
                            {
                                register u16 *response asm("r1") = D_02007574;
                                register u32 first asm("r0");
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(response) high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = response;
                                    response = guard.part.high;
                                }
                                first = response[0];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(first) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = first;
                                    first = guard.part.low;
                                }
                                if (first != 1)
                                    goto pilot_assignment_solo_cancel553;
                                first = response[1];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(first) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = first;
                                    first = guard.part.low;
                                }
                                if (first != 0)
                                    goto pilot_assignment_solo_cancel553;
                            }
                            {
                                register s32 mask asm("r2") = 128;
                                asm("" : "+r"(mask));
                                mask = -mask;
                                asm("" : "+r"(mask));
                                record_bits = mask;
                                asm("" : "+r"(record_bits));
                            }
                            goto pilot_assignment_record553;
                        pilot_assignment_front_linked553:
                        {
                            register const u8 *script asm("r4") = D_0875B448;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low;
                                        __typeof__(script) high;
                                    } part;
                                } guard asm("r3");
                                guard.part.high = script;
                                script = guard.part.high;
                            }
                            func_0803E488(script, 4);
                            {
                                register u8 *entry asm("r5") = (*(u8 **)(formation_stack + 116));
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(entry) high;
                                        } part;
                                    } guard asm("r4");
                                    guard.part.high = entry;
                                    entry = guard.part.high;
                                }
                                func_08032818(*entry);
                            }
                            func_0803E488(script, 5);
                            func_0803E488(D_0875B068, 17);
                            func_0803E488(D_0875AFB8, 0);
                        }
                            {
                                register u16 *response asm("r1") = D_02007574;
                                register u32 first asm("r0");
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(response) high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = response;
                                    response = guard.part.high;
                                }
                                first = response[0];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(first) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = first;
                                    first = guard.part.low;
                                }
                                if (first != 1)
                                    goto pilot_assignment_linked_cancel553;
                                first = response[1];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(first) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = first;
                                    first = guard.part.low;
                                }
                                if (first == 0)
                                    goto pilot_assignment_linked_accept553;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(response) high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = response;
                                    response = guard.part.high;
                                }
                                goto pilot_assignment_linked_cancel553;
                            }
                        pilot_other_back_start553:
                        {
                            register u32 address asm("r0");
                            register s32 row asm("r1");
                            other = 3;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low;
                                        __typeof__(other) high;
                                    } part;
                                } guard asm("r4");
                                guard.part.high = other;
                                other = guard.part.high;
                            }
                            if ((s32)other == signed_slot)
                                goto pilot_other_back_next553;
                            {
                                register u8 *save asm("r1") = D_02000B5C;
                                register u32 offset asm("r3") = 0x360C;
                                asm("" : : "r"(save), "r"(offset));
                                address = (u32)save + offset;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(address) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                goto pilot_other_back_row553;
                            }
                        pilot_other_back_next553:
                        {
                            register u32 shifted asm("r0") = (u32)other << 16;
                            register u32 step asm("r4") = 0x10000;
                            asm("" : : "r"(shifted), "r"(step));
                            shifted += step;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        __typeof__(shifted) low;
                                        u32 high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = shifted;
                                shifted = guard.part.low;
                            }
                            other = shifted >> 16;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low;
                                        __typeof__(other) high;
                                    } part;
                                } guard asm("r4");
                                guard.part.high = other;
                                other = guard.part.high;
                            }
                            row = (s32)shifted >> 16;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low;
                                        __typeof__(row) high;
                                    } part;
                                } guard asm("r0");
                                guard.part.high = row;
                                row = guard.part.high;
                            }
                        }
                            if (row > 5)
                                goto pilot_other_back_done553;
                            address = (s32)slot_shift >> 16;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        __typeof__(address) low;
                                        u32 high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = address;
                                address = guard.part.low;
                            }
                            if (row == (s32)address)
                                goto pilot_other_back_next553;
                            address = (u32)row << 2;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        __typeof__(address) low;
                                        u32 high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = address;
                                address = guard.part.low;
                            }
                            {
                                register u8 *save asm("r7") = D_02000B5C;
                                register u32 offset asm("r1");
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(save) high;
                                        } part;
                                    } guard asm("r6");
                                    guard.part.high = save;
                                    save = guard.part.high;
                                }
                                address += (u32)save;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(address) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = address;
                                    address = guard.part.low;
                                }
                                offset = 0x3600;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(offset) high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = offset;
                                    offset = guard.part.high;
                                }
                                address += offset;
                            }
                        pilot_other_back_row553:
                            address = *(u8 *)address;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        __typeof__(address) low;
                                        u32 high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = address;
                                address = guard.part.low;
                            }
                            if (address == 255)
                                goto pilot_other_back_next553;
                        pilot_other_back_done553:;
                        }
                            if (other != 6)
                                goto pilot_assignment_back_linked553;
                            {
                                register s32 selected_slot asm("r0") = (s32)slot_shift >> 16;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            __typeof__(selected_slot) low;
                                            u32 high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = selected_slot;
                                    selected_slot = guard.part.low;
                                }
                                if (selected_slot == 4)
                                    goto pilot_assignment_done553;
                            }
                            {
                                register const u8 *script asm("r4") = D_0875B448;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(script) high;
                                        } part;
                                    } guard asm("r3");
                                    guard.part.high = script;
                                    script = guard.part.high;
                                }
                                func_0803E488(script, 4);
                                func_0803E488(script, 6);
                                func_0803E488(D_0875B068, 17);
                                func_0803E488(D_0875AFB8, 0);
                            }
                            {
                                register u16 *response asm("r1") = D_02007574;
                                register u32 first asm("r0");
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(response) high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = response;
                                    response = guard.part.high;
                                }
                                first = response[0];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = first;
                                    first = guard.part.low;
                                }
                                if (first != 1)
                                    goto pilot_assignment_solo_cancel553;
                                first = response[1];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = first;
                                    first = guard.part.low;
                                }
                                if (first != 0)
                                    goto pilot_assignment_solo_cancel553;
                            }
                            {
                                register s32 mask asm("r2") = 128;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r2");
                                    guard.part.low = mask;
                                    mask = guard.part.low;
                                }
                                mask = -mask;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r2");
                                    guard.part.low = mask;
                                    mask = guard.part.low;
                                }
                                record_bits = mask;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = record_bits;
                                    record_bits = guard.part.low;
                                }
                            }
                            goto pilot_assignment_record553;
                        pilot_assignment_solo_cancel553:
                            if (D_02007574[0] == 0)
                                func_080019EC(63);
                            {
                                register u16 *remembered asm("r3") = remembered_base;
                                register u32 cursor asm("r0");
                                register u16 *destination asm("r4");
                                asm("" : : "r"(remembered));
                                cursor = remembered[2];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = cursor;
                                    cursor = guard.part.low;
                                }
                                destination = pilot_stock_cursor;
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(destination) high;
                                        } part;
                                    } guard asm("r3");
                                    guard.part.high = destination;
                                    destination = guard.part.high;
                                }
                                *destination = cursor;
                            }
                            goto pilot_stock_open;
                        pilot_assignment_back_linked553:
                        {
                            register const u8 *script asm("r4") = D_0875B448;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low;
                                        __typeof__(script) high;
                                    } part;
                                } guard asm("r3");
                                guard.part.high = script;
                                script = guard.part.high;
                            }
                            func_0803E488(script, 4);
                            {
                                register u8 *entry asm("r5") = (*(u8 **)(formation_stack + 116));
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(entry) high;
                                        } part;
                                    } guard asm("r4");
                                    guard.part.high = entry;
                                    entry = guard.part.high;
                                }
                                func_08032818(*entry);
                            }
                            func_0803E488(script, 5);
                            func_0803E488(D_0875B068, 17);
                            func_0803E488(D_0875AFB8, 0);
                        }
                            {
                                register u16 *response asm("r1") = D_02007574;
                                register u32 first asm("r0");
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low;
                                            __typeof__(response) high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.high = response;
                                    response = guard.part.high;
                                }
                                first = response[0];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = first;
                                    first = guard.part.low;
                                }
                                if (first != 1)
                                    goto pilot_assignment_linked_cancel553;
                                first = response[1];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = first;
                                    first = guard.part.low;
                                }
                                if (first != 0)
                                    goto pilot_assignment_linked_cancel553;
                            }
                        pilot_assignment_linked_accept553:
                            record_bits = 64;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = record_bits;
                                record_bits = guard.part.low;
                            }
                        pilot_assignment_record553:
                            slot |= record_bits;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r6");
                                guard.part.low = slot;
                                slot = guard.part.low;
                            }
                            record_bits = (u8)slot;
                            {
                                register union
                                {
                                    unsigned long long whole;
                                    struct
                                    {
                                        u32 low, high;
                                    } part;
                                } guard asm("r0");
                                guard.part.low = record_bits;
                                record_bits = guard.part.low;
                            }
                            frame.field_4C = record_bits;
                            goto pilot_assignment_done553;
                        pilot_assignment_linked_cancel553:
                            if (D_02007574[0] == 0)
                                func_080019EC(63);
                            {
                                register u16 *remembered asm("r6") = remembered_base;
                                register u32 cursor asm("r0");
                                asm("" : : "r"(remembered));
                                cursor = remembered[2];
                                {
                                    register union
                                    {
                                        unsigned long long whole;
                                        struct
                                        {
                                            u32 low, high;
                                        } part;
                                    } guard asm("r0");
                                    guard.part.low = cursor;
                                    cursor = guard.part.low;
                                }
                                menu_pointer.cursor = pilot_stock_cursor;
                                asm("" : "+l"(menu_pointer.cursor) : "r"(cursor), "r"(remembered));
                                *menu_pointer.cursor = cursor;
                            }
                            goto pilot_stock_open;
                        pilot_assignment_done553:;
                        }
                    }
                    state = 0x320;
                }
                else if (action == 0)
                {
                    func_080019EC(63);
                    state = 0x301;
                }
                else
                {
                    {
                        register u32 linked asm("r1");
                        register u32 value asm("r0");
                        ((volatile u32)linked) = frame.linked_slot;
                        ((volatile u32)value) = (volatile u32)linked << 16;
                        ((volatile u32)value) = (s32)(volatile u32)value >> 16;
                        if ((s32)(volatile u32)value <= 86)
                        {
                            ((volatile u32)value) = (u8)(volatile u32)linked;
                            frame.first_item = (volatile u32)value;
                        }
                        else
                        {
                            register u32 none asm("r2") = 255;
                            asm("" : : "r"(none));
                            frame.first_item = none;
                        }
                    }
                    {
                        register u32 selected asm("r3") = frame.selected;
                        register u32 address asm("r0");
                        register u32 returning asm("r4");
                        asm("" : : "r"(selected));
                        ((volatile u32)address) = selected << 16;
                        ((volatile u32)address) = (s32)(volatile u32)address >> 16;
                        ((volatile u32)address) += (u32)pilot_stock_roster;
                        ((volatile u32)address) = *(u8 *)(volatile u32)address;
                        frame.second_item = (volatile u32)address;
                        ((volatile u32)returning) = 0x311;
                        asm("" : : "r"(returning));
                        frame.return_state = (volatile u32)returning;
                    }
                    state = 0x500;
                }
                func_0803E488(D_0875AFB8, 11);
                {
                    register u8 *address asm("r0");
                    register u32 flags asm("r1");
                    register u32 mask asm("r6");
                    register u32 bits asm("r2");
                    ((u8 *volatile)address) = D_03004BBC;
                    asm("" : "+r"(address));
                    ((u8 *volatile)address) += 0x88;
                    ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
                    ((volatile u32)mask) = 0x7FFF;
                    asm("" : "+r"(flags), "+r"(mask));
                    ((volatile u32)bits) = (volatile u32)mask;
                    asm("" : "+r"(bits));
                    ((volatile u32)flags) &= (volatile u32)bits;
                    *(u16 *)(u8 *volatile)address = (volatile u32)flags;
                }
                func_0803E488(D_0875AFB8, 9);
                func_0803E488(D_0875AFB8, 0);
            }
            break;
        }
        case 0x320:
        {
            register u8 *bonuses asm("r9");
            register u32 pilot_shift asm("r4");

            s32 base;
            register s32 bonus asm("r6");
            register s32 result asm("r10");
            u8 selected_zoid;
            register const u8 *separator asm("r4");
            register const u8 *results asm("r5");
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875B47C;
                func_0803E488((const u8 *volatile)message, 0);
            }
            {
                register u8 *roster asm("r1") = D_0200E5F0;
                register u32 loaded asm("r7");
                register u32 address asm("r0");
                asm("" : "+r"(roster));
                loaded = frame.field_30;
                asm("" : "+r"(loaded));
                pilot_shift = loaded << 16;
                asm("" : "+r"(pilot_shift));
                address = (s32)pilot_shift >> 16;
                asm("" : "+r"(address));
                address += (u32)roster;
                asm("" : "+r"(address));
                bonuses = func_080334F8(*(u8 *)address);
                asm("" : "+r"(bonuses));
            }
            {
                register u32 loaded asm("r1") = frame.linked_slot;
                register u32 shifted asm("r0");
                register s32 linked asm("r1");
                asm("" : "+r"(loaded));
                shifted = loaded << 16;
                asm("" : "+r"(shifted));
                linked = (s32)shifted >> 16;
                asm("" : "+r"(linked));
                (*(volatile u32 *)(formation_stack + 140)) = shifted;
                (*(u32 *)(formation_stack + 132)) = pilot_shift;
                if (linked != 87)
                {
                    register u8 *roster asm("r1") = D_0200E7F4;
                    register u32 loaded asm("r2");
                    register u32 shifted asm("r4");
                    register u32 address asm("r0");
                    register u32 entry asm("r1");
                    register u8 *stats asm("r3");
                    asm("" : "+r"(roster));
                    loaded = frame.selected;
                    asm("" : "+r"(loaded));
                    shifted = loaded << 16;
                    asm("" : "+r"(shifted));
                    address = (s32)shifted >> 16;
                    asm("" : "+r"(address));
                    address += (u32)roster;
                    asm("" : "+r"(address));
                    entry = *(u8 *)address;
                    {
                        register u32 argument asm("r0") = 255;
                        register u8 *destination asm("r2");
                        asm("" : : "r"(argument));
                        destination = (u8 *)formation_stack + 16;
                        asm("" : "+r"(destination));
                        func_08036C1C(argument, entry, destination);
                    }
                    (*(u32 *)(formation_stack + 136)) = shifted;
                    ((u8 *volatile)stats) = (u8 *)&frame.stats;
                    asm("" : : "r"(stats));
                    stats_base = (u8 *volatile)stats;
                    asm("" : "+r"(stats_base));
                }
                else
                {
                    register u8 *roster asm("r1") = D_0200E7F4;
                    register u32 loaded asm("r4");
                    register u32 shifted asm("r2");
                    register u32 address asm("r0");
                    register u32 entry asm("r1");
                    register u8 *save asm("r5");
                    register u32 offset asm("r6");
                    register u8 *stats asm("r5");
                    register struct MenuStats553 *destination asm("r1");
                    asm("" : "+r"(roster));
                    loaded = frame.selected;
                    asm("" : "+r"(loaded));
                    shifted = loaded << 16;
                    asm("" : "+r"(shifted));
                    address = (s32)shifted >> 16;
                    asm("" : "+r"(address));
                    address += (u32)roster;
                    asm("" : "+r"(address));
                    entry = *(u8 *)address;
                    asm("" : "+r"(entry));
                    address = entry * 56;
                    asm("" : "+r"(address));
                    save = D_02000B5C;
                    asm("" : "+r"(save));
                    address += (u32)save;
                    asm("" : "+r"(address));
                    ((struct MenuStats553 *volatile)destination) =
                        (struct MenuStats553 *)(formation_stack + 16);
                    asm("" : : "r"(destination));
                    offset = 0xD54;
                    asm("" : "+r"(offset));
                    address += offset;
                    asm("" : "+r"(address));
                    *destination = *(struct MenuStats553 *)address;
                    asm("" : : "r"(save), "r"(offset), "r"(shifted));
                    (*(u32 *)(formation_stack + 136)) = shifted;
                    ((u8 *volatile)stats) = (u8 *)&frame.stats;
                    asm("" : : "r"(stats));
                    stats_base = (u8 *volatile)stats;
                    asm("" : "+r"(stats_base));
                }
            }
            {
                register u8 *roster asm("r0") = D_0200E7F4;
                register s32 selected asm("r6");
                asm("" : : "r"(roster));
                selected = (*(u32 *)(formation_stack + 136));
                asm("" : "+r"(selected));
                selected >>= 16;
                asm("" : "+r"(selected));
                (*(s32 *)(formation_stack + 120)) = selected;
                roster = (u8 *)((u32)selected + (u32)roster);
                asm("" : "+r"(roster));
                (*(u8 **)(formation_stack + 124)) = roster;
            }
            {
                register u32 entry asm("r1") = *(*(u8 **)(formation_stack + 124));
                register u32 address asm("r0");
                register u32 offset asm("r1");
                asm("" : "+r"(entry));
                address = entry * 56;
                asm("" : "+r"(address));
                menu_pointer.save = D_02000B5C;
                asm("" : "+l"(menu_pointer.save));
                address += (u32)menu_pointer.save;
                asm("" : "+r"(address));
                offset = 0xD32;
                asm("" : "+r"(offset));
                address += offset;
                func_08032800(*(u16 *)address);
            }
            {
                register u8 *entry_address asm("r2") = (*(u8 **)(formation_stack + 124));
                register u32 entry asm("r1");
                register u32 address asm("r0");
                register u32 offset asm("r3");
                register u32 rank asm("r1");
                asm("" : "+r"(entry_address));
                entry = *entry_address;
                asm("" : "+r"(entry));
                address = entry * 56;
                asm("" : "+r"(address));
                address += (u32)menu_pointer.save;
                asm("" : "+r"(address));
                offset = 0xD61;
                asm("" : "+r"(offset));
                address += offset;
                asm("" : "+r"(address));
                rank = *(u8 *)address;
                asm("" : "+r"(rank));
                rank += 8;
                asm("" : "+r"(rank));
                func_0803E488(D_0875B0F8, rank);
            }
            separator = D_08675C5C;
            asm("" : "+r"(separator));
            func_0803E488(separator, 0);
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875B47C;
                func_0803E488((const u8 *volatile)message, 1);
            }
            base = frame.stats.hp;
            {
                register u8 *bonus_base asm("r5") = bonuses;
                register u32 held1 asm("r1");
                asm("" : "=r"(held1) : "r"(bonus_base));
                bonus = *(s16 *)(bonus_base + 4);
                asm("" : : "r"(bonus), "r"(held1));
            }
            result = base + func_080346C0(base, bonus);
            asm("" : : "r"(result));
            func_08001848(base, 5, 0);
            func_08001848(bonus, 5, 0);
            func_0803E488(D_0875AFB8, 39);
            results = D_0875B1F0;
            asm("" : "+r"(results));
            func_0803E488(results, 6);
            func_08001848(result, 5, 0);
            func_0803E488(separator, 0);
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875B47C;
                func_0803E488((const u8 *volatile)message, 2);
            }
            {
                register const struct MenuStats553 *stats asm("r1") =
                    (const struct MenuStats553 *)stats_base;
                asm("" : "+r"(stats));
                base = (s32)stats->ep;
            }
            func_08001848(base, 5, 0);
            func_0803E488(D_0875AFB8, 42);
            func_0803E488(D_0875AFB8, 42);
            func_0803E488(D_0875AFB8, 42);
            func_0803E488(D_0875AFB8, 42);
            func_0803E488(D_0875AFB8, 42);
            func_0803E488(D_0875AFB8, 42);
            func_0803E488(results, 6);
            func_08001848(base, 5, 0);
            func_0803E488(separator, 0);
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875B47C;
                func_0803E488((const u8 *volatile)message, 3);
            }
            {
                register const u8 *stats asm("r2") = stats_base;
                register u32 held0 asm("r0");
                register u32 held1 asm("r1");
                asm("" : "=r"(held0), "=r"(held1) : "r"(stats));
                base = *(s16 *)(stats + 8);
                asm("" : : "r"(base), "r"(held0), "r"(held1));
            }
            {
                register u8 *bonus_base asm("r0") = bonuses;
                asm("" : : "r"(bonus_base));
                bonus = *(s16 *)(bonus_base + 6);
                asm("" : : "r"(bonus));
            }
            result = base + func_080346C0(base, bonus);
            asm("" : : "r"(result));
            func_08001848(base, 5, 0);
            func_08001848(bonus, 5, 0);
            func_0803E488(D_0875AFB8, 39);
            func_0803E488(results, 6);
            func_08001848(result, 5, 0);
            func_0803E488(separator, 0);
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875B47C;
                func_0803E488((const u8 *volatile)message, 4);
            }
            {
                register const u8 *stats asm("r2") = stats_base;
                register u32 held0 asm("r0");
                register u32 held1 asm("r1");
                asm("" : "=r"(held0), "=r"(held1) : "r"(stats));
                base = *(s16 *)(stats + 10);
                asm("" : : "r"(base), "r"(held0), "r"(held1));
            }
            {
                register u8 *bonus_base asm("r4") = bonuses;
                asm("" : : "r"(bonus_base));
                bonus = *(s16 *)(bonus_base + 8);
                asm("" : : "r"(bonus));
            }
            result = base + func_080346C0(base, bonus);
            asm("" : : "r"(result));
            func_08001848(base, 4, 0);
            func_0803E488(D_0875AFB8, 39);
            func_08001848(bonus, 5, 0);
            func_0803E488(D_0875AFB8, 39);
            func_0803E488(results, 6);
            func_08001848(result, 4, 0);
            func_0803E488(D_0875AFB8, 39);
            {
                register u8 *entry_address asm("r2") = (*(u8 **)(formation_stack + 124));
                register u32 entry asm("r1");
                register u32 address asm("r0");
                register u8 *save asm("r3");
                register u32 offset asm("r4");
                asm("" : : "r"(entry_address));
                entry = *entry_address;
                asm("" : : "r"(entry));
                address = entry * 56;
                asm("" : : "r"(address));
                save = D_02000B5C;
                asm("" : : "r"(save));
                address += (u32)save;
                asm("" : : "r"(address));
                offset = 0xD32;
                asm("" : : "r"(offset));
                address += offset;
                func_0804D654(*(u16 *)address, 40, 88);
            }
            asm("" : : "g"((*(s32 *)(formation_stack + 120))));
            {
                register const u8 *message asm("r0");
                ((const u8 *volatile)message) = D_0875B47C;
                func_0803E488((const u8 *volatile)message, 5);
            }
            do
                func_0803E488(D_0875AFB8, 38);
            while (D_02007574[0] > 1 && D_02007574[0] != 128);
            if (D_02007574[0] == 128)
                goto pilot_detail_inspect553;
            {
                func_080019EC(65);
                {
                    register const u8 *message asm("r0");
                    ((const u8 *volatile)message) = D_0875B47C;
                    func_0803E488((const u8 *volatile)message, 6);
                }
                func_0803E488(D_0875B068, 17);
                if (D_02007574[0] == 1)
                {
                    if (D_02007574[1] == 0)
                    {
                        register u32 old_zoid asm("r7");
                        register u32 active_part asm("r6");
                        {
                            register u8 *roster asm("r1") = D_0200E5F0;
                            register u32 cached_pilot asm("r5");
                            register u32 address asm("r0");
                            register u8 *save asm("r6");
                            register u32 offset asm("r7");
                            register u32 selected asm("r1");
                            asm("" : : "r"(roster));
                            cached_pilot = *(u32 *)(formation_stack + 132);
                            asm("" : : "r"(cached_pilot));
                            address = (s32)cached_pilot >> 16;
                            asm("" : : "r"(address));
                            address += (u32)roster;
                            asm("" : : "r"(address));
                            address = *(u8 *)address;
                            asm("" : : "r"(address));
                            address <<= 2;
                            asm("" : : "r"(address));
                            save = D_02000B5C;
                            asm("" : : "r"(save));
                            address += (u32)save;
                            asm("" : : "r"(address));
                            offset = 0x34A6;
                            asm("" : : "r"(offset));
                            address += offset;
                            asm("" : : "r"(address));
                            old_zoid = *(u8 *)address;
                            asm("" : : "r"(old_zoid));
                            selected = old_zoid;
                            asm("" : : "r"(selected));
                            active_part = 3;
                            asm("" : : "r"(active_part));
                            if (selected == 255)
                                goto pilot_detail_parts_scanned553;
                            {
                                register u8 *part_base asm("r2");
                                register u8 *parts asm("r3");
                                register u32 empty asm("r4");
                                register u32 mask asm("r8");
                                active_part = 0;
                                asm("" : : "r"(active_part));
                                part_base = D_02001898;
                                asm("" : : "r"(part_base));
                                address = selected * 56;
                                asm("" : : "r"(address));
                                parts = (u8 *)(address + (u32)part_base);
                                asm("" : : "r"(parts));
                                empty = 0xFFFF;
                                asm("" : : "r"(empty));
                                address = 3;
                                asm("" : : "r"(address));
                                mask = address;
                                asm("" : : "r"(mask));
                            pilot_detail_part_scan553:
                            {
                                register s32 signed_part asm("r2");
                                register u16 *part asm("r5");
                                register u32 flags asm("r1");
                                address = active_part << 16;
                                asm("" : : "r"(address));
                                signed_part = (s32)address >> 16;
                                asm("" : : "r"(signed_part));
                                address = (u32)signed_part << 2;
                                asm("" : : "r"(address));
                                part = (u16 *)((u32)parts + address);
                                asm("" : : "r"(part));
                                address = part[1];
                                asm("" : : "r"(address));
                                if (address == empty)
                                    goto pilot_detail_part_scan_next553;
                                flags = part[0];
                                asm("" : : "r"(flags));
                                address = mask;
                                asm("" : : "r"(address));
                                address &= flags;
                                asm("" : : "r"(address));
                                if (address != 0)
                                    goto pilot_detail_parts_scanned553;
                            pilot_detail_part_scan_next553:
                                address = signed_part + 1;
                                asm("" : : "r"(address));
                                address <<= 16;
                                asm("" : : "r"(address));
                                active_part = address >> 16;
                                asm("" : : "r"(active_part));
                                address = (s32)address >> 16;
                                asm("" : : "r"(address));
                                if ((s32)address <= 2)
                                    goto pilot_detail_part_scan553;
                            }
                            }
                        }
                    pilot_detail_parts_scanned553:
                    {
                        register const u8 *message asm("r0");
                        register u32 selector asm("r1");
                        if (active_part != 3)
                            goto pilot_detail_remove_prompt553;
                        message = D_0875B47C;
                        asm("" : : "r"(message));
                        selector = 7;
                        asm("" : : "r"(selector));
                        goto pilot_detail_remove_message553;
                    pilot_detail_remove_prompt553:
                    {
                        register u8 *flags_address asm("r2") = D_03004BBC;
                        register u32 flags asm("r0");
                        register u32 mask asm("r3");
                        register u32 bits asm("r1");
                        register const u8 *script asm("r4");
                        asm("" : : "r"(flags_address));
                        flags_address += 0x88;
                        asm("" : : "r"(flags_address));
                        flags = *(u16 *)flags_address;
                        asm("" : : "r"(flags));
                        mask = 0x7FFF;
                        asm("" : : "r"(mask));
                        bits = mask;
                        asm("" : : "r"(bits));
                        flags &= bits;
                        *(u16 *)flags_address = flags;
                        func_0803E488(D_0875AFB8, 9);
                        script = D_0875B47C;
                        asm("" : : "r"(script));
                        func_0803E488(script, 8);
                        func_0803E488(D_0875B068, 18);
                        {
                            register u16 *response asm("r0") = D_02007574;
                            asm("" : : "r"(response));
                            flags = response[1];
                            asm("" : : "r"(flags));
                            if (flags != 0)
                                goto pilot_detail_check_inventory553;
                        }
                        message = script;
                        asm("" : : "r"(message));
                        selector = 9;
                        asm("" : : "r"(selector));
                    }
                    pilot_detail_remove_message553:
                        func_0803E488(message, selector);
                        old_zoid <<= 16;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r6");
                            guard.part.high = old_zoid;
                            old_zoid = guard.part.high;
                        }
                        goto pilot_detail_detach553;
                    }
                    pilot_detail_check_inventory553:
                    {
                        register s32 unit asm("r4");
                        register u8 *parts_base asm("r9");
                        register u8 *inventory asm("r10");
                        register const u8 *part_messages asm("r8");
                        register u32 address asm("r0");
                        register u8 *base_address asm("r2");
                        register u32 offset asm("r5");
                        active_part = 0;
                        asm("" : : "r"(active_part));
                        old_zoid <<= 16;
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r6");
                            guard.part.high = old_zoid;
                            old_zoid = guard.part.high;
                        }
                        unit = (s32)old_zoid >> 16;
                        asm("" : : "r"(unit));
                        base_address = D_02001898;
                        asm("" : : "r"(base_address));
                        parts_base = base_address;
                        asm("" : : "r"(parts_base));
                        offset = 0x2610;
                        asm("" : : "r"(offset));
                        offset += (u32)parts_base;
                        asm("" : : "r"(offset));
                        inventory = (u8 *)offset;
                        asm("" : : "r"(inventory));
                        address = (u32)D_0875B1F0;
                        asm("" : : "r"(address));
                        part_messages = (const u8 *)address;
                        asm("" : : "r"(part_messages));
                    pilot_detail_inventory_check553:
                    {
                        register u32 index asm("r1");
                        register u16 *part asm("r5");
                        address = unit * 56;
                        asm("" : : "r"(address));
                        address += (u32)parts_base;
                        asm("" : : "r"(address));
                        index = active_part << 16;
                        asm("" : : "r"(index));
                        index = (s32)index >> 14;
                        asm("" : : "r"(index));
                        part = (u16 *)(address + index);
                        asm("" : : "r"(part));
                        address = part[1];
                        asm("" : : "r"(address));
                        index = 0xFFFF;
                        asm("" : : "r"(index));
                        if (address == index)
                            goto pilot_detail_inventory_next553;
                        index = part[0];
                        asm("" : : "r"(index));
                        address = 3;
                        asm("" : : "r"(address));
                        address &= index;
                        asm("" : : "r"(address));
                        if (address == 0)
                            goto pilot_detail_inventory_next553;
                        address = part[1];
                        asm("" : : "r"(address));
                        address += (u32)inventory;
                        asm("" : : "r"(address));
                        address = *(u8 *)address;
                        asm("" : : "r"(address));
                        if (address <= 8)
                            goto pilot_detail_inventory_next553;
                        func_0803E488(D_0875AFB8, 0);
                        func_0803E488(D_0875AFB8, 25);
                        func_0803E488(part_messages, 7);
                        func_0803E488(D_0866634C, part[1]);
                        func_0803E488(part_messages, 8);
                        func_0803E488(D_0875B068, 18);
                        {
                            register u16 *response asm("r0") = D_02007574;
                            asm("" : : "r"(response));
                            address = response[1];
                            asm("" : : "r"(address));
                            if (address != 0)
                                goto pilot_detail_inventory_checked553;
                        }
                    pilot_detail_inventory_next553:
                    {
                        register u32 step asm("r2");
                        asm("" : "+r"(active_part));
                        address = active_part << 16;
                        asm("" : "+r"(address));
                        step = 0x10000;
                        asm("" : : "r"(step));
                        address += step;
                        asm("" : : "r"(address));
                        active_part = address >> 16;
                        asm("" : : "r"(active_part));
                        address = (s32)address >> 16;
                        asm("" : : "r"(address));
                        if ((s32)address <= 2)
                            goto pilot_detail_inventory_check553;
                    }
                    }
                    pilot_detail_inventory_checked553:
                        if (active_part != 3)
                            goto pilot_detail_inventory_cancel553;
                        {
                            register u8 *base_address asm("r2");
                            register const u8 *message_address asm("r3");
                            register const u8 *messages asm("r9");
                            register s32 unit asm("r1");
                            register u8 *parts asm("r4");
                            register u8 *inventory_address asm("r5");
                            register u8 *inventory asm("r8");
                            register u32 empty asm("r3");
                            active_part = 0;
                            asm("" : : "r"(active_part));
                            base_address = D_02001898;
                            asm("" : : "r"(base_address));
                            message_address = D_0875B47C;
                            asm("" : : "r"(message_address));
                            messages = message_address;
                            asm("" : : "r"(messages));
                            unit = (s32)old_zoid >> 16;
                            asm("" : : "r"(unit));
                            address = unit * 56;
                            asm("" : : "r"(address));
                            parts = (u8 *)(address + (u32)base_address);
                            asm("" : : "r"(parts));
                            inventory_address = (u8 *)0x2610;
                            asm("" : : "r"(inventory_address));
                            inventory_address += (u32)base_address;
                            asm("" : : "r"(inventory_address));
                            inventory = inventory_address;
                            asm("" : : "r"(inventory));
                            empty = 0xFFFF;
                            asm("" : : "r"(empty));
                        pilot_detail_return_part553:
                        {
                            register u32 index asm("r1");
                            register u32 shifted asm("r2");
                            register u16 *part asm("r5");
                            address = active_part << 16;
                            asm("" : : "r"(address));
                            index = (s32)address >> 14;
                            asm("" : : "r"(index));
                            part = (u16 *)((u32)parts + index);
                            asm("" : : "r"(part));
                            index = part[1];
                            asm("" : : "r"(index));
                            shifted = address;
                            asm("" : : "r"(shifted));
                            if (index == empty)
                                goto pilot_detail_return_next553;
                            index = part[0];
                            asm("" : : "r"(index));
                            address = 3;
                            asm("" : : "r"(address));
                            address &= index;
                            asm("" : : "r"(address));
                            if (address == 0)
                                goto pilot_detail_return_next553;
                            address = part[1];
                            asm("" : : "r"(address));
                            {
                                register u8 *inventory_base asm("r6") = inventory;
                                asm("" : : "r"(inventory_base));
                                index = address + (u32)inventory_base;
                            }
                            asm("" : : "r"(index));
                            address = *(u8 *)index;
                            asm("" : : "r"(address));
                            if (address > 8)
                                goto pilot_detail_return_clear553;
                            address++;
                            *(u8 *)index = address;
                        pilot_detail_return_clear553:
                            index = part[1];
                            asm("" : : "r"(index));
                            address = empty;
                            asm("" : : "r"(address));
                            address |= index;
                            part[1] = address;
                        pilot_detail_return_next553:
                            index = 0x10000;
                            asm("" : : "r"(index));
                            address = shifted + index;
                            asm("" : : "r"(address));
                            active_part = address >> 16;
                            asm("" : : "r"(active_part));
                            address = (s32)address >> 16;
                            asm("" : : "r"(address));
                            if ((s32)address <= 2)
                                goto pilot_detail_return_part553;
                        }
                            func_0803E488(messages, 10);
                            goto pilot_detail_detach553;
                        }
                    pilot_detail_inventory_cancel553:
                        func_0803E488(D_0875B47C, 9);
                    }
                    pilot_detail_detach553:
                    {
                        register u32 flags asm("r2") = frame.field_4C;
                        register u32 argument asm("r0");
                        asm("" : : "r"(flags));
                        if (flags == 0)
                            goto pilot_detail_detach_pilot553;
                        argument = 0x3F;
                        asm("" : : "r"(argument));
                        argument &= flags;
                        func_080371C4(argument);
                    }
                    pilot_detail_detach_pilot553:
                    {
                        register s32 selected asm("r0") = (s32)old_zoid >> 16;
                        asm("" : : "r"(selected));
                        if (selected == 255)
                            goto pilot_detail_detach_linked553;
                        {
                            register u8 *roster asm("r0") = D_0200E5F0;
                            register u32 cached asm("r3");
                            register u8 *entry asm("r1");
                            asm("" : : "r"(roster));
                            cached = *(u32 *)(formation_stack + 132);
                            asm("" : : "r"(cached));
                            entry = (u8 *)((s32)cached >> 16);
                            asm("" : : "r"(entry));
                            entry += (u32)roster;
                            func_08036B98(*entry);
                        }
                    }
                    pilot_detail_detach_linked553:
                    {
                        register u32 cached asm("r4") = *(volatile u32 *)(formation_stack + 140);
                        register s32 linked asm("r0");
                        asm("" : : "r"(cached));
                        linked = (s32)cached >> 16;
                        asm("" : : "r"(linked));
                        if (linked == 87)
                            goto pilot_detail_assign553;
                        {
                            register u32 selected asm("r5") = frame.linked_slot;
                            register u32 pilot asm("r0");
                            asm("" : : "r"(selected));
                            pilot = (u8)selected;
                            func_08036B98(pilot);
                        }
                    }
                    pilot_detail_assign553:
                    {
                        register u8 *assigned_pilot asm("r6");
                        register u8 *assigned_unit asm("r5");
                        register u8 *pilot_roster asm("r1") = D_0200E5F0;
                        register u32 pilot_cache asm("r6");
                        register u32 pilot_index asm("r0");
                        register u8 *unit_roster asm("r2");
                        register u32 unit_cache asm("r7");
                        register u32 unit_index asm("r1");
                        asm("" : : "r"(pilot_roster));
                        pilot_cache = *(u32 *)(formation_stack + 132);
                        asm("" : : "r"(pilot_cache));
                        pilot_index = (s32)pilot_cache >> 16;
                        asm("" : : "r"(pilot_index));
                        assigned_pilot = (u8 *)(pilot_index + (u32)pilot_roster);
                        asm("" : : "r"(assigned_pilot));
                        pilot_index = *assigned_pilot;
                        asm("" : : "r"(pilot_index));
                        unit_roster = D_0200E7F4;
                        asm("" : : "r"(unit_roster));
                        unit_cache = *(u32 *)(formation_stack + 136);
                        {
                            register union
                            {
                                unsigned long long whole;
                                struct
                                {
                                    u32 low, high;
                                } part;
                            } guard asm("r6");
                            guard.part.high = unit_cache;
                            unit_cache = guard.part.high;
                        }
                        unit_index = (s32)unit_cache >> 16;
                        asm("" : : "r"(unit_index));
                        assigned_unit = (u8 *)(unit_index + (u32)unit_roster);
                        asm("" : : "r"(assigned_unit));
                        unit_index = *assigned_unit;
                        func_08036B4C(pilot_index, unit_index);
                        {
                            register u32 mask asm("r0") = 0xC0;
                            register u32 flags asm("r1");
                            register u32 rank asm("r4");
                            asm("" : : "r"(mask));
                            flags = frame.field_4C;
                            asm("" : : "r"(flags));
                            mask &= flags;
                            asm("" : : "r"(mask));
                            if (mask != 0x80)
                                goto pilot_detail_assigned553;
                            rank = 0x3F;
                            asm("" : : "r"(rank));
                            rank &= flags;
                            asm("" : : "r"(rank));
                            mask = 0xC1;
                            asm("" : : "r"(mask));
                            mask = -mask;
                            asm("" : : "r"(mask));
                            mask &= flags;
                            rank -= func_0805D3B4(mask, 3);
                            asm("" : : "r"(rank));
                            rank++;
                            asm("" : : "r"(rank));
                            rank = (u8)rank;
                            asm("" : : "r"(rank));
                            {
                                register u32 pilot asm("r1") = *assigned_pilot;
                                register u32 unit asm("r0");
                                register u32 info asm("r2");
                                asm("" : : "r"(pilot));
                                unit = *assigned_unit;
                                asm("" : : "r"(unit));
                                info = unit * 56;
                                asm("" : : "r"(info));
                                unit = (u32)(D_02000B5C + 0xD2C);
                                asm("" : : "r"(unit));
                                info += unit;
                                func_08037118(rank, pilot, (u8 *)info);
                            }
                        }
                    }
                    pilot_detail_assigned553:
                    }
                    state = 0x301;
                }
                else
                {
                    func_080019EC(63);
                    state = 0x311;
                }
            }
            goto pilot_detail_finish553;
        pilot_detail_inspect553:
        {
            register u8 *roster asm("r1") = D_0200E5F0;
            register u32 pilot_cache asm("r2");
            register u32 address asm("r0");
            register u32 unit_cache asm("r3");
            register u32 returning asm("r4");
            asm("" : : "r"(roster));
            pilot_cache = *(u32 *)(formation_stack + 132);
            asm("" : : "r"(pilot_cache));
            address = (s32)pilot_cache >> 16;
            asm("" : : "r"(address));
            address += (u32)roster;
            asm("" : : "r"(address));
            address = *(u8 *)address;
            frame.first_item = address;
            roster = D_0200E7F4;
            asm("" : : "r"(roster));
            unit_cache = *(u32 *)(formation_stack + 136);
            asm("" : : "r"(unit_cache));
            address = (s32)unit_cache >> 16;
            asm("" : : "r"(address));
            address += (u32)roster;
            asm("" : : "r"(address));
            address = *(u8 *)address;
            frame.second_item = address;
            returning = 0x320;
            asm("" : : "r"(returning));
            frame.return_state = returning;
            state = 0x510;
        }
        pilot_detail_finish553:

        {
            register u8 *address asm("r0");
            register u32 flags asm("r1");
            register u32 mask asm("r6");
            register u32 bits asm("r2");
            ((u8 *volatile)address) = D_03004BBC;
            asm("" : "+r"(address));
            ((u8 *volatile)address) += 0x88;
            ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
            ((volatile u32)mask) = 0x7FFF;
            asm("" : "+r"(flags), "+r"(mask));
            ((volatile u32)bits) = (volatile u32)mask;
            asm("" : "+r"(bits));
            ((volatile u32)flags) &= (volatile u32)bits;
            *(u16 *)(u8 *volatile)address = (volatile u32)flags;
        }
            func_0803E488(D_0875AFB8, 9);
            func_0803E488(D_0875AFB8, 0);
            break;
        }
        case 0x400:
            func_0803E488(D_0875AFB8, 11);
            func_0803E488(D_0875AFB8, 10);
            func_0803E488(D_0875AFB8, 9);
            func_0803E488(D_0875AFB8, 0);
            func_0803E488(D_0875B448, 0);
            {
                register u32 initial_page asm("r7");
                ((volatile u32)initial_page) = 0;
                frame.page = (volatile u32)initial_page;
                D_02007588 = (volatile u32)initial_page;
            }
            state = 0x402;
            break;
        case 0x401:
            func_0803E488(D_0875B448, 0);
            {
                register u16 *remembered asm("r1");
                register u32 selection asm("r0");
                register u16 *details asm("r0");
                ((u16 *volatile)remembered) = remembered_base;
                ((volatile u32)selection) = ((u16 *volatile)remembered)[2];
                {
                    register u8 *cached_selection asm("r2");
                    register u16 *cursor asm("r3");
                    ((u8 *volatile)cached_selection) = &D_02007FA9;
                    *(u8 *volatile)cached_selection = (volatile u32)selection;
                    ((volatile u32)selection) = (u8)(volatile u32)selection;
                    ((u16 *volatile)cursor) = &D_02007588;
                    *(u16 *volatile)cursor = (volatile u32)selection;
                }
                ((u16 *volatile)details) = frame.detail;
                asm("" : "+r"(details));
                frame.page = ((u16 *volatile)details)[2];
            }
        case 0x402:
        {
            register u32 previous_shift asm("r8");
            register u32 sale_page_shift asm("r5");
            register u32 previous_page_shift asm("r0");
            {
                register u32 previous asm("r4");
                register u32 refresh asm("r5");
                ((volatile u32)previous) = 0xFFFF;
                frame.previous_selected = (volatile u32)previous;
                frame.previous_page = (volatile u32)previous;
                ((volatile u32)refresh) = 0;
                frame.refresh = (volatile u32)refresh;
            }
            {
                register u8 *details asm("r6");
                ((u8 *volatile)details) = (u8 *)&frame;
                asm("" : "+r"(details));
                ((u8 *volatile)details) = (u8 *volatile)details + 8;
                (*(u16 **)(formation_stack + 128)) = (u16 *)(u8 *volatile)details;
            }
        zoid_sale_open:
            func_0805506C(255);
            func_0803E488(D_0875AFB8, 25);
            func_0803E488(D_0875B4AC, 0);
            func_0803E488(D_0875AFB8, 28);
            {
                register u32 active asm("r7");
                ((volatile u32)active) = 1;
                frame.active = (volatile u32)active;
            }
        zoid_sale_update:
        {
            register u32 loaded asm("r0");
            register u32 previous_page asm("r1");
            register u32 refresh asm("r2");
            register u32 previous_selected asm("r3");
            ((volatile u32)loaded) = frame.page;
            ((volatile u32)sale_page_shift) = (volatile u32)loaded << 16;
            ((volatile u32)previous_page) = frame.previous_page;
            ((volatile u32)previous_page_shift) = (volatile u32)previous_page << 16;
            ((volatile u32)refresh) = frame.refresh;
            if ((volatile u32)refresh)
                goto zoid_sale_redraw;
            ((volatile u32)previous_selected) = frame.previous_selected;
            ((volatile u32)previous_selected) = (volatile u32)previous_selected << 16;
            ((volatile u32)previous_shift) = (volatile u32)previous_selected;
            if ((volatile u32)sale_page_shift == (volatile u32)previous_page_shift)
                goto zoid_sale_selected;
        }
        zoid_sale_redraw:
        {
            register u32 shown asm("r6");
            register s32 page asm("r5");
            u8 *limit;
            u8 *save;
            u8 *cursor_byte;
            register u8 *count_address asm("r12");
            {
                register s32 previous_page asm("r0");
                register s32 none asm("r4");
                ((volatile s32)previous_page) = (s32)(volatile u32)previous_page_shift >> 16;
                ((volatile s32)none) = 1;
                ((volatile s32)none) = -(volatile s32)none;
                if ((volatile s32)previous_page != (volatile s32)none)
                    func_0803E488(D_0875AFB8, 3);
            }
            {
                register u8 *initial asm("r6");
                ((u8 *volatile)initial) = &D_0200E8A1;
                asm("" : "+r"(initial));
                ((u8 *volatile)count_address) = (u8 *volatile)initial;
            }
            {
                register u32 previous_selected asm("r7");
                ((volatile u32)previous_selected) = frame.previous_selected;
                ((volatile u32)previous_selected) = (volatile u32)previous_selected << 16;
                asm("" : "+r"(previous_selected));
                ((volatile u32)previous_shift) = (volatile u32)previous_selected;
            }
            {
                register u8 *address asm("r3") = &D_02007FA9;
                asm("" : "+r"(address));
                cursor_byte = address;
                asm("" : "+r"(cursor_byte));
            }
        zoid_sale_page:
        {
            register s32 signed_page asm("r1");
            register u32 first_row asm("r0");
            register u32 stored_row asm("r2");
            register u32 bound asm("r4");
            ((volatile u32)shown) = 0;
            ((volatile s32)signed_page) = (s32)(volatile u32)sale_page_shift >> 16;
            asm("" : "+r"(signed_page));
            ((volatile u32)first_row) = (volatile s32)signed_page * 6;
            ((volatile u32)first_row) = (volatile u32)first_row << 16;
            ((volatile u32)stored_row) = (volatile u32)first_row >> 16;
            frame.row = (volatile u32)stored_row;
            ((volatile u32)first_row) = (s32)(volatile u32)first_row >> 16;
            {
                register u8 *address asm("r4");
                ((u8 *volatile)address) = (u8 *volatile)count_address;
                asm("" : "+r"(address));
                ((volatile u32)bound) = *(u8 *volatile)address;
                asm("" : "+r"(bound));
            }
            if ((s32)(volatile u32)first_row < (s32)(volatile u32)bound)
            {
                register s32 signed_row asm("r0");
                {
                    register u8 *base asm("r2") = D_02000B5C;
                    asm("" : "+r"(base));
                    save = base;
                    asm("" : "+r"(save));
                }
                limit = &D_0200E8A1;
                asm("" : "+r"(limit));
                page = (volatile s32)signed_page;
                asm("" : "+r"(page));
            zoid_sale_row:
            {
                register s32 row_index asm("r4");
                register u32 loaded asm("r1");
                register u32 shifted asm("r0");
                register s32 signed_shown asm("r0");
                u8 entry;
                ((volatile u32)loaded) = frame.row;
                ((volatile u32)shifted) = (volatile u32)loaded << 16;
                ((volatile s32)row_index) = (s32)(volatile u32)shifted >> 16;
                asm("" : : "r"(row_index), "r"(save), "r"(cursor_byte), "r"(limit));
                {
                    register u8 *roster asm("r1") = D_0200E7F4;
                    register u32 address asm("r0");
                    register u32 loaded_entry asm("r1");
                    asm("" : : "r"(roster));
                    address = row_index + (u32)roster;
                    asm("" : : "r"(address));
                    loaded_entry = *(u8 *)address;
                    asm("" : : "r"(loaded_entry));
                    address = loaded_entry * 56;
                    func_08032800(*(u16 *)(address + (u32)save + 0xD32));
                }
                ((volatile s32)signed_shown) = (s32)(shown << 16) >> 16;
                asm("" : "+r"(limit) : "r"(save), "r"(cursor_byte), "r"(signed_shown));
                if ((volatile s32)signed_shown <= 4 && row_index < *limit - 1)
                {
                    func_0803E488(D_08675C5C, 0);
                    asm("" : : "r"(cursor_byte));
                    asm("" : : "r"(save));
                }
                {
                    register u32 shifted asm("r0") = shown << 16;
                    register u32 step asm("r4") = 0x10000;
                    register s32 next asm("r1");
                    asm("" : : "r"(shifted), "r"(step));
                    shifted += step;
                    asm("" : : "r"(shifted));
                    shown = shifted >> 16;
                    asm("" : : "r"(shown));
                    next = (s32)shifted >> 16;
                    asm("" : : "r"(next));
                    {
                        register u8 *address asm("r0");
                        ((u8 *volatile)address) = &D_0200E8A1;
                        asm("" : "+r"(address));
                        ((u8 *volatile)count_address) = (u8 *volatile)address;
                    }
                    if (next > 5)
                        goto zoid_sale_rows_done;
                    ((volatile u32)shifted) = page * 6;
                    ((volatile u32)shifted) = next + (volatile u32)shifted;
                    ((volatile u32)shifted) = (volatile u32)shifted << 16;
                    next = (volatile u32)shifted >> 16;
                    frame.row = next;
                    ((volatile s32)signed_row) = (s32)(volatile u32)shifted >> 16;
                }
                {
                    register s32 count asm("r4");
                    ((volatile s32)count) = *limit;
                    asm("" : "+r"(count));
                    if ((volatile s32)signed_row < (volatile s32)count)
                        goto zoid_sale_row;
                }
            }
            }
        }
        zoid_sale_rows_done:
        {
            register s32 signed_shown asm("r0");
            ((volatile s32)signed_shown) = (s32)(shown << 16) >> 16;
            asm("" : "+r"(signed_shown));
            if (signed_shown != 0)
                goto zoid_sale_adjust_cursor553;
            {
                register u32 loaded_page asm("r5") = frame.page;
                register u32 shifted asm("r0");
                register u32 decrement asm("r6");
                register u32 page_shift asm("r1");
                register s32 none asm("r2");
                asm("" : : "r"(loaded_page));
                shifted = loaded_page << 16;
                asm("" : : "r"(shifted));
                decrement = 0xFFFF0000;
                asm("" : : "r"(decrement));
                shifted += decrement;
                asm("" : : "r"(shifted));
                shifted >>= 16;
                asm("" : : "r"(shifted));
                frame.page = shifted;
                page_shift = shifted << 16;
                asm("" : : "r"(page_shift));
                shifted = (s32)page_shift >> 16;
                asm("" : : "r"(shifted));
                menu_pointer.save = D_020075A0;
                asm("" : "+l"(menu_pointer.save));
                none = 1;
                asm("" : : "r"(none));
                none = -none;
                asm("" : : "r"(none));
                if ((s32)shifted == none)
                    goto zoid_sale_page_flags553;
                shifted = 5;
                asm("" : : "r"(shifted));
                *cursor_byte = shifted;
                {
                    register u16 *cursor asm("r4") = &D_02007588;
                    asm("" : : "r"(cursor));
                    *cursor = shifted;
                }
                sale_page_shift = page_shift;
                asm("" : : "r"(sale_page_shift));
                goto zoid_sale_page;
            }
        zoid_sale_adjust_cursor553:
        {
            register u16 *cursor asm("r2") = &D_02007588;
            register u32 selected asm("r5");
            asm("" : : "r"(cursor));
            menu_pointer.save = D_020075A0;
            asm("" : "+l"(menu_pointer.save));
            selected = *cursor;
            asm("" : : "r"(selected));
            if (signed_shown > (s32)selected)
                goto zoid_sale_page_flags553;
            signed_shown = shown - 1;
            asm("" : : "r"(signed_shown));
            *cursor_byte = signed_shown;
            signed_shown = (u8)signed_shown;
            asm("" : : "r"(signed_shown));
            *cursor = signed_shown;
        }
        zoid_sale_page_flags553:
        {
            register u32 offset asm("r6") = 0xA0B;
            register u8 *flags asm("r2");
            register u32 zero asm("r3");
            register u32 value asm("r0");
            register u32 page asm("r7");
            asm("" : : "r"(offset));
            flags = menu_pointer.save + offset;
            asm("" : : "r"(flags));
            zero = 0;
            asm("" : : "r"(zero));
            value = 0;
            asm("" : "+r"(value) : "r"(zero));
            *flags = value;
            page = frame.page;
            asm("" : : "r"(page));
            value = page << 16;
            asm("" : : "r"(value));
            sale_page_shift = value;
            asm("" : : "r"(sale_page_shift));
            if ((s32)sale_page_shift > 0)
            {
                value = 1;
                *flags = value;
            }
            value = frame.row;
            asm("" : : "r"(value));
            {
                register s32 row asm("r1");
                register u8 *count asm("r4");
                row = value << 16;
                asm("" : "+r"(row));
                row >>= 16;
                asm("" : : "r"(row));
                count = count_address;
                asm("" : : "r"(count));
                value = *count - 1;
                if (row >= (s32)value)
                    goto zoid_sale_page_flags_done553;
                row = *flags;
                asm("" : : "r"(row));
                value = 2;
                asm("" : : "r"(value));
                row |= value;
                *flags = row;
            }
        zoid_sale_page_flags_done553:
        {
            register u32 previous asm("r6") = sale_page_shift >> 16;
            asm("" : : "r"(previous));
            frame.previous_page = previous;
        }
        }
        }
        }
        zoid_sale_selected:
        {
            register s32 page asm("r1") = (s32)sale_page_shift >> 16;
            register u32 selected asm("r0");
            register u32 cursor_value asm("r7");
            asm("" : : "r"(page));
            selected = page * 6;
            asm("" : : "r"(selected));
            menu_pointer.cursor = &D_02007588;
            asm("" : "+l"(menu_pointer.cursor) : "r"(selected));
            cursor_value = *menu_pointer.cursor;
            {
                register union
                {
                    unsigned long long whole;
                    struct
                    {
                        u32 low, high;
                    } part;
                } guard asm("r6");
                guard.part.high = cursor_value;
                cursor_value = guard.part.high;
            }
            selected += cursor_value;
            asm("" : : "r"(selected));
            selected = (u16)selected;
            asm("" : : "r"(selected));
            frame.selected = selected;
        }
            {
                register u32 dirty asm("r0");
                ((volatile u32)dirty) = frame.refresh;
                if ((volatile u32)dirty)
                    goto zoid_sale_refresh_selected;
                {
                    register u32 selected asm("r1");
                    register u32 shifted asm("r0");
                    ((volatile u32)selected) = *(volatile u32 *)&frame.selected;
                    ((volatile u32)shifted) = (volatile u32)selected << 16;
                    (*(u32 *)(formation_stack + 136)) = (volatile u32)shifted;
                    if ((volatile u32)shifted != (volatile u32)previous_shift)
                        goto zoid_sale_refresh_selected;
                }
                goto zoid_sale_selected_done;
            }
        zoid_sale_refresh_selected:
        {
            u8 entry;
            register u32 sale_pilot_index asm("r6");
            {
                register u32 previous asm("r2") = previous_shift;
                register s32 index asm("r0");
                register s32 none asm("r3");
                asm("" : : "r"(previous));
                index = (s32)previous >> 16;
                asm("" : : "r"(index));
                none = 1;
                asm("" : : "r"(none));
                none = -none;
                asm("" : : "r"(none));
                if (index == none)
                    goto zoid_sale_refresh_header553;
            }
            {
                {
                    register u16 *flags asm("r2");
                    register u32 value asm("r1");
                    register u32 mask asm("r4");
                    register u32 bits asm("r0");
                    ((u16 *volatile)flags) = (u16 *)D_03004BBC;
                    asm("" : "+r"(flags));
                    ((u16 *volatile)flags) = (u16 *)((u8 *)(u16 *volatile)flags + 0x88);
                    ((volatile u32)value) = *(u16 *volatile)flags;
                    ((volatile u32)mask) = 0x7FFF;
                    asm("" : "+r"(mask) : "r"(value));
                    ((volatile u32)bits) = (volatile u32)mask;
                    asm("" : "+r"(bits));
                    ((volatile u32)value) &= (volatile u32)bits;
                    *(u16 *volatile)flags = (volatile u32)value;
                }
                func_0803E488(D_0875AFB8, 1);
            }
        zoid_sale_refresh_header553:
            ((volatile u32)sale_pilot_index) = 0;
            {
                register u32 selected asm("r5");
                ((volatile u32)selected) = frame.selected;
                ((volatile u32)selected) = (volatile u32)selected << 16;
                (*(u32 *)(formation_stack + 136)) = (volatile u32)selected;
            }
            {
                register u8 *save asm("r5");
                register const u8 *selected_entry asm("r4");
                register u8 *stats asm("r7");
                register u32 selected asm("r1");
                register u32 address asm("r0");
                register const u8 *roster asm("r2");
                ((u8 *volatile)stats) = (u8 *)&frame.stats;
                ((u8 *volatile)stats_base) = (u8 *volatile)stats;
                ((u8 *volatile)save) = D_02000B5C;
                ((volatile u32)selected) = (*(u32 *)(formation_stack + 136));
                asm("" : "+r"(selected));
                ((volatile u32)address) = (s32)(volatile u32)selected >> 16;
                ((const u8 *volatile)roster) = D_0200E7F4;
                ((const u8 *volatile)selected_entry) =
                    (u8 *)(volatile u32)address + (u32)(const u8 *volatile)roster;
            sale_detail_pilot_search:
            {
                register s32 signed_index asm("r3");
                register u32 shifted asm("r0");
                register u8 *record asm("r2");
                register u32 flags_offset asm("r7");
                register u32 flags asm("r1");
                asm("" : "+r"(sale_pilot_index));
                ((volatile u32)shifted) = (volatile u32)sale_pilot_index << 16;
                ((volatile s32)signed_index) = (s32)(volatile u32)shifted >> 16;
                ((volatile u32)shifted) = (volatile s32)signed_index * 4;
                ((u8 *volatile)record) = (u8 *)(volatile u32)shifted + (u32)(u8 *volatile)save;
                ((volatile u32)flags_offset) = 0x34A4;
                asm("" : "+r"(flags_offset));
                ((volatile u32)shifted) = (u32)(u8 *volatile)record + (volatile u32)flags_offset;
                ((volatile u32)flags) = *(u16 *)(volatile u32)shifted;
                if ((volatile u32)flags & 2)
                {
                    register u32 zoid_offset asm("r1");
                    ((volatile u32)zoid_offset) = 0x34A6;
                    asm("" : "+r"(zoid_offset));
                    ((volatile u32)shifted) = (u32)(u8 *volatile)record + (volatile u32)zoid_offset;
                    {
                        register u32 selected_zoid asm("r2");
                        ((volatile u32)shifted) = *(u8 *)(volatile u32)shifted;
                        ((volatile u32)selected_zoid) = *(const u8 *volatile)selected_entry;
                        asm("" : "+r"(selected_zoid));
                        if ((volatile u32)shifted == (volatile u32)selected_zoid)
                            goto sale_detail_pilot_search_done;
                    }
                }
                ((volatile u32)shifted) = (volatile s32)signed_index + 1;
                ((volatile u32)shifted) = (volatile u32)shifted << 16;
                ((volatile u32)sale_pilot_index) = (volatile u32)shifted >> 16;
                if ((s32)(volatile u32)shifted >> 16 <= 86)
                    goto sale_detail_pilot_search;
            }
            sale_detail_pilot_search_done:
                frame.linked_slot = (volatile u32)sale_pilot_index;
                {
                    register u32 selected asm("r3");
                    register u32 index asm("r4");
                    register const u8 *roster asm("r5");
                    ((volatile u32)selected) = (*(u32 *)(formation_stack + 136));
                    asm("" : "+r"(selected));
                    ((volatile u32)index) = (s32)(volatile u32)selected >> 16;
                    ((const u8 *volatile)roster) = D_0200E7F4;
                    ((volatile u32)index) += (u32)(const u8 *volatile)roster;
                    ((const u8 *volatile)selected_entry) = (const u8 *)(volatile u32)index;
                }
                {
                    register u32 address asm("r0");
                    register u8 *save asm("r6");
                    register u32 offset asm("r7");
                    register struct MenuStats553 *destination asm("r1");
                    ((volatile u32)address) = *(const u8 *volatile)selected_entry * 56;
                    ((u8 *volatile)save) = D_02000B5C;
                    ((volatile u32)address) += (u32)(u8 *volatile)save;
                    ((struct MenuStats553 *volatile)destination) =
                        (struct MenuStats553 *)(u8 *volatile)stats_base;
                    asm("" : "+r"(destination));
                    ((volatile u32)offset) = 0xD54;
                    asm("" : "+r"(offset));
                    ((volatile u32)address) += (volatile u32)offset;
                    *(struct MenuStats553 *volatile)destination =
                        *(struct MenuStats553 *)(volatile u32)address;
                    func_0803E488(D_0875AFB8, 26);
                    ((volatile u32)address) = *(const u8 *volatile)selected_entry * 56;
                    ((volatile u32)address) += (u32)(u8 *volatile)save;
                    {
                        register u32 model_offset asm("r6");
                        ((volatile u32)model_offset) = 0xD32;
                        asm("" : "+r"(model_offset));
                        ((volatile u32)address) += (volatile u32)model_offset;
                    }
                    func_08032800(*(u16 *)(volatile u32)address);
                }
            }
            func_0803E488(D_08675C5C, 0);
            func_0803E488(D_0875B448, 7);
            func_08001848(frame.stats.hp, 4, 0);
            func_0803E488(D_08675C5C, 0);
            func_0803E488(D_0875B448, 8);
            {
                register const u8 *stats asm("r7");
                ((const u8 *volatile)stats) = (u8 *volatile)stats_base;
                asm("" : "+r"(stats));
                func_08001848(*(u32 *)((const u8 *volatile)stats + 4), 3, 0);
            }
            func_0803E488(D_08675C5C, 0);
            func_0803E488(D_0875B448, 11);
            {
                register u32 linked asm("r1") = frame.linked_slot;
                register s32 index asm("r0");
                asm("" : : "r"(linked));
                index = (s32)(linked << 16) >> 16;
                asm("" : : "r"(index));
                if (index == 87)
                    goto zoid_sale_unassigned553;
                func_08032818(index);
                goto zoid_sale_pilot_shown553;
            zoid_sale_unassigned553:
                func_0803E488(D_0875B448, 12);
            zoid_sale_pilot_shown553:;
            }
            {
                register u32 selected asm("r2");
                register u32 address asm("r0");
                register const u8 *roster asm("r3");
                register u32 entry asm("r1");
                register u8 *save asm("r4");
                register u32 offset asm("r5");
                ((volatile u32)selected) = (*(u32 *)(formation_stack + 136));
                asm("" : "+r"(selected));
                ((volatile u32)address) = (s32)(volatile u32)selected >> 16;
                ((const u8 *volatile)roster) = D_0200E7F4;
                asm("" : "+r"(roster));
                ((volatile u32)address) += (u32)(const u8 *volatile)roster;
                ((volatile u32)entry) = *(u8 *)(volatile u32)address;
                ((volatile u32)address) = (volatile u32)entry * 56;
                ((u8 *volatile)save) = D_02000B5C;
                asm("" : "+r"(save));
                ((volatile u32)address) += (u32)(u8 *volatile)save;
                ((volatile u32)offset) = 0xD32;
                asm("" : "+r"(offset));
                ((volatile u32)address) += (volatile u32)offset;
                func_0804D654(*(u16 *)(volatile u32)address, 40, 88);
            }
            {
                register u32 previous asm("r6");
                register u32 active asm("r7");
                register u32 refresh asm("r0");
                ((volatile u32)previous) = (*(u32 *)(formation_stack + 136));
                asm("" : : "r"(previous));
                ((volatile u32)previous) = (volatile u32)previous >> 16;
                frame.previous_selected = (volatile u32)previous;
                ((volatile u32)active) = 1;
                frame.active = (volatile u32)active;
                ((volatile u32)refresh) = 0;
                frame.refresh = (volatile u32)refresh;
            }
        }
        zoid_sale_selected_done:
        {
            u32 condition;
            {
                register u32 active asm("r1");
                ((volatile u32)active) = frame.active;
                asm("" : "+r"(active));
                condition = (volatile u32)active;
            }
            if (condition)
            {
                register u32 clear asm("r2");
                func_0803E488(D_0875AFB8, 24);
                ((volatile u32)clear) = 0;
                frame.active = (volatile u32)clear;
            }
        }
            do
                func_0803E488(D_0875AFB8, 36);
            while (D_0300235A & 4);
            {
                register u16 *input asm("r0");
                register u32 key asm("r1");
                ((u16 *volatile)input) = D_02007574;
                asm("" : "+r"(input));
                ((volatile u32)key) = *(u16 *volatile)input;
                if ((volatile u32)key <= 1 || (volatile u32)key == 128)
                    goto zoid_sale_input_selected;
                {
                    register u16 *address asm("r3");
                    register u32 reloaded asm("r0");
                    ((u16 *volatile)address) = (u16 *volatile)input;
                    asm("" : : "r"(address));
                    ((volatile u32)reloaded) = *(volatile u16 *)(u16 *volatile)address;
                    if ((volatile u32)reloaded == 2)
                        goto zoid_sale_page_left;
                    if ((volatile u32)reloaded == 4)
                        goto zoid_sale_page_right;
                }
                goto zoid_sale_update;
            }
        zoid_sale_page_left:
        {
            register s32 page asm("r4");
            register u32 shifted asm("r0");
            ((volatile s32)page) = frame.page;
            asm("" : : "r"(page));
            ((volatile u32)shifted) = (volatile u32)page << 16;
            asm("" : : "r"(shifted));
            ((volatile s32)page) = (s32)(volatile u32)shifted >> 16;
            asm("" : "+r"(page));
            if ((volatile s32)page <= 0)
                goto zoid_sale_update;
            func_080019EC(64);
            ((volatile u32)shifted) = (volatile s32)page - 1;
            ((volatile u32)shifted) = (volatile u32)shifted << 16;
            frame.page = (volatile u32)shifted >> 16;
            goto zoid_sale_update;
        }
        zoid_sale_page_right:
        {
            {
                register u32 loaded_row asm("r5");
                register s32 row asm("r1");
                ((volatile u32)loaded_row) = frame.row;
                asm("" : : "r"(loaded_row));
                ((volatile s32)row) = (volatile u32)loaded_row << 16;
                ((volatile s32)row) = (volatile s32)row >> 16;
                if ((volatile s32)row >= D_0200E8A1 - 1)
                    goto zoid_sale_update;
            }
            func_080019EC(64);
            {
                register u32 page asm("r6");
                register u32 shifted asm("r0");
                register u32 step asm("r7");
                ((volatile u32)page) = frame.page;
                asm("" : : "r"(page));
                ((volatile u32)shifted) = (volatile u32)page << 16;
                ((volatile u32)step) = 0x10000;
                asm("" : : "r"(shifted), "r"(step));
                ((volatile u32)shifted) += (volatile u32)step;
                frame.page = (volatile u32)shifted >> 16;
            }
            goto zoid_sale_update;
        }
        zoid_sale_input_selected:
        {
            register u32 sale_action asm("r0");
            sale_action = ({
                register u16 *input asm("r1");
                register u32 response asm("r0");
                register u16 *remembered asm("r2");
                ((u16 *volatile)input) = D_02007574;
                asm("" : : "r"(input));
                ((volatile u32)response) = *(volatile u16 *)(input + 1);
                ((u16 *volatile)remembered) = remembered_base;
                remembered[2] = (volatile u32)response;
                {
                    register u16 *page_address asm("r3");
                    register u32 page asm("r4");
                    register u16 *detail asm("r3");
                    ((u16 *volatile)page_address) = (u16 *)&frame;
                    asm("" : : "r"(page_address));
                    ((volatile u32)page) = page_address[16];
                    ((u16 *volatile)detail) = (*(u16 **)(formation_stack + 128));
                    asm("" : : "r"(detail));
                    detail[2] = (volatile u32)page;
                }
                ((volatile u32)response) = *(volatile u16 *)input;
                (volatile u32) response;
            });
            if (sale_action == 1)
            {
                register u32 available asm("r7");
                register const u8 *definition asm("r7");
                register s32 price asm("r9");
                register const u8 *price_definition asm("r7");
                register u8 *price_entry asm("r5");
                register u32 price_offset asm("r4");
                u8 *price_record;
                register u8 *assigned_entry asm("r6");
                register u32 model_offset asm("r8");
                register const u8 *parts_messages asm("r4");
                {
                    register u32 entry_index asm("r6");
                    register u8 *save asm("r12");
                    register u32 flags_offset asm("r10");
                    register u8 *save_address asm("r5");
                    register u32 address asm("r0");
                    available = 0;
                    asm("" : : "r"(available));
                    entry_index = 0;
                    asm("" : : "r"(entry_index));
                    save_address = D_02000B5C;
                    asm("" : : "r"(save_address));
                    save = save_address;
                    asm("" : : "r"(save));
                    address = 0x34A4;
                    asm("" : : "r"(address));
                    flags_offset = address;
                    asm("" : : "r"(flags_offset));
                zoid_sale_count_unit553:
                {
                    register s32 unit_index asm("r3");
                    register u32 model asm("r1");
                    register u32 shifted asm("r2");
                    address = entry_index << 16;
                    asm("" : : "r"(address));
                    unit_index = (s32)address >> 16;
                    asm("" : : "r"(unit_index));
                    model = unit_index * 56;
                    asm("" : : "r"(model));
                    model += (u32)save;
                    asm("" : : "r"(model));
                    shifted = 0xD32;
                    asm("" : : "r"(shifted));
                    model += shifted;
                    asm("" : : "r"(model));
                    model = *(u16 *)model;
                    asm("" : "+r"(model));
                    shifted = address;
                    asm("" : : "r"(shifted));
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low, high;
                            } part;
                        } condition asm("r0");
                        condition.part.high = model;
                        if (condition.part.high == 0)
                            goto zoid_sale_count_next553;
                    }
                    {
                        register u32 pilot_index asm("r5");
                        register u8 *pilot_save asm("r9");
                        register u8 *base asm("r4");
                        register u32 selected_unit asm("r6");
                        register u32 mask asm("r8");
                        pilot_index = 0;
                        asm("" : : "r"(pilot_index));
                        base = D_02000B5C;
                        asm("" : : "r"(base));
                        pilot_save = base;
                        asm("" : : "r"(pilot_save));
                        selected_unit = unit_index;
                        asm("" : : "r"(selected_unit));
                        address = 2;
                        asm("" : : "r"(address));
                        mask = address;
                        asm("" : : "r"(mask));
                    zoid_sale_count_pilot553:
                    {
                        register s32 signed_pilot asm("r4");
                        register u8 *pointer asm("r1");
                        register u8 *record asm("r3");
                        register u32 bits asm("r1");
                        address = pilot_index << 16;
                        asm("" : : "r"(address));
                        signed_pilot = (s32)address >> 16;
                        asm("" : : "r"(signed_pilot));
                        address = (u32)signed_pilot << 2;
                        asm("" : : "r"(address));
                        pointer = pilot_save;
                        asm("" : : "r"(pointer));
                        record = (u8 *)(address + (u32)pointer);
                        asm("" : : "r"(record));
                        bits = flags_offset;
                        asm("" : : "r"(bits));
                        address = (u32)record + bits;
                        asm("" : : "r"(address));
                        bits = *(u16 *)address;
                        asm("" : : "r"(bits));
                        address = mask;
                        asm("" : : "r"(address));
                        address &= bits;
                        asm("" : : "r"(address));
                        if (address == 0)
                            goto zoid_sale_count_pilot_next553;
                        bits = 0x34A6;
                        asm("" : : "r"(bits));
                        address = (u32)record + bits;
                        asm("" : : "r"(address));
                        address = *(u8 *)address;
                        asm("" : : "r"(address));
                        if (address == selected_unit)
                            goto zoid_sale_count_pilot_found553;
                    zoid_sale_count_pilot_next553:
                        address = signed_pilot + 1;
                        asm("" : : "r"(address));
                        address <<= 16;
                        asm("" : : "r"(address));
                        pilot_index = address >> 16;
                        asm("" : : "r"(pilot_index));
                        address = (s32)address >> 16;
                        asm("" : : "r"(address));
                        if ((s32)address <= 86)
                            goto zoid_sale_count_pilot553;
                    }
                    zoid_sale_count_pilot_found553:
                        address = pilot_index << 16;
                        asm("" : : "r"(address));
                        address = (s32)address >> 16;
                        asm("" : : "r"(address));
                        if (address == 87)
                            goto zoid_sale_count_available553;
                        address <<= 2;
                        asm("" : : "r"(address));
                        address += (u32)save;
                        asm("" : : "r"(address));
                        address += flags_offset;
                        asm("" : : "r"(address));
                        {
                            register u32 bits asm("r1") = *(u16 *)address;
                            asm("" : : "r"(bits));
                            address = 8;
                            asm("" : : "r"(address));
                            address &= bits;
                            asm("" : : "r"(address));
                            if (address != 0)
                                goto zoid_sale_count_next553;
                        }
                    }
                zoid_sale_count_available553:
                    address = available + 1;
                    asm("" : : "r"(address));
                    address = (u8)address;
                    available = address;
                    asm("" : : "r"(available));
                zoid_sale_count_next553:
                {
                    register u32 step asm("r3") = 0x10000;
                    asm("" : : "r"(step));
                    address = shifted + step;
                    asm("" : : "r"(address));
                    entry_index = address >> 16;
                    asm("" : : "r"(entry_index));
                    address = (s32)address >> 16;
                    asm("" : : "r"(address));
                    if ((s32)address <= 172)
                        goto zoid_sale_count_unit553;
                }
                }
                }
                if (available <= 4)
                {
                    func_080019EC(79);
                    func_0803E488(D_0875B4AC, 5);
                    func_08001848(D_0200E8A1, 3, 1);
                    func_0803E488(D_0875B4AC, 6);
                    goto zoid_sale_done;
                }
                {
                    register u32 selected asm("r4") = *(u32 *)(formation_stack + 136);
                    register u32 address asm("r0");
                    register u8 *roster asm("r5");
                    register u8 *save asm("r7");
                    register u32 offset asm("r1");
                    register u32 model asm("r1");
                    asm("" : : "r"(selected));
                    address = (s32)selected >> 16;
                    asm("" : : "r"(address));
                    roster = D_0200E7F4;
                    asm("" : : "r"(roster));
                    assigned_entry = (u8 *)(address + (u32)roster);
                    asm("" : : "r"(assigned_entry));
                    model = *assigned_entry;
                    asm("" : : "r"(model));
                    address = model * 56;
                    asm("" : : "r"(address));
                    save = D_02000B5C;
                    {
                        register union
                        {
                            unsigned long long whole;
                            struct
                            {
                                u32 low;
                                u8 *high;
                            } part;
                        } guard asm("r6");
                        guard.part.high = save;
                        save = guard.part.high;
                    }
                    address += (u32)save;
                    asm("" : : "r"(address));
                    offset = 0xD32;
                    asm("" : : "r"(offset));
                    model_offset = offset;
                    asm("" : : "r"(model_offset));
                    address += model_offset;
                    asm("" : : "r"(address));
                    model = *(u16 *)address;
                    asm("" : : "r"(model));
                    definition = D_0867006C + model * 76;
                }
                asm("" : "+r"(definition));
                if (*(u32 *)(definition + 40) == 0)
                {
                    func_080019EC(79);
                    func_0803E488(D_0875B4AC, 9);
                    goto zoid_sale_done;
                }
                {
                    register s32 zero asm("r2");
                    ((volatile s32)zero) = 0;
                    asm("" : : "r"(zero));
                    ((volatile s32)price) = (volatile s32)zero;
                }
                {
                    register u32 linked_slot asm("r3");
                    register u32 shifted_slot asm("r0");
                    register s32 assigned_pilot asm("r5");
                    ((volatile u32)linked_slot) = frame.linked_slot;
                    asm("" : : "r"(linked_slot));
                    ((volatile u32)shifted_slot) = (volatile u32)linked_slot << 16;
                    assigned_pilot = (s32)(volatile u32)shifted_slot >> 16;
                    asm("" : : "r"(assigned_pilot));
                    (*(volatile u32 *)(formation_stack + 140)) = (volatile u32)shifted_slot;
                    if (assigned_pilot != 87)
                    {
                        register const u8 *script asm("r7") = D_0875AFB8;
                        asm("" : "+r"(script));
                        func_0803E488(script, 0);
                        func_0803E488(script, 25);
                        if (({
                                register u32 address asm("r0") = (u32)assigned_pilot << 2;
                                register u8 *save asm("r4");
                                register u32 offset asm("r1");
                                register u32 flags asm("r1");
                                asm("" : : "r"(address));
                                save = D_02000B5C;
                                asm("" : : "r"(save));
                                address += (u32)save;
                                asm("" : : "r"(address));
                                offset = 0x34A4;
                                asm("" : : "r"(offset));
                                address += offset;
                                asm("" : : "r"(address));
                                flags = *(u16 *)address;
                                asm("" : "+r"(flags));
                                flags;
                            }) &
                            8)
                        {
                            func_080019EC(79);
                            func_08032818(assigned_pilot);
                            func_0803E488(D_0875B434, 1);
                            {
                                register u32 model asm("r1") = *assigned_entry;
                                register u32 address asm("r0");
                                register u8 *save asm("r2");
                                asm("" : : "r"(model));
                                address = model * 56;
                                asm("" : : "r"(address));
                                save = D_02000B5C;
                                asm("" : : "r"(save));
                                address += (u32)save;
                                asm("" : : "r"(address));
                                address += model_offset;
                                func_08032800(*(u16 *)address);
                            }
                            func_0803E488(D_0875B434, 3);
                            func_080019EC(65);
                            goto zoid_sale_assigned_pending_price;
                        }
                        {
                            register u32 model asm("r1") = *assigned_entry;
                            register u32 address asm("r0");
                            register u8 *save asm("r3");
                            asm("" : : "r"(model));
                            address = model * 56;
                            asm("" : : "r"(address));
                            save = D_02000B5C;
                            asm("" : : "r"(save));
                            address += (u32)save;
                            asm("" : : "r"(address));
                            address += model_offset;
                            func_08032800(*(u16 *)address);
                        }
                        func_0803E488(D_0875B448, 2);
                        func_08032818(assigned_pilot);
                        func_0803E488(D_0875B448, 3);
                        func_0803E488(D_0875B068, 17);
                        func_0803E488(script, 0);
                        {
                            register u16 *input asm("r1");
                            register u32 response asm("r0");
                            ((u16 *volatile)input) = D_02007574;
                            asm("" : : "r"(input));
                            ((volatile u32)response) = *(volatile u16 *)input;
                            if ((volatile u32)response != 1)
                                goto zoid_sale_assigned_response_cancel;
                            ((volatile u32)response) = *(volatile u16 *)(input + 1);
                            if ((volatile u32)response == 0)
                                goto zoid_sale_assigned_response_accept;
                        }
                    zoid_sale_assigned_response_cancel:
                    {
                        register u16 *input asm("r0");
                        ((u16 *volatile)input) = D_02007574;
                        asm("" : : "r"(input));
                        if (*(volatile u16 *)input == 0)
                            func_080019EC(63);
                    zoid_sale_assigned_pending_price:
                    {
                        register s32 pending asm("r4");
                        pending = (volatile s32)price;
                        asm("" : : "r"(pending));
                        if (pending == 0)
                            goto zoid_sale_restore;
                    }
                    }
                    zoid_sale_assigned_response_accept:;
                    }
                }
                {
                    register u32 selected asm("r5") = (*(u32 *)(formation_stack + 136));
                    register s32 index asm("r0");
                    register u8 *roster asm("r6");
                    asm("" : : "r"(selected));
                    index = (s32)selected >> 16;
                    roster = D_0200E7F4;
                    asm("" : : "r"(index), "r"(roster));
                    price_entry = (u8 *)((u32)index + (u32)roster);
                }
                {
                    register u32 unit asm("r0") = *price_entry;
                    register u32 row asm("r1");
                    register u8 *save asm("r7");
                    row = ((unit << 3) - unit) << 3;
                    save = D_02000B5C;
                    asm("" : : "r"(row), "r"(save));
                    price_record = (u8 *)(row + (u32)save);
                }
                ((volatile u32)price_offset) = 0xD32;
                price_definition =
                    D_0867006C + *(u16 *)(price_record + (volatile u32)price_offset) * 76;
                price = func_080346C0(*(s32 *)(price_definition + 40), price_record[0xD60]);
                price = *(s32 *)(price_definition + 40) + price;
                func_0803E488(D_0875AFB8, 0);
                func_0803E488(D_0875AFB8, 25);
                {
                    register u32 unit asm("r1") = *price_entry;
                    register u32 address asm("r0");
                    register u8 *save asm("r3");
                    address = ((unit << 3) - unit) << 3;
                    save = D_02000B5C;
                    asm("" : : "r"(address), "r"(save));
                    address += (u32)save;
                    address += price_offset;
                    func_08032800(*(u16 *)address);
                }
                func_0803E488(D_0875B4AC, 1);
                func_08001848(price, 7, 1);
                func_0803E488(D_0875B4AC, 2);
                func_0803E488(D_0875B068, 17);
                func_0803E488(D_0875AFB8, 0);
                {
                    register const u16 *response asm("r1") = D_02007574;
                    if (response[0] != 1)
                        goto zoid_sale_price_response_refused;
                    if (response[1] != 0)
                        goto zoid_sale_price_response_cancelled;
                }
                {
                    register u32 active_part asm("r6");
                    register u8 *parts_base asm("r3");
                    ((volatile u32)active_part) = 0;
                    {
                        register u8 *parts_start asm("r2");
                        register u32 unit asm("r1");
                        register u32 row_offset asm("r0");
                        ((u8 *volatile)parts_start) = D_02001898;
                        asm("" : "+r"(parts_start));
                        ((volatile u32)unit) = *(u8 *volatile)price_entry;
                        asm("" : "+r"(unit));
                        ((volatile u32)row_offset) =
                            (((volatile u32)unit << 3) - (volatile u32)unit) << 3;
                        asm("" : "+r"(row_offset));
                        ((u8 *volatile)parts_base) =
                            (u8 *)((volatile u32)row_offset + (u32)(u8 *volatile)parts_start);
                    }
                    {
                        register s32 part_index asm("r2");
                        register u32 shifted asm("r0");
                        register u16 *part asm("r5");
                        register u32 item asm("r0");
                        register u32 missing asm("r4");
                        register u32 flags asm("r1");
                        register u32 mask asm("r0");
                        register u32 next asm("r0");
                    zoid_sale_active_part_scan:
                        asm("" : "+r"(active_part));
                        ((volatile u32)shifted) = (volatile u32)active_part << 16;
                        asm("" : "+r"(shifted));
                        ((volatile s32)part_index) = (s32)(volatile u32)shifted >> 16;
                        asm("" : "+r"(part_index), "+r"(parts_base));
                        ((volatile u32)shifted) = (volatile s32)part_index << 2;
                        asm("" : "+r"(shifted));
                        ((u16 *volatile)part) =
                            (u16 *)((u32)(u8 *volatile)parts_base + (volatile u32)shifted);
                        asm("" : "+r"(part));
                        ((volatile u32)item) = part[1];
                        asm("" : "+r"(item));
                        ((volatile u32)missing) = 0xFFFF;
                        asm("" : "+r"(missing));
                        if ((volatile u32)item != (volatile u32)missing)
                        {
                            ((volatile u32)flags) = part[0];
                            asm("" : "+r"(flags));
                            ((volatile u32)mask) = 3;
                            ((volatile u32)mask) &= (volatile u32)flags;
                            if ((volatile u32)mask)
                                goto zoid_sale_active_parts_found;
                        }
                        ((volatile u32)next) = ((volatile s32)part_index + 1) << 16;
                        asm("" : "+r"(next));
                        ((volatile u32)active_part) = (volatile u32)next >> 16;
                        if ((s32)(volatile u32)next >> 16 <= 2)
                            goto zoid_sale_active_part_scan;
                    }
                zoid_sale_active_parts_found:
                    if ((volatile u32)active_part != 3)
                    {
                        parts_messages = D_0875B4AC;
                        asm("" : : "r"(parts_messages));
                        func_0803E488(parts_messages, 7);
                        func_0803E488(D_0875B068, 17);
                        {
                            register u16 *input asm("r1") = D_02007574;
                            register u32 response asm("r0");
                            asm("" : : "r"(input));
                            response = input[0];
                            asm("" : "+r"(response));
                            if (response != 1)
                                goto zoid_sale_parts_response_refused;
                            response = input[1];
                            asm("" : "+r"(response));
                            if (response != 0)
                                goto zoid_sale_parts_response_cancelled;
                        }
                        {
                            register u32 overflow_index asm("r6");
                            register u8 *roster asm("r10");
                            register u8 *parts asm("r7");
                            register u8 *inventory asm("r8");
                            register const u8 *messages asm("r4");
                            overflow_index = 0;
                            {
                                register u8 *loaded asm("r5") = D_0200E7F4;
                                asm("" : : "r"(loaded));
                                roster = loaded;
                            }
                            {
                                register u8 *loaded asm("r2") = D_02001898;
                                asm("" : : "r"(loaded));
                                parts = loaded;
                            }
                            {
                                register u32 offset asm("r0") = 0x2610;
                                asm("" : "+r"(offset));
                                offset += (u32)parts;
                                asm("" : : "r"(offset));
                                inventory = (u8 *)offset;
                            }
                            messages = D_0875B1F0;
                        zoid_sale_overflow_scan:
                        {
                            register u32 selected asm("r1") = (*(u32 *)(formation_stack + 136));
                            register u32 unit asm("r0");
                            register u32 row asm("r1");
                            register u32 position asm("r0");
                            register u16 *part asm("r5");
                            register u32 missing asm("r2");
                            asm(""
                                :
                                : "r"(selected), "r"(roster), "r"(parts), "r"(inventory),
                                  "r"(messages), "r"(overflow_index));
                            unit = (s32)selected >> 16;
                            asm("" : "+r"(unit));
                            unit += (u32)roster;
                            asm("" : "+r"(unit));
                            unit = *(u8 *)unit;
                            row = ((unit << 3) - unit) << 3;
                            asm("" : "+r"(row));
                            row += (u32)parts;
                            asm("" : "+r"(row));
                            position = (s32)(overflow_index << 16) >> 14;
                            asm("" : "+r"(position));
                            part = (u16 *)(row + position);
                            asm("" : "+r"(part));
                            unit = part[1];
                            missing = 0xFFFF;
                            asm("" : : "r"(unit), "r"(missing));
                            if (unit != missing && (part[0] & 3) && inventory[part[1]] > 8)
                            {
                                func_0803E488(D_0875AFB8, 0);
                                func_0803E488(D_0875AFB8, 25);
                                func_0803E488(messages, 7);
                                func_0803E488(D_0866634C, part[1]);
                                func_0803E488(messages, 8);
                                func_0803E488(D_0875B068, 17);
                                if (D_02007574[0] != 1 || D_02007574[1] != 0)
                                {
                                    if (D_02007574[0] == 0)
                                        func_080019EC(63);
                                    goto zoid_sale_overflow_scan_done;
                                }
                            }
                        }
                            {
                                register u32 shifted asm("r0");
                                register u32 step asm("r3");
                                asm("" : "+r"(overflow_index), "+r"(parts));
                                shifted = overflow_index << 16;
                                asm("" : "+r"(shifted));
                                step = 0x10000;
                                asm("" : : "r"(shifted), "r"(step));
                                shifted += step;
                                overflow_index = shifted >> 16;
                                if ((s32)shifted >> 16 <= 2)
                                    goto zoid_sale_overflow_scan;
                            }
                        zoid_sale_overflow_scan_done:
                            if (overflow_index != 3)
                                goto zoid_sale_parts_cancel;
                        }
                        {
                            register u32 return_index asm("r6");
                            u8 *return_entry;
                            register u8 *return_parts asm("r4");
                            register u32 missing asm("r3");
                            register u8 *inventory asm("r8");
                            return_index = 0;
                            {
                                register u32 selected asm("r4") = (*(u32 *)(formation_stack + 136));
                                register u32 position asm("r0");
                                register u8 *roster asm("r5");
                                asm("" : : "r"(selected));
                                position = (s32)selected >> 16;
                                asm("" : "+r"(position));
                                roster = D_0200E7F4;
                                asm("" : : "r"(position), "r"(roster));
                                return_entry = (u8 *)(position + (u32)roster);
                            }
                            return_parts = D_02001898;
                            missing = 0xFFFF;
                            {
                                register u32 offset asm("r0") = 0x2610;
                                asm("" : : "r"(offset), "r"(return_parts), "r"(missing));
                                offset += (u32)return_parts;
                                asm("" : : "r"(offset));
                                inventory = (u8 *)offset;
                            }
                        zoid_sale_return_scan:
                        {
                            register u32 unit asm("r1");
                            register u32 row asm("r0");
                            register u32 shifted asm("r2");
                            register u32 position asm("r1");
                            register u16 *part asm("r5");
                            register u32 item asm("r0");
                            asm(""
                                : "+r"(return_index), "+r"(return_entry), "+r"(return_parts),
                                  "+r"(missing), "+r"(inventory));
                            unit = *return_entry;
                            row = ((unit << 3) - unit) << 3;
                            asm("" : "+r"(row));
                            row += (u32)return_parts;
                            asm("" : "+r"(row));
                            shifted = return_index << 16;
                            asm("" : "+r"(shifted));
                            position = (s32)shifted >> 14;
                            asm("" : "+r"(position));
                            part = (u16 *)(row + position);
                            asm("" : "+r"(part));
                            item = part[1];
                            asm("" : : "r"(item), "r"(missing));
                            if (item != missing && (part[0] & 3))
                            {
                                register u8 *quantity_base asm("r6");
                                register u8 *quantity_address asm("r1");
                                register u32 quantity asm("r0");
                                item = part[1];
                                asm("" : "+r"(item));
                                quantity_base = inventory;
                                asm("" : : "r"(item), "r"(quantity_base));
                                quantity_address = (u8 *)(item + (u32)quantity_base);
                                quantity = *quantity_address;
                                if (quantity <= 8)
                                    *quantity_address = quantity + 1;
                                {
                                    register u32 previous_item asm("r1") = part[1];
                                    register u32 cleared_item asm("r0") = missing;
                                    asm("" : "+r"(previous_item), "+r"(cleared_item));
                                    cleared_item |= previous_item;
                                    part[1] = cleared_item;
                                }
                            }
                            {
                                register u32 step asm("r1") = 0x10000;
                                register u32 next asm("r0");
                                asm("" : : "r"(step), "r"(shifted));
                                next = shifted + step;
                                return_index = next >> 16;
                                if ((s32)next >> 16 <= 2)
                                    goto zoid_sale_return_scan;
                            }
                        }
                        }
                    }
                }
                goto zoid_sale_completion;
            zoid_sale_parts_cancel:
                func_0803E488(D_0875B4AC, 8);
                {
                    register u16 *remembered asm("r2") = remembered_base;
                    register u32 selected asm("r0");
                    register u16 *cursor asm("r3");
                    asm("" : : "r"(remembered));
                    selected = remembered[2];
                    asm("" : "+r"(selected));
                    cursor = &D_02007588;
                    asm("" : : "r"(cursor), "r"(selected));
                    *cursor = selected;
                }
                goto zoid_sale_open;
            zoid_sale_parts_response_cancelled:
                func_0803E488(parts_messages, 8);
                {
                    register u16 *remembered asm("r4") = remembered_base;
                    register u32 selected asm("r0");
                    register u16 *cursor asm("r5");
                    asm("" : : "r"(remembered));
                    selected = remembered[2];
                    asm("" : "+r"(selected));
                    cursor = &D_02007588;
                    asm("" : : "r"(cursor), "r"(selected));
                    *cursor = selected;
                }
                goto zoid_sale_open;
            zoid_sale_parts_response_refused:
                func_080019EC(63);
                func_0803E488(parts_messages, 8);
                {
                    register u16 *remembered asm("r6") = remembered_base;
                    register u32 selected asm("r0");

                    asm("" : : "r"(remembered));
                    selected = remembered[2];
                    asm("" : "+r"(selected));
                    menu_pointer.cursor = &D_02007588;
                    asm("" : "+l"(menu_pointer.cursor) : "r"(selected), "r"(remembered));
                    *menu_pointer.cursor = selected;
                }
                goto zoid_sale_open;
            zoid_sale_completion:
            {
                register u32 linked asm("r1") = (*(volatile u32 *)(formation_stack + 140));
                register s32 linked_index asm("r0");
                asm("" : : "r"(linked));
                linked_index = (s32)linked >> 16;
                asm("" : "+r"(linked_index));
                if (linked_index != 87)
                {
                    register u32 slot asm("r2") = frame.linked_slot;
                    asm("" : : "r"(slot));
                    func_08036B98((u8)slot);
                }
            }
                {
                    register u32 selected asm("r3") = (*(u32 *)(formation_stack + 136));
                    register u32 address asm("r0");
                    register u8 *roster asm("r4");
                    register u32 unit asm("r1");
                    register u8 *save asm("r5");
                    register u32 model_field asm("r6");
                    asm("" : : "r"(selected));
                    address = (s32)selected >> 16;
                    asm("" : "+r"(address));
                    roster = D_0200E7F4;
                    asm("" : : "r"(roster), "r"(address));
                    address += (u32)roster;
                    asm("" : "+r"(address));
                    unit = *(u8 *)address;
                    address = ((unit << 3) - unit) << 3;
                    asm("" : "+r"(address));
                    save = D_02000B5C;
                    asm("" : : "r"(save));
                    address += (u32)save;
                    asm("" : "+r"(address));
                    model_field = 0xD32;
                    asm("" : : "r"(model_field));
                    address += model_field;
                    asm("" : "+r"(address));
                    *(u16 *)address = 0;
                    {
                        register u32 cash_offset asm("r7") = 0xD28;
                        register u32 *cash asm("r2");
                        register u32 total asm("r0");
                        register u32 limit asm("r1");
                        asm("" : : "r"(save), "r"(cash_offset));
                        cash = (u32 *)((u32)save + cash_offset);
                        asm("" : "+r"(cash));
                        total = *cash;
                        total += (u32)price;
                        *cash = total;
                        limit = 9999999;
                        asm("" : : "r"(total), "r"(limit));
                        if (total > limit)
                            *cash = limit;
                    }
                }
                func_0803E488(D_0875AFB8, 0);
                func_0803E488(D_0875B4AC, 3);
                frame.refresh = 1;
                goto zoid_sale_done;
            zoid_sale_price_response_cancelled:
                func_0803E488(D_0875B4AC, 4);
            zoid_sale_done:
                func_080019EC(65);
                goto zoid_sale_restore;
            zoid_sale_price_response_refused:
                func_080019EC(63);
            zoid_sale_restore:
            {
                register u16 *remembered asm("r1") = remembered_base;
                register u32 selected asm("r0");
                register u16 *cursor asm("r2");
                asm("" : : "r"(remembered));
                selected = remembered[2];
                asm("" : "+r"(selected));
                cursor = &D_02007588;
                asm("" : : "r"(cursor), "r"(selected));
                *cursor = selected;
            }
                goto zoid_sale_open;
            }
            if (sale_action == 0)
            {
                func_080019EC(63);
                state = 0x10;
            }
            else
            {
                {
                    register u32 linked asm("r3") = frame.linked_slot;
                    register s32 index asm("r0");
                    asm("" : : "r"(linked));
                    index = (s32)(linked << 16) >> 16;
                    if (index <= 86)
                    {
                        register u32 first asm("r0") = (linked << 24) >> 24;
                        asm("" : "+r"(first));
                        frame.first_item = first;
                    }
                    else
                    {
                        register u32 missing asm("r4") = 255;
                        asm("" : "+r"(missing));
                        frame.first_item = missing;
                    }
                }
                {
                    register u32 selected asm("r5") = (*(u32 *)(formation_stack + 136));
                    register u32 address asm("r0");
                    register const u8 *roster asm("r6");
                    asm("" : : "r"(selected));
                    address = (s32)selected >> 16;
                    roster = D_0200E7F4;
                    asm("" : : "r"(address), "r"(roster));
                    address += (u32)roster;
                    frame.second_item = *(u8 *)address;
                }
                {
                    register u32 returning asm("r7") = 0x401;
                    asm("" : "+r"(returning));
                    frame.return_state = returning;
                }
                state = 0x500;
            }
            func_0803E488(D_0875AFB8, 11);
            {
                register u8 *address asm("r0") = D_03004BBC;
                register u32 flags asm("r1");
                register u32 mask asm("r3");
                register u32 bits asm("r2");
                asm("" : : "r"(address));
                address += 0x88;
                asm("" : : "r"(address));
                flags = *(u16 *)address;
                asm("" : : "r"(flags));
                mask = 0x7FFF;
                asm("" : : "r"(mask));
                bits = mask;
                asm("" : : "r"(bits));
                flags &= bits;
                *(u16 *)address = flags;
            }
            func_0803E488(D_0875AFB8, 9);
            func_0803E488(D_0875AFB8, 0);
        }
        break;
        }
        case 0x500:
        {
            register const u16 *model_header asm("r9");
            register u32 model_address asm("r4");
            register const u8 *messages asm("r7");
            register const u8 *separator asm("r5");
            register u32 first_item asm("r4");
            func_0803E488(D_0875B3B8, 11);
            ((volatile u32)first_item) = frame.first_item;
            if ((volatile u32)first_item == 255)
            {
                register u32 linked_index asm("r6");
                ((volatile u32)linked_index) = 0;
                {
                    register u8 *stats asm("r5");
                    register u32 selected asm("r7");
                    ((u8 *volatile)stats) = (u8 *)&frame.stats;
                    asm("" : "+r"(stats));
                    ((u8 *volatile)stats_base) = (u8 *volatile)stats;
                    ((volatile u32)selected) = frame.second_item;
                    ((volatile u32)model_address) = (volatile u32)selected << 3;
                }
                {
                    register u8 *save asm("r5");
                    register u32 mask asm("r7");
                    save = D_02000B5C;
                    asm("" : "+r"(save));
                    mask = 2;
                    asm("" : "+r"(mask));
                summary_linked_scan:
                {
                    register s32 index asm("r3");
                    register u32 scaled asm("r0");
                    register u8 *record asm("r2");
                    register u32 offset asm("r1");
                    register u8 *address asm("r0");
                    register u32 flags asm("r1");
                    register u32 bits asm("r0");
                    ((volatile u32)scaled) = linked_index << 16;
                    ((volatile s32)index) = (s32)(volatile u32)scaled >> 16;
                    ((volatile u32)scaled) = (volatile s32)index * 4;
                    ((u8 *volatile)record) = (u8 *)((volatile u32)scaled + (u32)save);
                    ((volatile u32)offset) = 0x34A4;
                    asm("" : "+r"(offset));
                    ((u8 *volatile)address) = (u8 *volatile)record + (volatile u32)offset;
                    ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
                    ((volatile u32)bits) = mask;
                    ((volatile u32)bits) &= (volatile u32)flags;
                    if ((volatile u32)bits)
                    {
                        register u32 linked asm("r0");
                        register u32 selected asm("r2");
                        ((volatile u32)offset) = 0x34A6;
                        asm("" : "+r"(offset));
                        ((u8 *volatile)address) = (u8 *volatile)record + (volatile u32)offset;
                        ((volatile u32)linked) = *(u8 *volatile)address;
                        ((volatile u32)selected) = *(volatile u32 *)&frame.second_item;
                        if ((volatile u32)linked == (volatile u32)selected)
                            goto summary_linked_found;
                    }
                    ((volatile u32)scaled) = (volatile s32)index + 1;
                    ((volatile u32)scaled) <<= 16;
                    ((volatile u32)linked_index) = (volatile u32)scaled >> 16;
                    ((volatile u32)scaled) = (s32)(volatile u32)scaled >> 16;
                    if ((s32)(volatile u32)scaled <= 86)
                        goto summary_linked_scan;
                }
                }
            summary_linked_found:
                frame.linked_slot = linked_index;
                {
                    register u32 shifted asm("r0");
                    ((volatile u32)shifted) = linked_index << 16;
                    ((volatile u32)shifted) = (s32)(volatile u32)shifted >> 16;
                    if ((s32)(volatile u32)shifted != 87)
                        goto summary_recalculate;
                }
                goto summary_unlinked_stats;
            summary_recalculate:
            {
                register u32 pilot asm("r0");
                register u32 unit asm("r1");
                ((volatile u32)pilot) = 255;
                ((volatile u32)unit) = frame.second_item;
                func_08036C1C((volatile u32)pilot, (volatile u32)unit, (u8 *volatile)stats_base);
            }
                goto summary_stats_ready;
            summary_unlinked_stats:
            {
                register u32 selected asm("r3");
                register u32 address asm("r0");
                register u8 *save asm("r5");
                register u8 *stats asm("r1");
                register u32 offset asm("r6");
                ((volatile u32)selected) = frame.second_item;
                ((volatile u32)address) = ((volatile u32)model_address - (volatile u32)selected)
                                          << 3;
                ((u8 *volatile)save) = D_02000B5C;
                ((volatile u32)address) += (u32)(u8 *volatile)save;
                ((u8 *volatile)stats) = (u8 *volatile)stats_base;
                asm("" : "+r"(stats));
                ((volatile u32)offset) = 0xD54;
                asm("" : "+r"(offset));
                ((volatile u32)address) += (volatile u32)offset;
                *(struct MenuStats553 *)(u8 *volatile)stats =
                    *(struct MenuStats553 *)(volatile u32)address;
                asm("" : : "r"(save), "r"(offset));
            }
            }
            else
            {
                register u32 selected asm("r4");
                register u32 scaled asm("r0");
                register u8 *record asm("r1");
                register u8 *save asm("r5");
                register u32 offset asm("r6");
                register struct MenuStats553 *destination asm("r2");
                ((volatile u32)selected) = frame.second_item;
                ((volatile u32)scaled) = (volatile u32)selected << 3;
                ((u8 *volatile)record) =
                    (u8 *)(((volatile u32)scaled - (volatile u32)selected) << 3);
                ((u8 *volatile)save) = D_02000B5C;
                ((u8 *volatile)record) += (u32)(u8 *volatile)save;
                destination = (struct MenuStats553 *)(formation_stack + 16);
                asm("" : "+r"(destination));
                ((volatile u32)offset) = 0xD54;
                asm("" : "+r"(offset));
                ((u8 *volatile)record) += (volatile u32)offset;
                *destination = *(struct MenuStats553 *)(u8 *volatile)record;
                asm("" : : "r"(save), "r"(offset));
                ((u8 *volatile)save) = (u8 *)&frame.stats;
                asm("" : "+r"(save));
                ((u8 *volatile)stats_base) = (u8 *volatile)save;
                ((volatile u32)model_address) = (volatile u32)scaled;
            }
        summary_stats_ready:
            func_0803E488(D_0875AFB8, 26);
            {
                register u32 selected asm("r6");
                register u8 *save asm("r7");
                ((volatile u32)selected) = frame.second_item;
                asm("" : "+r"(selected));
                ((volatile u32)model_address) =
                    ((volatile u32)model_address - (volatile u32)selected) << 3;
                ((u8 *volatile)save) = D_02000B5C;
                asm("" : "+r"(save));
                ((volatile u32)model_address) += (u32)(u8 *volatile)save;
            }
            {
                register u32 address asm("r0");
                ((volatile u32)address) = 0xD32;
                asm("" : "+r"(address));
                ((volatile u32)address) += (volatile u32)model_address;
                ((const u16 *volatile)model_header) = (u16 *)(volatile u32)address;
                func_08032800(*(u16 *)(volatile u32)address);
            }
            ((const u8 *volatile)messages) = D_0875B0F8;
            {
                register u32 offset asm("r1");
                register u32 address asm("r0");
                register u32 name asm("r1");
                ((volatile u32)offset) = 0xD61;
                asm("" : "+r"(offset));
                ((volatile u32)address) = (volatile u32)model_address + (volatile u32)offset;
                ((volatile u32)name) = *(u8 *)(volatile u32)address;
                ((volatile u32)name) += 8;
                func_0803E488((const u8 *volatile)messages, (volatile u32)name);
            }
            ((const u8 *volatile)separator) = D_08675C5C;
            func_0803E488((const u8 *volatile)separator, 0);
            func_0803E488((const u8 *volatile)messages, 1);
            func_08001848(frame.stats.hp, 4, 0);
            func_0803E488((const u8 *volatile)separator, 0);
            func_0803E488((const u8 *volatile)messages, 2);
            {
                register u8 *stats asm("r2");
                ((u8 *volatile)stats) = (u8 *volatile)stats_base;
                func_08001848(*(s32 *)((u8 *volatile)stats + 4), 4, 0);
            }
            func_0803E488((const u8 *volatile)separator, 0);
            func_0803E488((const u8 *volatile)messages, 3);
            {
                register u8 *stats asm("r3");
                ((u8 *volatile)stats) = (u8 *volatile)stats_base;
                asm("" : "+r"(stats));
                {
                    register u32 held1 asm("r1");
                    register u32 held2 asm("r2");
                    register s32 value asm("r0");
                    asm("" : "=r"(held1), "=r"(held2));
                    value = *(s16 *)(stats + 8);
                    asm("" : : "r"(value), "r"(held1), "r"(held2));
                    func_08001848(value, 4, 0);
                }
            }
            func_0803E488((const u8 *volatile)separator, 0);
            func_0803E488((const u8 *volatile)messages, 4);
            {
                register u8 *stats asm("r1");
                ((u8 *volatile)stats) = (u8 *volatile)stats_base;
                asm("" : "+r"(stats));
                func_08001848(*(s16 *)(stats + 10), 3, 0);
            }
            func_0803E488(D_0875AFB8, 39);
            func_0803E488((const u8 *volatile)separator, 0);
            func_0803E488((const u8 *volatile)messages, 5);
            func_08001848(*(u8 *)((volatile u32)model_address + 0xD60), 3, 0);
            {
                register const u16 *header asm("r4");
                ((const u16 *volatile)header) = (const u16 *volatile)model_header;
                func_0804D654(*(const u16 *volatile)header, 40, 88);
            }
            {
                register u32 first asm("r5");
                ((volatile u32)first) = frame.first_item;
                if ((volatile u32)first == 255)
                {
                    register u32 linked asm("r6");
                    ((volatile u32)linked) = frame.linked_slot;
                    if ((s16)(volatile u32)linked != 87)
                        func_08036B4C((u8)(volatile u32)linked, frame.second_item);
                }
            }
            func_0803E488(D_0875AFB8, 24);
            func_0803E488(D_0875AFB8, 37);
            if (D_02007574[0] == 1)
                state = 0x510;
            else
            {
                func_080019EC(63);
                {
                    register u32 loaded asm("r7") = frame.return_state;
                    register u32 shifted asm("r0");
                    asm("" : "+r"(loaded));
                    shifted = loaded << 16;
                    asm("" : "+r"(shifted));
                    state = shifted >> 16;
                }
            }
            {
                register u8 *address asm("r0");
                register u32 flags asm("r1");
                register u32 mask asm("r3");
                register u32 bits asm("r2");
                ((u8 *volatile)address) = D_03004BBC;
                asm("" : "+r"(address));
                ((u8 *volatile)address) += 0x88;
                ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
                ((volatile u32)mask) = 0x7FFF;
                asm("" : "+r"(flags), "+r"(mask));
                ((volatile u32)bits) = (volatile u32)mask;
                asm("" : "+r"(bits));
                ((volatile u32)flags) &= (volatile u32)bits;
                *(u16 *)(u8 *volatile)address = (volatile u32)flags;
            }
            func_0803E488(D_0875AFB8, 9);
            func_0803E488(D_0875AFB8, 0);
            break;
        }
        case 0x510:
            func_0803E488(D_0875B3B8, 12);
            func_0803E488(D_0875B124, 0);
            func_08054F70(frame.first_item, frame.second_item, 0);
            func_0803E488(D_0875AFB8, 24);
            func_0803E488(D_0875AFB8, 37);
            if (D_02007574[0] == 1)
                state = 0x520;
            else
            {
                func_080019EC(63);
                {
                    register u32 loaded asm("r5") = frame.return_state;
                    register u32 shifted asm("r0");
                    asm("" : "+r"(loaded));
                    shifted = loaded << 16;
                    asm("" : "+r"(shifted));
                    state = shifted >> 16;
                }
                func_0803E488(D_0875AFB8, 9);
                func_0803E488(D_0875AFB8, 0);
            }
            break;
        case 0x520:
            func_0803E488(D_0875B124, 1);
            func_08054F70(frame.first_item, frame.second_item, 1);
            func_0803E488(D_0875AFB8, 18);
            func_0803E488(D_0875AFB8, 37);
            if (D_02007574[0] == 1)
                state = 0x530;
            else
            {
                func_080019EC(63);
                {
                    register u32 loaded asm("r6") = frame.return_state;
                    register u32 shifted asm("r0");
                    asm("" : "+r"(loaded));
                    shifted = loaded << 16;
                    asm("" : "+r"(shifted));
                    state = shifted >> 16;
                }
                func_0803E488(D_0875AFB8, 10);
                func_0803E488(D_0875AFB8, 9);
                func_0803E488(D_0875AFB8, 0);
            }
            break;
        case 0x530:
            func_0803E488(D_0875B124, 2);
            func_08054F70(frame.first_item, frame.second_item, 2);
            func_0803E488(D_0875AFB8, 19);
            func_0803E488(D_0875AFB8, 37);
            if (D_02007574[0] == 1)
                state = 0x540;
            else
            {
                func_080019EC(63);
                {
                    register u32 loaded asm("r7") = frame.return_state;
                    register u32 shifted asm("r0");
                    asm("" : "+r"(loaded));
                    shifted = loaded << 16;
                    asm("" : "+r"(shifted));
                    state = shifted >> 16;
                }
                func_0803E488(D_0875AFB8, 11);
                func_0803E488(D_0875AFB8, 10);
                func_0803E488(D_0875AFB8, 9);
                func_0803E488(D_0875AFB8, 0);
            }
            break;
        case 0x540:
            func_0803E488(D_0875B124, 7);
            func_08055054(frame.first_item, frame.second_item, 3);
            func_0803E488(D_0875AFB8, 17);
            func_0803E488(D_0875AFB8, 37);
            if (D_02007574[0] == 1)
                state = 0x550;
            else
            {
                func_080019EC(63);
                {
                    register u32 loaded asm("r1") = frame.return_state;
                    register u32 shifted asm("r0");
                    asm("" : "+r"(loaded));
                    shifted = loaded << 16;
                    asm("" : "+r"(shifted));
                    state = shifted >> 16;
                }
                func_0803E488(D_0875AFB8, 11);
                func_0803E488(D_0875AFB8, 10);
                func_0803E488(D_0875AFB8, 9);
                func_0803E488(D_0875AFB8, 0);
            }
            break;
        case 0x550:
            func_0803E488(D_0875B124, 8);
            func_08055054(frame.first_item, frame.second_item, 4);
            func_0803E488(D_0875AFB8, 18);
            func_0803E488(D_0875AFB8, 37);
            if (D_02007574[0] == 1)
                state = 0x560;
            else
            {
                func_080019EC(63);
                {
                    register u32 loaded asm("r2") = frame.return_state;
                    register u32 shifted asm("r0");
                    asm("" : "+r"(loaded));
                    shifted = loaded << 16;
                    asm("" : "+r"(shifted));
                    state = shifted >> 16;
                }
                func_0803E488(D_0875AFB8, 11);
                func_0803E488(D_0875AFB8, 10);
                func_0803E488(D_0875AFB8, 9);
                func_0803E488(D_0875AFB8, 0);
            }
            break;
        recovery_empty:
            func_0803E488(menu_pointer.definition, 11);
            {
                register u8 *address asm("r2");
                register u32 flags asm("r0");
                register u32 mask asm("r3");
                register u32 bits asm("r1");
                ((u8 *volatile)address) = D_03004BBC;
                asm("" : "+r"(address));
                ((u8 *volatile)address) += 0x88;
                ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
                ((volatile u32)mask) = 0x7FFF;
                asm("" : "+r"(flags), "+r"(mask));
                ((volatile u32)bits) = (volatile u32)mask;
                asm("" : "+r"(bits));
                ((volatile u32)flags) &= (volatile u32)bits;
                *(u16 *)(u8 *volatile)address = (volatile u32)flags;
            }
            func_0803E488(menu_pointer.definition, 10);
            func_0803E488(D_0875B3B8, 5);
            func_080019EC(65);
            state = 0x20;
            func_0803E488(menu_pointer.definition, 0);
            func_0803E488(D_0875B3B8, 0);
            break;
        cancel_submenu:
            func_080019EC(63);
            state = 0x20;
            func_0803E488(D_0875AFB8, 11);
            {
                register u8 *address asm("r0");
                register u32 flags asm("r1");
                register u32 mask asm("r4");
                register u32 bits asm("r2");
                ((u8 *volatile)address) = D_03004BBC;
                asm("" : "+r"(address));
                ((u8 *volatile)address) += 0x88;
                ((volatile u32)flags) = *(u16 *)(u8 *volatile)address;
                ((volatile u32)mask) = 0x7FFF;
                asm("" : "+r"(flags), "+r"(mask));
                ((volatile u32)bits) = (volatile u32)mask;
                asm("" : "+r"(bits));
                ((volatile u32)flags) &= (volatile u32)bits;
                *(u16 *)(u8 *volatile)address = (volatile u32)flags;
            }
            func_0803E488(D_0875AFB8, 10);
            func_0803E488(D_0875AFB8, 0);
            func_0803E488(D_0875B3B8, 0);
            break;
        case 0x560:
            func_0803E488(D_0875B3B8, 13);
            func_0803E488(D_0875B124, 9);
            func_08055054(frame.first_item, frame.second_item, 5);
            func_0803E488(D_0875AFB8, 19);
            func_0803E488(D_0875AFB8, 37);
            if (D_02007574[0] == 0)
                func_080019EC(63);
            func_0803E488(D_0875AFB8, 11);
            func_0803E488(D_0875AFB8, 10);
            func_0803E488(D_0875AFB8, 9);
            func_0803E488(D_0875AFB8, 0);
            {
                register u32 loaded asm("r5") = frame.return_state;
                asm("" : : "r"(loaded));
                state_shift = loaded << 16;
                asm("" : : "r"(state_shift));
            }
        store_shifted_state553:
            state = (u16)(state_shift >> 16);
            break;
        }
        {
            register u32 shifted asm("r0");
            shifted = state << 16;
            asm("" : : "r"(shifted));
            exit_bits = shifted;
            asm("" : : "r"(exit_bits));
        }
        if ((s32)(volatile u32)exit_bits < 0)
            break;
    }
    func_08003DF8(10, func_08004034);
    {
        register u8 *base asm("r1") = D_02000034;
        register u32 offset asm("r7") = 0x558;
        register u32 *argument asm("r2");
        register u32 zero asm("r0");
        asm("" : : "r"(base), "r"(offset));
        argument = (u32 *)(base + offset);
        asm("" : : "r"(argument));
        *argument = 1;
        zero = 0x55C;
        asm("" : : "r"(zero));
        argument = (u32 *)(base + zero);
        asm("" : : "r"(argument));
        zero = 0;
        *argument = zero;
        {
            register u32 reply_offset asm("r2") = 0x568;
            register u32 *reply asm("r1");
            u32 *waiting;
            asm("" : : "r"(base), "r"(reply_offset));
            reply = (u32 *)(base + reply_offset);
            if (*reply != 1)
            {
                waiting = reply;
                asm("" : : "r"(waiting));
                for (;;)
                {
                    func_0805EE78(1);
                    if (*waiting == 1)
                        break;
                }
            }
        }
    }
    func_08003E3C(10);
    func_08003E3C(5);
    {
        register u8 *base asm("r2") = D_02000034;
        register u8 *current asm("r0") = &D_02000030;
        register u32 task_index asm("r1");
        register u32 offset asm("r0");
        register s32 result asm("r1");
        asm("" : : "r"(base), "r"(current));
        task_index = *current;
        offset = task_index * 136;
        asm("" : : "r"(offset));
        base += 8;
        asm("" : : "r"(base), "r"(offset), "r"(exit_bits));
        offset += (u32)base;
        asm("" : "+r"(exit_bits) : "r"(offset));
        result = (s32)exit_bits >> 16;
        asm("" : : "r"(result));
        *(s32 *)offset = result;
    }
}
