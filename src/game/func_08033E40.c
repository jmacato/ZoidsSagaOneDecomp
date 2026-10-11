#include "types.h"

struct Move33
{
    u32 flags;
    s16 value;
    u16 pad_6;
    s32 effect;
    s16 cost;
    u16 pad_E;
    u8 pad_10;
    u8 strength;
    u16 duration;
};
struct Counter33 { u16 current; u16 maximum; };
struct Unit33
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[6];
    s32 hp;
    s32 energy;
    u8 pad_18[0x18];
    s32 maximum_hp;
    s32 maximum_energy;
    u8 pad_38[0x18];
    struct Move33 moves[6];
    u8 pad_C8[12];
    u32 gold;
    u32 experience;
    struct Counter33 counters[6];
    u8 pad_F4[0x1D8];
};
struct Side33 { struct Unit33 units[6]; u8 pad_10C8[16]; };
struct Turn33 { u8 side; u8 slot; u8 pad_2[2]; };
struct Status33 { u16 flags; u16 kind; s32 value; u8 type; u8 pad_9[3]; };
extern struct
{
    u16 flags;
    u8 pad_2[6];
    struct Side33 sides[2];
    u8 pad_21B8[0x34];
    u8 actor_side;
    u8 actor_slot;
    u8 pad_21EE[2];
    u8 move;
    u8 count;
    u8 pad_21F2[2];
    struct Turn33 turns[6];
    struct Status33 status[2][6];
    u8 pad_229C[4];
    u32 gold;
    u32 experience;
} D_0200EB84;
extern u16 D_020143BC[];
extern u16 D_02010E20;
extern u8 D_02000B5C[];
void func_08034448(void);
void func_080350A4(void);
void func_0805D270(const void *, void *, u32);
u16 func_08034500(struct Unit33 *, struct Unit33 *, u8);
s32 func_080345EC(struct Unit33 *, struct Unit33 *, u8, u16);
void func_08032B54(struct Unit33 *, u32, s32, u32, u32, u32);
void func_08033874(struct Unit33 *, u32);
s32 func_080395E8(s32, u16 *);

