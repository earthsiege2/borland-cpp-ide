//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TAppDictionary. This class manages associations between
// processes/tasks and TApplication pointers.
//----------------------------------------------------------------------------
#if !defined(OWL_APPDICT_H)
#define OWL_APPDICT_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif

#if !defined(BI_PLAT_WIN32)
  inline uint GetCurrentProcessId() {return (uint)GetCurrentTask();}
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TApplication;

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TAppDictionary
// ~~~~~ ~~~~~~~~~~~~~~
class _OWLCLASS TAppDictionary {
  public:
    struct TEntry {
      uint           Pid;
      TApplication*  App;
    };
    typedef void (*TEntryIterator)(TEntry&);

  public:
    TAppDictionary();
   ~TAppDictionary();

    TApplication* GetApplication(uint pid = 0);  // default to current pid

    void          Add(TApplication* app, uint pid = 0);
    void          Remove(TApplication* app);
    void          Remove(uint pid);
    void          Condemn(TApplication* app);

    bool          DeleteCondemned();
    void          Iterate(TEntryIterator iter);

  private:
#if defined(BI_APP_DLL) || defined(_OWLDLL) || defined(BI_PLAT_WIN32)
    class TAppDictImp*  Imp;
#else
    TEntry        E;
#endif
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

// Global exported TAppDictionary in Owl. User Component DLLs should have a
// similar 'AppDictionary'.
//
extern TAppDictionary& _OWLFUNC OWLGetAppDictionary();

//
// Global function that calls GetApplication() on owl's app-dictionary.
// Used by EXEs, or DLLs statically linking Owl. Never returns 0, will make
// an alias app if needed. Primarily for compatibility
//
TApplication* _OWLFUNC GetApplicationObject(uint pid = 0);

//
// Convenient macro to define a 'AppDictionary' ref and object as needed
// for use in component DLLs and EXEs
//
#if defined(BI_APP_DLL) && defined(_OWLDLL)
# define DEFINE_APP_DICTIONARY(AppDictionary)    \
  TAppDictionary  AppDictionary
#else
# define DEFINE_APP_DICTIONARY(AppDictionary)    \
  TAppDictionary& AppDictionary = OWLGetAppDictionary()
#endif

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif
    
//----------------------------------------------------------------------------
// inlines

//
// 16bit static link exe models 
//
#if !defined(BI_APP_DLL) && !defined(_OWLDLL) && !defined(BI_PLAT_WIN32)

//
// Constructor
//
inline TAppDictionary::TAppDictionary() {
  E.App = 0;
  E.Pid = 0;
}

//
// Destructor
//
inline TAppDictionary::~TAppDictionary() {
  DeleteCondemned();
}

//
// GetApplication
//
inline TApplication* TAppDictionary::GetApplication(uint /*pid*/) {
  return E.App;
}

//
// Add
//
inline void TAppDictionary::Add(TApplication* app, uint pid) {
  E.App = app;
  E.Pid = pid;
}

//
// Remove
//
inline void TAppDictionary::Remove(TApplication* /*app*/) {
  E.App = 0;
}

//
// Remove
//
inline void TAppDictionary::Remove(uint /*pid*/) {
  E.App = 0;
}

//
// Condemn an application
//
inline void TAppDictionary::Condemn(TApplication* /*app*/) {
  E.Pid = 0;
}

//
// Iterate
//
inline void TAppDictionary::Iterate(TEntryIterator iter) {
  (*iter)(E);
}

#endif // !defined(BI_APP_DLL) && !defined(_OWLDLL) && !defined(BI_PLAT_WIN32)

#endif  // OWL_APPDICT_H
