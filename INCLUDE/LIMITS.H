/* Limits.h - stub redirector for either _lim.h or limits.stl
*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#if !defined(__cplusplus)
# include <_lim.h>
#else /* __cplusplus */
# include <_lim.h>
# if defined(__USING_STD_NAMES__)
#  ifdef _USE_OLD_RW_STL
#   include <oldstl/limits.stl>
#  else
#   include <stlport/limits>
#  endif
# endif /* __USING_STD_NAMES__ */
#endif