#include "lib/libgcc2.h"

USItype
__fixunsdfsi (DFtype a)
{
  if (a >= - (DFtype) (-2147483647L - 1))
    return (SItype) (a + (-2147483647L - 1)) - (-2147483647L - 1);
  return (SItype) a;
}
