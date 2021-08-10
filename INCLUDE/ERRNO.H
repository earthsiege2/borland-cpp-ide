/*  errno.h

    Defines the system error variable errno and the error
    numbers set by system calls. Errors which exist in Unix(tm)
    but not MSDOS have value -1.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.6  $ */

#ifndef __ERRNO_H
#define __ERRNO_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#ifdef __cplusplus
namespace std {
extern "C" {
#endif /* __cplusplus */

#if !defined(RC_INVOKED)


#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


/*  Dos Error Codes */

#define EZERO      0    /* Error 0                          */
#define EINVFNC    1    /* Invalid function number          */
#define ENOFILE    2    /* File not found                   */
#define ENOPATH    3    /* Path not found                   */
#define ECONTR     7    /* Memory blocks destroyed          */
#define EINVMEM    9    /* Invalid memory block address     */
#define EINVENV   10    /* Invalid environment              */
#define EINVFMT   11    /* Invalid format                   */
#define EINVACC   12    /* Invalid access code              */
#define EINVDAT   13    /* Invalid data                     */
#define EINVDRV   15    /* Invalid drive specified          */
#define ECURDIR   16    /* Attempt to remove CurDir         */
#define ENOTSAM   17    /* Not same device                  */
#define ENMFILE   18    /* No more files                    */

#define ENOENT     2    /* No such file or directory        */
#define EMFILE     4    /* Too many open files              */
#define EACCES     5    /* Permission denied                */
#define EBADF      6    /* Bad file number                  */
#define ENOMEM     8    /* Not enough core                  */
#define EFAULT    14    /* Unknown error                    */
#define ENODEV    15    /* No such device                   */
#define EINVAL    19    /* Invalid argument                 */
#define E2BIG     20    /* Arg list too long                */
#define ENOEXEC   21    /* Exec format error                */
#define EXDEV     22    /* Cross-device link                */
#define ENFILE    23    /* Too many open files              */
#define ECHILD    24    /* No child process                 */
#define ENOTTY    25    /* UNIX - not MSDOS                 */
#define ETXTBSY   26    /* UNIX - not MSDOS                 */
#define EFBIG     27    /* UNIX - not MSDOS                 */
#define ENOSPC    28    /* No space left on device          */
#define ESPIPE    29    /* Illegal seek                     */
#define EROFS     30    /* Read-only file system            */
#define EMLINK    31    /* UNIX - not MSDOS                 */
#define EPIPE     32    /* Broken pipe                      */
#define EDOM      33    /* Math argument                    */
#define ERANGE    34    /* Result too large                 */
#define EEXIST    35    /* File already exists              */
#define EDEADLOCK 36    /* Locking violation                */
#define EPERM     37    /* Operation not permitted          */
#define ESRCH     38    /* UNIX - not MSDOS                 */
#define EINTR     39    /* Interrupted function call        */
#define EIO       40    /* Input/output error               */
#define ENXIO     41    /* No such device or address        */
#define EAGAIN    42    /* Resource temporarily unavailable */
#define ENOTBLK   43    /* UNIX - not MSDOS                 */
#define EBUSY     44    /* Resource busy                    */
#define ENOTDIR   45    /* UNIX - not MSDOS                 */
#define EISDIR    46    /* UNIX - not MSDOS                 */
#define EUCLEAN   47    /* UNIX - not MSDOS                 */
#define ENAMETOOLONG 48 /* Filename too long                */
#define ENOTEMPTY 49    /* Directory not empty              */

#if !defined(__STDC__)
#define sys_nerr     _sys_nerr
#define sys_errlist  _sys_errlist
#endif

#ifdef _MT

#ifdef __cplusplus
extern "C" {
#endif
extern  int * _RTLENTRY _EXPFUNC __errno(void);
extern  int * _RTLENTRY _EXPFUNC __doserrno(void);
#ifdef  __cplusplus
}
#endif
#define errno (*__errno())
#define _doserrno (*__doserrno())

#else

extern  int _RTLENTRY  _EXPDATA errno;
extern  int _RTLENTRY  _EXPDATA _doserrno;

#endif

extern  int   _RTLENTRY _EXPDATA _sys_nerr;
extern char * _RTLENTRY _EXPDATA _sys_errlist[];

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif


#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // "C"
} // std
#endif /* __cplusplus */

#endif  /* __ERRNO_H  */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__ERRNO_H_USING_LIST)
#define __ERRNO_H_USING_LIST
#    ifdef _MT
       using std:: __errno;
       using std:: __doserrno;
#    else // !_MT
       using std::errno;
       using std::_doserrno;
#    endif // _MT
     using std::_sys_nerr;
     using std::_sys_errlist;
#endif /* __USING_CNAME__ */
