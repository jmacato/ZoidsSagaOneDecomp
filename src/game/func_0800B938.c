#include "types.h"

struct Object
{
    u8 pad_0[0x4A];
    u16 field_4A;
    u8 pad_4C[0xC];
    u16 link;
    u16 state;
    u8 pad_5C[2];
    u16 id;
    u8 pad_60[0x28];
};

extern struct Object D_03004BBC[];

s32 func_08001040(u16);
void func_08000BD8(u16, s32);
void func_080019EC(s32);
void func_0805EE78(s32);
void func_08000F88(u16);
void func_08037614(u16);

void func_0800B938(u16 index)
{
    u16 link = D_03004BBC[index].link;
    struct Object *object = &D_03004BBC[link];
    u16 id = object->id;
    u16 flag = id + 0x1E;

    if (func_08001040(flag) == 0)
    {
        func_08000BD8(link, 1);
        if (object->state == 0x115)
            func_080019EC(0x46);
        else
            func_080019EC(0x48);
        func_0805EE78(0x1E);
        func_08000F88(flag);
        func_08037614(id);
    }
    D_03004BBC[index].field_4A = 0;
}
