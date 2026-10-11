#include "types.h"
extern u8 D_02000B56[];
extern u8 D_02007574[];
extern u8 D_02007588[];
extern u8 D_0200758A[];
extern u8 D_0200758C[];
extern u8 D_0200758D[];
extern u8 D_020075A0[];
extern u8 D_020075B0[];
extern u8 D_02009118[];
extern u8 D_0300235A[];
extern u8 D_03004BBC[];


struct ByteWindow { u8 unk0; u8 unk1; u8 unk2; u8 unk3; u8 unk4; u8 unk5; u8 unk6; u8 unk7; u8 unk8; u8 unk9; u8 unkA; u8 unkB; u8 unkC; u8 unkD; u8 unkE; u8 unkF; };
struct ScriptTemps { u16 unk0; u16 unk2; u16 rest[6]; };
struct ScriptFrame { u8 arguments[16]; volatile u16 temporary[8]; volatile u16 variables[8]; };
#define spC frame.arguments
#define sp1C frame.temporary
#define sp2C frame.variables

void dispatch_window_callback(u8, s32, s32, s32);
void func_08000F88(u16);
void func_08000FD8(u16);
u16 func_08001040(u16);
u16 func_0800175C(s32, s32);
void func_08001A08(u16);
void func_080404BC(u8, u8);
void func_080404F0(u8, u8, u8, s32);
void func_08040828(u8);
u16 func_080408D0(u16, s32, u8, s32);
void func_08040A14(u8);
void func_08040A94(u8);
void func_08040AD4(u8);
void func_08040D0C(u8, u8);
void func_08040DF0();
void func_08040E40();
void func_08040E90();
void func_08040EC8(u8);
void func_08040F44(u8, u16, u32, u8);
void func_08041100();
void func_08041498(u8);
void func_08041540(u8, u8, u8, u8, s32, s32, s32);
u32 func_0805D484(u32, u32);
void func_0805EE78(u8);
const u8 *script_get_entry(u16);
void window_command(u8, s32, s32, s32);
void window_emit_character(u8, u16);

static inline void dispatch_script_window(u8 window, s32 command, s32 high, s32 low)
{
    register u32 callback asm("r4") = *(const u32 *)((((u32)D_020075A0) + 16) + window * 0x354);
    asm volatile("" : : "r"(callback));
    dispatch_window_callback(window, command, high, low);
}

