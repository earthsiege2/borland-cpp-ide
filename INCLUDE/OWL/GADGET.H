//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.13  $
//
// Base class TGadget and simple derived TSeparatorGadget.
//----------------------------------------------------------------------------
#if !defined(OWL_GADGET_H)
#define OWL_GADGET_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TGadgetWindow;

//
// Ids of some OWL predefined gadgets
//
#define IDG_FIRST       30000   // first predefined gadget ID
#define IDG_LAST        31000   // last predefined gadget ID
#define IDG_MESSAGE     IDG_FIRST + 0    // + 0 is for backwards compatability
#define IDG_STATUS_EXT  IDG_FIRST + 1
#define IDG_STATUS_CAPS IDG_FIRST + 2
#define IDG_STATUS_NUM  IDG_FIRST + 3
#define IDG_STATUS_SCRL IDG_FIRST + 4
#define IDG_STATUS_OVR  IDG_FIRST + 5
#define IDG_STATUS_REC  IDG_FIRST + 6
#define IDG_SIZEGRIP    IDG_FIRST + 7    // The ID for a size grip gadget

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// struct TMargins
// ~~~~~~ ~~~~~~~~
// Margin units & dimensions used by class TGadgetWindow and class TGadget.
//
struct _OWLCLASS TMargins {
  enum TUnits {Pixels, LayoutUnits, BorderUnits};

  TUnits  Units;

  int  Left;
  int  Right;
  int  Top;
  int  Bottom;

  TMargins() {Units = LayoutUnits; Left = Right = Top = Bottom = 0;}

  TMargins(TUnits u, int l, int r, int t, int b)
      {Units = u; Left = l; Right = r; Top = t; Bottom = b;}

  void GetPixels(int& left, int& right, int& top, int& bottom, int fontHeight) const;
};

//
// class TGadget
// ~~~~~ ~~~~~~~
// Gadgets have outer borders and margins within, belong to a gadget window
// in a gadget list, and have their own coordinate system.
//
// Margins are the same as for TGadgetWindow and borders are always in
// border units
//
// Default behavior for gadgets is to shrink wrap to "fit" around their
// contents you can control this by setting "ShrinkWrapWidth" and
// "ShrinkWrapHeight"
//
#if defined(BI_NO_RTTI)
class _OWLCLASS TGadget : public TStreamableBase {
#else
class _OWLCLASS TGadget {
#endif
  public:
    // Gadget border styles. These match TIUBorder's TStyles exactly
    //
    enum TBorderStyle {
      None,             //  No border painted at all
      Plain,            //  Plain plain window frame
      Raised,           //  Status field style raised
      Recessed,         //  Status field style recessed
      Embossed,         //  Grouping raised emboss bead
      Grooved,          //  Grouping groove
      ButtonUp,         //  Button in up position
      ButtonDn,         //  Button in down position
      WndRaised,        //  Raised window outer+inner edge
      WndRecessed,      //  Input field & other window recessed
      WellSet,          //  Well option set (auto grows + 1)
    };

    TGadget(int id = 0, TBorderStyle borderStyle = None);
    virtual ~TGadget();

    // Border dimensions
    //
    struct TBorders {
      uint  Left   : 8;
      uint  Right  : 8;
      uint  Top    : 8;
      uint  Bottom : 8;

      TBorders() {Left = Right = Top = Bottom = 0;}
    };

    int            GetId() const;

    // Typically you would either choose a border style (which automatically
    // sets the individual border edges) or set the borders and then override
    // member function PaintBorder() to create a custom look
    //
    // NOTE: changing the borders, margins, or border style all end up invoking
    //       the gadget window's GadgetChangedSize() member function
    //
    void           SetBorders(const TBorders& borders);
    TBorders&      GetBorders();

    void           SetMargins(const TMargins& margins);
    TMargins&      GetMargins();

    void           SetBorderStyle(TBorderStyle bs);
    TBorderStyle   GetBorderStyle() const;

    TRect&         GetBounds();

    virtual void   SetEnabled(bool enabled);
    bool           GetEnabled() const;

    void           SetVisible(bool visible);
    bool           IsVisible() const;

    void           SetEndOfRow(bool eor);
    bool           IsEndOfRow() const;

    // Simply sets the corresponding member data.
    //
    void           SetShrinkWrap(bool shrinkWrapWidth, bool shrinkWrapHeight);

    // Directly alters the size of the gadget.
    //
    void           SetSize(TSize& size);

    // Get the size that this gadget would like to be
    //
    virtual void   GetDesiredSize(TSize& size);

    // Returns the amount of space in pixels taken up by the borders and
    // margins
    //
    void           GetOuterSizes(int& left, int& right, int& top, int& bottom);

    // Returns the area excluding the borders and margins
    //
    void           GetInnerRect(TRect& rect);

    // Set the bounding rectangle for this gadget
    //
    virtual void   SetBounds(const TRect& rect);

    virtual bool   IdleAction(long idleCount);
    virtual void   CommandEnable();
    virtual void   SysColorChange();

    TGadget*       NextGadget();

  protected:

    // The following virtual methods are called to allow the gadget
    // to initialize, cleanup or update any internal information
    // when its inserted into a window, moved or removed.
    //
    virtual void   Created();
    virtual void   Inserted();
    virtual void   Moved();
    virtual void   Removed();

