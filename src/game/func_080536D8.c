#include "types.h"
typedef unsigned long long u64;
union RegisterWord { u32 word; u64 wide; };

struct ShopEntry { u8 kind, id; u16 pad; };
struct ShopFrame {
    u32 shop, page, selected, previous, saved_cursor;
    u32 quantity, total, refresh, last_index;
};
extern u8 D_02000030;
extern u8 D_02000034[];
extern u32 D_02001884;
extern u8 D_020075A0[];
extern u8 D_02000B5C[];
extern u8 D_02003E61[], D_02003E68[];
extern u16 D_02007574[], D_02007588;
extern u8 D_0200E779[], D_0200E780, D_020082FD, D_020082FF;
extern u16 D_030022FC;
extern const struct ShopEntry D_0875BACC[][4];
extern const u32 D_0875BC1C[], D_0875BC38[];
extern const u8 D_08676238[], D_08676254[], D_08676350[], D_0875B8A4[];
extern const u8 D_0875BA9C[], D_0875B330[], D_0875B068[], D_0875AFB8[];
extern const u8 D_08675BEC[], D_08675C5C[];
void func_08000DB8(void);
void func_08000D1C(u32);
void func_08001A54(const void *, u32, u32);
void func_0803E024(u32, u32, u32);
void func_08003DF8(u32, void (*)(void));
void func_08003E3C(u32);
void func_08053524(void);
void func_08004034(void);
void func_0803E488(const void *, u32);
void func_08001848(s32, u32, u32);
void func_080019EC(u32);
void func_0804D604(const void *, u32, u32);
void func_0804E230(void);
s32 func_0805D484(s32, s32);
u32 func_0805354C(u32, s32, u32);
void func_0805EE78(s32);