s32 script_interpret(const u8 *arg0) {
    struct ScriptFrame frame;
    register u32 command_window_base asm("r2");
    register u8 *command_arguments asm("r0");
    u8 callback_window;
    s32 temp_r1_24;
    register s32 var_r0_5 asm("r0");
    s32 var_r1;
    register s32 var_r1_4 asm("r1");
    s32 var_r2;
    register volatile u16 *menu_variables asm("r9");
    register volatile u16 *menu_keys asm("r6");
    const u8 *var_r4;
    volatile u16 *temp_r1_18;
    volatile u16 *temp_r1_19;
    register volatile u16 *var_r1_5 asm("r1");
    register volatile u16 *var_r1_6 asm("r1");
    register volatile u16 *var_r2_4 asm("r2");
    register volatile u16 *var_r4_2 asm("r4");
    u16 temp_r0_16;
    u16 temp_r0_41;
    u16 temp_r0_45;
    u16 temp_r1_10;
    u16 temp_r1_14;
    u16 temp_r1_5;
    u16 temp_r1_9;
    u16 temp_r2_10;
    u16 temp_r2_11;
    u16 temp_r2_12;
    u16 temp_r2_13;
    register u16 var_r0_10 asm("r0");
    u16 var_r0_2;
    u16 var_r0_3;
    u16 var_r0_4;
    register u16 var_r0_7 asm("r0");
    register u16 var_r0_8 asm("r0");
    register u32 var_r0_9 asm("r0");
    u16 var_r1_2;
    register u32 var_r1_7 asm("r1");
    register u16 var_r2_2 asm("r2");
    register u16 var_r2_3 asm("r2");
    u32 temp_r0_15;
    u32 temp_r0_25;
    u32 temp_r0_31;
    u32 temp_r0_40;
    u32 temp_r1_21;
    const u8 *temp_r4;
    const u8 *temp_r4_2;
    const u8 *temp_r4_3;
    const u8 *temp_r4_4;
    const u8 *temp_r4_5;
    const u8 *var_r7;
    u8 temp_r0;
    u8 temp_r0_10;
    u8 temp_r0_11;
    u8 temp_r0_12;
    u8 temp_r0_13;
    u8 temp_r0_14;
    u8 temp_r0_17;
    u8 temp_r0_18;
    u8 temp_r0_19;
    u8 temp_r0_20;
    u8 temp_r0_21;
    u8 temp_r0_22;
    u8 temp_r0_23;
    u8 temp_r0_24;
    u8 temp_r0_26;
    u8 temp_r0_27;
    u8 temp_r0_28;
    u8 temp_r0_29;
    u8 temp_r0_2;
    u8 temp_r0_30;
    u8 temp_r0_32;
    u8 temp_r0_33;
    u8 temp_r0_34;
    u8 temp_r0_35;
    u8 temp_r0_36;
    u8 temp_r0_37;
    u8 temp_r0_38;
    u8 temp_r0_39;
    u8 temp_r0_3;
    u8 temp_r0_42;
    u8 temp_r0_43;
    u8 temp_r0_44;
    u8 temp_r0_4;
    u8 temp_r0_5;
    u8 temp_r0_6;
    u8 temp_r0_7;
    u8 temp_r0_8;
    u8 temp_r0_9;
    u8 temp_r1_23;
    u8 temp_r1_2;
    u8 temp_r1_4;
    u8 temp_r2_14;
    u8 temp_r2_16;
    u8 temp_r2_2;
    u8 temp_r2_3;
    u8 temp_r2_4;
    u8 temp_r2_6;
    u8 temp_r2_8;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r3_3;
    u8 temp_r3_4;
    u8 temp_r3_5;
    u8 temp_r3_6;
    u8 temp_r3_7;
    u8 var_r0;
    register u32 var_r0_6 asm("r0");
    register u32 var_r1_3 asm("r1");
    struct ByteWindow *temp_r1;
    struct ByteWindow *temp_r1_11;
    struct ByteWindow *temp_r1_12;
    struct ByteWindow *temp_r1_13;
    struct ByteWindow *temp_r1_15;
    struct ByteWindow *temp_r1_16;
    struct ByteWindow *temp_r1_17;
    struct ByteWindow *temp_r1_20;
    struct ByteWindow *temp_r1_22;
    struct ByteWindow *temp_r1_3;
    struct ByteWindow *temp_r1_6;
    struct ByteWindow *temp_r1_7;
    struct ByteWindow *temp_r1_8;
    struct ByteWindow *temp_r2;
    struct ByteWindow *temp_r2_15;
    struct ByteWindow *temp_r2_5;
    struct ByteWindow *temp_r2_7;
    struct ByteWindow *temp_r2_9;
    const u8 *temp_r7;
    const u8 *temp_r7_10;
    const u8 *temp_r7_11;
    const u8 *temp_r7_12;
    const u8 *temp_r7_13;
    const u8 *temp_r7_14;
    const u8 *temp_r7_15;
    const u8 *temp_r7_16;
    const u8 *temp_r7_17;
    const u8 *temp_r7_18;
    const u8 *temp_r7_19;
    const u8 *temp_r7_20;
    const u8 *temp_r7_21;
    const u8 *temp_r7_22;
    const u8 *temp_r7_23;
    const u8 *temp_r7_24;
    const u8 *temp_r7_25;
    const u8 *temp_r7_26;
    const u8 *temp_r7_27;
    const u8 *temp_r7_28;
    const u8 *temp_r7_29;
    const u8 *temp_r7_2;
    const u8 *temp_r7_30;
    const u8 *temp_r7_31;
    const u8 *temp_r7_32;
    const u8 *temp_r7_33;
    const u8 *temp_r7_34;
    const u8 *temp_r7_35;
    const u8 *temp_r7_36;
    const u8 *temp_r7_37;
    const u8 *temp_r7_38;
    const u8 *temp_r7_39;
    const u8 *temp_r7_3;
    const u8 *temp_r7_40;
    const u8 *temp_r7_41;
    const u8 *temp_r7_42;
    const u8 *temp_r7_43;
    const u8 *temp_r7_4;
    const u8 *temp_r7_5;
    const u8 *temp_r7_6;
    const u8 *temp_r7_7;
    const u8 *temp_r7_8;
    const u8 *temp_r7_9;
    const u8 *var_r7_2;
    register const u8 *branch_origin asm("r4");

    asm volatile("" : : : "r9", "r10");
loop_0:
    var_r7 = arg0;
loop_1:
    temp_r0 = var_r7[0];
    switch (temp_r0) {
    case 0:
        goto block_457;
    case 0x3A:
        var_r7 += 1;
        spC[0] = *var_r7;
        func_080404BC(0xFFU, spC[0]);
        goto block_457;
    default:
        goto block_457;
    case 0x1:
        var_r7 += 1;
        spC[0] = *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        var_r7 += 1;
        spC[3] = (u8) *var_r7;
        var_r7 += 1;
        spC[4] = (u8) *var_r7;
        var_r7 += 1;
        spC[5] = (u8) *var_r7;
        var_r7 += 1;
        spC[6] = (u8) *var_r7;
        func_08041540(spC[0], spC[1], spC[2], spC[3], (s32) spC[4], (s32) spC[5], (s32) spC[6]);
        *(u8 **)((u32)D_02009118) = (u8 *)((0x354 * spC[0]) + ((u32)D_020075A0));
        temp_r3 = spC[0];
        temp_r2 = (struct ByteWindow *)((0x354 * temp_r3) + ((u32)D_020075A0));
        if (!(8 & temp_r2->unk7)) {

        } else {
            register volatile u16 *variables asm("r0") = sp2C;
            asm("" : : "r"(variables));
            func_08040F44(temp_r3, *variables, (u8) temp_r2->unk9 >> 4, 1U);
        }
        goto block_46;
    case 0x3B:
        var_r7 += 1;
        spC[0] = *var_r7;
        {
            register u32 base asm("r2") = (u32)D_020075A0;
            asm("" : : "r"(base));
            temp_r1 = (struct ByteWindow *)((0x354 * spC[0]) + base);
        }
        {
            register u32 flags asm("r2") = temp_r1->unk9;
            register u32 bit asm("r0") = 16;
            bit |= flags;
            temp_r1->unk9 = bit;
        }
        goto block_457;
    case 0x2:
        var_r7 += 1;
        temp_r0_2 = *var_r7;
        switch (temp_r0_2) {
        case 0:
            func_08040E40();
            break;
        case 1:
            *(s16 *)((u32)D_02007588) = 0;
            *(s16 *)((u32)D_0200758A) = 0;
            func_08040DF0();
            break;
        }
        temp_r1_2 = 0xF0 & *var_r7;
        if (temp_r1_2 != 0) {

        } else {
            spC[0] = temp_r1_2;
            {
                register volatile u16 *variables asm("r2") = sp2C;
                register u8 *arguments asm("r1") = spC;
                register u32 zero asm("r3") = 0;
                register u32 next asm("r0");
                asm("" : : "r"(variables), "r"(arguments), "r"(zero));
                do {
                    register u32 offset asm("r0") = arguments[0] << 1;
                    register volatile u16 *address asm("r0");
                    address = (volatile u16 *)((u32)variables + offset);
                    *address = zero;
                    next = arguments[0] + 1;
                    arguments[0] = next;
                    asm("" : "+r"(next) : : "r4", "r5", "r6");
                } while ((u8)next <= 7U);
            }
        }
        goto block_37;
    case 0x3: {
        register u8 *arguments asm("r1") = spC;
        register u32 value asm("r0");
        asm("" : : "r"(arguments));
        arguments[0] = **(u8 **)((u32)D_02009118);
        var_r7 += 1;
        value = *var_r7;
        arguments[1] = value;
        asm("" : "+r"(value) : "r"(arguments));
        temp_r0_4 = (u8)value;
        if (temp_r0_4 != 0xFF) {
            register u32 base asm("r2") = (u32)D_020075A0;
            register u8 *copy asm("r0") = arguments;
            register u32 selected asm("r1");
            asm("" : : "r"(base), "r"(copy));
            selected = copy[1];
            if (2 & ((struct ByteWindow *)((selected * 0x354) + base))->unk9) {
                *(u16 *)((u32)D_03004BBC) &= 0x7FFF;
            }
            func_08040EC8(spC[1]);
        } else {
            register u16 *flags asm("r2") = (u16 *)D_03004BBC;
            register u32 original asm("r1") = *flags;
            register u32 masked asm("r0") = 0x7FFF;
            register u32 zero asm("r1");
            register u8 *copy asm("r0");
            register u8 *loop asm("r4");
            asm("" : : "r"(original), "r"(masked));
            masked &= original;
            zero = 0;
            asm("" : : "r"(flags), "r"(masked), "r"(zero));
            *flags = masked;
            copy = spC;
            copy[1] = zero;
            loop = copy;
            asm("" : : "r"(copy), "r"(loop));
            do {
                register u32 next asm("r0");
                func_08040EC8(loop[1]);
                next = loop[1] + 1;
                loop[1] = next;
                asm("" : "+r"(next));
                temp_r0_5 = (u8)next;
            } while ((u32) temp_r0_5 <= 7U);
            spC[1] = (u8) **(u8 **)((u32)D_02009118);
        }
        func_08040E90();
        {
            register u8 *arguments asm("r1") = spC;
            register u32 zero asm("r0") = 0;
            register u32 base asm("r6");
            register u8 *loop asm("r5");
            register u32 width asm("r0");
            register u32 stride asm("r8");
            register u32 callback_offset asm("r1");
            register u32 callbacks asm("r10");
            register u32 saved_one asm("r9");
            arguments[2] = zero;
            base = (u32)D_020075A0;
            asm("" : : "r"(base), "r"(arguments));
            loop = arguments;
            width = 0x354;
            stride = width;
            callback_offset = 16;
            asm("" : : "r"(callback_offset));
            callback_offset += base;
            callbacks = callback_offset;
            asm("" : : "r"(loop), "r"(width), "r"(stride), "r"(callback_offset), "r"(callbacks));
            do {
                register u32 row asm("r0") = loop[2];
                register u32 offset asm("r2") = stride;
                register u32 address asm("r0");
                register u32 one asm("r3");
                register u32 copy asm("r1");
                register u32 selected asm("r2");
                register u32 selected_offset asm("r1");
                register u32 active asm("r0");
                offset *= row;
                address = offset;
                asm("" : : "r"(address));
                address += base;
                asm("" : : "r"(offset), "r"(address));
                one = 1;
                saved_one = one;
                copy = saved_one;
                asm("" : : "r"(one), "r"(saved_one), "r"(copy));
                *(u8 *)(address + 6) = copy;
                selected = loop[2];
                selected_offset = stride;
                selected_offset *= selected;
                active = selected_offset + base;
                active = *(u8 *)(active + 14);
                if (active) {
                    register u32 table asm("r3") = callbacks;
                    register u32 entry asm("r0") = selected_offset + table;
                    register u32 callback asm("r4") = *(u32 *)entry;
                    asm volatile("" : : "r"(callback));
                    dispatch_window_callback(selected, 4, 0, 0);
                }
                {
                    register u32 next asm("r0") = loop[2] + 1;
                    loop[2] = next;
                    asm("" : "+r"(next) : "r"(base), "r"(stride), "r"(callbacks));
                    temp_r0_6 = (u8)next;
                }
            } while ((u32)temp_r0_6 <= 7U);
        if (spC[0] != spC[1]) {
            register u32 base asm("r2") = (u32)D_020075A0;
            register u8 *arguments asm("r0");
            register u32 row asm("r0");
            register u32 width asm("r1");
            register u32 address asm("r0");
            register u32 one asm("r3");
            register u32 offset asm("r1");
            register u32 callback asm("r4");
            asm("" : : "r"(base));
            arguments = spC;
            row = arguments[0];
            width = 0x354;
            asm("" : : "r"(width));
            address = row * width;
            address += base;
            one = saved_one;
            asm("" : : "r"(one));
            *(u8 *)(address + 6) = one;
            arguments = spC;
            row = arguments[0];
            offset = width * row;
            base += 16;
            offset += base;
            callback = *(u32 *)offset;
            asm volatile("" : : "r"(callback));
            callback_window = row;
            {
                register u32 command asm("r1") = 4;
                asm("" : "+r"(command) : "r"(callback_window));
                var_r1 = command;
            }
            dispatch_window_callback(callback_window, var_r1, 0, 0);
            asm volatile("");
        }
        }
        goto block_37;
        }
    case 0x4: {
        register u8 *arguments asm("r1");
        register u32 value asm("r0");
        register u32 zero asm("r2");
        var_r7 += 1;
        arguments = spC;
        asm("" : : "r"(arguments));
        value = *var_r7;
        zero = 0;
        asm("" : : "r"(value), "r"(zero));
        arguments[0] = value;
        asm("" : "+r"(value), "+r"(zero) : "r"(arguments));
        temp_r0_7 = (u8)value;
        if (temp_r0_7 != 0xFF) {
            register u32 base asm("r2") = (u32)D_020075A0;
            register u8 *copy asm("r0");
            register u32 row asm("r0");
            register u32 width asm("r3");
            register u32 address asm("r0");
            register u32 one asm("r1");
            register u32 offset asm("r1");
            register u32 callback asm("r4");
            asm("" : : "r"(base));
            copy = arguments;
            asm("" : : "r"(copy));
            row = copy[0];
            width = 0x354;
            asm("" : : "r"(width), "r"(row));
            address = row * width + base;
            asm("" : : "r"(address));
            one = 1;
            asm("" : : "r"(one));
            *(u8 *)(address + 6) = one;
            copy = spC;
            row = copy[0];
            offset = row;
            offset *= width;
            base += 16;
            offset += base;
            callback = *(u32 *)offset;
            asm volatile("" : : "r"(callback));
            var_r0 = row;
            {
                register u32 command asm("r1") = 4;
                asm("" : "+r"(command) : "r"(var_r0));
                var_r1 = command;
            }
            goto shared_script_window_callback;
            goto block_37;
        } else {
            register u8 *copy asm("r0") = spC;
            register u32 base asm("r6");
            register u8 *loop asm("r5");
            register u32 width asm("r0");
            register u32 stride asm("r8");
            register u32 callback_offset asm("r1");
            register u32 callbacks asm("r9");
            copy[1] = zero;
            base = (u32)D_020075A0;
            asm("" : : "r"(copy), "r"(base));
            loop = copy;
            width = 0x354;
            stride = width;
            callback_offset = 16;
            asm("" : : "r"(callback_offset));
            callback_offset += base;
            callbacks = callback_offset;
            asm("" : : "r"(loop), "r"(width), "r"(stride), "r"(callback_offset), "r"(callbacks));
            do {
                register u32 row asm("r0") = loop[1];
                register u32 offset asm("r2") = stride;
                register u32 address asm("r0");
                register u32 one asm("r1");
                register u32 selected asm("r2");
                register u32 selected_offset asm("r1");
                register u32 active asm("r0");
                offset *= row;
                address = offset;
                asm("" : : "r"(address));
                address += base;
                asm("" : : "r"(offset), "r"(address));
                one = 1;
                asm("" : : "r"(one));
                *(u8 *)(address + 6) = one;
                selected = loop[1];
                selected_offset = stride;
                selected_offset *= selected;
                active = selected_offset + base;
                active = *(u8 *)(active + 14);
                if (active) {
                    register u32 table asm("r3") = callbacks;
                    register u32 entry asm("r0") = selected_offset + table;
                    register u32 callback asm("r4") = *(u32 *)entry;
                    asm volatile("" : : "r"(callback));
                    dispatch_window_callback(selected, 4, 0, 0);
                }
                {
                    register u32 next asm("r0") = loop[1] + 1;
                    loop[1] = next;
                    asm("" : "+r"(next) : "r"(base), "r"(stride), "r"(callbacks));
                    temp_r0_8 = (u8)next;
                }
            } while ((u32)temp_r0_8 <= 7U);
        }
        }
block_37:
        func_08041100();
        goto block_457;
    case 0xD: {
        register u8 *arguments asm("r1");
        register u32 base asm("r2");
        register u8 *copy asm("r0");
        register u32 row asm("r0");
        register u32 width asm("r1");
        register u32 offset asm("r1");
        register u32 callback asm("r4");
        var_r7 += 1;
        arguments = spC;
        arguments[0] = *var_r7;
        base = (u32)D_020075A0;
        asm("" : "+r"(base) : "r"(arguments));
        copy = arguments;
        asm("" : : "r"(copy));
        row = copy[0];
        width = 0x354;
        offset = width * row;
        base += 16;
        offset += base;
        callback = *(u32 *)offset;
        asm volatile("" : : "r"(callback));
        dispatch_window_callback(row, 4, 0, 0);
        goto block_457;
        }
    case 0xE: {
        register u32 base asm("r2");
        var_r7 += 1;
        spC[0] = *var_r7;
        base = (u32)D_020075A0;
        asm("" : "+r"(base));
        ((struct ByteWindow *)((0x354 * spC[0]) + base))->unk6 = 1;
        var_r0 = spC[0];
block_40:
        {
            register u32 offset asm("r1") = var_r0 * 0x354;
            register u32 callback asm("r4");
            base += 16;
            asm("" : "+r"(base) : "r"(offset));
            offset += base;
            callback = *(u32 *)offset;
            asm volatile("" : : "r"(callback));
            var_r1 = 7;
shared_script_window_callback:
            dispatch_window_callback(var_r0, var_r1, 0, 0);
        }
        goto block_37;
        }
    case 0xF:
        var_r7 += 1;
        spC[0] = *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        command_window_base = (u32)D_020075A0;
        command_arguments = spC;
        asm("" : : "r"(command_window_base), "r"(command_arguments));
        goto block_45;
    case 0x3D: {
        register u8 *arguments asm("r1");
        register u32 value asm("r0");
        var_r7 += 1;
        arguments = spC;
        asm("" : : "r"(arguments));
        value = *var_r7;
        arguments[0] = value;
        asm("" : "+r"(value) : "r"(arguments));
        temp_r0_9 = (u8)value;
        if ((temp_r0_9 << 0x18) != 0) {
            register u8 *copy asm("r0") = arguments;
            asm("" : : "r"(copy));
            func_0805EE78(copy[0]);
        }
        goto block_457;
        }
    case 0x37:
        var_r7 += 1;
        spC[0] = *var_r7;
        var_r7 += 1;
        spC[3] = (u8) *var_r7;
        var_r7 += 1;
        spC[4] = (u8) *var_r7;
        {
            register u8 *arguments asm("r2") = spC;
            register volatile u16 *variables asm("r1") = sp2C;
            register u8 *copy asm("r0");
            register u32 offset asm("r0");
            register volatile u16 *address asm("r0");
            register u32 value asm("r0");
            register volatile u16 *last asm("r1");
            asm("" : : "r"(arguments), "r"(variables));
            copy = arguments;
            asm("" : : "r"(copy));
            offset = copy[3] << 1;
            address = (volatile u16 *)((u32)variables + offset);
            value = *address;
            arguments[1] = value;
            copy = arguments;
            asm("" : : "r"(copy));
            offset = copy[4] << 1;
            last = (volatile u16 *)((u32)variables + offset);
            value = *last;
            arguments[2] = value;
        }
        command_window_base = (u32)D_020075A0;
        command_arguments = spC;
        asm("" : : "r"(command_window_base), "r"(command_arguments));
block_45:
        temp_r1_3 = (struct ByteWindow *)((0x354 * command_arguments[0]) + command_window_base);
        temp_r1_3->unk9 = (u8)(2 | temp_r1_3->unk9);
        func_080404F0(spC[0], spC[1], spC[2], 0);
block_46:
        func_0805EE78(1U);
        goto block_457;
    case 0x5: {
        register volatile u16 *keys asm("r6");
        register volatile u16 *command_variables asm("r0");
        u32 menu_finished;
        var_r7 += 1;
        spC[0] = 0xF & *var_r7;
        spC[1] = (u8) (0xF0 & *var_r7);
        spC[2] = 0U;
        spC[3] = (u8) **(u8 **)((u32)D_02009118);
        spC[4] = 0U;
        keys = &frame.temporary[0];
        asm("" : "+r"(keys));
        goto loop_57;
block_48:
        temp_r1_4 = spC[4];
        if (temp_r1_4 != 0) goto script_command_5_finished;
        if (spC[2] == 0x28) spC[2] = temp_r1_4;
        temp_r0_11 = spC[2];
        if (temp_r0_11 == 0x14) {
            func_08040A94(spC[3]);
            func_08041100();
        } else if (temp_r0_11 == 0) {
            func_08040AD4(spC[3]);
            func_08041100();
        }
        spC[2] = (u8)(spC[2] + 1);
        func_0805EE78(1U);
loop_57:
        asm("" : : "r"(keys));
        *keys = func_0800175C(0x10, 6);
        temp_r0_10 = spC[0];
        switch ((u32) temp_r0_10) {
        case 0: {
            register u32 buttons asm("r1") = *keys;
            register u32 finished asm("r3") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons), "r"(finished), "r"(accepted));
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                register volatile u16 *variables asm("r0") = sp2C;
                register u8 *arguments asm("r0");
                asm("" : : "r"(variables));
                *variables = accepted;
                arguments = spC;
                arguments[4] = finished;
                func_080404BC(arguments[3], 5U);
            }
            break;
            }
        case 1:
            if (8 & *keys) {
                register volatile u16 *variables asm("r1") = sp2C;
                register u32 finished asm("r2") = 1;
                register u32 accepted asm("r0") = 1;
                register u8 *arguments asm("r0");
                asm("" : : "r"(variables), "r"(finished), "r"(accepted));
                *variables = accepted;
                arguments = spC;
                arguments[4] = finished;
                func_080404BC(arguments[3], 0xBU);
            }
            break;
        case 2: {
            register u32 buttons asm("r1") = *keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[3], 0xBU);
            }
            if (0x200 & *keys) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = 2;
                }
                spC[4] = menu_finished;
            }
            if (!(0x100 & *keys)) {

            } else {
                command_variables = sp2C;
                asm("" : : "r"(command_variables));
                var_r1_2 = 4;
                goto block_105;
            }
            break;
            }
        case 3: {
            register u32 buttons asm("r1") = *keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[3], 0xBU);
            }
            if (!(0x200 & *keys)) {

            } else {
                command_variables = sp2C;
                asm("" : : "r"(command_variables));
                var_r1_2 = 2;
                goto block_105;
            }
            break;
            }
        case 4: {
            register u32 buttons asm("r1") = *keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[3], 0xBU);
            }
            if (!(0x100 & *keys)) {

            } else {
                command_variables = sp2C;
                asm("" : : "r"(command_variables));
                var_r1_2 = 4;
                goto block_105;
            }
            break;
            }
        case 5: {
            register u32 buttons asm("r1") = *keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[3], 0xBU);
            }
            if (0x200 & *keys) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = 2;
                }
                spC[4] = menu_finished;
            }
            if (0x100 & *keys) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = 4;
                }
                spC[4] = menu_finished;
            }
            if (0x20 & *keys) {
                command_variables = sp2C;
                asm("" : : "r"(command_variables));
                var_r1_2 = 8;
                goto block_105;
            }
            break;
            }
        case 6: {
            register u32 buttons asm("r1") = *keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[3], 0xBU);
            }
            if (0x200 & *keys) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = 2;
                }
                spC[4] = menu_finished;
            }
            if (0x100 & *keys) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = 4;
                }
                spC[4] = menu_finished;
            }
            if (0x20 & *keys) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = 8;
                }
                spC[4] = menu_finished;
            }
            if (0x10 & *keys) {
                {
                    register volatile u16 *variables asm("r0") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = 0x10;
                }
                spC[4] = menu_finished;
            }
            if (8 & *keys) {
                {
                    register volatile u16 *variables asm("r1") = sp2C;
                    asm("" : : "r"(variables));
                    *variables = 0x80;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[3], 0xBU);
            }
            if (4 & *keys) {
                command_variables = sp2C;
                asm("" : : "r"(command_variables));
                var_r1_2 = 0;
                goto block_105;
            }
            break;
            }
        }
        goto script_command_5_dispatch_done;
