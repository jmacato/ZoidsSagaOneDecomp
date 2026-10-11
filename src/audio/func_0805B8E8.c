#include "types.h"

// Audio callbacks share low registers; this frame also preserves the caller's high registers.
#pragma GCC optimize("no-reorder-blocks", "no-ipa-pure-const", "no-crossjumping",                  \
                     "no-tree-tail-merge", "align-functions=2")
register u32 value asm("r0");
register u32 argument asm("r1");
register u32 selector asm("r2");
register u32 cursor asm("r3");
register u32 voice asm("r4");
register u32 track asm("r5");
register u32 selected asm("r6");
register u32 owner asm("r7");
register u32 candidate asm("r8");
register u32 instrument asm("r9");
register u32 *note_stack asm("sp");

#define KEEP(value) asm volatile("" : "+r"(value))
#define COPY(destination, source)                                                                  \
    asm volatile("add %0, %1, #0" : "=r"(destination) : "r"(source) : "cc")
#define CALL(target)                                                                               \
    asm volatile("bl " #target                                                                     \
                 : "+r"(value), "+r"(argument), "+r"(selector), "+r"(cursor)                       \
                 :                                                                                 \
                 : "memory", "cc")

void func_0805B8E8(void)
{
    asm volatile("push {r4, r5, r6, r7, lr}\n\tmov r4, r8\n\tmov r5, r9\n\tmov r6, r10\n\tmov r7, "
                 "r11\n\tpush {r4, r5, r6, r7}\n\tsub sp, #24"
                 : "=r"(voice), "=r"(track), "=r"(selected), "=r"(owner)
                 :
                 : "memory");
    note_stack[0] = argument;
    COPY(track, selector);
    asm volatile("ldr %0, note_literals" : "=r"(argument));
    argument = *(u32 *)argument;
    KEEP(argument);
    note_stack[1] = argument;
    asm volatile("ldr %0, note_literals+4" : "=r"(argument));
    value += argument;
    KEEP(value);
    value = *(u8 *)value;
    KEEP(value);
    *(u8 *)(track + 4) = value;
    cursor = *(u32 *)(track + 0x40);
    KEEP(cursor);
    value = *(u8 *)cursor;
    KEEP(value);
    asm goto("cmp %0, #128\n\tbhs %l[select_instrument]" : : "r"(value) : "cc" : select_instrument);
    *(u8 *)(track + 5) = value;
    cursor++;
    KEEP(cursor);
    value = *(u8 *)cursor;
    KEEP(value);
    asm goto("cmp %0, #128\n\tbhs %l[save_cursor]" : : "r"(value) : "cc" : save_cursor);
    *(u8 *)(track + 6) = value;
    cursor++;
    KEEP(cursor);
    value = *(u8 *)cursor;
    KEEP(value);
    asm goto("cmp %0, #128\n\tbhs %l[save_cursor]" : : "r"(value) : "cc" : save_cursor);
    argument = *(u8 *)(track + 4);
    KEEP(argument);
    argument += value;
    KEEP(argument);
    *(u8 *)(track + 4) = argument;
    cursor++;
    KEEP(cursor);
save_cursor:
    *(u32 *)(track + 0x40) = cursor;
select_instrument:
    value = 0;
    KEEP(value);
    note_stack[5] = value;
    COPY(voice, track);
    voice += 0x24;
    KEEP(voice);
    selector = *(u8 *)voice;
    KEEP(selector);
    value = 0xC0;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[direct_instrument]"
             :
             : "r"(value), "r"(selector)
             : "cc"
             : direct_instrument);
    cursor = *(u8 *)(track + 5);
    KEEP(cursor);
    value = 0x40;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[direct_key]" : : "r"(value), "r"(selector) : "cc" : direct_key);
    argument = *(u32 *)(track + 0x2C);
    KEEP(argument);
    argument += cursor;
    KEEP(argument);
    value = *(u8 *)argument;
    KEEP(value);
    goto instrument_index;
direct_key:
    COPY(value, cursor);
instrument_index:
    argument = value << 1;
    KEEP(argument);
    argument += value;
    KEEP(argument);
    argument <<= 2;
    KEEP(argument);
    value = *(u32 *)(track + 0x28);
    KEEP(value);
    argument += value;
    KEEP(argument);
    instrument = argument;
    asm volatile("" : "+h"(instrument));
    selected = instrument;
    KEEP(selected);
    argument = *(u8 *)selected;
    KEEP(argument);
    value = 0xC0;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[valid_instrument]"
             :
             : "r"(value), "r"(argument)
             : "cc"
             : valid_instrument);
    goto finish;
valid_instrument:
    value = 0x80;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[priority]" : : "r"(value), "r"(selector) : "cc" : priority);
    argument = *(u8 *)(selected + 3);
    KEEP(argument);
    value = 0x80;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[drum_key]" : : "r"(value), "r"(argument) : "cc" : drum_key);
    argument -= 0xC0;
    KEEP(argument);
    argument <<= 1;
    KEEP(argument);
    note_stack[5] = argument;
