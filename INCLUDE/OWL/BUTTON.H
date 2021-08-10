//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TButton. This defines the basic behavior of all buttons.
//----------------------------------------------------------------------------
#if !defined(OWL_BUTTON_H)
#define OWL_BUTTON_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class TButton
// ~~~~~ ~~~~~~~
class _OWLCLASS TButton : public TControl {
  public:
    TButton(TWindow*        parent,
            int             id,
            const char far* text,
            int X, int Y, int W, int H,
            bool            isDefault = false,
            TModule*        module = 0);

    TButton(TWindow* parent, int resourceId, TModule* module = 0);
   ~TButton();

    bool  GetIsDefPB() const;
    void  SetIsDefPB(bool isdefpb);

    bool  GetIsCurrentDefPB() const;
    void  SetIsCurrentDefPB(bool is);

    uint  GetState() const;
    void  SetState(uint state);

    void  SetStyle(uint style, bool redraw);

#if defined(BI_PLAT_WIN32)
    void   Click();

    // image can be HICON or HBITMAP
    //
    HANDLE GetImage() const;
    HANDLE SetImage(HANDLE image);
#endif

  protected:
    // Message response functions
    //
    uint      EvGetDlgCode(MSG far*);
    TResult   BMSetStyle(TParam1, TParam2);

    // Override TWindow member functions
    //
    char far* GetClassName();
    void      SetupWindow();

  public_data:
    bool  IsDefPB;

  protected_data:
    bool  IsCurrentDefPB;

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TButton(const TButton&);
    TButton& operator=(const TButton&);

  DECLARE_RESPONSE_TABLE(TButton);
  DECLARE_STREAMABLE(_OWLCLASS, TButton, 1);
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//
// button notification response table entry macros, methods are: void method()
//
// EV_BN_CLICKED(id, method)
// EV_BN_DISABLE(id, method)
// EV_BN_DOUBLECLICKED(id, method)
// EV_BN_HILITE(id, method)
// EV_BN_PAINT(id, method)
// EV_BN_UNHILITE(id, method)

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return true if this button is the default pushbutton.
//
inline bool TButton::GetIsDefPB() const
{
  return IsDefPB;
}

//
// Set this button the default pushbutton.
//
inline void TButton::SetIsDefPB(bool isdefpb)
{
  IsDefPB = isdefpb;
}

//
// Return true if this button is the current default pushbutton.
//
inline bool TButton::GetIsCurrentDefPB() const
{
  return IsCurrentDefPB;
}

//
// Set this button the current default push button.
//
inline void TButton::SetIsCurrentDefPB(bool is)
{
  IsCurrentDefPB = is;
}

#if defined(BI_PLAT_WIN32)
//
// Simulate clicking of this button
//
inline void TButton::Click()
{
  PRECONDITION(GetHandle());
  SendMessage(BM_CLICK);
}

//
// Return the image associated with the button.
//
inline HANDLE TButton::GetImage() const
{
  PRECONDITION(GetHandle());
  return (HANDLE)CONST_CAST(TButton*, this)->SendMessage(BM_GETIMAGE);
}

//
// Set the associated image for this button.
//
inline HANDLE TButton::SetImage(HANDLE newImage)
{
  PRECONDITION(GetHandle());
  return (HANDLE)SendMessage(BM_SETIMAGE, 0, (TParam2)newImage);
}
#endif

//
// Set the display state of the button.
//
inline void TButton::SetState(uint state)
{
  PRECONDITION(GetHandle());
  SendMessage(BM_SETSTATE, state);
}

//
//
inline uint TButton::GetState() const
{
  PRECONDITION(GetHandle());
  return (uint)CONST_CAST(TButton*, this)->SendMessage(BM_GETSTATE);
}

//
inline void TButton::SetStyle(uint style, bool redraw)
{
  PRECONDITION(GetHandle());
  SendMessage(BM_SETSTYLE, style, MkParam2(redraw,0));
}

#endif  // OWL_BUTTON_H
