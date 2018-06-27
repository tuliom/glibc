#ifndef _ERR_H
#include <misc/err.h>

# ifndef _ISOMAC

#  if !__HAVE_DISTINCT_FLOAT128 \
      || (__HAVE_DISTINCT_FLOAT128 && __LDBL_MANT_DIG__ != 113)
libc_hidden_proto (warn)
libc_hidden_proto (warnx)
libc_hidden_proto (vwarn)
libc_hidden_proto (vwarnx)
libc_hidden_proto (verr)
libc_hidden_proto (verrx)
#  endif
# endif /* !_ISOMAC */
#endif /* err.h */
