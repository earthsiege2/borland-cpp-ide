//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\control.h
//   Defines class TControl.  This defines the basic behavior
//   of all controls.
//----------------------------------------------------------------------------
#if !defined(__OWL_CONTROL_H)
#define __OWL_CONTROL_H

#if !defined(__OWL_WINDOW_H)
  #include <owl\window.h>
#endif

//
//  class TControl
//  ----- --------
//
class _OWLCLASS TControl : public TWindow {
  public:
    TControl(TWindow*        parent,
             int             id,
             const char far* title,
             int x, int y, int w, int h,
             TModule*        module = 0);

    TControl(TWindow* parent, int resourceId, TModule* module = 0);

  protected:
    //
    // these methods are called for owner-draw controls (buttons, list boxes,
    // and combo boxes)
    //
    virtual int   CompareItem(COMPAREITEMSTRUCT far& compareInfo);
    virtual void  DeleteItem(DELETEITEMSTRUCT far& deleteInfo);
    virtual void  MeasureItem(MEASUREITEMSTRUCT far& measureInfo);
    virtual void  DrawItem(DRAWITEMSTRUCT far& drawInfo);

    //
    // default behavior for DrawItem is to call one of the following based on
    // the draw type:
    //
    virtual void  ODADrawEntire(DRAWITEMSTRUCT far& drawInfo);
    virtual void  ODAFocus(DRAWITEMSTRUCT far& drawInfo);
    virtual void  ODASelect(DRAWITEMSTRUCT far& drawInfo);

    //
    // message response functions
    //
    void          EvPaint();
    LRESULT       EvCompareItem(UINT ctrlId, COMPAREITEMSTRUCT far& comp);
    void          EvDeleteItem(UINT ctrlId, DELETEITEMSTRUCT far& del);
    void          EvDrawItem(UINT ctrlId, DRAWITEMSTRUCT far& draw);
    void          EvMeasureItem(UINT ctrlId, MEASUREITEMSTRUCT far& meas);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TControl(const TControl&);
    TControl& operator =(const TControl&);

  DECLARE_RESPONSE_TABLE(TControl);
  DECLARE_STREAMABLE(_OWLCLASS, TControl, 1);
};

#endif  // __OWL_CONTROL_H