block_105:
        *command_variables = var_r1_2;
        spC[4] = menu_finished;
script_command_5_dispatch_done:
        if (spC[1] != 0x10 || !(2 & *keys)) goto block_48;
        {
            register volatile u16 *variables asm("r1") = sp2C;
            asm("" : : "r"(variables));
            *variables = 0;
        }
        func_08001A08(*(u16 *)((u32)D_02000B56));
script_command_5_finished:
        func_08040AD4(spC[3]);
        goto block_37;
        }
    case 0x6: {
        register u8 *menu_arguments asm("r0");
        u32 menu_finished;
        var_r7 += 1;
        spC[0] = 0xF & *var_r7;
        spC[1] = (u8) (0xF0 & *var_r7);
        spC[2] = (u8) **(u8 **)((u32)D_02009118);
        spC[4] = 0U;
        window_command(spC[2], 4, 0, 0);
        func_08040828(spC[2]);
        func_08040D0C(spC[2], spC[0]);
        func_08041100();
        {
            register volatile u16 *copy asm("r0") = sp2C;
            asm("" : : "r"(copy));
            menu_variables = copy;
            menu_keys = &frame.temporary[0];
            asm("" : "+r"(menu_variables), "+r"(menu_keys));
        }
        goto loop_127;
script_command_6_idle:
        if (spC[4] != 0) goto script_command_6_accepted;
        {
            register u32 buttons asm("r1") = *menu_keys;
            asm("" : : "r"(buttons));
            temp_r1_5 = buttons;
                if (0x40 & temp_r1_5) {
                    func_080404BC(spC[2], 4U);
                    func_08040A14(spC[2]);
                    {
                        register u32 menu_base asm("r5") = (u32)D_020075A0;
                        register u32 menu_stride asm("r4");
                        register u32 row asm("r0");
                        asm("" : : "r"(menu_base));
                        row = spC[2];
                        menu_stride = 0x354;
                        asm("" : : "r"(row), "r"(menu_stride));
                    temp_r1_6 = (struct ByteWindow *)((menu_stride * row) + menu_base);
                    temp_r0_13 = temp_r1_6->unkD;
                    if (temp_r0_13 != 0) {
                        temp_r1_6->unkD = (u8) (temp_r0_13 - 1);
                    }
                    temp_r1_7 = (struct ByteWindow *)((menu_stride * spC[2]) + menu_base);
                    temp_r2_4 = temp_r1_7->unkD;
                    if ((u32) temp_r1_7->unkC > (u32) temp_r2_4) {
                        temp_r1_7->unkC = temp_r2_4;
                    }
                    window_command(spC[2], 4, 0, 0);
                    func_08040828(spC[2]);
                    *(u16 *)((u32)D_02007588) = (s16) ((struct ByteWindow *)((menu_stride * spC[2]) + menu_base))->unkD;
                    func_08040D0C(spC[2], spC[0]);
                    func_08041100();
                    }
                } else if (0x80 & temp_r1_5) {
                    func_080404BC(spC[2], 4U);
                    func_08040A14(spC[2]);
                    {
                        register u32 menu_base asm("r5") = (u32)D_020075A0;
                        register u32 menu_stride asm("r4");
                        register u32 row asm("r0");
                        asm("" : : "r"(menu_base));
                        row = spC[2];
                        menu_stride = 0x354;
                        asm("" : : "r"(row), "r"(menu_stride));
                    temp_r1_8 = (struct ByteWindow *)((menu_stride * row) + menu_base);
                    temp_r0_14 = temp_r1_8->unkD;
                    if ((u32) temp_r0_14 < (u32) temp_r1_8->unkB) {
                        temp_r1_8->unkD = (u8) (temp_r0_14 + 1);
                    }
                    temp_r2_5 = (struct ByteWindow *)((menu_stride * spC[2]) + menu_base);
                    temp_r3_2 = temp_r2_5->unkC;
                    temp_r0_15 = temp_r2_5->unk4 - 2;
                    if ((s32) (temp_r3_2 + ((s32) (temp_r0_15 + (temp_r0_15 >> 0x1F)) >> 1)) <= (s32) temp_r2_5->unkD) {
                        temp_r2_5->unkC = (u8) (temp_r3_2 + 1);
                    }
                    window_command(spC[2], 4, 0, 0);
                    func_08040828(spC[2]);
                    *(u16 *)((u32)D_02007588) = (s16) ((struct ByteWindow *)((menu_stride * spC[2]) + menu_base))->unkD;
                    func_08040D0C(spC[2], spC[0]);
                    func_08041100();
                    }
                }
                func_0805EE78(1U);
                goto loop_127;
        }
loop_127:
        asm("" : : "r"(menu_variables), "r"(menu_keys));

        {
            register volatile u16 *selection asm("r3") = (volatile u16 *)D_02007588;
            register u32 base asm("r2") = (u32)D_020075A0;
            asm("" : : "r"(selection), "r"(base));
            *selection = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
        }
        *menu_keys = func_0800175C(0x10, 6);
        temp_r0_12 = spC[0];
        switch ((u32) temp_r0_12) {
        case 0: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r3") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons), "r"(finished), "r"(accepted));
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (!pressed) break;
            {
                register volatile u16 *variables asm("r0") = menu_variables;
                asm("" : : "r"(variables));
                *variables = accepted;
                menu_arguments = spC;
                menu_arguments[4] = finished;
                goto block_136;
            }
            }
        case 1:
            if (!(8 & *menu_keys)) break;
            {
                register u32 finished asm("r1") = 1;
                register u32 accepted asm("r0") = 1;
                register volatile u16 *variables asm("r2") = menu_variables;
                asm("" : : "r"(finished), "r"(accepted), "r"(variables));
                *variables = accepted;
                menu_arguments = spC;
                menu_arguments[4] = finished;
block_136:
                func_080404BC(menu_arguments[2], 0xBU);
            }
            break;
        case 2: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r3") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (!(0x100 & *menu_keys)) {

            } else {
                var_r0_2 = 4;
                goto block_176;
            }
            break;
            }
        case 3: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r3") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (!(0x200 & *menu_keys)) {

            } else {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                    asm("" : : "r"(variables));
                }
                goto block_177;
            }
            break;
            }
        case 4: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r3") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (!(0x100 & *menu_keys)) {

            } else {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                goto block_177;
            }
            break;
            }
        case 5: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r3") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x100 & *menu_keys) {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r2");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x20 & *menu_keys) {
                {
                    register u32 value asm("r0") = 8;
                    register volatile u16 *variables asm("r3");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                goto block_177;
            }
            break;
            }
        case 6: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x100 & *menu_keys) {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r2");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x20 & *menu_keys) {
                {
                    register u32 value asm("r0") = 8;
                    register volatile u16 *variables asm("r3");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x10 & *menu_keys) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    *variables = 0x10;
                }
                spC[4] = menu_finished;
            }
            if (8 & *menu_keys) {
                {
                    register u32 value asm("r0") = 0x80;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (4 & *menu_keys) {
                var_r0_2 = 0;
                goto block_176;
            }
            break;
            }
        }
        goto script_command_6_dispatch_done;
block_176:
        {
            register volatile u16 *variables asm("r2") = menu_variables;
            *variables = var_r0_2;
        }
block_177:
        spC[4] = menu_finished;
