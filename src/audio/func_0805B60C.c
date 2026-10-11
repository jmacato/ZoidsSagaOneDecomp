#include "types.h"

// Player callbacks preserve the caller's high registers through a shared return frame.
#pragma GCC optimize("no-reorder-blocks", "no-ipa-pure-const", "no-crossjumping",                  \
                     "no-tree-tail-merge", "align-functions=2")
register u32 value asm("r0");
register u32 argument asm("r1");
register u32 remaining asm("r2");
register u32 callback asm("r3");
register u32 channel asm("r4");
register u32 track asm("r5");
register u32 count asm("r6");
register u32 player asm("r7");
register u32 engine asm("r8");
register u32 saved_count asm("r9");
register u32 track_bit asm("r10");
register u32 active_tracks asm("r11");

#define KEEP(value) asm volatile("" : "+r"(value))
#define COPY(destination, source)                                                                  \
    asm volatile("add %0, %1, #0" : "=r"(destination) : "r"(source) : "cc")
#define CALL(target)                                                                               \
    asm volatile("bl " #target                                                                     \
                 : "+r"(value), "+r"(argument), "+r"(remaining), "+r"(callback)                    \
                 :                                                                                 \
                 : "memory", "cc")

void func_0805B60C(void)
{
    asm volatile("ldr %0, player_literals+8" : "=r"(remaining));
    callback = *(u32 *)(value + 0x34);
    KEEP(callback);
    asm goto("cmp %0, %1\n\tbeq %l[enter]" : : "r"(remaining), "r"(callback) : "cc" : enter);
    asm volatile("bx lr");
    __builtin_unreachable();
enter:
    callback++;
    KEEP(callback);
    *(u32 *)(value + 0x34) = callback;
    asm volatile("push {r0, lr}" : : "r"(value) : "memory");
    callback = *(u32 *)(value + 0x38);
    KEEP(callback);
    asm goto("cmp %0, #0\n\tbeq %l[save_registers]" : : "r"(callback) : "cc" : save_registers);
    value = *(u32 *)(value + 0x3C);
    KEEP(value);
    CALL(func_0805B864);
save_registers:
    asm volatile("pop {r0}\n\tpush {r4, r5, r6, r7}\n\t"
                 "mov r4, r8\n\tmov r5, r9\n\tmov r6, r10\n\tmov r7, r11\n\t"
                 "push {r4, r5, r6, r7}"
                 : "=r"(value), "=r"(channel), "=r"(track), "=r"(count), "=r"(player)
                 :
                 : "memory");
    COPY(player, value);
    value = *(u32 *)(player + 4);
    KEEP(value);
    asm goto("cmp %0, #0\n\tbge %l[fade]" : : "r"(value) : "cc" : fade);
    goto finish;
fade:
    asm volatile("ldr %0, player_literals+4" : "=r"(value));
    value = *(u32 *)value;
    KEEP(value);
    engine = value;
    asm volatile("" : "+h"(engine));
    COPY(value, player);
    CALL(func_0805C4B0);
    value = *(u32 *)(player + 4);
    KEEP(value);
    asm goto("cmp %0, #0\n\tbge %l[tempo]" : : "r"(value) : "cc" : tempo);
    goto finish;
tempo:
    value = *(u16 *)(player + 0x22);
    KEEP(value);
    argument = *(u16 *)(player + 0x20);
    KEEP(argument);
    value += argument;
    KEEP(value);
    goto tempo_update;
tick:
    count = *(u8 *)(player + 8);
    KEEP(count);
    track = *(u32 *)(player + 0x2C);
    KEEP(track);
    callback = 1;
    KEEP(callback);
    channel = 0;
    KEEP(channel);
track_tick:
    value = *(u8 *)track;
    KEEP(value);
    argument = 0x80;
    KEEP(argument);
    asm goto("tst %0, %1\n\tbne %l[active_track]"
             :
             : "r"(argument), "r"(value)
             : "cc"
             : active_track);
    goto next_track;
active_track:
    track_bit = callback;
    asm volatile("" : "+h"(track_bit));
    channel |= callback;
    KEEP(channel);
    active_tracks = channel;
    asm volatile("" : "+h"(active_tracks));
    channel = *(u32 *)(track + 0x20);
    KEEP(channel);
    asm goto("cmp %0, #0\n\tbeq %l[reset_track]" : : "r"(channel) : "cc" : reset_track);
channel_tick:
    argument = *(u8 *)channel;
    KEEP(argument);
    value = 0xC7;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[unlink_channel]"
             :
             : "r"(value), "r"(argument)
             : "cc"
             : unlink_channel);
    value = *(u8 *)(channel + 0x10);
    KEEP(value);
    asm goto("cmp %0, #0\n\tbeq %l[next_channel]" : : "r"(value) : "cc" : next_channel);
    value--;
    KEEP(value);
    *(u8 *)(channel + 0x10) = value;
    asm goto("bne %l[next_channel]" : : : : next_channel);
    value = 0x40;
    KEEP(value);
    argument |= value;
    KEEP(argument);
    *(u8 *)channel = argument;
    goto next_channel;
