#include "lib/libgcc2.h"

#define __umulsidi3(u, v) \
  ({DIunion __w;							\
    do {								\
      USItype __x0, __x1, __x2, __x3;					\
      USItype __ul, __vl, __uh, __vh;					\
      __ul = __ll_lowpart (u);						\
      __uh = __ll_highpart (u);						\
      __vl = __ll_lowpart (v);						\
      __vh = __ll_highpart (v);						\
      __x0 = (USItype) __ul * __vl;					\
      __x1 = (USItype) __ul * __vh;					\
      __x2 = (USItype) __uh * __vl;					\
      __x3 = (USItype) __uh * __vh;					\
      __x1 += __ll_highpart (__x0);					\
      __x1 += __x2;							\
      if (__x1 < __x2)							\
	__x3 += __ll_B;							\
      (__w.s.high) = __x3 + __ll_highpart (__x1);			\
      (__w.s.low) = __ll_lowpart (__x1) * __ll_B + __ll_lowpart (__x0);	\
    } while (0);							\
    __w.ll; })

DItype
__muldi3 (DItype u, DItype v)
{
  DIunion w;
  DIunion uu, vv;

  uu.ll = u,
  vv.ll = v;

  w.ll = __umulsidi3 (uu.s.low, vv.s.low);
  w.s.high += ((USItype) uu.s.low * (USItype) vv.s.high
	       + (USItype) uu.s.high * (USItype) vv.s.low);

  return w.ll;
}
