#include "types.h"

extern u16 D_03006550[];
extern u16 D_030064B0[];
extern void (*D_03007220)(const u8 *, u8 *, u32);
extern u32 (*D_03007224)(const u8 *, u8 *, u32);

void func_0805D0C8(const u8 *, u8 *, u32);
void copy_sram_bytes(const u8 *, u8 *, u32);
u32 func_0805D148(const u8 *, u8 *, u32);

void region_0805D194(void)
{
    u16 *src;
    u16 *dst;
    u16 size;

    src = (u16 *)func_0805D0C8;
    src = (u16 *)((s32)src ^ 1);
    dst = D_03006550;
    size = ((s32)copy_sram_bytes - (s32)func_0805D0C8) >> 1;
    while (size != 0)
    {
        *dst++ = *src++;
        size--;
    }
    D_03007220 = (void (*)(const u8 *, u8 *, u32))((s32)D_03006550 + 1);

    src = (u16 *)func_0805D148;
    src = (u16 *)((s32)src ^ 1);
    dst = D_030064B0;
    size = ((s32)region_0805D194 - (s32)func_0805D148) >> 1;
    while (size != 0)
    {
        *dst++ = *src++;
        size--;
    }
    D_03007224 = (u32 (*)(const u8 *, u8 *, u32))((s32)D_030064B0 + 1);

    *(vu16 *)0x04000204 = (*(vu16 *)0x04000204 & ~3) | 3;
}
