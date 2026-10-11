#include "types.h"

struct RewardTask {
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 flags;
    u8 pad_C[12];
    u32 busy;
    u8 pad_1C[12];
    u8 levels;
    u8 remaining;
    u8 level;
    u8 pad_2B[0x5D];
};
extern u8 D_02000030;
extern struct RewardTask D_02000034[];
struct RewardBattle {
    u16 flags, bonuses;
    u8 pad_4[0x21E4];
    u8 mode;
    u8 pad_21E9[0xB7];
    u32 experience, money;
    u8 item, part, pilot, skill;
    union { u32 amount; u8 kind; } reward;
};
struct RewardUnit { u8 pad_0[0x4A]; u8 wound; u8 pad_4B[0x281]; };
extern union { struct RewardBattle state; struct RewardUnit units[6]; } D_0200EB84;
struct RewardMember {
    u16 flags;
    u8 pad_2[6];
    u32 hp, energy;
    u8 pad_10[24];
    u32 max_hp, max_energy;
    u8 pad_30[8];
};
struct RewardSlot { u8 pad_0; u8 kind; u8 pad_2[2]; };
struct RewardSave {
    u8 pad_0[0xCD2];
    u8 level;
    u8 pad_CD3;
    u32 experience;
    u8 pad_CD8[0x54];
    struct RewardMember members[6];
    u8 pad_E7C[0x262A];
    u8 leader;
    u8 pad_34A7[0x159];
    struct RewardSlot slots[6];
};
extern struct RewardSave D_02000B5C;
extern u16 D_02007574[];
extern u16 D_02004A6C[];
extern u8 D_08675BEC[], D_08675C5C[], D_0866634C[], D_08675B68[];
extern u32 D_0866B9B4[];
void func_080019EC(u32);
void func_0803E488(u8 *, u32);
void func_08001848(u32, u32, u32);
void func_0803706C(u32);
void func_08037090(u32);
void func_0803666C(void);
void func_0803680C(void);
void func_08036F80(u32, u32);
void func_08036FAC(u32, u32);
void func_08036FD8(u32, u32);
void func_08032840(u32);
void func_080328E4(u32);
void func_08032800(u32);
s32 func_08037004(u32);
void func_08032818(u32);
void func_08003DF8(u32, void (*)(void));
void func_080360A0(void);
void func_08003E3C(u32);
void func_080368BC(void);
void func_08036960(u32);
void func_08004018(void);
void func_080364DC(void);
u8 func_08032B18(void);
void func_0803699C(u32, u32);
void func_08037A20(u32, u32);
void func_08059338(void);
void func_0805EE78(u32);
s32 func_08032A88(u8, u8);
u8 func_08035FE0(void);

#define B8(offset) ((u8 *)&D_0200EB84)[offset]
#define B16(offset) (*(u16 *)(D_0200EB84 + (offset)))
#define B32(offset) (*(u32 *)(D_0200EB84 + (offset)))
#define S8(offset) D_02000B5C[offset]
#define S16(offset) (*(u16 *)(D_02000B5C + (offset)))
#define S32(offset) (*(u32 *)(D_02000B5C + (offset)))
#define TEXT_A(index) func_0803E488(D_08675BEC, (index))
#define TEXT_B(index) func_0803E488(D_08675C5C, (index))

