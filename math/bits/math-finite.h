/* Entry points to finite-math-only compiler runs.
   Copyright (C) 2011-2018 Free Software Foundation, Inc.
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

#ifndef _MATH_H
# error "Never use <bits/math-finite.h> directly; include <math.h> instead."
#endif

#define __REDIRFROM_F(...) __REDIRFROM_X(__VA_ARGS__)

#define __REDIRTO_F(...) __REDIRTO_X(__VA_ARGS__)

/* Redirects to a function that is part of the API.  */
#define __REDIRTO_PUBLIC_F(...) __REDIRTO_PUBLIC_X(__VA_ARGS__)

#define __MATH_REDIR_X(type, from, args, to) \
  extern type __REDIRECT_NTH (from, args, to)

#define __MATH_REDIRCALL(function, reentrant, args) \
  __MATH_REDIR_X (_Mdouble_, \
		  __REDIRFROM_F (function, reentrant), args, \
		  __REDIRTO_F (function, reentrant))

#define __MATH_REDIRCALL_INTERNAL(function, reentrant, args) \
  __MATH_REDIR_X (_Mdouble_, \
		  __REDIRFROM_F (__CONCAT (__, function), \
				 __CONCAT (reentrant, _finite)), \
		  args, __REDIRTO_F (function, _r))


/* Redirect __lgammal_r_finite to __lgamma_r_finite when __NO_LONG_DOUBLE_MATH
   is set and to itself otherwise.  It also redirects __lgamma_r_finite and
   __lgammaf_r_finite to themselves.  */
__MATH_REDIRCALL_INTERNAL (lgamma, _r, (_Mdouble_, int *));

#if ((defined __USE_XOPEN || defined __USE_ISOC99) \
     && defined __extern_always_inline)
/* lgamma.  */
__extern_always_inline _Mdouble_
__NTH (__REDIRFROM_F (lgamma, ) (_Mdouble_ __d))
{
# if defined __USE_MISC || defined __USE_XOPEN
  return __REDIRTO_PUBLIC_F (lgamma, _r) (__d, &signgam);
# else
  int __local_signgam = 0;
  return __REDIRTO_PUBLIC_F (lgamma, _r) (__d, &__local_signgam);
# endif
}
#endif

#if ((defined __USE_MISC || (defined __USE_XOPEN && !defined __USE_XOPEN2K)) \
     && defined __extern_always_inline) && !__MATH_DECLARING_FLOATN
/* gamma.  */
__extern_always_inline _Mdouble_
__NTH (__REDIRFROM_F (gamma, ) (_Mdouble_ __d))
{
  return __REDIRTO_PUBLIC_F (lgamma, _r) (__d, &signgam);
}
#endif

#if defined __USE_ISOC99 && defined __extern_always_inline
/* tgamma.  */
# if __HAVE_DISTINCT_FLOAT128 && !__HAVE_FLOAT128_UNLIKE_LDBL
__MATH_REDIRCALL_INTERNAL (gamma, _r, (_Mdouble_, int *));
# else
extern _Mdouble_
__REDIRFROM_F (__gamma, _r_finite) (_Mdouble_, int *);
# endif

__extern_always_inline _Mdouble_
__NTH (__REDIRFROM_F (tgamma, ) (_Mdouble_ __d))
{
  int __local_signgam = 0;
  _Mdouble_ __res = __REDIRTO_PUBLIC_F (gamma, _r) (__d, &__local_signgam);
  return __local_signgam < 0 ? -__res : __res;
}
#endif

#undef __MATH_REDIRCALL
#undef __MATH_REDIRCALL_INTERNAL
#undef __MATH_REDIR_X
#undef __REDIRFROM_F
#undef __REDIRTO_F
