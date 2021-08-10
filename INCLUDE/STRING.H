/* String.h - stub redirector for either _str.h or string.stl
*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#if !defined(__cplusplus)
# include <_str.h>
#else /* __cplusplus */
# include <_str.h>
# if defined(__USING_STD_NAMES__)
#  ifdef _USE_OLD_RW_STL
#   include <oldstl/string.stl>
#  else
#   include <stlport/string>
#  endif
# endif /* __USING_STD_NAMES__ */
#endif