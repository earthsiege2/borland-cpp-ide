/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

///////////////////////////////////////////////////////////////////////////////
//
// xx.h
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//      We want "C" exception handling, RTTI support, and MT/DLL support
//

#define RTTI
#define EXCEPT_C
#define DTORX_DLLMT

///////////////////////////////////////////////////////////////////////////////
//
//      We want exception handling enabled, but not destructor cleanup.
//

#pragma option  -x -xd- -xv -Vo- -p- -Z- -O- -G-

#pragma warn    -par
#pragma warn    -ibc
#pragma warn    -aus

///////////////////////////////////////////////////////////////////////////////

#define _ss
#define __far
#define __near
#define __huge

#undef  THREAD
#ifdef  __MT__
#define THREAD          /* __thread */
#else
#define THREAD
#endif

#define FLAT_DLL

///////////////////////////////////////////////////////////////////////////////

#define EXHCC   __cdecl
#define SYSCC   __stdcall
#define DEFCC   __cdecl    _EXPFUNC
#define STDCC   __cdecl

#if defined(__DLL__)
#  define   EHCC  EXHCC _EXPFUNC
#else
#  define   EHCC  EXHCC _EXPFUNC
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <windows.h>

///////////////////////////////////////////////////////////////////////////////

#define FPDST
#define DPDST
#define CPDST

///////////////////////////////////////////////////////////////////////////////

//      We want the exception handling structures to be 1 byte aligned,
//      the compiler excepts this.

#pragma option  push    -a1

///////////////////////////////////////////////////////////////////////////////

#define TPDST   __far                   // type-id's and such are always 'far'

struct  TPDST   tpid;                   // type descriptor structure

typedef void     DPDST *dataPtr;
typedef void    (FPDST *codePtr)(void);

typedef tpid     TPDST *tpidPtr;
typedef char     TPDST *tpchPtr;

typedef struct  baseList                // base class list entry
{
        tpidPtr         blType;         // type   of this base
        unsigned        blOffs;         // offset of this base
        unsigned        blFlags;        // flags
}
        TPDST * baseListPtr;

typedef struct  dMemList                // destructible member list entry
{
        tpidPtr         dmType;         // type   of member
        unsigned        dmOffs;         // offset of member
}
        TPDST * dMemListPtr;

//
//  IMPORTANT:
//
//  If you change the following struct, you HAVE to change the C/C++
//  compiler, specifically the 'outputClassTypeId' function in the
//  cppfin.c file
//

struct  tpid                            // type descriptor
{
        unsigned        tpSize;         // size of type in bytes
        unsigned short  tpMask;         // attribute bits
        unsigned short  tpName;         // offset of start of the zero terminated name
                                        // where offset is relative from tpid base

        union
        {

                struct
                {
                        tpidPtr         tppBaseType;    // pointed-to type
                }
                                tpPtr;

                struct
                {
                        tpidPtr         tpaElemType;    // element type
                        unsigned long   tpaElemCount;   // element count
                }
                                tpArr;

                struct
                {
                        unsigned        tpcVptrOffs;    // offset of vtable pointer
                        unsigned        tpcFlags;       // more flags

                        // Only valid if (tpMask & TM_IS_CLASS)

                        unsigned short  tpcBaseList;    // offset of non-virt base list,
                                                        // where offset is relative from tpid base
                        unsigned short  tpcVbasList;    // offset of virtual  base list
                                                        // where offset is relative from tpid base

                        void    __far * tpcDlOpAddr;    // operator delete   addr
                        unsigned short  tpcDlOpMask;    // operator delete   convention

                        unsigned short  tpcDaOpMask;    // operator delete[] convention
                        void    __far * tpcDaOpAddr;    // operator delete[] addr


                        // Only valid if (tpcFlags & CF_HAS_DTOR), implies also (tpMask & TM_IS_CLASS)

                        unsigned        tpcDtorCount;   // dtor count - total
                        unsigned        tpcNVdtCount;   // dtor count - non-virtual

                        void    __far * tpcDtorAddr;    // destructor addr
                        unsigned short  tpcDtorMask;    // destructor convention

                        unsigned short  tpcDtMembers;   // offset of list of destructible members
                                                        // where offset is relative from tpid base

                        // The following field is only there is the CF_HAS_GUID flag
                        // is turned on.   To make it worse, you can NOT just access
                        // this field by name, you HAVE to go through the type_info::guid
                        // function in xxtype.cpp, which does all the magic to determine
                        // where this field is located exactly.

                        GUID            guid;
                }
                                tpClass;
        };