    void           Invalidate(bool erase = true);
    void           InvalidateRect(const TRect& rect, // receiver's coord system
                                  bool  erase = true);
    void           Update();  // Paint now if possible

    // Default behavior returns true if the point is within the receiver's
    // bounding rect. "point" is in the receiver's coordinate system
    //
    virtual bool   PtIn(const TPoint& point);

    virtual void   Paint(TDC& dc);

    // Self sent by method Paint(). Override this is if you want to
    // implement a border style that isn't supported
    //
    virtual void   PaintBorder(TDC& dc);

    // Mouse virtuals forwarded from TGadgetWindows message handlers.
    // "point" is in the receiver's coordinate system.

    // MouseMove is only called if the mouse is captured. Enter & leave when
    // mouse enters & leaves a gadget & is not captured.
    //
    virtual void   MouseEnter(uint modKeys, TPoint& point);
    virtual void   MouseMove(uint modKeys, TPoint& point);
    virtual void   MouseLeave(uint modKeys, TPoint& point);

    // Captures the mouse if "TrackMouse" is set.
    //
    virtual void   LButtonDown(uint modKeys, TPoint& point);
    virtual void   RButtonDown(uint modKeys, TPoint& point);

    // Releases the mouse capture if "TrackMouse" is set.
    //
    virtual void   LButtonUp(uint modKeys, TPoint& point);
    virtual void   RButtonUp(uint modKeys, TPoint& point);

  // Data members -- will become private
  //
  public_data:
    bool             Clip;         // Does this gadget need clip rgn set? false
    bool             WideAsPossible;  // Should this gadget be made wide? false

  protected_data:
    TGadgetWindow*   Window;          // The window that this gadget is in
    TRect            Bounds;          // The bounding rectangle of this gadget
    TBorderStyle     BorderStyle;     // Style of border to use
    TBorders         Borders;         // Size of each of the 4 borders
    TMargins         Margins;         // Size & units of the 4 margins within
    bool             ShrinkWrapWidth; // Shrink the width to fit contents?
    bool             ShrinkWrapHeight;// Shrink the height to fit contents?
    bool             TrackMouse;      // Should gadget capture the mouse? false
    int              Id;              // Integer id of this gadget

  private:
    TGadget*         Next;
    enum {
      Enabled  = 0x01,
      Visible  = 0x02,
      EndOfRow = 0x04,
    };
    uint16           Flags;           // Enabled, EndOfRow flags

    // Hidden to prevent accidental copying or assignment
    //
    TGadget(const TGadget&);
    TGadget& operator =(const TGadget&);

  friend class _OWLCLASS TGadgetList;   // Access to Next for containment
  friend class _OWLCLASS TGadgetWindow; // Access to Next for containment
  DECLARE_CASTABLE;
};

//
// class TSeparatorGadget
// ~~~~~ ~~~~~~~~~~~~~~~~
// Simple helper class that you can use when you want a separator between
// gadgets. You specify the size of the separator and the separator disables
// itself and turns off shrink wrapping
//
// "size" is used for both the width and the height
//
class _OWLCLASS TSeparatorGadget : public TGadget {
  public:
    TSeparatorGadget(int size = 0, int id = 0);
    void   Inserted();
};

//
// class TSizeGripGadget
// ~~~~~ ~~~~~~~~~~~~~~~
// A gadget that is used on the far right of a status bar to provide re-sizing
// grip for the host window.
//
class _OWLCLASS TSizeGripGadget : public TSeparatorGadget {
  public:
    TSizeGripGadget(int id = IDG_SIZEGRIP);
    void Paint(TDC& dc);
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
// Return the Id of the gadget
//
inline int TGadget::GetId () const {
  return Id;
}

//
// Return the current border of the gadget
//
inline TGadget::TBorders& TGadget::GetBorders() {
  return Borders;
}

//
// Return the margins of the gadget
//
inline TMargins& TGadget::GetMargins() {
  return Margins;
}

//
// Return the borderstyle the gadget is using
//
inline TGadget::TBorderStyle TGadget::GetBorderStyle() const {
  return BorderStyle;
}

//
// Return the bounds of the gadget
//
inline TRect& TGadget::GetBounds() {
  return Bounds;
}

//
// Return true if the gadget is enabled
//
inline bool TGadget::GetEnabled() const {
  return Flags & Enabled;
}

//
// Change the visibility of the gadget
//
inline void TGadget::SetVisible(bool visible) {
  if (visible)
    Flags |= Visible;
  else
    Flags &= ~Visible;
}

//
// Return true if the gadget is visible
//
inline bool TGadget::IsVisible() const {
  return Flags & Visible;
}

//
// Set the end of row property for the gadget
// The end of row property is used to tile gadgets
//
inline void TGadget::SetEndOfRow(bool eor) {
  if (eor)
    Flags |= EndOfRow;
  else
    Flags &= ~EndOfRow;
}

//
// Return true if this gadget is at the end of a row
//
inline bool TGadget::IsEndOfRow() const {
  return Flags & EndOfRow;
}

//
// Return the next gadget after this one
//
inline TGadget* TGadget::NextGadget() {
  return Next;
}

#endif  // OWL_GADGET_H
