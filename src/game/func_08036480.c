#include "types.h"

extern struct
{
    u8 pad_0[0xCDC];
    s16 field_CDC;
    s16 field_CDE;
    s16 field_CE0;
    s16 field_CE2;
    s16 field_CE4;
} D_02000B5C;

s32 func_08036480(void)
{
    s32 result = 1;

    if (D_02000B5C.field_CDC != 200)
        result = 0;
    else if (D_02000B5C.field_CE2 != 200)
        result = 0;
    else if (D_02000B5C.field_CE0 != 200)
        result = 0;
    else if (D_02000B5C.field_CDE != 200)
        result = 0;
    else if (D_02000B5C.field_CE4 != 200)
        result = 0;
    return result;
}
