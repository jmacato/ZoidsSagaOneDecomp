#include "types.h"

#pragma GCC optimize("no-toplevel-reorder", "align-functions=2", "no-reorder-blocks")

register u8 *argument asm("r0");
register u8 *track asm("r1");
register u8 *cursor asm("r2");
register u32 value asm("r3");
register u32 scratch_link asm("ip");

void func_0805B49C(void)
{
    asm volatile("push {lr}" : : : "memory");
    cursor = *(u8 **)(track + 0x40);
    value = *cursor;
    asm("" : "+r"(value));
    asm goto("cmp %0, #0\n\tbne %l[repeat]" : : "r"(value) : "cc" : repeat);
    cursor++;
    asm("" : "+r"(cursor));
    *(u8 **)(track + 0x40) = cursor;
    asm volatile("b func_0805B44E" : : : "memory");
    __builtin_unreachable();
repeat:
    value = track[3];
    asm("" : "+r"(value));
    value++;
    asm("" : "+r"(value));
    track[3] = value;
    /* The comparison keeps 256 when the stored byte wraps from 255 to zero. */
    scratch_link = value;
    asm volatile("bl func_0805B440" : "+r"(cursor), "+r"(value) : : "memory", "cc");
    asm goto("cmp %0, %1\n\tbcs %l[finished]" : : "r"(scratch_link), "r"(value) : "cc" : finished);
    asm volatile("b func_0805B44E" : : : "memory");
    __builtin_unreachable();
finished:
    value = 0;
    asm("" : "+r"(value));
    track[3] = value;
    asm("" : "+r"(cursor) : : "memory");
    cursor += 5;
    asm("" : "+r"(cursor));
    *(u8 **)(track + 0x40) = cursor;
    asm volatile("pop {r0}\n\tbx r0" : : : "memory");
    __builtin_unreachable();
}

static const u16 repeat_padding __attribute__((used, section(".text"), aligned(2))) = 0;

/* Command helpers preserve their return address in ip, outside the C call ABI. */
#define BEGIN_COMMAND() asm volatile("mov %0, lr" : "=r"(scratch_link))
#define READ_BYTE() asm volatile("bl func_0805B440" : "+r"(cursor), "+r"(value) : : "memory", "cc")
#define END_COMMAND()                                                                              \
    do                                                                                             \
    {                                                                                              \
        asm volatile("bx %0" : : "r"(scratch_link));                                               \
        __builtin_unreachable();                                                                   \
    } while (0)
#define MARK_TRACK(mask)                                                                           \
    do                                                                                             \
    {                                                                                              \
        asm("" : : : "memory");                                                                    \
        value = track[0];                                                                          \
        asm("" : "+r"(value) : : "r2");                                                            \
        cursor = (u8 *)mask;                                                                       \
        asm("" : "+r"(cursor));                                                                    \
        value |= (u32)cursor;                                                                      \
        track[0] = value;                                                                          \
    } while (0)

void func_0805B4CC(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    track[0x1D] = value;
    END_COMMAND();
}
static const u16 command_padding_4CC __attribute__((used, section(".text"), aligned(2))) = 0;

void func_0805B4D8(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    value <<= 1;
    asm("" : "+r"(value));
    /* Keep the full computed register value while storing only its low halfword. */
    asm volatile("strh %0, [%1, #28]" : : "r"(value), "r"(argument) : "memory");
    cursor = (u8 *)(u32) * (u16 *)(argument + 0x1E);
    asm("" : "+r"(cursor));
    value *= (u32)cursor;
    value >>= 8;
    asm volatile("strh %0, [%1, #32]" : : "r"(value), "r"(argument) : "memory");
    END_COMMAND();
}

void func_0805B4EC(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    track[0xA] = value;
    MARK_TRACK(12);
    END_COMMAND();
}
static const u16 command_padding_4EC __attribute__((used, section(".text"), aligned(2))) = 0;

void func_0805B500(void)
{
    BEGIN_COMMAND();
    cursor = *(u8 **)(track + 0x40);
    value = *cursor;
    asm("" : "+r"(value));
    cursor++;
    asm("" : "+r"(cursor));
    *(u8 **)(track + 0x40) = cursor;
    asm("" : : : "memory");
    cursor = (u8 *)(value << 1);
    asm("" : "+r"(cursor));
    cursor += value;
    asm("" : "+r"(cursor));
    cursor = (u8 *)((u32)cursor << 2);
    asm("" : "+r"(cursor) : : "memory");
    value = *(u32 *)(argument + 0x30);
    asm("" : "+r"(value));
    cursor += value;
    asm("" : "+r"(cursor));
    value = *(u32 *)cursor;
    asm volatile("bl func_0805B426" : "+r"(value) : "r"(cursor) : "memory", "cc");
    *(u32 *)(track + 0x24) = value;
    value = *(u32 *)(cursor + 4);
    asm volatile("bl func_0805B426" : "+r"(value) : "r"(cursor) : "memory", "cc");
    *(u32 *)(track + 0x28) = value;
    value = *(u32 *)(cursor + 8);
    asm volatile("bl func_0805B426" : "+r"(value) : "r"(cursor) : "memory", "cc");
    *(u32 *)(track + 0x2C) = value;
    END_COMMAND();
}
static const u16 command_padding_500 __attribute__((used, section(".text"), aligned(2))) = 0;

void func_0805B530(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    track[0x12] = value;
    MARK_TRACK(3);
    END_COMMAND();
}
static const u16 command_padding_530 __attribute__((used, section(".text"), aligned(2))) = 0;

void func_0805B544(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    value -= 64;
    asm("" : "+r"(value));
    track[0x14] = value;
    MARK_TRACK(3);
    END_COMMAND();
}

void func_0805B558(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    value -= 64;
    asm("" : "+r"(value));
    track[0xE] = value;
    MARK_TRACK(12);
    END_COMMAND();
}

void func_0805B56C(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    track[0xF] = value;
    MARK_TRACK(12);
    END_COMMAND();
}
static const u16 command_padding_56C __attribute__((used, section(".text"), aligned(2))) = 0;

void func_0805B580(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    track[0x1B] = value;
    END_COMMAND();
}
static const u16 command_padding_580 __attribute__((used, section(".text"), aligned(2))) = 0;

void func_0805B58C(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    argument = (u8 *)(u32)track[0x18];
    asm goto("cmp %0, %1\n\tbeq %l[done]" : : "r"(argument), "r"(value) : "cc" : done);
    track[0x18] = value;
    MARK_TRACK(15);
done:
    END_COMMAND();
}

void func_0805B5A4(void)
{
    BEGIN_COMMAND();
    READ_BYTE();
    value -= 64;
    asm("" : "+r"(value));
    track[0xC] = value;
    MARK_TRACK(12);
    END_COMMAND();
}

void func_0805B5B8(void)
{
    BEGIN_COMMAND();
    cursor = *(u8 **)(track + 0x40);
    value = *cursor;
    asm("" : "+r"(value));
    cursor++;
    asm("" : "+r"(cursor));
    asm("ldr %0, sound_register_base" : "=r"(argument) : "r"(cursor));
    argument += value;
    asm("" : "+r"(argument));
    asm volatile("bl func_0805B442" : "+r"(cursor), "+r"(value) : : "memory", "cc");
    asm volatile("strb %0, [%1]" : : "r"(value), "r"(argument) : "memory");
    END_COMMAND();
}

static volatile u8 *const sound_register_base __attribute__((used, section(".text"), aligned(4))) =
    (volatile u8 *)0x04000060;