script_command_6_dispatch_done:
        if (spC[1] != 0x10 || !(2 & *menu_keys)) goto script_command_6_idle;
        {
            register u32 value asm("r0") = 0;
            register volatile u16 *variables asm("r3");
            register u32 base asm("r2");
            asm("" : : "r"(value));
            variables = menu_variables;
            asm("" : : "r"(variables));
            *variables = value;
            base = (u32)D_020075A0;
            asm("" : : "r"(base));
            value = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
            variables[1] = value;
        }
        func_08001A08(*(u16 *)((u32)D_02000B56));
        goto script_command_6_finished;
        }
    case 0x38: {
        register volatile u16 *entry_temporary asm("r5");
        register volatile u16 *entry_variables asm("r4");
        register u16 menu_buttons asm("r1");
        register u8 *arguments asm("r3");
        register u32 mask asm("r2");
        register u32 value asm("r1");
        register u32 low asm("r0");
        register u8 *copy asm("r1");
        var_r7 += 1;
        arguments = spC;
        value = *var_r7;
        mask = 15;
        asm("" : "+r"(mask) : "r"(arguments), "r"(value));
        low = mask;
        asm("" : : "r"(low));
        arguments[0] = low & value;
        value = *var_r7;
        arguments[1] = value & 0xF0;
        copy = arguments;
        asm("" : : "r"(copy));
        copy[2] = **(u8 **)((u32)D_02009118);
        entry_temporary = (volatile u16 *)&sp1C;
        entry_variables = sp2C;
        asm("" : "+r"(entry_temporary) : "r"(entry_variables));
        {
            register u32 base asm("r3") = (u32)D_020075A0;
            register u8 *copy0 asm("r0");
            register u32 row asm("r1");
            register u32 flags asm("r0");
            register volatile u16 *address asm("r2");
            register u32 selected asm("r0");
            register u32 zero asm("r1");
            register u8 *output asm("r0");
            asm("" : : "r"(base));
            copy0 = copy;
            asm("" : : "r"(copy0));
            row = copy0[2];
            flags = ((struct ByteWindow *)(row * 0x354 + base))->unk9;
            mask &= flags;
            asm("" : "+r"(mask));
            mask <<= 1;
            address = (volatile u16 *)((u32)entry_variables + mask);
            asm("" : : "r"(address));
            selected = *address;
            zero = 0;
            asm("" : : "r"(selected), "r"(zero));
            entry_temporary[1] = selected;
            output = spC;
            output[5] = zero;
        }
        window_command(spC[2], 4, 0, 0);
        func_08040828(spC[2]);
        func_08041100();
        menu_variables = entry_variables;
        menu_keys = (volatile u16 *)entry_temporary;
        asm("" : "+r"(menu_variables), "+r"(menu_keys));
        goto loop_201;
script_command_38_start:
        if (8 & menu_buttons) goto script_command_38_start_accepted;
block_185:
        if (spC[1] == 0x10 && (2 & menu_keys[0])) goto script_command_38_aborted;
        {
            register u32 buttons asm("r1") = menu_keys[0];
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons));
            pressed = 0x40;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            asm("" : : "r"(pressed));
                if (pressed) {
                    func_080404BC(spC[2], 4U);
                    {
                        register volatile u16 *selection asm("r1") = (volatile u16 *)D_02007588;
                        register u32 carrier asm("r0") = (u32)D_020075A0;
                        register u32 movement_base asm("r10");
                        register u32 movement_stride asm("r5");
                        register u32 row asm("r0");
                        register u8 zero asm("r4");
                        register u32 columns asm("r8");
                        asm("" : : "r"(selection), "r"(carrier));
                        movement_base = carrier;
                        asm("" : : "r"(movement_base));
                        row = spC[2];
                        movement_stride = 0x354;
                        asm("" : : "r"(row), "r"(movement_stride));
                        *selection = ((struct ByteWindow *)(row * movement_stride + movement_base))->unkD;
                    {
                        register u16 selected asm("r0") = menu_keys[1];
                        register u8 *arguments asm("r1") = spC;
                        register u32 width asm("r2") = arguments[5];
                        register u32 four asm("r1") = 4;
                        register u32 copy asm("r3");
                        register u16 result asm("r0");
                        asm("" : : "r"(selected), "r"(width), "r"(four));
                        columns = four;
                        asm("" : : "r"(columns));
                        copy = columns;
                        asm("" : : "r"(copy));
                        width = copy - width;
                        result = func_080408D0(selected, 0x40, (u8)width, 4);
                        zero = 0;
                        asm("" : "+r"(zero) : "r"(result));
                        menu_keys[1] = result;
                    }
                    func_08041498(spC[2]);
                    ((struct ByteWindow *)((spC[2] * movement_stride) + movement_base))->unkC = zero;
                    ((struct ByteWindow *)((spC[2] * movement_stride) + movement_base))->unkA = zero;
                    temp_r0_17 = spC[2];
                    func_08040F44(temp_r0_17, menu_keys[1], (u8) ((struct ByteWindow *)((temp_r0_17 * movement_stride) + movement_base))->unk9 >> 4, 1U);
                    window_command(spC[2], 4, 0, 0);
                    {
                        register u32 row asm("r0") = spC[2];
                        register u32 offset asm("r1");
                        register struct ByteWindow *window asm("r1");
                        register u32 value asm("r0");
                        register u32 four asm("r2");
                        register u32 write asm("r3");
                        asm("" : : "r"(row));
                        offset = row;
                        asm("" : : "r"(offset));
                        window = (struct ByteWindow *)(offset * movement_stride + movement_base);
                        value = spC[5];
                        four = columns;
                        asm("" : : "r"(four));
                        value = four - value;
                        asm("" : : "r"(value));
                        columns = value;
                        asm("" : : "r"(columns));
                        write = columns;
                        asm("" : : "r"(write));
                        window->unkA = write;
                    }
                        asm("" : : "r"(movement_base), "r"(zero));
                    }
                    goto block_195;
                }
                if (0x80 & buttons) {
                    func_080404BC(spC[2], 4U);
                    {
                        register volatile u16 *selection asm("r1") = (volatile u16 *)D_02007588;
                        register u32 carrier asm("r0") = (u32)D_020075A0;
                        register u32 movement_base asm("r10");
                        register u32 movement_stride asm("r5");
                        register u32 row asm("r0");
                        register u8 zero asm("r4");
                        register u32 columns asm("r8");
                        asm("" : : "r"(selection), "r"(carrier));
                        movement_base = carrier;
                        asm("" : : "r"(movement_base));
                        row = spC[2];
                        movement_stride = 0x354;
                        asm("" : : "r"(row), "r"(movement_stride));
                        *selection = ((struct ByteWindow *)(row * movement_stride + movement_base))->unkD;
                    {
                        register u16 selected asm("r0") = menu_keys[1];
                        register u8 *arguments asm("r1") = spC;
                        register u32 width asm("r2") = arguments[5];
                        register u32 four asm("r1") = 4;
                        register u32 copy asm("r3");
                        register u16 result asm("r0");
                        asm("" : : "r"(selected), "r"(width), "r"(four));
                        columns = four;
                        asm("" : : "r"(columns));
                        copy = columns;
                        asm("" : : "r"(copy));
                        width = copy - width;
                        result = func_080408D0(selected, 0x80, (u8)width, 4);
                        zero = 0;
                        asm("" : "+r"(zero) : "r"(result));
                        menu_keys[1] = result;
                    }
                    func_08041498(spC[2]);
                    ((struct ByteWindow *)((spC[2] * movement_stride) + movement_base))->unkC = zero;
                    ((struct ByteWindow *)((spC[2] * movement_stride) + movement_base))->unkA = zero;
                    temp_r0_18 = spC[2];
                    func_08040F44(temp_r0_18, menu_keys[1], (u8) ((struct ByteWindow *)((temp_r0_18 * movement_stride) + movement_base))->unk9 >> 4, 1U);
                    window_command(spC[2], 4, 0, 0);
                    {
                        register u32 row asm("r0") = spC[2];
                        register u32 offset asm("r1");
                        register struct ByteWindow *window asm("r1");
                        register u32 value asm("r0");
                        register u32 four asm("r2");
                        register u32 write asm("r3");
                        asm("" : : "r"(row));
                        offset = row;
                        asm("" : : "r"(offset));
                        window = (struct ByteWindow *)(offset * movement_stride + movement_base);
                        value = spC[5];
                        four = columns;
                        asm("" : : "r"(four));
                        value = four - value;
                        asm("" : : "r"(value));
                        columns = value;
                        asm("" : : "r"(columns));
                        write = columns;
                        asm("" : : "r"(write));
                        window->unkA = write;
                    }
                    }
                    goto block_195;
                }
                if (0x20 & buttons) {
                    func_080404BC(spC[2], 4U);
                    temp_r0_19 = spC[5];
                    if ((u32) temp_r0_19 <= 2U) {
                        spC[5] = (u8) (temp_r0_19 + 1);
                    }
                    window_command(spC[2], 4, 0, 0);
                    {
                        register u32 base asm("r2") = (u32)D_020075A0;
                        asm("" : : "r"(base));
                        ((struct ByteWindow *)(0x354 * spC[2] + base))->unkA = (s8)(4 - spC[5]);
                    }
block_195:
                    func_08040828(spC[2]);
                    func_08041100();
                } else if (0x10 & buttons) {
                    func_080404BC(spC[2], 4U);
                    temp_r0_20 = spC[5];
                    if (temp_r0_20 != 0) {
                        spC[5] = (u8) (temp_r0_20 - 1);
                    }
                    window_command(spC[2], 4, 0, 0);
                    {
                        register u32 base asm("r2") = (u32)D_020075A0;
                        asm("" : : "r"(base));
                        ((struct ByteWindow *)(0x354 * spC[2] + base))->unkA = (s8)(4 - spC[5]);
                    }
                    func_08040828(spC[2]);
                    func_08041100();
                }
                func_0805EE78(1U);
                goto loop_201;
        }