        // Following is the zero terminated name, padded with zero's to
        // the next dword boundary.

        // Optionally (if tpMask & TM_IS_CLASS), we have next:
        //  - non-virtual base list, terminated by a null pointer
        //  -     virtual base list, terminated by a null pointer

        // Optionally (if tpcFlags & CF_HAS_DTOR), we have next:
        //  - list of destructible members, terminated by a null pointer
};

//
//  IMPORTANT:
//
//  If you change the following flags, you HAVE to change the C/C++
//  compiler, specifically the 'outputClassTypeId' function in the
//  cppfin.c file
//

//  tpMask flags

#define TM_IS_STRUCT    0x0001
#define TM_IS_CLASS     0x0002

#define TM_IS_PTR       0x0010
#define TM_IS_REF       0x0020

#define TM_IS_VOIDPTR   0x0040

#define TM_LOCALTYPE    0x0080

#define TM_IS_CONST     0x0100
#define TM_IS_VOLATILE  0x0200

#define TM_IS_ARRAY     0x0400

#define IS_CLASS(m)     ((m) & TM_IS_CLASS )
#define IS_STRUC(m)     ((m) & TM_IS_STRUCT)

//      Class flags ('tpcFlags') follow:

#define CF_HAS_CTOR     0x00000001
#define CF_HAS_DTOR     0x00000002

#define CF_HAS_BASES    0x00000004
#define CF_HAS_VBASES   0x00000008

#define CF_HAS_VTABPTR  0x00000010
#define CF_HAS_VIRTDT   0x00000020
#define CF_HAS_RTTI     0x00000040

#ifdef  NEWXX
#define CF_DELPHICLASS  0x00000080
#endif

#define CF_HAS_FARVPTR  0x00001000

#define CF_HAS_GUID     0x00002000  // The tpcGuid field is valid and filled in

//      Variable cleanup descriptor flags:

#define DTCVF_PTRVAL    0x0001
#define DTCVF_DELPTR    0x0002
#define DTCVF_STACKVAR  0x0004
#define DTCVF_DELETE    0x0008
#define DTCVF_RETVAL    0x0010
#define DTCVF_RETCTX    0x0020
#define DTCVF_VECCNT    0x0040

#define DTCVF_DTCADJ    0x0100

#define DTCVF_THROWCTX  0x0200  // Used internally by the compiler?

#ifdef  NEWXX
#define DTCVF_THISCTX   0x0400
#endif

#define DTCVF_WITHVT    0x1000

//      Catch handler table flags:

#define CHF_ARG_CONST   0x0001
#define CHF_ARG_UNNAMED 0x0080

///////////////////////////////////////////////////////////////////////////////

// Flags that define the flags passed to ___ExceptionHandler (see xx.cpp)

#define XPF_NONE        0x0000
#define XPF_CATCHPAS    0x0001  // catch pascal exceptions
#define XPF_CATCHOS     0x0002  // catch OS exceptions
#define XPF_DELPHI      XPF_CATCHPAS | XPF_CATCHOS

#ifdef MAGIC
#define XPF_DEFAULT     XPF_DELPHI
#else
#define XPF_DEFAULT     XPF_NONE
#endif

extern unsigned long __xxPersonality;

// Current limitation:  XPF_CATCHPAS and XPF_CATCHOS cannot be
// independently set (eg they must both be the same value)
// --xmsb, 23 Aug 1999 15:36:49

///////////////////////////////////////////////////////////////////////////////

#define XX_SIGNATURE    "**BCCxh1"  // precedes our exception handler

///////////////////////////////////////////////////////////////////////////////

typedef unsigned char   BYTE;
typedef unsigned short  USHORT;

///////////////////////////////////////////////////////////////////////////////

#define CONTINUE_EXECUTION      0
#define CONTINUE_SEARCH         1

#define UNWINDING               2
#define UNWINDING_FOR_EXIT      4
#define UNWIND_IN_PROGRESS      (UNWINDING + UNWINDING_FOR_EXIT)

#define XCPT_UNWIND             0x00000026

///////////////////////////////////////////////////////////////////////////////

typedef int     (SYSCC*catchPtrTP)(void __far *, void _ss *, void __far *, void __far *);

typedef struct  _REGISTRATION_RECORD_   _ss *   PREGISTRATION_RECORD;
typedef struct  _REGISTRATION_RECORD_
{
        void    _ss *   ERRnext;        // next registration record in chain
        catchPtrTP      ERRcatcher;     // address of handler
}
        REGISTRATION_RECORD;

///////////////////////////////////////////////////////////////////////////////
//
//      The following are part of the OS-defined exception handling
//      mechanism.
//


