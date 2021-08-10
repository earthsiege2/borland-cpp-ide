//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.2  $
//
// Reliable include for standard C++ exception classes
//----------------------------------------------------------------------------
#if !defined(SERVICES_EXCEPT_H)
#define SERVICES_EXCEPT_H

#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif

//
// Provide throw specifier macros that allow conditionally disabling the use
// of throw specifiers based on the macro, BI_NO_THROWSPEC.
// This can be turned on for compilers that don't support it, or for users
// that dont want it.
//
#if defined(BI_NO_THROWSPEC)
# define THROW_SPEC0
# define THROW_SPEC1(x)
# define THROW_SPEC2(x,x2)
# define THROW_SPEC3(x,x2,x3)
# define THROW_SPEC4(x,x2,x3,x4)
#else
# define THROW_SPEC0                    throw()
# define THROW_SPEC1(x)                 throw(x)
# define THROW_SPEC2(x,x2)              throw(x,x2)
# define THROW_SPEC3(x,x2,x3)           throw(x,x2,x3)
# define THROW_SPEC4(x,x2,x3,x4)        throw(x,x2,x3,x4)
#endif

//
// In a Borland C++ environment, use the file provided
//
#if defined(BI_COMP_BORLANDC)
# include <except.h>

//
// In a non-Borland C++ environment, use the C++ Exception Handling support
// and add missing components of that support.
//
#else
# if defined(BI_COMP_MSC)
#   include <eh.h>
# endif

# include <stdlib.h>

class _EXPCLASS string;

class _EXPCLASS xmsg
{
public:
    _RTLENTRY xmsg(const string _FAR &msg);
    _RTLENTRY xmsg(const xmsg _FAR &msg);
    _RTLENTRY ~xmsg();

    const string _FAR & _RTLENTRY why() const;
    void                _RTLENTRY raise() THROW_SPEC1(xmsg);
    xmsg&               _RTLENTRY operator=(const xmsg _FAR &src);

private:
    string _FAR *str;
};

inline const string _FAR & _RTLENTRY xmsg::why() const
{
    return *str;
};

class _EXPCLASS xalloc : public xmsg
{
public:
    _RTLENTRY xalloc(const string _FAR &msg, size_t size);

    size_t _RTLENTRY requested() const;
    void   _RTLENTRY raise() THROW_SPEC1(xalloc);

private:
    size_t siz;
};

inline size_t _RTLENTRY xalloc::requested() const
{
    return siz;
}

#endif  // if/else BI_COMP_BORLANDC

#endif  // SERVICES_EXCEPT_H
