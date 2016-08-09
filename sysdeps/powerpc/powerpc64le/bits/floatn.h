/* Macros to control TS 18661-3 glibc features on PPC64.
   Copyright (C) 2016 Free Software Foundation, Inc.
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

#define __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
#include <bits/libc-header-start.h>

/* The compiler supports the type _Float128 or __float128.  */
#ifdef __FLOAT128__
# define __HAVE_FLOAT128 1
#else
# define __HAVE_FLOAT128 0
#endif

/* Enable _Float128 (only set if the type is actually supported on the
   building toolchain.  */
#ifdef __FLOAT128__
# define __USE_FLOAT128 \
  (__GLIBC_USE (IEC_60559_TYPES_EXT) && __GNUC_PREREQ (6, 2))
#else
# define __USE_FLOAT128 0
#endif

/* Include macros to allow support for older compilers.  */
#include <bits/floatn-compat.h>
