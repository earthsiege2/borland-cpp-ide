/*  typeinfo.h

    Definitions for RTTI
*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__cplusplus)
#error Must use C++ for typeinfo.h
#endif

#if defined(__TINY__)
#error Cannot use Runtime Type Information in tiny model
#endif

#ifndef __TYPEINFO_H
#define __TYPEINFO_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma option  -Vt-                    // make sure vtable pointer is 'low'
#pragma option  -RT

#endif  /* !RC_INVOKED */


#if defined(_BUILDRTLDLL) || defined(_RTLDLL)
#   define _TIDIST   _EXPCLASS
#else
#   if defined(__FLAT__)
#     define _TIDIST
#   else
#      if     defined(__LARGE__) || defined(__COMPACT__) || defined(__HUGE__) || defined(__DLL__)
#         define _TIDIST  __huge
#      else
#         define _TIDIST  __huge __near
#      endif
#   endif
#endif

class                   tpid;

class   _TIDIST  __rtti typeinfo
{

public:

#if defined(__FLAT__)
        tpid          * tpp;
#else
        tpid    __far * tpp;
#endif

private:
                __cdecl typeinfo(const typeinfo _FAR &);
    typeinfo &  __cdecl operator=(const typeinfo _FAR &);

public:

    virtual     __cdecl ~typeinfo();

    bool        __cdecl operator==(const typeinfo _FAR &) const;
    bool        __cdecl operator!=(const typeinfo _FAR &) const;

    bool        __cdecl before(const typeinfo _FAR &) const;

    const char _FAR *__cdecl name() const;
};


#if !defined(__STDC__)
typedef typeinfo Type_info;  // For backwards compatibility.
#endif

class   Bad_cast{};
class   Bad_typeid{};


#if !defined(RC_INVOKED)

#pragma option  -RT.
#pragma option  -Vt.

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#endif
