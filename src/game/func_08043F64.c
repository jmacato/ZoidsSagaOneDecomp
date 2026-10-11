#include "types.h"

extern struct
{
    u8 pad_0[0xC];
    s32 offset;
    s32 scroll;
} D_03004B9C;

extern u8 D_0200E238;
extern s32 D_0200E230;
extern u8 D_0200DA71;

void func_08041EE8(s32);
u16 func_08042FA4(u8);
void func_080440F8(void);
void func_0805EE78(s32);

void func_08043F64(void)
{
    u8 frame;

    D_0200E238 = 0;
    frame = 0;
    D_0200E230 = D_03004B9C.scroll;
    func_08041EE8(1);
    for (;;)
    {
        switch (D_0200E238)
        {
        case 0:
            switch (D_0200DA71)
            {
            default:
                D_03004B9C.scroll += -0x1000;
                D_03004B9C.offset = 0;
                break;
            case 3:
                D_03004B9C.scroll += -0x4000;
                D_03004B9C.offset = 0;
                break;
            case 7:
                D_03004B9C.scroll += -0x30000;
                D_03004B9C.offset = func_08042FA4(frame) << 10;
                break;
            case 10:
            case 11:
            case 15:
            case 16:
                D_03004B9C.scroll += -0x1000;
                D_03004B9C.offset = 0;
                break;
            }
            break;
        case 0x20:
            switch (D_0200DA71)
            {
            case 3:
                D_03004B9C.scroll += 0x4000;
                D_03004B9C.offset = 0;
                break;
            case 7:
                D_03004B9C.scroll += 0x30000;
                D_03004B9C.offset = func_08042FA4(frame) << 10;
                break;
            case 10:
            case 11:
            case 15:
            case 16:
            default:
                D_03004B9C.scroll += 0x1000;
                D_03004B9C.offset = 0;
                break;
            }
            break;
        }
        func_080440F8();
        frame++;
        func_0805EE78(1);
    }
}