loop_201:
        asm("" : : "r"(menu_variables), "r"(menu_keys));
        {
            register volatile u16 *selection asm("r3") = (volatile u16 *)D_02007588;
            register u32 base asm("r2") = (u32)D_020075A0;
            register u16 input asm("r0");
            register u32 accepted asm("r0");
            register volatile u16 *variables asm("r1");
            asm("" : : "r"(selection), "r"(base));
            *selection = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
            input = func_0800175C(0x10, 2);
            asm("" : "+r"(input));
            menu_buttons = input;
            asm("" : : "r"(menu_buttons));
            menu_keys[0] = menu_buttons;
            if (spC[0] != 0) goto script_command_38_start;
            accepted = 1;
            asm("" : : "r"(accepted));
            menu_buttons &= accepted;
            if (!menu_buttons) goto block_185;
            variables = menu_variables;
            *variables = accepted;
            accepted = menu_keys[1];
            variables[1] = accepted;
            goto block_450;
        }
        }
    case 0x3C: {
        register u32 edge_mask asm("r2");
        var_r7 += 1;
        spC[0] = 0xF & *var_r7;
        spC[1] = (u8) (0xF0 & *var_r7);
        spC[2] = (u8) **(u8 **)((u32)D_02009118);
        spC[4] = 0U;
        window_command(spC[2], 4, 0, 0);
        func_08040828(spC[2]);
        func_08040D0C(spC[2], spC[0]);
        func_08041100();
        {
            register volatile u16 *copy asm("r2") = sp2C;
            asm("" : : "r"(copy));
            menu_variables = copy;
            menu_keys = &frame.temporary[0];
            asm("" : "+r"(menu_variables), "+r"(menu_keys));
        }
        goto loop_221;
script_command_3c_idle:
        if (spC[4] != 0) goto script_command_3c_accepted;
        {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 down_value asm("r4") = 0x40;
            register u32 pressed asm("r0");
            asm("" : "+r"(down_value) : "r"(buttons));
            pressed = down_value;
            asm("" : : "r"(pressed));
            pressed &= buttons;
                if (pressed) {
                    func_080404BC(spC[2], 4U);
                    {
                        register u32 value asm("r0") = 0x20;
                        register volatile u16 *variables asm("r3");
                        asm("" : : "r"(value));
                        variables = menu_variables;
                        *variables = value;
                    }
                    func_08040A14(spC[2]);
                    {
                        register u32 movement_base asm("r5") = (u32)D_020075A0;
                        register u32 movement_stride asm("r4");
                        register u32 row asm("r0");
                        asm("" : : "r"(movement_base));
                        row = spC[2];
                        movement_stride = 0x354;
                        asm("" : : "r"(row), "r"(movement_stride));
                    temp_r1_11 = (struct ByteWindow *)((row * movement_stride) + movement_base);
                    temp_r0_22 = temp_r1_11->unkD;
                    if (temp_r0_22 != 0) {
                        temp_r1_11->unkD = (u8) (temp_r0_22 - 1);
                    }
                    temp_r1_12 = (struct ByteWindow *)((spC[2] * movement_stride) + movement_base);
                    temp_r2_6 = temp_r1_12->unkD;
                    if ((u32) temp_r1_12->unkC > (u32) temp_r2_6) {
                        temp_r1_12->unkC = temp_r2_6;
                    }
                    window_command(spC[2], 4, 0, 0);
                    func_08040828(spC[2]);
                    {
                        register volatile u16 *selection asm("r1") = (volatile u16 *)D_02007588;
                        register u32 value asm("r0");
                        register volatile u16 *variables asm("r2");
                        asm("" : : "r"(selection));
                        value = ((struct ByteWindow *)(spC[2] * movement_stride + movement_base))->unkD;
                        asm("" : : "r"(value));
                        variables = menu_variables;
                        asm("" : : "r"(variables));
                        variables[1] = value;
                        *selection = value;
                        asm("" : : "r"(variables));
                    }
                    }
                    goto block_454;
                }
                if (0x80 & buttons) {
                    func_080404BC(spC[2], 4U);
                    {
                        register volatile u16 *variables asm("r3") = menu_variables;
                        *variables = down_value;
                    }
                    func_08040A14(spC[2]);
                    {
                        register u32 movement_base asm("r5") = (u32)D_020075A0;
                        register u32 movement_stride asm("r4");
                        register u32 row asm("r0");
                        asm("" : : "r"(movement_base));
                        row = spC[2];
                        movement_stride = 0x354;
                        asm("" : : "r"(row), "r"(movement_stride));
                    temp_r1_13 = (struct ByteWindow *)((row * movement_stride) + movement_base);
                    temp_r0_24 = temp_r1_13->unkD;
                    if ((u32) temp_r0_24 < (u32) temp_r1_13->unkB) {
                        temp_r1_13->unkD = (u8) (temp_r0_24 + 1);
                    }
                    temp_r2_7 = (struct ByteWindow *)((spC[2] * movement_stride) + movement_base);
                    temp_r3_3 = temp_r2_7->unkC;
                    {
                        register u32 height asm("r0") = temp_r2_7->unk4 - 2;
                        asm("" : : "r"(height));
                        temp_r0_25 = height;
                    }
                    {
                        register u32 original asm("r0") = temp_r0_25;
                        register u32 correction asm("r1") = original >> 31;
                        register u32 rounded asm("r0");
                        register s32 half asm("r0");
                        register s32 end asm("r0");
                        asm("" : "+r"(original) : "r"(correction));
                        rounded = original + correction;
                        asm("" : : "r"(rounded));
                        half = (s32)rounded >> 1;
                        end = temp_r3_3 + half;
                        asm("" : : "r"(end));
                        if (end <= (s32)temp_r2_7->unkD) temp_r2_7->unkC = temp_r3_3 + 1;
                    }
                    window_command(spC[2], 4, 0, 0);
                    func_08040828(spC[2]);
                    {
                        register volatile u16 *selection asm("r1") = (volatile u16 *)D_02007588;
                        register u32 value asm("r0");
                        register volatile u16 *variables asm("r2");
                        asm("" : : "r"(selection));
                        value = ((struct ByteWindow *)(spC[2] * movement_stride + movement_base))->unkD;
                        asm("" : : "r"(value));
                        variables = menu_variables;
                        asm("" : : "r"(variables));
                        variables[1] = value;
                        *selection = value;
                        asm("" : : "r"(movement_base), "r"(value));
                    }
                    }
                    goto block_454;
                }
                func_0805EE78(1U);
                goto loop_221;
        }
loop_221:
        asm("" : : "r"(menu_variables), "r"(menu_keys));

        {
            register volatile u16 *selection asm("r3") = (volatile u16 *)D_02007588;
            register u32 base asm("r2") = (u32)D_020075A0;
            asm("" : : "r"(selection), "r"(base));
            *selection = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
        }
        *menu_keys = func_0800175C(0x10, 6);
        temp_r0_21 = spC[0];
        switch ((u32) temp_r0_21) {
        case 0: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r3") = 1;
            register u32 pressed asm("r0");
            edge_mask = 1;
            asm("" : : "r"(buttons), "r"(finished), "r"(edge_mask));
            pressed = edge_mask;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (!pressed) break;
            {
                register volatile u16 *variables asm("r0") = menu_variables;
                register u8 *arguments asm("r0");
                asm("" : : "r"(variables));
                *variables = edge_mask;
                arguments = spC;
                arguments[4] = finished;
                goto block_230;
            }
            }
        case 1: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 pressed asm("r0");
            edge_mask = 8;
            asm("" : : "r"(buttons), "r"(edge_mask));
            pressed = edge_mask;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (!pressed) break;
            {
                register u32 finished asm("r1") = 1;
                register u32 accepted asm("r0") = 1;
                register volatile u16 *variables asm("r3");
                register u8 *arguments asm("r0");
                asm("" : : "r"(finished), "r"(accepted));
                variables = menu_variables;
                *variables = accepted;
                arguments = spC;
                arguments[4] = finished;
            }
block_230:
            {
                register volatile u16 *edge_address asm("r0") = (volatile u16 *)D_0300235A;
                register u32 edges asm("r1") = *edge_address;
                register u32 edge_pressed asm("r0") = edge_mask;
                asm("" : : "r"(edge_pressed));
                if (edge_pressed & edges) func_080404BC(spC[2], 0xBU);
            }
            break;
            }
        case 2: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r3") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons), "r"(finished), "r"(accepted));
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    register u8 *arguments asm("r0");
                    asm("" : : "r"(variables));
                    *variables = accepted;
                    arguments = spC;
                    arguments[4] = finished;
                }
                {
                    register volatile u16 *edge_address asm("r0") = (volatile u16 *)D_0300235A;
                    register u32 edges asm("r1") = *edge_address;
                    register u32 edge_pressed asm("r0") = accepted;
                    asm("" : : "r"(edge_pressed));
                    if (edge_pressed & edges) func_080404BC(spC[2], 0xBU);
                }
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                {
                    register u8 *arguments asm("r1") = spC;
                    register u32 value asm("r0") = 1;
                    asm("" : : "r"(arguments), "r"(value));
                    arguments[4] = value;
                }
            }
            if (!(0x100 & *menu_keys)) {

            } else {
                var_r0_3 = 4;
                goto block_278;
            }
            break;
            }
        case 3: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r3") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons), "r"(finished), "r"(accepted));
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    register u8 *arguments asm("r0");
                    asm("" : : "r"(variables));
                    *variables = accepted;
                    arguments = spC;
                    arguments[4] = finished;
                }
                {
                    register volatile u16 *edge_address asm("r0") = (volatile u16 *)D_0300235A;
                    register u32 edges asm("r1") = *edge_address;
                    register u32 edge_pressed asm("r0") = accepted;
                    asm("" : : "r"(edge_pressed));
                    if (edge_pressed & edges) func_080404BC(spC[2], 0xBU);
                }
            }
            if (!(0x200 & *menu_keys)) {

            } else {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                    asm("" : : "r"(variables));
                }
                goto block_279;
            }
            break;
            }
        case 4: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r3") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons), "r"(finished), "r"(accepted));
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    register u8 *arguments asm("r0");
                    asm("" : : "r"(variables));
                    *variables = accepted;
                    arguments = spC;
                    arguments[4] = finished;
                }
                {
                    register volatile u16 *edge_address asm("r0") = (volatile u16 *)D_0300235A;
                    register u32 edges asm("r1") = *edge_address;
                    register u32 edge_pressed asm("r0") = accepted;
                    asm("" : : "r"(edge_pressed));
                    if (edge_pressed & edges) func_080404BC(spC[2], 0xBU);
                }
            }
            if (!(0x100 & *menu_keys)) {

            } else {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                goto block_279;
            }
            break;
            }
        case 5: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r3") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons), "r"(finished), "r"(accepted));
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    register u8 *arguments asm("r0");
                    asm("" : : "r"(variables));
                    *variables = accepted;
                    arguments = spC;
                    arguments[4] = finished;
                }
                {
                    register volatile u16 *edge_address asm("r0") = (volatile u16 *)D_0300235A;
                    register u32 edges asm("r1") = *edge_address;
                    register u32 edge_pressed asm("r0") = accepted;
                    asm("" : : "r"(edge_pressed));
                    if (edge_pressed & edges) func_080404BC(spC[2], 0xBU);
                }
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                {
                    register u8 *arguments asm("r1") = spC;
                    register u32 value asm("r0") = 1;
                    asm("" : : "r"(arguments), "r"(value));
                    arguments[4] = value;
                }
            }
            if (0x100 & *menu_keys) {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r2");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                {
                    register u8 *arguments asm("r1") = spC;
                    register u32 value asm("r0") = 1;
                    asm("" : : "r"(arguments), "r"(value));
                    arguments[4] = value;
                }
            }
            if (0x20 & *menu_keys) {
                {
                    register u32 value asm("r0") = 8;
                    register volatile u16 *variables asm("r3");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                goto block_279;
            }
            break;
            }
        case 6: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r3") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons), "r"(finished), "r"(accepted));
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    register u8 *arguments asm("r0");
                    asm("" : : "r"(variables));
                    *variables = accepted;
                    arguments = spC;
                    arguments[4] = finished;
                }
                {
                    register volatile u16 *edge_address asm("r0") = (volatile u16 *)D_0300235A;
                    register u32 edges asm("r1") = *edge_address;
                    register u32 edge_pressed asm("r0") = accepted;
                    asm("" : : "r"(edge_pressed));
                    if (edge_pressed & edges) func_080404BC(spC[2], 0xBU);
                }
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                {
                    register u8 *arguments asm("r1") = spC;
                    register u32 value asm("r0") = 1;
                    asm("" : : "r"(arguments), "r"(value));
                    arguments[4] = value;
                }
            }
            if (0x100 & *menu_keys) {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r2");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                {
                    register u8 *arguments asm("r1") = spC;
                    register u32 value asm("r0") = 1;
                    asm("" : : "r"(arguments), "r"(value));
                    arguments[4] = value;
                }
            }
            if (0x20 & *menu_keys) {
                {
                    register u32 value asm("r0") = 8;
                    register volatile u16 *variables asm("r3");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                {
                    register u8 *arguments asm("r1") = spC;
                    register u32 value asm("r0") = 1;
                    asm("" : : "r"(arguments), "r"(value));
                    arguments[4] = value;
                }
            }
            if (0x10 & *menu_keys) {
                menu_variables[0] = 0x10;
                {
                    register u8 *arguments asm("r1") = spC;
                    register u32 value asm("r0") = 1;
                    asm("" : : "r"(arguments), "r"(value));
                    arguments[4] = value;
                }
            }
            if (8 & *menu_keys) {
                {
                    register u32 value asm("r0") = 0x80;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                {
                    register u8 *arguments asm("r1") = spC;
                    register u32 value asm("r0") = 1;
                    asm("" : : "r"(arguments), "r"(value));
                    arguments[4] = value;
                }
                if (8 & *(u16 *)((u32)D_0300235A)) {
                    func_080404BC(spC[2], 0xBU);
                }
            }
            if (4 & *menu_keys) {
                var_r0_3 = 0;
                goto block_278;
            }
            break;
            }
        }
        goto script_command_3c_dispatch_done;
block_278:
        {
            register volatile u16 *variables asm("r2") = menu_variables;
            *variables = var_r0_3;
        }
block_279:
        {
            register u8 *arguments asm("r1") = spC;
            register u32 value asm("r0") = 1;
            asm("" : : "r"(arguments), "r"(value));
            arguments[4] = value;
        }
