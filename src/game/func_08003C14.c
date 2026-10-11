#include "types.h"

u8 func_08059380(u8);
void func_08003B7C(s32);
void func_08003BFC(void);
void func_08003948(void);

s32 func_08003C14(u8 flag)
{
    u8 result;

    if (func_08059380(0) == 1)
    {
        func_08003BFC();
        return 0;
    }
    result = func_08059380(1);
    if (result == 1)
    {
        if (flag)
            func_08003B7C(2);
        func_08003BFC();
        return 0;
    }
    if (result == 2)
    {
        if (!flag)
            goto done;
        result = 1;
    }
    else
    {
        if (!flag)
            goto done;
        result = 0;
    }
    func_08003B7C(result);
done:
    func_08003948();
    return 1;
}