typedef int     (*procPtr)(void);

extern  "C"     unsigned long   __stdcall __import RtlUnwind             (PREGISTRATION_RECORD, void *, unsigned);

#if !defined(_WINBASE_)
extern  "C"     procPtr         __stdcall __import GetProcAddress        (void *, const char *);
extern  "C"     void *          __stdcall __import GetModuleHandleA      (const char *);
#endif

#define RAISECC __stdcall       __import

#ifndef DELPHI_EXCEPTIONS
#if !defined(_WINBASE_)
extern  "C"     void            RAISECC         RaiseException        (unsigned long, unsigned long, unsigned long, unsigned long __far *);
#endif
#endif

#define END_OF_CHAIN    ((PREGISTRATION_RECORD)-1)

#include "_xx.h"
#include "xxdbg.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef  DIABLO
void      __lockDebuggerData(void);
void    __unlockDebuggerData(void);
#else
#define   __lockDebuggerData()
#define __unlockDebuggerData()
#endif

#ifdef  DIABLO
extern DebuggerData STDCC __export _DebuggerHookData;
extern  int     __cdecl __debuggerDisableTerminateCallback;
extern  void    STDCC   __debuggerHookFunction(void);
extern  void    STDCC   __debuggerExcListChange(void);
#endif



///////////////////////////////////////////////////////////////////////////////
//
//      The following are used by the C++ compiler only.
//

extern          void    STDCC   _CatchCleanup(void);

extern          void    STDCC   _ExceptionCleanup(void _ss *target);

extern          int    STDCC    _ExceptionHandler(void __far *_excPtr,
                                                  void   _ss *_errPtr,
                                                  void __far *_ctxPtr,
                                                  void __far *_dspPtr);
                                           


typedef void    (STDCC *         PFV)();
typedef void    (STDCC __far *  FPFV)();

namespace std {
extern          void    _RTLENTRY _EXPFUNC  unexpected(void);
extern          void    _RTLENTRY _EXPFUNC  terminate (void);

extern          PFV     _RTLENTRY _EXPFUNC  set_unexpected(PFV);
extern          PFV     _RTLENTRY _EXPFUNC  set_terminate (PFV);
} // std

#define OUR_TERMINATE_ADDR      (std::terminate )
#define OUR_UNEXPECTD_ADDR      (std::unexpected)

///////////////////////////////////////////////////////////////////////////////

#define CPP_EXCEPT_CODE 0x0EEFFACEUL            /* use something better, OK? */
#ifdef  PRONTO
#define PAS_EXCEPT_CODE 0x0EEDFADE
#endif
///////////////////////////////////////////////////////////////////////////////

typedef struct  _EXCEPTION_POINTERS EXCEPTION_PTRS, *PEXCEPTION_PTRS;
///////////////////////////////////////////////////////////////////////////////

struct  HD
{
        codePtr         HDhndPtr;       // addr of handler code
        tpidPtr         HDtypeID;       // type of the handler
        unsigned        HDflags;        // const/volatile/unnamed
        void    __far * HDcctrAddr;     // copy-ctor address
        unsigned        HDcctrMask;     // copy-ctor mask
};

struct  HTD
{
        unsigned        HTDargAddr;     // BP offset of handler arg
        unsigned        HTDargSize;     // size of handler arg
        HD              HTDtable[];     // table of handlers
};

///////////////////////////////////////////////////////////////////////////////

struct  DTT
{
        tpidPtr         dttType;
        unsigned        dttFlags;
        union
        {
                void    __far * dttAddress;
                unsigned        dttFrameOffs;
        };
};

///////////////////////////////////////////////////////////////////////////////

typedef unsigned int            dtorCntType;
typedef   signed int            dtorCntTypeSigned;

typedef struct
{
        tpidPtr TPDST * xtThrowLst;             // throw-list address or NULL
        unsigned        xtBPoffs;               // BP frame offset of ERR

        unsigned        xtTable[];              // context table follows ...
}
        EXCTAB, TPDST * EXCTABPTR;

typedef struct  ERRbc
{
        PREGISTRATION_RECORD    ERRcNext;       // next registration record
        catchPtrTP              ERRcCatcher;    // address of handler

        EXCTABPTR               ERRcXtab;       // addr of table of handlers

        unsigned                ERRcSPsv;       // saved (E)SP value

        unsigned short          ERRcCCtx;       // current context

#ifdef  EXCEPT_C
        struct
        {
                unsigned short  ERRcUnwind;     // unwinding flag
                unsigned long   ERRcExcCode;    // exception code
                void    _ss *   ERRcExcInfo;    // exception info
        }
                        ERRcInfo;
#endif

        dtorCntType     ERRcInitDtc;            // initial destructor count
        unsigned char   ERRflags;               // flags for hacks - see EF_*
}
        REGREC_BC, _ss *PREGREC_BC;

