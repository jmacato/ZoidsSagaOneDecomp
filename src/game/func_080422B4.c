#include "types.h"

struct Task
{
    u32 header;
    s16 state;
    u16 pad_6;
    u8 pad_8[16];
    u32 result;
    u8 pad_1C[108];
};
extern u8 D_02000030;
extern struct Task D_02000034[];
extern u8 D_0200DA97, D_0200DA7C, D_0200DA7D;
extern u8 D_0200DA90, D_0200DA93, D_0200DA94, D_0200DA95, D_0200DA96, D_0200DA98;
extern u8 D_0200DA70, D_0200E24B, D_0200E24C, D_0200E24D;
extern u8 D_0200DA80[2][8], D_0200E24E[], D_0200E23C[], D_02010D75;
extern u8 D_0200EB84[], D_0200D920[], D_0200D9C8[], D_03004BBC[];
extern u16 D_0200DA74, D_0200DA72, D_02007574[], D_02000B56, D_03002358;
extern u32 D_0200E284;
extern u8 *D_0200DA78;
extern const u8 D_08755ECC[], D_08755B6C[], D_08755E1C[], D_08755CC4[];
void func_08041D20(void);
void func_0803E024(u32, u32, u32);
void func_08042100(void);
void func_08043E18(void *, u32, u32);
void func_08044DE8(u32, u32, u32);
void func_08044E04(u32, u32);
void func_08000D1C(u32);
void func_080457F8(void *, u32);
void func_0803E454(u32);
s32 func_08048140(u32, u32, u32);
void func_08044F0C(u32, u32);
u8 func_08047D18(void *, u32);
void func_080450E0(u32, u32, u32);
void func_08049050(void *, u32, u32);
void func_08048B0C(void *, u32, u32);
void func_08003DF8(u32, void (*)(void));
void func_08045B64(void);
void func_08003E3C(u32);
void *func_0805ED60(void *, const void *, u32);
void func_0805EE78(u32);
u32 func_08042168(void);
u32 func_08042184(u16, u16);
void func_0803E488(const void *, u32);
void func_08046884(void);
void func_08048530(void *, u32, u32, u32);
u8 func_080420C0(u32, u32);
void func_08001A08(u32);
void func_08047DB4(u32, u32, u32);
void func_08000DF4(u32);
void func_0804206C(void);
void func_08041FE4(void);
u8 func_0804200C(void);
u8 func_08042094(void);
void func_08041E1C(void);

#define READ_HALF(address) (*(u16 *)(address))
#define ACTOR_FIELD(offset) READ_HALF(actor + (offset))
#define UPDATE_SPRITES(start_register) \
    { \
        register u8 *start asm(start_register) = sprite_base; \
        u32 bound; \
        index = *start; \
        bound = index + 18; \
        asm("" : "+r"(index) : "r"(bound), "r"(start)); \
        if ((s32)index < (s32)bound) { \
            register u8 *current asm("r5") = &D_0200DA97; \
            asm("" : : "r"(current), "l"(task)); \
            do { \
                func_08000DF4(index); \
                index = (u16)(index + 1); \
                bound = *current + 18; \
            } while ((s32)index < (s32)bound); \
        } \
    }
#define COUNT_ACTIVE_SPRITES(one_register, start_register) \
    { \
        register u8 *flag asm("r0"); \
        register u32 one asm(one_register); \
        register u8 *start asm(start_register); \
        u32 bound; \
        active = 0; \
        asm("" : "+r"(active)); \
        flag = &D_0200DA70; \
        one = 1; \
        asm("" : : "r"(flag), "r"(one)); \
        *flag = one; \
        start = sprite_base; \
        asm("" : : "r"(start)); \
        index = *start; \
        bound = index + 18; \
        asm("" : "+r"(index) : "r"(bound)); \
        if ((s32)index < (s32)bound) { \
            register u8 *pool asm("r6") = D_03004BBC; \
            asm("" : : "r"(pool), "l"(task)); \
            do { \
                register u32 offset asm("r0"); \
                func_08000DF4(index); \
                offset = index * 136; \
                asm("" : : "r"(offset)); \
                offset += (u32)pool; \
                asm("" : : "r"(offset)); \
                offset += 100; \
                { \
                    register u32 value asm("r0") = *(u8 *)offset; \
                    asm("" : : "r"(value)); \
                    active = (u8)(active + value); \
                } \
                index = (u16)(index + 1); \
                { \
                    register u8 *next_start asm("r1") = sprite_base; \
                    asm("" : : "r"(next_start)); \
                    bound = *next_start + 18; \
                } \
            } while ((s32)index < (s32)bound); \
        } \
    } \
    if (D_03002358 & 1) { \
        register u32 remaining asm("r3") = frame.hold; \
        asm("" : : "r"(remaining)); \
        if (remaining) { \
            register u32 decrement asm("r0") = remaining; \
            asm("" : : "r"(decrement)); \
            frame.hold = (u16)(decrement - 1); \
        } \
        else if (!(READ_HALF(D_0200EB84) & 1)) active = 0; \
    }

