/*  cassert.h

    Standard C header file wrapper for assert.h
*/

/* $Copyright: 1997$ */
/* $Revision: 9.4 $ */

#define  __USING_CNAME__
#include <assert.h>
#ifndef __ASSERT_H_USING_LIST
# define __ASSERT_H_USING_LIST
  using std::_assert;
  using std::__assertfail;
#endif
#undef   __USING_CNAME__
