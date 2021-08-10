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
# error Must use STLport for rope.h
#else
# include <stlport\rope>
#endif

#if !defined(__USING_STD_NAMES__) && defined(__cplusplus)
using namespace std;
#endif /* __USING_STD_NAMES__ */