unlink_channel:
    COPY(value, channel);
    CALL(func_0805BFF4);
next_channel:
    channel = *(u32 *)(channel + 0x34);
    KEEP(channel);
    asm goto("cmp %0, #0\n\tbne %l[channel_tick]" : : "r"(channel) : "cc" : channel_tick);
reset_track:
    callback = *(u8 *)track;
    KEEP(callback);
    value = 0x40;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[wait]" : : "r"(value), "r"(callback) : "cc" : wait);
    COPY(value, track);
    CALL(func_0805C008);
    value = 0x80;
    KEEP(value);
    *(u8 *)track = value;
    value = 2;
    KEEP(value);
    *(u8 *)(track + 0xF) = value;
    value = 0x40;
    KEEP(value);
    *(u8 *)(track + 0x13) = value;
    value = 0x16;
    KEEP(value);
    *(u8 *)(track + 0x19) = value;
    value = 1;
    KEEP(value);
    argument = track + 6;
    KEEP(argument);
    *(u8 *)(argument + 0x1E) = value;
    goto wait;
command:
    remaining = *(u32 *)(track + 0x40);
    KEEP(remaining);
    argument = *(u8 *)remaining;
    KEEP(argument);
    asm goto("cmp %0, #128\n\tbhs %l[new_command]" : : "r"(argument) : "cc" : new_command);
    argument = *(u8 *)(track + 7);
    KEEP(argument);
    goto dispatch;
new_command:
    remaining++;
    KEEP(remaining);
    *(u32 *)(track + 0x40) = remaining;
    asm goto("cmp %0, #189\n\tblo %l[dispatch]" : : "r"(argument) : "cc" : dispatch);
    *(u8 *)(track + 7) = argument;
dispatch:
    asm goto("cmp %0, #207\n\tblo %l[control]" : : "r"(argument) : "cc" : control);
    value = engine;
    KEEP(value);
    callback = *(u32 *)(value + 0x38);
    KEEP(callback);
    COPY(value, argument);
    value -= 0xCF;
    KEEP(value);
    COPY(argument, player);
    COPY(remaining, track);
    CALL(func_0805B864);
    goto wait;
control:
    asm goto("cmp %0, #176\n\tbls %l[wait_command]" : : "r"(argument) : "cc" : wait_command);
    COPY(value, argument);
    value -= 0xB1;
    KEEP(value);
    *(u8 *)(player + 0xA) = value;
    callback = engine;
    KEEP(callback);
    callback = *(u32 *)(callback + 0x34);
    KEEP(callback);
    value <<= 2;
    KEEP(value);
    callback = *(u32 *)(callback + value);
    KEEP(callback);
    COPY(value, player);
    COPY(argument, track);
    CALL(func_0805B864);
    value = *(u8 *)track;
    KEEP(value);
    asm goto("cmp %0, #0\n\tbeq %l[restore_track_mask]" : : "r"(value) : "cc" : restore_track_mask);
    goto wait;
wait_command:
    asm volatile("ldr %0, player_literals" : "=r"(value));
    argument -= 0x80;
    KEEP(argument);
    argument += value;
    KEEP(argument);
    value = *(u8 *)argument;
    KEEP(value);
    *(u8 *)(track + 1) = value;
wait:
    value = *(u8 *)(track + 1);
    KEEP(value);
    asm goto("cmp %0, #0\n\tbeq %l[command]" : : "r"(value) : "cc" : command);
    value--;
    KEEP(value);
    *(u8 *)(track + 1) = value;
    argument = *(u8 *)(track + 0x19);
    KEEP(argument);
    asm goto("cmp %0, #0\n\tbeq %l[restore_track_mask]"
             :
             : "r"(argument)
             : "cc"
             : restore_track_mask);
    value = *(u8 *)(track + 0x17);
    KEEP(value);
    asm goto("cmp %0, #0\n\tbeq %l[restore_track_mask]" : : "r"(value) : "cc" : restore_track_mask);
    value = *(u8 *)(track + 0x1C);
    KEEP(value);
    asm goto("cmp %0, #0\n\tbeq %l[modulate]" : : "r"(value) : "cc" : modulate);
    value--;
    KEEP(value);
    *(u8 *)(track + 0x1C) = value;
    goto restore_track_mask;
