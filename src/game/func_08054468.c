#include "types.h"
typedef unsigned long long u64;
union RegisterWord { u32 word; u64 wide; };
union SignedRegisterWord { u32 word; s16 halves[2]; };

struct Task {
    u8 pad_0[8];
    s32 result;
    u32 parameter;
    u8 pad_10[8];
    u32 busy;
    u8 pad_1C[108];
};
struct Item {
    u32 name;
    u32 price;
    u8 pad_8[16];
};
extern struct Task D_02000034[];
extern u8 D_02000030, D_0200E6DE, D_020082FD, D_020082FF;
extern u8 D_0200E648[], D_02003EA8[], D_02000B5C[];
extern u16 D_02007574[], D_02007588;
extern u8 D_020075A0[0xD60];
extern u32 D_02001884;
extern const u16 D_0875BD38[][4];
extern const u8 D_0866634C[];
extern const struct Item D_0866C754[];
extern const u8 D_0875BA9C[], D_08675BEC[], D_0875B37C[];
extern const u8 D_0875B068[], D_0875AFB8[], D_08675C5C[];
void func_08000DB8(void);
void func_08000D1C(u32);
void func_08001A54(const void *, u32, u32);
void func_0803E024(u32, u32, u32);
void func_08003DF8(u32, void (*)(void));
void func_08053524(void);
void func_08004034(void);
void func_0803E488(const void *, u32);
void func_08001848(u32, u32, u32);
void func_0805EE78(u32);
void func_080019EC(u32);
void func_0804E1B8(u32);
void func_0804D604(const void *, u32, u32);
void func_080543F4(s32);
void func_08003E3C(u32);

