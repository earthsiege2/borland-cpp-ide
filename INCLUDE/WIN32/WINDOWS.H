/*++ BUILD Version: 0001    Increment this if a change has global effects

Copyright (c) 1985-1996, Microsoft Corporation

Module Name:


    windows.h

Abstract:

    Master include file for Windows applications.

--*/

#ifndef _WINDOWS_
#define _WINDOWS_
#pragma option -b


#ifndef WINVER
#define WINVER 0x0400
#endif

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

/*  If defined, the following flags inhibit definition
 *     of the indicated items.
 *
 *  NOGDICAPMASKS     - CC_*, LC_*, PC_*, CP_*, TC_*, RC_
 *  NOVIRTUALKEYCODES - VK_*
 *  NOWINMESSAGES     - WM_*, EM_*, LB_*, CB_*
 *  NOWINSTYLES       - WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
 *  NOSYSMETRICS      - SM_*
 *  NOMENUS           - MF_*
 *  NOICONS           - IDI_*
 *  NOKEYSTATES       - MK_*
 *  NOSYSCOMMANDS     - SC_*
 *  NORASTEROPS       - Binary and Tertiary raster ops
 *  NOSHOWWINDOW      - SW_*
 *  OEMRESOURCE       - OEM Resource values
 *  NOATOM            - Atom Manager routines
 *  NOCLIPBOARD       - Clipboard routines
 *  NOCOLOR           - Screen colors
 *  NOCTLMGR          - Control and Dialog routines
 *  NODRAWTEXT        - DrawText() and DT_*
 *  NOGDI             - All GDI defines and routines
 *  NOKERNEL          - All KERNEL defines and routines
 *  NOUSER            - All USER defines and routines
 *  NONLS             - All NLS defines and routines
 *  NOMB              - MB_* and MessageBox()
 *  NOMEMMGR          - GMEM_*, LMEM_*, GHND, LHND, associated routines
 *  NOMETAFILE        - typedef METAFILEPICT
 *  NOMINMAX          - Macros min(a,b) and max(a,b)
 *  NOMSG             - typedef MSG and associated routines
 *  NOOPENFILE        - OpenFile(), OemToAnsi, AnsiToOem, and OF_*
 *  NOSCROLL          - SB_* and scrolling routines
 *  NOSERVICE         - All Service Controller routines, SERVICE_ equates, etc.
 *  NOSOUND           - Sound driver routines
 *  NOTEXTMETRIC      - typedef TEXTMETRIC and associated routines
 *  NOWH              - SetWindowsHook and WH_*
 *  NOWINOFFSETS      - GWL_*, GCL_*, associated routines
 *  NOCOMM            - COMM driver routines
 *  NOKANJI           - Kanji support stuff.
 *  NOHELP            - Help engine interface.
 *  NOPROFILER        - Profiler interface.
 *  NODEFERWINDOWPOS  - DeferWindowPos routines
 *  NOMCX             - Modem Configuration Extensions
 */

#if defined(RC_INVOKED) && !defined(NOWINRES)

#pragma option -b.
#include <winresrc.h>
#pragma option -b

#else

#if defined(RC_INVOKED)
/* Turn off a bunch of stuff to ensure that RC files compile OK. */
#define NOATOM
#define NOGDI
#define NOGDICAPMASKS
#define NOMETAFILE
#define NOMINMAX
#define NOMSG
#define NOOPENFILE
#define NORASTEROPS
#define NOSCROLL
#define NOSOUND
#define NOSYSMETRICS
#define NOTEXTMETRIC
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOCRYPT
#define NOMCX
#endif

#if defined(__BORLANDC__)
    #if !defined(__MFC_COMPAT__)
        #undef  _ANONYMOUS_STRUCT    /* The correct term */
    #else
        #define _ANONYMOUS_STRUCT    /* on for __MFC_COMPAT__ support */
    #endif
    #if defined(__cplusplus)
        #ifndef _WCHAR_T_DEFINED
           #define _WCHAR_T_DEFINED
        #endif
	#define __inline  inline
    #else
        #undef  _ANONYMOUS_UNION    /* The correct term */
        #define NONAMELESSUNION     /* Incorrect term, but MS keeps using it! */
	#define __inline
    #endif
    #if defined(_UNICODE)
        #define UNICODE
    #endif
#endif

