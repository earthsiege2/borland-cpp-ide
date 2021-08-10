//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.11  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#if !defined(OWL_WSKERR_H)
#define OWL_WSKERR_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TSocketError
// ~~~~~ ~~~~~~~~~~~~
// Converts Winsock errors to string messages.
//
class _OWLCLASS TSocketError {
  public:
    TSocketError(int error = 0, int sizeToAllocate = 128);
    virtual ~TSocketError();

    TSocketError& operator =(const TSocketError& src);
    friend bool operator ==(const TSocketError& socketError1,
                            const TSocketError& socketError2);

    void  Init(int error);
    int   GetReasonValue() const;
    const char* GetReasonString() const;

    // Default to our own string (NULL argument).
    char* AppendError(char* stringToAppendErrorTo, char* destination = 0);
    char* AppendError(int stringResourceToAppendErrorTo, char* destination = 0);

  protected:
    int   Error;            // Error code
    int   SizeToAllocate;   // Size to allocate for String.
                            // Usually bigger than String so we can append to it.
    char* String;           // Error code converted to string
    void  GetErrorString(); // Convert the error code to string

  private:
    static TModule& GetModule();    // used for LoadString()
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_WSKERR_H
