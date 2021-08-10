//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.7  $
//
// Defines WIN95 specific macros/structures for use with pre-4.0 versions of
// the WINDOWS.H header.
//
//----------------------------------------------------------------------------
#if defined(_Windows)
#if !defined(SERVICES_WIN95_16_H)
#define SERVICES_WIN95_16_H

//
// Check that WINDOWS.H has been included
//
#if !defined(WINVER)
# error  WINVER must be defined. Include WINDOWS.H before WIN95_16.H
#endif
#if (WINVER < 0x030a)
# error  Requires version of WINDOWS.H where WINVER >= 0x030a
#endif

//
// This header is only necessary if we're using an earlier
// version of WINDOWS.H
//
#if (WINVER < 0x0400)

typedef struct tagNMHDR
{
#ifdef tagWND
    HWND_16 hwndFrom;
#else
    HWND  hwndFrom;
#endif
    WORD  _wDummy1;
    UINT  idFrom;
    WORD  _wDummy2;
    UINT  code;
    WORD  _wDummy3;
}   NMHDR;
typedef NMHDR FAR * LPNMHDR;

#define WM_NOTIFY       0x004E
#define WM_CONTEXTMENU  0x007B

typedef WORD            WCHAR;

/* Image type */
#define DST_COMPLEX     0x0000
#define DST_TEXT        0x0001
#define DST_PREFIXTEXT  0x0002
#define DST_ICON        0x0003
#define DST_BITMAP      0x0004

/* State type */
#define DSS_NORMAL      0x0000
#define DSS_UNION       0x0010  /* Old gray string appearance */
#define DSS_DISABLED    0x0020
#define DSS_MONO        0x0080
#define DSS_RIGHT       0x8000

#ifdef STRICT
typedef BOOL (CALLBACK* DRAWSTATEPROC)(HDC, LPARAM, WPARAM, int, int);
#else
typedef FARPROC DRAWSTATEPROC;
#endif
BOOL    WINAPI DrawState(HDC, HBRUSH, DRAWSTATEPROC, LPARAM, WPARAM, int, int, int, int, UINT);

#if !defined(BI_BITFIELDS)
# define BI_BITFIELDS 3L
#endif

#if !defined(REG_SZ)
# define  REG_SZ              1
#endif
#if !defined(HKEY_CLASSES_ROOT)
# define  HKEY_CLASSES_ROOT   1
#endif

// When compiling a 16-bit app, wide-string types need to be redefined
// as ANSI types to avoid compiler complaints.  The problem arises
// because we include common control headers in 16-bit compilation.
// (16-bit apps don't use the wide-string declarations, but bcc complains
// because WINDOWS.H doesn't define them.)
//

#if !defined(__FLAT__)
typedef char far* LPSTR;
typedef LPSTR LPCWSTR;
typedef LPSTR LPWSTR;
#endif

// Plays games with COMMCTRL.H so that we can get the WIN95 goodies
// even when using an earlier version of the 16-bit version of
// WINDOWS.H
//
#undef  WINVER
#define WINVER      0x0400
#include <commctrl.h>
#undef  WINVER
#define WINVER      0x030a

#endif  // WINVER < 0x0400
#endif  // SERVICES_WIN95_16_H
#endif  // _Windows
