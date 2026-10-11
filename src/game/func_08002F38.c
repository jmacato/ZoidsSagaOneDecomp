#include "types.h"

struct ScanlineState
{
    u32 level : 4;
    u32 delay : 8;
    u32 phase : 2;
    u32 phase_reset : 2;
    u32 unused : 16;
};

extern u32 D_03004B9C[8];
extern u16 D_0200E8B0[];
extern u8 D_0200E8A9;
extern u16 *D_0200E8AC;
extern void (*D_02000B58)(void);
extern void (*D_03000204)(void);
extern u16 D_0300239C[];
extern u16 D_0200E8A4;
extern u16 D_0200E9EE;
extern u8 D_02000030;

void func_08002E94(void);
void func_08002ED8(void);
void func_0805EE78(u32);
void func_0805D270(const void *, void *, u32);
void func_08003DD8(u8);
void irq_noop(void);
void func_08003244(void);
void func_080032D0(void);
void func_080032F8(void);
void func_08002C64(void);
void func_08002CA4(void);
void func_08002CC0(void);
void func_08002CDC(void);

void func_08002F38(void)
{
    register u32 i asm("r5");
    u32 k;
    /* The later mask lifetime keeps this ordinary address in r7 during its byte load. */
    u32 sweep;
    register u32 target asm("r2");
    u16 fill;
    func_08002E94();
    func_0805EE78(1);
    D_03004B9C[4] = 0;
    D_03004B9C[5] = 0;
    {
    register u16 *pool asm("r10");
    {
        register u16 *cursor asm("r0");
        register u32 end asm("r2");
        register u32 level asm("r1");
        i = 0;
        asm("" : : "r"(i));
        end = 319;
        level = 15;
        cursor = D_0200E8B0;
        asm("" : : "r"(end), "r"(level), "r"(cursor));
        pool = cursor;
        asm("" : : "r"(pool));
        do
        {
            *cursor++ = level;
            i++;
        } while (i <= end);
    }
    i = 0;
    asm("" : : "r"(i));
    {
    register u8 *current asm("r8");
    register void (*hblank_noop)(void) asm("r9");
    {
        register u8 *low asm("r1") = &D_0200E8A9;
        asm("" : : "r"(low));
        current = low;
        asm("" : : "r"(current));
    }
    {
        register void (*low)(void) asm("r2") = irq_noop;
        asm("" : : "r"(low));
        hblank_noop = low;
        asm("" : : "r"(hblank_noop));
    }
    {
        register u32 keep asm("r6") = 0xFFFFF00F;
        register u16 *first asm("r3") = D_0200E8B0;
        register u16 *second asm("r4");
        register u32 midpoint asm("r12");
        register u32 byte_mask asm("r7");
        asm("" : : "r"(current), "r"(hblank_noop), "r"(keep), "r"(first));
        {
            register u32 stride asm("r7") = 320;
            asm("" : : "r"(stride));
            second = (u16 *)((u32)first + stride);
            asm("" : : "r"(second));
        }
        {
            register u32 value asm("r0") = 80;
            asm("" : : "r"(value));
            midpoint = value;
            asm("" : : "r"(midpoint));
        }
        byte_mask = 255;
        asm("" : : "r"(byte_mask));
        do
        {
            register u32 middle asm("r1") = midpoint;
            register u32 delay asm("r2");
            asm("" : "+r"(byte_mask) : "r"(middle));
            delay = middle - i;
            delay &= byte_mask;
            asm("" : "+r"(delay));
            delay <<= 4;
            {
                register u32 value asm("r1") = *second;
                register u32 word asm("r0") = keep;
                asm("" : "+r"(word) : "r"(value));
                *second = (word & value) | delay;
            }
            {
                register u32 value asm("r1") = *first;
                register u32 word asm("r0") = keep;
                asm("" : "+r"(word) : "r"(value));
                *first = (word & value) | delay;
            }
            first++;
            second++;
            i++;
            asm("" : : "r"(byte_mask), "r"(keep));
        } while (i <= 79);
    }
    if (i <= 159)
    {
        register u16 *base asm("r1") = D_0200E8B0;
        register u32 keep asm("r6") = 0xFFFFF00F;
        register u32 offset asm("r0") = i * 2;
        register u16 *first asm("r4");
        register u16 *second asm("r3");
        register u32 byte_mask asm("r7");
        register u32 stride asm("r2");
        asm("" : : "r"(base), "r"(keep), "r"(offset));
        first = (u16 *)(offset + (u32)base);
        asm("" : : "r"(first));
        stride = 320;
        offset += stride;
        asm("" : "+r"(offset) : "r"(stride));
        second = (u16 *)(offset + (u32)base);
        byte_mask = 255;
        asm("" : : "r"(second), "r"(byte_mask));
        do
        {
            register u32 delay asm("r2") = i - 80;
            asm("" : "+r"(byte_mask));
            delay &= byte_mask;
            asm("" : "+r"(delay));
            delay <<= 4;
            {
                register u32 value asm("r1") = *second;
                register u32 word asm("r0") = keep;
                asm("" : "+r"(word) : "r"(value));
                *second = (word & value) | delay;
            }
            {
                register u32 value asm("r1") = *first;
                register u32 word asm("r0") = keep;
                asm("" : "+r"(word) : "r"(value));
                *first = (word & value) | delay;
            }
            first++;
            second++;
            i++;
            asm("" : : "r"(byte_mask), "r"(keep));
        } while (i <= 159);
    }
    {
        register u32 zero asm("r0") = 0;
        register u8 *low asm("r3") = current;
        asm("" : : "r"(zero), "r"(low));
        *low = zero;
    }
    {
        register u16 *value asm("r7") = pool;
        register u16 **destination asm("r0") = &D_0200E8AC;
        asm("" : "+r"(destination) : "r"(value));
        *destination = value;
    }
    {
        register void (*value)(void) asm("r1") = hblank_noop;
        register void (**destination)(void) asm("r2") = &D_02000B58;
        asm("" : "+r"(destination) : "r"(value));
        *destination = value;
    }
    *(vu16 *)0x04000004 |= 16;
    *(vu16 *)0x04000200 |= 2;
    {
        register void (**address)(void) asm("r0") = &D_03000204;
        register void (*callback)(void) asm("r3") = func_08003244;
        asm("" : : "r"(address), "r"(callback));
        *address = callback;
    }
    func_0805EE78(1);
    {
        register u32 value asm("r1");
        register u32 one asm("r0");
        register u32 offset asm("r0");
        register u32 last asm("r1");
        sweep = (u32)current;
        value = *(u8 *)sweep;
        one = 1;
        asm("" : : "r"(value), "r"(one));
        target = one;
        target ^= value;
        offset = (target << 2) + target;
        asm("" : "+r"(offset));
        offset <<= 6;
        last = (u32)pool + 318;
        asm("" : "+r"(last) : "r"(offset));
        if ((*(u8 *)(offset + last) & 15) == 0)
            goto scanlines_done;
    }
    {
        register u32 one asm("r9");
        register u32 keep asm("r8");
        register u32 phase_keep asm("r6");
        {
            register u32 low asm("r0") = 1;
            asm("" : : "r"(low));
            one = low;
            asm("" : : "r"(one));
        }
        {
            register u32 low asm("r1") = 0xFFFFF00F;
            asm("" : : "r"(low));
            keep = low;
            asm("" : : "r"(keep));
        }
        {
            register u32 low asm("r3") = -49;
            asm("" : : "r"(low));
            phase_keep = low;
            asm("" : : "r"(phase_keep));
        }
scanline_frame:
        i = 0;
        asm("" : : "r"(i));
        {
            register struct ScanlineState *destination asm("r3");
            register struct ScanlineState *source asm("r4");
            register u32 offset asm("r0") = target << 2;
            register u32 other asm("r1") = target;
            register u32 flip asm("r7") = one;
            register u16 *base asm("r2");
            asm("" : : "r"(offset), "r"(other), "r"(flip));
            other ^= flip;
            offset = (offset + target) << 6;
            base = pool;
            destination = (struct ScanlineState *)(offset + (u32)base);
            asm("" : : "r"(destination), "r"(base), "r"(other));
            offset = ((other << 2) + other) << 6;
            source = (struct ScanlineState *)(offset + (u32)base);
            do
            {
                register u32 value asm("r1") = *(u16 *)source;
                u32 test;
                sweep = 0xFF0;
                asm("" : "+l"(sweep) : "r"(value) : "r0", "r2");
                test = sweep & value;
                if (test == 0)
                {
                    register u32 source_bits asm("r1") = *(u32 *)source;
                    register u32 mask asm("r0") = sweep;
                    register u32 destination_bits asm("r2");
                    asm("" : "+r"(mask) : "r"(source_bits));
                    source_bits &= mask;
                    destination_bits = *(u16 *)destination;
                    mask = keep;
                    asm("" : "+r"(mask) : "r"(source_bits), "r"(destination_bits));
                    *(u16 *)destination = (mask & destination_bits) | source_bits;
                    {
                    register u32 byte_value asm("r1") = *(u8 *)source;
                    register u32 level_mask asm("r2") = 15;
                    asm("" : "+r"(level_mask) : "r"(byte_value));
                    if ((byte_value & 15) != 0)
                    {
                        register u32 phase asm("r1");
                        if ((((u8 *)source)[1] & 0x30) == 0)
                        {
                            register u32 level asm("r1") = (source->level - 1) & level_mask;
                            register u32 byte asm("r0") = *(u8 *)destination;
                            register u32 clear asm("r2");
                            {
                                register u32 low asm("r7") = -16;
                                asm("" : "+r"(low) : "r"(level), "r"(byte));
                                clear = low;
                                asm("" : : "r"(clear));
                            }
                            *(u8 *)destination = (byte & clear) | level;
                            phase = destination->phase_reset;
                            {
                                register u32 mask asm("r0") = 3;
                                asm("" : "+r"(mask) : "r"(phase));
                                phase &= mask;
                                asm("" : "+r"(phase));
                            }
                        }
                        else
                        {
                            register u32 mask asm("r2");
                            phase = source->phase - 1;
                            asm("" : : "r"(phase));
                            mask = 3;
                            asm("" : "+r"(mask) : "r"(phase));
                            phase &= mask;
                        }
                        {
                            register u32 word asm("r0");
                            phase <<= 4;
                            asm("" : : "r"(phase));
                            word = ((u8 *)destination)[1];
                            asm("" : : "r"(word));
                            ((u8 *)destination)[1] = (word & phase_keep) | phase;
                        }
                    }
                    }
                }
                else
                {
                    register u32 word asm("r1") = *(u32 *)source >> 4;
                    register u32 old asm("r2");
                    register u32 mask asm("r0");
                    asm("" : "+r"(word));
                    word = ((u8)word - 1) & 255;
                    word <<= 4;
                    old = *(u16 *)destination;
                    mask = keep;
                    asm("" : "+r"(mask) : "r"(word), "r"(old));
                    *(u16 *)destination = (mask & old) | word;
                }
                destination = (struct ScanlineState *)((u8 *)destination + 2);
                source = (struct ScanlineState *)((u8 *)source + 2);
                i++;
            } while (i <= 159);
        }
        {
            register void (**address)(void) asm("r0") = &D_03000204;
            register void (*callback)(void) asm("r3") = func_080032D0;
            asm("" : : "r"(address), "r"(callback));
            *address = callback;
        }
        func_0805EE78(1);
        {
            register u32 value asm("r0") = D_0200E8A9;
            register u32 offset asm("r0");
            register u32 last asm("r1");
            asm("" : : "r"(value));
            target = one ^ value;
            offset = (target << 2) + target;
            asm("" : "+r"(offset));
            offset <<= 6;
            last = (u32)&D_0200E9EE;
            asm("" : : "r"(offset), "r"(last));
            if ((*(u8 *)(offset + last) & 15) != 0)
                goto scanline_frame;
        }
    }
scanlines_done:
    {
    u32 updates = (u32)&D_03000204;
    *(void (**)(void))updates = func_080032F8;
    func_0805EE78(1);
    *(vu16 *)0x04000200 &= 0xFFFD;
    {
        register u16 *address asm("r1") = &fill;
        register u32 value asm("r7") = 256;
        register u32 copy asm("r0");
        asm("" : : "r"(address), "r"(value));
        copy = value;
        asm("" : : "r"(copy));
        *address = copy;
    }
    func_0805D270(&fill, D_0300239C, 0x01000400);
    func_08002ED8();
    D_03004B9C[0] = 0xFFF80000;
    D_03004B9C[1] = 0xFFDC0000;
    D_0200E8A4 = 0;
    *(void (**)(void))updates = func_08002C64;
    func_0805EE78(1);
    k = 0;
    {
        register u32 stream asm("r7") = updates;
        register void (*callback)(void) asm("r5") = func_08002CA4;
        asm("" : : "r"(stream), "r"(callback));
        do
        {
            D_0200E8A4++;
            *(void (**)(void))stream = callback;
            func_0805EE78(1);
            k++;
        } while (k <= 15);
    }
    }
    D_0200E8A4 = 0;
    for (k = 0; k <= 15; k++)
    {
        D_0200E8A4++;
        D_03000204 = func_08002CC0;
        func_0805EE78(1);
    }
    D_03000204 = func_08002CDC;
    func_0805EE78(1);
    func_08003DD8(D_02000030);
    }
    }
}