drum_key:
    cursor = *(u8 *)(selected + 1);
    KEEP(cursor);
    goto priority;
direct_instrument:
    instrument = voice;
    asm volatile("" : "+h"(instrument));
    cursor = *(u8 *)(track + 5);
    KEEP(cursor);
priority:
    note_stack[2] = cursor;
    selected = note_stack[0];
    KEEP(selected);
    argument = *(u8 *)(selected + 9);
    KEEP(argument);
    value = *(u8 *)(track + 0x1D);
    KEEP(value);
    value += argument;
    KEEP(value);
    asm goto("cmp %0, #255\n\tbls %l[priority_ready]" : : "r"(value) : "cc" : priority_ready);
    value = 255;
    KEEP(value);
priority_ready:
    note_stack[4] = value;
    selected = instrument;
    KEEP(selected);
    value = *(u8 *)selected;
    KEEP(value);
    selected = 7;
    KEEP(selected);
    selected &= value;
    KEEP(selected);
    note_stack[3] = selected;
    asm goto("beq %l[find_pcm]" : : : : find_pcm);
    value = note_stack[1];
    KEEP(value);
    voice = *(u32 *)(value + 0x1C);
    KEEP(voice);
    asm goto("cmp %0, #0\n\tbne %l[hardware_voice]" : : "r"(voice) : "cc" : hardware_voice);
    goto finish;
hardware_voice:
    selected--;
    KEEP(selected);
    value = selected << 6;
    KEEP(value);
    voice += value;
    KEEP(voice);
    argument = *(u8 *)voice;
    KEEP(argument);
    value = 0xC7;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[attach]" : : "r"(value), "r"(argument) : "cc" : attach);
    value = 0x40;
    KEEP(value);
    asm goto("tst %0, %1\n\tbne %l[attach]" : : "r"(value), "r"(argument) : "cc" : attach);
    argument = *(u8 *)(voice + 0x13);
    KEEP(argument);
    value = note_stack[4];
    KEEP(value);
    asm goto("cmp %0, %1\n\tblo %l[attach]\n\tbeq %l[compare_owner]"
             :
             : "r"(argument), "r"(value)
             : "cc"
             : attach, compare_owner);
    goto finish;
compare_owner:
    value = *(u32 *)(voice + 0x2C);
    KEEP(value);
    asm goto("cmp %0, %1\n\tbhs %l[attach]" : : "r"(value), "r"(track) : "cc" : attach);
    goto finish;
find_pcm:
    selected = note_stack[4];
    KEEP(selected);
    COPY(owner, track);
    selector = 0;
    KEEP(selector);
    candidate = selector;
    asm volatile("" : "+h"(candidate));
    voice = note_stack[1];
    KEEP(voice);
    cursor = *(u8 *)(voice + 6);
    KEEP(cursor);
    voice += 0x50;
    KEEP(voice);
scan:
    argument = *(u8 *)voice;
    KEEP(argument);
    value = 0xC7;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[attach]" : : "r"(value), "r"(argument) : "cc" : attach);
    value = 0x40;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[active_voice]"
             :
             : "r"(value), "r"(argument)
             : "cc"
             : active_voice);
    asm goto("cmp %0, #0\n\tbne %l[compare_priority]" : : "r"(selector) : "cc" : compare_priority);
    selector++;
    KEEP(selector);
    selected = *(u8 *)(voice + 0x13);
    KEEP(selected);
    owner = *(u32 *)(voice + 0x2C);
    KEEP(owner);
    goto choose_voice;
active_voice:
    asm goto("cmp %0, #0\n\tbne %l[next_voice]" : : "r"(selector) : "cc" : next_voice);
compare_priority:
    value = *(u8 *)(voice + 0x13);
    KEEP(value);
    asm goto("cmp %0, %1\n\tbhs %l[compare_pcm_owner]"
             :
             : "r"(value), "r"(selected)
             : "cc"
             : compare_pcm_owner);
    COPY(selected, value);
    owner = *(u32 *)(voice + 0x2C);
    KEEP(owner);
    goto choose_voice;
compare_pcm_owner:
    asm goto("bhi %l[next_voice]" : : : : next_voice);
    value = *(u32 *)(voice + 0x2C);
    KEEP(value);
    asm goto("cmp %0, %1\n\tbls %l[same_owner]" : : "r"(value), "r"(owner) : "cc" : same_owner);
    COPY(owner, value);
    goto choose_voice;
same_owner:
    asm goto("blo %l[next_voice]" : : : : next_voice);
choose_voice:
    candidate = voice;
    asm volatile("" : "+h"(candidate));
next_voice:
    voice += 0x40;
    KEEP(voice);
    asm goto("sub %0, #1\n\tbgt %l[scan]" : "+r"(cursor) : : "cc" : scan);
    voice = candidate;
    KEEP(voice);
    asm goto("cmp %0, #0\n\tbeq %l[finish]" : : "r"(voice) : "cc" : finish);
