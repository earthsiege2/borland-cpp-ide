//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Defines class TScrollBar.  This defines the basic
//   behavior of all scrollbar controls.
//----------------------------------------------------------------------------
#if !defined(OWL_SCROLLBAR_H)
#define OWL_SCROLLBAR_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif

//
//  class TScrollBar
//  ----- ----------
//
class _OWLCLASS TScrollBar : public TControl {
  public:
    TScrollBar(TWindow*        parent,
               int             id,
               int x, int y, int w, int h,
               bool            isHScrollBar,
               TModule*        module = 0);

    TScrollBar(TWindow* parent, int resourceId, TModule*   module = 0);

    //
    // Virtual functions to interface to scrollbars & derived
    //
    virtual void  GetRange(int& min, int& max) const
                    {::GetScrollRange(HWindow, SB_CTL, &min, &max);}
    virtual int   GetPosition() const {return ::GetScrollPos(HWindow, SB_CTL);}
    virtual void  SetRange(int min, int max)
                    {::SetScrollRange(HWindow, SB_CTL, min, max, false);}
    virtual void  SetPosition(int thumbPos);
    virtual int   DeltaPos(int delta);

    //
    // Override TWindow virtual member functions
    //
    uint          Transfer(void* buffer, TTransferDirection direction);

    //
    // called by EvHScroll and EvVScroll response table handlers
    //
    // these routines all end up calling SetPosition()
    //
    virtual void  SBLineUp();
    virtual void  SBLineDown();
    virtual void  SBPageUp();
    virtual void  SBPageDown();
    virtual void  SBThumbPosition(int thumbPos);
    virtual void  SBThumbTrack(int thumbPos);
    virtual void  SBTop();
    virtual void  SBBottom();
    virtual void  SBEndScroll();

    //
    // response table handlers that call above virtual functions in 
    // response to messages sent by to us by TWindow::DispatchScroll()
    //
    void          EvHScroll(uint scrollCode, uint thumbPos, HWND hWndCtl);
    void          EvVScroll(uint scrollCode, uint thumbPos, HWND hWndCtl);
    
  public:
    int  LineMagnitude;
    int  PageMagnitude;

  protected:
    //
    // Override TWindow virtual member functions
    //
    char far*     GetClassName();
    void          SetupWindow();

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TScrollBar(const TScrollBar&);
    TScrollBar& operator=(const TScrollBar&);

  DECLARE_RESPONSE_TABLE(TScrollBar);
  DECLARE_STREAMABLE(_OWLCLASS, TScrollBar, 1);
};

//
// scroll bar notification macros. methods are: void method()
//
// EV_SB_LINEDOWN(id, method)
// EV_SB_LINEUP(id, method)
// EV_SB_PAGEDOWN(id, method)
// EV_SB_PAGEUP(id, method)
// EV_SB_TOP(id, method)
// EV_SB_BOTTOM(id, method)
// EV_SB_THUMBPOSITION(id, method)
// EV_SB_ENDSCROLL(id, method)
// EV_SB_BEGINTRACK(id, method)

//
//  struct TScrollBarData
//  ------ --------------
//
//  TScrollBar transfer structure
//
struct TScrollBarData {
  int  LowValue;
  int  HighValue;
  int  Position;
};

#endif  // OWL_SCROLLBAR_H
