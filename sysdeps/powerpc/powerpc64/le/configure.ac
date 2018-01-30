GLIBC_PROVIDES dnl See aclocal.m4 in the top level source directory.
# Local configure fragment for sysdeps/powerpc/powerpc64le.

dnl Require long double that is binary compatible with binary128
dnl floating point support on powerpc64le (available in GCC 7.0).
AC_CACHE_CHECK([if $CC supports binary128 floating point type],
	       libc_cv_compiler_powerpc64le_binary128_ok, [dnl
save_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -Werror -mfloat128"
AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
__float128 a, b, c, d, e;
int i;

__float128
foobar (__float128 x)
{
  a = __builtin_nansf128 ("0");
  b = __builtin_huge_valf128 ();
  c = __builtin_inff128 ();
  d = __builtin_fabsf128 (x);
  e = __builtin_nanf128 ("0");
  i = __builtin_signbit (x);
  return __builtin_copysignf128 (x, x);
}
]])],
		  [libc_cv_compiler_powerpc64le_binary128_ok=yes],
		  [libc_cv_compiler_powerpc64le_binary128_ok=no])
CFLAGS="$save_CFLAGS"])
AS_IF([test "$libc_cv_compiler_powerpc64le_binary128_ok" != "yes"],
      [critic_missing="$critic_missing binary128 floating point type (GCC >= 7.0) is required on powerpc64le."])

dnl Require at least POWER8 on powerpc64le
OLD_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS $libc_cv_cc_submachine"
AC_CACHE_CHECK([if the target machine is at least POWER8],
	       libc_cv_target_power8_ok, [
AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#ifndef _ARCH_PWR8
#error invalid target architecture
#endif
]])],
	       [libc_cv_target_power8_ok=yes],
	       [libc_cv_target_power8_ok=no])])
AS_IF([test "$libc_cv_target_power8_ok" != "yes"],
      [critic_missing="$critic_missing POWER8 or newer is required on powerpc64le."])
CFLAGS="$OLD_CFLAGS"

test -n "$critic_missing" && AC_MSG_ERROR([*** $critic_missing])
