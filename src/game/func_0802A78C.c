#include "types.h"

struct Save
{
    u8 pad_0[0xCD0];
    u8 slots[2];
};

extern struct Save D_02000B5C;

extern struct
{
    u16 confirmed;
    u16 choice;
} D_02007574;

void func_08026694(void);
void func_08000FD8(u8);
void func_08008B58(s32);
void func_0802A67C(u8);
void func_08026634(u8);

void func_0802A78C(void)
{
    struct Save *save;
    u8 *slot;

    func_08026694();
    save = &D_02000B5C;
    slot = &save->slots[1];
    if (*slot == 0xFF)
    {
        slot = &save->slots[0];
        if (*slot != 0xFF)
        {
            func_08000FD8(*slot);
            if (*slot == 0x19 || *slot == 0x1B)
            {
                func_08000FD8(0x19);
                func_08000FD8(0x1B);
            }
            if (D_02000B5C.slots[0] == 0x1A || D_02000B5C.slots[0] == 0x1C)
            {
                func_08000FD8(0x1A);
                func_08000FD8(0x1C);
            }
        }
        func_08008B58(0x281);
        if (D_02007574.choice <= 0x1C)
        {
            D_02000B5C.slots[1] = D_02007574.choice;
            func_0802A67C(D_02000B5C.slots[1]);
            func_08008B58(0x285);
        }
    }
    else
    {
        func_08008B58(0x283);
        if (D_02007574.choice == 0 && D_02007574.confirmed != 0)
        {
            func_08026634(*slot);
            *slot = 0xFF;
        }
    }
}
