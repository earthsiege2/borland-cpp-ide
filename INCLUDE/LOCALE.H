/* Locale.h - stub redirector for either _loc.h or locale.stl
*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#if !defined(__cplusplus)
# include <_loc.h>
#else /* __cplusplus */
# include <_loc.h>
# if defined(__USING_STD_NAMES__)
#  ifdef _USE_OLD_RW_STL
#   include <oldstl/locale.stl>
#  else
#   include <stlport/locale>
#  endif
# endif /* __USING_STD_NAMES__ */
#endif
