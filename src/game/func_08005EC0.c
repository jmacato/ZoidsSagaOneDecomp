#include "types.h"

struct TransferState
{
    u32 limit;
    u32 slot;
    u8 *buffer;
    u32 offset;
    u32 index;
    u32 progress;
    u8 active;
};

struct TransferEntry
{
    u8 *data;
    u32 size;
};

struct TransferDirectory
{
    u32 stride;
    u32 reserved[2];
    struct TransferEntry entries[1];
};

extern u32 (*D_03007220)(const u8 *, u8 *, u32);
extern u32 (*D_03007224)(const u8 *, u8 *, u32);
extern const u8 D_08666CA4[];
u32 func_0805D2A8(const u8 *, const u8 *, u32, void *);
u32 func_0805D22C(const u8 *, u8 *, u32);
s32 func_0805EE14(const u8 *, const u8 *);
void func_0805D108(const u8 *, u8 *, u32);

u32 func_08005EC0(struct TransferState *state_input, u32 mode_input, u8 **selected,
                struct TransferDirectory *directory)
{
    register struct TransferState *state asm("r5") = state_input;
    struct Frame
    {
        u32 checksum;
        u32 mode;
        u8 **selected;
        struct TransferDirectory *directory;
        u32 block_size;
        struct TransferEntry *prefix;
    } frame;
    u32 result;
    u8 *sram = (u8 *)0x0E000000;
    asm("" : "+r"(state) : "r"(selected), "r"(directory));
    frame.selected = selected;
    frame.directory = directory;
    frame.mode = (u8)mode_input;
    asm("" : : "m"(frame.mode), "m"(frame.selected), "m"(frame.directory) : "r0");
    {
        register u32 prefix asm("r0") = (u32)directory;
        asm("" : "+r"(prefix));
        prefix += 4;
        asm("" : "+r"(prefix) : "m"(frame.mode), "m"(frame.selected), "m"(frame.directory));
        frame.prefix = (struct TransferEntry *)prefix;
    }
    result = 0;
    asm("" : "+l"(result) : "r"(state), "m"(frame.prefix) : "r0", "r1", "r2", "r3", "r4", "r6");
    if (!state->active)
    {
        register void **reader asm("r8");
        register u8 *header_sram asm("r4");
        register void **comparer asm("r6");
        {
            register void **address asm("r1") = (void **)&D_03007220;
            asm("" : "+r"(address));
            reader = address;
            asm("" : "+r"(reader));
        }
        header_sram = sram;
        asm("" : "+r"(header_sram));
        comparer = (void **)&D_03007224;
        asm("" : "+r"(comparer));
        {
            u32 error;
            do
            {
                register const u8 *source asm("r0");
                register void *callback asm("r3");
                func_0805D2A8(header_sram, state->buffer, 11, *reader);
                source = state->buffer;
                callback = *comparer;
                asm("" : "+r"(source), "+r"(callback));
                error = func_0805D2A8(source, header_sram, 11, callback);
            } while (error);
        }
        if (func_0805EE14(state->buffer, D_08666CA4))
        {
            register u32 mode_word asm("r1") = frame.mode;
            asm("" : "+r"(mode_word));
            switch (mode_word)
            {
            case 0:
            {
                {
                register u32 bit asm("r0") = 0x10;
                register u32 byte asm("r1") = result;
                register u32 mask asm("r0");
                byte |= bit;
                asm("" : "+r"(byte) : "r"(bit));
                byte = (u8)byte;
                asm("" : "+r"(byte));
                mask = 0xFFFFFF00;
                asm("" : "+r"(mask) : "r"(byte));
                result &= mask;
                result |= byte;
            }
                return result;
            }
            case 1:
                while (func_0805D22C(D_08666CA4, sram, 11))
                    ;
                break;
            }
        }
        state->active = 1;
    }
    for (;;)
    {
        register u8 **selection asm("r3");
        register u8 **saved_selection asm("r4");
        register u8 *item asm("r2");
        register u32 missing_value asm("r2");
        register u32 entry_offset asm("r8");
        register u32 payload asm("r6");
        register u32 chunk asm("r10");
        register u32 attempt asm("r4");
        register u8 *payload_address asm("r9");
        register u32 byte_index asm("r3");
        register u32 checksum_index asm("r2");
        {
            register u32 offset asm("r0") = state->index;
            register u8 **base asm("r1");
            asm("" : "+r"(offset));
            offset <<= 2;
            asm("" : "+r"(offset));
            base = frame.selected;
            asm("" : "+r"(base) : "r"(offset));
            selection = (u8 **)(offset + (u32)base);
            item = *selection;
            asm("" : "+r"(selection), "+r"(item));
        }
        if (!item)
        {
            {
                register u32 bit asm("r0") = 1;
                register u32 byte asm("r1") = result;
                register u32 mask asm("r0");
                byte |= bit;
                asm("" : "+r"(byte) : "r"(bit));
                byte = (u8)byte;
                asm("" : "+r"(byte));
                mask = 0xFFFFFF00;
                asm("" : "+r"(mask) : "r"(byte));
                result &= mask;
                result |= byte;
            }
            state->progress = (u32)item;
            state->index = (u32)item;
            state->offset = (u32)item;
            state->active = (u32)item;
            return result;
        }
        {
            register struct TransferDirectory *directory asm("r1") = frame.directory;
            register u32 stride asm("r0") = directory->stride;
            register u32 slot asm("r1");
            asm("" : "+r"(stride) : "r"(directory));
            slot = state->slot;
            asm("" : "+r"(slot) : "r"(stride));
            stride *= slot;
            payload = stride + 11;
            asm("" : "+r"(payload) : "r"(stride), "r"(selection));
        }
        saved_selection = selection;
        asm("" : "+r"(saved_selection));
        {
            register struct TransferEntry *cursor asm("r3");
            register u32 offset asm("r0") = 8;
            asm("" : "+r"(offset));
            cursor = frame.prefix;
            asm("" : "+r"(cursor) : "r"(offset));
seek_entry:
            {
                register u8 *data asm("r2");
                cursor = (struct TransferEntry *)((u8 *)cursor + 8);
                data = cursor->data;
                entry_offset = offset;
                asm("" : "+r"(entry_offset) : "r"(data), "r"(cursor));
        if (!data)
        {
            missing_value = (u32)data;
            goto missing_entry;
        }
                if (data == *(u8 * volatile *)saved_selection)
                    goto found_entry;
                {
                    register u32 next asm("r1") = payload + 4;
                    register u32 size asm("r0") = cursor->size;
                    asm("" : "+r"(next), "+r"(size));
                    payload = next + size;
                }
                offset = entry_offset + 8;
                goto seek_entry;
            }
found_entry:
            ;
        }
        {
            register u32 block asm("r0") = ((struct TransferEntry *)((u8 *)frame.prefix + entry_offset))->size + 4;
            register u32 progress asm("r2");
            register u32 remaining asm("r1");
            register u32 consumed asm("r0");
            register u32 limit asm("r0");
            register u32 held_block asm("r3");
            frame.block_size = block;
            progress = state->progress;
            remaining = block + progress;
            asm("" : "+r"(remaining) : "r"(block), "r"(progress));
            consumed = state->offset;
            remaining -= consumed;
            limit = state->limit;
            asm("" : "+r"(remaining), "+r"(limit) : "r"(progress), "m"(frame.block_size));
            held_block = frame.block_size;
            asm("" : "+r"(held_block) : "r"(remaining), "r"(limit), "r"(progress));
            chunk = held_block;
            asm("" : "+r"(chunk) : "r"(held_block), "r"(remaining), "r"(limit), "r"(progress));
            if (remaining >= limit)
            {
                limit -= progress;
                asm("" : "+r"(limit) : "r"(progress));
                chunk = limit;
            }
        }
        attempt = 0;
        asm("" : "+r"(attempt));
        payload_address = sram + payload;
        asm("" : "+r"(payload_address));
retry_transfer:
        {
            u32 compared;
            register u32 next_attempt asm("r6");
            register u32 mode_word asm("r1") = frame.mode;
            asm("" : "+r"(mode_word));
            switch (mode_word)
            {
            case 0:
            {
                register void **address asm("r3") = (void **)&D_03007220;
                register u32 offset asm("r2");
                register const u8 *sram_address asm("r1");
                register const u8 *source asm("r0");
                register u8 *destination asm("r1");
                register void *callback asm("r3");
                asm("" : "+r"(address));
                offset = state->offset;
                sram_address = payload_address;
                source = (const u8 *)(offset + (u32)sram_address);
                asm("" : "+r"(source) : "r"(offset), "r"(sram_address));
                destination = state->buffer + offset;
                callback = *address;
                asm("" : "+r"(callback) : "r"(source), "r"(destination));
                func_0805D2A8(source, destination, chunk, callback);
                next_attempt = attempt + 1;
                break;
            }
            case 1:
            {
                register u32 offset asm("r0") = state->offset;
                next_attempt = attempt + 1;
                asm("" : "+r"(next_attempt) : "r"(offset));
                if (!offset && !attempt)
                {
                    register u32 copied_offset asm("r4");
                    register u32 count asm("r0");
                    asm("" : "+r"(attempt));
                    frame.checksum = attempt;
                    byte_index = 0;
                    asm("" : "+r"(byte_index));
                    copied_offset = entry_offset;
                    asm("" : "+r"(copied_offset) : : "r0");
                    count = ((struct TransferEntry *)((u8 *)frame.prefix + entry_offset))->size;
                    asm("" : "+r"(count) : "r"(byte_index));
                    if (byte_index >= count)
                        goto write_checksum;
write_value:
                    {
                        register u8 *destination asm("r1") = state->buffer + byte_index;
                        register u32 prefix asm("r0");
                        register struct TransferEntry *entry asm("r2");
                        register u32 value asm("r1");
                        register u32 sum asm("r0");
                        asm("" : "+r"(destination) : "r"(byte_index) : "r0");
                        prefix = (u32)frame.prefix;
                        entry = (struct TransferEntry *)(copied_offset + prefix);
                        asm("" : "+r"(entry) : "r"(prefix), "r"(copied_offset));
                        *destination = entry->data[byte_index];
                        value = entry->data[byte_index];
                        asm("" : "+r"(value) : "r"(entry), "r"(byte_index) : "r0");
                        sum = frame.checksum;
                        sum += value;
                        frame.checksum = sum;
                        byte_index++;
                        count = entry->size;
                        asm("" : "+r"(count) : "r"(byte_index));
                        if (byte_index < count)
                            goto write_value;
                    }
write_checksum:
                    ;
                    {
                        register u8 *checksum_bytes asm("r4");
                        checksum_index = 0;
                        asm("" : "+r"(checksum_index));
                        checksum_bytes = (u8 *)&frame.checksum;
                        asm("" : "+r"(checksum_bytes));
                        do
                        {
                            state->buffer[byte_index++] = *(u8 *)((u32)checksum_index + (u32)checksum_bytes);
                            checksum_index++;
                        } while (checksum_index <= 3);
                    }
                }
                func_0805D108(state->buffer + state->offset,
                              payload_address + state->offset, chunk);
            }
                break;
            default:
                next_attempt = attempt + 1;
                break;
            }
            {
                register u32 shifted asm("r0") = next_attempt << 24;
                asm("" : "+r"(shifted));
                attempt = shifted >> 24;
                asm("" : "+r"(attempt) : "r"(shifted));
            }
            {
                register void **address asm("r2") = (void **)&D_03007224;
                register const u8 *source asm("r0");
                register u32 offset asm("r1");
                register u8 *destination asm("r1");
                register void *callback asm("r3");
                asm("" : "+r"(address));
                source = state->buffer;
                offset = state->offset;
                source += offset;
                destination = payload_address + offset;
                callback = *address;
                asm("" : "+r"(callback) : "r"(source), "r"(destination), "r"(address));
                compared = func_0805D2A8(source, destination, chunk, callback);
            }
            if (!compared)
                goto transferred_chunk;
            if (attempt <= 2)
                goto retry_transfer;
            {
                {
                register u32 bit asm("r1") = 4;
                register u32 byte asm("r0") = result;
                register u32 mask asm("r1");
                byte |= bit;
                asm("" : "+r"(byte) : "r"(bit));
                byte = (u8)byte;
                asm("" : "+r"(byte));
                mask = 0xFFFFFF00;
                asm("" : "+r"(mask) : "r"(byte));
                result &= mask;
                result |= byte;
            }
                state->progress = 0;
            state->index = 0;
            state->offset = 0;
            state->active = 0;
            return result;
            }
        }
transferred_chunk:
        {
            register u32 transferred asm("r0") = state->offset;
            register u32 block asm("r1");
            transferred += chunk;
            state->offset = transferred;
            asm("" : "+r"(transferred) : "m"(state->offset) : "r1");
            block = frame.block_size;
            asm("" : "+r"(block) : "r"(transferred));
            if (transferred >= block)
            {
                register u32 mode_word asm("r3") = frame.mode;
                asm("" : "+r"(mode_word));
                if (mode_word == 0)
                {
                    register u32 count asm("r0");
                    register u8 *read_buffer asm("r6");
                    register u8 *read_pointer asm("r4");
                    register u32 count_limit asm("r2");
                    frame.checksum = mode_word;
                    asm("" : : "m"(frame.checksum) : "r3");
                    byte_index = 0;
                    count = ((struct TransferEntry *)((u8 *)frame.prefix + entry_offset))->size;
                    read_buffer = state->buffer;
                    asm("" : "+r"(count), "+r"(read_buffer) : "r"(byte_index));
                    if (byte_index >= count)
                        goto read_checksum;
                    read_pointer = read_buffer;
                    count_limit = count;
read_value:
                    {
                        register u32 value asm("r1") = read_pointer[byte_index];
                        register u32 sum asm("r0");
                        sum = frame.checksum;
                        sum += value;
                        frame.checksum = sum;
                        byte_index++;
                        if (byte_index < count_limit)
                            goto read_value;
                    }
read_checksum:
                    checksum_index = 0;
                    read_pointer = (u8 *)&frame.checksum;
                    asm("" : "+r"(read_pointer));
                    do
                    {
                        register u8 *source asm("r0") = read_buffer + byte_index;
                        register u8 *compared asm("r1") = (u8 *)((u32)checksum_index + (u32)read_pointer);
                        register u32 value asm("r0");
                        register u32 expected asm("r1");
                        asm("" : "+r"(source), "+r"(compared));
                        value = *source;
                        expected = *compared;
                        if (value != expected)
                        {

                register u32 bit asm("r0") = 8;
                register u32 byte asm("r1") = result;
                register u32 mask asm("r0");
                byte |= bit;
                asm("" : "+r"(byte) : "r"(bit));
                byte = (u8)byte;
                asm("" : "+r"(byte));
                mask = 0xFFFFFF00;
                result &= mask;
                result |= byte;
                                    }
                        byte_index++;
                        checksum_index++;
                    } while (checksum_index <= 3);
                    if ((s32)(result << 28) < 0)
                        goto clear_entry;
                    {
                        register u32 copied_offset asm("r4");
                        register u32 prefix asm("r1");
                        byte_index = 0;
                        copied_offset = entry_offset;
                        asm("" : "+r"(copied_offset));
                        prefix = (u32)frame.prefix;
                        count = ((struct TransferEntry *)(copied_offset + prefix))->size;
                        asm("" : "+r"(count) : "r"(prefix), "r"(copied_offset), "r"(byte_index));
                        if (byte_index >= count)
                            goto finished_copy;
copy_value:
                        {
                            register u32 prefix asm("r0") = (u32)frame.prefix;
                            register struct TransferEntry *entry asm("r2") = (struct TransferEntry *)(copied_offset + prefix);
                            register u8 *destination asm("r1");
                            register u8 *source asm("r0");
                            asm("" : "+r"(entry) : "r"(prefix), "r"(copied_offset));
                            destination = entry->data + byte_index;
                            source = *(u8 * volatile *)&state->buffer + byte_index;
                            *destination = *source;
                            byte_index++;
                            count = entry->size;
                            asm("" : "+r"(count) : "r"(byte_index));
                            if (byte_index < count)
                                goto copy_value;
                        }
                    }
                    goto finished_copy;
missing_entry:

            {
                register u32 bit asm("r0") = 2;
                register u32 byte asm("r1") = result;
                register u32 mask asm("r0");
                byte |= bit;
                asm("" : "+r"(byte) : "r"(bit));
                byte = (u8)byte;
                asm("" : "+r"(byte));
                mask = 0xFFFFFF00;
                result &= mask;
                result |= byte;
            }
            state->progress = missing_value;
            state->index = missing_value;
            state->offset = missing_value;
            state->active = missing_value;
            return result;
        clear_entry:
                    {
                        register u32 copied_offset asm("r2");
                        register u32 prefix asm("r1");
                        register u32 zero asm("r4");
                        byte_index = 0;
                        copied_offset = entry_offset;
                        asm("" : "+r"(copied_offset));
                        prefix = (u32)frame.prefix;
                        count = ((struct TransferEntry *)(copied_offset + prefix))->size;
                        asm("" : "+r"(count) : "r"(prefix), "r"(copied_offset), "r"(byte_index));
                        if (byte_index >= count)
                            goto finished_copy;
                        zero = 0;
clear_value:
                        {
                            register u32 prefix asm("r1") = (u32)frame.prefix;
                            register struct TransferEntry *entry asm("r0") = (struct TransferEntry *)(copied_offset + prefix);
                            register u8 *destination asm("r1");
                            asm("" : "+r"(entry) : "r"(prefix), "r"(copied_offset));
                            destination = entry->data + byte_index;
                            *destination = zero;
                            byte_index++;
                            count = entry->size;
                            asm("" : "+r"(count) : "r"(byte_index));
                            if (byte_index < count)
                                goto clear_value;
                        }
                    }
finished_copy:
                    ;
                }
                state->offset = 0;
                state->index++;
            }
        }
        {
            register u32 progress asm("r1") = state->progress;
            register u32 limit asm("r0");
            progress += chunk;
            state->progress = progress;
            asm("" : "+r"(progress) : "m"(state->progress) : "r0");
            limit = state->limit;
            asm("" : "+r"(limit) : "r"(progress));
            if (progress >= limit)
            {
                state->progress = 0;
                return result;
            }
        }
    }
}
