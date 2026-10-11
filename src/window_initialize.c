#define window_initialize window_initialize_decl
#include "text.h"
#undef window_initialize

int window_initialize(u32 window_arg, u32 style_arg, u32 x_arg, u32 y_arg,
                      u32 width_arg, u32 height_arg, u32 flags_arg)
{
    u8 window;
    register u32 style_register asm("r9");
    register u32 y_register asm("r10");
    register u32 width_register asm("r6");
    register u32 height_register asm("r5");
    register u32 raw_width asm("r4");
    register u32 raw_flags asm("r6");
    register u32 saved_flags asm("r8");
    struct { u32 x, width, flags, pad; int reopened; } saved;
    u32 offset;
    TextWindow *current;

    asm("" : "=r"(raw_width), "=r"(height_register), "=r"(raw_flags)
        : "0"(width_arg), "1"(height_arg), "2"(flags_arg));
    saved_flags = raw_flags;
    asm("" : : "r"(saved_flags));
    window = window_arg;
    style_register = (u8)style_arg;
    asm("" : : "r"(style_register));
    saved.x = (u8)x_arg;
    asm("" : : "m"(saved.x));
    y_register = (u8)y_arg;
    asm("" : : "r"(y_register));
    width_register = (u8)raw_width;
    saved.width = width_register;
    asm("" : : "r"(width_register), "m"(saved.width));
    height_register = (u8)height_register;
    asm("" : : "r"(height_register));
    {
        register u32 raw asm("r0") = saved_flags;
        register u32 byte asm("r1");
        asm("" : "+r"(raw));
        byte = (u8)raw;
        asm("" : : "r"(byte));
        saved.flags = byte;
    }
    asm("" : : "m"(saved.flags));
    {
        register int value asm("r2") = 0;
        asm("" : : "r"(value));
        saved.reopened = value;
    }
    offset = window * sizeof(TextWindow);
    asm("" : "+h"(offset));
    current = (TextWindow *)((u32)text_windows + offset);

    if (current->active)
    {
        register int value asm("r2") = 1;
        asm("" : : "r"(value));
        saved.reopened = value;
        window_close(window);
    }
    current->id = window;
    current->x = *(u8 *)&saved.x;
    {
        register u32 value asm("r2") = y_register;
        asm("" : : "r"(value));
        current->y = value;
    }
    current->width = width_register;
    current->height = height_register;
    current->unknown06 = 0;
    {
        register u32 mask asm("r0") = 0xF;
        register u32 style_low asm("r6") = style_register;
        register u32 palette asm("r0");
        asm("" : : "r"(mask), "r"(style_low));
        mask &= style_low;
        current->style = mask;
        palette = style_low >> 4;
        asm("" : : "r"(palette));
        current->palette = palette;
    }
    current->active = 1;
    current->flags = *(u8 *)&saved.flags;
    current->unknown0d = 0;
    current->unknown0f = 0;
    switch (current->style)
    {
    case 1:
        current->columns = saved.width - 4;
        {
            register WindowCallback *address asm("r0") = (WindowCallback *)((u32)text_windows + 0x10 + offset);
            register WindowCallback callback asm("r4");
            asm("" : "+r"(address));
            callback = window_render_callback;
            asm("" : : "r"(callback), "r"(address));
            *address = callback;
        }
        dispatch_window_callback(window, 1, 0, 0);
        break;
    case 0:
    case 4:
    case 8:
        {
            register u32 base asm("r1") = (u32)text_windows;
            register u32 row_offset asm("r2");
            register TextWindow *row asm("r3");
            register WindowCallback callback asm("r4");
            asm("" : "+r"(base));
            row_offset = window * sizeof(TextWindow);
            row = (TextWindow *)(row_offset + base);
            row->columns = row->width - 2;
            base += 0x10;
            row_offset += base;
            asm("" : "+r"(row_offset));
            callback = window_render_callback;
            asm("" : : "r"(callback));
            *(WindowCallback *)row_offset = callback;
        }
        dispatch_window_callback(window, 1, 0, 0);
        break;
    }
    return saved.reopened;
}
