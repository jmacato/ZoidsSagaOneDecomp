#include "types.h"
#include "engine/bios.h"
#include "graphics/background.h"

extern vu8 D_03000200;
extern u8 D_03001F55;
extern u32 D_03001F4C;
extern u8 D_03001EEC[];
extern u8 D_03001ED4[];
extern u8 shadow_oam[];

void update_sprites_and_build_oam(void);
void process_transfers(void);
void func_08004B38(void);
void func_08004B8C(void);
u32 func_080062E8(u8 *dest);
void func_080063D0(const void *data);
void func_08006284(void);

void wait_for_frame_updates(u16 frames)
{
    u16 i;

    for (i = 0; i < frames; i++)
    {
        update_sprites_and_build_oam();
        process_transfers();
        D_03000200 = 1;
    loop:
        if (D_03000200 != 0)
            goto loop;
    }
    switch (D_03001F55)
    {
    case 1:
        func_08004B38();
        D_03001F55 = 2;
    case 2:
        D_03001F4C = func_080062E8(D_03001EEC);
        func_080063D0(D_03001ED4);
        func_08006284();
        break;
    case 3:
        func_08004B8C();
        D_03001F55 = 0;
        break;
    case 0:
    default:
        break;
    }
    if (D_03001F55 != 0)
    {
        bios_cpu_set(shadow_oam, (void *)0x07000000, 0x04000100);
        if (background_update != 0)
        {
            background_update--;
            bios_cpu_set(background_tiles, (void *)0x06000000, 0x04000A00);
        }
        else
            bios_cpu_set(background_tiles, (void *)0x06000000, 0x04000400);
    }
}