script_command_3c_dispatch_done:
        if (spC[1] != 0x10 || !(2 & *menu_keys)) goto script_command_3c_idle;
        asm("" : : "r"(menu_variables));
        goto block_355;
        }
    case 0x36: {
        register u8 *menu_arguments asm("r0");
        u32 menu_finished;
        var_r7 += 1;
        spC[0] = 0xF & *var_r7;
        spC[1] = (u8) (0xF0 & *var_r7);
        spC[2] = (u8) **(u8 **)((u32)D_02009118);
        spC[4] = 0U;
        window_command(spC[2], 4, 0, 0);
        func_08040828(spC[2]);
        func_08040D0C(spC[2], spC[0]);
        func_08041100();
        {
            register volatile u16 *copy asm("r0") = sp2C;
            asm("" : : "r"(copy));
            menu_variables = copy;
            menu_keys = &frame.temporary[0];
            asm("" : "+r"(menu_variables), "+r"(menu_keys));
        }
        goto loop_300;
script_command_36_idle:
        if (spC[4] != 0) goto script_command_36_accepted;
        {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 down_value asm("r4") = 0x40;
            register u32 pressed asm("r0");
            asm("" : "+r"(down_value) : "r"(buttons));
            pressed = down_value;
            asm("" : : "r"(pressed));
            pressed &= buttons;
                if (pressed) {
                    func_080404BC(spC[2], 4U);
                    {
                        register u32 value asm("r0") = 0x20;
                        register volatile u16 *variables asm("r1");
                        asm("" : : "r"(value));
                        variables = menu_variables;
                        *variables = value;
                    }
                    func_08040A14(spC[2]);
                    {
                        register u32 movement_base asm("r5") = (u32)D_020075A0;
                        register u32 movement_stride asm("r4");
                        register u32 row asm("r0");
                        asm("" : : "r"(movement_base));
                        row = spC[2];
                        movement_stride = 0x354;
                        asm("" : : "r"(row), "r"(movement_stride));
                    temp_r1_11 = (struct ByteWindow *)((row * movement_stride) + movement_base);
                    temp_r0_22 = temp_r1_11->unkD;
                    if (temp_r0_22 != 0) {
                        temp_r1_11->unkD = (u8) (temp_r0_22 - 1);
                    }
                    temp_r1_12 = (struct ByteWindow *)((spC[2] * movement_stride) + movement_base);
                    temp_r2_6 = temp_r1_12->unkD;
                    if ((u32) temp_r1_12->unkC > (u32) temp_r2_6) {
                        temp_r1_12->unkC = temp_r2_6;
                    }
                    window_command(spC[2], 4, 0, 0);
                    func_08040828(spC[2]);
                    {
                        register volatile u16 *selection asm("r1") = (volatile u16 *)D_02007588;
                        register u32 value asm("r0");
                        register volatile u16 *variables asm("r2");
                        asm("" : : "r"(selection));
                        value = ((struct ByteWindow *)(spC[2] * movement_stride + movement_base))->unkD;
                        asm("" : : "r"(value));
                        variables = menu_variables;
                        asm("" : : "r"(variables));
                        variables[1] = value;
                        *selection = value;
                        asm("" : : "r"(variables));
                    }
                    }
                    goto block_454;
                }
                if (0x80 & buttons) {
                    func_080404BC(spC[2], 4U);
                    {
                        register volatile u16 *variables asm("r3") = menu_variables;
                        *variables = down_value;
                    }
                    func_08040A14(spC[2]);
                    {
                        register u32 movement_base asm("r5") = (u32)D_020075A0;
                        register u32 movement_stride asm("r4");
                        register u32 row asm("r0");
                        asm("" : : "r"(movement_base));
                        row = spC[2];
                        movement_stride = 0x354;
                        asm("" : : "r"(row), "r"(movement_stride));
                    temp_r1_13 = (struct ByteWindow *)((row * movement_stride) + movement_base);
                    temp_r0_24 = temp_r1_13->unkD;
                    if ((u32) temp_r0_24 < (u32) temp_r1_13->unkB) {
                        temp_r1_13->unkD = (u8) (temp_r0_24 + 1);
                    }
                    temp_r2_7 = (struct ByteWindow *)((spC[2] * movement_stride) + movement_base);
                    temp_r3_3 = temp_r2_7->unkC;
                    {
                        register u32 height asm("r0") = temp_r2_7->unk4 - 2;
                        asm("" : : "r"(height));
                        temp_r0_25 = height;
                    }
                    {
                        register u32 original asm("r0") = temp_r0_25;
                        register u32 correction asm("r1") = original >> 31;
                        register u32 rounded asm("r0");
                        register s32 half asm("r0");
                        register s32 end asm("r0");
                        asm("" : "+r"(original) : "r"(correction));
                        rounded = original + correction;
                        asm("" : : "r"(rounded));
                        half = (s32)rounded >> 1;
                        end = temp_r3_3 + half;
                        asm("" : : "r"(end));
                        if (end <= (s32)temp_r2_7->unkD) temp_r2_7->unkC = temp_r3_3 + 1;
                    }
                    window_command(spC[2], 4, 0, 0);
                    func_08040828(spC[2]);
                    {
                        register volatile u16 *selection asm("r1") = (volatile u16 *)D_02007588;
                        register u32 value asm("r0");
                        register volatile u16 *variables asm("r2");
                        asm("" : : "r"(selection));
                        value = ((struct ByteWindow *)(spC[2] * movement_stride + movement_base))->unkD;
                        asm("" : : "r"(value));
                        variables = menu_variables;
                        asm("" : : "r"(variables));
                        variables[1] = value;
                        *selection = value;
                    }
                    }
                    goto block_454;
                }
                func_0805EE78(1U);
                goto loop_300;
        }
loop_300:
        asm("" : : "r"(menu_variables), "r"(menu_keys));

        {
            register volatile u16 *selection asm("r3") = (volatile u16 *)D_02007588;
            register u32 base asm("r2") = (u32)D_020075A0;
            asm("" : : "r"(selection), "r"(base));
            *selection = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
        }
        *menu_keys = func_0800175C(0x10, 6);
        temp_r0_12 = spC[0];
        switch ((u32) temp_r0_12) {
        case 0: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r3") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : : "r"(buttons), "r"(finished), "r"(accepted));
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (!pressed) break;
            {
                register volatile u16 *variables asm("r0") = menu_variables;
                asm("" : : "r"(variables));
                *variables = accepted;
                menu_arguments = spC;
                menu_arguments[4] = finished;
                goto script_command_36_sound;
            }
            }
        case 1:
            if (!(8 & *menu_keys)) break;
            {
                register u32 finished asm("r1") = 1;
                register u32 accepted asm("r0") = 1;
                register volatile u16 *variables asm("r2") = menu_variables;
                asm("" : : "r"(finished), "r"(accepted), "r"(variables));
                *variables = accepted;
                menu_arguments = spC;
                menu_arguments[4] = finished;
script_command_36_sound:
                func_080404BC(menu_arguments[2], 0xBU);
            }
            break;
        case 2: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r3") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (!(0x100 & *menu_keys)) {

            } else {
                var_r0_2 = 4;
                goto script_command_36_store;
            }
            break;
            }
        case 3: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r3") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (!(0x200 & *menu_keys)) {

            } else {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                    asm("" : : "r"(variables));
                }
                goto script_command_36_finished_flag;
            }
            break;
            }
        case 4: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r3") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (!(0x100 & *menu_keys)) {

            } else {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                goto script_command_36_finished_flag;
            }
            break;
            }
        case 5: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r3") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x100 & *menu_keys) {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r2");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x20 & *menu_keys) {
                {
                    register u32 value asm("r0") = 8;
                    register volatile u16 *variables asm("r3");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                goto script_command_36_finished_flag;
            }
            break;
            }
        case 6: {
            register u32 buttons asm("r1") = *menu_keys;
            register u32 finished asm("r4") = 1;
            register u32 accepted asm("r2") = 1;
            register u32 pressed asm("r0");
            asm("" : "+r"(finished) : "r"(buttons), "r"(accepted));
            menu_finished = finished;
            pressed = accepted;
            asm("" : : "r"(pressed));
            pressed &= buttons;
            if (pressed) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    asm("" : : "r"(variables));
                    *variables = accepted;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (0x200 & *menu_keys) {
                {
                    register u32 value asm("r0") = 2;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x100 & *menu_keys) {
                {
                    register u32 value asm("r0") = 4;
                    register volatile u16 *variables asm("r2");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x20 & *menu_keys) {
                {
                    register u32 value asm("r0") = 8;
                    register volatile u16 *variables asm("r3");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
            }
            if (0x10 & *menu_keys) {
                {
                    register volatile u16 *variables asm("r0") = menu_variables;
                    *variables = 0x10;
                }
                spC[4] = menu_finished;
            }
            if (8 & *menu_keys) {
                {
                    register u32 value asm("r0") = 0x80;
                    register volatile u16 *variables asm("r1");
                    asm("" : : "r"(value));
                    variables = menu_variables;
                    *variables = value;
                }
                spC[4] = menu_finished;
                func_080404BC(spC[2], 0xBU);
            }
            if (4 & *menu_keys) {
                var_r0_2 = 0;
                goto script_command_36_store;
            }
            break;
            }
        }
        goto script_command_36_dispatch_done;
script_command_36_store:
        {
            register volatile u16 *variables asm("r2") = menu_variables;
            *variables = var_r0_2;
        }
script_command_36_finished_flag:
        spC[4] = menu_finished;
script_command_36_dispatch_done:
        if (spC[1] != 0x10 || !(2 & *menu_keys)) goto script_command_36_idle;
block_355:
        {
            register u32 value asm("r0") = 0;
            register volatile u16 *variables asm("r3");
            register u32 base asm("r2");
            asm("" : : "r"(value));
            variables = menu_variables;
            asm("" : : "r"(variables));
            *variables = value;
            base = (u32)D_020075A0;
            asm("" : : "r"(base));
            value = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
            variables[1] = value;
        }
        func_08040D0C(spC[2], spC[0]);
        func_08001A08(*(u16 *)((u32)D_02000B56));
        goto block_457;
        }
    case 0x7: {
        register const u8 *snapshot asm("r4") = var_r7;
        register u8 *arguments asm("r2");
        register u32 value asm("r0");
        register u32 zero asm("r3");
        register u32 script_value asm("r1");
        register u8 *copy asm("r0");
        register volatile u16 *variables asm("r1");
        register volatile u16 *address asm("r1");
        asm("" : : "r"(snapshot));
        branch_origin = snapshot;
        var_r7 += 1;
        arguments = spC;
        script_value = *var_r7;
        value = 7;
        asm("" : : "r"(script_value), "r"(value));
        value &= script_value;
        zero = 0;
        asm("" : "+r"(zero) : "r"(value), "r"(arguments));
        arguments[0] = value;
        copy = arguments;
        asm("" : : "r"(copy));
        copy[1] = zero;
        variables = sp2C;
        asm("" : "+r"(variables));
        address = variables + spC[0];
        asm("" : : "r"(address));
        if (zero < *address) {
            register u32 count asm("r0");
            register u32 bound asm("r3");
            do {
                asm("" : : "r"(address), "r"(arguments));
                var_r7 += 2;
                count = arguments[1] + 1;
                arguments[1] = count;
                count = arguments[1];
                bound = *address;
                asm("" : : "r"(count), "r"(bound));
            } while (count < bound);
        }
        var_r7 += 1;
        {
            register u8 *arguments asm("r1") = spC;
            register u32 byte asm("r0");
            asm("" : : "r"(arguments));
            byte = *var_r7;
            arguments[0] = byte;
            byte = var_r7[1];
            arguments[1] = byte;
            asm("" : "+r"(byte) : "r"(arguments));
            if ((s32)(byte << 24) < 0) {
                register u8 *copy asm("r0") = arguments;
                register u32 high asm("r0");
                register u32 low asm("r1");
                asm("" : : "r"(copy));
                high = copy[1] << 8;
                low = arguments[0];
                    var_r0_5 = high;
                var_r1_3 = low;
                goto block_396;
            } else {
                register u8 *copy asm("r0") = spC;
                register u32 high asm("r1");
                register u32 low asm("r0");
                asm("" : : "r"(copy));
                high = copy[1] << 8;
                low = copy[0];
                    var_r1_4 = high;
                var_r0_6 = low;
                goto block_398;
            }
        }
        }
    case 0x8: {
        branch_origin = var_r7;
        asm("" : : "r"(branch_origin));
        var_r7 += 1;
        {
            register u8 *arguments asm("r1") = spC;
            register u32 byte asm("r0");
            asm("" : : "r"(arguments));
            byte = *var_r7;
            arguments[0] = byte;
            byte = var_r7[1];
            arguments[1] = byte;
            asm("" : "+r"(byte) : "r"(arguments));
            if ((s32)(byte << 24) < 0) {
                register u8 *copy asm("r0") = arguments;
                register u32 high asm("r0");
                register u32 low asm("r1");
                asm("" : : "r"(copy));
                high = copy[1] << 8;
                low = arguments[0];
                asm("" : : "r"(high), "r"(low));
                var_r0_5 = high;
                var_r1_3 = low;
                goto block_396;
            } else {
                register u8 *copy asm("r0") = spC;
                register u32 high asm("r1");
                register u32 low asm("r0");
                asm("" : : "r"(copy));
                high = copy[1] << 8;
                low = copy[0];
                asm("" : : "r"(high), "r"(low));
                var_r1_4 = high;
                var_r0_6 = low;
                goto block_398;
            }
        }
        }
    case 0x9:
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        {
            register u8 *arguments asm("r1") = spC;
            register volatile u16 *variables asm("r2") = sp2C;
            register u8 *copy asm("r0");
            register u32 offset asm("r0");
            register u32 low asm("r1");
            register u32 high asm("r0");
            copy = arguments;
            asm("" : : "r"(copy));
            offset = copy[0];
            variables += offset;
            copy = arguments;
            low = copy[1];
            high = copy[2] << 8;
            low |= high;
            *variables = low;
        }
        goto block_457;
    case 0x39:
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = *var_r7;
        var_r7 += 1;
        spC[2] = 0U;
        {
            register u8 *arguments asm("r2") = spC;
            register volatile u16 *variables asm("r1") = sp2C;
            register u8 *copy asm("r0") = spC;
            register u16 value asm("r0");
            variables += copy[0];
            copy = arguments;
            value = copy[1];
            *variables = value;
        }
        goto block_457;
    case 0xA: {
        register u8 *arguments asm("r3");
        register u32 script_value asm("r2");
        register u32 mask asm("r1");
        register u32 value asm("r0");
        register u8 *copy asm("r2");
        register volatile u16 *variables asm("r2");
        register u8 *read asm("r0");
        register u32 offset asm("r1");
        register volatile u16 *target asm("r1");
        register volatile u16 *source asm("r2");
        var_r7 += 1;
        arguments = spC;
        script_value = *var_r7;
        mask = 7;
        asm("" : "+r"(mask) : "r"(arguments), "r"(script_value));
        value = mask;
        arguments[0] = value & script_value;
        var_r7 += 1;
        copy = arguments;
        value = *var_r7;
        mask &= value;
        copy[1] = mask;
        variables = sp2C;
        read = arguments;
        offset = read[0] << 1;
        target = (volatile u16 *)((u32)variables + offset);
        value = read[1] << 1;
        source = (volatile u16 *)((u32)variables + value);
        value = *source;
        *target = value;
        goto block_457;
        }
    case 0xB: {
        register u8 *arguments asm("r1") = spC;
        register u32 next asm("r0") = 0;
        register volatile u16 *shared asm("r4");
        register volatile u16 *variables asm("r3");
        register u8 *cursor asm("r2");
        arguments[0] = next;
        shared = (volatile u16 *)D_02007574;
        cursor = arguments;
        variables = sp2C;
        do {
            register u32 offset asm("r0") = cursor[0] << 1;
            register volatile u16 *target asm("r1");
            register volatile u16 *source asm("r0");
            register u16 value asm("r0");
            target = (volatile u16 *)(offset + (u32)shared);
            source = (volatile u16 *)((u32)variables + offset);
            value = *source;
            *target = value;
            next = cursor[0] + 1;
            cursor[0] = next;
            asm("" : "+r"(next));
        } while ((u8)next <= 7);
        goto block_457;
        }
    case 0xC: {
        register u8 *arguments asm("r1") = spC;
        register u32 next asm("r0") = 0;
        register volatile u16 *shared asm("r4");
        register volatile u16 *variables asm("r3");
        register u8 *cursor asm("r2");
        arguments[0] = next;
        variables = sp2C;
        cursor = arguments;
        shared = (volatile u16 *)D_02007574;
        do {
            register u32 offset asm("r0") = cursor[0] << 1;
            register volatile u16 *target asm("r1");
            register volatile u16 *source asm("r0");
            register u16 value asm("r0");
            target = (volatile u16 *)((u32)variables + offset);
            source = (volatile u16 *)(offset + (u32)shared);
            value = *source;
            *target = value;
            next = cursor[0] + 1;
            cursor[0] = next;
            asm("" : "+r"(next));
        } while ((u8)next <= 7);
        goto block_457;
        }
    case 0x10: {
        register u32 expected asm("r2");
        register u32 value asm("r0");
        temp_r4 = var_r7;
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        var_r7 += 1;
        spC[3] = (u8) *var_r7;
        var_r7 += 1;
        spC[4] = (u8) *var_r7;
        {
            register volatile u16 *temporary asm("r1") = &frame.temporary[0];
            register u8 *arguments asm("r2") = spC;
            register u8 *copy asm("r0");
            register u32 low asm("r2");
            register u32 high asm("r0");
            register volatile u16 *variables asm("r1");
            register u32 offset asm("r0");
            copy = arguments;
            low = copy[1];
            high = copy[2] << 8;
            low |= high;
            *temporary = low;
            variables = sp2C;
            copy = spC;
            offset = copy[0] << 1;
            variables = (volatile u16 *)((u32)variables + offset);
            value = *variables;
            expected = low;
        }
        branch_origin = temp_r4;
        if (value != expected) {

        } else {
            if ((s32) (s8) spC[4] < 0) {
                var_r0_5 = spC[4] << 8;
                var_r1_3 = spC[3];
                goto block_396;
            }
            var_r1_4 = spC[4] << 8;
            var_r0_6 = spC[3];
            goto block_398;
            goto block_399;
        }
        goto block_457;
        }
    case 0x11: {
        register u32 expected asm("r2");
        register u32 value asm("r0");
        temp_r4_2 = var_r7;
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        var_r7 += 1;
        spC[3] = (u8) *var_r7;
        var_r7 += 1;
        spC[4] = (u8) *var_r7;
        {
            register volatile u16 *temporary asm("r1") = &frame.temporary[0];
            register u8 *arguments asm("r2") = spC;
            register u8 *copy asm("r0");
            register u32 low asm("r2");
            register u32 high asm("r0");
            register volatile u16 *variables asm("r1");
            register u32 offset asm("r0");
            copy = arguments;
            low = copy[1];
            high = copy[2] << 8;
            low |= high;
            *temporary = low;
            variables = sp2C;
            copy = spC;
            offset = copy[0] << 1;
            variables = (volatile u16 *)((u32)variables + offset);
            value = *variables;
            expected = low;
        }
        branch_origin = temp_r4_2;
        if (value <= expected) {

        } else {
            if ((s32) (s8) spC[4] < 0) {
                var_r0_5 = spC[4] << 8;
                var_r1_3 = spC[3];
                asm("" : : "r"(var_r0_5), "r"(var_r1_3), "r"(branch_origin));
                goto block_396;
            }
            var_r1_4 = spC[4] << 8;
            var_r0_6 = spC[3];
            asm("" : : "r"(var_r1_4), "r"(var_r0_6), "r"(branch_origin));
            goto block_398;
            goto block_399;
        }
        goto block_457;
        }
    case 0x12: {
        register u32 expected asm("r2");
        register u32 value asm("r0");
        temp_r4_3 = var_r7;
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        var_r7 += 1;
        spC[3] = (u8) *var_r7;
        var_r7 += 1;
        spC[4] = (u8) *var_r7;
        {
            register volatile u16 *temporary asm("r1") = &frame.temporary[0];
            register u8 *arguments asm("r2") = spC;
            register u8 *copy asm("r0");
            register u32 low asm("r2");
            register u32 high asm("r0");
            register volatile u16 *variables asm("r1");
            register u32 offset asm("r0");
            copy = arguments;
            low = copy[1];
            high = copy[2] << 8;
            low |= high;
            *temporary = low;
            variables = sp2C;
            copy = spC;
            offset = copy[0] << 1;
            variables = (volatile u16 *)((u32)variables + offset);
            value = *variables;
            expected = low;
        }
        branch_origin = temp_r4_3;
        if (value >= expected) {

        } else {
            if ((s32) (s8) spC[4] < 0) {
                var_r0_5 = spC[4] << 8;
                var_r1_3 = spC[3];
                asm("" : : "r"(var_r0_5), "r"(var_r1_3));
                goto block_396;
            }
            var_r1_4 = spC[4] << 8;
            var_r0_6 = spC[3];
            asm("" : : "r"(var_r1_4), "r"(var_r0_6));
            goto block_398;
            goto block_399;
        }
        goto block_457;
        }
    case 0x13: {
        register u32 byte asm("r3");
        register u32 value asm("r0");
        register u32 other asm("r2");
        temp_r4_4 = var_r7;
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = 7 & *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        var_r7 += 1;
        {
            register u8 *previous asm("r1") = spC;
            register u8 *arguments asm("r0");
            register volatile u16 *variables asm("r2");
            register u32 offset asm("r1");
            register volatile u16 *left asm("r1");
            register volatile u16 *right asm("r2");
            arguments = previous;
            byte = *var_r7;
            arguments[3] = byte;
            variables = sp2C;
            offset = arguments[0] << 1;
            left = (volatile u16 *)((u32)variables + offset);
            value = arguments[1] << 1;
            right = (volatile u16 *)((u32)variables + value);
            value = *left;
            other = *right;
            asm("" : : "r"(value), "r"(other));
        }
        branch_origin = temp_r4_4;
        if (value != other) {

        } else {
            register s32 signed_byte asm("r0") = byte << 24;
            if (signed_byte >= 0) {
                asm("" : : "r"(byte), "r"(branch_origin));
                goto block_397;
            }
            goto block_395;
            goto block_399;
        }
        goto block_457;
        }
    case 0x14: {
        register u32 byte asm("r3");
        register u32 value asm("r0");
        register u32 other asm("r2");
        temp_r4_5 = var_r7;
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = 7 & *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        var_r7 += 1;
        {
            register u8 *previous asm("r1") = spC;
            register u8 *arguments asm("r0");
            register volatile u16 *variables asm("r2");
            register u32 offset asm("r1");
            register volatile u16 *left asm("r1");
            register volatile u16 *right asm("r2");
            arguments = previous;
            byte = *var_r7;
            arguments[3] = byte;
            variables = sp2C;
            offset = arguments[0] << 1;
            left = (volatile u16 *)((u32)variables + offset);
            value = arguments[1] << 1;
            right = (volatile u16 *)((u32)variables + value);
            value = *left;
            other = *right;
            asm("" : : "r"(value), "r"(other));
        }
        branch_origin = temp_r4_5;
        if (value <= other) {

        } else {
            register s32 signed_byte asm("r0") = byte << 24;
            if (signed_byte < 0) {
                goto block_395;
            }
            goto block_397;
            goto block_399;
        }
        goto block_457;
        }
block_395:
        var_r0_5 = spC[3] << 8;
        var_r1_3 = spC[2];
block_396:
        {
            register u32 high asm("r0") = var_r0_5;
            register u32 low asm("r1") = var_r1_3;
            high |= low;
            high |= 0xFFFF0000;
            branch_origin += high;
        }
        goto block_399;
block_397:
        var_r1_4 = spC[3] << 8;
        var_r0_6 = spC[2];
block_398:
        {
            register u32 high asm("r1") = var_r1_4;
            register u32 low asm("r0") = var_r0_6;
            high |= low;
            branch_origin += high;
        }
block_399:
        var_r7 = branch_origin - 1;
        goto block_457;
    case 0x15:
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        {
            register volatile u16 *temporary asm("r1") = &frame.temporary[0];
            register u8 *arguments asm("r2") = spC;
            register u8 *copy asm("r0");
            register u32 low asm("r2");
            register u32 high asm("r0");
            register volatile u16 *variables asm("r1");
            register u32 offset asm("r0");
            register u16 original asm("r0");
            copy = arguments;
            low = copy[1];
            high = copy[2] << 8;
            low |= high;
            *temporary = low;
            variables = sp2C;
            copy = spC;
            offset = copy[0] << 1;
            variables = (volatile u16 *)((u32)variables + offset);
            original = *variables;
            var_r1_5 = variables;
            var_r0_7 = original;
            var_r2_2 = low;
            goto block_405;
        }
    case 0x16:
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        {
            register volatile u16 *temporary asm("r1") = &frame.temporary[0];
            register u8 *arguments asm("r2") = spC;
            register u8 *copy asm("r0");
            register u32 low asm("r2");
            register u32 high asm("r0");
            register volatile u16 *variables asm("r1");
            register u32 offset asm("r0");
            register u16 original asm("r0");
            copy = arguments;
            low = copy[1];
            high = copy[2] << 8;
            low |= high;
            *temporary = low;
            variables = sp2C;
            copy = spC;
            offset = copy[0] << 1;
            variables = (volatile u16 *)((u32)variables + offset);
            original = *variables;
            *variables = original - low;
            goto block_457;
        }
    case 0x17:
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        {
            register volatile u16 *temporary asm("r1") = &frame.temporary[0];
            register u8 *arguments asm("r2") = spC;
            register u8 *copy asm("r0");
            register u32 low asm("r2");
            register u32 high asm("r0");
            register volatile u16 *variables asm("r1");
            register u32 offset asm("r0");
            register u16 original asm("r0");
            copy = arguments;
            low = copy[1];
            high = copy[2] << 8;
            low |= high;
            *temporary = low;
            variables = sp2C;
            copy = spC;
            offset = copy[0] << 1;
            variables = (volatile u16 *)((u32)variables + offset);
            original = *variables;
            var_r1_6 = variables;
            var_r0_8 = original;
            var_r2_3 = low;
            goto block_408;
        }
    case 0x18:
        var_r7 += 1;
        spC[0] = 7 & *var_r7;
        var_r7 += 1;
        spC[1] = (u8) *var_r7;
        var_r7 += 1;
        spC[2] = (u8) *var_r7;
        {
            register volatile u16 *temporary asm("r2") = &frame.temporary[0];
            register u8 *arguments asm("r1") = spC;
            register u8 *copy asm("r0");
            register u32 low asm("r1");
            register u32 high asm("r0");
            register volatile u16 *variables asm("r4");
            register u32 offset asm("r0");
            copy = arguments;
            low = copy[1];
            high = copy[2] << 8;
            low |= high;
            *temporary = low;
            variables = sp2C;
            copy = spC;
            offset = copy[0];
            variables += offset;
            var_r4_2 = variables;
            var_r0_9 = *variables;
            var_r1_7 = *temporary;
            goto block_410;
        }
    case 0x19: {
        register u8 *arguments asm("r3");
        register u32 script_value asm("r2");
        register u32 mask asm("r1");
        register u32 value asm("r0");
        register u8 *copy asm("r2");
        register volatile u16 *variables asm("r2");
        register u8 *read asm("r0");
        register u32 offset asm("r1");
        register volatile u16 *target asm("r1");
        register volatile u16 *source asm("r2");
        var_r7 += 1;
        arguments = spC;
        script_value = *var_r7;
        mask = 7;
        asm("" : "+r"(mask) : "r"(arguments), "r"(script_value));
        value = mask;
        arguments[0] = value & script_value;
        var_r7 += 1;
        copy = arguments;
        value = *var_r7;
        mask &= value;
        copy[1] = mask;
        variables = sp2C;
        read = arguments;
        offset = read[0] << 1;
        target = (volatile u16 *)((u32)variables + offset);
        value = read[1] << 1;
        source = (volatile u16 *)((u32)variables + value);
        var_r1_5 = target;
        var_r0_7 = *source;
        var_r2_2 = *target;
block_405:
        *var_r1_5 = var_r0_7 + var_r2_2;
        goto block_457;
        }
    case 0x1A: {
        register u8 *arguments asm("r3");
        register u32 script_value asm("r2");
        register u32 mask asm("r1");
        register u32 value asm("r0");
        register u8 *copy asm("r2");
        register volatile u16 *variables asm("r1");
        register u8 *read asm("r0");
        register u32 offset asm("r2");
        register volatile u16 *target asm("r2");
        register volatile u16 *source asm("r1");
        var_r7 += 1;
        arguments = spC;
        script_value = *var_r7;
        mask = 7;
        asm("" : "+r"(mask) : "r"(arguments), "r"(script_value));
        value = mask;
        arguments[0] = value & script_value;
        var_r7 += 1;
        copy = arguments;
        value = *var_r7;
        mask &= value;
        copy[1] = mask;
        variables = sp2C;
        read = copy;
        offset = read[0] << 1;
        target = (volatile u16 *)((u32)variables + offset);
        value = read[1] << 1;
        source = (volatile u16 *)((u32)variables + value);
        {
            register u16 left asm("r0") = *target;
            register u16 right asm("r1") = *source;
            var_r2_4 = target;
            var_r0_10 = left - right;
            goto block_456;
        }
        }
    case 0x1B: {
        register u8 *arguments asm("r3");
        register u32 script_value asm("r2");
        register u32 mask asm("r1");
        register u32 value asm("r0");
        register u8 *copy asm("r2");
        register volatile u16 *variables asm("r3");
        register u8 *read asm("r0");
        register u32 offset asm("r1");
        register volatile u16 *target asm("r1");
        register volatile u16 *source asm("r3");
        var_r7 += 1;
        arguments = spC;
        script_value = *var_r7;
        mask = 7;
        asm("" : "+r"(mask) : "r"(arguments), "r"(script_value));
        value = mask;
        arguments[0] = value & script_value;
        var_r7 += 1;
        copy = arguments;
        value = *var_r7;
        mask &= value;
        copy[1] = mask;
        variables = sp2C;
        read = copy;
        offset = read[0] << 1;
        target = (volatile u16 *)((u32)variables + offset);
        value = read[1] << 1;
        source = (volatile u16 *)((u32)variables + value);
        var_r1_6 = target;
        var_r2_3 = *target;
        var_r0_8 = *source;
block_408:
        *var_r1_6 = var_r2_3 * var_r0_8;
        goto block_457;
        }
    case 0x1C: {
        register u8 *arguments asm("r3");
        register u32 script_value asm("r2");
        register u32 mask asm("r1");
        register u32 value asm("r0");
        register u8 *copy asm("r2");
        register volatile u16 *variables asm("r1");
        register u8 *read asm("r0");
        register u32 offset asm("r4");
        register volatile u16 *target asm("r4");
        register volatile u16 *source asm("r1");
        var_r7 += 1;
        arguments = spC;
        script_value = *var_r7;
        mask = 7;
        asm("" : "+r"(mask) : "r"(arguments), "r"(script_value));
        value = mask;
        arguments[0] = value & script_value;
        var_r7 += 1;
        copy = arguments;
        value = *var_r7;
        mask &= value;
        copy[1] = mask;
        variables = sp2C;
        read = copy;
        offset = read[0] << 1;
        target = (volatile u16 *)((u32)variables + offset);
        value = read[1] << 1;
        source = (volatile u16 *)((u32)variables + value);
        var_r4_2 = target;
        var_r0_9 = *target;
        var_r1_7 = *source;
block_410:
        *var_r4_2 = func_0805D484(var_r0_9, var_r1_7);
        goto block_457;
        }
    case 0x20:
        var_r7 += 1;
        spC[0] = 0;
        spC[1] = (u8) **(u8 **)((u32)D_02009118);
        goto loop_415;
script_text_advance:
        var_r7 += 1;
        goto loop_415;
script_text_glyph:
        {
            register volatile u16 *temporary asm("r2") = &frame.temporary[0];
            register u32 high asm("r1");
            register u32 low asm("r0");
            const volatile u8 *glyph = var_r7;
            high = glyph[1] << 8;
            low = glyph[0];
            low |= high;
            *temporary = low;
            window_emit_character(spC[1], *temporary);
        }
        var_r7 += 2;
        {
            register u32 base asm("r1") = (u32)D_020075A0;
            register u8 row asm("r2");
            register u32 flags asm("r1");
            register u32 mask asm("r0");
            row = spC[1];
            flags = ((struct ByteWindow *)(row * 0x354 + base))->unk9;
            mask = 1;
            mask &= flags;
            if (mask) {
                window_command(row, 4, 0, 0);
                func_08041100();
            }
        }
loop_415:
        temp_r0_39 = *var_r7;
        if (temp_r0_39 > 0x3F) goto script_text_glyph;
        temp_r0_40 = temp_r0_39 - 0xD;
        switch (temp_r0_40) {
        case 15:
            var_r7 += 1;
            spC[1] = (u8) *var_r7;
            break;
        case 16:
            spC[0] = 1;
            break;
        case 0: {
            register u32 base asm("r5") = (u32)D_020075A0;
            register u32 stride asm("r4");
            register u32 row asm("r0");
            register struct ByteWindow *first asm("r1");
            register u32 zero asm("r2");
            row = spC[1];
            stride = 0x354;
            first = (struct ByteWindow *)(row * stride + base);
            row = first->unkB + 1;
            zero = 0;
            first->unkB = row;
            row = spC[1];
            ((struct ByteWindow *)(row * stride + base))->unkA = zero;
            {
                register u32 current asm("r3") = spC[1];
                register struct ByteWindow *window asm("r2");
                register u32 flags asm("r1");
                register u32 mask asm("r0");
                row = current;
                row *= stride;
                window = (struct ByteWindow *)(row + base);
                flags = window->unk9;
                mask = 1;
                mask &= flags;
                    if (mask) {
                    register u32 y asm("r0") = window->unkB;
                    register s32 height asm("r1") = window->unk4 - 2;
                    if ((s32)y >= (height + (s32)((u32)height >> 31)) >> 1) {
                        window_command(current, 5, 0, 0);
                        row = spC[1];
                        first = (struct ByteWindow *)(row * stride + base);
                        row = first->unkB - 1;
                        first->unkB = row;
                    }
                }
            }
            break;
        }
        case 18: {
            register u8 *arguments asm("r1");
            register u8 *read asm("r0");
            register u8 *copy asm("r2");
            register u32 value asm("r0");
            register u32 digits asm("r1");
            register u32 mask asm("r0");
            var_r7 += 1;
            arguments = spC;
            value = *var_r7;
            arguments[2] = value;
            var_r7 += 1;
            read = arguments;
            digits = *var_r7;
            read[3] = digits;
            copy = read;
            mask = 0xF0;
            asm("" : "+r"(mask) : "r"(copy), "r"(digits));
            mask &= digits;
            mask >>= 4;
            copy[4] = mask;
            read = copy;
            digits = read[3];
            mask = 7;
            mask &= digits;
            copy[3] = mask;
            read = copy;
            value = read[1];
            {
                register volatile u16 *variables asm("r2") = sp2C;
                register u8 *index_source asm("r1") = spC;
                register u32 index asm("r1");
                register u32 number asm("r1");
                index = index_source[2] << 1;
                variables = (volatile u16 *)((u32)variables + index);
                number = *variables;
                func_08040F44(value, number, spC[3], spC[4]);
            }
            break;
        }
        case 17: {
            register u8 *arguments asm("r1") = spC;
            register u32 zero asm("r0") = 0;
            register volatile u16 *temporary asm("r6");
            register u32 name asm("r5");
            register u8 *copy asm("r4");
            register u32 initial_base asm("r0");
            register u32 window_base asm("r8");
            arguments[2] = zero;
            temporary = &frame.temporary[0];
            name = (u32)D_0200758C;
            copy = arguments;
            initial_base = (u32)D_020075A0;
            window_base = initial_base;
script_text_name_loop:
            {
                register u32 offset asm("r1") = copy[2] << 1;
                register u32 address asm("r0");
                register u32 high asm("r2");
                register u32 value asm("r0");
                register u8 next asm("r0");
                address = offset + 1;
                address += name;
                high = *(u8 *)address << 8;
                offset += name;
                value = *(u8 *)offset;
                value |= high;
                *temporary = value;
                if (value != 0) {
                window_emit_character(copy[1], *temporary);
                {
                    register u32 row asm("r2") = copy[1];
                    register u32 flags asm("r1");
                    register u32 mask asm("r0");
                    value = row * 0x354 + window_base;
                    flags = ((struct ByteWindow *)value)->unk9;
                    mask = 1;
                    mask &= flags;
                            if (mask) {
                        window_command(row, 4, 0, 0);
                        func_08041100();
                    }
                }
                value = copy[2] + 1;
                copy[2] = value;
                next = value;
                if (next <= 7) goto script_text_name_loop;
                }
            }
            break;
        }
        }
        if (spC[0] == 0) goto script_text_advance;
        goto block_457;
    case 0x21: {
        register u8 *arguments asm("r1");
        register u8 *copy asm("r0");
        register volatile u16 *temporary asm("r2");
        register u32 low asm("r1");
        register u32 high asm("r0");
        register const u8 *child asm("r0");
        register const u8 *held_child asm("r4");
        var_r7 += 1;
        arguments = spC;
        high = *var_r7;
        arguments[0] = high;
        var_r7 += 1;
        high = *var_r7;
        arguments[1] = high;
        temporary = &frame.temporary[0];
        copy = arguments;
        low = copy[0];
        high = copy[1] << 8;
        low |= high;
        *temporary = low;
        child = script_get_entry(*temporary);
        held_child = child;
        asm("" : : "r"(child), "r"(held_child));
        script_interpret(child);
        goto block_457;
    }
    case 0x30:
    case 0x31:
        var_r7 += 1;
        goto block_457;
    case 0x32: {
        register u8 *arguments asm("r2");
        register u32 raw asm("r1");
        register u32 mask asm("r0");
        register u8 *copy asm("r1");
        register u8 *read asm("r0");
        register u32 value asm("r0");
        var_r7 += 1;
        arguments = spC;
        raw = *var_r7;
        mask = 7;
        mask &= raw;
        arguments[0] = mask;
        var_r7 += 1;
        copy = arguments;
        value = *var_r7;
        copy[1] = value;
        read = copy;
        value = read[1];
        switch (value) {
        case 1: {
            register volatile u16 *variables asm("r1") = sp2C;
            read = arguments;
            asm("" : : "r"(read));
            value = read[0] << 1;
            variables = (volatile u16 *)((u32)variables + value);
            value = *variables;
            func_08000F88(value);
            break;
        }
        case 0: {
            register volatile u16 *variables asm("r1") = sp2C;
            read = spC;
            value = read[0] << 1;
            variables = (volatile u16 *)((u32)variables + value);
            value = *variables;
            func_08000FD8(value);
            break;
        }
        }
        goto block_457;
    }
    case 0x33: {
        register u8 *arguments asm("r1");
        register u8 *copy asm("r0");
        register volatile u16 *temporary asm("r2");
        register volatile u16 *held asm("r6");
        register u32 low asm("r1");
        register u32 high asm("r0");
        var_r7 += 1;
        arguments = spC;
        high = *var_r7;
        arguments[0] = high;
        var_r7 += 1;
        high = *var_r7;
        arguments[1] = high;
        temporary = &frame.temporary[0];
        copy = arguments;
        low = copy[0];
        high = copy[1] << 8;
        low |= high;
        *temporary = low;
        var_r7 += 1;
        arguments = spC;
        high = *var_r7;
        arguments[2] = high;
        copy = arguments;
        high = copy[2];
        held = temporary;
        asm("" : : "r"(held), "r"(high));
        switch (high) {
        case 1:
            func_08000F88(*held);
            break;
        case 0:
            func_08000FD8(*held);
            break;
        }
        goto block_457;
    }
    case 0x34: {
        register u8 *arguments asm("r3");
        register u32 raw asm("r2");
        register u32 mask asm("r1");
        register u32 value asm("r0");
        register u8 *copy asm("r2");
        register volatile u16 *variables asm("r4");
        register u8 *read asm("r0");
        register u32 index asm("r1");
        register u16 result asm("r0");
        var_r7 += 1;
        arguments = spC;
        raw = *var_r7;
        mask = 7;
        asm("" : "+r"(mask) : "r"(arguments), "r"(raw));
        value = mask;
        arguments[0] = value & raw;
        var_r7 += 1;
        copy = arguments;
        value = *var_r7;
        mask &= value;
        copy[1] = mask;
        variables = sp2C;
        read = copy;
        value = read[1] << 1;
        result = *(volatile u16 *)((u32)variables + value);
        result = func_08001040(result);
        {
            register volatile u16 *temporary asm("r1") = &frame.temporary[0];
            register u8 *select asm("r1");
            *temporary = result;
            select = spC;
                index = select[0] << 1;
            variables = (volatile u16 *)((u32)variables + index);
            *variables = result;
        }
        goto block_457;
    }
    case 0x35:
        goto script_command_35;
    case 0x22:
        goto script_done;
    }
    goto block_457;
