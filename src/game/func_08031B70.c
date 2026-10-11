#include "types.h"

struct Effect
{
    void *src1;
    void *dst1;
    u16 size1;
    u8 pad_A[2];
    void *src2;
    void *dst2;
    u16 size2;
    u8 pad_16[2];
    u32 anim;
    u32 frames;
    u32 x;
    u32 y;
    u16 palette;
    u16 priority;
};

struct Obj
{
    u8 pad_0[6];
    u16 tile;
    u32 x;
    u32 y;
    u8 pad_10[0xC];
    u16 priority;
    u8 pad_1E[0x6A];
};

struct Template
{
    u8 pad_0[0x14];
    u32 anim;
    u32 frames;
    u8 pad_1C[0x6C];
};

extern const struct Effect D_0866B454[];
extern const struct Template D_0866B3CC;
extern struct Obj D_03004BBC[];

void func_0805D270(const void *, void *, u32);
void func_0805ED60(void *, const void *, u32);
void func_08000CEC(u16, struct Template *, s32);
void func_08001834(u16 *, u16);

void func_08031B70(u16 kind, u16 obj, u16 mode)
{
    struct Template template;

    if (mode == 0)
    {
        func_0805D270(D_0866B454[kind].src1, D_0866B454[kind].dst1, D_0866B454[kind].size1 >> 1);
        func_0805D270(D_0866B454[kind].src2, D_0866B454[kind].dst2, D_0866B454[kind].size2 >> 1);
    }
    else if (mode == 2)
    {
        func_0805D270(D_0866B454[kind].src1, D_0866B454[kind].dst1, D_0866B454[kind].size1 >> 1);
    }
    func_0805ED60(&template, &D_0866B3CC, sizeof(template));
    template.anim = D_0866B454[kind].anim;
    template.frames = D_0866B454[kind].frames;
    func_08000CEC(obj, &template, 0);
    D_03004BBC[obj].x = D_0866B454[kind].x;
    D_03004BBC[obj].y = D_0866B454[kind].y;
    D_03004BBC[obj].priority = D_0866B454[kind].priority;
    func_08001834(&D_03004BBC[obj].tile, D_0866B454[kind].palette);
}
