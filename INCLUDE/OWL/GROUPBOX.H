//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Defines class TGroupBox.  This defines the basic behavior
//   for all group boxes.
//----------------------------------------------------------------------------
#if !defined(OWL_GROUPBOX_H)
#define OWL_GROUPBOX_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif

//
//  class TGroupBox
//  ----- ---------
//
class _OWLCLASS TGroupBox : public TControl {
  public:
    bool  NotifyParent;

    TGroupBox(TWindow*        parent,
              int             id,
              const char far* text,
              int X, int Y, int W, int H,
              TModule*        module = 0);

    TGroupBox(TWindow* parent, int resourceId, TModule*   module = 0);

    virtual void SelectionChanged(int controlId);

  protected:
    char far*    GetClassName();

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TGroupBox(const TGroupBox&);
    TGroupBox& operator =(const TGroupBox&);

  DECLARE_STREAMABLE(_OWLCLASS, TGroupBox, 1);
};

#endif  // OWL_GROUPBOX_H