script_command_6_accepted:
    {
        register u32 base asm("r2") = (u32)D_020075A0;
        register u32 value asm("r0");
        register volatile u16 *variables asm("r1");
        value = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
        variables = menu_variables;
        variables[1] = value;
    }
script_command_6_finished:
    func_08040D0C(spC[2], spC[0]);
    goto block_37;
script_command_38_start_accepted:
    {
        register u32 value asm("r0") = 1;
        register volatile u16 *variables asm("r2");
        variables = menu_variables;
        *variables = value;
        value = menu_keys[1];
        variables[1] = value;
    }
block_450:
    func_080404BC(spC[2], 0xBU);
    goto block_457;
script_command_38_aborted:
    {
        register u32 value asm("r0") = 0;
        register volatile u16 *variables asm("r3");
        variables = menu_variables;
        *variables = value;
    }
    func_080404BC(spC[2], 3U);
    goto block_457;
script_command_3c_accepted:
    {
        register u32 base asm("r2") = (u32)D_020075A0;
        register u32 value asm("r0");
        register volatile u16 *variables asm("r1");
        value = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
        variables = menu_variables;
        variables[1] = value;
    }
    goto block_454;
script_command_36_accepted:
    {
        register u32 base asm("r2") = (u32)D_020075A0;
        register u32 value asm("r0");
        register volatile u16 *variables asm("r2");
        value = ((struct ByteWindow *)(spC[2] * 0x354 + base))->unkD;
        variables = menu_variables;
        variables[1] = value;
    }
