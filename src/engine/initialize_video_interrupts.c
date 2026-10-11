#include "types.h"

extern const u16 *display_configurations[];
void apply_display_config(const u16 *config);

void initialize_video_interrupts(void)
{
    *(volatile u16 *)0x04000200 = 0x2001;
    *(volatile u16 *)0x04000004 = 8;
    *(volatile u16 *)0x04000208 = 1;
    apply_display_config(display_configurations[6]);
    *(volatile u16 *)0x05000000 = 0x7FFF;
}
