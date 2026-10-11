#include "types.h"

struct MusicPlayerInfo
{
    u32 song_header;
    u32 status;
    u8 pad_8[3];
    u8 unk_B;
    u8 pad_C[0xC];
    u32 mem_acc_area;
};

struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    void *track;
    u8 unk_8;
    u8 pad_9;
    u16 unk_A;
};

struct Song
{
    u32 header;
    u16 ms;
    u16 me;
};

extern const struct MusicPlayer D_08567594[];
extern const struct Song D_085675C4[];

extern u8 D_00000004[];
extern u8 D_03007228[];
extern u8 D_03006600[];
extern u8 D_03007010[];
extern u8 D_030071D0[];

void func_0805B074(void);
void func_0805D270(const void *, void *, u32);
void func_0805C01C(void *);
void func_0805BED8(void *);
void func_0805C18C(u32);
void func_0805C314(struct MusicPlayerInfo *, void *, u8);

void func_0805BC1C(void)
{
    s32 i;

    func_0805D270((void *)((s32)func_0805B074 & ~1), D_03007228, 0x040000E0);
    func_0805C01C(D_03006600);
    func_0805BED8(D_03007010);
    func_0805C18C(0x0099E800);
    for (i = 0; i < (u16)(u32)D_00000004; i++)
    {
        struct MusicPlayerInfo *info = D_08567594[i].info;

        func_0805C314(info, D_08567594[i].track, D_08567594[i].unk_8);
        info->unk_B = D_08567594[i].unk_A;
        info->mem_acc_area = (u32)D_030071D0;
    }
}
