#include "types.h"

// Fixed registers and explicit stack operations preserve the library helper's custom ABI.
#pragma GCC optimize("no-reorder-blocks", "no-crossjumping")
register u32 numerator asm("r0");
register u32 denominator asm("r1");
register u32 corrections asm("r2");
register u32 bit asm("r3");
register u32 scratch asm("r4");
register u32 saved_bit asm("ip");

u32 func_0805D4FC(u32 left, u32 right)
{
    asm goto("cmp %0, #0\n\tbeq %l[zero]" : : "r"(denominator) : "cc" : zero);
    bit = 1;
    asm("" : "+r"(bit));
    asm goto("cmp %0, %1\n\tbhs %l[align_setup]"
             :
             : "r"(numerator), "r"(denominator)
             : "cc"
             : align_setup);
    asm volatile("mov pc, lr" : : "r"(numerator));
    __builtin_unreachable();
align_setup:
    asm volatile("push {r4}" : : : "memory");
    scratch = 1;
    asm("" : "+r"(scratch));
    scratch <<= 28;
    asm("" : "+r"(scratch));
align_four:
    asm goto("cmp %0, %1\n\tbhs %l[align_one_setup]"
             :
             : "r"(denominator), "r"(scratch)
             : "cc"
             : align_one_setup);
    asm goto("cmp %0, %1\n\tbhs %l[align_one_setup]"
             :
             : "r"(denominator), "r"(numerator)
             : "cc"
             : align_one_setup);
    denominator <<= 4;
    bit <<= 4;
    asm volatile("" : "+r"(denominator), "+r"(bit));
    goto align_four;
align_one_setup:
    scratch <<= 3;
    asm("" : "+r"(scratch));
align_one:
    asm goto("cmp %0, %1\n\tbhs %l[divide]" : : "r"(denominator), "r"(scratch) : "cc" : divide);
    asm goto("cmp %0, %1\n\tbhs %l[divide]" : : "r"(denominator), "r"(numerator) : "cc" : divide);
    denominator <<= 1;
    bit <<= 1;
    asm volatile("" : "+r"(denominator), "+r"(bit));
    goto align_one;
divide:
    corrections = 0;
    asm volatile("" : "+r"(corrections));
    if (numerator >= denominator)
    {
        numerator -= denominator;
    }
    scratch = denominator >> 1;
    asm("" : "+r"(scratch));
    if (numerator >= scratch)
    {
        numerator -= scratch;
        asm volatile("" : "+r"(numerator), "+r"(scratch));
        saved_bit = bit;
        asm volatile("" : "+r"(saved_bit));
        scratch = 1;
        asm volatile("" : "+r"(scratch));
        bit = (bit >> scratch) | (bit << ((0 - scratch) & 31));
        asm volatile("" : "+r"(bit));
        corrections |= bit;
        asm volatile("" : "+r"(corrections));
        bit = saved_bit;
        asm volatile("" : "+r"(bit));
    }
    scratch = denominator >> 2;
    asm("" : "+r"(scratch));
    if (numerator >= scratch)
    {
        numerator -= scratch;
        asm volatile("" : "+r"(numerator), "+r"(scratch));
        saved_bit = bit;
        asm volatile("" : "+r"(saved_bit));
        scratch = 2;
        asm volatile("" : "+r"(scratch));
        bit = (bit >> scratch) | (bit << ((0 - scratch) & 31));
        asm volatile("" : "+r"(bit));
        corrections |= bit;
        asm volatile("" : "+r"(corrections));
        bit = saved_bit;
        asm volatile("" : "+r"(bit));
    }
    scratch = denominator >> 3;
    asm("" : "+r"(scratch));
    if (numerator >= scratch)
    {
        numerator -= scratch;
        asm volatile("" : "+r"(numerator), "+r"(scratch));
        saved_bit = bit;
        asm volatile("" : "+r"(saved_bit));
        scratch = 3;
        asm volatile("" : "+r"(scratch));
        bit = (bit >> scratch) | (bit << ((0 - scratch) & 31));
        asm volatile("" : "+r"(bit));
        corrections |= bit;
        asm volatile("" : "+r"(corrections));
        bit = saved_bit;
        asm volatile("" : "+r"(bit));
    }
    saved_bit = bit;
    asm volatile("" : "+r"(saved_bit));
    if (numerator == 0)
        goto done;
    bit >>= 4;
    asm goto("beq %l[done]" : : "r"(bit) : : done);
    denominator >>= 4;
    goto divide;
done:
    scratch = 14;
    asm volatile("" : "+r"(scratch));
    scratch <<= 28;
    asm volatile("" : "+r"(scratch));
    corrections &= scratch;
    asm goto("bne %l[restore_remainder]" : : "r"(corrections) : : restore_remainder);
    asm volatile("pop {r4}\n\tmov pc, lr" : : "r"(numerator) : "memory");
    __builtin_unreachable();
restore_remainder:
    bit = saved_bit;
    asm volatile("" : "+r"(bit));
    scratch = 3;
    asm volatile("" : "+r"(scratch));
    bit = (bit >> scratch) | (bit << ((0 - scratch) & 31));
    asm volatile("" : "+r"(bit));
    asm goto("tst %0, %1\n\tbeq %l[restore_two]"
             :
             : "r"(corrections), "r"(bit)
             : "cc"
             : restore_two);
    scratch = denominator >> 3;
    asm volatile("" : "+r"(scratch));
    numerator += scratch;
    asm volatile("" : "+r"(numerator));
restore_two:
    bit = saved_bit;
    asm volatile("" : "+r"(bit));
    scratch = 2;
    asm volatile("" : "+r"(scratch));
    bit = (bit >> scratch) | (bit << ((0 - scratch) & 31));
    asm volatile("" : "+r"(bit));
    asm goto("tst %0, %1\n\tbeq %l[restore_one]"
             :
             : "r"(corrections), "r"(bit)
             : "cc"
             : restore_one);
    scratch = denominator >> 2;
    asm volatile("" : "+r"(scratch));
    numerator += scratch;
    asm volatile("" : "+r"(numerator));
restore_one:
    bit = saved_bit;
    asm volatile("" : "+r"(bit));
    scratch = 1;
    asm volatile("" : "+r"(scratch));
    bit = (bit >> scratch) | (bit << ((0 - scratch) & 31));
    asm volatile("" : "+r"(bit));
    asm goto("tst %0, %1\n\tbeq %l[return_result]"
             :
             : "r"(corrections), "r"(bit)
             : "cc"
             : return_result);
    scratch = denominator >> 1;
    asm volatile("" : "+r"(scratch));
    numerator += scratch;
return_result:
    asm volatile("pop {r4}\n\tmov pc, lr" : : "r"(numerator) : "memory");
    __builtin_unreachable();
zero:
    asm volatile("push {lr}\n\tbl func_0805D36C" : : : "memory", "cc");
    numerator = 0;
    asm volatile("pop {pc}" : : "r"(numerator) : "memory");
    __builtin_unreachable();
}
