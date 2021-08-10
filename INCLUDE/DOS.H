/*  dos.h

    Defines structs, unions, macros, and functions for dealing
    with MSDOS and the Intel iAPX86 microprocessor family.

*/
/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.18  $ */

#ifndef __DOS_H
#define __DOS_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#ifndef __ERRNO_H
#include <errno.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */

/* Define intrinsic outside of any namespace */
#ifdef __cplusplus
extern "C" {
#endif
void     _RTLENTRY             __int__(int __interruptnum);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */


#ifdef __cplusplus
extern "C" {
#endif


#ifndef FA_NORMAL
#define FA_NORMAL   0x00        /* Normal file, no attributes */
#define FA_RDONLY   0x01        /* Read only attribute */
#define FA_HIDDEN   0x02        /* Hidden file */
#define FA_SYSTEM   0x04        /* System file */
#define FA_LABEL    0x08        /* Volume label */
#define FA_DIREC    0x10        /* Directory */
#define FA_ARCH     0x20        /* Archive */
#endif /* FA_NORMAL */

#ifndef _A_NORMAL
/* MSC names for file attributes */
#define _A_NORMAL   0x00        /* Normal file, no attributes */
#define _A_RDONLY   0x01        /* Read only attribute */
#define _A_HIDDEN   0x02        /* Hidden file */
#define _A_SYSTEM   0x04        /* System file */
#define _A_VOLID    0x08        /* Volume label */
#define _A_SUBDIR   0x10        /* Directory */
#define _A_ARCH     0x20        /* Archive */
#endif /* _A_NORMAL */

#ifndef SEEK_CUR
#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0
#endif /* SEEK_CUR */

#if !defined(__STDC__)
#define environ  _environ
#endif


struct  dfree
{
    unsigned df_avail;
    unsigned df_total;
    unsigned df_bsec;
    unsigned df_sclus;
};

struct diskfree_t
{
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
};

struct time
{
    unsigned char   ti_min;     /* Minutes */
    unsigned char   ti_hour;    /* Hours */
    unsigned char   ti_hund;    /* Hundredths of seconds */
    unsigned char   ti_sec;     /* Seconds */
};

struct dostime_t
{
    unsigned char hour;         /* Hours */
    unsigned char minute;       /* Minutes */
    unsigned char second;       /* Seconds */
    unsigned char hsecond;      /* Hundredths of seconds */
};

struct date
{
    int     da_year;        /* Year - 1980 */
    char    da_day;     /* Day of the month */
    char    da_mon;     /* Month (1 = Jan) */
};

struct dosdate_t
{
    unsigned char day;      /* 1-31 */
    unsigned char month;    /* 1-12 */
    unsigned int  year;     /* 1980 - 2099 */
    unsigned char dayofweek;/* 0 - 6 (0=Sunday) */
};

#ifndef MAXPATH
#define MAXPATH   260
#define MAXDIR    256
#define MAXFILE   256
#define MAXEXT    256
#define MAXDRIVE    3
#endif

#ifndef _FFBLK_DEF
#define _FFBLK_DEF
struct  ffblk   {
    long            ff_reserved;
    long            ff_fsize;
    unsigned long   ff_attrib;
    unsigned short  ff_ftime;
    unsigned short  ff_fdate;
    char            ff_name[MAXPATH];
};
struct  _wffblk {
    long            ff_reserved;
    long            ff_fsize;
    unsigned long   ff_attrib;
    unsigned short  ff_ftime;
    unsigned short  ff_fdate;
    wchar_t         ff_name[MAXPATH];
};

#endif  /* __FFBLK_DEF */

struct find_t
{
    long            reserved;
    long            size;              /* size of file */
    unsigned long   attrib;            /* attribute byte for matched file */
    unsigned short  wr_time;           /* time of last write to file */
    unsigned short  wr_date;           /* date of last write to file */
    char            name[MAXPATH];     /* asciiz name of matched file */
};

/*
   The prototype for __emit__ has been removed from DOS.H.  __emit__ is
   still supported, but is now automatically recognized by the compiler and
   provides some new features, now that it's un-prototyped:

   __emit__ usually works with constant numbers of size char, short, long,
   and __int64, however, there are three special additions here:

     int x;
     __emit__(&x);

   This will emit the address of the variable x in the correct little-endian
   form to be used in assembly operations.

     __emit__(1.234F);
     __emit__(1.234);
     __emit__(1.234L);

   These emit the 4, 8, or 10 byte pattern that represents the constant
   float, double, or long double values of 1.23.

     __emit__("Hello There");

   This will create a constant string (just like the compiler does with
   any constant string in C or C++) and emits the 4-byte address of this
   string.

   There is a special byte-saving optimization made if a signed
   int constant number is specified: the fewest number of bytes required
   to represent that number will be emitted.  If the same value is cast
   or suffixed to be unsigned int instead, the full size is emitted.  Keep
   in mind that all integral literals are, by definition, signed integers
   (unless an alternate suffix is applied):

     __emit__(0);            // yields an 8-bit 00h not a 32-bit 00000000h
                                use __emit__(0u) to get 32-bits.

     __emit__(0x64);         // yields an 8-bit 64h
     __emit__(100u);         // yields a 32-bit 00000064h
     __emit__(0x64u);        // yields a 32-bit 00000064h

     __emit__((char) 50);    // yields an 8-bit 32h
     __emit__((short) 500);  // yields a 16-bit 01F4h

     __emit__(2ui64);        // yields a 64-bit 0000000000000002h
     __emit__(20i64);        // yields a 64-bit 0000000000000014h

   Multiple parameters can be passed to __emit__ and they will be generated
   from left to right (similar to the pascal calling convention).  The left
   most parameter will be emitted to a lower address in memory than the
   right most parameter.

    __emit__(0,1,2,3,4);              // yields 5 bytes: 0001020304
    __emit__(L'\x8C\x1F', 0, 300i64); // yields 11 bytes:8C1F001201000000000000

*/

unsigned _RTLENTRY _EXPFUNC _dos_close(int __fd);
unsigned _RTLENTRY _EXPFUNC _dos_creat(const char _FAR *__pathP, unsigned __attr,
                                int _FAR *__fd);
unsigned _RTLENTRY _EXPFUNC _dos_creatnew(const char _FAR *__pathP, unsigned __attr,
                                int _FAR *__fd);
unsigned _RTLENTRY _EXPFUNC _dos_findfirst(const char _FAR *__path,
                                unsigned __attrib,
                                struct find_t _FAR *__finfo);
unsigned _RTLENTRY _EXPFUNC _dos_findnext(struct find_t _FAR *__finfo);
void     _RTLENTRY _EXPFUNC _dos_getdate(struct dosdate_t _FAR *__datep);
unsigned _RTLENTRY _EXPFUNC _dos_getdiskfree(unsigned __drive,
                                struct diskfree_t _FAR *__dtable);
void     _RTLENTRY _EXPFUNC _dos_getdrive(unsigned _FAR *__drive);
unsigned _RTLENTRY _EXPFUNC _dos_getfileattr(const char _FAR *__filename,
                                unsigned _FAR *__attrib);
unsigned _RTLENTRY _EXPFUNC _dos_getftime(int __fd, unsigned _FAR *__date,
                                unsigned _FAR *__time);
void     _RTLENTRY _EXPFUNC _dos_gettime(struct dostime_t _FAR *__timep);
unsigned _RTLENTRY _EXPFUNC _dos_open(const char _FAR *__pathP, unsigned __oflag,
                                int _FAR *__fd);
unsigned _RTLENTRY _EXPFUNC _dos_setdate(struct dosdate_t _FAR *__datep);
void     _RTLENTRY _EXPFUNC _dos_setdrive(unsigned __drive, unsigned _FAR *__ndrives);
unsigned _RTLENTRY _EXPFUNC _dos_setfileattr(const char _FAR *__filename,
                                unsigned _FAR __attrib);
unsigned _RTLENTRY _EXPFUNC _dos_setftime(int __fd, unsigned __date, unsigned __time);
unsigned _RTLENTRY _EXPFUNC _dos_settime(struct dostime_t _FAR *__timep);
long     _RTLENTRY _EXPFUNC dostounix(struct date _FAR *__d, struct time _FAR *__t);
void     _RTLENTRY _EXPFUNC getdate(struct date _FAR *__datep);
void     _RTLENTRY _EXPFUNC getdfree(unsigned char __drive,
                                struct dfree _FAR *__dtable);
int      _RTLENTRY _EXPFUNC _getdrive(void);
void     _RTLENTRY _EXPFUNC gettime(struct time _FAR *__timep);
void     _RTLENTRY _EXPFUNC setdate(struct date _FAR *__datep);
void     _RTLENTRY _EXPFUNC settime( struct time _FAR *__timep);
void     _RTLENTRY _EXPFUNC unixtodos(long __time, struct date _FAR *__d,
                                struct time _FAR *__t);
int      _RTLENTRY _EXPFUNC unlink(const char _FAR *__path);
unsigned _RTLENTRY _EXPFUNC _dos_read(int __fd, void *__buf, unsigned __len,
                                unsigned *__nread);
unsigned _RTLENTRY _EXPFUNC _dos_write(int __fd, const void *__buf, unsigned __len,
                                unsigned *__nread );

__inline void _disable(void) { __emit__((unsigned char)(0xfa)); }
__inline void _enable(void)  { __emit__((unsigned char)(0xfb)); }

#define geninterrupt(i) __int__(i)      /* Interrupt instruction */

/* Variables */
#if !defined(__ARGV_DEFINED)
#define __ARGV_DEFINED
    extern int           _RTLENTRY _EXPDATA _argc;
    extern char **       _RTLENTRY _EXPDATA _argv;
#   define __argc        _argc  /* MSC Version */
#   define __argv        _argv  /* MSC Version */
#endif /* __ARGV_DEFINED */

extern int const     _RTLENTRY _EXPDATA _8087;
extern char **       _RTLENTRY _EXPDATA _environ;

extern unsigned char _RTLENTRY _EXPDATA _osmajor;
extern unsigned char _RTLENTRY _EXPDATA _osminor;
extern unsigned      _RTLENTRY _EXPDATA _osversion;
extern unsigned      _RTLENTRY _EXPDATA _version;

void _RTLENTRY _EXPFUNC _sleep(unsigned __seconds);
void _RTLENTRY _EXPFUNC sleep(unsigned __seconds);

#ifdef __MFC_COMPAT__
#define _getdiskfree _dos_getdiskfree
#define _diskfree_t diskfree_t
#else
#pragma obsolete _dos_getdiskfree
#endif

#if !defined(RC_INVOKED)
#pragma obsolete _dos_close
#pragma obsolete _dos_creat
#pragma obsolete _dos_creatnew
#pragma obsolete _dos_findfirst
#pragma obsolete _dos_findnext
#pragma obsolete _dos_getdate
#pragma obsolete _dos_getdrive
#pragma obsolete _dos_getfileattr
#pragma obsolete _dos_getftime
#pragma obsolete _dos_gettime
#pragma obsolete _dos_open
#pragma obsolete _dos_read
#pragma obsolete _dos_setdate
#pragma obsolete _dos_setdrive
#pragma obsolete _dos_setfileattr
#pragma obsolete _dos_setftime
#pragma obsolete _dos_settime
#pragma obsolete _dos_write
#pragma obsolete sleep
#endif

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#endif  /* __DOS_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__DOS_H_USING_LIST)
#define __DOS_H_USING_LIST

    using std::dfree;
    using std::diskfree_t;
    using std::time;
    using std::dostime_t;
    using std::date;
    using std::dosdate_t;
    using std::ffblk;
    using std::_wffblk;
    using std::find_t;
    using std::_dos_close;
    using std::_dos_creat;
    using std::_dos_creatnew;
    using std::_dos_findfirst;
    using std::_dos_findnext;
    using std::_dos_getdate;
    using std::_dos_getdiskfree;
    using std::_dos_getdrive;
    using std::_dos_getfileattr;
    using std::_dos_getftime;
    using std::_dos_gettime;
    using std::_dos_open;
    using std::_dos_setdate;
    using std::_dos_setdrive;
    using std::_dos_setfileattr;
    using std::_dos_setftime;
    using std::_dos_settime;
    using std::_disable;
    using std::dostounix;
    using std::_enable;
    using std::getdate;
    using std::getdfree;
    using std::_getdrive;
    using std::gettime;
    using std::setdate;
    using std::settime;
    using std::unixtodos;
    using std::unlink;
    using std::_dos_read;
    using std::_dos_write;
    using std::_argc;
    using std::_argv;
    using std::_8087;
    using std::_environ;
    using std::_osmajor;
    using std::_osminor;
    using std::_osversion;
    using std::_version;
    using std::_sleep;
    using std::sleep;
#endif /* __USING_CNAME__ */

