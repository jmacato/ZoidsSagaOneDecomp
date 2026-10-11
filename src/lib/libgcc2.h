typedef unsigned int UQItype __attribute__ ((mode (QI)));
typedef int SItype __attribute__ ((mode (SI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
typedef float SFtype __attribute__ ((mode (SF)));
typedef float DFtype __attribute__ ((mode (DF)));
typedef int word_type __attribute__ ((mode (__word__)));

struct DIstruct {SItype low, high;};

typedef union
{
  struct DIstruct s;
  DItype ll;
} DIunion;

#define __BITS4 ((sizeof (SItype) * 8) / 4)
#define __ll_B (1L << ((sizeof (SItype) * 8) / 2))
#define __ll_lowpart(t) ((USItype) (t) % __ll_B)
#define __ll_highpart(t) ((USItype) (t) / __ll_B)
