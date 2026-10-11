#include "types.h"

struct TaskState
{
    u32 flags;
    s16 state;
    u8 pad_6[2];
    u32 message;
    vu32 data;
    u32 size;
    u8 pad_14[4];
    u32 busy;
    u32 result;
    u32 mode;
    u8 pad_24[0x64];
};

struct BattleSelection
{
    u8 pad_0[0x21F1];
    u8 count;
    u8 pad_21F2[2];
    struct
    {
        u8 flags;
        u8 selector;
        u8 pad_2[2];
    } units[6];
};

extern u8 D_02000030;
extern struct TaskState D_02000034[];
extern vu16 D_03001F56[10];
extern u32 D_020001D4;
extern u32 D_020001E4;
extern u32 D_020001EC;
extern u8 D_02010D74[];
extern u8 D_020139C0[];
extern struct BattleSelection D_0200EB84;
extern struct BattleSelection D_020117D0;

u32 func_08034A78(u32);
void func_0805D270(const void *, void *, u32);
void func_0805EE78(u32);

void func_0803520C(void)
{
    register u8 *current asm("r0") = &D_02000030;
    register u32 selected asm("r1");
    register u32 offset asm("r0");
    register struct TaskState *base asm("r1");
    register struct TaskState *states asm("r10");
    register struct TaskState *task asm("r5");
    u32 next_state;
    register u32 next_value asm("r0");
    u32 length;
    u32 index;

    selected = *current;
    asm("" : : "r"(selected));
    offset = selected * sizeof(struct TaskState);
    base = D_02000034;
    asm("" : : "r"(offset), "r"(base));
    task = (struct TaskState *)(offset + (u32)base);
    states = base;
    asm("" : "+r"(states) : "r"(task));
    for (;;)
    {
        /* Preserve the signed ROM decision tree and its shared state stores. */
        register s32 state asm("r1") = task->state;
        register s32 limit asm("r2") = 5100;

        asm("" : : "r"(state), "r"(limit));
        if (state == limit)
            goto state_5100;
        if (state > limit)
            goto dispatch_upper;
        limit = 1100;
        asm("" : : "r"(limit));
        if (state == limit)
            goto state_1100;
        if (state > limit)
            goto dispatch_middle;
        if (state == 0)
            goto state_0;
        if (state == 1000)
            goto state_1000;
        goto yield;
    dispatch_middle:
        if (state == 3000)
            goto state_3000;
        if (state > 3000)
            goto dispatch_5000;
        if (state == 2000)
            goto state_2000;
        goto yield;
    dispatch_5000:
        if (state == 5000)
            goto state_5000;
        goto yield;
    dispatch_upper:
        limit = 9000;
        asm("" : : "r"(limit));
        if (state == limit)
            goto state_9000;
        if (state > limit)
            goto dispatch_9500;
        if (state == 7000)
            goto state_7000;
        if (state > 7000)
            goto dispatch_8000;
        if (state == 6000)
            goto state_6000;
        goto yield;
    dispatch_8000:
        if (state == 8000)
            goto state_8000;
        goto yield;
    dispatch_9500:
        limit = 9500;
        asm("" : : "r"(limit));
        if (state == limit)
            goto state_9500;
        goto yield;
    state_0:
    {
        {
            register u32 command asm("r0") = 1;
            register u32 *field asm("r1") = &D_020001D4;

            asm("" : : "r"(command), "r"(field));
            *field = command;
        }
        {
            register u32 mode asm("r0") = 0xC003;
            register u32 *destination asm("r2") = &D_020001EC;

            asm("" : : "r"(mode), "r"(destination));
            *destination = mode;
        }
        next_value = 1000;
        goto set_value;
    }
    state_1000:
    {
        register const u32 *reply asm("r1") = &D_020001E4;

        register u32 response asm("r0") = *reply;

        asm("" : : "r"(reply), "r"(response));
        switch (response)
        {
        case 5:
        case 0xFC:
        case 0xFE:
        case 0xFF:
            goto failed;
        case 4:
            next_state = limit;
            goto set_state;
        }
        goto yield;
    }
    state_1100:
        if (task->message == 1)
        {
            register vu16 *selected asm("r1") = D_03001F56;
            register u32 *data_field asm("r0");
            register u32 *size_field asm("r1");

            asm("" : "+r"(selected));
            selected[0] = task->data;
            task->result = task->data;
            {
                register u32 command asm("r0") = 2;
                register u32 *field asm("r2") = &D_020001D4;

                asm("" : : "r"(command), "r"(field));
                *field = command;
            }
            data_field = (u32 *)((u32)states + 0x1A4);
            asm("" : "+r"(data_field));
            *data_field = (u32)selected;
            size_field = (u32 *)((u32)states + 0x1A8);
            asm("" : "+r"(size_field));
            *size_field = 20;
            {
                register u32 mode asm("r0") = 0xC003;
                register u32 *field asm("r1") = &D_020001EC;

                asm("" : : "r"(mode), "r"(field));
                *field = mode;
            }
            next_value = 2000;
            goto set_value;
        }
        else
        {
            register u32 *data_field asm("r1");

            {
                register u32 command asm("r0") = 3;
                register u32 *field asm("r2") = &D_020001D4;

                asm("" : : "r"(command), "r"(field));
                *field = command;
            }
            data_field = (u32 *)((u32)states + 0x1A4);
            asm("" : "+r"(data_field));
            *data_field = (u32)D_03001F56;
            {
                register u32 mode asm("r0") = 0xC003;
                register u32 *field asm("r1") = &D_020001EC;

                asm("" : : "r"(mode), "r"(field));
                *field = mode;
            }
            next_value = 3000;
            goto set_value;
        }
    state_2000:
    {
        register const u32 *reply asm("r2") = &D_020001E4;

        asm("" : : "r"(reply));
        if (*reply == 3)
        {
            if (D_03001F56[0] == 0)
            {
                next_value = 5000;
                asm volatile("" : "+r"(next_value));
                goto set_value;
            }
            else
            {
                next_value = 9000;
                asm volatile("" : "+r"(next_value));
                goto set_value;
            }
        }
        goto yield;
    }
    state_3000:
    {
        register const u32 *reply asm("r1") = &D_020001E4;

        asm("" : : "r"(reply));
        if (*reply == 3)
        {
            task->result = D_03001F56[0];
            if (D_03001F56[0] == 0)
            {
                next_state = 5000;
            set_state:
            {
                register u32 state_value asm("r2") = next_state;

                asm("" : : "r"(state_value));
                task->state = state_value;
            }
                goto yield;
            }
            else
            {
                next_value = 9000;
                asm volatile("" : "+r"(next_value));
                goto set_value;
            }
        }
        goto yield;
    }
    state_5000:
    {
        register u32 *size_field asm("r1");

        {
            register u32 command asm("r0") = 5;
            register u32 *field asm("r1") = &D_020001D4;

            asm("" : : "r"(command), "r"(field));
            *field = command;
        }
        size_field = (u32 *)((u32)states + 0x1A8);
        asm("" : "+r"(size_field));
        *size_field = 0xFD08;
        {
            register u32 mode asm("r0") = 0xC003;
            register u32 *field asm("r2") = &D_020001EC;

            asm("" : : "r"(mode), "r"(field));
            *field = mode;
        }
        next_value = 5100;
        asm("" : : "r"(next_value));
        task->state = next_value;
    }
        /* Process the reply in the same update as state 5000. */
    state_5100:
    {
        register const u32 *reply asm("r1") = &D_020001E4;

        register u32 response asm("r0") = *reply;

        asm("" : : "r"(reply), "r"(response));
        switch (response)
        {
        case 5:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        failed:
            next_state = 9500;
            goto set_state;
        case 3:
            next_value = 6000;
            goto set_value;
        }
        goto yield;
    }
    state_6000:
    {
        register const u8 *buffer asm("r6") = D_02010D74;
        register u32 input asm("r0");
        register u32 aligned_size asm("r1");

        asm("" : "+r"(buffer));
        input = 0x1C;
        length = input;
        asm("" : "+m"(length) : "r"(input));
        aligned_size = func_08034A78(input);
        asm("" : "+r"(aligned_size));
        if (task->message == 1)
        {
            register u32 *data_field asm("r0");
            register u32 *size_field asm("r0");

            {
                register u32 command asm("r0") = 2;
                register u32 *field asm("r2") = &D_020001D4;

                asm("" : : "r"(command), "r"(field));
                *field = command;
            }
            data_field = (u32 *)((u32)states + 0x1A4);
            asm("" : "+r"(data_field));
            *data_field = (u32)buffer;
            size_field = (u32 *)((u32)states + 0x1A8);
            asm("" : "+r"(size_field));
            *size_field = aligned_size;
            {
                register u32 mode asm("r0") = 0xC003;
                register u32 *field asm("r1") = &D_020001EC;

                asm("" : : "r"(mode), "r"(field));
                *field = mode;
            }
            task->state = 7000;
        }
        else
        {
            register u32 *data_field asm("r1");

            {
                register u32 command asm("r0") = 3;
                register u32 *field asm("r2") = &D_020001D4;

                asm("" : : "r"(command), "r"(field));
                *field = command;
            }
            data_field = (u32 *)((u32)states + 0x1A4);
            asm("" : "+r"(data_field));
            *data_field = (u32)D_020139C0;
            {
                register u32 mode asm("r0") = 0xC003;
                register u32 *field asm("r1") = &D_020001EC;

                asm("" : : "r"(mode), "r"(field));
                *field = mode;
            }
            next_value = 8000;
            goto set_value;
        }
        goto yield;
    }
    state_7000:
    {
        register const u32 *reply asm("r1") = &D_020001E4;

        asm("" : : "r"(reply));
        if (*reply == 3)
        {
            next_state = limit;
            goto set_state;
        }
        goto yield;
    }
    state_8000:
    {
        register const u32 *reply asm("r2") = &D_020001E4;

        asm("" : : "r"(reply));
        if (*reply == 3)
        {
            register u32 count asm("r0") = length;

            asm("" : : "r"(count));
            func_0805D270(D_020139C0, D_02010D74, count >> 1);
            {
                register u8 *destination asm("r2");
                u32 flags_offset;
                register u32 zero asm("r6");
                register u32 mask asm("r3");

                index = 0;
                destination = (u8 *)&D_0200EB84;
                flags_offset = 0x21F4;
                zero = 0;
                mask = 0xFF;
                asm("" : "+r"(destination), "+l"(flags_offset), "+l"(index) : "r"(zero), "r"(mask));
                do
                {
                    register u32 partial asm("r1") = index * 4 + (u32)destination;
                    register u32 address asm("r0");
                    register u32 selector_offset asm("r0");
                    register u32 bits asm("r0");

                    asm("" : "+r"(partial));
                    address = partial + flags_offset;
                    *(u8 *)address = zero;
                    selector_offset = 0x21F5;
                    partial += selector_offset;
                    asm("" : : "r"(selector_offset), "r"(partial));
                    bits = *(u8 *)partial;
                    bits |= mask;
                    *(u8 *)partial = bits;
                    index = (u8)(index + 1);
                } while (index <= 5);
            }
            {
                register u8 *source asm("r0");
                register u32 count_offset asm("r2");
                register u8 *count_field asm("r1");
                register u32 entries asm("r2");

                index = 0;
                source = (u8 *)&D_020117D0;
                count_offset = 0x21F1;
                asm("" : : "r"(source), "r"(count_offset));
                count_field = source + count_offset;
                entries = *count_field;
                asm("" : : "r"(count_field), "r"(entries));
                if (index < entries)
                {
                    register u8 *destination asm("r2") = (u8 *)&D_0200EB84;
                    register u8 *destination_base asm("r12");
                    register u8 *source_base asm("r9");
                    u32 selector_offset;
                    register u32 flags_offset asm("r6");
                    register u8 *count_base asm("r8");

                    destination_base = destination;
                    source_base = source;
                    selector_offset = 0x21F5;
                    flags_offset = 0x21F4;
                    count_base = count_field;
                    asm(""
                        : "+l"(selector_offset), "+r"(flags_offset), "+r"(destination_base),
                          "+r"(source_base)
                        : "r"(count_base), "r"(destination));
                    do
                    {
                        register u32 source_offset asm("r0") = index * 4 + (u32)source_base;
                        register u8 *selector asm("r2");
                        register u32 target_offset asm("r1");
                        register u32 flags asm("r3");
                        register u32 address asm("r0");

                        asm("" : "+r"(source_offset));
                        selector = (u8 *)(source_offset + selector_offset);
                        target_offset = *selector * 4 + (u32)destination_base;
                        flags = 0;
                        source_offset += flags_offset;
                        asm(""
                            : "+r"(target_offset)
                            : "r"(selector), "r"(flags), "r"(source_offset));
                        if (*(u8 *)source_offset == 0)
                            flags = 1;
                        address = target_offset + flags_offset;
                        *(u8 *)address = flags;
                        address = *selector * 4 + (u32)destination_base;
                        address += selector_offset;
                        *(u8 *)address = 1;
                        index = (u8)(index + 1);
                    } while (index < *count_base);
                }
            }
            {
                register u8 *destination asm("r1") = (u8 *)&D_0200EB84;
                register u32 count_offset asm("r2") = 0x21F1;
                register u8 *field asm("r0") = destination + count_offset;

                asm("" : "+r"(field) : "r"(destination), "r"(count_offset));
                *field = 0;
            }
            next_value = 9000;
            asm volatile("" : "+r"(next_value));
            goto set_value;
        }
        goto yield;
    }
    state_9000:
        task->busy = 1;
        next_value = 9010;
        goto set_value;
    state_9500:
    {
        register const u32 *reply asm("r1") = &D_020001E4;

        asm("" : : "r"(reply));
        task->busy = *reply;
        next_value = 9510;
    set_value:
        task->state = next_value;
        goto yield;
    }
    yield:
        func_0805EE78(1);
    }
}
