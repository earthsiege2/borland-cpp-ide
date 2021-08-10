//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TGroupBox.  This defines the basic behavior for all
// group boxes.
//----------------------------------------------------------------------------
#if !defined(OWL_GROUPBOX_H)
#define OWL_GROUPBOX_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TGroupBox
// ~~~~~ ~~~~~~~~~
class _OWLCLASS TGroupBox : public TControl {
  public:
    TGroupBox(TWindow*        parent,
              int             id,
              const char far* text,
              int X, int Y, int W, int H,
              TModule*        module = 0);

    TGroupBox(TWindow* parent, int resourceId, TModule* module = 0);

    // Returns the length of the control's text
    //
    int   GetTextLen();

    // Fills the given string with the text of the control.  Returns the
    // number of characters copied.
    // Sets the contents of the associated static text control to the given
    // string
    //
    int   GetText(char far* str, int maxChars);
    void  SetText(const char far* str);

    virtual void SelectionChanged(int controlId);

    bool   GetNotifyParent() const;
    void   SetNotifyParent(bool notifyparent);

  protected:
    char far*    GetClassName();

  public_data:
    bool  NotifyParent;

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TGroupBox(const TGroupBox&);
    TGroupBox& operator =(const TGroupBox&);

  DECLARE_STREAMABLE(_OWLCLASS, TGroupBox, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline int TGroupBox::GetTextLen() {
  return ::GetWindowTextLength(GetHandle());
}

//
inline int TGroupBox::GetText(char far* str, int maxChars) {
  return ::GetWindowText(GetHandle(), str, maxChars);
}

//
inline void TGroupBox::SetText(const char far* str) {
  ::SetWindowText(GetHandle(), str);
}

//
// Return the flag that indicates whether the parent is notified or not.
//
inline bool TGroupBox::GetNotifyParent() const
{
  return NotifyParent;
}

//
// Set the flag that indicates whether the parent is notified or not.
//
inline void TGroupBox::SetNotifyParent(bool notifyparent)
{
  NotifyParent = notifyparent;
}

#endif  // OWL_GROUPBOX_H