#define EF_DELETETHIS   0x01            // set if we need to delete 'this'

///////////////////////////////////////////////////////////////////////////////
// called by _ExceptionHandler (above)
extern "C"
int _RTLENTRY _EXPFUNC
___ExceptionHandler(	PEXCEPTION_RECORD excPtr,
			PREGREC_BC        errPtr,
			PCONTEXT          ctxPtr,
			void *           _dspPtr,
			unsigned long     OSEsp,
			unsigned long     OSEbp,
			unsigned long     OSEsi,
			unsigned long     OSEdi,
			unsigned long     OSEbx,
			unsigned long     flags);  // XPF_*

///////////////////////////////////////////////////////////////////////////////

typedef enum
{
        XB_FINALLY,                     /* 0 try/finally        ("C") */
        XB_EXCEXP,                      /* 1 try/except(expr )  ("C") */
        XB_EXCCNS,                      /* 2 try/except(const)  ("C") */
        XB_TRYCPP,                      /* 3 try                (C++) */
        XB_CATCH,                       /* 4 catch              (C++) */
        XB_DEST,                        /* 5 destructor cleanup (C++) */
}
        excBlockKind;

///////////////////////////////////////////////////////////////////////////////

#define XDF_ZEROPOINTER         0x00000001

#ifdef  DELPHI_EXCEPTIONS
#define XDF_OSEXCEPTION         0x00000002
#endif

#define XDF_ISDELPHIEXCEPTION   0x00000004
#define XDF_RETHROWN            0x00000008

typedef struct  __near  _exceptDesc     __far * excDscPtr;

typedef void   (*freeMemFP)(excDscPtr xdp);

typedef struct  __near  _exceptDesc
{
        excDscPtr       xdPrevious;     // previous exception or 0

        tpidPtr         xdTypeID;       // addr of type-id for thrown type
        tpidPtr TPDST * xdFriendList;   // friend list supplied to _ThrowExcept
        unsigned        xdFlags;        // flags passed to _ThrowExcept
        unsigned        xdSize;         // size of thrown value
        tpidPtr         xdBase;         // type-id of base type
        unsigned short  xdMask;         // type-id mask
        unsigned short  xdCflg;         // type-id class flags (or 0)

        freeMemFP       xdFreeFunc;     // function to free memory

        void    __far * xdCCaddr;       // copy-ctor addr
        unsigned        xdCCmask;       // copy-ctor mask

        PREGREC_BC      xdERRaddr;      // address of matching ERR (when found)
        HD      TPDST * xdHtabAdr;      // address of matching handler

        unsigned        xdContext;      // context of 'catch' block

        unsigned        xdThrowLine;    // source line no.  of throw statement
        unsigned char * xdThrowFile;    // source file name of throw statement

        tpidPtr         xdArgType;      // address of arg type descriptor
        void    _ss *   xdArgAddr;      // address of arg copy on stack
        char            xdArgBuff;      // arg stored in buffer
        char            xdArgCopy;      // arg copied to catch arg

        unsigned long   xdOSESP;        // esp of main OS exception handler
        unsigned long   xdOSERR;        // addr of the OS ERR on entry to _ExceptionHandler
        PCONTEXT        xdOSContext;    // CPU Context for an OS exception
        char            xdValue[];      // copy of thrown value
}
        exceptDesc;

///////////////////////////////////////////////////////////////////////////////

extern  "C"     void    __call_terminate (void);
extern  "C"     void    __call_unexpected(void);

///////////////////////////////////////////////////////////////////////////////

#ifdef  USE_XX_VARS
#define STGCL           extern
#define INIT(x)
#else
#define STGCL
#define INIT(x)         x
#endif

#if defined(_BUILDRTLDLL)
#define _XXDATA         __import
#else
#define _XXDATA
#endif

///////////////////////////////////////////////////////////////////////////////

STGCL   dtorCntType  *  STDCC           _DestructorCountPtr;

#ifdef  DTORX_DLLMT
extern  dtorCntType     STDCC           _DestructorCount;
#else
STGCL   dtorCntType     STDCC           _DestructorCount;
#endif

///////////////////////////////////////////////////////////////////////////////

STGCL   excDscPtr       STDCC   THREAD  __CPPexceptionList      INIT(=0);

