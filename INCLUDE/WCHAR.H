/* WCHAR.H - Most of this stuff is in TCHAR.H, so we include that */

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1997, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.7.2.1 $ */

#ifndef __WCHAR_H
#define __WCHAR_H

#if !defined(__TCHAR_H)
#  include <tchar.h>
#endif

/* ************************************************************
 * FIXME: This breaks IDE build right now. Need to talk to
 * IDE R&D to get ibmnewdom reconfigured for use with stdint.h
 **************************************************************
#ifndef __STDINT_H
# include <stdint.h>
#endif

*/

#define wmemcpy _wmemcpy
#define wmemchr _wmemchr
#define wmemset _wmemset

#endif /* __WCHAR_H */