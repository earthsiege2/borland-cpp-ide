//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.6  $
//
//   Base exception support for framework exceptions
//----------------------------------------------------------------------------
#if !defined(WINSYS_EXBASE_H)
#define WINSYS_EXBASE_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif

//----------------------------------------------------------------------------
// Exception support comes in two levels.
//
//  1) No emulation provided, any compiler support disabled. Throwing causes
//     an abort. (DISABLE_EXCEPTIONS defined)
//
//  2) Compiler support exceptions (DISABLE_EXCEPTIONS not defined)
//
// BI_NO_EXCEPTIONS comes from winsys/compiler.h
// DISABLE_EXCEPTIONS comes from the outside
//
#if defined(DISABLE_EXCEPTIONS)  // (level 1 -- exceptions disabled)
# define TRY
# define CATCH(arg_and_code)
# define ENDCATCH
# define THROW(expr) abort()
# define RETHROW

#else                            // (level 2 -- compiler support required)
# include <services/except.h>

# define TRY try
# define CATCH(arg_and_code)  catch arg_and_code
# define ENDCATCH
# define THROW(expr) throw expr
# define RETHROW throw
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//----------------------------------------------------------------------------
//
// Derived exception class that supports cloning, rethrowing & instance
// counting
//

class _WSYSCLASS_RTL TXBase : public xmsg {
  public:
    TXBase(const string& msg);
    TXBase(const TXBase& src);
    virtual ~TXBase();

    virtual TXBase* Clone();
    virtual void Throw();

    static void Raise(const string& msg);

  //private:
    static int InstanceCount;
};

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif

#endif  // WINSYS_EXBASE_H
