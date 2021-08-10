//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Definition of class TAnimateCtrl
//----------------------------------------------------------------------------
#if !defined(OWL_ANIMCTRL_H)
#define OWL_ANIMCTRL_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(BI_PLAT_WIN32)
# error OWL: Animctrl.h only supports WIN32 targets
#endif

#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TAnimateCtrl
// ~~~~~ ~~~~~~~~~~~~
// Encapsulates the Animation Control [a window that silently displays
// an Audio Video Interleaved, AVI clip].
// NOTE: This control can only display uncompressed or RLE-compressed
//       AVI files.
//
class _OWLCLASS TAnimateCtrl : public TControl {
  public:
    TAnimateCtrl(TWindow* parent, int id, int x, int y, int w, int h,
                 TModule* module = 0);
    TAnimateCtrl(TWindow* parent, int resourceId, TModule* module = 0);
   ~TAnimateCtrl();

    // Operations on the object
    //
    bool      Open(char far* fileOrRes);
    bool      Play(uint16 start = 0, uint16 end = -1, uint repeat = 1);
    bool      Seek(uint16 frame);
    void      Stop();

  protected:
    char far* GetClassName();
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif  // OWL_ANIMCTRL_H