void func_08035778(void)
{
    struct RewardTask *task = &D_02000034[D_02000030];
    for (;;)
    {
        switch (task->state)
        {
        case 0:
            if (D_0200EB84.state.flags & 0x20)
                task->state = 11000;
            else
                switch (D_0200EB84.state.mode)
                {
                case 1: case 2:
                    func_080019EC(0x33);
                    task->state = 1000;
                    break;
                case 3:
                    task->state = 7000;
                    break;
                case 4:
                    func_080019EC(0x53);
                    task->state = 8000;
                    break;
                }
            break;
        case 1000:
        {
            register u8 *script_a asm("r5");
            register u8 *script_b asm("r8");
            register struct RewardBattle *battle asm("r6");
            register u32 *reward asm("r4");
            script_a = D_08675BEC;
            func_0803E488(script_a, 6);
            func_0803E488(script_a, 7);
            script_b = D_08675C5C;
            asm("" : : "r"(script_b));
            func_0803E488(script_b, 11);
            func_0803E488(script_a, 5);
            func_0803E488(script_a, 20);
            battle = &D_0200EB84.state;
            if (battle->bonuses & 2)
            {
                register u32 *bonus asm("r1") = &battle->money;
                asm("" : "+r"(bonus));
                *bonus *= 2;
            }
            reward = &battle->money;
            func_0803706C(*reward);
            func_0803E488(script_a, 6);
            func_0803E488(script_a, 7);
            func_08001848(*reward, 7, 1);
            func_0803E488(script_b, 10);
            func_0803E488(script_a, 5);
            func_0803E488(script_a, 20);
            func_0803666C();
            func_0803680C();
            switch (({
                register u32 offset asm("r5") = 0x22AC;
                register u8 *kind asm("r0");
                asm("" : "+r"(offset));
                kind = (u8 *)battle + offset;
                asm("" : "+r"(kind) : "r"(battle));
                *kind;
            }))
            {
            case 0: task->state = 3000; break;
            case 1: task->state = 2100; break;
            case 2: task->state = 2200; break;
            case 3: task->state = 2300; break;
            case 4: task->state = 2700; break;
            }
            if (({
                register u8 *base asm("r0") = (u8 *)&D_0200EB84;
                register u32 offset asm("r1") = 0x22AC;
                asm("" : "+r"(base), "+r"(offset));
                base[offset];
            }))
                func_080019EC(0x35);
            break;
        }
        case 2100:
        {
            register u8 *entry asm("r4") = (u8 *)&D_0200EB84;
            register u32 offset asm("r5") = 0x22A8;
            asm("" : "+r"(entry), "+r"(offset));
            entry += offset;
            func_08036F80(*entry, 1);
            TEXT_A(6); TEXT_A(7); TEXT_B(0x27);
            func_08032840(*entry);
            TEXT_B(9); TEXT_A(5); TEXT_A(20);
            task->state = 3000;
            break;
        }
        case 2200:
        {
            register u8 *entry asm("r4") = (u8 *)&D_0200EB84;
            register u32 offset asm("r0") = 0x22A9;
            asm("" : "+r"(entry), "+r"(offset));
            entry += offset;
            func_08036FAC(*entry, 1);
            TEXT_A(6); TEXT_A(7); TEXT_B(0x28);
            func_080328E4(*entry);
            TEXT_B(9); TEXT_A(5); TEXT_A(20);
            task->state = 3000;
            break;
        }
        case 2300:
        {
            register u8 *entry asm("r4") = (u8 *)&D_0200EB84;
            register u32 offset asm("r1") = 0x22AA;
            asm("" : "+r"(entry), "+r"(offset));
            entry += offset;
            func_08036FD8(*entry, 1);
            TEXT_A(6); TEXT_A(7); TEXT_B(0x29);
            D_02007574[6] = *entry;
            func_0803E488(D_0866634C, D_02007574[6]);
            TEXT_B(9); TEXT_A(5); TEXT_A(20);
            task->state = 3000;
            break;
        }
        case 2700:
            TEXT_A(6); TEXT_A(7); TEXT_B(0x2A);
            func_08032800(D_0200EB84.state.skill);
            TEXT_B(0x2B); TEXT_A(5); TEXT_A(20);
            if (func_08037004(D_0200EB84.state.skill))
            {
                TEXT_A(6); TEXT_A(7); TEXT_B(0x2C); TEXT_A(5); TEXT_A(20);
            }
            task->state = 3000;
            break;
        case 3000: case 3100:
            if (D_0200EB84.state.bonuses & 4)
                D_0200EB84.state.experience *= 2;
            func_08037090(D_0200EB84.state.experience);
            TEXT_A(6); TEXT_A(7);
            func_08001848(D_0200EB84.state.experience, 7, 1);
            TEXT_B(7); TEXT_A(5); TEXT_A(20);
            task->level = D_02000B5C.level;
            {
                register u8 *initial asm("r0") = &task->levels;
                register u8 *levels asm("r5");
                register u8 *counter asm("r4");
                asm("" : "+r"(initial));
                *initial = 0;
                asm("" : : "r"(initial));
                levels = initial;
                asm("" : "+r"(levels));
                counter = levels;
                asm("" : "+r"(counter));
check_levels:
                if (func_08035FE0() == 0)
                    goto levels_done;
                (*counter)++;
                goto check_levels;
levels_done:
                if (*levels == 0)
                    task->state = 9000;
                else
                    task->state = 4000;
            }
            break;
        case 4000:
            task->remaining = task->levels;
        case 4100:
            func_080019EC(0x34);
            TEXT_A(6); TEXT_A(7);
            func_08032818(0);
            TEXT_B(8);
            task->level++;
            func_08001848(task->level, 7, 1);
            TEXT_B(0x2E); TEXT_A(5); TEXT_A(20);
            task->remaining--;
            if (task->remaining)
                task->state = 4100;
            else
                task->state = 5000;
            break;
        case 5000:
            func_08003DF8(6, func_080360A0);
            D_02000034[6].flags = task->levels;
            task->state = 5010;
            break;
        case 5010:
            if (D_02000034[6].busy == 1)
            {
                func_08003E3C(6);
                func_080368BC();
                func_08036960(0); func_08036960(1); func_08036960(2); func_08036960(3);
                task->state = 9000;
            }
            break;
        case 7000:
            TEXT_A(6); TEXT_A(7);
            func_08032818(0);
            TEXT_B(12); TEXT_A(5); TEXT_A(20);
            task->state = 9000;
            break;
        case 8000:
            TEXT_A(6); TEXT_A(7); TEXT_B(13); TEXT_A(5);
            func_08004018();
            task->state = 8100;
            break;
        case 8100:
            if (D_02000034[9].busy == 1)
                task->state = 9000;
            break;
        case 9000:
            func_080364DC();
            if (D_0200EB84.state.mode == 3)
            {
                task->level = D_02000B5C.leader;
                if (task->level == 255)
                {
                    task->level = func_08032B18();
                    if (task->level == 255)
                    {
                        func_0803699C(0x39, 0);
                        task->level = func_08032B18();
                    }
                }
                D_02000B5C.members[task->level].hp = D_02000B5C.members[task->level].max_hp;
                D_02000B5C.members[task->level].energy = D_02000B5C.members[task->level].max_energy;
                D_02000B5C.members[task->level].flags &= 0xF7FF;
                func_08037A20(0, 1);
            }
            task->busy = 1;
            task->state = 9100;
            break;
        case 11000:
            switch (D_0200EB84.state.mode)
            {
            case 1: case 2:
                func_080019EC(0x33);
                task->state = 12000;
                break;
            case 3: case 4:
                task->state = 15000;
                break;
            default:
                task->state = 15000;
                break;
            }
            break;
        case 12000:
            D_02004A6C[0]++;
            if (D_02004A6C[0] > 9999)
                D_02004A6C[0] = 9999;
            func_08059338();
            TEXT_A(6); TEXT_A(7);
            func_0803E488(D_08675B68, 17);
            TEXT_A(5); TEXT_A(20);
            task->state = 17000;
            break;
        case 15000:
            TEXT_A(6); TEXT_A(7);
            D_02004A6C[1]++;
            if (D_02004A6C[1] > 9999)
                D_02004A6C[1] = 9999;
            func_08059338();
            func_0803E488(D_08675B68, 18);
            TEXT_A(5); TEXT_A(20);
            task->state = 17000;
            break;
        case 17100:
        case 9100:
            break;
        case 17000:
            task->busy = 1;
            task->state = 17100;
            break;
        }
        func_0805EE78(1);
    }
}

