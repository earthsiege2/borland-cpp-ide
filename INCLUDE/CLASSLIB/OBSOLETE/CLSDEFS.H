/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CLSDEFS.H                                                             */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLSDEFS_H )
#define __CLSDEFS_H

#define BI_OLDNAMES

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

const hashValueType ERROR_CLASS_HASH_VALUE = 0;

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif
