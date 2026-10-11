#include "types.h"

extern const u8 *D_020060A8[];
extern u16 *D_020060E8[];
extern u16 D_02006128[];
extern u16 D_02006148[];
extern u16 D_02006168;

void func_0805D26C(const void *, void *, u32);
void func_0805D288(const void *, void *);
void func_0805D28C(const void *, void *);
void func_0805D294(const void *, void *);
void func_0805D298(const void *, void *);
void func_0805D284(const void *, void *);
void func_0805D27C(const void *, void *);
void func_0805D278(const void *, void *);
void func_0805D274(const void *, void *);

void process_transfers(void)
{
    u32 i = 0;
    register u16 *count asm("r1");
    register const u8 *src asm("r3");
    u16 *dst;
    u16 *sizes;
    register u32 next asm("r12");
    u16 command;
    u32 n;
    u16 k;
    register u32 hi asm("r6");

    while (i < ({
        register u16 *address asm("r0") = &D_02006168;
        asm("" : : "r"(address));
        count = address;
        asm("" : : "r"(count));
        *count;
    }))
    {
        register u32 offset asm("r1");
        register u32 address asm("r0");
        register u32 mode asm("r0");
        register u32 size_offset asm("r2");
        address = (u32)D_020060A8;
        asm("" : : "r"(address));
        offset = i << 2;
        asm("" : : "r"(offset));
        address = offset + address;
        asm("" : : "r"(address));
        src = *(const u8 **)address;
        asm("" : : "r"(src));
        address = (u32)D_020060E8;
        asm("" : : "r"(address));
        offset += address;
        asm("" : : "r"(offset));
        dst = *(u16 **)offset;
        asm("" : : "r"(dst));
        offset = i << 1;
        asm("" : : "r"(offset));
        address = (u32)D_02006148;
        asm("" : : "r"(address));
        address = offset + address;
        asm("" : : "r"(address));
        mode = *(u16 *)address;
        sizes = D_02006128;
        asm("" : : "r"(sizes), "r"(mode));
        size_offset = offset;
        asm("" : : "r"(size_offset));
        offset = i + 1;
        asm("" : : "r"(offset));
        next = offset;
        asm("" : : "r"(next));
        switch (mode)
        {
        case 0:
            {
                register u16 *size asm("r0") = (u16 *)(size_offset + (u32)sizes);
                asm("" : : "r"(size));
                func_0805D26C(src, dst, *size >> 2);
            }
            goto bios_done;
        case 1:
            func_0805D288(src, dst);
            goto bios_done;
        case 2:
            func_0805D28C(src, dst);
            goto bios_done;
        case 4:
            func_0805D294(src, dst);
            goto bios_done;
        case 5:
            func_0805D298(src, dst);
            goto bios_done;
        case 6:
            func_0805D284(src, dst);
            goto bios_done;
        case 8:
            func_0805D27C(src, dst);
            goto bios_done;
        case 7:
            func_0805D278(src, dst);
            goto bios_done;
        case 9:
            func_0805D274(src, dst);
            goto bios_done;
        case 3:
            goto custom_start;
        }
        goto finish_transfer;
bios_done:
        asm("" : "+l"(i));
        i++;
        next = i;
        asm("" : : "r"(next));
        goto finish_transfer;
custom_start:
        {
            register u16 first asm("r2") = *src;
            asm("" : : "r"(first));
            command = first;
        }
        asm("" : "+l"(i));
        i++;
        next = i;
        asm("" : : "r"(next));
        while (command)
        {
            {
                register u32 masked asm("r0") = command & 0xC0;
                asm("" : : "r"(masked));
                n = masked >> 6;
            }
            if (command == 1)
                n = 4;
            asm("" : "+l"(n));
            switch (n)
            {
            default:
                goto custom_done;
            case 0:
                n = command & 0x3F;
                src++;
                command = *src++;
                asm("" : "+l"(command));
                {
                    register u32 repeated asm("r0") = command + (command << 8);
                    command = (u16)repeated;
                }
                k = 0;

                for (; k < n; k += 2)
                {
                    *dst++ = command;
                }
                break;
            case 1:
                {
                    register u32 mask asm("r0") = 0xF;
                    command &= mask;
                    n = command + 1;
                }
                src++;
                command = *src++;
                k = 0;

                for (; k < n; k += 2)
                {
                    register u32 pair asm("r1");
                    hi = command;
                    {
                        register u32 increment asm("r0") = hi + 1;
                        command = (u16)increment;
                    }
                    pair = hi + (command << 8);
                    {
                        register u32 increment asm("r0") = command + 1;
                        command = (u16)increment;
                    }
                    *dst++ = pair;
                }
                break;
            case 2:
                n = command & 0x3F;
                n++;
                src++;
                k = 0;

                for (; k < n; k += 2)
                {
                    register u32 high asm("r0");
                    command = *src++;
                    high = *src << 8;
                    command |= high;
                    src++;
                    *dst++ = command;
                }
                break;
            case 3:
                n = command & 0x3F;
                src++;
                command = *src++;
                {
                    register u32 high asm("r0") = *src << 8;
                    command |= high;
                    src++;
                }
                k = 0;

                for (; k < n; k++)
                {
                    *dst++ = command;
                }
                break;
            case 4:
                src++;
                {
                    register u32 byte asm("r0") = *src;
                    hi = byte << 8;
                    src++;
                }
                n = *src++;
                k = 0;

                for (; k < n; k++)
                {
                    register u32 value asm("r0") = *src;
                    value = hi + value;
                    src++;
                    *dst++ = value;
                }
                break;
            }
custom_done:
            command = *src;
        }
finish_transfer:
        {
            register u32 value asm("r1") = next;
            register u32 shifted asm("r0");
            asm("" : : "r"(value));
            shifted = value << 16;
            asm("" : : "r"(shifted));
            i = shifted >> 16;
        }
    }
    {
        register u32 zero asm("r0") = 0;
        asm("" : : "r"(zero));
        *count = zero;
    }
}