#if !defined(_PPC_) && !defined(_ALPHA_) && !defined(_MIPS_) && !defined(_X86_) && defined(_M_IX86)
#define _X86_
#endif

#if !defined(_PPC_) && !defined(_ALPHA_) && !defined(_X86_) && !defined(_MIPS_) && defined(_M_MRX000)
#define _MIPS_
#endif

#if !defined(_PPC_) && !defined(_ALPHA_) && !defined(_X86_) && !defined(_MIPS_) && defined(_M_ALPHA)
#define _ALPHA_
#endif

#if !defined(_PPC_) && !defined(_ALPHA_) && !defined(_X86_) && !defined(_MIPS_) && defined(_M_PPC)
#define _PPC_
#endif

#ifndef RC_INVOKED
#if     ( _MSC_VER >= 800 )
#pragma warning(disable:4001)
#endif
#pragma option -b.
#include <excpt.h>
#pragma option -b
#pragma option -b.
#include <stdarg.h>
#pragma option -b
#endif /* RC_INVOKED */

#pragma option -b.
#include <windef.h>
#pragma option -b
#pragma option -b.
#include <winbase.h>
#pragma option -b
#pragma option -b.
#include <wingdi.h>
#pragma option -b
#pragma option -b.
#include <winuser.h>
#pragma option -b
#pragma option -b.
#include <winnls.h>
#pragma option -b
#pragma option -b.
#include <wincon.h>
#pragma option -b
#pragma option -b.
#include <winver.h>
#pragma option -b
#pragma option -b.
#include <winreg.h>
#pragma option -b
#pragma option -b.
#include <winnetwk.h>
#pragma option -b

#ifndef WIN32_LEAN_AND_MEAN
#pragma option -b.
#include <cderr.h>
#pragma option -b
#pragma option -b.
#include <dde.h>
#pragma option -b
#pragma option -b.
#include <ddeml.h>
#pragma option -b
#pragma option -b.
#include <dlgs.h>
#pragma option -b
#pragma option -b.
#include <lzexpand.h>
#pragma option -b
#pragma option -b.
#include <mmsystem.h>
#pragma option -b
#pragma option -b.
#include <nb30.h>
#pragma option -b
#pragma option -b.
#include <rpc.h>
#pragma option -b
#pragma option -b.
#include <shellapi.h>
#pragma option -b
#pragma option -b.
#include <winperf.h>
#pragma option -b
#if(_WIN32_WINNT >= 0x0400)
#pragma option -b.
#include <winsock2.h>
#pragma option -b
#pragma option -b.
#include <mswsock.h>
#pragma option -b
#else
#pragma option -b.
#include <winsock.h>
#pragma option -b
#endif /* _WIN32_WINNT >=  0x0400 */

#if(_WIN32_WINNT >= 0x0400)
#ifndef NOCRYPT
#pragma option -b.
#include <wincrypt.h>
#pragma option -b
#endif
#endif /* _WIN32_WINNT >=  0x0400 */

#ifndef NOGDI
#pragma option -b.
#include <commdlg.h>
#pragma option -b
#pragma option -b.
#include <winspool.h>
#pragma option -b
#ifdef INC_OLE1
#pragma option -b.
#include <ole.h>
#pragma option -b
#else
#pragma option -b.
#include <ole2.h>
#pragma option -b
#endif /* !INC_OLE1 */
#endif /* !NOGDI */
#endif /* WIN32_LEAN_AND_MEAN */

#ifdef INC_OLE2
#pragma option -b.
#include <ole2.h>
#pragma option -b
#endif /* INC_OLE2 */

#ifndef NOSERVICE
#pragma option -b.
#include <winsvc.h>
#pragma option -b
#endif

#if(WINVER >= 0x0400)
#ifndef NOMCX
#pragma option -b.
#include <win32\mcx.h>
#pragma option -b
#endif /* NOMCX */

#ifndef NOIME
#pragma option -b.
#include <win32\imm.h>
#pragma option -b
#endif
#endif /* WINVER >= 0x0400 */

#ifndef RC_INVOKED
#if     ( _MSC_VER >= 800 )
#pragma warning(default:4001)
#endif
#endif /* RC_INVOKED */

#endif /* RC_INVOKED */

#endif /* _INC_WINDOWS */
#pragma option -b.
#endif /* _WINDOWS_ */
