/*------------------------------------------------------------------------
 * filename - asmrules.h
 *
 *      Rules & structures useful for in-line assembler
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#pragma inline
#pragma warn -asm

/****
#define  LPROG  (4 == sizeof (void (*) (void)))
#define  LDATA  (4 == sizeof (void *))
****/
#define  LDATA 1
#define  LPROG 1

#define  W0(ea) (word ptr (ea))
#define  W1(ea) (word ptr (ea) [2])

#define  BY0(ea) (byte ptr (ea))
#define  BY1(ea) (byte ptr (ea) [1])

#define  FLOAT(ea)  (dword ptr (ea))
#define  DOUBLE(ea) (qword ptr (ea))
#define  LONGDOUBLE(ea) (tbyte ptr (ea))

#define  LES_  LES
#define  ES_   ES:
#define  SS_   SS:
#define  DPTR_(ea)  (dword ptr (ea))
#define  dPtrSize    4
#define  pushDS_     asm     push    DS
#define  LDS_        LDS
#define  popDS_      asm     pop     DS

#define  CPTR_(ea)  (dword ptr (ea))
#define  EXTPROC(x)  (far ptr (x))
#define  cPtrSize    4

/* Use these macros inside of a function to force an si or di save/restore */
#define SaveSI                  asm     __savesi equ si
#define SaveDI                  asm     __savedi equ di

/* Use these macros when you want to return a value in DX:AX and
   avoid a warning messages being generated.  Ex: return( MK_LONG ); */
#define MK_LONG   (long)(void *)(((_DX) << 16) | (_AX))
#define MK_ULONG  (unsigned long)(void *)(((_DX) << 16) | (_AX))
