/*  except.h

    Definitions for exception handling

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1992, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for except.h
#endif

#ifndef __EXCEPT_H
#define __EXCEPT_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif
#if !defined(___STDLIB_H)
#include <stdlib.h>
#endif

#pragma option -a-      // byte packing
#pragma option -Vo-     // set standard C++ options
#pragma option -RT

#if defined(__BCOPT__) && !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-     // disable Object data calling convention
#endif

typedef void (_RTLENTRY *terminate_function)();
typedef void (_RTLENTRY *unexpected_function)();

terminate_function  _RTLENTRY set_terminate(terminate_function);
unexpected_function _RTLENTRY set_unexpected(unexpected_function);

terminate_function  _RTLENTRY terminate();
unexpected_function _RTLENTRY unexpected();

extern  char _FAR * _RTLENTRY __ThrowFileName();
extern  unsigned    _RTLENTRY __ThrowLineNumber();
extern  char _FAR * _RTLENTRY __ThrowExceptionName();

#define  __throwFileName      __ThrowFileName()
#define  __throwLineNumber    __ThrowLineNumber()
#define  __throwExceptionName __ThrowExceptionName()

class _EXPCLASS string;

class _EXPCLASS xmsg
{
public:
    xmsg(const string _FAR &msg);
    xmsg(const xmsg _FAR &msg);
    ~xmsg();

    const string _FAR & why() const;
    void raise() throw(xmsg);
    xmsg& operator=(const xmsg _FAR &src);
private:
    string _FAR *str;
};

inline const string _FAR & xmsg::why() const
{
    return *str;
};

class _EXPCLASS xalloc : public xmsg
{
public:
    xalloc(const string _FAR &msg, size_t size);

    size_t requested() const;
    void raise() throw(xalloc);
private:
    size_t siz;
};

inline size_t xalloc::requested() const
{
    return siz;
}

#if defined(__BCOPT__) && !defined(__FLAT__)
#pragma option -po.     // restore Object Data calling convention
#endif

#pragma option -RT.
#pragma option -Vo.     // restore user C++ options
#pragma option -a.      // restore default packing

#endif  // __EXCEPT_H
