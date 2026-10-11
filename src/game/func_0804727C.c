#include "types.h"

extern u8 D_086D4218[];

u8 func_080470F0(u8);

u8 func_0804727C(u8 kind)
{
    u8 base = kind * 6;
    u8 result = 0;
    u8 i;
    u8 id;

    switch (kind)
    {
    case 0:
        for (i = 0; i < 6; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    case 5:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
            result = 2;
        }
        break;
    case 7:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
            result = 1;
        }
        break;
    case 1:
        for (i = 0; i < 6; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    case 2:
        for (i = 0; i < 6; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    case 10:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
            result = 2;
        }
        break;
    case 12:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
            result = 1;
        }
        break;
    case 3:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    case 4:
        for (i = 0; i < 6; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    }
    switch (result)
    {
    case 3:
        return id;
    case 1:
        return 0xFE;
    case 2:
        return 0xFF;
    default:
        return i;
    }
}

u8 func_08047494(u8 kind)
{
    u8 base = kind * 6;
    u8 result = 0;
    u8 i;
    u8 id;

    switch (kind)
    {
    case 0:
        for (i = 0; i < 6; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    case 5:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
            result = 2;
        }
        break;
    case 7:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
            result = 1;
        }
        break;
    case 1:
        for (i = 0; i < 6; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    case 2:
        for (i = 0; i < 6; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    case 10:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
            result = 2;
        }
        break;
    case 12:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
            result = 1;
        }
        break;
    case 3:
        for (i = 0; i < 3; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    case 4:
        for (i = 0; i < 6; i++)
        {
            id = D_086D4218[i + base];
            if (func_080470F0(id))
            {
                result = 3;
                break;
            }
        }
        break;
    }
    switch (result)
    {
    case 3:
        return id;
    case 1:
        return 0xFE;
    case 2:
        return 0xFF;
    }
}
