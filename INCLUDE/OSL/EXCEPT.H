//----------------------------------------------------------------------------
// ObjectSupport
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Base exception support for framework exceptions
//----------------------------------------------------------------------------
#if !defined(OSL_EXCEPT_H)
#define OSL_EXCEPT_H

#if !defined(OSL_DEFS_H)
# include <osl/defs.h>
#endif

//----------------------------------------------------------------------------
// Exception support comes in two levels.
//
//  1) No emulation provided, any compiler support disabled. Throwing causes
//     an abort. (DISABLE_EXCEPTIONS defined)
//  2) Compiler support exceptions (DISABLE_EXCEPTIONS not defined)
//
// BI_NO_EXCEPTIONS comes from classlib/compiler.h
// DISABLE_EXCEPTIONS comes from the outside
//
#if defined(DISABLE_EXCEPTIONS)  // (level 1 -- exceptions disabled)

#define TRY
#define CATCH(arg_and_code)
#define ENDCATCH
#define THROW(expr) abort()
#define RETHROW

#else                            // (level 2 -- compiler support required)

#if defined( __BCPLUSPLUS__ )
# include <except.h>
#else
# error Exceptions are only natively supported with Borland C++.
#endif

#define TRY try
#define CATCH(arg_and_code)  catch arg_and_code
#define ENDCATCH
#define THROW(expr) throw expr
#define RETHROW throw

#endif

//----------------------------------------------------------------------------
//
// Derived exception class that supports cloning, rethrowing & instance
// counting
//
//----------------------------------------------------------------------------

class _BIDSCLASS_RTL TXBase : public xmsg {
  public:
    TXBase(const string& msg);
    TXBase(const TXBase& src);
    virtual ~TXBase();

    virtual TXBase* Clone();
    virtual void Throw();

    static int InstanceCount;
};

#endif  // OSL_EXCEPT_H
