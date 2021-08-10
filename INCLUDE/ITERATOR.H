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
# include <oldstl\iterator.h>
#else
# include <stlport\iterator>
#endif

#if !defined(__USING_STD_NAMES__) && defined(__cplusplus)
using namespace std;
#endif /* __USING_STD_NAMES__ */

