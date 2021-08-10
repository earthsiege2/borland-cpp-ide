/*  typeinfo.h

    Definitions for RTTI
*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__cplusplus)
#error Must use C++ for typeinfo.h
#endif

#ifndef __TYPEINFO_H
#define __TYPEINFO_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#pragma option  -Vt-                    // make sure vtable pointer is 'low'
#pragma option  -RT


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

class   _TIDIST  __rtti  Type_info
{

public:

#if defined(__FLAT__)
        tpid          *         tpp;
#else
        tpid    __far *         tpp;
#endif

private:
                __cdecl Type_info(const Type_info _FAR &);
    Type_info & __cdecl operator=(const Type_info _FAR &);

public:

    virtual     __cdecl ~Type_info();

    int         __cdecl operator==(const Type_info _FAR &) const;
    int         __cdecl operator!=(const Type_info _FAR &) const;

    int         __cdecl before(const Type_info _FAR &) const;

    const char _FAR *__cdecl name() const;
};

class   Bad_cast{};
class   Bad_typeid{};

#pragma option  -RT.
#pragma option  -Vt.

#endif
