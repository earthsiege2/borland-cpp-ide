/*  locking.h

    Definitions for mode parameter of locking() function.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1990, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $ */

#if !defined(__LOCKING_H)
#define __LOCKING_H

#define LK_UNLCK  0     /* unlock file region */
#define LK_LOCK   1     /* lock file region, try for 10 seconds */
#define LK_NBLCK  2     /* lock file region, don't block */
#define LK_RLCK   3     /* same as LK_LOCK */
#define LK_NBRLCK 4     /* same as LK_NBLCK */

#endif  /* __LOCKING_H */
