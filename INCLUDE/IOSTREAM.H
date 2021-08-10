/**************************************************************************
 *  Wrapper header file used to select STL via defines.
 *  Default is STLport.
 **************************************************************************/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#ifdef _USE_OLD_RW_STL
# include <oldstl\iostream.h>
#else
# include <stlport\iostream>
/* Define __STD_IOSTREAM__ here to cause sysclass.h to define
   VCL_IOSTREAM which causes certian iostream operators to get defined
*/
#define __STD_IOSTREAM__
#endif

#if !defined(__USING_STD_NAMES__) && defined(__cplusplus)
using namespace std;
#endif /* __USING_STD_NAMES__ */

