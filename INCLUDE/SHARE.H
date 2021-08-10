/*  share.h

    File sharing mode for use with sopen.
    See DOS function 3Dh for definition.

*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined( __SHARE_H )
#define __SHARE_H

#if !defined( ___DEFS_H )
#include <_defs.h>
#endif

#define SH_COMPAT      0x00    /* compatibility mode */
#define SH_DENYRW      0x10    /* deny read/write mode */
#define SH_DENYWR      0x20    /* deny write mode */
#define SH_DENYRD      0x30    /* deny read mode */
#define SH_DENYNO      0x40    /* deny none mode */

#define SH_DENYNONE    SH_DENYNO

#endif  /* __SHARE_H */