modulate:
    value = *(u8 *)(track + 0x1A);
    KEEP(value);
    value += argument;
    KEEP(value);
    *(u8 *)(track + 0x1A) = value;
    COPY(argument, value);
    value -= 0x40;
    KEEP(value);
    value <<= 24;
    KEEP(value);
    asm goto("bpl %l[falling_wave]" : : : : falling_wave);
    remaining = (s8)argument;
    KEEP(remaining);
    goto modulation_depth;
falling_wave:
    value = 0x80;
    KEEP(value);
    remaining = value - argument;
    KEEP(remaining);
modulation_depth:
    value = *(u8 *)(track + 0x17);
    KEEP(value);
    asm volatile("mul %0, %1" : "+r"(value) : "r"(remaining) : "cc");
    remaining = (s32)value >> 6;
    KEEP(remaining);
    value = *(u8 *)(track + 0x16);
    KEEP(value);
    value ^= remaining;
    KEEP(value);
    value <<= 24;
    KEEP(value);
    asm goto("beq %l[restore_track_mask]" : : : : restore_track_mask);
    *(u8 *)(track + 0x16) = remaining;
    value = *(u8 *)track;
    KEEP(value);
    argument = *(u8 *)(track + 0x18);
    KEEP(argument);
    asm goto("cmp %0, #0\n\tbne %l[volume_modulation]"
             :
             : "r"(argument)
             : "cc"
             : volume_modulation);
    argument = 0xC;
    KEEP(argument);
    goto set_modulation_flags;
volume_modulation:
    argument = 3;
    KEEP(argument);
set_modulation_flags:
    value |= argument;
    KEEP(value);
    *(u8 *)track = value;
restore_track_mask:
    callback = track_bit;
    KEEP(callback);
    channel = active_tracks;
    KEEP(channel);
next_track:
    asm goto("sub %0, #1\n\tble %l[tick_end]" : "+r"(count) : : "cc" : tick_end);
    value = 0x50;
    KEEP(value);
    track += value;
    KEEP(track);
    callback <<= 1;
    KEEP(callback);
    goto track_tick;
tick_end:
    value = *(u32 *)(player + 0xC);
    KEEP(value);
    value++;
    KEEP(value);
    *(u32 *)(player + 0xC) = value;
    asm goto("cmp %0, #0\n\tbne %l[tracks_remain]" : : "r"(channel) : "cc" : tracks_remain);
    value = 0x80;
    KEEP(value);
    value <<= 24;
    KEEP(value);
    *(u32 *)(player + 4) = value;
    goto finish;
tracks_remain:
    *(u32 *)(player + 4) = channel;
    value = *(u16 *)(player + 0x22);
    KEEP(value);
    value -= 0x96;
    KEEP(value);
tempo_update:
    *(u16 *)(player + 0x22) = value;
    asm goto("cmp %0, #150\n\tblo %l[update_tracks]" : : "r"(value) : "cc" : update_tracks);
    asm goto("b %l[tick]" : : : : tick);
    __builtin_unreachable();
update_tracks:
    remaining = *(u8 *)(player + 8);
    KEEP(remaining);
    track = *(u32 *)(player + 0x2C);
    KEEP(track);
update_track:
    value = *(u8 *)track;
    KEEP(value);
    argument = 0x80;
    KEEP(argument);
    asm goto("tst %0, %1\n\tbeq %l[next_update]"
             :
             : "r"(argument), "r"(value)
             : "cc"
             : next_update);
    argument = 0xF;
    KEEP(argument);
    asm goto("tst %0, %1\n\tbeq %l[next_update]"
             :
             : "r"(argument), "r"(value)
             : "cc"
             : next_update);
    saved_count = remaining;
    asm volatile("" : "+h"(saved_count));
    COPY(value, player);
    COPY(argument, track);
    CALL(func_0805C578);
    channel = *(u32 *)(track + 0x20);
    KEEP(channel);
    asm goto("cmp %0, #0\n\tbeq %l[track_updated]" : : "r"(channel) : "cc" : track_updated);