u8 func_08035FE0(void)
{
    u8 result = 0;
    register struct RewardSave *save asm("r4");
    register volatile u8 *level asm("r2");
    register u32 value asm("r0");
    asm("" : : "r"(result));
    save = &D_02000B5C;
    asm("" : "+r"(save));
    level = &save->level;
    asm("" : "+r"(level));
    value = *level;
    asm("" : "+r"(value));
    if (value <= 98)
    {
        register u32 next asm("r3") = (u8)(value + 1);
        register u32 threshold asm("r1");
        register u32 offset asm("r6");
        register u32 experience asm("r0");
        asm("" : "+r"(next));
        threshold = D_0866B9B4[*level];
        asm("" : "+r"(threshold));
        offset = 0xCD4;
        asm("" : "+r"(offset));
        experience = *(u32 *)((u8 *)save + offset);
        asm("" : "+r"(experience) : "r"(save), "r"(offset));
        if (experience >= threshold)
        {
            *level = next;
            result = 1;
        }
    }
    return result;
}

u8 func_08036028(void)
{
    u8 result = 0;
    u8 slot = 0;
    register u8 *base asm("r0") = (u8 *)&D_02000B5C;
    register u32 first asm("r1");
    register u8 *save asm("r2");
    asm("" : "+r"(base));
    first = ({
        register u32 offset asm("r2") = 0x3601;
        register u8 *entry asm("r1");
        asm("" : "+r"(offset));
        entry = base + offset;
        asm("" : "+r"(entry) : "r"(base));
        *entry;
    });
    asm("" : "+r"(first) : "r"(base));
    save = base;
    asm("" : "+r"(save) : "r"(first));
    if (first)
    {
        for (;;)
        {
            slot++;
            if (slot > 5)
                break;
            if (({
                register u8 *entry asm("r0") = (u8 *)(slot * 4 + (u32)save);
                register u32 offset asm("r1");
                asm("" : "+r"(entry));
                offset = 0x3601;
                asm("" : "+r"(offset) : "r"(entry));
                entry[offset];
            }) == 0)
            {
                result = 1;
                break;
            }
        }
        if (result == 0)
            goto done;
    }
    result = 0;
    for (slot = 0; slot <= 5; slot++)
    {
        if (func_08032A88(0, slot) && D_0200EB84.units[slot].wound == 0)
        {
            result = 1;
            break;
        }
    }
done:
    asm("" : "+r"(result));
    return result;
}
