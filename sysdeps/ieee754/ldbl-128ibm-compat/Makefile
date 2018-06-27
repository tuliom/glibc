ifeq ($(subdir),libio)
ldbl-extra-routines += wscanf \
		       fwscanf \
		       vwscanf \
		       swscanf
endif

ifeq ($(subdir),stdio-common)
# Wrappers for *printf functions that take long double arguments with
# IEEE binary128 format
ldbl-extra-routines += asprintf \
		       dprintf \
		       fprintf \
		       printf \
		       snprintf \
		       sprintf \
		       vasprintf \
		       vdprintf \
		       vfprintf \
		       vprintf \
		       vsnprintf \
		       vsprintf \
		       fwprintf \
		       swprintf \
		       wprintf \
		       vfwprintf \
		       vswprintf \
		       vwprintf \
		       asprintf_chk \
		       dprintf_chk \
		       fprintf_chk \
		       printf_chk \
		       snprintf_chk \
		       sprintf_chk \
		       vasprintf_chk \
		       vdprintf_chk \
		       vfprintf_chk \
		       vprintf_chk \
		       vsnprintf_chk \
		       vsprintf_chk \
		       fwprintf_chk \
		       swprintf_chk \
		       wprintf_chk \
		       vfwprintf_chk \
		       vswprintf_chk \
		       vwprintf_chk \
		       fscanf \
		       scanf \
		       sscanf \
		       vfscanf \
		       vscanf \
		       vsscanf \
		       vfwscanf \
		       vswscanf

# Printing long double values with IEEE binary128 format reuses part
# of the internal float128 implementation (__printf_fp, __printf_fphex,
# and __float128 variables and union members).  Likewise, reading these
# values reuses __strtof128_internal.  Thus, the compilation of the
# following functions, must have -mfloat128 passed to the compiler.
CFLAGS-vfprintf-internal.c += -mfloat128
CFLAGS-vfwprintf-internal.c += -mfloat128
CFLAGS-vfscanf-internal.c += -mfloat128
CFLAGS-vfwscanf-internal.c += -mfloat128

# Basic tests for the implementation of long double with IEEE binary128
# format and for the related redirections in installed headers.
tests-internal += test-printf-ieee128 test-printf-ibm128
CFLAGS-test-printf-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-printf-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

tests-internal += test-wprintf-ieee128 test-wprintf-ibm128
CFLAGS-test-wprintf-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-wprintf-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

tests-internal += test-printf-chk-ieee128 test-printf-chk-ibm128
CFLAGS-test-printf-chk-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-printf-chk-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

tests-internal += test-wprintf-chk-ieee128 test-wprintf-chk-ibm128
CFLAGS-test-wprintf-chk-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-wprintf-chk-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

tests-internal += test-scanf-ieee128 test-scanf-ibm128
CFLAGS-test-scanf-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-scanf-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

$(objpfx)test-scanf-ieee128: gnulib-tests += $(f128-loader-link)

tests-internal += test-wscanf-ieee128 test-wscanf-ibm128
CFLAGS-test-wscanf-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-wscanf-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

$(objpfx)test-wscanf-ieee128: gnulib-tests += $(f128-loader-link)

ifeq ($(run-built-tests),yes)
tests-special += $(objpfx)test-printf-ieee128.out
tests-special += $(objpfx)test-printf-ibm128.out

tests-special += $(objpfx)test-wprintf-ieee128.out
tests-special += $(objpfx)test-wprintf-ibm128.out

tests-special += $(objpfx)test-printf-chk-ieee128.out
tests-special += $(objpfx)test-printf-chk-ibm128.out

tests-special += $(objpfx)test-wprintf-chk-ieee128.out
tests-special += $(objpfx)test-wprintf-chk-ibm128.out

tests-special += $(objpfx)test-scanf-ieee128.out
tests-special += $(objpfx)test-scanf-ibm128.out

tests-special += $(objpfx)test-wscanf-ieee128.out
tests-special += $(objpfx)test-wscanf-ibm128.out
endif

$(objpfx)test-printf-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-printf-ldbl-compat.sh \
  $(objpfx)test-printf-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-printf-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-printf-ldbl-compat.sh \
  $(objpfx)test-printf-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-wprintf-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-wprintf-ldbl-compat.sh \
  $(objpfx)test-wprintf-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-wprintf-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-wprintf-ldbl-compat.sh \
  $(objpfx)test-wprintf-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-printf-chk-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-printf-chk-ldbl-compat.sh \
  $(objpfx)test-printf-chk-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-printf-chk-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-printf-chk-ldbl-compat.sh \
  $(objpfx)test-printf-chk-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-wprintf-chk-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-wprintf-chk-ldbl-compat.sh \
  $(objpfx)test-wprintf-chk-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-wprintf-chk-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-wprintf-chk-ldbl-compat.sh \
  $(objpfx)test-wprintf-chk-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-scanf-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-scanf-ldbl-compat.sh \
  $(objpfx)test-scanf-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-scanf-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-scanf-ldbl-compat.sh \
  $(objpfx)test-scanf-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-wscanf-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-scanf-ldbl-compat.sh \
  $(objpfx)test-wscanf-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-wscanf-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-scanf-ldbl-compat.sh \
  $(objpfx)test-wscanf-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)
endif

ifeq ($(subdir),argp)
# Wrappers for argp functions that take long double arguments with
# IEEE binary128 format
routines += ieee128-argp_error
routines += ieee128-argp_failure

