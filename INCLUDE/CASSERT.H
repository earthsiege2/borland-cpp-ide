/*  cassert.h

    Standard C header file wrapper for assert.h
*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1997, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $ */

#define  __USING_CNAME__
#include <assert.h>
#ifndef __ASSERT_H_USING_LIST
# define __ASSERT_H_USING_LIST
  using std::_assert;
  using std::__assertfail;
#endif
#undef   __USING_CNAME__
