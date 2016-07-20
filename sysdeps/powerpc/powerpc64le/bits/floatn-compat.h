/* Define _FloatN macros for ISO/IEC TS-18661-3 support for powerpc64le.
   Copyright (C) 2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Define macros to support _Float128 on old compilers.  */
#if __USE_FLOAT128

/* The type _Float128, as well as the literal suffix (F128), exist for powerpc
   only since GCC 7.0.  */
# if !__GNUC_PREREQ (7, 0)
#  define L(x) x##Q
typedef __float128 _Float128;
# else
#  define L(x) x##F128
# endif

/* Add a typedef for older GCC compilers which don't natively support
   _Complex _Float128.  */
# if __GNUC_PREREQ (6, 2) && !__GNUC_PREREQ (7, 0) && !defined __CFLOAT128
typedef _Complex float __cfloat128 __attribute__ ((mode (KC)));
#  define __CFLOAT128 __cfloat128
# endif

/* Builtin __builtin_huge_val is only type-generic since GCC 7.0.  */
# if !__GNUC_PREREQ (7, 0)
#  define __builtin_huge_valf128() ((_Float128) __builtin_huge_val ())
# endif

/* The following builtins (suffixed with 'q') are available in GCC >= 6.2,
   which is the minimum version required for float128 support on powerpc64le.
   Since GCC 7.0 the builtins suffixed with f128 are also available, then
   there is no need to redefined them.  */
# if !__GNUC_PREREQ (7, 0)
#  define __builtin_copysignf128 __builtin_copysignq
#  define __builtin_fabsf128 __builtin_fabsq
#  define __builtin_inff128 __builtin_infq
#  define __builtin_nanf128 __builtin_nanq
# endif

/* __builtin_signbit is type generic in GCC 6.2, which is the minimum
   version required for float128 support on powerpc64le.  */
# define __builtin_signbitf128 __builtin_signbit

#endif