STGCL   unsigned        STDCC   THREAD  __exceptFlags           INIT(=0);

#ifdef  DIABLO
STGCL   void    (STDCC *STDCC   THREAD  __debuggerHookFN)()     INIT(=__debuggerHookFunction);
STGCL   unsigned long  *STDCC   THREAD  __debuggerWatchingP     INIT(=0);
STGCL   DebuggerData   *STDCC   THREAD  __debuggerHookDataP     INIT(=0);
#endif

extern   FPFV   _XXDATA                 __terminatePTR;
extern   FPFV   _XXDATA                 __unexpectdPTR;

STGCL   char    *       STDCC   THREAD  __throwFileName         INIT(=0);
STGCL   unsigned        STDCC   THREAD  __throwLineNumber       INIT(=0);
STGCL   char    *       STDCC   THREAD  __throwExceptionName    INIT(=0);

STGCL   void    *       STDCC   THREAD  __exceptStaticBuffP     INIT(=0);
STGCL   void    *       STDCC   THREAD  __exceptMemAllocVars    INIT(=0);

STGCL   char            STDCC   THREAD  __ExceptStaticXbuff[128] INIT(={0});


///////////////////////////////////////////////////////////////////////////////

// These flags belong to the __exceptFlags variable.

#define XF_STATIC_BUFF_USED     0x00000001
#define XF_UNCAUGHT_EXCEPTION   0x00000002


///////////////////////////////////////////////////////////////////////////////

typedef struct
{
        excDscPtr       xvrCPPexceptionList;

        unsigned        xvrExceptFlags;

#ifdef  DIABLO
        void    (STDCC *  xvrDebuggerHookFN)();
        unsigned long *   xvrDebuggerWatchingP;
        DebuggerData *    xvrDebuggerHookDataP;
#endif

        char    *       xvrThrowFileName;
        unsigned        xvrThrowLineNumber;
        char    *       xvrThrowExceptionName;

        void    *       xvrExceptStaticBuffP;
        void    *       xvrExceptMemAllocVars;

        char            xvrExceptStaticXbuff[128];
}
        exceptVarRec,
        *exceptVarPtr;

#define getDTCount()    (*(dtorCntType *)((char *)__StackBase - sizeof(unsigned)                 ))

// Note: _Exception_list is automatically mapped by the compiler to [FS:0]

extern  __declspec(thread)      exceptVarRec    __xxInfo;

//#define getXVarPtr()    (*(exceptVarPtr*)((char *)__StackBase - sizeof(unsigned) - sizeof(void *)))
#define getXVarPtr()    (&__xxInfo)

#undef __CPPexceptionList
#undef __exceptFlags
#undef __throwFileName
#undef __throwLineNumber
#undef __throwExceptionName
#undef __exceptMemAllocVars
#undef __exceptStaticBuffP

#define __CPPexceptionList              (getXVarPtr()->xvrCPPexceptionList  )
#define __exceptFlags                   (getXVarPtr()->xvrExceptFlags       )
#define __throwFileName                 (getXVarPtr()->xvrThrowFileName     )
#define __throwLineNumber               (getXVarPtr()->xvrThrowLineNumber   )
#define __throwExceptionName            (getXVarPtr()->xvrThrowExceptionName)
#define __exceptMemAllocVars            (getXVarPtr()->xvrExceptMemAllocVars)
#define __exceptStaticBuffP             (getXVarPtr()->xvrExceptStaticBuffP )

#ifdef  DIABLO
#define __debuggerHookFunction          ((void (*)(void))(getXVarPtr()->xvrDebuggerHookDataP->p_hook_fcn))
#define __debuggerWatchingP             (getXVarPtr()->xvrDebuggerWatchingP )
#define __debuggerHookDataP             (getXVarPtr()->xvrDebuggerHookDataP )
#define __debuggerWatching              (*__debuggerWatchingP)
#endif

#define __ExceptStaticXbuff             (getXVarPtr()->xvrExceptStaticXbuff );

///////////////////////////////////////////////////////////////////////////////
// Some other function protos:

char    *       __typeIDname(tpidPtr id);
int             __isCompatTypeID(tpidPtr src, tpidPtr dst, int exact, tpidPtr TPDST * flist);
int             __isSameTypeID(tpidPtr tp1, tpidPtr tp2);
void    *       __adjustClassAdr(void * ptr, tpidPtr srctp, tpidPtr dsttp);

void _RTLENTRY _EXPFUNC _InitTermAndUnexPtrs(void);

///////////////////////////////////////////////////////////////////////////////

#pragma option  pop
