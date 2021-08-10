//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Basic behavior for a class owning tiled gadgets.
//----------------------------------------------------------------------------
#if !defined(OWL_GADGETWI_H)
#define OWL_GADGETWI_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

//
//  class TGadgetWindowFont
//  ----- -----------------
//
//  specify the point size of the font (not the size in pixels) and whether it
//  is bold and/or italic. you get a variable width sans serif font(typically
//  Helvetica)
//
class _OWLCLASS TGadgetWindowFont : public TFont {
  public:
    TGadgetWindowFont(int  pointSize = 10,
                      bool bold = false,
                      bool italic = false);
};

//
//  class TGadgetWindow
//  ----- -------------
//
//  - maintains a list of tiled Gadgets
//  - you specify whether the Gadgets are tiled horizontally or vertically
//  - a font that the Gadgets should use
//  - you can specify left, right, top, and bottom margins. the Gadgets are
//    situated within the inner rectangle (area excluding borders and
//    margins). margins can be specified in pixels, layout units (based on
//    the window font), or border units (width or height of a thin window
//    border)
//  - you can specify that the Gadget window shrink wrap itself to "fit"
//    around its Gadgets in either the width or height or both (default for
//    horizontally tiled Gadgets is shrink wrap height and default for
//    vertically tiled Gadgets is shrink wrap width)
//
class _OWLCLASS TGadgetWindow : public TWindow {
  public:
    enum TTileDirection {Horizontal, Vertical};

    TGadgetWindow(TWindow*        parent = 0,
                  TTileDirection  direction = Horizontal,
                  TFont*          font = new TGadgetWindowFont,
                  TModule*        module = 0);

   ~TGadgetWindow();  // deletes the font

    //
    // override TWindow member function and choose initial size if shrink
    // wrapping was requested
    //
    bool          Create();

    //
    // changes the margins and initiates a layout session
    //
    void          SetMargins(TMargins& margins);

    TTileDirection GetDirection() const {return Direction;}
    virtual void  SetDirection(TTileDirection direction);
  
    TFont&        GetFont() {return *Font;}
    uint          GetFontHeight() const {return FontHeight;}

    //
    // Gadgets always get notified when a left button down occurs within their
    // bounding rectangle. if you want mouse drags and a mouse up then you
    // need to capture the mouse
    //
    bool          GadgetSetCapture(TGadget& gadget);     // fails if already captured
    void          GadgetReleaseCapture(TGadget& gadget); // ignores other gadgets

    //
    // Hint mode settings & action used by contained gadgets
    //
    enum THintMode {NoHints, PressHints, EnterHints};
    void          SetHintMode(THintMode hintMode)  // default is PressHints
                    {HintMode = hintMode;}
    THintMode     GetHintMode() {return HintMode;}

    void          SetHintCommand(int id);  // (id <= 0) to clear

    enum TPlacement {Before, After};

    //
    // insert a Gadget. you can specify a sibling Gadget that the new Gadget
    // is to be inserted before or after
    //
    // if "sibling" is 0 then the new Gadget is inserted at the beginning or
    // the end. the default is to insert the new Gadget at the end
    //
    // caller needs to also call LayoutSession() after inserting gadgets if
    // this window has already been created
    //
    virtual void  Insert(TGadget& gadget, TPlacement = After, TGadget* sibling = 0);

    //
    // removes (unlinks) a gadget from the gadget window. The gadget is
    // returned but not destroyed. returns 0 if gadget is not in window
    //
    // caller needs to also call LayoutSession() after removing gadgets if
    // this gadget window has already been created
    //
    virtual TGadget*  Remove(TGadget& gadget);

    //
    // iterates over the Gadgets invoking their CommandEnable() member function
    //
    bool          IdleAction(long idleCount);

    //
    // sent by a Gadget when its size has changed. initiates a layout session
    //
    void          GadgetChangedSize(TGadget& gadget);

    //
    // begins a layout session
    //
    // default behavior is just to tiles the Gadgets
    //
    // typically initiated by a change in margins, adding/deleting Gadgets,
    // or a Gadget changing size
    //
    virtual void  LayoutSession();

