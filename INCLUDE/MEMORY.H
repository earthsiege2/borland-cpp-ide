/* Memory.h - stub redirector for either mem.h or memory.stl
*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#if !defined(__cplusplus)
#  include <mem.h>
#else /* __cplusplus */
#  if !defined(__USING_STD_NAMES__)
#    include <mem.h>
#  else
#    ifdef _USE_OLD_RW_STL
#      include <oldstl/memory.stl>
#    else
#      include <stlport\memory>
#    endif
#  endif
#endif  