void func_08054468(void)
{
    volatile u32 frame[9];
    register s32 list_index asm("r6");
    register u32 loop_index_value asm("r4");
    u16 state;
    u16 row;
    s16 selected;
    s16 page;
    s16 previous;
    const u16 *entry;
    register const struct Item *item asm("r10");
    u32 price;
    register u32 phase_base asm("r5") = (u32)D_02000034;

    {
        register u8 *current asm("r0") = &D_02000030;
        register u32 task_index asm("r1");
        register u32 offset asm("r0");
        register u32 parameters asm("r1");
        asm volatile("" : "=r"(list_index), "=r"(loop_index_value) : "r"(phase_base), "r"(current));
        task_index = *current;
        offset = task_index * 136;
        parameters = phase_base + 12;
        frame[0] = *(u32 *)(offset + parameters);
    }
    func_08000DB8();
    func_08000D1C(0);
    *(volatile u16 *)0x04000000 = 0x1D40;
    {
        register volatile u16 *destination asm("r1") = (volatile u16 *)0x0400000C;
        register u32 config asm("r3");
        register u32 copy asm("r0");
        config = 0x38B;
        copy = config;
        asm("" : : "r"(config), "r"(copy));
        *destination = copy;
    }
    {
        register volatile u16 *destination asm("r1") = (volatile u16 *)0x0400000E;
        register u32 config asm("r4");
        register u32 copy asm("r0");
        config = 0x48B;
        copy = config;
        asm("" : : "r"(config), "r"(copy));
        *destination = copy;
    }
    func_08001A54(D_0875BA9C, 0, 1);
    func_08001A54(D_0875BA9C, 1, 1);
    func_08001A54(D_0875BA9C, 2, 1);
    func_08001A54(D_0875BA9C, 3, 1);
    func_0803E024(3, 0, 255);
    func_08003DF8(5, func_08053524);
    func_08003DF8(10, func_08004034);
    {
        register u32 offset asm("r1") = 0x558;
        register u32 address asm("r0");
        register u32 zero asm("r1");
        register u32 parameter_offset asm("r2");
        asm("" : : "r"(offset));
        address = phase_base + offset;
        zero = 0;
        asm("" : : "r"(address), "r"(zero));
        *(u32 *)address = zero;
        parameter_offset = 0x55C;
        asm("" : : "r"(phase_base), "r"(parameter_offset));
        phase_base += parameter_offset;
        *(u32 *)phase_base = zero;
    }
    state = 0;
dispatch:
    switch ((s16)state)
    {
    case 0:
        {
        register const u8 *text asm("r4");
        func_0803E488(D_08675BEC, 1);
        func_0803E488(D_0875B37C, 0);
        text = D_0875B068;
        func_0803E488(text, 0);
        {
            register const u8 *script asm("r0") = D_0875AFB8;
            asm("" : : "r"(script) : "r6", "r7");
            func_0803E488(script, 42);
        }
        {
            register u32 *money asm("r3") = &D_02001884;
            asm("" : : "r"(money));
            func_08001848(*money, 7, 0);
        }
        func_0803E488(text, 1);
        func_0803E488(D_0875AFB8, 24);
        {
            register u32 base asm("r0") = (u32)D_02000034;
            register u32 offset asm("r4") = 0x568;
            register u32 *busy asm("r1");
            busy = (u32 *)(base + offset);
            asm("" : : "r"(base), "r"(offset), "r"(busy));
            if (*busy != 1)
            {
                register u32 *waiting asm("r4") = busy;
                do { func_0805EE78(1); } while (*waiting != 1);
            }
        }
        func_0803E488(D_0875B37C, 1);
        }
    case 0x20:
        {
        register const u8 *prompt asm("r4") = D_0875B37C;
        func_0803E488(prompt, 2);
        if (!D_02007574[0])
        {
            func_080019EC(63);
            state = 0xFFFF;
            break;
        }
        if (D_02007574[1] == 1)
        {
            func_0804E1B8(15);
            if (!D_0200E6DE)
            {
                func_080019EC(79);
                func_0803E488(prompt, 3);
                func_080019EC(65);
        choose_action:
                {
                    register u32 next asm("r2") = 0x20;

                    state = next;
                }
                break;
            }
        }
        func_0803E488(D_0875AFB8, 0);
        {
            register union RegisterWord increment asm("r1");
            register u32 shifted asm("r0");
            shifted = (u32)D_02007574[1] << 24;
            increment.word = 0x01000000;
            state = (u16)((shifted + increment.word) >> 16);
        }
        break;
        }
    case 0x100:
        {
        register u16 offer_row asm("r3");
        register u32 shop_offset asm("r7");
        register const u16 *offers asm("r8");
        register const u8 *names asm("r9");
        register u32 shifted_row asm("r5");
        register s32 signed_row asm("r6");
        register const u16 *offer asm("r4");
        register u32 next asm("r0");
        func_0803E488(D_0875B37C, 4);
        offer_row = 0;
        {
            register u32 shop asm("r2") = frame[0];
            register u32 offset asm("r0");
            register const u16 *base asm("r4");
            register const u16 *first asm("r1");
            register u32 id asm("r1");
            register u32 end asm("r2");
            offset = shop * 8;
            base = &D_0875BD38[0][0];
            first = (const u16 *)(offset + (u32)base);
            id = *first;
            end = 0xFFFF;
            shop_offset = offset;

            if (id == end) goto offers_finished;
            {
                register u64 copy asm("r0") = (u32)base;
                register u64 name_copy asm("r1");
                offers = (const u16 *)(u32)copy;
                name_copy = (u32)D_0866634C;
                names = (const u8 *)(u32)name_copy;
            }
        }
    offer_loop:
        {
            shifted_row = (u32)offer_row << 16;
            signed_row = (s32)shifted_row >> 16;
            offer = (const u16 *)(signed_row * 2 + shop_offset + (u32)offers);
            {
                register u32 id asm("r1") = *offer;
                register const struct Item *base asm("r2");
                register u32 byte_offset asm("r0") = id * 24;
                register const struct Item *copy asm("r0");
                base = D_0866C754;
                copy = (const struct Item *)byte_offset;
                copy = (const struct Item *)((u32)copy + (u32)base);
                item = copy;
                func_0803E488(names, id);
            }
            func_0804D604(names, *offer, 9);
            {
                register const struct Item *price_record asm("r2") = item;
                func_08001848(price_record->price, 7, 0);
            }
            func_0803E488(D_0875B068, 1);
            if (signed_row <= 2)
            {
                register s32 next_row asm("r0") = signed_row + 1;
                register const u16 *address asm("r0");
                register u32 id asm("r0");
                register u32 end asm("r3");
                address = (const u16 *)(next_row * 2 + shop_offset + (u32)offers);
                id = *address;
                end = 0xFFFF;

                if (id != end) func_0803E488(D_08675C5C, 0);
            }
            {
                register union RegisterWord increment asm("r4");
                register s32 normalized asm("r0");
                register const u16 *next_offer asm("r0");
                register u32 next_id asm("r0");
                register u32 end asm("r1");
                increment.word = 0x10000;
                next = shifted_row + increment.word;
                offer_row = next >> 16;
                normalized = (s32)next >> 16;
                if (normalized > 3) goto offers_finished;
                next_offer = (const u16 *)(normalized * 2 + shop_offset + (u32)offers);
                next_id = *next_offer;
                end = 0xFFFF;
                if (next_id != end) goto offer_loop;
            }
        }
    offers_finished:
        {
            register u16 *cursor asm("r1") = &D_02007588;
            register u32 zero asm("r0") = 0;
            register u32 selection asm("r2");
            register u32 previous asm("r3");
            register u32 refresh asm("r4");
            *cursor = zero;
            selection = 0;
            frame[3] = selection;
            previous = 0xFFFF;
            frame[4] = previous;
            refresh = 0;
            frame[6] = refresh;

        }
        }
    case 0x101:
        {
        register u32 selected_shift asm("r6");
        register u32 previous_shift asm("r1");
        register u32 selected_value asm("r2");
        register u32 refresh asm("r3");
        register const u16 *chosen asm("r4");
        register const u8 *description asm("r5");
    buy_select:
        {
            register u32 previous_value asm("r0") = frame[4];
            previous_shift = previous_value << 16;
            selected_value = frame[3];
            selected_shift = selected_value << 16;
            refresh = frame[6];

            if (!refresh && previous_shift == selected_shift) goto buy_input;
        }
    buy_refresh:
        {
            register s32 previous_signed asm("r0") = (s32)previous_shift >> 16;
            register s32 invalid asm("r4") = -1;
            if (previous_signed != invalid)
            {
                {
                    register const u8 *script asm("r0") = D_0875AFB8;
                    func_0803E488(script, 0);
                }
                {
                    register const u8 *script asm("r0") = D_0875AFB8;
                    func_0803E488(script, 4);
                }
            }
        }
        description = D_0875B37C;
        func_0803E488(description, 5);
        {
            register u32 row_offset asm("r4") = (s32)selected_shift >> 15;
            register u32 shop asm("r1");
            register u32 shop_offset asm("r0");
            register const u16 *base asm("r2");
            shop = frame[0];
            shop_offset = shop * 8;
            row_offset += shop_offset;
            base = &D_0875BD38[0][0];
            chosen = (const u16 *)(row_offset + (u32)base);
            {
                register u32 id asm("r0") = *chosen;
                register const u8 *counts asm("r3");
                counts = D_02003EA8;
                func_08001848(*(const u8 *)(id + (u32)counts), 1, 0);
            }
        }
        func_0803E488(description, 6);
        {
            register u32 hold asm("r2");
            register s32 id asm("r0");
            id = *(const s16 *)chosen;
            func_080543F4(id);
        }
        func_0803E488(D_0875AFB8, 24);
        selected_shift >>= 16;
        frame[4] = selected_shift;
        {
            register u32 refresh asm("r2") = 0;
            frame[6] = refresh;
        }
    buy_input:
        {
            register const u8 *script asm("r0") = D_0875AFB8;
            func_0803E488(script, 35);
        }
        frame[3] = D_02007588;
        if (D_02007574[0] > 1) goto buy_select;
        if (!D_02007574[0]) goto close_menu;
        {
            register u32 selected_value asm("r3") = frame[3];
            register u32 shifted asm("r2");
            register u32 offset asm("r0");
            register u32 shop asm("r4");
            register u32 shop_offset asm("r1");
            register const u16 *base asm("r1");
            register u32 id asm("r3");
            register const struct Item *record_base asm("r1");
            register const struct Item *record asm("r0");
            shifted = selected_value << 16;
            offset = (s32)shifted >> 15;
            shop = frame[0];
            shop_offset = shop * 8;
            offset += shop_offset;

            base = &D_0875BD38[0][0];
            id = *(const u16 *)(offset + (u32)base);
            record = (const struct Item *)(id * 24);
            record_base = D_0866C754;
            record = (const struct Item *)((u32)record + (u32)record_base);
            item = record;

            {
                register u32 price asm("r1") = record->price;
                register u32 *money asm("r4") = &D_02001884;
                register u32 amount asm("r0");
                amount = *money;
                selected_shift = shifted;

                if (price > amount)
                {
                    func_080019EC(79);
                    func_0803E488(D_0875B37C, 7);
                    func_080019EC(65);
                    {
                        register u32 value asm("r0") = frame[4];
                        previous_shift = value << 16;
                    }
                    goto buy_refresh;
                }
            }
            {
            register const u8 *counts asm("r1") = D_02003EA8;
            register u32 count asm("r0");
            {
                register const u8 *address asm("r0") = (const u8 *)(id + (u32)counts);
                count = *address;
            }
            if (count == 9)
            {
                func_080019EC(79);
                func_0803E488(D_0875B37C, 8);
                func_080019EC(65);
                {
                    register u32 value asm("r2") = frame[4];
                    previous_shift = value << 16;
                }
                goto buy_refresh;
            }
        }
        }
        state = 0x120;
        break;
        }
    case 0x120:
        {
        register u32 purchase_price asm("r6");
        register const u8 *script asm("r5");
        register const u8 *prompt asm("r7");
        register const struct Item *records asm("r8");
        register const u8 *text asm("r9");
        register const u16 *chosen asm("r4");
        {
            register const struct Item *price_record asm("r3") = item;
            purchase_price = price_record->price;
        }
        script = D_0875AFB8;
        func_0803E488(script, 0);
        func_0803E488(script, 25);
        {
            register u32 selected_value asm("r4") = frame[3];
            register u32 row_offset asm("r0");
            register u32 shop asm("r2");
            register u32 offset asm("r1");
            register const u16 *offers asm("r3");
            row_offset = (s32)(selected_value << 16) >> 15;
            shop = frame[0];
            offset = shop * 8;
            row_offset += offset;

            offers = &D_0875BD38[0][0];
            chosen = (const u16 *)(row_offset + (u32)offers);
        }
        {
            register u32 id asm("r1") = *chosen;
            register const u8 *names asm("r0");
            names = D_0866634C;
            func_0803E488(names, id);
        }
        prompt = D_0875B37C;
        func_0803E488(prompt, 9);
        {
            register u32 id asm("r1") = *chosen;
            register u32 offset asm("r0");
            register u64 base asm("r1");
            offset = id * 24;
            base = (u32)D_0866C754;
            records = (const struct Item *)(u32)base;
            item = (const struct Item *)(offset + (u32)records);
        }
        func_08001848(purchase_price, 7, 1);
        func_0803E488(prompt, 10);
        func_0803E488(script, 16);
        {
            register u64 copy asm("r2") = (u32)D_0875B068;
            text = (const u8 *)(u32)copy;
            func_0803E488(text, 17);
        }
        if (D_02007574[0] == 1)
        {
            if (!D_02007574[1])
            {
                {
                    register u32 id asm("r1") = *chosen;
                    register u8 *counts asm("r3");
                    register u8 *address asm("r1");
                    register u32 count asm("r0");
                    counts = D_02003EA8;
                    address = (u8 *)(id + (u32)counts);
                    count = *address;
                    count++;
                    *address = count;
                }
                item = (const struct Item *)((u32)records + *chosen * 24);
                {
                    register u32 *money asm("r1") = &D_02001884;
                    register u32 amount asm("r0");
                    amount = *money - purchase_price;
                    *money = amount;
                }
                func_0803E488(script, 1);
                func_0803E488(script, 26);
                func_0803E488(script, 42);
                {
                    register u32 *money asm("r2") = &D_02001884;
                    func_08001848(*money, 7, 0);
                }
                func_0803E488(text, 1);
                func_0803E488(script, 4);
                func_0803E488(prompt, 5);
                {
                    register u32 id asm("r0") = *chosen;
                    register u8 *counts asm("r3");
                    counts = D_02003EA8;
                        func_08001848(*(u8 *)(id + (u32)counts), 1, 0);
                }
                func_0803E488(prompt, 6);
                func_0803E488(prompt, 11);
            }
            else func_0803E488(prompt, 12);

            {
                register const u8 *finish asm("r0") = D_0875AFB8;
                func_0803E488(finish, 24);
            }
            {
                register const u8 *finish asm("r0") = D_0875AFB8;
                func_0803E488(finish, 25);
            }
            {
                register const u8 *finish asm("r0") = D_0875AFB8;
                func_0803E488(finish, 37);
            }
            func_080019EC(65);
        }
        else func_080019EC(63);
        {
            register u32 refresh asm("r4") = 1;
            frame[6] = refresh;
        }
        state = 0x101;
        break;
        }
    case 0x200:
        func_0803E488(D_0875B37C, 13);
        {
            register u32 zero asm("r0") = 0;
            register u32 previous asm("r1");
            register u16 *cursor asm("r0");
            register const volatile u8 *page_address asm("r2");
            register u32 page_value asm("r2");
            register u32 refresh asm("r3");
            frame[1] = zero;
            previous = 0xFFFF;
            frame[4] = previous;
            frame[2] = previous;
            cursor = &D_02007588;
            page_address = (const volatile u8 *)&frame;
            page_value = *(const volatile u16 *)(page_address + 4);
            *cursor = page_value;
            refresh = 0;
            frame[6] = refresh;

        }
    case 0x201:
        {
        register u32 sell_row asm("r3");
        register const u8 *inventory_count asm("r6");
        register u32 page_shift asm("r7");
        register u32 previous_shift asm("r4");
        register u32 initial_refresh asm("r1");
        register u8 *window_base asm("r4");
        func_0804E1B8(15);
sell_select:
        {
            register u32 prior_value asm("r0");
            previous_shift = frame[1];
            page_shift = previous_shift << 16;
            prior_value = frame[2];
            previous_shift = prior_value << 16;
            initial_refresh = frame[6];
        }
        if (initial_refresh == 2 || page_shift != previous_shift)
        {
            {
                register u32 refresh asm("r2") = frame[6];
                    if (refresh) func_0803E488(D_0875AFB8, 29);
            }
            {
                register s32 prior asm("r0") = (s32)previous_shift >> 16;
                register s32 invalid asm("r3") = -1;

                if (prior != invalid) func_0803E488(D_0875AFB8, 4);
            }

            inventory_count = &D_0200E6DE;
sell_page:
            {
            register const u8 *names asm("r9");
            register const u8 *script asm("r8");
            register const u8 *listing asm("r4");

            register union RegisterWord page_count asm("r1");
            sell_row = 0;
            {
                register u32 shifted asm("r0") = page_shift << 2;
                previous_shift = shifted >> 16;
                frame[7] = previous_shift;
                {
                    register s32 index asm("r0") = (s32)shifted >> 16;
                    page_count.word = *inventory_count;
                    if (index >= (s32)page_count.word) goto sale_rows_finished;
                }
            }
            {
                {
                    register const u8 *name_copy asm("r2") = D_0866634C;
                    names = (const u8 *)(u32)name_copy;
                    {
                        register u64 script_copy asm("r4") = (u32)D_0875AFB8;
                        script = (const u8 *)(u32)script_copy;
                    }
                }
            sale_row_loop:
                {
                    {
                        register const u8 *base asm("r4") = D_0200E648;
                        register u32 index_value asm("r1");
                        register u32 shifted asm("r0");
                        register u32 id asm("r1");
                        register const u8 *name_arg asm("r0");
                        index_value = frame[7];
                        shifted = index_value << 16;
                        list_index = (s32)shifted >> 16;

                        listing = (const u8 *)(list_index + (u32)base);
                        id = *listing;
                        name_arg = names;

                        frame[8] = sell_row;
                        func_0803E488(name_arg, id);
                    }
                    func_0804D604(names, *listing, 8);
                    func_0803E488(script, 40);
                    {
                        register u32 id asm("r0") = *listing;
                        register const u8 *counts asm("r2");
                        counts = D_02003EA8;
                                func_08001848(*(const u8 *)(id + (u32)counts), 1, 0);
                    }
                    func_0803E488(script, 42);
                    item = &D_0866C754[*listing];
                    func_08001848(item->price >> 1, 7, 0);
                    func_0803E488(D_0875B068, 1);
                    sell_row = frame[8];
                    if ((s16)sell_row <= 2 && list_index < D_0200E6DE - 1)
                    {
                        func_0803E488(D_08675C5C, 0);
                        sell_row = frame[8];
                    }
                    {
                        register u32 shifted asm("r0") = sell_row << 16;
                        register union RegisterWord increment asm("r3");
                        register s32 signed_row asm("r5");

                        register s32 index asm("r0");
                        register u32 count asm("r1");
                        increment.word = 0x10000;
                        shifted += increment.word;
                        sell_row = shifted >> 16;
                        signed_row = (s32)shifted >> 16;
                        inventory_count = &D_0200E6DE;

                        if (signed_row > 3) goto sale_rows_finished;
                        index = signed_row + ((s32)page_shift >> 14);
                        shifted = (u32)index << 16;
                        loop_index_value = shifted >> 16;
                        frame[7] = loop_index_value;
                        index = (s32)shifted >> 16;
                        count = *inventory_count;

                        if (index < (s32)count) goto sale_row_loop;
                    }
                }
            }
    sale_rows_finished:
            }
            {
            s32 rows = (s16)sell_row;
            if (!rows)
            {
                register u32 value asm("r1") = frame[1];
                register u32 shifted asm("r0");
                register u32 decrement asm("r2");
                register u32 adjusted asm("r2");
                register s32 normalized asm("r0");
                register s32 invalid asm("r3");
                shifted = value << 16;
                decrement = 0xFFFF0000;

                shifted += decrement;
                shifted >>= 16;
                frame[1] = shifted;
                adjusted = shifted << 16;
                normalized = (s32)adjusted >> 16;
                window_base = D_020075A0;
                invalid = -1;

                if (normalized != invalid)
                {
                    register u16 *cursor asm("r1") = &D_02007588;
                    register u32 three asm("r0");
                    register u8 *cursor_byte asm("r4");
                    three = 3;
                    cursor_byte = &D_020082FD;

                    *cursor_byte = three;
                    *cursor = three;
                    page_shift = adjusted;
                    goto sell_page;
                }
            }
            else
            {
                register u16 *cursor asm("r1") = &D_02007588;
                register u32 current asm("r2");
                window_base = D_020075A0;
                current = *cursor;

                if (rows <= (s32)current)
                {
                    register u32 last asm("r0") = sell_row - 1;
                    register u8 *cursor_byte asm("r3");
                    cursor_byte = &D_020082FD;

                    *cursor_byte = last;
                    *cursor = (u8)last;
                }
            }
            }
            {
                register u32 offset asm("r0") = 0xD5F;
                register u8 *flags asm("r2");
                register u32 scratch asm("r3");
                register u32 zero asm("r0");
                flags = window_base + offset;
                scratch = 0;

                zero = 0;
                *flags = zero;
                {
                    register u32 page_value asm("r1") = frame[1];
                    register u32 shifted asm("r0");
                    shifted = page_value << 16;
                    page_shift = shifted;
                    asm("" : : "r"(scratch), "r"(page_value), "r"(shifted), "r"(page_shift));
                }
                if ((s32)page_shift > 0) *flags = 1;
                {
                    register s32 index asm("r1");
                    register u32 count asm("r0");
                    previous_shift = frame[7];
                    index = (s32)(previous_shift << 16) >> 16;
                    count = *inventory_count;

                    if (index < (s32)count - 1) {
                        register u32 value asm("r0") = *flags;
                        register union RegisterWord bit asm("r1");
                        bit.word = 2;
                        value |= bit.word;
                        *flags = value;
                    }
                }
                frame[2] = page_shift >> 16;
            }
        }
        {
            u32 selection_value;
            register s32 page_signed asm("r0");
            register union RegisterWord invalid_word asm("r1");
            register s32 invalid asm("r2");

            page_signed = (s32)page_shift >> 16;
            invalid_word.word = 0xFFFF0000;
            invalid = (s32)invalid_word.word >> 16;

            if (page_signed == invalid) goto sale_reply;
            {
                register u16 *cursor asm("r1") = &D_02007588;
                register u32 index asm("r0");
                register u32 cursor_value asm("r1");
                index = page_signed << 2;

                cursor_value = *cursor;
                index += cursor_value;
                index = (index << 16) >> 16;
                frame[3] = index;
                selection_value = index;
            }
            {
                register u32 prior_value asm("r3") = frame[4];
                register u32 prior_shift asm("r1");
                register u32 refresh asm("r4");
                register u32 selected_shift asm("r4");
                prior_shift = prior_value << 16;
                refresh = frame[6];

                if (!refresh)
                {
                    register u32 selected_value asm("r0") = selection_value;
                    register u32 shifted asm("r0");
                        shifted = selected_value << 16;
                    if (shifted == prior_shift) goto sale_input;
                }
                {
                    register s32 previous asm("r0") = (s32)prior_shift >> 16;
                    if (previous != invalid) func_0803E488(D_0875AFB8, 0);
                }
                {
                    register const u8 *listing asm("r1") = D_0200E648;
                    register u32 selected_value asm("r0");
                    register s32 index asm("r0");
                    selected_value = frame[3];
                    selected_shift = selected_value << 16;

                    index = (s32)selected_shift >> 16;
                    func_080543F4(*(const u8 *)(index + (u32)listing));
                }
                func_0803E488(D_0875AFB8, 24);
                selected_shift >>= 16;
                frame[4] = selected_shift;
                {
                    register u32 zero asm("r1") = 0;
                    frame[6] = zero;
                }
            }
    sale_input:
            func_0803E488(D_0875AFB8, 35);
            {
                register const u16 *variables asm("r1") = D_02007574;
                register u32 reply asm("r0");
                reply = variables[0];
                if (reply <= 1) goto sale_reply;
                if (reply == 2) goto sale_previous_page;
                if (reply == 4) goto sale_next_page;
                goto sell_select;
            }
    sale_previous_page:
            {
                register u32 value asm("r2") = frame[1];
                register u32 shifted asm("r0");
                register s32 page asm("r4");
                shifted = value << 16;
                page = (s32)shifted >> 16;

                if (page <= 0) goto sell_select;
                func_080019EC(64);
                shifted = (u32)(page - 1) << 16;
                frame[1] = shifted >> 16;
                goto sell_select;
            }
    sale_next_page:
            {
                register u32 value asm("r3") = frame[7];
                register s32 index asm("r1");
                register const u8 *count_address asm("r0");
                register s32 count asm("r0");
                index = (s32)(value << 16) >> 16;
                count_address = &D_0200E6DE;
                count = *count_address - 1;
                if (index >= count) goto sell_select;
                func_080019EC(64);
                {
                    register u32 page_value asm("r4") = frame[1];
                    register u32 shifted asm("r0");
                    register u32 increment asm("r1");
                    shifted = page_value << 16;
                    increment = 0x10000;

                    shifted += increment;
                    frame[1] = shifted >> 16;
                }
                goto sell_select;
            }
        }
    sale_reply:
        {
            register const volatile u16 *variables asm("r0") = D_02007574;
            u32 reply;
            reply = *variables;
            if (reply)
            {
                register s32 page_signed asm("r0");
            register union SignedRegisterWord page_copy asm("r7");
                register s32 invalid asm("r2");
                page_copy.word = page_shift;
            page_signed = page_copy.halves[1];
                invalid = -1;

                if (page_signed != invalid) goto sale_chosen;
            }
            else func_080019EC(63);
        }
    sell_close:
        {
            register const u8 *script asm("r0") = D_0875AFB8;
            func_0803E488(script, 13);
        }
        {
            register const u8 *script asm("r0") = D_0875AFB8;
            func_0803E488(script, 12);
        }
        {
            register const u8 *script asm("r0") = D_0875AFB8;
            func_0803E488(script, 0);
        }
        {
            register s32 page_signed asm("r0");
            register union SignedRegisterWord page_copy asm("r7");
            register s32 invalid asm("r3");
            page_copy.word = page_shift;
            page_signed = page_copy.halves[1];
            invalid = -1;

            if (page_signed == invalid)
            {
                func_0803E488(D_0875B37C, 3);
                func_080019EC(65);
            }
        }
        goto choose_action;
    sale_chosen:
        frame[5] = D_02007588;
        state = 0x220;
        break;
        }
    case 0x220:
        {
            register const u8 *listing asm("r4");
            register u32 sale_price asm("r6");
            register const u8 *script asm("r5");
            const u8 *prompt;
            register const u8 *text asm("r8");
            {
                register const u8 *inventory asm("r1") = D_0200E648;
                register u32 selected_value asm("r4");
                register s32 index asm("r0");
                register u32 id asm("r1");
                register u32 offset asm("r0");
                register const struct Item *records asm("r1");
                register const struct Item *record asm("r0");
                register u32 full_price asm("r0");
                selected_value = frame[3];
                index = (s32)(selected_value << 16) >> 16;

                listing = (const u8 *)(index + (u32)inventory);
                id = *listing;
                offset = id * 24;
                records = D_0866C754;
                record = (const struct Item *)(offset + (u32)records);
                item = record;

                full_price = record->price;
                sale_price = full_price >> 1;
            }
            script = D_0875AFB8;
            func_0803E488(script, 0);
            func_0803E488(script, 25);
            {
                register u32 id asm("r1") = *listing;
                register const u8 *names asm("r0");
                    names = D_0866634C;
                func_0803E488(names, id);
            }
            prompt = D_0875B37C;
            func_0803E488(prompt, 9);
            func_08001848(sale_price, 7, 1);
            func_0803E488(prompt, 14);
            func_0803E488(script, 16);
            {
                register const u8 *copy asm("r0") = D_0875B068;
                text = copy;
                func_0803E488(copy, 17);
            }
            if (D_02007574[0] != 1) goto sale_confirmation_cancel;
            {
                if (!D_02007574[1])
                {
                    register u32 *money asm("r4");
                    {
                        register u32 id asm("r0") = *listing;
                        register u8 *counts asm("r1");
                        register u8 *address asm("r0");
                        register u32 count asm("r1");
                                    counts = D_02003EA8;
                        address = (u8 *)(id + (u32)counts);
                        count = *address;
                        count--;
                        *address = count;
                    }
                    {
                        register u8 *base asm("r2") = D_02000B5C;
                        register union RegisterWord offset asm("r3");
                        register u32 amount asm("r0");
                        register u32 limit asm("r1");
                        offset.word = 0xD28;
                        money = (u32 *)(base + offset.word);
                        amount = *money + sale_price;
                        *money = amount;
                        limit = 9999999;
                        if (amount > limit) *money = limit;
                    }
                    func_0803E488(script, 1);
                    func_0803E488(script, 26);
                    func_0803E488(script, 42);
                    func_08001848(*money, 7, 0);
                    func_0803E488(text, 1);
                    func_0803E488(prompt, 11);
                }
                else func_0803E488(prompt, 12);

                {
                    register const u8 *finish asm("r0") = D_0875AFB8;
                    func_0803E488(finish, 24);
                }
                {
                    register const u8 *finish asm("r0") = D_0875AFB8;
                    func_0803E488(finish, 25);
                }
                {
                    register const u8 *finish asm("r0") = D_0875AFB8;
                    func_0803E488(finish, 37);
                }
                func_080019EC(65);
                {
                    register u32 refresh asm("r4") = 2;
                            frame[6] = refresh;
                }
            }
            goto sale_restore;
close_menu:
        func_080019EC(63);
        {
            register const u8 *script asm("r0") = D_0875AFB8;
            func_0803E488(script, 13);
        }
        {
            register const u8 *script asm("r0") = D_0875AFB8;
            func_0803E488(script, 12);
        }
        {
            register const u8 *script asm("r0") = D_0875AFB8;
            func_0803E488(script, 0);
        }
        goto choose_action;
sale_confirmation_cancel:
                func_080019EC(63);
                frame[6] = 1;
sale_restore:
        }
        {
            register u16 *cursor asm("r0") = &D_02007588;
            register const volatile u8 *frame_bytes asm("r1");
            frame_bytes = (const volatile u8 *)&frame;

            *cursor = *(const volatile u16 *)(frame_bytes + 20);
        }
        state = 0x201;
        break;
    }
    {
        register u32 shifted asm("r0") = (u32)state << 16;
        phase_base = shifted;
        asm("" : : "r"(shifted), "r"(phase_base));
    }
    if ((s32)phase_base >= 0) goto dispatch;
    func_08003DF8(10, func_08004034);
    {
        register u32 task_base asm("r1") = (u32)D_02000034;
        register u32 result_offset asm("r3") = 0x558;
        register u32 address asm("r2");
        register u32 one asm("r0");
        register u32 parameter_offset asm("r4");
        register u32 zero asm("r0");
        register u32 busy_offset asm("r0");
        register u32 *busy asm("r1");
        asm("" : : "r"(task_base), "r"(result_offset));
        address = task_base + result_offset;
        one = 1;
        asm("" : : "r"(address), "r"(one));
        *(u32 *)address = one;
        parameter_offset = 0x55C;
        asm("" : : "r"(parameter_offset));
        address = task_base + parameter_offset;
        zero = 0;
        asm("" : : "r"(address), "r"(zero));
        *(u32 *)address = zero;
        busy_offset = 0x568;
        asm("" : : "r"(busy_offset));
        busy = (u32 *)(task_base + busy_offset);
        asm("" : : "r"(busy));
        if (*busy != 1)
        {
            register u32 *waiting asm("r4") = busy;
            asm("" : : "r"(waiting));
            do { func_0805EE78(1); } while (*waiting != 1);
        }
    }
    func_08003E3C(10);
    func_08003E3C(5);
    {
        register u32 task_base asm("r2") = (u32)D_02000034;
        register const u8 *current asm("r0") = &D_02000030;
        register u32 task_index asm("r1");
        register u32 offset asm("r0");
        register u32 address asm("r0");
        register s32 result asm("r1");
        asm("" : : "r"(task_base), "r"(current), "r"(phase_base));
        task_index = *current;
        offset = task_index * 136;
        asm("" : : "r"(offset));
        task_base += 8;
        asm("" : : "r"(task_base));
        address = offset + task_base;
        asm("" : "+r"(phase_base) : "r"(address));
        result = (s32)phase_base >> 16;
        *(s32 *)address = result;
    }
}
