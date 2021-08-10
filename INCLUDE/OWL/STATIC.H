//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\static.h
//   Defines class TStatic.  This defines the basic behavior of static
//   controls
//----------------------------------------------------------------------------
#if !defined(__OWL_STATIC_H)
#define __OWL_STATIC_H

#if !defined(__OWL_CONTROL_H)
  #include <owl\control.h>
#endif

//
//  class TStatic
//  ----- -------
//
class _OWLCLASS TStatic : public TControl {
  public:
    UINT  TextLen;

    TStatic(TWindow*        parent,
            int             id,
            const char far* title,
            int x, int y, int w, int h,
            UINT            textLen = 0,
            TModule*        module = 0);

    TStatic(TWindow*   parent,
            int        resourceId,
            UINT       textLen = 0,
            TModule*   module = 0);

    //
    // returns the length of the control's text
    //
    int   GetTextLen() {return ::GetWindowTextLength(HWindow);}

    //
    // fills the passed string with the text of the associated text
    // control.  returns the number of characters copied
    //
    int   GetText(char far* str, int maxChars)
            {return ::GetWindowText(HWindow, str, maxChars);}

    //
    // sets the contents of the associated static text control to
    // the passed string
    //
    void  SetText(const char far* str) {::SetWindowText(HWindow, str);}

    //
    // clears the text of the associated static text control
    //
    virtual void Clear();

    //
    // Override TWindow virtual member functions
    //
    UINT  Transfer(void* buffer, TTransferDirection direction);

  protected:
    //
    // Override TWindow virtual member functions
    //
    char far* GetClassName();

    // Make sure that control is re-painted when resized
    void EvSize(UINT sizeType, TSize& size);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TStatic(const TStatic&);
    TStatic& operator =(const TStatic&);

  DECLARE_STREAMABLE(_OWLCLASS, TStatic, 1);
  DECLARE_RESPONSE_TABLE(TStatic);
};

#endif  // __OWL_STATIC_H
