//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   OWL exception class & function definitions
//----------------------------------------------------------------------------
#if !defined(OWL_EXCEPT_H)
#define OWL_EXCEPT_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
#if !defined(__EXCEPT_H)
# include <except.h>
#endif
#if !defined(OSL_EXCEPT_H)
# include <osl/except.h>
#endif
#include <owl/except.rh>

class _OWLCLASS TModule;     
extern TModule* Module;
const int MAX_RSRC_ERROR_STRING = 255;

int _OWLFUNC
HandleGlobalException(xmsg& x, char* caption, char* canResume=0);

class _OWLCLASS_RTL TXOwl : public TXBase {
  public:
    TXOwl(const string& msg, unsigned resId = 0);
    TXOwl(unsigned resId, TModule* module = ::Module);
   ~TXOwl();

    TXOwl* Clone();
    void Throw();
    virtual int Unhandled(TModule* app, unsigned promptResId);
    unsigned GetErrorCode() const {return ResId;}

    static string ResourceIdToString(bool* found, unsigned resId,
                                     TModule* module = ::Module);
    
  public:
    unsigned ResId;
};

class _OWLCLASS_RTL TXOutOfMemory : public TXOwl {
  public:
    TXOutOfMemory();
   ~TXOutOfMemory();
    TXOutOfMemory* Clone();
    void   Throw();
};

//----------------------------------------------------------------------------
// Owl 1.0 compatibility exception classes
//

class _OWLCLASS_RTL TXCompatibility : public TXOwl {
  public:
    TXCompatibility(int statusCode);
    TXCompatibility(const TXCompatibility& src);
   ~TXCompatibility();

    TXCompatibility* Clone();
    void             Throw();
    int              Unhandled(TModule* app, unsigned promptResId);

    static string MapStatusCodeToString(int statusCode);

    int Status;
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

#endif  // OWL_EXCEPT_H
