//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of class TControl.  This defines the basic behavior of all
// controls.
//----------------------------------------------------------------------------
#if !defined(OWL_CONTROL_H)
#define OWL_CONTROL_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// enum TUseNative
// ~~~~ ~~~~~~~~~~
// Settings to suggest how a control should obtain its implementation, OWL or
// Native. nuNever..nuAlways. Control can be later queried back per
// instance to determine the choice made by looking at the nuUsing bit.
//
enum TNativeUse {
              // Suggested native control use for class
  nuNever,    // Instance should never use native implementation
  nuAvoid,    // Avoid if possible, unless options require native
  nuDontCare, // Don't care--control uses whatever is best
  nuAttempt,  // Attempt to use, unless options not supported
  nuAlways,   // Always use when available
  nuSuggestion = 0xFF,

  nuUsing = 0x8000, // Instance is using native
};

//
// class TControl
// ~~~~~ ~~~~~~~~
class _OWLCLASS TControl : virtual public TWindow {
  public:
    TControl(TWindow*        parent,
             int             id,
             const char far* title,
             int x, int y, int w, int h,
             TModule*        module = 0);

    TControl(TWindow* parent, int resourceId, TModule* module = 0);
   ~TControl();

    TNativeUse GetNativeUse() const;

  protected:

    // Constructor to alias non-OWL control
    //
    TControl(HWND hWnd, TModule* module = 0);

    // These methods are called for owner-draw controls (buttons, list boxes,
    // and combo boxes)
    //
    virtual int   CompareItem(COMPAREITEMSTRUCT far& compareInfo);
    virtual void  DeleteItem(DELETEITEMSTRUCT far& deleteInfo);
    virtual void  MeasureItem(MEASUREITEMSTRUCT far& measureInfo);
    virtual void  DrawItem(DRAWITEMSTRUCT far& drawInfo);

    // Default behavior for DrawItem is to call one of the following based on
    // the draw type:
    //
    virtual void  ODADrawEntire(DRAWITEMSTRUCT far& drawInfo);
    virtual void  ODAFocus(DRAWITEMSTRUCT far& drawInfo);
    virtual void  ODASelect(DRAWITEMSTRUCT far& drawInfo);

    // Message response functions
    //
    void          EvPaint();
    TResult       EvCompareItem(uint ctrlId, COMPAREITEMSTRUCT far& comp);
    void          EvDeleteItem(uint ctrlId, DELETEITEMSTRUCT far& del);
    void          EvDrawItem(uint ctrlId, DRAWITEMSTRUCT far& draw);
    void          EvMeasureItem(uint ctrlId, MEASUREITEMSTRUCT far& meas);

  protected:
    TNativeUse    NativeUse;  // Using a native control implementation

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TControl(const TControl&);
    TControl& operator =(const TControl&);

  DECLARE_RESPONSE_TABLE(TControl);
  DECLARE_STREAMABLE(_OWLCLASS, TControl, 2);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline Implementations
//

//
// Return if OWL is using the native common control or not.
//
inline TNativeUse TControl::GetNativeUse() const
{
  return NativeUse;
}

#endif  // OWL_CONTROL_H
