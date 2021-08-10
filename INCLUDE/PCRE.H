/*************************************************
*       Perl-Compatible Regular Expressions      *
*************************************************/

/* Copyright (c) 1998 University of Cambridge */

#ifndef _PCRE_H
#define _PCRE_H

/* Have to include stdlib.h in order to ensure that size_t is defined;
it is needed here for malloc. */

#include <sys/types.h>
#include <stdlib.h>

/* Allow for C++ users */

#ifdef __cplusplus
extern "C" {
#endif

/* Options */

#define PCRE_CASELESS        0x0001
#define PCRE_MULTILINE       0x0002
#define PCRE_DOTALL          0x0004
#define PCRE_EXTENDED        0x0008
#define PCRE_ANCHORED        0x0010
#define PCRE_DOLLAR_ENDONLY  0x0020
#define PCRE_EXTRA           0x0040
#define PCRE_NOTBOL          0x0080
#define PCRE_NOTEOL          0x0100
#define PCRE_UNGREEDY        0x0200

/* Exec-time error codes */

#define PCRE_ERROR_NOMATCH        (-1)
#define PCRE_ERROR_NULL           (-2)
#define PCRE_ERROR_BADOPTION      (-3)
#define PCRE_ERROR_BADMAGIC       (-4)
#define PCRE_ERROR_UNKNOWN_NODE   (-5)
#define PCRE_ERROR_NOMEMORY       (-6)

/* Types */

typedef void pcre;
typedef void pcre_extra;

/* Store get and free functions. These can be set to alternative malloc/free
functions if required. */

extern void *(*pcre_malloc)(size_t);
extern void  (*pcre_free)(void *);

/* Functions */

extern pcre *
#ifdef __BORLANDC__
_RTLENTRY _EXPFUNC
#endif
pcre_compile(const char *, int, const char **, int *,
  const unsigned char *);
extern int
#ifdef __BORLANDC__
_RTLENTRY _EXPFUNC
#endif
pcre_exec(const pcre *, const pcre_extra *, const char *,
  int, int, int *, int);
extern unsigned const char *
#ifdef __BORLANDC__
_RTLENTRY _EXPFUNC
#endif
pcre_maketables(void);
extern int
#ifdef __BORLANDC__
_RTLENTRY _EXPFUNC
#endif
pcre_info(const pcre *, int *, int *);
extern pcre_extra *
#ifdef __BORLANDC__
_RTLENTRY _EXPFUNC
#endif
pcre_study(const pcre *, int, const char **);
extern const char *
#ifdef __BORLANDC__
_RTLENTRY _EXPFUNC
#endif
pcre_version(void);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* End of pcre.h */