    //
    // simply sets the corresponding member data
    //
    void          SetShrinkWrap(bool shrinkWrapWidth, bool shrinkWrapHeight);

    TGadget*      FirstGadget() const {return Gadgets;}
    TGadget*      NextGadget(TGadget& gadget) const {return gadget.Next;}
    TGadget*      GadgetFromPoint(TPoint& point) const;
    TGadget*      GadgetWithId(int id) const;

  protected:
    TGadget*        Gadgets;        // Linked list of gadgets
    TFont*          Font;           // Font used for size calculations
    TBrush*         BkgndBrush;     // background brush
    TGadget*        Capture;        // Gadget that has captured the mouse
    TGadget*        AtMouse;        // Last Gadget at mouse position
    TMargins        Margins;
    uint            NumGadgets       : 8;
    uint            FontHeight       : 8;
    bool            ShrinkWrapWidth  : 8;
    bool            ShrinkWrapHeight : 8;
    uint            WideAsPossible   : 8;  // # of "WideAsPossible" gadgets
    bool            DirtyLayout      : 8;
    TTileDirection  Direction        : 8;
    THintMode       HintMode         : 8;

    //
    // called by Paint(). iterates over the Gadgets and asks each one to draw
    //
    // override this to implement a specific look (e.g. separator line,
    // raised, ...)
    //
    virtual void  PaintGadgets(TDC& dc, bool erase, TRect& rect);

    //
    // if shrink wrapping was requested returns the size needed to accomodate
    // the borders, margins, and the widest/highest Gadget; otherwise the
    // current width/height are returned
    //
    // override this member function if you want to leave extra room for a
    // specific look (e.g. separator line, raised, ...)
    //
    // if you override GetDesiredSize() you will probably also need to
    // override GetInnerRect()
    //
    virtual void  GetDesiredSize(TSize& size);

    //
    // computes the area inside of the borders and margins
    //
    // override this if you want to leave extra room for a specific look
    // (e.g. separator line, raised, ...)
    //
    // if you override GetInnerRect() you will probably also need to override
    // GetDesiredSize()
    //
    virtual void  GetInnerRect(TRect& rect);

    //
    // a layout unit is defined by dividing the window font "em" into 8
    // vertical and 8 horizontal segments
    //
    int           LayoutUnitsToPixels(int units);

    //
    // returns the left, right, top, and bottom margins converted to pixels
    //
    void          GetMargins(TMargins& margins,
                             int& left, int& right, int& top, int& bottom);

    //
    // tiles the Gadgets in the direction requested (horizontal or vertical)
    //
    // calls member function PositionGadget() to allow derived classes an
    // opportunity to adjust the spacing between Gadgets
    //
    virtual TRect TileGadgets();

    //
    // selects the font into the DC and calls PaintGadgets()
    //
    void          Paint(TDC& dc, bool erase, TRect& rect);

    virtual void  PositionGadget(TGadget* previous, TGadget* next, TPoint& point);

    //
    // message response functions
    //
    void          EvLButtonDown(uint modKeys, TPoint& point);
    void          EvLButtonUp(uint modKeys, TPoint& point);
    void          EvLButtonDblClk(uint modKeys, TPoint& point);
    void          EvMouseMove(uint modKeys, TPoint& point);
    HBRUSH        EvCtlColor(HDC hDC, HWND /*hWndChild*/, uint /*ctlType*/);
    void          EvSize(uint sizeType, TSize& size);
    void          EvSysColorChange();

  private:
    TRect         TileHorizontally();
    TRect         TileVertically();

    friend class TGadget;

    //
    // hidden to prevent accidental copying or assignment
    //
    TGadgetWindow(const TGadgetWindow&);
    TGadgetWindow& operator =(const TGadgetWindow&);

  DECLARE_RESPONSE_TABLE(TGadgetWindow);
  DECLARE_CASTABLE;
};

#endif  // OWL_GADGETWI_H
