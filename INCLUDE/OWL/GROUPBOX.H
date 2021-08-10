//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\groupbox.h
//   Defines class TGroupBox.  This defines the basic behavior
//   for all group boxes.
//----------------------------------------------------------------------------
#if !defined(__OWL_GROUPBOX_H)
#define __OWL_GROUPBOX_H

#if !defined(__OWL_CONTROL_H)
  #include <owl\control.h>
#endif

//
//  class TGroupBox
//  ----- ---------
//
class _OWLCLASS TGroupBox : public TControl {
  public:
    BOOL  NotifyParent;

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

#endif  // __OWL_GROUPBOX_H
