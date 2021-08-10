/* Borland version of Microsoft CRTDBG.H header file
   This is used by MFC and ATL.
*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $ */

#ifndef _INC_CRTDBG
#define _INC_CRTDBG

#ifndef __UTILCLS_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif
/* Prototypes for internal RTL helper functions: */
void _ErrorMessage(const char *__message);
void _ErrorExit   (const char *__message);
#ifdef __cplusplus
}
#endif

/* Asserts */

#if !defined(_DEBUG)

#define _ASSERT(expr) ((void)0)
#define _ASSERTE(expr) ((void)0)

#else /* !defined(_DEBUG) */

#define _ASSERT(a) _ASSERTE(a)
#define  _ASSERTE(expr) do {                                                            \
  if (!(expr) && __ASSERTE_Helper (#expr, __FILE__, __LINE__) == IDCANCEL)              \
    ::DebugBreak();                                                                     \
} while (0)

/* _ASSERTE helper routine returns: MB_YES, MB_NO or MB_CANCEL
*/
__inline int __ASSERTE_Helper(bool expr, char *file, int line)
{
  TCHAR msg[256*2];
  ::wsprintf(msg, _T("%s failed - %s/%d"), expr, file, line);
/*  throw (msg); */
  _ErrorExit(msg);
  return 0; /* Never really gets here */
}

#endif /* !defined(_DEBUG) */

#endif /* __UTILCLS_H */

#endif /* _INC_CRTDBG */
