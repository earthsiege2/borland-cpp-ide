//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Definition of TMCIWnd class
//----------------------------------------------------------------------------
#if !defined(OWL_MCIWND_H)
#define OWL_MCIWND_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif

#if !defined(BI_PLAT_WIN32)
#error This example must be built as a WIN32 Target
#endif

// VFW.H relies on some macros which may not be defined by the 
// BORLAND C++ compiler.
//
#if defined(__BORLANDC__)  
# define __inline  inline
# if defined(__WIN32__) && !defined(_WIN32)    
#   define _WIN32
# endif
#endif
#if !defined(_INC_VFW)
# include <vfw.h>
#endif

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif

//
// The MCI Wnd procs are strangely __cdecl, so we need custom TModuleProc
// templates for them
//

//
template <class R>
class TModuleProc0V : public TModuleProc {
  public:
    TModuleProc0V(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()() {
      typedef R (far VFWAPIV* TProc)();
      return ((TProc)Proc)();
    }
};

//
template <class R, class P1, class P2, class P3, class P4>
class TModuleProc4V : public TModuleProc {
  public:
    TModuleProc4V(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4) {
      typedef R (far VFWAPIV* TProc)(P1 p1, P2 p2, P3 p3, P4 p4);
      return ((TProc)Proc)(p1, p2, p3, p4);
    }
};

//
// class TMciWndDll
// ~~~~~ ~~~~~~~~~~
class _OWLCLASS TMciWndDll : public TModule {
  public:
    TMciWndDll();

    TModuleProc4V<HWND,HWND,HINSTANCE,DWORD,LPCSTR> Create;
    TModuleProc0V<BOOL>                             RegisterClass;
};

//
// class TMciWnd
// ~~~~~ ~~~~~~~
class _OWLCLASS TMciWnd : public TControl {
  public:
    TMciWnd(TWindow* parent, int id, char far* title, 
            int x, int y, int w, int h, TModule* module = 0);
    TMciWnd(TWindow* parent, int resourceId, TModule* module = 0);

    bool        Open(char far* fileOrDevice, uint flags = 0);
    bool        OpenDialog();
    uint32      Close();
    uint32      Play();
    uint32      Stop();
    uint32      Pause();
    uint32      Resume();
    uint32      Seek(long pos);

    // Overriden virtuals of TWindow
    //
    char far*   GetClassName();
    bool        Register();

  protected:
    TMciWndDll  MciWndDll;
};

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline bool TMciWnd::Open(char far* fileOrDevice, uint flags)
{
  PRECONDITION(GetHandle());
  return MCIWndOpen(*this, fileOrDevice, flags) != 0;
}

//
inline uint32 TMciWnd::Close()
{
  PRECONDITION(GetHandle());
  return MCIWndClose(*this);
}

//
inline uint32 TMciWnd::Play()
{
  PRECONDITION(GetHandle());
  return MCIWndPlay(*this);
}

//
inline uint32 TMciWnd::Stop()
{
  PRECONDITION(GetHandle());
  return MCIWndStop(*this);
}

//
inline uint32 TMciWnd::Pause()
{
  PRECONDITION(GetHandle());
  return MCIWndPause(*this);
}

//
inline uint32 TMciWnd::Resume()
{
  PRECONDITION(GetHandle());
  return MCIWndResume(*this);
}

//
inline uint32 TMciWnd::Seek(long pos)
{
  PRECONDITION(GetHandle());
  return MCIWndSeek(*this, pos);
}

#endif  // OWL_MCIWND_H
