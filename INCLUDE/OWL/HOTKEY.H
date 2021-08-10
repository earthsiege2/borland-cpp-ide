//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Definition of class THotKey
//----------------------------------------------------------------------------
#if !defined(OWL_HOTKEY_H)
#define OWL_HOTKEY_H

#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class THotKey
// ~~~~~ ~~~~~~~
// THotKey encapsulates the hot-key control, a window that allows the user to 
// enter a combination of keystrokes to be used as a a hot key. 
// [A hot key is a key combination that the user can press to perform an 
// action quickly].
//
class _OWLCLASS THotKey : public TControl {
  public:
    THotKey(TWindow* parent,
            int             id,
            int x, int y, int w, int h,
            TModule*        module = 0);

    THotKey(TWindow* parent, int resourceId, TModule* module = 0);

    // Set and retrieve the hot key virtual code.
    //
    uint16  GetHotKey();
    void    SetHotKey(uint16 hotKey);
    void    SetHotKey(uint8 vk, uint8 mods);

    // Set the invalid key combinations for this control
    //
    void    SetRules(uint16 invalid, uint16 defFlag);

  protected:
    // Override TWindow virtual member functions
    //
    char far*    GetClassName();
    uint         Transfer(void* buffer, TTransferDirection direction);

  private:
    // Hidden to prevent accidental copying or assignment
    //
    THotKey(const THotKey&);
    THotKey& operator =(const THotKey&);

  DECLARE_STREAMABLE(_OWLCLASS, THotKey, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_HOTKEY_H
