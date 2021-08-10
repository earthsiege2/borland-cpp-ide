//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\compat.h
//----------------------------------------------------------------------------
#if !defined(__OWL_COMPAT_H)
#define __OWL_COMPAT_H

#if !defined(BI_OLDNAMES)
#define BI_OLDNAMES
#endif

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif

struct TMessage {
  HWND  Receiver;
  WORD  Message;

  union {
    WORD  WParam;

    struct tagWP {
      BYTE Lo;
      BYTE Hi;
    } WP;
  };

  union {
    DWORD  LParam;

    struct tagLP {
      WORD Lo;
      WORD Hi;
    } LP;
  };

  long  Result;
};

TMessage _OWLFUNC __GetTMessage();

//
// Constants for application messages
//
#define WM_FIRST        0x0000  // 0x0000- 0x7FFF window messages
#define WM_INTERNAL     0x7F00  // 0x7F00- 0x7FFF reserved for internal use
#define ID_FIRST        0x8000  // 0x8000- 0x8FFF child id messages
#define ID_INTERNAL     0x8F00  // 0x8F00- 0x8FFF reserved for internal use
#define NF_FIRST        0x9000  // 0x9000- 0x9FFF notification messages
#define NF_INTERNAL     0x9F00  // 0x9F00- 0x9FFF reserved for internal use
#define CM_FIRST        0xA000  // 0xA000- 0xFFFF command messages
#define CM_INTERNAL     0xFF00  // 0xFF00- 0xFFFF reserved for internal use
#define WM_COUNT        0x8000  // num of window msgs
#define ID_COUNT        0x1000  // num of child id msgs
#define NF_COUNT        0x1000  // num of notification msgs
#define CM_COUNT        0x6000  // num of command msgs

#define WM_RESERVED             WM_INTERNAL - WM_FIRST

#define ID_RESERVED             ID_INTERNAL - Id_FIRST
#define ID_FIRSTMDICHILD        ID_RESERVED + 1
#define ID_MDICLIENT            ID_RESERVED + 2

#define CM_RESERVED             CM_INTERNAL - CM_FIRST


//
// Error conditions
//
#define EM_INVALIDCHILD         -1
#define EM_INVALIDCLIENT        -2
#define EM_INVALIDMAINWINDOW    -3
#define EM_INVALIDMODULE        -4
#define EM_INVALIDWINDOW        -5
#define EM_OUTOFMEMORY          -6


typedef int _FAR & Rint;
typedef int _FAR * Pint;
typedef void _FAR * Pvoid;
typedef void _FAR * _FAR & RPvoid;
typedef char _FAR * Pchar;
typedef const char _FAR * PCchar;
typedef const void _FAR * PCvoid;

#endif  // __OWL_COMPAT_H
