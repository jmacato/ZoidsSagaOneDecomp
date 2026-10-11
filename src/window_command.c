#include "text.h"

void window_command(u8 window, u8 command, u8 high, u8 low)
{
    register WindowCallback callback asm("r4") =
        text_windows[window].callback;

    /* The callback dispatcher receives its target in r4. */
    asm volatile("" : : "r"(callback));
    dispatch_window_callback(window, command, high, low);
}
