//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Defines class TAppDictionary. This class manages associations between
//   processes/tasks and TApplication pointers.
//----------------------------------------------------------------------------
#if !defined(OWL_APPDICT_H)
#define OWL_APPDICT_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
class _OWLCLASS TApplication;

#if !defined(BI_PLAT_WIN32)
  inline unsigned GetCurrentProcessId() {return (unsigned)GetCurrentTask();}
#endif

//
//  class TAppDictionary
//  ----- --------------
//
class _OWLCLASS TAppDictionary {
  public:
    struct TEntry {
      unsigned       Pid;
      TApplication*  App;
    };
    typedef void (*TEntryIterator)(TEntry&);

  public:
    TAppDictionary();
   ~TAppDictionary();

    TApplication* GetApplication(unsigned pid = 0);  // default to current pid

    void          Add(TApplication* app, unsigned pid = 0);
    void          Remove(TApplication* app);
    void          Remove(unsigned pid);
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

//
// Global exported TAppDictionary in Owl. User Component DLLs should have a
// similar 'AppDictionary'.
//
extern TAppDictionary _OWLDATA OwlAppDictionary;

//
// Global function that calls GetApplication() on owl's app-dictionary.
// Used by EXEs, or DLLs statically linking Owl. Never returns 0, will make
// an alias app if needed. Primarily for compatibility
//
TApplication* _OWLFUNC GetApplicationObject(unsigned pid = 0);

//
// Convenient macro to define a 'AppDictionary' ref and object as needed
// for use in component DLLs and EXEs
//
#if defined(BI_APP_DLL) && defined(_OWLDLL)
# define DEFINE_APP_DICTIONARY(AppDictionary)    \
   TAppDictionary  AppDictionary
#else
# define DEFINE_APP_DICTIONARY(AppDictionary)    \
   TAppDictionary& AppDictionary = ::OwlAppDictionary
#endif


//----------------------------------------------------------------------------
// inlines

#if !defined(BI_APP_DLL) && !defined(_OWLDLL) && !defined(BI_PLAT_WIN32)

inline TAppDictionary::TAppDictionary() {
  E.App = 0;
  E.Pid = 0;
}

inline TAppDictionary::~TAppDictionary() {DeleteCondemned();}

inline TApplication* TAppDictionary::GetApplication(unsigned /*pid*/) {
  return E.App;
}

inline void TAppDictionary::Add(TApplication* app, unsigned pid) {
  E.App = app;
  E.Pid = pid;
}

inline void TAppDictionary::Remove(TApplication* /*app*/) {
  E.App = 0;
}

inline void TAppDictionary::Remove(unsigned /*pid*/) {
  E.App = 0;
}

inline void TAppDictionary::Condemn(TApplication* /*app*/) {
  E.Pid = 0;
}

inline bool TAppDictionary::DeleteCondemned() {
  if (!E.Pid) {
    delete E.App;
    E.App = 0;
  }
  return false;
}

inline void TAppDictionary::Iterate(TEntryIterator iter) {
  (*iter)(E);
}

#endif // !defined(BI_APP_DLL) && !defined(_OWLDLL)

#endif  // OWL_APPDICT_H
