/*  cstring.h

    Standard C header file wrapper for string.h
*/

/* $Copyright: 1997$ */
/* $Revision: 1.3.2.1 $ */

#define  __USING_CNAME__
#include <_str.h>
#if !defined(__USING_STD_NAMES__) && !defined(__STD_STRING)
/* Include the STL string class for backwards support if the user includes
   <cstring.h>.  Else this is an include of <cstring> and our previous include
   of _str.h will suffice.
*/
#  undef   __USING_CNAME__
# ifdef __USE_OLD_RW_STL
#  include <oldstl/string.stl>
# else
#  include <stlport/string>
#endif
    using std::string;
#endif  /* __USING_STD_NAMES__ */

#undef   __USING_CNAME__
