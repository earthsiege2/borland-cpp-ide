//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Class definition for implementation of Mail enabling.
//----------------------------------------------------------------------------
#if !defined(OWL_MAILER_H)
#define OWL_MAILER_H

#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif

#ifdef UNICODE
# error OWL: The current version of MAILER.H does not support UNICODE
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TMailer
// ~~~~~ ~~~~~~~
class _OWLCLASS TMailer : public TModule {
  public:
    TMailer();

    bool  IsMAPIAvailable() const;
    void  SendDocuments(TWindow* owner, const char far* paths,
                        const char far* names = 0, bool asynchWork = false);

    TModuleProc5<uint32,uint32,char far*,char far*,char far*,uint32> MAPISendDocuments;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_MAILER_H
