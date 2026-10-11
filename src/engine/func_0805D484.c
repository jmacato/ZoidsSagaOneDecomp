#include "types.h"

// Fixed registers and explicit stack operations preserve the library helper's custom ABI.
#pragma GCC optimize("no-reorder-blocks")
register u32 numerator asm("r0");
register u32 denominator asm("r1");
register u32 quotient asm("r2");
register u32 bit asm("r3");
register u32 scratch asm("r4");

u32 func_0805D484(u32 left, u32 right)
{
    asm goto("cmp %0, #0\n\tbeq %l[zero]" : : "r"(denominator) : "cc" : zero);
    bit = 1;
    asm("" : "+r"(bit));
    quotient = 0;
    asm("" : "+r"(quotient));
    asm volatile("push {r4}" : : : "memory");
    if (numerator < denominator)
        goto done;
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
    if (numerator >= denominator)
    {
        numerator -= denominator;
        quotient |= bit;
    }
    scratch = denominator >> 1;
    asm("" : "+r"(scratch));
    if (numerator >= scratch)
    {
        numerator -= scratch;
        asm volatile("" : "+r"(numerator), "+r"(scratch));
        scratch = bit >> 1;
        asm volatile("" : "+r"(scratch));
        quotient |= scratch;
    }
    scratch = denominator >> 2;
    asm("" : "+r"(scratch));
    if (numerator >= scratch)
    {
        numerator -= scratch;
        asm volatile("" : "+r"(numerator), "+r"(scratch));
        scratch = bit >> 2;
        asm volatile("" : "+r"(scratch));
        quotient |= scratch;
    }
    scratch = denominator >> 3;
    asm("" : "+r"(scratch));
    if (numerator >= scratch)
    {
        numerator -= scratch;
        asm volatile("" : "+r"(numerator), "+r"(scratch));
        scratch = bit >> 3;
        asm volatile("" : "+r"(scratch));
        quotient |= scratch;
    }
    if (numerator == 0)
        goto done;
    bit >>= 4;
    asm goto("beq %l[done]" : : "r"(bit) : : done);
    denominator >>= 4;
    goto divide;
done:
    asm volatile("add %0, %1, #0\n\tpop {r4}\n\tmov pc, lr"
                 : "=r"(numerator)
                 : "r"(quotient)
                 : "memory", "cc");
    __builtin_unreachable();
zero:
    asm volatile("push {lr}\n\tbl func_0805D36C" : : : "memory", "cc");
    numerator = 0;
    asm volatile("pop {pc}" : : "r"(numerator) : "memory");
    __builtin_unreachable();
}