attach:
    COPY(value, voice);
    CALL(func_0805BFF4);
    argument = 0;
    KEEP(argument);
    *(u32 *)(voice + 0x30) = argument;
    cursor = *(u32 *)(track + 0x20);
    KEEP(cursor);
    *(u32 *)(voice + 0x34) = cursor;
    asm goto("cmp %0, #0\n\tbeq %l[attach_head]" : : "r"(cursor) : "cc" : attach_head);
    *(u32 *)(cursor + 0x30) = voice;
attach_head:
    *(u32 *)(track + 0x20) = voice;
    *(u32 *)(voice + 0x2C) = track;
    value = *(u8 *)(track + 0x1B);
    KEEP(value);
    *(u8 *)(track + 0x1C) = value;
    asm goto("cmp %0, %1\n\tbeq %l[update_track]"
             :
             : "r"(value), "r"(argument)
             : "cc"
             : update_track);
    COPY(argument, track);
    CALL(func_0805BB28);
update_track:
    value = note_stack[0];
    KEEP(value);
    COPY(argument, track);
    CALL(func_0805C578);
    value = *(u32 *)(track + 4);
    KEEP(value);
    *(u32 *)(voice + 0x10) = value;
    value = note_stack[4];
    KEEP(value);
    *(u8 *)(voice + 0x13) = value;
    value = note_stack[2];
    KEEP(value);
    *(u8 *)(voice + 8) = value;
    value = note_stack[5];
    KEEP(value);
    *(u8 *)(voice + 0x14) = value;
    selected = instrument;
    KEEP(selected);
    value = *(u8 *)selected;
    KEEP(value);
    *(u8 *)(voice + 1) = value;
    owner = *(u32 *)(selected + 4);
    KEEP(owner);
    *(u32 *)(voice + 0x24) = owner;
    value = *(u32 *)(selected + 8);
    KEEP(value);
    *(u32 *)(voice + 4) = value;
    value = *(u16 *)(track + 0x1E);
    KEEP(value);
    *(u16 *)(voice + 0xC) = value;
    CALL(func_0805B8B8);
    argument = *(u8 *)(voice + 8);
    KEEP(argument);
    value = 8;
    KEEP(value);
    value = *(s8 *)(track + value);
    KEEP(value);
    asm goto("add %0, %1, %2\n\tbpl %l[pitch_ready]"
             : "=r"(cursor)
             : "r"(argument), "r"(value)
             : "cc"
             : pitch_ready);
    cursor = 0;
    KEEP(cursor);
pitch_ready:
    selected = note_stack[3];
    KEEP(selected);
    asm goto("cmp %0, #0\n\tbeq %l[pcm_pitch]" : : "r"(selected) : "cc" : pcm_pitch);
    selected = instrument;
    KEEP(selected);
    value = *(u8 *)(selected + 2);
    KEEP(value);
    *(u8 *)(voice + 0x1E) = value;
    argument = *(u8 *)(selected + 3);
    KEEP(argument);
    value = 0x80;
    KEEP(value);
    asm goto("tst %0, %1\n\tbne %l[default_length]"
             :
             : "r"(value), "r"(argument)
             : "cc"
             : default_length);
    value = 0x70;
    KEEP(value);
    asm goto("tst %0, %1\n\tbne %l[length_ready]"
             :
             : "r"(value), "r"(argument)
             : "cc"
             : length_ready);
default_length:
    argument = 8;
    KEEP(argument);
length_ready:
    *(u8 *)(voice + 0x1F) = argument;
    selector = *(u8 *)(track + 9);
    KEEP(selector);
    COPY(argument, cursor);
    value = note_stack[3];
    KEEP(value);
    cursor = note_stack[1];
    KEEP(cursor);
    cursor = *(u32 *)(cursor + 0x30);
    KEEP(cursor);
    CALL(func_0805B864);
    goto start;
pcm_pitch:
    selector = *(u8 *)(track + 9);
    KEEP(selector);
    COPY(argument, cursor);
    COPY(value, owner);
    CALL(func_0805BB78);
start:
    *(u32 *)(voice + 0x20) = value;
    value = 0x80;
    KEEP(value);
    *(u8 *)voice = value;
    argument = *(u8 *)track;
    KEEP(argument);
    value = 0xF0;
    KEEP(value);
    value &= argument;
    KEEP(value);
    *(u8 *)track = value;
finish:
    asm volatile("add sp, #24\n\tpop {r0, r1, r2, r3, r4, r5, r6, r7}\n\t"
                 "mov r8, r0\n\tmov r9, r1\n\tmov r10, r2\n\tmov r11, r3\n\tpop {r0}\n\tbx r0"
                 :
                 :
                 : "memory");
    __builtin_unreachable();
}

const u16 note_padding __attribute__((section(".text"), aligned(2))) = 0;
const u32 note_literals[2] __attribute__((section(".text"), aligned(4))) = {0x03007FF0, 0x085662F4};