tests-internal += test-argp-error-ieee128 test-argp-error-ibm128
CFLAGS-test-argp-error-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-argp-error-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

tests-internal += test-argp-failure-ieee128 test-argp-failure-ibm128
CFLAGS-test-argp-failure-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-argp-failure-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

ifeq ($(run-built-tests),yes)
tests-special += $(objpfx)test-argp-error-ieee128.out
tests-special += $(objpfx)test-argp-error-ibm128.out
tests-special += $(objpfx)test-argp-failure-ieee128.out
tests-special += $(objpfx)test-argp-failure-ibm128.out
endif

$(objpfx)test-argp-error-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-argp-error-ldbl-compat.sh \
  $(objpfx)test-argp-error-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-argp-error-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-argp-error-ldbl-compat.sh \
  $(objpfx)test-argp-error-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-argp-failure-ieee128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-argp-failure-ldbl-compat.sh \
  $(objpfx)test-argp-failure-ieee128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-argp-failure-ibm128.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-argp-failure-ldbl-compat.sh \
  $(objpfx)test-argp-failure-ibm128
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)
endif

ifeq ($(subdir),misc)
# Wrappers for err.h functions that take long double arguments with
# IEEE binary128 format
ldbl-extra-routines += err \
		       error

tests-internal += test-warn-ibm128 test-warn-ieee128
CFLAGS-test-warn-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-warn-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

tests-internal += test-err-ibm128 test-err-ieee128
tests-internal += test-errx-ibm128 test-errx-ieee128
tests-internal += test-verr-ibm128 test-verr-ieee128
tests-internal += test-verrx-ibm128 test-verrx-ieee128
CFLAGS-test-err-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-err-ibm128.c += -mabi=ibmlongdouble -Wno-psabi
CFLAGS-test-errx-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-errx-ibm128.c += -mabi=ibmlongdouble -Wno-psabi
CFLAGS-test-verr-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-verr-ibm128.c += -mabi=ibmlongdouble -Wno-psabi
CFLAGS-test-verrx-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-verrx-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

tests-internal += test-error1-ibm128 test-error1-ieee128
tests-internal += test-error2-ibm128 test-error2-ieee128
CFLAGS-test-error1-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-error1-ibm128.c += -mabi=ibmlongdouble -Wno-psabi
CFLAGS-test-error2-ieee128.c += -mfloat128 -mabi=ieeelongdouble -Wno-psabi
CFLAGS-test-error2-ibm128.c += -mabi=ibmlongdouble -Wno-psabi

ifeq ($(run-built-tests),yes)
tests-special += $(objpfx)test-warn-ieee128.out
tests-special += $(objpfx)test-warn-ibm128.out

tests-special += $(objpfx)test-err-ieee128.out
tests-special += $(objpfx)test-err-ibm128.out
tests-special += $(objpfx)test-errx-ieee128.out
tests-special += $(objpfx)test-errx-ibm128.out
tests-special += $(objpfx)test-verr-ieee128.out
tests-special += $(objpfx)test-verr-ibm128.out
tests-special += $(objpfx)test-verrx-ieee128.out
tests-special += $(objpfx)test-verrx-ibm128.out

tests-special += $(objpfx)test-error1-ieee128.out
tests-special += $(objpfx)test-error1-ibm128.out
tests-special += $(objpfx)test-error2-ieee128.out
tests-special += $(objpfx)test-error2-ibm128.out
endif

$(objpfx)test-warn-%.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-warn-ldbl-compat.sh \
  $(objpfx)test-warn-%
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-err-%.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-err-ldbl-compat.sh \
  $(objpfx)test-err-%
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-errx-%.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-err-ldbl-compat.sh \
  $(objpfx)test-errx-%
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-verr-%.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-err-ldbl-compat.sh \
  $(objpfx)test-verr-%
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-verrx-%.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-err-ldbl-compat.sh \
  $(objpfx)test-verrx-%
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-error1-%.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-err-ldbl-compat.sh \
  $(objpfx)test-error1-%
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)

$(objpfx)test-error2-%.out: \
  ../sysdeps/ieee754/ldbl-128ibm-compat/test-err-ldbl-compat.sh \
  $(objpfx)test-error2-%
	$(SHELL) $^ '$(test-program-prefix)' $@; \
	$(evaluate-test)
endif

routines += $(foreach r,$(ldbl-extra-routines),ieee128-$(r))

ldbl-ibm128-files := $(objpfx)test-printf-ibm128^ \
		     $(objpfx)test-wprintf-ibm128^ \
		     $(objpfx)test-printf-chk-ibm128^ \
		     $(objpfx)test-wprintf-chk-ibm128^ \
		     $(objpfx)test-scanf-ibm128^ \
		     $(objpfx)test-wscanf-ibm128^ \
		     $(foreach r,$(ldbl-extra-routines),$(objpfx)$(r)^) \
		     $(foreach r,$(ldbl-extra-routines),$(objpfx)$(r)-internal^)
obj-suf-foreach = $(foreach suf,$(all-object-suffixes),$(subst ^,$(suf),$(1)))

# Removes -mabi=ieeelongdouble from ldbl-ibm128 files.  This is not required,
# but helps when analyzing the flags that were passed to the compiler.
$(call obj-suf-foreach,$(ldbl-ibm128-files)): \
  sysdep-CFLAGS := $(filter-out -mabi=ieeelongdouble -Wno-psabi, \
				$(sysdep-CFLAGS)) -mabi=ibmlongdouble
