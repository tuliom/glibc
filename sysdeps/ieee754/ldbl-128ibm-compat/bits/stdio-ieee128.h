/* Redirections for stdio functions for -mabi=ieeelongdouble.
   Copyright (C) 2018 Free Software Foundation, Inc.
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

/* XXX: DO NOT COMMIT.

   On powerpc64le, the implementation of long double with IEEE binary128
   format is not complete.  The redirections of the stdio.h functions
   are supposed to be implemented in bits/stdio-ldbl.h, however, we can
   only redirect all or none.  In the meantime, bits/stdio-ieee128.h
   allows us to redirect part of them for testing purposes.  */

#ifndef _STDIO_H
# error "Never include <bits/stdio-ibm128.h> directly; use <stdio.h> instead."
#endif

#include <stdio.h>
#include <wchar.h>

#define __IEEE128_REDIR(name) \
  extern __typeof (name) __##name##ieee128; \
  extern __typeof (name) name __asm (__ASMNAME ("__" #name "ieee128"));

#define __IEEE128_REDIR_PREFIX(name) \
  extern __typeof (__##name) __##name##ieee128; \
  extern __typeof (__##name) __##name __asm (__ASMNAME ("__" #name "ieee128"));

__IEEE128_REDIR (asprintf)
__IEEE128_REDIR (dprintf)
__IEEE128_REDIR (fprintf)
__IEEE128_REDIR (printf)
__IEEE128_REDIR (snprintf)
__IEEE128_REDIR (sprintf)

__IEEE128_REDIR (vasprintf)
__IEEE128_REDIR (vdprintf)
__IEEE128_REDIR (vfprintf)
__IEEE128_REDIR (vprintf)
__IEEE128_REDIR (vsnprintf)
__IEEE128_REDIR (vsprintf)

__IEEE128_REDIR (fwprintf)
__IEEE128_REDIR (swprintf)
__IEEE128_REDIR (wprintf)

__IEEE128_REDIR (vfwprintf)
__IEEE128_REDIR (vswprintf)
__IEEE128_REDIR (vwprintf)

#if __USE_FORTIFY_LEVEL > 0
__IEEE128_REDIR_PREFIX (asprintf_chk)
__IEEE128_REDIR_PREFIX (dprintf_chk)
__IEEE128_REDIR_PREFIX (fprintf_chk)
__IEEE128_REDIR_PREFIX (printf_chk)
__IEEE128_REDIR_PREFIX (snprintf_chk)
__IEEE128_REDIR_PREFIX (sprintf_chk)

__IEEE128_REDIR_PREFIX (vasprintf_chk)
__IEEE128_REDIR_PREFIX (vdprintf_chk)
__IEEE128_REDIR_PREFIX (vfprintf_chk)
__IEEE128_REDIR_PREFIX (vprintf_chk)
__IEEE128_REDIR_PREFIX (vsnprintf_chk)
__IEEE128_REDIR_PREFIX (vsprintf_chk)

__IEEE128_REDIR_PREFIX (fwprintf_chk)
__IEEE128_REDIR_PREFIX (swprintf_chk)
__IEEE128_REDIR_PREFIX (wprintf_chk)

__IEEE128_REDIR_PREFIX (vfwprintf_chk)
__IEEE128_REDIR_PREFIX (vswprintf_chk)
__IEEE128_REDIR_PREFIX (vwprintf_chk)
#endif

__IEEE128_REDIR (fscanf)
__IEEE128_REDIR (scanf)
__IEEE128_REDIR (sscanf)

__IEEE128_REDIR (vfscanf)
__IEEE128_REDIR (vscanf)
__IEEE128_REDIR (vsscanf)

__IEEE128_REDIR (fwscanf)
__IEEE128_REDIR (swscanf)
__IEEE128_REDIR (wscanf)

__IEEE128_REDIR (vfwscanf)
__IEEE128_REDIR (vswscanf)
__IEEE128_REDIR (vwscanf)
/* To be completed with the other functions.  */