void func_080422B4(void)
{
    struct Frame {
        u32 timer;
        u32 hold;
        union { u32 word; u16 half; } next_state;
    } frame;
    register struct Task *task = &D_02000034[D_02000030];
    register u8 *sprite_base asm("r10") = &D_0200DA97;
    register u8 *actor asm("r8");
    u32 index;
    u8 active;
    u32 sprite_state;

    asm("" : : "l"(task), "r"(sprite_base));
    for (;;)
    {
        asm("" : "+l"(task) : : "r4", "r5", "r6", "r9");
        switch (task->state)
        {
        case 0:
            func_08041D20();
            func_0803E024(3, 0, 50);
            index = 0;
            do { D_0200DA80[0][index] = 0; D_0200DA80[1][index] = 0; index = (u16)(index + 1); } while (index <= 5);
            func_08042100();
            {
                register u32 clear asm("r5") = 0;
                register u32 first asm("r9");
                register u8 *second asm("r12");
                register u8 *loaded_first asm("r3") = &D_0200E24B;
                register u8 *loaded_second asm("r0");
                register u8 *unit_base asm("r3");
                u32 enabled;
                first = (u32)loaded_first;
                asm("" : "+r"(first) : "r"(clear), "r"(loaded_first) : "r0");
                loaded_second = &D_0200E24C;
                second = loaded_second;
                asm("" : : "r"(second), "r"(loaded_second));
                *loaded_second = clear;
                *loaded_first = clear;
                {
                    u8 **selected_actor = &D_0200DA78;
                    register u8 *selector asm("r1") = &D_0200DA7C;
                    asm("" : : "r"(selected_actor), "r"(selector), "l"(task));
                    *selected_actor = D_0200D920 + (*selector & 15) * 28;
                }
                unit_base = D_0200EB84;
                enabled = READ_HALF(unit_base) & 3;
                if (enabled != 1)
                    task->state = 0x1050;
                else
                {
                    u32 offset;
                    u16 flags;
                    register u32 part_offset asm("r2");
                    register u8 *empty asm("r6") = &D_0200E24D;
                    *empty = clear;
                    asm("" : : "r"(empty), "r"(unit_base), "l"(task) : "r2");
                    part_offset = 0x21F0;
                    asm("" : "+r"(part_offset));
                    {
                        register u8 *field asm("r0") = unit_base + part_offset;
                        asm("" : : "r"(field));
                        offset = *field * 20;
                    }
                    asm("" : "+r"(offset));
                    part_offset -= 3;
                    {
                        register u8 *field asm("r0") = unit_base + part_offset;
                        asm("" : : "r"(field));
                        offset += *field * 716;
                    }
                    asm("" : "+r"(offset));
                    offset += unit_base[0x21EC] * 0x10D8;
                    {
                        register u8 *records asm("r0") = unit_base + 0x58;
                        asm("" : : "r"(records));
                        offset += (u32)records;
                        asm("" : "+r"(offset));
                        flags = READ_HALF(offset);
                    }
                    if (flags & 4)
                    {
                        register u8 *flag asm("r3") = (u8 *)first;
                        asm("" : : "r"(flag), "l"(task));
                        *flag = enabled;
                    }
                    if (flags & 2) *second = enabled;
                    else *empty = enabled;
                    task->state = 0x10B0;
                }
            }
            break;
        case 0x1050:
            {
                register u8 *selector asm("r1") = &D_0200DA7C;
                register u32 chosen asm("r2");
                register u8 *source_actor asm("r1");
                register u32 zero asm("r5");
                register u32 color asm("r1");
                chosen = *selector;
                asm("" : : "r"(selector), "r"(chosen));
                source_actor = D_0200D920 + (chosen & 15) * 28;
                actor = source_actor;
                asm("" : : "r"(actor), "r"(source_actor));
                D_0200DA90 = chosen & 32;
                {
                    register u8 *view asm("r2") = actor;
                    asm("" : : "r"(view));
                    func_08043E18(actor, view[3], D_0200DA7C);
                }
                color = 0xFF500000;
                zero = 0;
                asm("" : : "r"(color), "r"(zero));
                D_0200E284 = zero;
                func_08044DE8(1, color, 0);
                {
                    register u8 *view asm("r1") = actor;
                    asm("" : : "r"(view));
                    func_08044E04(READ_HALF(view), D_0200DA7C);
                }
                func_08000D1C(0);
                D_0200DA74 = zero;
                func_080457F8(actor, D_0200DA7C);
                {
                    register u8 *view asm("r1") = actor;
                    register u32 actor_value asm("r0");
                    register u16 *variables asm("r2");
                    asm("" : : "r"(view));
                    actor_value = view[21];
                    variables = D_02007574;
                    asm("" : : "r"(actor_value), "r"(variables));
                    variables[6] = actor_value;
                    variables[7] = zero;
                }
                func_0803E454(11);
                {
                    register u32 next asm("r3") = 0x1051;
                    asm("" : : "r"(next));
                    frame.next_state.word = next;
                }
                task->state = 0x1000;
            }
            break;
        case 0x1051:
            {
                register u8 *unit_base asm("r3");
                u32 flags;
                register u32 one asm("r4");
                register u32 mask asm("r0");
                func_08048140(1, 0, 0);
                {
                    register u8 *view asm("r1") = actor;
                    asm("" : : "r"(view));
                    func_08044F0C(READ_HALF(view), D_0200DA7C);
                }
                unit_base = D_0200EB84;
                flags = READ_HALF(unit_base);
                one = 1;
                mask = 1;
                asm("" : : "r"(unit_base), "r"(flags), "r"(one), "r"(mask));
                mask &= flags;
                if (mask || D_0200DA90 == 32)
                {
                    register u8 *empty asm("r5") = &D_0200E24D;
                    u32 offset;
                    asm("" : : "r"(empty));
                    *empty = 0;
                    offset = unit_base[0x21F0] * 20;
                    asm("" : "+r"(offset));
                    offset += unit_base[0x21ED] * 716;
                    asm("" : "+r"(offset));
                    offset += unit_base[0x21EC] * 0x10D8;
                    {
                        register u8 *records asm("r0") = unit_base + 0x58;
                        asm("" : : "r"(records));
                        offset += (u32)records;
                        asm("" : "+r"(offset));
                        flags = READ_HALF(offset);
                    }
                    if (flags & 4) { D_0200E24B = one; D_0200E24C = one; }
                    else if (flags & 2) { D_0200E24C = one; D_0200E24B = one; }
                    else *empty = one;
                    task->state = 0x1010;
                }
                else task->state = 0x1052;
            }
            break;
        case 0x1052:
            {
                register u32 value asm("r0") = func_08047D18(D_0200DA78, D_0200E24E[D_0200DA7C & 15]);
                register u16 *variables asm("r2");
                variables = D_02007574;
                asm("" : : "r"(value), "r"(variables));
                variables[7] = value;
            }
            {
                register u16 *start asm("r1") = &D_0200DA74;
                register u32 amount asm("r3");
                register u32 value asm("r0");
                amount = 384;
                value = amount;
                asm("" : : "r"(start), "r"(amount), "r"(value));
                *start = value;
            }
            func_080450E0(16, 8, 0);
            func_08049050(actor, 0, 0);
            {
                register u8 *variables asm("r0") = (u8 *)D_02007574;
                asm("" : : "r"(variables));
                func_08048B0C(actor, variables[14], 0);
            }
            task->state = 0x1053;
        case 0x1053:
            func_08003DF8(8, func_08045B64);
            task->state = 0x1054;
            break;
        case 0x1054:
            if (D_02000034[8].result == 1)
            {
                register u16 *variables asm("r3");
                register u32 value asm("r0");
                register u8 *units asm("r2");
                register u32 field asm("r3");
                register u8 *destination asm("r1");
                func_08003E3C(8);
                variables = D_02007574;
                asm("" : : "r"(variables));
                value = variables[7];
                units = D_0200EB84;
                field = 0x21F0;
                asm("" : : "r"(value), "r"(units), "r"(field));
                destination = units + field;
                *destination = value;
                if ((u8)value == 2)
                {
                    register u8 *pool asm("r4");
                    register u8 *first asm("r6");
                    register u8 *second asm("r5");
                    register u32 first_offset asm("r2");
                    register u32 second_offset asm("r3");
                    register u32 target_offset asm("r1");
                    register u32 count asm("r0") = 3;
                    asm("" : : "r"(count));
                    (*sprite_base) = count;
                    pool = D_03004BBC;
                    first_offset = 0xAA0;
                    asm("" : : "r"(pool), "r"(first_offset), "l"(task));
                    first = pool + first_offset;
                    asm("" : : "r"(first));
                    func_0805ED60(pool + 136, first, 136);
                    second_offset = 0xB28;
                    asm("" : : "r"(second_offset));
                    second = pool + second_offset;
                    target_offset = 272;
                    asm("" : : "r"(second), "r"(target_offset));
                    func_0805ED60(pool + target_offset, second, 136);
                    READ_HALF(first) &= 0x7FFF;
                    READ_HALF(second) &= 0x7FFF;
                }
                task->state = 0x1010;
            }
            if (D_02000034[8].result == 2)
            {
                register u16 *variables asm("r2");
                register u32 value asm("r0");
                register u8 *units asm("r3");
                register u32 field asm("r2");
                register u8 *destination asm("r1");
                func_08003E3C(8);
                variables = D_02007574;
                asm("" : : "r"(variables));
                value = variables[7];
                units = D_0200EB84;
                field = 0x21F0;
                asm("" : : "r"(value), "r"(units), "r"(field));
                destination = units + field;
                *destination = value;
                {
                    register u32 next asm("r3") = 0x2010;
                    asm("" : : "r"(next));
                    frame.next_state.word = next;
                }
                task->state = 0x1001;
            }
            break;
        case 0x1010:
            func_08048140(1, 0, 0);
            {
                register u8 *units asm("r0") = D_0200EB84;
                register u32 header asm("r1");
                header = READ_HALF(units);
                asm("" : : "r"(units), "r"(header));
                if (header & 1)
            {
                register u32 period asm("r1") = 90;
                register u32 limit asm("r2");
                asm("" : "+r"(period));
                frame.timer = period;
                index = 0;
                do
                {
                    func_0805EE78(1);
                    index = (u16)(index + 1);
                    limit = frame.timer;
                    asm("" : : "r"(limit));
                } while (index < limit);
            }
            else
            {
                register u32 period asm("r3") = 30;
                register u32 limit asm("r0");
                asm("" : "+r"(period));
                frame.timer = period;
                index = 0;
                do
                {
                    func_0805EE78(1);
                    index = (u16)(index + 1);
                    limit = frame.timer;
                    asm("" : : "r"(limit));
                } while (index < limit);
            }
            }
            {
                register u32 period asm("r1") = 30;
                register u32 current_hold asm("r2");
                frame.timer = period;
                current_hold = 60;
                asm("" : : "r"(period), "r"(current_hold));
                frame.hold = current_hold;
            }
            func_0803E454(18);
            {
                register u8 *part asm("r2") = &D_0200DA93;
                register u8 *units asm("r3") = D_0200EB84;
                register u32 offset asm("r1") = 0x21F0;
                register u16 *selection asm("r4");
                register u16 *variables asm("r5");
                register u32 response asm("r3");
                asm("" : : "r"(part), "r"(units), "r"(offset), "l"(task));
                {
                    register u8 *field asm("r0") = units + offset;
                    asm("" : : "r"(field));
                    *part = *field;
                }
                selection = &D_0200DA72;
                {
                    register u8 *definitions asm("r1") = D_0200E23C;
                    asm("" : : "r"(selection), "r"(definitions));
                    *selection = READ_HALF(definitions + *part * 2);
                }
                {
                    u32 value = func_08042168();
                    variables = D_02007574;
                    asm("" : : "r"(variables));
                    variables[3] = (u8)value;
                }
                response = func_08042184(*selection, variables[3]);
                asm("" : : "r"(response));
                variables[3] = response;
                {
                register u8 *view asm("r2") = actor;
                register u32 unit asm("r1");
                register u32 address asm("r0");
                register u32 side asm("r2");
                register u32 side_offset asm("r1");
                register u8 *units asm("r1");
                register u32 script asm("r1");
                asm("" : : "r"(view), "l"(task));
                unit = view[23];
                address = unit * 716;
                side = view[22];
                asm("" : : "r"(address), "r"(side));
                side_offset = side * 0x10D8;
                address += side_offset;
                units = D_0200EB84;
                asm("" : : "r"(address), "r"(units));
                address += (u32)units;
                address += 0xD6;
                script = *(u8 *)address;
                asm("" : : "r"(script));
                if (script == 255)
                {
                    register u32 argument asm("r1");
                    if (!D_0200E24B)
                    {
                        register u32 mask asm("r2") = 0x8000;
                        register u32 test asm("r0") = mask;
                        asm("" : : "r"(mask), "r"(test), "r"(response));
                        test &= response;
                        if (test)
                        {
                            register u32 mask asm("r1") = 0x7FFF;
                            register u32 value asm("r0") = mask;
                            asm("" : : "r"(mask), "r"(value), "r"(response));
                            value &= response;
                            variables[3] = value;
                            func_0803E488(D_08755ECC, variables[3]);
                            goto attacker_script_done;
                        }
                        {
                            register u8 *view asm("r2") = actor;
                            asm("" : : "r"(view));
                            argument = view[21];
                        }
                    }
                    else
                    {
                        variables[3] = 3;
                        {
                            register u8 *view asm("r3") = actor;
                            asm("" : : "r"(view));
                            argument = view[21];
                        }
                    }
                    func_0803E488(D_08755B6C, argument);
                }
                else func_0803E488(D_08755E1C, script);
                }
            }
attacker_script_done:
            {
                register u8 *skip asm("r1") = &D_02010D75;
                asm("" : : "r"(skip), "l"(task));
                if (!*skip) func_08046884();
            }
            func_08048530(actor, D_0200DA72, D_0200DA93, D_0200DA7C);
            {
                register u32 next asm("r1") = 0x10B0;
                asm("" : : "r"(next));
                frame.next_state.word = next;
            }
            task->state = 0x1070;
            break;
        case 0x10B0:
            {
                register u32 chosen asm("r5") = func_080420C0(D_0200DA90, 0);
                register u32 clear asm("r6");
                u32 flags;
                register u8 *target_ref asm("r9");
                register u8 *unit_base asm("r12");
                if (chosen == 255) goto target_window_done;
                clear = D_0200E24C;
                if (clear) goto target_window_done;
                {
                    register u8 *loaded_units asm("r2") = D_0200EB84;
                    register u32 header asm("r1");
                    register u32 gate asm("r0");
                    header = READ_HALF(loaded_units);
                    gate = 5;
                    gate &= header;
                    unit_base = loaded_units;
                    asm("" : : "r"(unit_base), "r"(gate), "r"(loaded_units));
                    if (gate == 1) goto target_window_done;
                }
                {
                    register u8 *loaded_target asm("r2") = &D_0200DA7D;
                    register u32 encoded asm("r3");
                    register u32 side_mask asm("r1") = 32;
                    register u32 mask asm("r4");
                    encoded = chosen & side_mask;
                    encoded |= 16;
                    asm("" : : "r"(encoded), "r"(side_mask), "r"(loaded_target) : "r4");
                    mask = 15;
                    chosen &= mask;
                    encoded |= chosen;
                    *loaded_target = encoded;
                    {
                        register u32 selected_side asm("r0") = encoded & side_mask;
                        asm("" : "+r"(selected_side) : "r"(encoded), "r"(side_mask), "r"(mask));
                        chosen = (u8)selected_side;
                    }
                    target_ref = loaded_target;
                if (chosen)
                {
                    register u32 unit asm("r2") = mask;
                    unit &= encoded;
                    actor = D_0200D9C8 + unit * 28;
                    {
                        register u32 address asm("r0") = unit * 12 + (u32)unit_base;
                        register u32 offset asm("r2");
                        register u32 status asm("r1");
                        register u32 one asm("r2");
                        register u32 test asm("r0");
                        offset = 0x2254;
                        asm("" : : "r"(address), "r"(offset));
                        address += offset;
                        status = READ_HALF(address);
                        one = 1;
                        test = 1;
                        test &= status;
                        if (test) D_0200DA94 = clear;
                        else D_0200DA94 = one;
                    }
                    {
                        register u8 *view asm("r3") = target_ref;
                        register u32 address asm("r0");
                        register u32 offset asm("r1");
                        register u32 value asm("r0");
                        register u32 mask asm("r2");
                        register u32 test asm("r1");
                        register u32 normalized asm("r1");
                        u32 unit;
                        unit = *view & 15;
                        address = unit * 12 + (u32)unit_base;
                        offset = 0x2254;
                        asm("" : : "r"(address), "r"(offset));
                        address += offset;
                        value = READ_HALF(address);
                        mask = 0x8000;
                        test = mask;
                        asm("" : "+r"(value), "+r"(test) : "r"(mask));
                        value &= test;
                        normalized = (u16)value;
                        if (normalized)
                        {
                            register u8 *destination asm("r0") = &D_0200DA95;
                            register u32 one asm("r3");
                            one = 1;
                            *destination = one;
                        }
                        else
                        {
                            register u8 *destination asm("r0") = &D_0200DA95;
                            *destination = normalized;
                        }
                    }
                    {
                        register u8 *view asm("r1") = target_ref;
                        register u32 address asm("r0");
                        register u32 offset asm("r2");
                        register u32 status asm("r1");
                        register u32 mask asm("r0");
                        register u32 normalized asm("r1");
                        u32 unit;
                        unit = *view & 15;
                        address = unit * 12 + (u32)unit_base;
                        offset = 0x2254;
                        asm("" : : "r"(address), "r"(offset));
                        address += offset;
                        status = READ_HALF(address);
                        mask = 2;
                        asm("" : : "r"(status), "r"(mask));
                        mask &= status;
                        normalized = (u16)mask;
                        flags = normalized;
                    }
                    if (flags) goto target_status_set;
                    goto target_status_clear;
                }
                else
                {
                    register u32 unit asm("r2") = mask;
                    unit &= encoded;
                    actor = D_0200D920 + unit * 28;
                    {
                        register u32 address asm("r0") = unit * 12 + (u32)unit_base;
                        register u32 offset asm("r1");
                        register u32 status asm("r1");
                        register u32 one asm("r2");
                        register u32 test asm("r0");
                        offset = 0x220C;
                        asm("" : : "r"(address), "r"(offset));
                        address += offset;
                        status = READ_HALF(address);
                        one = 1;
                        test = 1;
                        test &= status;
                        if (test) D_0200DA94 = chosen;
                        else D_0200DA94 = one;
                    }
                    {
                        register u8 *view asm("r2") = target_ref;
                        register u32 address asm("r0");
                        register u32 offset asm("r3");
                        register u32 value asm("r0");
                        register u32 mask asm("r2");
                        register u32 test asm("r1");
                        register u32 normalized asm("r1");
                        u32 unit;
                        unit = *view & 15;
                        address = unit * 12 + (u32)unit_base;
                        offset = 0x220C;
                        asm("" : : "r"(address), "r"(offset));
                        address += offset;
                        value = READ_HALF(address);
                        mask = 0x8000;
                        test = mask;
                        asm("" : "+r"(value), "+r"(test) : "r"(mask));
                        value &= test;
                        normalized = (u16)value;
                        if (normalized)
                        {
                            register u8 *destination asm("r0") = &D_0200DA95;
                            register u32 one asm("r3");
                            one = 1;
                            *destination = one;
                        }
                        else
                        {
                            register u8 *destination asm("r0") = &D_0200DA95;
                            *destination = normalized;
                        }
                    }
                    {
                        register u8 *view asm("r1") = target_ref;
                        register u32 address asm("r0");
                        register u32 offset asm("r2");
                        register u32 status asm("r1");
                        register u32 mask asm("r0");
                        register u32 normalized asm("r1");
                        u32 unit;
                        unit = *view & 15;
                        address = unit * 12 + (u32)unit_base;
                        offset = 0x220C;
                        asm("" : : "r"(address), "r"(offset));
                        address += offset;
                        status = READ_HALF(address);
                        mask = 2;
                        asm("" : : "r"(status), "r"(mask));
                        mask &= status;
                        normalized = (u16)mask;
                        flags = normalized;
                    }
                }
                if (!flags) goto target_status_clear;
target_status_set:
                {
                    register u8 *destination asm("r0") = &D_0200DA96;
                    register u32 one asm("r3");
                    one = 1;
                    *destination = one;
                }
                goto target_status_done;
target_status_clear:
                {
                    register u8 *destination asm("r0") = &D_0200DA96;
                    *destination = flags;
                }
target_status_done:
                task->state = 0x1060;
                }
                break;
target_window_done:
                task->state = 0x2000;
            }
            break;
        case 0x1060:
            {
                register u8 *selector asm("r4");
                register u32 zero asm("r5");
                register u32 color asm("r1");
                func_08001A08(D_02000B56);
                {
                    register u32 one asm("r1") = 1;
                    asm("" : : "r"(one));
                    (*sprite_base) = one;
                }
                {
                    register u8 *reset asm("r0") = &D_0200DA98;
                    register u32 clear asm("r2");
                    clear = 0;
                    asm("" : : "r"(reset), "r"(clear));
                    *reset = clear;
                    reset = &D_0200DA70;
                    asm("" : : "r"(reset));
                    *reset = clear;
                }
                {
                    register u8 *visible asm("r2") = &D_0200DA90;
                    selector = &D_0200DA7D;
                    asm("" : : "r"(visible), "r"(selector), "l"(task));
                    *visible = *selector & 32;
                }
                {
                    register u8 *view asm("r3") = actor;
                    asm("" : : "r"(view));
                    func_08043E18(actor, view[3], *selector);
                }
                color = 0xFF500000;
                zero = 0;
                asm("" : : "r"(color), "r"(zero));
                D_0200E284 = zero;
                func_08044DE8(1, color, 0);
                {
                    register u8 *view asm("r1") = actor;
                    asm("" : : "r"(view));
                    func_08044E04(READ_HALF(view), *selector);
                }
                func_08000D1C(0);
                D_0200DA74 = zero;
                func_080457F8(actor, *selector);
                {
                    register u8 *view asm("r2") = actor;
                    register u32 actor_value asm("r0");
                    register u16 *variables asm("r3");
                    asm("" : : "r"(view));
                    actor_value = view[21];
                    variables = D_02007574;
                    asm("" : : "r"(actor_value), "r"(variables));
                    variables[6] = actor_value;
                    variables[7] = zero;
                }
                func_0803E454(11);
                func_08047DB4(31, 1, 15);
                {
                    register u32 next asm("r0") = 0x1061;
                    asm("" : : "r"(next));
                    frame.next_state.word = next;
                }
                task->state = 0x1000;
            }
            break;
        case 0x1061:
            {
                register u8 *selector asm("r4");
                func_08048140(1, 0, 0);
                {
                    register u8 *view asm("r1") = actor;
                    register u32 id asm("r0");
                    id = READ_HALF(view);
                    selector = &D_0200DA7D;
                    asm("" : : "r"(view), "r"(id), "r"(selector), "l"(task));
                    func_08044F0C(id, *selector);
                }
                func_08048530(actor, D_0200DA72, D_0200DA93, *selector);
                {
                    register u32 count asm("r2") = 35;
                    asm("" : : "r"(count));
                    frame.hold = count;
                }
                task->state = 0x1090;
                {
                    register u32 next asm("r3") = 0x10B0;
                    asm("" : : "r"(next));
                    frame.next_state.word = next;
                }
            }
            break;
        case 0x10A0:
            index = (*sprite_base);
            {
                u32 bound = index + 18;
                asm("" : "+r"(index) : "r"(bound));
                if ((s32)index < (s32)bound)
                {
                    register u8 *pool asm("r5") = D_03004BBC;
                    asm("" : : "r"(pool), "l"(task));
                    do
                    {
                        register u8 *sprite asm("r2");
                        func_08000DF4(index);
                        {
                            register u32 offset asm("r0") = index * 136;
                            asm("" : : "r"(offset));
                            sprite = (u8 *)(offset + (u32)pool);
                        }
                        asm("" : : "r"(sprite));
                        if (READ_HALF(sprite) & 0x800)
                        {
                            register u8 *field asm("r0") = sprite + 0x6E;
                            register u32 one asm("r1") = 1;
                            asm("" : : "r"(field), "r"(one));
                            READ_HALF(field) = one;
                            READ_HALF(sprite) &= 0xF7FF;
                        }
                        index = (u16)(index + 1);
                        {
                            register u8 *start asm("r1") = sprite_base;
                            asm("" : : "r"(start));
                            bound = *start + 18;
                        }
                    } while ((s32)index < (s32)bound);
                }
            }
            {
                register u8 *view asm("r2") = actor;
                register u32 unit asm("r1");
                register u32 address asm("r0");
                register u32 side asm("r2");
                register u32 side_offset asm("r1");
                register u8 *units asm("r3");
                register u32 script asm("r1");
                asm("" : : "r"(view), "l"(task));
                unit = view[23];
                address = unit * 716;
                side = view[22];
                asm("" : : "r"(address), "r"(side));
                side_offset = side * 0x10D8;
                address += side_offset;
                units = D_0200EB84;
                asm("" : : "r"(address), "r"(units));
                address += (u32)units;
                address += 0xD6;
                script = *(u8 *)address;
                asm("" : : "r"(script));
                if (script == 255)
                {
                    if (D_0200DA94)
                    {
                        register u32 value asm("r0") = 4;
                        register u16 *variables asm("r1");
                        variables = D_02007574;
                        asm("" : : "r"(value), "r"(variables));
                        variables[3] = value;
                    }
                    else if (D_0200DA95)
                    {
                        register u32 value asm("r0") = 3;
                        register u16 *variables asm("r2");
                        variables = D_02007574;
                        asm("" : : "r"(value), "r"(variables));
                        variables[3] = value;
                    }
                    else
                    {
                        register u32 value asm("r0") = (u8)func_08042168();
                        register u16 *variables asm("r3");
                        variables = D_02007574;
                        asm("" : : "r"(value), "r"(variables));
                        variables[3] = value;
                    }
                    {
                        register u8 *view asm("r0") = actor;
                        asm("" : : "r"(view));
                        func_0803E488(D_08755CC4, view[21]);
                    }
                }
                else func_0803E488(D_08755E1C, script);
            }
            {
                register u8 *start asm("r1") = sprite_base;
                asm("" : : "r"(start));
                index = *start;
            }
            {
                u32 bound = index + 18;
                asm("" : "+r"(index) : "r"(bound));
                if ((s32)index < (s32)bound)
                {
                    register u8 *pool asm("r5") = D_03004BBC;
                    asm("" : : "r"(pool), "l"(task));
                    do
                    {
                        register u8 *sprite asm("r2");
                        {
                            register u32 offset asm("r0") = index * 136;
                            asm("" : : "r"(offset));
                            sprite = (u8 *)(offset + (u32)pool);
                        }
                        asm("" : : "r"(sprite));
                        if (READ_HALF(sprite + 0x6E)) READ_HALF(sprite) |= 0x800;
                        func_08000DF4(index);
                        index = (u16)(index + 1);
                        {
                            register u8 *start asm("r1") = sprite_base;
                            asm("" : : "r"(start));
                            bound = *start + 18;
                        }
                    } while ((s32)index < (s32)bound);
                }
            }
            {
                register u8 *units asm("r2") = D_0200EB84;
                register u32 header asm("r1");
                register u32 mode asm("r0");
                register u32 initial asm("r3");
                header = READ_HALF(units);
                mode = 1;
                mode &= header;
                initial = 180;
                asm("" : "+r"(mode) : "r"(units), "r"(header), "r"(initial), "l"(task));
                frame.timer = initial;
                if (!mode)
                {
                    register u32 normal asm("r0") = 50;
                    register u32 current_hold asm("r1");
                    asm("" : : "r"(normal));
                    frame.timer = normal;
                    current_hold = frame.hold;
                    asm("" : : "r"(current_hold));
                    if (!current_hold)
                    {
                        register u32 short_timer asm("r2") = 10;
                        asm("" : : "r"(short_timer));
                        frame.timer = short_timer;
                    }
                }
            }
            task->state = 0x1005;
            break;
        case 0x1090:
            COUNT_ACTIVE_SPRITES("r3", "r0");
            if (active) break;
            sprite_state = 0x10A0;
            goto active_sprites_done;
        case 0x1070:
            COUNT_ACTIVE_SPRITES("r2", "r3");
            if (active) break;
            sprite_state = 0x1005;
active_sprites_done:
            task->state = sprite_state;
            D_0200DA70 = 0;
            break;
        case 0x1000:
            func_0804206C();
            task->state = 0x1002;
            UPDATE_SPRITES("r2");
            break;
        case 0x1001:
            func_08041FE4();
            task->state = 0x1003;
            UPDATE_SPRITES("r3");
            break;
        case 0x1003:
            if (func_0804200C())
            {
                register struct Frame *values asm("r0") = &frame;
                asm("" : : "r"(values));
                task->state = values->next_state.half;
            }
            UPDATE_SPRITES("r1");
            break;
        case 0x1002:
            if (func_08042094())
            {
                register struct Frame *values asm("r2") = &frame;
                register u16 state asm("r2");
                asm("" : : "r"(values));
                state = values->next_state.half;
                asm("" : : "r"(state));
                task->state = state;
            }
            UPDATE_SPRITES("r3");
            break;
        case 0x1005:
            if (frame.timer)
            {
                frame.timer = (u16)(frame.timer - 1);
                {
                    register u32 remaining asm("r1") = frame.hold;
                    asm("" : : "r"(remaining));
                    if (remaining)
                    {
                        register u32 keys asm("r1") = D_03002358;
                        asm("" : : "r"(keys));
                        if (keys & 1) frame.hold = (u16)(frame.hold - 1);
                    }
                    else
                    {
                        register u32 keys asm("r1") = D_03002358;
                        asm("" : : "r"(keys));
                        if (keys & 1)
                        {
                            register u32 zero asm("r2") = 0;
                            asm("" : : "r"(zero));
                            frame.timer = zero;
                        }
                    }
                }
            }
            else task->state = 0x1001;
            UPDATE_SPRITES("r3");
            break;
        case 0x2000:
            func_08041E1C();
            task->state = 0x2001;
            task->result = 1;
            func_08003E3C(6);
            break;
        case 0x2010:
            func_08041E1C();
            task->state = 0x2001;
            task->result = 2;
            func_08003E3C(6);
            break;
        }
        asm("" : "+l"(task) : : "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r9");
        func_0805EE78(1);
        asm("" : "+l"(task) : : "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r9");
    }
}
