//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   owl\include\except.h
//   OWL base exception class definition
//----------------------------------------------------------------------------
#if !defined(__OWL_EXCEPT_H)
#define __OWL_EXCEPT_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif
#if !defined(__EXCEPT_H)
  #include <except.h>
#endif
#include "owl\except.rh"

class _OWLCLASS TModule;     

extern TModule* Module;

const int MAX_RSRC_ERROR_STRING = 255;

int _OWLFUNC
HandleGlobalException(xmsg& x, char* caption, char* canResume=0);

class _OWLCLASS_RTL TXOwl : public xmsg {
  public:
    TXOwl(const string& msg) : xmsg(msg), ResId(0) {}
    TXOwl(unsigned resId, TModule* module = ::Module);
    virtual ~TXOwl() {}
    virtual TXOwl* Clone();
    virtual void Throw();
    virtual int Unhandled(TModule* app, unsigned promptResId);
    static string ResourceIdToString(BOOL *found, unsigned resId,
                                     TModule* module = ::Module);
    unsigned ResId;
};

class _OWLCLASS_RTL TXCompatibility : public TXOwl {
  public:
    TXCompatibility(int statusCode);
    TXCompatibility(const TXCompatibility& src);
    TXOwl* Clone();
    void   Throw();
    int    Unhandled(TModule* app, unsigned promptResId);
    static string MapStatusCodeToString(int statusCode);

    int Status;
};

class _OWLCLASS_RTL TXOutOfMemory : public TXOwl {
  public:
    TXOutOfMemory();
    TXOwl* Clone();
    void   Throw();
};

class _OWLCLASS TStatus {
  public:
    TStatus() {StatusCode = 0;}
    TStatus& operator =(int statusCode) {Set(statusCode); return *this;}
    operator int() const {return StatusCode;}

  private:
    void Set(int statusCode);
    int  StatusCode;
};

//
// Macros that control actual exception handling code used. Defining
// NO_CPP_EXCEPTIONS will disable the use of C++ exceptions, otherwise
// standard C++ exception handling code will be used.
//
#if defined(NO_CPP_EXCEPTIONS)
  #define TRY                     // try block is executed normally
  #define THROW(x)    abort()     // abort on any exception
  #define THROWX(x)   abort()
  #define RETHROW                 // only used in catch clauses, no code needed
  #define CATCH(x)                // exception & code is arg to macro
#else
  #define TRY         try
  #define THROW(x)    throw x
  #define THROWX(x)   x.Throw()   // Classes derived from TXOwl can use this
  #define RETHROW     throw
  #define CATCH(x)    catch x
#endif

#endif  // __OWL_EXCEPT_H
