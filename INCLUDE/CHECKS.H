/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CHECKS.H                                                              */
/*                                                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.6  $ */

#ifndef __cplusplus
#error Must use C++ for CHECKS.H
#endif

//
// the __CHECKS_H header guard applies to sections of the header that
// are always included.  See also __CHECKS_DIAGS_DEFINED below.
//
#ifndef __CHECKS_H
#define __CHECKS_H

#ifndef __FLAT__
#error 16 bit targets not supported.
#endif

#if !defined( __DEFS_H )
#  include <_defs.h>
#endif  // __DEFS_H

#if !defined( __SYSTYPES_H )
#  include <systypes.h>
#endif  // __SYSTYPES_H

#if !defined(__EXCEPT_H)
#  include <except.h>
#endif   // __EXCEPT_H

#if !defined(RC_INVOKED)

#pragma option push -Vo-

#if defined(__STDC__)
#pragma option push -w-nak
#endif

#endif  /* !RC_INVOKED */

class _EXPCLASS xerror : public xmsg
{
public:
     _RTLENTRY xerror( const char *type,
             const char *txt,
             const char *file,
             uint32 line );
};

class precondition : public xerror
{
public:
     _RTLENTRY precondition( const char *txt,
                  const char *file,
                  uint32 line ) : xerror( "Precondition", txt, file, line )
                  {
                  }
};

class check : public xerror
{
public:
    _RTLENTRY check( const char *txt,
           const char *file,
              uint32 line ) : xerror( "Check", txt, file, line )
           {
           }
};


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma option pop
#endif

#pragma option pop

#endif  /* !RC_INVOKED */


#endif  // __CHECKS_H

# if !defined(__CHECKS_DIAGS_DEFINED) && (defined(__TRACE) || defined(__WARN))
#define __CHECKS_DIAGS_DEFINED

#include <systypes.h>
#include <string>
#include <sstream>

#if defined( _RTLDLL ) || defined( _BUILDRTLDLL )
#define DIAG_IMPORT __import
#define DIAG_EXPORT __export
#if defined( _BUILDRTLDLL )
#define DIAG_CLASS __export
#else
#define DIAG_CLASS __import
#endif
#else
#define DIAG_IMPORT
#define DIAG_EXPORT
#define DIAG_CLASS
#endif


class DIAG_CLASS TDiagGroup {
public:
    TDiagGroup( uint8 enabled, uint8 level, const char *group);

    void _RTLENTRY Trace( std::ostringstream &os, const char *fname, uint32 line );

    void _RTLENTRY Warn( std::ostringstream &os, const char *fname, uint32 line );

    void _RTLENTRY Enable( uint8 enabled )
    {
        Flags.Enabled = uint8(enabled ? 1 : 0);
    }

    int _RTLENTRY IsEnabled() { return Flags.Enabled; }
    void _RTLENTRY SetLevel( uint8 level ) { Flags.Level = level; }
    uint8 _RTLENTRY GetLevel() { return Flags.Level; }

private:
    void _RTLENTRY Message( const char *type, std::ostringstream &os,
                         const char *fname, uint32 line );
    static void _RTLENTRY Output( const std::string &msg );
    struct TFlags
    {
        uint8 Enabled : 1;
        uint8 Level   : 7;
    } Flags;
	std::string Group;
	
	// no copies
	TDiagGroup(TDiagGroup const &);
	TDiagGroup &operator=(TDiagGroup const &);
};

inline void _RTLENTRY TDiagGroup::Trace(std::ostringstream &os, const char *fname, uint32 line)
{
    Message("Trace", os, fname, line);
}

inline void _RTLENTRY TDiagGroup::Warn(std::ostringstream &os, const char *fname, uint32 line)
{
    Message("Warning", os, fname, line);
}

#endif // !__CHECKS_DIAGS_DEFINED && (__TRACE || __WARN)


#if !defined( __DEBUG )
#define __DEBUG 0
#endif

#undef PRECONDITION
#undef PRECONDITIONX

#define PRECONDITION(p) PRECONDITIONX(p,#p)

#if __DEBUG < 1
#define PRECONDITIONX(p,s)   ((void)0)
#else
#define PRECONDITIONX(p,s)   \
    if(!(p)) {throw precondition(s,__FILE__,__LINE__);}
#endif

#undef CHECK
#undef CHECKX

#define CHECK(p) CHECKX(p,#p)

#if __DEBUG < 2
#define CHECKX(p,s)    ((void)0)
#else
#define CHECKX(p,s)   \
    if(!(p)) {throw check(s,__FILE__,__LINE__);}
#endif

#if defined(__TRACE) || defined(__WARN)

#define DECLARE_DIAG_GROUP(g, qual) TDiagGroup & qual _GetDiagGroup##g()

#define DIAG_DECLARE_GROUP(g)  DECLARE_DIAG_GROUP(g,DIAG_IMPORT);
#define DIAG_DEFINE_GROUP(g, e, l) \
    DECLARE_DIAG_GROUP(g, DIAG_EXPORT); \
    TDiagGroup &_GetDiagGroup##g() \
    { \
        static TDiagGroup dg(e, l, #g); \
        return dg; \
    } \

#define DIAG_ENABLE(g,s)            _GetDiagGroup##g().Enable(s)
#define DIAG_ISENABLED(g)           _GetDiagGroup##g().IsEnabled()
#define DIAG_SETLEVEL(g,l)          _GetDiagGroup##g().SetLevel(l)
#define DIAG_GETLEVEL(g)            _GetDiagGroup##g().GetLevel()

#if !defined(_BUILD_CHECKS) && !defined( _DEF_DECLARED )
#define _DEF_DECLARED
DECLARE_DIAG_GROUP(Def, _EXPCLASS);
#endif

#else   // !defined(__TRACE) && !defined(__WARN)

#define DIAG_DECLARE_GROUP(g)
#define DIAG_DEFINE_GROUP(g,e,l)

#define DIAG_ENABLE(g,s)            ((void)0)
#define DIAG_ISENABLED(g)           ((void)0)
#define DIAG_SETLEVEL(g,l)          ((void)0)
#define DIAG_GETLEVEL(g)            ((void)0)

#endif

#if defined(__TRACE)
    #define TRACE(m)                    TRACEX(Def,0,m)
    #define TRACEX(g,l,m)\
            do { \
                TDiagGroup &dg = _GetDiagGroup##g(); \
                if (dg.IsEnabled() && l <= dg.GetLevel()) { \
                    std::ostringstream os; \
                    os << m; \
                    dg.Trace(os, __FILE__, __LINE__); \
                } \
            } while (0)
#else
    #define TRACE(m)                    ((void)0)
    #define TRACEX(g,l,m)               ((void)0)
#endif

#if defined(__WARN)
    #define WARN(c,m)                   WARNX(Def,c,0,m)
    #define WARNX(g,c,l,m)\
            do { \
                if (c) { \
                    TDiagGroup &dg = _GetDiagGroup##g(); \
                    if (dg.IsEnabled() && l <= dg.GetLevel()) { \
                        std::ostringstream os; \
                        os << m; \
                        dg.Warn(os, __FILE__, __LINE__); \
                    } \
                } \
            } while (0)
#else
    #define WARN(c,m)                   ((void)0)
    #define WARNX(g,c,l,m)              ((void)0)
#endif