update_channel:
    argument = *(u8 *)channel;
    KEEP(argument);
    value = 0xC7;
    KEEP(value);
    asm goto("tst %0, %1\n\tbne %l[channel_active]"
             :
             : "r"(value), "r"(argument)
             : "cc"
             : channel_active);
    COPY(value, channel);
    CALL(func_0805BFF4);
    goto next_update_channel;
channel_active:
    value = *(u8 *)(channel + 1);
    KEEP(value);
    count = 7;
    KEEP(count);
    count &= value;
    KEEP(count);
    callback = *(u8 *)track;
    KEEP(callback);
    value = 3;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[update_pitch]"
             :
             : "r"(value), "r"(callback)
             : "cc"
             : update_pitch);
    CALL(func_0805B8B8);
    asm goto("cmp %0, #0\n\tbeq %l[update_pitch]" : : "r"(count) : "cc" : update_pitch);
    value = *(u8 *)(channel + 0x1D);
    KEEP(value);
    argument = 1;
    KEEP(argument);
    value |= argument;
    KEEP(value);
    *(u8 *)(channel + 0x1D) = value;
update_pitch:
    callback = *(u8 *)track;
    KEEP(callback);
    value = 0xC;
    KEEP(value);
    asm goto("tst %0, %1\n\tbeq %l[next_update_channel]"
             :
             : "r"(value), "r"(callback)
             : "cc"
             : next_update_channel);
    argument = *(u8 *)(channel + 8);
    KEEP(argument);
    value = 8;
    KEEP(value);
    value = *(s8 *)(track + value);
    KEEP(value);
    asm goto("add %0, %1, %2\n\tbpl %l[pitch_ready]"
             : "=r"(remaining)
             : "r"(argument), "r"(value)
             : "cc"
             : pitch_ready);
    remaining = 0;
    KEEP(remaining);
pitch_ready:
    asm goto("cmp %0, #0\n\tbeq %l[pcm_pitch]" : : "r"(count) : "cc" : pcm_pitch);
    value = engine;
    KEEP(value);
    callback = *(u32 *)(value + 0x30);
    KEEP(callback);
    COPY(argument, remaining);
    remaining = *(u8 *)(track + 9);
    KEEP(remaining);
    COPY(value, count);
    CALL(func_0805B864);
    *(u32 *)(channel + 0x20) = value;
    value = *(u8 *)(channel + 0x1D);
    KEEP(value);
    argument = 2;
    KEEP(argument);
    value |= argument;
    KEEP(value);
    *(u8 *)(channel + 0x1D) = value;
    goto next_update_channel;
pcm_pitch:
    COPY(argument, remaining);
    remaining = *(u8 *)(track + 9);
    KEEP(remaining);
    value = *(u32 *)(channel + 0x24);
    KEEP(value);
    CALL(func_0805BB78);
    *(u32 *)(channel + 0x20) = value;
next_update_channel:
    channel = *(u32 *)(channel + 0x34);
    KEEP(channel);
    asm goto("cmp %0, #0\n\tbne %l[update_channel]" : : "r"(channel) : "cc" : update_channel);
track_updated:
    value = *(u8 *)track;
    KEEP(value);
    argument = 0xF0;
    KEEP(argument);
    value &= argument;
    KEEP(value);
    *(u8 *)track = value;
    remaining = saved_count;
    KEEP(remaining);
next_update:
    asm goto("sub %0, #1\n\tble %l[finish]" : "+r"(remaining) : : "cc" : finish);
    value = 0x50;
    KEEP(value);
    track += value;
    KEEP(track);
    asm goto("bgt %l[update_track]" : : : : update_track);
finish:
    asm volatile("ldr %0, player_literals+8" : "=r"(value));
    *(u32 *)(player + 0x34) = value;
    asm volatile("pop {r0, r1, r2, r3, r4, r5, r6, r7}\n\t"
                 "mov r8, r0\n\tmov r9, r1\n\tmov r10, r2\n\tmov r11, r3\n\tpop {r3}"
                 :
                 :
                 : "memory");
    __builtin_unreachable();
}

__attribute__((naked)) void func_0805B864(void) { asm volatile("bx r3"); }
const u16 player_padding __attribute__((section(".text"), aligned(2))) = 0;
const u32 player_literals[3]
    __attribute__((section(".text"), aligned(4))) = {0x085662F4, 0x03007FF0, 0x68736D53};
