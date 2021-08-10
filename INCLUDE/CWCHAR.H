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
# include <oldstl\cwchar.h>
#else
# include <stlport\cwchar>
#endif
