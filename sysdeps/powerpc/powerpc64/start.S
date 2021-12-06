/* Startup code for programs linked with GNU libc.  PowerPC64 version.
   Copyright (C) 1998-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   In addition to the permissions in the GNU Lesser General Public
   License, the Free Software Foundation gives you unlimited
   permission to link the compiled version of this file with other
   programs, and to distribute those programs without any restriction
   coming from the use of this file. (The GNU Lesser General Public
   License restrictions do apply in other respects; for example, they
   cover modification of the file, and distribution when not linked
   into another program.)

   Note that people who make modified versions of this file are not
   obligated to grant this special exception for their modified
   versions; it is their choice whether to do so. The GNU Lesser
   General Public License gives permission to release a modified
   version without this exception; this exception also makes it
   possible to release a modified version which carries forward this
   exception.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <sysdep.h>

/* We do not want .eh_frame info for crt1.o since crt1.o is linked
   before crtbegin.o, the file defining __EH_FRAME_BEGIN__.  */
#undef cfi_startproc
#define cfi_startproc
#undef cfi_endproc
#define cfi_endproc

#if _CALL_ELF == 2
# define FRAME_SIZE		(FRAME_MIN_SIZE+32)
# define SDA_BASE_OFFSET	32
# define MAIN_OFFSET		40
# define INIT_OFFSET		48
# define FINI_OFFSET		56
#else
# define FRAME_SIZE		(FRAME_MIN_SIZE+32)
# define SDA_BASE_OFFSET	112
# define MAIN_OFFSET		120
# define INIT_OFFSET		128
# define FINI_OFFSET		136
#endif
	.section	".toc","aw"
.L01:
	.tc	main[TC],main
	.section ".text"
/* Initialize the stack and prepare the arguments for the following call:
   __libc_start_main_impl (int argc (r3),
			   char **argv (r4),
			   char **ev (r5),
			   void * auxvec (r6),
			   void (*rtld_fini) (void) (r7),
			   struct startup_info *stinfo (r8),
			   char **stack_on_entry (r9));  */
ENTRY (_start)
 /* Save the stack pointer, in case we're statically linked under Linux.  */
	mr	r9,r1
 /* Set up an initial stack frame, and clear the LR.  */
	clrrdi	r1,r1,4
	li	r0,0
	stdu	r1,-FRAME_SIZE(r1)
	mtlr	r0
	std	r0,0(r1)

#if defined SHARED || _CALL_ELF == 1
	ld	r8,.L01@toc(r2)
#else
/* Avoid depending on a runtime relocation too early for the static case.  Get
   an address that is guaranteed to be available at this moment and defer the
   relocation.  */
	addi	r8,r12,L(__wrap_main)-BODY_LABEL(_start)
#endif
	/* Save struct startup_info in the stack.  */
	std	r0,SDA_BASE_OFFSET(r1)
	std	r8,MAIN_OFFSET(r1)
	std	r0,INIT_OFFSET(r1)
	std	r0,FINI_OFFSET(r1)

	addi	r8,r1,SDA_BASE_OFFSET

/* and continue in libc-start, in glibc.  */
	b	JUMPTARGET(__libc_start_main)
/* Older versions of ld need this nop to recognize that it's OK to call via a
   TOC adjusting stub.  */
	nop

#if !defined SHARED
/* Relocations have already been applied and we can get main's address now.
   Note: in powerpc64, this file is always built as PIC.  */
L(__wrap_main):
/* Rebuild the TOC pointer because __libc_start_main may be defined in a
   shared library.  */
	addis	r2,r12,.TOC.-L(__wrap_main)@ha
	addi	r2,r2,.TOC.-L(__wrap_main)@l
	ld	r12,.L01@toc(r2)
	mtctr	r12
	bctr
#endif
END(_start)

/* Define a symbol for the first piece of initialized data.  */
	.section ".data"
	.globl	__data_start
__data_start:
	.long	0
weak_alias (__data_start, data_start)
