/*  fcntl.h

    Define flag values accessible to open.

*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__FCNTL_H)
#define __FCNTL_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#if defined(__FLAT__)

#if defined(__cplusplus)
extern "C" {
#endif
int _RTLENTRY _EXPFUNC _pipe(int *phandles, unsigned int psize, int textmode);
#if defined(__cplusplus)
}
#endif
#endif  /* __FLAT__ */

extern int _RTLENTRY _fmode;

/* The first three can only be set by open */

#if !defined(__FLAT__)
#define O_RDONLY    1
#define O_WRONLY    2
#define O_RDWR      4
#else
#define O_RDONLY    0
#define O_WRONLY    1
#define O_RDWR      2
#define O_ACCMODE   3       /* mask for file access modes */
#endif  /* __FLAT__ */

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


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __FCNTL_H */

