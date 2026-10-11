#include "types.h"

struct Unit
{
    u8 pad_0[0xE];
    u8 kind;
    u8 pad_F[0xC0];
    u8 rank;
};

extern u8 D_08675DBC[];
extern u8 D_0866B94C[];

void func_08032800(u8);
void func_0803E488(u8 *, u8);

void func_080339C4(struct Unit *unit)
{
    func_08032800(unit->kind);
    if ((u8)(unit->rank - 1) <= 5)
        func_0803E488(D_08675DBC, D_0866B94C[unit->rank]);
}
