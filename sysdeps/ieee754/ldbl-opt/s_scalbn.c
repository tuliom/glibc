#include <math_ldbl_opt.h>
#include <bits/wordsize.h>
# if __WORDSIZE == 64
#   include <sysdeps/ieee754/dbl-64/wordsize-64/s_scalbn.c>
# else
#   include <sysdeps/ieee754/dbl-64/s_scalbn.c>
#endif
#if IS_IN (libm)
# if LONG_DOUBLE_COMPAT(libm, GLIBC_2_0)
compat_symbol (libm, __scalbn, scalbnl, GLIBC_2_0);
# endif
#elif LONG_DOUBLE_COMPAT(libc, GLIBC_2_0)
compat_symbol (libc, __scalbn, scalbnl, GLIBC_2_0);
#endif