void func_080536D8(void)
{
    struct ShopFrame frame;
    u16 state;
    s32 i, shown;
    u16 previous_page;
    const struct ShopEntry *entry;
    u32 limit, price;
    register union RegisterWord sale_refresh asm("r2");
    u8 *owned;
    {
        register u8 *tasks asm("r5") = D_02000034;
        register u8 *current asm("r0") = &D_02000030;
        register u32 task_index asm("r1");
        register u32 offset asm("r0");
        register u8 *parameter_base asm("r1");
        asm("" : : "r"(tasks), "r"(current));
        task_index = *current;
        offset = task_index * 136;
        asm("" : "+r"(offset) : "r"(task_index));
        parameter_base = tasks + 12;
        asm("" : "+r"(parameter_base) : "r"(offset));
        frame.shop = *(u32 *)((u32)offset + (u32)parameter_base);
        func_08000DB8();
        func_08000D1C(0);
        {
            register vu16 *display asm("r1") = (vu16 *)0x04000000;
            register u32 control asm("r2") = 0x1D40;
            register u32 background asm("r3");
            register u32 value asm("r0");
            asm("" : "+r"(display), "+r"(control));
            value = control;
            asm("" : "+r"(value) : "r"(control), "r"(display));
            *display = value;
            display += 6;
            background = 0x38B;
            asm("" : "+r"(background) : "r"(display));
            value = background;
            asm("" : "+r"(value) : "r"(background), "r"(display));
            *display = value;
            display++;
            control = 0x48B;
            asm("" : "+r"(control) : "r"(display));
            value = control;
            asm("" : "+r"(value) : "r"(control), "r"(display));
            *display = value;
        }
        func_08001A54(D_0875BA9C, 0, 1);
        func_08001A54(D_0875BA9C, 1, 1);
        func_08001A54(D_0875BA9C, 2, 1);
        func_08001A54(D_0875BA9C, 3, 1);
        func_0803E024(3, 0, 255);
        func_08003DF8(5, func_08053524);
        func_08003DF8(10, func_08004034);
        {
            register u32 flag_offset asm("r3") = 0x558;
            register u32 zero asm("r1");
            register u32 flag_address asm("r0");
            register u32 control_offset asm("r0");
            asm("" : "+r"(flag_offset));
            flag_address = (u32)tasks + flag_offset;
            asm("" : "+r"(flag_address));
            zero = 0;
            asm("" : : "r"(zero), "r"(flag_address));
            *(u32 *)flag_address = zero;
            control_offset = 0x55C;
            asm("" : "+r"(control_offset) : "r"(zero));
            tasks += control_offset;
            *(u32 *)tasks = zero;
        }
        state = 0;
    }
dispatch_shop_state:
    {
        {
        register s32 selected_state asm("r1");
        register u32 shifted asm("r0");
        u32 compare;
        shifted = state << 16;
        asm("" : "+r"(shifted));
        selected_state = (s32)shifted >> 16;
        asm("" : "+r"(selected_state));
        compare = 0x110;
        asm volatile("" : : : "r9");
            if (selected_state == compare) goto shop_state_110;
            if (selected_state > (s32)compare) goto shop_above_110;
            if (selected_state == 0x20) goto shop_state_020;
            if (selected_state > 0x20) goto shop_above_020;
            {
                u32 zero_state = selected_state;
                asm("" : "+l"(zero_state));
                if (zero_state == 0) goto shop_state_000;
            }
            goto dispatch_shop_done;
        shop_above_020:
            compare = 0x100;

            if (selected_state == compare) goto shop_state_100;
            compare += 1;

            if (selected_state == compare) goto shop_state_101;
            goto dispatch_shop_done;
        shop_above_110:
            {
                register s32 middle asm("r4") = 0x201;
                asm("" : "+r"(middle));
                if (selected_state == middle) goto shop_state_201;
                if (selected_state > middle) goto shop_above_201;
            }
            compare = 0x120;

            if (selected_state == compare) goto shop_state_120;
            compare += 0xE0;

            if (selected_state == compare) goto shop_state_200;
            goto dispatch_shop_done;
        shop_above_201:
            {
                register u32 value asm("r3") = 0x210;
                register u32 held asm("r9");
                asm("" : "+r"(value));
                held = value;
                asm("" : : "r"(held));
                if (selected_state == held) goto shop_state_210;
            }
            compare = 0x220;

            if (selected_state == compare) goto shop_state_220;
            goto dispatch_shop_done;
        }
        switch ((s16)state) {
        case 0:
        shop_state_000:
        {
            register const u8 *message asm("r4");
            func_0803E488(D_08675BEC, 1);
            func_0803E488(D_0875B330, 0);
            message = D_0875B068;
            func_0803E488(message, 0);
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r5", "r6", "r7");
                func_0803E488(layout, 42);
            }
            {
                register u32 *money asm("r1") = &D_02001884;
                func_08001848(*money, 7, 0);
            }
            func_0803E488(message, 1);
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r5", "r6", "r7");
                func_0803E488(layout, 24);
            }
        }
        {
            register u8 *base asm("r0") = D_02000034;
            register u32 offset asm("r2") = 0x568;
            register u32 *initial asm("r1");
            asm("" : "+r"(base), "+r"(offset));
            initial = (u32 *)(base + offset);
            if (*initial != 1) {
                u32 *flag = initial;
                do {
                    func_0805EE78(1);
                } while (*flag != 1);
            }
        }
            func_0803E488(D_0875B330, 1);
        case 0x20:
        shop_state_020:
            func_0803E488(D_0875B330, 2);
            if (!D_02007574[0]) {
                func_080019EC(63);
                state = 0xFFFF;
                break;
            }
            if (D_02007574[1] == 1) {
                func_0804E230();
                if (!D_0200E780) {
                    func_080019EC(79);
                    func_0803E488(D_0875B330, 3);
                    func_080019EC(65);
                return_to_shop_menu:
                    state = 0x20;
                    break;
                }
            }
            func_0803E488(D_0875AFB8, 0);
            {
                register u32 value asm("r0") = D_02007574[1];
                register u32 step asm("r3");
                register u32 next asm("r2");
                asm("" : "+r"(value));
                value <<= 24;
                asm("" : "+r"(value));
                step = 0x1000000;
                asm("" : "+r"(step));
                value += step;
                asm("" : "+r"(value));
                next = value >> 16;
                asm("" : : "r"(next));
                state = next;
            }
            break;
        case 0x100:
        shop_state_100:
        {
            u32 row;
            register u32 shop_offset asm("r6");
            register const u8 *catalog asm("r8");
            register const struct ShopEntry *item asm("r5");
            func_0803E488(D_0875B330, 4);
            row = 0;
            asm("" : : "r"(row));
            {
                register u32 value asm("r1") = frame.shop;
                register u32 offset asm("r0");
                register const u8 *base asm("r2");
                offset = value << 4;
                asm("" : : "r"(offset));
                base = (const u8 *)D_0875BACC;
                asm("" : : "r"(base), "r"(offset));
                value = (u32)offset + (u32)base;
                asm("" : : "r"(value));
                value = *(const u8 *)value;
                asm("" : : "r"(value));
                shop_offset = offset;
                asm("" : : "r"(shop_offset), "r"(value));
                if (value == 255)
                    goto purchase_entries_done;
                {
                    register const u8 *copy asm("r3") = base;
                    asm("" : : "r"(copy));
                    catalog = copy;
                    asm("" : : "r"(catalog));
                }
            }
purchase_entry:
            {
                u32 kind;
                register u32 shifted asm("r1") = row << 16;
                register u32 offset asm("r0");
                register const u8 *base asm("r2");
                asm("" : : "r"(shifted));
                offset = (s32)shifted >> 14;
                asm("" : : "r"(offset));
                offset += shop_offset;
                asm("" : : "r"(offset));
                base = catalog;
                asm("" : : "r"(base));
                item = (const struct ShopEntry *)((u32)offset + (u32)base);
                asm("" : : "r"(item));
                kind = item->kind;
                asm("" : "+r"(kind));
                row = shifted;
                asm("" : : "r"(row), "r"(kind));
                if (kind == 0) {
                    func_0803E488(D_08676238, item->id);
                    func_0804D604(D_08676238, item->id, 9);
                    {
                        register u32 offset asm("r0") = item->id;
                        register const u32 *prices asm("r3");
                        offset <<= 2;
                        asm("" : "+r"(offset));
                        prices = D_0875BC1C;
                        asm("" : "+r"(prices) : "r"(offset));
                        func_08001848(*(const u32 *)(offset + (u32)prices), 7, 0);
                    }
                    func_0803E488(D_0875B068, 1);
                } else if (kind == 1) {
                    func_0803E488(D_08676254, item->id);
                    func_0804D604(D_08676254, item->id, 9);
                    func_08001848(D_0875BC38[item->id], 7, 0);
                    func_0803E488(D_0875B068, 1);
                }
            }
            {
                register u32 offset asm("r0") = (s32)row >> 16;
                asm("" : "+r"(offset));
                if ((s32)offset <= 2) {
                    offset++;
                    asm("" : "+r"(offset));
                    offset <<= 2;
                    asm("" : "+r"(offset));
                    offset += shop_offset;
                    asm("" : "+r"(offset));
                    offset += (u32)catalog;
                    asm("" : "+r"(offset));
                    if (*(const u8 *)offset != 255)
                        func_0803E488(D_08675C5C, 0);
                }
            }
            {
                register u32 step asm("r1") = 0x10000;
                register u32 combined asm("r0");
                asm("" : "+r"(step));
                combined = row + step;
                asm("" : "+r"(combined));
                row = combined >> 16;
                asm("" : : "r"(row), "r"(combined));
                combined = (s32)combined >> 16;
                asm("" : "+r"(combined));
                if ((s32)combined <= 3) {
                    combined <<= 2;
                    asm("" : "+r"(combined));
                    combined += shop_offset;
                    asm("" : "+r"(combined));
                    combined += (u32)catalog;
                    asm("" : "+r"(combined));
                    if (*(const u8 *)combined != 255)
                        goto purchase_entry;
                }
            }
purchase_entries_done:
            {
                register u16 *cursor asm("r1") = &D_02007588;
                register u32 zero asm("r0") = 0;
                asm("" : "+r"(cursor), "+r"(zero));
                *cursor = zero;
            }
            {
                register u32 selected asm("r2") = 0;
                register u32 previous asm("r3");
                asm("" : "+r"(selected));
                frame.selected = selected;
                previous = 0xFFFF;
                asm("" : "+r"(previous) : "m"(frame.selected));
                frame.previous = previous;
            }
            {
                register u32 zero asm("r0") = 0;
                asm("" : "+r"(zero) : "m"(frame.previous));
                frame.refresh = zero;
            }
        }
        case 0x101:
        shop_state_101:
        {
            register u32 selected_shifted asm("r5");
            register u32 shop_offset asm("r6");
            u32 previous_shifted;
            const u8 *error_script;
            u32 error_index;
        refresh_purchase:
            {
                register u32 previous asm("r2") = frame.previous;
                register u32 selected asm("r3");
                u32 refresh;
                asm("" : "+r"(previous));
                previous_shifted = previous << 16;
                asm("" : "+r"(previous_shifted));
                selected = frame.selected;
                asm("" : "+r"(selected));
                selected_shifted = selected << 16;
                asm("" : "+r"(selected_shifted));
                refresh = frame.refresh;
                asm("" : "+r"(refresh));
                if (refresh || previous_shifted != selected_shifted)
                    goto redraw_purchase;
                goto purchase_wait;
            }
            {
            redraw_purchase:
                if ((s32)previous_shifted >> 16 != -1) {
                    {
                        register const u8 *layout asm("r0") = D_0875AFB8;
                        asm("" : "+r"(layout) : : "r4");
                        func_0803E488(layout, 0);
                    }
                    {
                        register const u8 *layout asm("r0") = D_0875AFB8;
                        asm("" : "+r"(layout) : : "r4");
                        func_0803E488(layout, 4);
                    }
                }
                func_0803E488(D_0875B330, 5);
                {
                    register u32 offset asm("r0") = (s32)selected_shifted >> 14;
                    register u32 shop asm("r1");
                    register u32 value asm("r2");
                    register u32 scratch asm("r3");
                    value = frame.shop;
                    shop = value << 4;
                    offset += shop;
                    scratch = (u32)D_0875BACC;
                    offset += scratch;
                    scratch = *(const u8 *)offset;
                    shop_offset = shop;
                    asm("" : : "r"(shop_offset), "r"(scratch), "r"(offset));
                    if (scratch == 0) {
                        register const u8 *inventory asm("r1");
                        offset = *(const u8 *)(offset + 1);
                        inventory = D_02003E61;
                        offset += (u32)inventory;
                        func_08001848(*(const u8 *)offset, 2, 0);
                    } else if (scratch == 1) {
                        register const u8 *inventory asm("r2");
                        offset = *(const u8 *)(offset + 1);
                        inventory = D_02003E68;
                        offset += (u32)inventory;
                        func_08001848(*(const u8 *)offset, 2, 0);
                    }
                }
                func_0803E488(D_0875B330, 6);
                func_0803E488(D_0875AFB8, 25);
                asm("" : "+r"(selected_shifted));
                {
                    register u32 offset asm("r0") = (s32)selected_shifted >> 14;
                    register u32 scratch asm("r3");
                    offset += shop_offset;
                    scratch = (u32)D_0875BACC;
                    offset += scratch;
                    scratch = *(const u8 *)offset;
                    if (scratch == 0) {
                        register u32 id asm("r1") = *(const u8 *)(offset + 1);
                        register const u8 *layout asm("r0");
                        layout = D_08676350;
                        asm("" : "+r"(layout) : "r"(id));
                        func_0803E488(layout, id);
                    } else if (scratch == 1) {
                        register u32 id asm("r1") = *(const u8 *)(offset + 1);
                        register const u8 *layout asm("r0");
                        layout = D_0875B8A4;
                        asm("" : "+r"(layout) : "r"(id));
                        func_0803E488(layout, id);
                    }
                }
                {
                    register const u8 *layout asm("r0") = D_0875AFB8;
                    asm("" : "+r"(layout) : : "r4");
                    func_0803E488(layout, 24);
                }
                selected_shifted >>= 16;
                asm("" : "+r"(selected_shifted));
                frame.previous = selected_shifted;
                frame.refresh = 0;
            }
        purchase_wait:
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4");
                func_0803E488(layout, 35);
            }
            {
                register u32 value asm("r0") = D_02007588;
                frame.selected = value;
            }
            if (D_02007574[0] > 1)
                goto refresh_purchase;
            if (D_02007574[0] == 0)
                goto cancel_purchase;
            {
                register u32 address asm("r1");
                register u32 offset asm("r0");
                register u32 scratch asm("r3");
                register u32 shop asm("r2");
                register const struct ShopEntry *item asm("r4");
                u32 kind;
                const u8 *catalog;
                asm("" : "+m"(frame.selected));
                address = frame.selected;
                offset = address << 16;
                address = (s32)offset >> 14;
                scratch = frame.shop;
                shop = scratch << 4;
                address += shop;
                scratch = (u32)D_0875BACC;
                item = (const struct ShopEntry *)(address + scratch);
                asm("" : "+r"(item));
                kind = item->kind;
                asm("" : "+r"(kind));
                catalog = (const u8 *)D_0875BACC;
                asm("" : "+r"(catalog));
                shop_offset = shop;
                selected_shifted = offset;
                asm("" : : "r"(shop_offset), "r"(selected_shifted), "r"(kind));
                if (kind == 0) {
                    offset = item->id;
                    offset <<= 2;
                    address = (u32)D_0875BC1C;
                    offset += address;
                    address = *(const u32 *)offset;
                    shop = (u32)&D_02001884;
                    offset = *(const u32 *)shop;
                    if (address > offset)
                        goto purchase_too_expensive;
                }
                if (kind != 1)
                    goto purchase_check_capacity;
                address = (u32)D_0875BC38;
                offset = item->id;
                offset <<= 2;
                offset += address;
                address = *(const u32 *)offset;
                scratch = (u32)&D_02001884;
                offset = *(const u32 *)scratch;
                if (address <= offset)
                    goto purchase_check_capacity;
            purchase_too_expensive:
                func_080019EC(79);
                error_script = D_0875B330;
                asm("" : "+r"(error_script));
                error_index = 9;
                goto purchase_error_message;
            purchase_check_capacity:
                offset = (s32)selected_shifted >> 14;
                offset += shop_offset;
                address = offset + (u32)catalog;
                kind = *(const u8 *)address;
                asm("" : "+r"(kind));
                if (kind == 0) {
                    offset = *(const u8 *)(address + 1);
                    shop = (u32)D_02003E61;
                    offset += shop;
                    offset = *(const u8 *)offset;
                    if (offset == 99)
                        goto purchase_stock_full;
                }
                if (kind != 1)
                    goto purchase_allowed;
                offset = *(const u8 *)(address + 1);
                scratch = (u32)D_02003E68;
                offset += scratch;
                offset = *(const u8 *)offset;
                if (offset != 99)
                    goto purchase_allowed;
            purchase_stock_full:
                func_080019EC(79);
                error_script = D_0875B330;
                asm("" : "+r"(error_script));
                error_index = 10;
            purchase_error_message:
                func_0803E488(error_script, error_index);
                func_080019EC(65);
                previous_shifted = frame.previous << 16;
                asm("" : "+r"(previous_shifted));
                goto redraw_purchase;
            }
        purchase_allowed:
            goto purchase_return_to_quantity;
        }
        case 0x110:
        shop_state_110:
        {
            register u32 value asm("r0");
            register u32 address asm("r1");
            register u32 scratch asm("r2");
            register u32 other asm("r3");
            register u32 id asm("r4");
            u32 kind;
            func_0803E488(D_0875B330, 7);
            address = frame.selected;
            value = address << 16;
            value = (s32)value >> 14;
            scratch = frame.shop;
            address = scratch << 4;
            value += address;
            other = (u32)D_0875BACC;
            address = value + other;
            kind = *(const u8 *)address;
            asm("" : "+r"(kind));
            if (kind == 0) {
                id = *(const u8 *)(address + 1);
                address = id << 2;
                value = (u32)D_0875BC1C;
                address += value;
                scratch = (u32)&D_02001884;
                value = *(const u32 *)scratch;
                address = *(const u32 *)address;
                value = func_0805D484(value, address);
                other = (u32)D_02003E61;
                id += other;
                scratch = *(const u8 *)id;
                address = 99;
                address -= scratch;
                scratch = value << 16;
                value = (s32)scratch >> 16;
                other = address << 16;
                if ((s32)value < (s32)address)
                    goto quantity_from_money;
                goto quantity_from_capacity;
            } else {
                value = (u32)D_0875BC38;
                id = *(const u8 *)(address + 1);
                address = id << 2;
                address += value;
                scratch = (u32)&D_02001884;
                value = *(const u32 *)scratch;
                address = *(const u32 *)address;
                value = func_0805D484(value, address);
                other = (u32)D_02003E68;
                id += other;
                scratch = *(const u8 *)id;
                address = 99;
                address -= scratch;
                scratch = value << 16;
                value = (s32)scratch >> 16;
                other = address << 16;
                if ((s32)value >= (s32)address)
                    goto quantity_from_capacity;
            }
        quantity_from_money:
            value = scratch >> 16;
            goto quantity_ready;
        quantity_from_capacity:
            value = other >> 16;
        quantity_ready:
            if ((u8)func_0805354C(1, (s16)value, 2)) {
                frame.quantity = D_030022FC;
                state = 0x120;
            } else {
                value = 1;
                frame.refresh = value;
                scratch = 0x101;
                asm("" : : "r"(scratch), "m"(frame.refresh));
                state = scratch;
            }
            break;
        }
        case 0x120:
        shop_state_120:
        {
            register u32 selected_shifted asm("r5");
            register u32 shop_offset asm("r6");
            register u32 quantity_shifted asm("r4");
            const u8 *message;
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4", "r7");
                func_0803E488(layout, 0);
            }
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4", "r7");
                func_0803E488(layout, 25);
            }
            {
                register u32 address asm("r1") = frame.selected;
                register u32 offset asm("r0");
                register u32 scratch asm("r3");
                register u32 shop asm("r2");
                u32 kind;
                offset = address << 16;
                address = (s32)offset >> 14;
                scratch = frame.shop;
                shop = scratch << 4;
                address += shop;
                scratch = (u32)D_0875BACC;
                address += scratch;
                kind = *(const u8 *)address;
                asm("" : "+r"(kind));
                shop_offset = shop;
                selected_shifted = offset;
                asm("" : : "r"(shop_offset), "r"(selected_shifted), "r"(kind));
                if (kind == 0) {
                    offset = frame.quantity;
                    quantity_shifted = offset << 16;
                    asm("" : "+r"(quantity_shifted));
                    shop = (s32)quantity_shifted >> 16;
                    asm("" : "+r"(shop));
                    address = *(const u8 *)(address + 1);
                    offset = address << 2;
                    scratch = (u32)D_0875BC1C;
                    offset += scratch;
                    offset = *(const u32 *)offset;
                    scratch = shop;
                    asm("" : "+r"(scratch));
                    scratch *= offset;
                    frame.total = scratch;
                    offset = (u32)D_08676238;
                    asm("" : "+r"(offset) : "m"(frame.total));
                    func_0803E488((const void *)offset, address);
                } else {
                    offset = frame.quantity;
                    quantity_shifted = offset << 16;
                    asm("" : "+r"(quantity_shifted));
                    if (kind == 1) {
                        scratch = (s32)quantity_shifted >> 16;
                        asm("" : "+r"(scratch));
                        shop = (u32)D_0875BC38;
                        address = *(const u8 *)(address + 1);
                        offset = address << 2;
                        offset += shop;
                        offset = *(const u32 *)offset;
                        shop = scratch;
                        asm("" : "+r"(shop));
                        shop *= offset;
                        frame.total = shop;
                        offset = (u32)D_08676254;
                        asm("" : "+r"(offset) : "m"(frame.total));
                        func_0803E488((const void *)offset, address);
                    }
                }
            }
            message = D_0875B330;
            asm("" : "+r"(message));
            func_0803E488(message, 11);
            func_08001848((s32)quantity_shifted >> 16, 2, 1);
            func_0803E488(message, 12);
            func_08001848(frame.total, 7, 1);
            func_0803E488(message, 13);
            func_0803E488(D_0875AFB8, 16);
            func_0803E488(D_0875B068, 17);
            if (D_02007574[0] != 1)
                goto purchase_cancel_confirmation;
            if (D_02007574[1] == 0) {
                register u32 offset asm("r0") = (s32)selected_shifted >> 14;
                register u32 address asm("r1");
                register u32 scratch asm("r3");
                register u32 quantity asm("r2");
                u32 kind, inventory_kind;
                offset += shop_offset;
                scratch = (u32)D_0875BACC;
                offset += scratch;
                inventory_kind = *(const u8 *)offset;
                asm("" : "+l"(inventory_kind) : : "r2", "r3");
                if (inventory_kind == 0) {
                    address = *(const u8 *)(offset + 1);
                    offset = (u32)D_02003E61;
                    address += offset;
                    goto purchase_increment_inventory;
                }
                if (inventory_kind != 1)
                    goto purchase_debit_money;
                address = *(const u8 *)(offset + 1);
                scratch = (u32)D_02003E68;
                address += scratch;
            purchase_increment_inventory:
                offset = *(const u8 *)address;
                quantity = frame.quantity;
                offset += quantity;
                *(u8 *)address = offset;
            purchase_debit_money:
                scratch = (u32)&D_02001884;
                offset = *(const u32 *)scratch;
                address = frame.total;
                offset -= address;
                *(u32 *)scratch = offset;
                {
                    register const u8 *layout asm("r0") = D_0875AFB8;
                    asm("" : "+r"(layout) : : "r4", "r7");
                    func_0803E488(layout, 1);
                }
                {
                    register const u8 *layout asm("r0") = D_0875AFB8;
                    asm("" : "+r"(layout) : : "r4", "r7");
                    func_0803E488(layout, 26);
                }
                {
                    register const u8 *layout asm("r0") = D_0875AFB8;
                    asm("" : "+r"(layout) : : "r4", "r7");
                    func_0803E488(layout, 42);
                }
                {
                    register u32 *money asm("r2") = &D_02001884;
                    func_08001848(*money, 7, 0);
                }
                func_0803E488(D_0875B068, 1);
                {
                    register const u8 *layout asm("r0") = D_0875AFB8;
                    asm("" : "+r"(layout) : : "r4", "r7");
                    func_0803E488(layout, 4);
                }
                func_0803E488(D_0875B330, 5);
                asm("" : "+r"(selected_shifted));
                offset = (s32)selected_shifted >> 14;
                offset += shop_offset;
                scratch = (u32)D_0875BACC;
                offset += scratch;
                kind = *(const u8 *)offset;
                asm("" : "+l"(kind) : : "r1", "r2");
                if (kind == 0) {
                    offset = *(const u8 *)(offset + 1);
                    address = (u32)D_02003E61;
                    offset += address;
                    func_08001848(*(const u8 *)offset, 2, 0);
                } else if (kind == 1) {
                    offset = *(const u8 *)(offset + 1);
                    quantity = (u32)D_02003E68;
                    offset += quantity;
                    func_08001848(*(const u8 *)offset, 2, 0);
                }
                {
                    const u8 *summary = D_0875B330;
                    asm("" : "+r"(summary));
                    func_0803E488(summary, 6);
                    func_0803E488(summary, 14);
                }
            } else
                func_0803E488(message, 15);
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4", "r7");
                func_0803E488(layout, 24);
            }
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4", "r7");
                func_0803E488(layout, 25);
            }
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4", "r7");
                func_0803E488(layout, 37);
            }
            func_080019EC(65);
            {
                register u32 refresh asm("r3") = 1;
                asm("" : : "r"(refresh));
                frame.refresh = refresh;
            }
            state = 0x101;
            break;
        purchase_cancel_confirmation:
            func_080019EC(63);
        purchase_return_to_quantity:
            state = 0x110;
            break;
        }
        case 0x200:
        shop_state_200:
            func_0803E488(D_0875B330, 16);
            {
                register u32 zero asm("r0") = 0;
                register u32 previous asm("r1");
                asm("" : "+r"(zero));
                frame.page = zero;
                previous = 0xFFFF;
                asm("" : : "r"(previous));
                frame.previous = previous;
                previous_page = previous;
                {
                    register u16 *cursor asm("r0") = &D_02007588;
                    register u32 value asm("r2");
                    asm("" : "+r"(cursor));
                    value = (u32)&frame;
                    asm("" : "+r"(value));
                    value = *(u16 *)(value + 4);
                    asm("" : "+r"(value));
                    *cursor = value;
                }
                {
                    register u32 refresh asm("r3") = 0;
                    asm("" : : "r"(refresh));
                    frame.refresh = refresh;
                }
            }
        case 0x201:
        shop_state_201:
        {
            register u32 page_shifted asm("r6");
            func_0804E230();
        refresh_sale:
            {
                register u32 value asm("r0") = frame.page;
                register u32 previous asm("r1");
                register u32 old_page_shifted asm("r4");
                u32 refresh;
                page_shifted = value << 16;
                asm("" : "+r"(page_shifted));
                previous = previous_page;
                asm("" : "+r"(previous));
                old_page_shifted = previous << 16;
                refresh = frame.refresh;
                asm("" : "+l"(refresh) : : "r0", "r1", "r3");
                if (refresh != 2 && page_shifted == old_page_shifted)
                    goto sale_details;
                asm("" : "+m"(frame.refresh));
                {
                u32 redraw = frame.refresh;
                asm("" : "+l"(redraw) : : "r0", "r1", "r2");
                if (redraw) {
                    register const u8 *layout asm("r0") = D_0875AFB8;
                    asm("" : "+r"(layout));
                    func_0803E488(layout, 29);
                }
                }
                value = (s32)old_page_shifted >> 16;
                previous = -1;
                if (value != previous) {
                    register const u8 *layout asm("r0") = D_0875AFB8;
                    asm("" : "+r"(layout));
                    func_0803E488(layout, 4);
                }
            }
            {
                register u32 held_address asm("r4");
                register u8 *cursor asm("r10");
                u32 rows;
                register const u8 *names asm("r9");
                register const u8 *layout asm("r8");
                register u32 offset asm("r0");
                register u32 address asm("r1");
                register u32 scratch asm("r2");
                register u32 value asm("r3");
                held_address = (u32)&D_0200E780;
                scratch = (u32)&D_020082FD;
                asm("" : "+r"(scratch));
                cursor = (u8 *)scratch;
                asm("" : : "r"(cursor));
            rebuild_sale:
                rows = 0;
                asm("" : : "r"(rows) : "r5");
                offset = page_shifted << 2;
                value = offset >> 16;
                frame.last_index = value;
                offset = (s32)offset >> 16;
                address = *(const u8 *)held_address;
                asm("" : "+r"(address));
                if ((s32)offset >= (s32)address)
                    goto sale_list_finished;
                scratch = (u32)D_08676238;
                asm("" : "+r"(scratch));
                names = (const u8 *)scratch;
                asm("" : : "r"(names));
                value = (u32)D_0875AFB8;
                asm("" : "+r"(value));
                layout = (const u8 *)value;
                asm("" : : "r"(layout));
            sale_list_entry:
                {
                    register s32 index asm("r5");
                    held_address = (u32)D_0200E779;
                    address = frame.last_index;
                    offset = address << 16;
                    index = (s32)offset >> 16;
                    held_address = index + held_address;
                    func_0803E488(names, *(const u8 *)held_address);
                    func_0804D604(names, *(const u8 *)held_address, 8);
                    func_0803E488(layout, 40);
                    offset = *(const u8 *)held_address;
                    scratch = (u32)D_02003E61;
                    offset += scratch;
                    func_08001848(*(const u8 *)offset, 2, 2);
                    func_0803E488(layout, 42);
                    offset = *(const u8 *)held_address;
                    offset <<= 2;
                    value = (u32)D_0875BC1C;
                    offset += value;
                    offset = *(const u32 *)offset;
                    address = offset >> 31;
                    offset += address;
                    offset = (s32)offset >> 1;
                    func_08001848(offset, 7, 0);
                    func_0803E488(D_0875B068, 1);
                    offset = rows << 16;
                    offset = (s32)offset >> 16;
                    if ((s32)offset <= 2) {
                        offset = (u32)&D_0200E780;
                        offset = *(const u8 *)offset;
                        offset -= 1;
                        if (index < (s32)offset)
                            func_0803E488(D_08675C5C, 0);
                    }
                }
                offset = rows << 16;
                address = 0x10000;
                asm("" : "+r"(address));
                offset += address;
                rows = offset >> 16;
                address = (s32)offset >> 16;
                held_address = (u32)&D_0200E780;
                if ((s32)address > 3)
                    goto sale_list_finished;
                offset = (s32)page_shifted >> 14;
                offset = address + offset;
                offset <<= 16;
                scratch = offset >> 16;
                frame.last_index = scratch;
                offset = (s32)offset >> 16;
                address = *(const u8 *)held_address;
                asm("" : "+r"(address));
                if ((s32)offset < (s32)address)
                    goto sale_list_entry;
            sale_list_finished:
                {
                u32 row_count;
                offset = rows << 16;
                row_count = (s32)offset >> 16;
                asm("" : "+l"(row_count) : : "r1", "r2", "r3");
                if (row_count == 0) {
                    value = frame.page;
                    offset = value << 16;
                    address = 0xFFFF0000;
                    asm("" : "+r"(address));
                    offset += address;
                    offset >>= 16;
                    asm("" : : "r"(offset));
                    frame.page = offset;
                    scratch = offset << 16;
                    offset = (s32)scratch >> 16;
                    value = (u32)D_020075A0;
                    address = -1;
                    if (offset != address) {
                        address = (u32)&D_02007588;
                        offset = 3;
                        *cursor = offset;
                        *(u16 *)address = offset;
                        page_shifted = scratch;
                        asm("" : "+r"(page_shifted));
                        goto rebuild_sale;
                    }
                } else {
                    address = (u32)&D_02007588;
                    value = (u32)D_020075A0;
                    scratch = *(u16 *)address;
                    if ((s32)row_count <= (s32)scratch) {
                        offset = rows - 1;
                        scratch = (u32)cursor;
                        *(u8 *)scratch = offset;
                        offset <<= 24;
                        offset >>= 24;
                        *(u16 *)address = offset;
                    }
                }
                }
                offset = 0xD5F;
                scratch = value + offset;
                value = 0;
                asm("" : : "r"(value));
                offset = 0;
                *(u8 *)scratch = offset;
                address = frame.page;
                offset = address << 16;
                asm("" : "+r"(offset));
                page_shifted = offset;
                asm("" : "+r"(page_shifted));
                if ((s32)page_shifted > 0) {
                    offset = 1;
                    *(u8 *)scratch = offset;
                }
                offset = frame.last_index;
                address = offset << 16;
                address = (s32)address >> 16;
                offset = *(const u8 *)held_address;
                offset -= 1;
                if ((s32)address < (s32)offset) {
                    offset = *(u8 *)scratch;
                    address = 2;
                    offset |= address;
                    *(u8 *)scratch = offset;
                }
                address = page_shifted >> 16;
                asm("" : : "r"(address));
                previous_page = address;
            }
        sale_details:
            {
                register u32 value asm("r0");
                register u32 address asm("r1");
                register u32 other asm("r2");
                register u32 scratch asm("r3");
                u32 page;
                page = (s32)page_shifted >> 16;
                asm("" : "+l"(page) : : "r1", "r2", "r3");
                scratch = 0xFFFF0000;
                asm("" : "+r"(scratch));
                other = (s32)scratch >> 16;
                asm("" : "+r"(other));
                if (page == other)
                    goto sale_read_exit;
                value = page;
                address = (u32)&D_02007588;
                asm("" : "+r"(address), "+r"(value));
                value <<= 2;
                address = *(const u16 *)address;
                value += address;
                value <<= 16;
                value >>= 16;
                asm("" : : "r"(value));
                frame.selected = value;
                value = frame.previous;
                address = value << 16;
                {
                    u32 refresh = frame.refresh;
                    asm("" : "+l"(refresh) : "r"(address), "r"(other) : "r0");
                    if (refresh)
                        goto sale_redraw_details;
                }
                scratch = frame.selected;
                value = scratch << 16;
                if (value == address)
                    goto sale_handle_keys;
            sale_redraw_details:
                value = (s32)address >> 16;
                if (value != other) {
                    register const u8 *script asm("r0") = D_0875AFB8;
                    asm("" : "+r"(script) : : "r4", "r7");
                    func_0803E488(script, 0);
                }
                {
                    register const u8 *script asm("r0") = D_0875AFB8;
                    asm("" : "+r"(script) : : "r4", "r7");
                    func_0803E488(script, 25);
                }
                {
                    register u32 selected_shifted asm("r4");
                    address = (u32)D_0200E779;
                    value = frame.selected;
                    selected_shifted = value << 16;
                    asm("" : "+r"(selected_shifted));
                    value = (s32)selected_shifted >> 16;
                    value += address;
                    address = *(const u8 *)value;
                    value = (u32)D_08676350;
                    func_0803E488((const void *)value, address);
                    {
                        register const u8 *script asm("r0") = D_0875AFB8;
                        asm("" : "+r"(script) : : "r7");
                        func_0803E488(script, 24);
                    }
                    selected_shifted >>= 16;
                    asm("" : : "r"(selected_shifted));
                    frame.previous = selected_shifted;
                    address = 0;
                    asm("" : : "r"(address));
                    frame.refresh = address;
                }
            sale_handle_keys:
                {
                    register const u8 *script asm("r0") = D_0875AFB8;
                    asm("" : "+r"(script) : : "r4", "r7");
                    func_0803E488(script, 35);
                }
                address = (u32)D_02007574;
                value = *(const u16 *)address;
                if (value <= 1)
                    goto sale_read_exit;
                if (value == 2)
                    goto sale_previous_page;
                if (value == 4)
                    goto sale_next_page;
                goto refresh_sale;
            sale_previous_page:
                {
                    register s32 previous asm("r4");
                    other = frame.page;
                    asm("" : "+r"(other));
                    value = other << 16;
                    previous = (s32)value >> 16;
                    if (previous <= 0)
                        goto refresh_sale;
                    func_080019EC(64);
                    value = previous - 1;
                    value <<= 16;
                    goto sale_store_page;
                }
            sale_next_page:
                scratch = frame.last_index;
                address = scratch << 16;
                address = (s32)address >> 16;
                value = (u32)&D_0200E780;
                value = *(const u8 *)value;
                value -= 1;
                if ((s32)address >= (s32)value)
                    goto refresh_sale;
                func_080019EC(64);
                address = frame.page;
                value = address << 16;
                other = 0x10000;
                asm("" : "+r"(other));
                value += other;
            sale_store_page:
                value >>= 16;
                asm("" : : "r"(value));
                frame.page = value;
                goto refresh_sale;
            }
        sale_read_exit:
            asm("" : "+r"(page_shifted));
            {
                u32 action = D_02007574[0];
                asm("" : "+l"(action) : : "r1", "r2", "r3");
                if (action == 0)
                    goto sale_cancel;

                else {
                    register s32 page asm("r1") = (s32)page_shifted >> 16;
                    register s32 minus_one asm("r0") = -1;
                    asm("" : "+r"(page), "+r"(minus_one));
                    if (page != minus_one)
                        goto sale_accept_item;
                    goto sale_close;
                }
            }
        sale_cancel:
            func_080019EC(63);
        sale_close:
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4", "r7");
                func_0803E488(layout, 13);
            }
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4", "r7");
                func_0803E488(layout, 12);
            }
            {
                register const u8 *layout asm("r0") = D_0875AFB8;
                asm("" : "+r"(layout) : : "r4", "r7");
                func_0803E488(layout, 0);
            }
            asm("" : "+r"(page_shifted));
            {
                register s32 page asm("r1") = (s32)page_shifted >> 16;
                register s32 minus_one asm("r0") = -1;
                asm("" : "+r"(page), "+r"(minus_one));
                if (page != minus_one)
                    goto return_to_shop_menu;
            }
            func_0803E488(D_0875B330, 3);
            func_080019EC(65);
            goto return_to_shop_menu;
        sale_accept_item:
            frame.saved_cursor = D_02007588;
            goto enter_sale_quantity;
        }
        case 0x210:
        shop_state_210:
        {
            func_0803E488(D_0875B330, 17);
            {
                register u32 address asm("r1") = (u32)D_0200E779;
                register u32 selected asm("r3");
                register u32 offset asm("r0");
                selected = frame.selected;
                offset = selected << 16;
                offset = (s32)offset >> 16;
                offset += address;
                offset = *(const u8 *)offset;
                address = (u32)D_02003E61;
                offset += address;
                address = *(const u8 *)offset;
                if ((u8)func_0805354C(1, address, 2)) {
                    frame.quantity = D_030022FC;
                    state = 0x220;
                    break;
                }
            }
            sale_refresh.word = 1;
            goto sale_restore_cursor;
        }
        case 0x220:
        shop_state_220:
        {
            register s32 quantity asm("r4");
            register const u8 *slot asm("r5");
            register const u8 *layout asm("r6");
            const u8 *message;
            register const u8 *selection asm("r8");
            {
                register u32 offset asm("r0") = frame.quantity;
                register u32 address asm("r1");
                register u32 selected asm("r2");
                register u32 scratch asm("r3");
                quantity = offset << 16;
                asm("" : "+r"(quantity));
                quantity >>= 16;
                address = (u32)D_0200E779;
                selected = frame.selected;
                offset = selected << 16;
                offset = (s32)offset >> 16;
                slot = (const u8 *)(offset + address);
                offset = *slot;
                offset <<= 2;
                scratch = (u32)D_0875BC1C;
                offset += scratch;
                offset = *(const u32 *)offset;
                offset *= quantity;
                address = offset >> 31;
                offset += address;
                offset = (s32)offset >> 1;
                frame.total = offset;
            }
            layout = D_0875AFB8;
            asm("" : "+r"(layout));
            func_0803E488(layout, 0);
            func_0803E488(layout, 25);
            {
                register u32 item asm("r1") = *slot;
                asm("" : "+r"(item));
                func_0803E488(D_08676238, item);
            }
            message = D_0875B330;
            asm("" : "+r"(message));
            func_0803E488(message, 11);
            func_08001848(quantity, 2, 1);
            func_0803E488(message, 12);
            func_08001848(frame.total, 7, 1);
            func_0803E488(message, 18);
            func_0803E488(layout, 16);
            {
                register const u8 *address asm("r0") = D_0875B068;
                asm("" : "+r"(address));
                selection = address;
                asm("" : : "r"(selection));
                func_0803E488(address, 17);
            }
            if (D_02007574[0] != 1)
                goto sale_cancel_confirmation;
            if (D_02007574[1] == 0) {
                register u32 offset asm("r0") = *slot;
                register u32 address asm("r1");
                register u32 count asm("r2");
                register u32 scratch asm("r3");
                register u32 *money asm("r4");
                address = (u32)D_02003E61;
                offset += address;
                address = *(const u8 *)offset;
                count = frame.quantity;
                address -= count;
                *(u8 *)offset = address;
                scratch = (u32)D_02000B5C;
                {
                    register union RegisterWord money_offset asm("r0");
                    money_offset.word = 0xD28;
                    money = (u32 *)(scratch + money_offset.word);
                }
                offset = *money;
                address = frame.total;
                offset += address;
                *money = offset;
                address = 9999999;
                if (offset > address)
                    *money = address;
                func_0803E488(layout, 1);
                func_0803E488(layout, 26);
                func_0803E488(layout, 42);
                func_08001848(*money, 7, 0);
                func_0803E488(selection, 1);
                func_0803E488(message, 14);
            } else
                func_0803E488(message, 15);
            {
                register const u8 *address asm("r0");
                ((const u8 *volatile)address) = D_0875AFB8;
                func_0803E488((const u8 *volatile)address, 24);
            }
            {
                register const u8 *address asm("r0");
                ((const u8 *volatile)address) = D_0875AFB8;
                func_0803E488((const u8 *volatile)address, 25);
            }
            {
                register const u8 *address asm("r0");
                ((const u8 *volatile)address) = D_0875AFB8;
                func_0803E488((const u8 *volatile)address, 37);
            }
            func_080019EC(65);
            sale_refresh.word = 2;
        sale_restore_cursor:
            {
                frame.refresh = sale_refresh.word;
            }
            {
                register u16 *cursor asm("r0");
                register u32 saved asm("r3");
                ((u16 *volatile)cursor) = &D_02007588;
                ((volatile u32)saved) = (u32)&frame;
                ((volatile u32)saved) = *(u16 *)((volatile u32)saved + 16);
                *((u16 *volatile)cursor) = (volatile u32)saved;
            }
            state = 0x201;
            break;
        }
        cancel_purchase:
            func_080019EC(63);
            {
                register const u8 *layout asm("r0");
                ((const u8 *volatile)layout) = D_0875AFB8;
                func_0803E488((const u8 *volatile)layout, 13);
            }
            {
                register const u8 *layout asm("r0");
                ((const u8 *volatile)layout) = D_0875AFB8;
                func_0803E488((const u8 *volatile)layout, 12);
            }
            {
                register const u8 *layout asm("r0");
                ((const u8 *volatile)layout) = D_0875AFB8;
                func_0803E488((const u8 *volatile)layout, 0);
            }
            goto return_to_shop_menu;
        sale_cancel_confirmation:
            func_080019EC(63);
        enter_sale_quantity:
            state = 0x210;
            break;
        }
    dispatch_shop_done:;
    }
    if ((s16)state >= 0)
        goto dispatch_shop_state;
    func_08003DF8(10, func_08004034);
    {
        register u8 *base asm("r1") = D_02000034;
        register u32 offset asm("r0") = 0x558;
        register u32 address asm("r2");
        register u32 scratch asm("r3");
        asm("" : "+r"(base), "+r"(offset));
        address = (u32)base + offset;
        asm("" : "+r"(address));
        offset = 1;
        asm("" : "+r"(offset));
        *(u32 *)address = offset;
        scratch = 0x55C;
        asm("" : "+r"(scratch));
        address = (u32)base + scratch;
        asm("" : "+r"(address));
        offset = 0;
        asm("" : "+r"(offset));
        *(u32 *)address = offset;
        offset = 0x568;
        asm("" : "+r"(offset));
        base += offset;
        asm("" : "+r"(base));
        if (*(u32 *)base != 1) {
            u32 *flag = (u32 *)base;
            do {
                func_0805EE78(1);
            } while (*flag != 1);
        }
    }
    func_08003E3C(10);
    func_08003E3C(5);
    {
        register u32 base asm("r2") = (u32)D_02000034;
        register u32 offset asm("r0");
        register u32 selected asm("r1");
        asm("" : "+r"(base));
        offset = (u32)&D_02000030;
        asm("" : "+r"(offset));
        selected = *(const u8 *)offset;
        asm("" : "+r"(selected));
        offset = selected * 136;
        asm("" : "+r"(offset));
        base += 8;
        asm("" : "+r"(base));
        offset += base;
        asm("" : "+r"(offset));
        selected = (s16)state;
        asm("" : "+r"(selected));
        *(u32 *)offset = selected;
    }
}
