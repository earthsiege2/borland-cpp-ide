/*-----------------------------------------------------------------------*
 * filename - predecl.cpp
 *
 *   This file predeclares a few items that need to be added into the RTL
 *   libs before the STL files.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.7.2.1 $        */

#include <stdcomp.h>
#include <rw/stddefs.h>
#include <rw/rwstderr.h>
#include <stdexcept>
#include <typeinfo.h>

using namespace std;

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#ifdef _RWSTD_MULTI_THREAD
#include <rw/stdmutex.h>
  static _RWSTDMutex __Borland_Test_mutex;
#endif

#ifndef _RWSTD_NO_NAMESPACE
}
#endif


static	bad_cast    __bad_cast_instance;
static	bad_typeid  __bad_typeid_instance;

static	bool	__generate_bad_cast_id()
{
	return typeid(__bad_cast_instance) == typeid(__bad_typeid_instance);
}


