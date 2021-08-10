/*  fcntl.h

    Define flag values accessible to open.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.5  $ */

#if !defined(__FCNTL_H)
#define __FCNTL_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

#if defined(__cplusplus)
extern "C" {
#endif
int _RTLENTRY _EXPFUNC _pipe(int *__phandles, unsigned int __psize, int __textmode);
#if defined(__cplusplus)
}
#endif

extern int _RTLENTRY _fmode;

/* The first three can only be set by open */

#define O_RDONLY    0
#define O_WRONLY    1
#define O_RDWR      2
#define O_ACCMODE   3       /* mask for file access modes */

/* Flag values for open only */

#define O_CREAT     0x0100  /* create and open file */
#define O_TRUNC     0x0200  /* open with truncation */
#define O_EXCL      0x0400  /* exclusive open */

/* The "open flags" defined above are not needed after open, hence they
   are re-used for other purposes when the file is running.  Sorry, it's
   getting crowded !
*/
#define _O_RUNFLAGS 0x0700
#define _O_WRITABLE 0x0100 /* file is not read-only */
#define _O_EOF      0x0200 /* set when text file hits ^Z   */

/* a file in append mode may be written to only at its end.
*/
#define O_APPEND    0x0800  /* to end of file */

/* MSDOS special bits */

#define O_CHANGED   0x1000  /* user may read these bits, but    */
#define O_DEVICE    0x2000  /*   only RTL\io functions may touch.   */
#define O_TEXT      0x4000  /* CR-LF translation    */
#define O_BINARY    0x8000  /* no translation   */

/* DOS 3.x options */

#define O_NOINHERIT 0x80
#define O_DENYALL   0x10
#define O_DENYWRITE 0x20
#define O_DENYREAD  0x30
#define O_DENYNONE  0x40

/* MSC compatible versions */
#define _O_APPEND      O_APPEND
#define _O_BINARY      O_BINARY
#define _O_CREAT       O_CREAT
#define _O_EXCL        O_EXCL
#define _O_NOINHERIT   O_NOINHERIT
#define _O_RANDOM      O_RANDOM
#define _O_RAW         O_BINARY
#define _O_RDONLY      O_RDONLY
#define _O_RDWR        O_RDWR
#define _O_TEXT        O_TEXT
#define _O_TRUNC       O_TRUNC
#define _O_WRONLY      O_WRONLY

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#endif  /* __FCNTL_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__FCNTL_H_USING_LIST)
#define __FCNTL_H_USING_LIST
    using std::_pipe;
    using std::_fmode;
#endif /* __USING_CNAME__ */
