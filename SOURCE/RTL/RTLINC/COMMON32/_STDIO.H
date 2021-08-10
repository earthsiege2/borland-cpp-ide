/*------------------------------------------------------------------------
 * filename - _stdio.h
 *
 *  Definitions for stream input/output.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

size_t  __fputn             (const void *__ptr, size_t __n, FILE *__fp);
char  * __mkname            (char *__s, char *__pfx, unsigned short __num);
char  * __tmpnam            (char *__s, unsigned short *__numP);
FILE  * __openfp            (FILE *__fp, const char *__fname,
                                const char *__type, int __shflag);
FILE  * __getfp             (void);
int     _allocbuf           (FILE *__fp, char *__buf, int __type, size_t __size);

#ifdef _MT
void    _lock_all_streams   (void);
void    _unlock_all_streams (void);
void    _lock_stream        (FILE *__stream);
void    _unlock_stream      (FILE *__stream);
void    _lock_exit(void);
void    _unlock_exit(void);
#else
#define _lock_all_streams()
#define _unlock_all_streams()
#define _lock_stream(stream)
#define _unlock_stream(stream)
#define _lock_exit()
#define _unlock_exit()
#endif

int _RTLENTRY   _flushall      (void);
int _RTLENTRY   _flushout      (void);

/* _lgetc and _lputc are like fgetc and fputc, except that they lock
 * the stream semaphore.
 */
#ifdef _MT
int          _lgetc         (FILE  *__stream );
int          _lputc         (int __ch, FILE *__stream );
#else
#define _lgetc fgetc
#define _lputc fputc
#endif

FILE *_RTLENTRY _fdopen        (int __handle, char *__type);

extern  unsigned short _tmpnum;     /* temporary file number */

#ifdef __cplusplus
}
#endif