block_454:
    func_08040D0C(spC[2], spC[0]);
    goto block_457;
script_command_35:
    {
        register u8 *arguments asm("r2");
        register u32 raw asm("r1");
        register u32 mask asm("r0");
        register u8 *copy asm("r1");
        register u8 *read asm("r0");
        register volatile u16 *temporary asm("r4");
        register u32 low asm("r1");
        register u32 high asm("r0");
        register volatile u16 *variables asm("r2");
        register u8 *select asm("r1");
        register u32 index asm("r1");
        var_r7 += 1;
        arguments = spC;
        raw = *var_r7;
        mask = 7;
        mask &= raw;
        arguments[0] = mask;
        var_r7 += 1;
        copy = arguments;
        high = *var_r7;
        copy[1] = high;
        var_r7 += 1;
        high = *var_r7;
        copy[2] = high;
        temporary = &frame.temporary[0];
        read = copy;
        low = read[1];
        high = read[2] << 8;
        low |= high;
        *temporary = low;
        var_r0_10 = func_08001040(*temporary);
        temporary[1] = var_r0_10;
        variables = sp2C;
        select = spC;
        index = select[0] << 1;
        var_r2_4 = (volatile u16 *)((u32)variables + index);
    }
block_456:
    *var_r2_4 = var_r0_10;
block_457:
    var_r7 += 1;
    goto loop_1;
script_done:
    return 0;
}