void func_08033E40(void)
{
    struct Unit33 *attacker;
    register struct Unit33 *target asm("r6");
    struct Move33 *move;
    register s32 *effect_base asm("sl");
    register struct Status33 *status asm("r5");
    u16 index;
    u32 side;
    u16 accuracy;
    u16 roll;
    u16 critical;
    u16 zero;
    u32 kind;
    func_08034448();
    { struct Side33 *selected = &D_0200EB84.sides[D_0200EB84.actor_side]; asm("" : : "r"(selected)); attacker = &selected->units[D_0200EB84.actor_slot]; }
    { register u32 offset asm("r6") = 0x21F0; register u8 *base asm("r2") = (u8 *)&D_0200EB84; asm("" : : "r"(offset), "r"(base)); move = &attacker->moves[base[offset]];
    attacker->energy -= move->cost;
    asm("" : : "r"(offset));
    }
    if (attacker->energy < 0)
        attacker->energy = 0;
    if (move->flags & 1)
        side = ({ register u32 opposite asm("r1") = D_0200EB84.actor_side == 0; asm("" : : "r"(opposite)); opposite; });
    else
        side = D_0200EB84.actor_side != 0;
    index = 0;
    if (index < ({ register u8 *base asm("r1") = (u8 *)&D_0200EB84; register u32 offset asm("r6"); register u8 *address asm("r0"); asm("" : "+r"(base)); offset = 0x21F1; asm("" : : "r"(offset), "r"(base)); address = base + offset; asm("" : "+r"(address)); *address; }))
    {
        { register u32 offset asm("r0") = 88; asm("" : "+r"(offset)); offset += (u32)attacker; effect_base = (s32 *)offset; }
        do
        {
        u32 slot;
        asm("" : "+r"(attacker));
        { register u32 turn_index asm("r1") = index;
          register u32 scaled asm("r0"); register u8 *base asm("r2");
          register u32 slot_offset asm("r3"); register u8 *address asm("r1");
          register u32 side_offset asm("r4");
          asm("" : : "r"(turn_index)); scaled = turn_index * 4; asm("" : "+r"(scaled));
          base = (u8 *)&D_0200EB84; asm("" : : "r"(base), "r"(scaled)); scaled += (u32)base;
          asm("" : "+r"(scaled)); slot_offset = 0x21F5; asm("" : : "r"(slot_offset));
          address = (u8 *)(scaled + slot_offset); asm("" : "+r"(address)); slot = *address;
          side_offset = 0x21F4; asm("" : : "r"(side_offset)); *((u8 *)(scaled + side_offset)) = side; }
        {
            register u32 stride asm("r0") = 4312;
            register u32 loop_side asm("r2") = side;
            register u32 selected asm("r1") = loop_side;
            asm("" : "+r"(stride) : "r"(loop_side));
            selected *= stride;
            asm("" : "+r"(selected) : "r"(slot), "r"(loop_side));
            stride = (u32)&D_0200EB84;
            asm("" : "+r"(stride) : "r"(selected));
            stride += 8;
            asm("" : "+r"(stride) : "r"(selected));
            selected += stride;
            asm("" : "+r"(selected) : "r"(slot), "r"(loop_side));
            stride = 716;
            asm("" : "+r"(stride) : "r"(selected), "r"(slot));
            stride *= slot;
            target = (struct Unit33 *)(selected + stride);
            {
                register u32 side_offset asm("r2") = loop_side << 3;
                register u32 saved_side asm("r4") = side;
                register u32 slot_offset asm("r0");
                register u32 base asm("r3");
                register u32 offset asm("r4");
                register u32 address asm("r1");
                asm("" : "+r"(side_offset), "+r"(saved_side) : "r"(slot));
                side_offset += saved_side;
                side_offset <<= 3;
                slot_offset = slot * 12;
                asm("" : "+r"(side_offset), "+r"(slot_offset));
                base = (u32)&D_0200EB84;
                offset = 0x220C;
                asm("" : "+r"(base), "+r"(offset) : "r"(side_offset), "r"(slot_offset));
                address = base + offset;
                asm("" : "+r"(address) : "r"(side_offset), "r"(slot_offset));
                slot_offset += address;
                status = (struct Status33 *)(side_offset + slot_offset);
            }
        }
        asm("" : : "r"(target), "r"(status));
        zero = 0;
        func_0805D270(&zero, status, 0x01000006);
        { register u8 *base asm("r2") = (u8 *)&D_0200EB84; register u32 offset asm("r3") = 0x21F0; register u8 *address asm("r0"); asm("" : "+r"(base), "+r"(offset)); address = base + offset; asm("" : "+r"(address)); accuracy = func_08034500(attacker, target, *address); }
        if (accuracy == 100)
        { register u32 flags asm("r0") = status->flags;
          register u32 one asm("r4") = 1; asm("" : "+r"(one) : "r"(flags)); status->flags = flags | one; }
        else if (accuracy != 0)
        {
            roll = D_020143BC[15 - index];
            if (accuracy >= roll)
            {
                status->flags |= 1;
                { register u16 *base asm("r1") = &D_02010E20; asm("" : : "r"(base)); critical = (*base >> 1) + 2; }
                if (({ register struct Move33 *selected asm("r4") = move; asm("" : : "r"(selected)); selected->flags; }) & 0x80)
                {
                    critical *= 2;
                    if (critical < 10)
                        critical = 10;
                }
                if (!(target->flags & 0x200) || D_02000B5C[2] <= 5)
                    if (critical > roll)
                        status->flags |= 2;
            }
        }
        if (move->flags & 1)
        {
            if (move->flags & 0x800)
            {
                status->flags |= 1;
                status->type = 2;
                {
                    register u8 *base asm("r3") = (u8 *)&D_0200EB84;
                    register u32 offset asm("r4") = 0x21F0;
                    register u8 *selector asm("r2");
                    asm("" : "+r"(base), "+r"(offset));
                    selector = base + offset;
                    asm("" : "+r"(selector));
                    status->value = effect_base[*selector * 5];
                    status->kind = 0x22;
                    {
                        register u32 scaled asm("r0") = *selector * 20;
                        register s32 *effect_start asm("r2") = effect_base;
                        register s32 *effect_address asm("r1");
                        register s32 effect asm("r2");
                        u32 strength;
                        asm("" : "+r"(scaled), "+r"(effect_start));
                        effect_address = (s32 *)((u32)effect_start + scaled);
                        asm("" : "+r"(effect_address) : "r"(scaled));
                        effect = *effect_address;
                        strength = *((u8 *)attacker + scaled + 0x61);
                        func_08032B54(target, 0x22, effect, 2, strength, move->duration);
                    }
                }
            }
            else if (status->flags & 1)
            {
                status->type = 0;
                { s32 damage = func_080345EC(attacker, target, D_0200EB84.move, status->flags);
                  status->value = damage;
                if ((target->hp -= damage >> 16) <= 0)
                {
                    target->hp = 0;
                    target->energy = 0;
                    status->flags |= 0x8000;
                    target->flags |= 0x400;
                    D_0200EB84.experience += target->experience;
                    D_0200EB84.gold += target->gold;
                }
                }
                if (move->flags & 0x1000)
                {
                    status->flags |= 8;
                    {
                        register u32 scaled asm("r0") = D_0200EB84.move * 20;
                        register s32 *effect_start asm("r2") = effect_base;
                        register s32 *effect_address asm("r1");
                        register s32 effect asm("r2");
                        u32 strength;

                        effect_address = (s32 *)((u32)effect_start + scaled);
                        asm("" : "+r"(effect_address) : "r"(scaled));
                        effect = *effect_address;
                        strength = *((u8 *)attacker + scaled + 0x61);
                        func_08032B54(target, 0x2000, effect, 3, strength, move->duration);
                    }
                }
                if (move->flags & 0x2000)
                    status->flags |= 4;
            }
        }
        else
        {
register u8 *base asm("r4") = (u8 *)&D_0200EB84; register u32 offset asm("r0") = 0x21F0; u8 *normal_selector; asm("" : : "r"(base), "r"(offset), "r"(attacker)); normal_selector = base + offset;
        if (attacker->moves[*normal_selector].flags & 0xC000)
        {
            if (attacker->moves[*normal_selector].flags & 0x4000)
            {
                u8 *support_selector=normal_selector;
                asm("" : "+l"(support_selector));
                {
                register u32 scaled asm("r3") = *normal_selector * 20;
                register s32 *effect_start asm("r1") = effect_base;
                register s32 *effect_address asm("r0");
                register s32 effect asm("r2");
                u32 strength;
                register u8 *strength_address asm("r0");
                effect_address = (s32 *)((u32)effect_start + scaled);
                asm("" : "+r"(effect_address) : "r"(scaled));
                effect = *effect_address;
                strength_address = (u8 *)attacker + scaled + 0x61;
                asm("" : "+r"(strength_address)); strength = *strength_address;
                func_08032B54(target, 0x1201, effect, 2, strength, move->duration);
            }
                func_08032B54(target, 0x1401, attacker->moves[*support_selector].value, 2,
                    attacker->moves[*support_selector].strength, move->duration);
            }
            else
            {
                {
                register u32 scaled asm("r3") = ({ asm("" : : "r"(attacker)); *normal_selector; }) * 20;
                register s32 *effect_start asm("r2") = effect_base;
                register s32 *effect_address asm("r0");
                register s32 effect asm("r2");
                u32 strength;
                register u8 *strength_address asm("r0");
                effect_address = (s32 *)((u32)effect_start + scaled);
                asm("" : "+r"(effect_address) : "r"(scaled));
                effect = *effect_address;
                strength_address = (u8 *)attacker + scaled + 0x61;
                asm("" : "+r"(strength_address)); strength = *strength_address;
                func_08032B54(target, 0x201, effect, 2, strength, move->duration);
            }
                {
                register u32 scaled asm("r0") = ({ asm("" : : "r"(attacker)); *normal_selector; }) * 20;
                register s32 *effect_start asm("r2") = effect_base;
                register s32 *effect_address asm("r1");
                register s32 effect asm("r2");
                u32 strength;
                effect_address = (s32 *)((u32)effect_start + scaled);
                asm("" : "+r"(effect_address) : "r"(scaled));
                effect = *effect_address;
                strength = *((u8 *)attacker + scaled + 0x61);
                func_08032B54(target, 0x401, effect, 2, strength, move->duration);
            }
            }
            {
            register u8 *base asm("r6");
            register u32 offset asm("r0");
            register u8 *selector asm("r3");            register s32 *effects asm("r2") = &attacker->moves[0].effect;
            register u32 support_one asm("r4") = 1;
            asm("" : : "r"(effects));
            asm("" : "+r"(support_one));
            *((u8 *)status + 8) = support_one;
            { register u32 status_flags asm("r0") = status->flags;
              asm("" : "+r"(status_flags) : "r"(support_one));
              *(u16 *)status = status_flags | support_one; }
            *((u16 *)status + 1) = support_one;
            base = (u8 *)&D_0200EB84;
            offset = 0x21F0;
            asm("" : "+r"(base), "+r"(offset));
            selector = base + offset;
            asm("" : "+r"(selector));
            {
                register u32 selected_index asm("r1") = *selector;
                register u32 product asm("r0") = selected_index * 5;
                register u32 scaled asm("r1");
                s16 value;
                asm("" : "+r"(product) : "r"(selected_index));
                scaled = product * 4;
                value = *(s16 *)((u8 *)attacker + scaled + 0x54);
                if (value == 0)
                {
                    status->kind = 0x201;
                    scaled = *selector * 20;
                    status->value = *(s32 *)((u8 *)effects + scaled);
                }
                else if (({ register s32 *effect_address asm("r0") = (s32 *)((u8 *)effects + scaled);
                            asm("" : "+r"(effect_address)); *effect_address; }) == 0)
                {
                    { register u32 support_kind asm("r1") = 0x401;
                      asm("" : : "r"(support_kind)); status->kind = support_kind; }
                    scaled = *selector * 20;
                    status->value = *(s16 *)((u8 *)attacker + scaled + 0x54);
                }
                else
                {
                    { register u32 mask asm("r6") = 0x100;
                      register u32 kind_mask asm("r1") = mask;
                      register u32 support_kind asm("r0") = support_one;
                      asm("" : : "r"(mask));
                      asm("" : "+r"(support_kind) : "r"(kind_mask));
                      status->kind = support_kind | kind_mask; }
                    { register u32 selected_index asm("r1") = *selector;
                      register u32 last_scaled asm("r0") = selected_index * 5;
                      register s16 *value_address asm("r0");
                      s16 value;
                      asm("" : "+r"(last_scaled) : "r"(selected_index));
                      last_scaled *= 4;
                      effects = (s32 *)((u8 *)effects + last_scaled);
                      value_address = (s16 *)((u8 *)attacker + last_scaled + 0x54);
                      asm("" : "+r"(value_address));
                      value = *value_address; status->value = *effects + value; }
                }
            }
        }
            }
        else if (attacker->moves[({ asm("" : : "r"(attacker)); *normal_selector; })].flags & 0x20000)
        {
            kind = 0x801;
            asm("" : "+r"(kind));
            {
                register u32 scaled asm("r3") = *normal_selector * 20;
                register s32 *effect_start asm("r1") = effect_base;
                register s32 *effect_address asm("r0");
                register s32 effect asm("r2");
                u32 strength;
                register u8 *strength_address asm("r0");
                effect_address = (s32 *)((u32)effect_start + scaled);
                effect = *effect_address;
                strength_address = (u8 *)attacker + scaled + 0x61;
                strength = *strength_address;
                func_08032B54(target, kind, effect, 2, strength, move->duration);
            }
            status->type = 1;
            status->flags |= 1;
            status->value = effect_base[*normal_selector * 5];
            status->kind = kind;
        }
        else if (attacker->moves[({ asm("" : : "r"(attacker)); *normal_selector; })].flags & 0x10000)
        {
            kind = 0x8001;
            asm("" : "+r"(kind));
            {
                register u32 scaled asm("r3") = *normal_selector * 20;
                register s32 *effect_start asm("r1") = effect_base;
                register s32 *effect_address asm("r0");
                register s32 effect asm("r2");
                u32 strength;
                register u8 *strength_address asm("r0");
                effect_address = (s32 *)((u32)effect_start + scaled);
                effect = *effect_address;
                strength_address = (u8 *)attacker + scaled + 0x61;
                strength = *strength_address;
                func_08032B54(target, kind, effect, 2, strength, move->duration);
            }
            status->type = 1;
            status->flags |= 1;
            status->value = effect_base[*normal_selector * 5];
            status->kind = kind;
        }
        else if (attacker->moves[({ asm("" : : "r"(attacker)); *normal_selector; })].flags & 0x40000)
        {
            {
                register u32 scaled asm("r3") = ({ asm("" : : "r"(attacker)); *normal_selector; }) * 20;
                register s32 *effect_start asm("r4") = effect_base;
                register s32 *effect_address asm("r0");
                register s32 effect asm("r2");
                u32 strength;
                register u8 *strength_address asm("r0");
                effect_address = (s32 *)((u32)effect_start + scaled);
                asm("" : "+r"(effect_address) : "r"(scaled));
                effect = *effect_address;
                strength_address = (u8 *)attacker + scaled + 0x61;
                asm("" : "+r"(strength_address)); strength = *strength_address;
                func_08032B54(target, 0x21, effect, 3, strength, move->duration);
            }
            status->type = 1;
            status->flags |= 1;
            status->kind = 0x21;
            status->value = effect_base[({ asm("" : : "r"(attacker)); *normal_selector; }) * 5];
        }
        else if (attacker->moves[({ asm("" : : "r"(attacker)); *normal_selector; })].flags & 0x400000)
        {
            status->type = 5;
            status->flags |= 1;
            func_08033874(target, 0x32);
            target->hp = target->maximum_hp;
            target->energy = target->maximum_energy;
        }
        else if (attacker->moves[({ asm("" : : "r"(attacker)); *normal_selector; })].flags & 0x100000)
        {
            status->type = 4;
            status->flags |= 1;
            {
                register u32 scaled asm("r0") = ({ asm("" : : "r"(attacker)); *normal_selector; }) * 20;
                register s32 *effect_start asm("r4") = effect_base;
                register s32 *effect_address asm("r1");
                register s32 effect asm("r2");
                u32 strength;
                effect_address = (s32 *)((u32)effect_start + scaled);
                asm("" : "+r"(effect_address) : "r"(scaled));
                effect = *effect_address;
                strength = *((u8 *)attacker + scaled + 0x61);
                func_08032B54(target, 0x4000, effect, 2, strength, move->duration);
            }
        }
        else if (attacker->moves[({ asm("" : : "r"(attacker)); *normal_selector; })].flags & 0x80000)
        {
            status->type = 3;
            status->flags |= 1;
            status->value = func_080395E8(effect_base[({ asm("" : : "r"(attacker)); *normal_selector; }) * 5], &target->flags);
        }
        }
        if ((s32)attacker->moves[D_0200EB84.move].flags < 0)
        {
            attacker->counters[D_0200EB84.move].current = 0;
            attacker->counters[D_0200EB84.move].maximum = 0xFFFF;
        }
        index++;
        } while (index < D_0200EB84.count);
    }
    func_080350A4();
}
