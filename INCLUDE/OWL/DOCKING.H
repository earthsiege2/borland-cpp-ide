//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.15  $
//
// TDockable classes: TDockableGadgetWindow & TDockableControlBar
// TDockingSlip classes: TFloatingSlip & TEdgeSlip
// and the THarbor docking manager
//----------------------------------------------------------------------------
#if !defined(OWL_DOCKING_H)
#define OWL_DOCKING_H

#if !defined(OWL_DECFRAME_H)
# include <owl/decframe.h>
#endif
#if !defined(OWL_FLOATFRA_H)
# include <owl/floatfra.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(OWL_CONTROLB_H)
# include <owl/controlb.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

class _OWLCLASS THarbor;

//
// General use 2-D rectangular relative position enum
//
// Used here to described the location of a docking window [more specifically
// the location of the EdgeSlip containing docking windows].
//
// NOTE: This enumeration corresponds to the TLocation enumeration of
//       TDecoratedFrame.
//
enum TRelPosition {
  rpNone,                       // No location specified
  rpAbove,                      // Refers to top edge of frame
  rpBelow,                      // Refers to bottom edge of frame
  rpRightOf,                    // Refers to left edge of frame
  rpLeftOf                      // Refers to right edge of frame
};

//
// class TDockable
// ~~~~~ ~~~~~~~~~
// Abstract base class for windows that want to be dockable into docking slips-
// either fixed or floating docking windows.
//
class _OWLCLASS TDockable {
  public:
    // Return the rectangle of the dockable window in the given location.
    // The dockable chooses its layout (horizontal, vertical or rectangle) in
    // that position.
    //
    virtual TSize ComputeSize(TAbsLocation loc, TSize* dim) = 0;
    virtual void  GetRect(TRect& rect) = 0;

    // Change the window to be equal to the size returned from ComputeNNNNN.
    //
    virtual void  Layout(TAbsLocation loc, TSize* dim=0) = 0;

    // This is overriden for any window that wants to be docked. This routine
    // is called from an LButtonDown to determine if the mouse down should move
    // the window or perform an action within the docked window. For example if
    // a gadget window is docked then this routine would decide if the
    // mousedown is on an enabled gadget then the control is not be moved but
    // the action of the gadget being depressed done. Otherwise, the gadget
    // window would be moved within the docking window.
    //
    virtual bool  ShouldBeginDrag(TPoint& pt) = 0;

    virtual TWindow* GetWindow() = 0;
    virtual THarbor* GetHarbor() = 0;
};

//
// class TDockableGadgetWindow
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~
// A version of TGadgetWindow which is dockable
//
class _OWLCLASS TDockableGadgetWindow : public TGadgetWindow, public TDockable {
  public:
    TDockableGadgetWindow(TWindow*        parent = 0,
                          TTileDirection  direction = Horizontal,
                          TFont*          font = new TGadgetWindowFont,
                          TModule*        module = 0);
   ~TDockableGadgetWindow();

    // Override TDockable virtuals
    //
    TSize    ComputeSize(TAbsLocation loc, TSize* dim);
    void     GetRect(TRect& rect);
    void     Layout(TAbsLocation loc, TSize* dim=0);
    bool     ShouldBeginDrag(TPoint& pt);
    TWindow* GetWindow();
    THarbor* GetHarbor();

    // Override TGadgetWindow virtuals
    //
    virtual void LayoutSession();

  protected:
    void          EvLButtonDown(uint modKeys, TPoint& point);

    // Returns the layout direction to use when placed in a slip
    // This can be overridden to provide different docking behaviour
    //
    virtual TTileDirection GetDirectionForLocation(TAbsLocation loc);

  DECLARE_RESPONSE_TABLE(TDockableGadgetWindow);
};

//
// class TDockableControlBar
// ~~~~~ ~~~~~~~~~~~~~~~~~~~
// A control bar class that is dockable
//
class _OWLCLASS TDockableControlBar : public TDockableGadgetWindow {
  public:
    TDockableControlBar(TWindow*        parent = 0,
                        TTileDirection  direction = Horizontal,
                        TFont*          font = new TGadgetWindowFont,
                        TModule*        module = 0);

  DECLARE_CASTABLE;
};

//
// class TDockingSlip
// ~~~~~ ~~~~~~~~~~~~
// Abstract base class for windows which accept & hold dockable windows.
//
class _OWLCLASS TDockingSlip {
  public:
    // These are overriden for any window that wants to be notified on dockable
    // windows being moved or removed.
    //
    virtual void DockableInsert(TDockable& dockable, const TPoint* topLeft=0,
                                TRelPosition position=rpNone, TDockable* relDockable=0) = 0;
    virtual void DockableMove(TDockable& dockable, const TPoint* topLeft=0,
                              TRelPosition position=rpNone, TDockable* relDockable=0) = 0;
    virtual void DockableRemoved(const TRect& orgRect) = 0;

    virtual TAbsLocation GetLocation() const = 0;

    // Called by Harbor to initialize back pointer
    //
    void     SetHarbor(THarbor* harbor);
    THarbor* GetHarbor() const;

  protected:
    THarbor* Harbor;
};

//
// class TFloatingSlip
// ~~~~~ ~~~~~~~~~~~~~
// A floating frame which can hold a dockable window. Is also dockable in order
// to act as a proxy for its held dockable when dragging.
//
class _OWLCLASS TFloatingSlip : public TFloatingFrame,
                                public TDockingSlip, public TDockable
{
  public:
    TFloatingSlip(TWindow*        parent,
                  int x, int y,
                  TWindow*        clientWnd = 0,
                  bool            shrinkToClient = true,
                  int             captionHeight = DefaultCaptionHeight,
                  bool            popupPalette = true,  // false?
                  TModule*        module = 0);

    // Override TDockingSlip virtuals
    //
    void     DockableInsert(TDockable& dockable, const TPoint* topLeft,
                            TRelPosition position, TDockable* relDockable);
    void     DockableMove(TDockable& dockable, const TPoint* topLeft,
                          TRelPosition position, TDockable* relDockable);
    void     DockableRemoved(const TRect& orgRect);

    TAbsLocation GetLocation() const;

    // Override TDockable virtuals
    //
    TSize    ComputeSize(TAbsLocation loc, TSize* dim);
    void     GetRect(TRect& rect);
    void     Layout(TAbsLocation loc, TSize* dim=0);
    bool     ShouldBeginDrag(TPoint& pt);
    TWindow* GetWindow();
    THarbor* GetHarbor();

  protected:
    void    EvNCLButtonDown(uint hitTest, TPoint& point);
    void    EvLButtonDown(uint hitTest, TPoint& point);
    bool    EvSizing(uint side, TRect& rect);
    void    EvWindowPosChanging(WINDOWPOS far& windowPos);
    void    EvWindowPosChanged(WINDOWPOS far& windowPos);
    void    EvClose();
    void    EvWinIniChange(char far*);

  DECLARE_RESPONSE_TABLE(TFloatingSlip);
};

enum TGridType {   // Grid type corresponds with Location:
  YCoord,            // Top & bottom edge have Y coords parallel horiz
  XCoord,            // Left & right edge have X coords parallel vertically
};

//
// Stuff for edge slip managing the dockable layout.
//
template <class T> class TFastList {
  public:
    TFastList(int initSize = 10, int deltaGrowth = 10, bool sorted = true,
              bool unique = true);
   ~TFastList();

    bool Add(uint32 comparison, T* object);
    bool Add(uint32 comparison, T object);
    T*   Remove(uint32 comparison);
    T*   RemoveEntry(int index);
    int  FindEntry(uint32 comparison);    // Find an object with the comparison return it's index.
    T&   GetEntry(int index);             // Return the object.

    int  Count() const;                   // The count of entries in list

    void Clear();     
//    void Free();              // Clear and free all Objects (delete the items).
    T& operator [](int i);

    void Fill(TWindow* parent, TGridType gridType);

  private:
    void Grow(int minNewSize);
    void OpenUpSpace(int index);
    void CloseUpSpace(int index);

    int   Delta;
    bool  SortEntries;
    bool  UniqueEntries;

    struct TDatum {
      uint32 CompareItem;
      T*     Object;
    };

    TDatum* DataPtr;
    int     SpaceCount;
    int     EntryCount;
};

//
// class TEdgeSlip
// ~~~~~ ~~~~~~~~~
// The class of windows used by THarbor as the actual docking slips
// along the decorated frame's client's edges
//
class _OWLCLASS TEdgeSlip : public TWindow, public TDockingSlip {
  public:
    TEdgeSlip(TDecoratedFrame& parent, TAbsLocation location, TModule* module = 0);

    // Overridden TWindow virtuals
    //
    TResult  EvCommand(uint id, THandle hWndCtl, uint notifyCode);
    void     EvCommandEnable(TCommandEnabler& commandEnabler);
    void     SetupWindow();

    // Overridden TDockingSlip virtuals
    //
    void     DockableInsert(TDockable& dockable, const TPoint* topLeft,
                            TRelPosition position, TDockable* relDockable);
    void     DockableMove(TDockable& dockable, const TPoint* topLeft,
                          TRelPosition position, TDockable* relDockable);
    void     DockableRemoved(const TRect& orgRect);

    TAbsLocation GetLocation() const;

    // Called by Harbor when creating this docking window on a drop
    //
    void     ReLayout(bool forcedLayout);

  protected:
    void     EvLButtonDown(uint modKeys, TPoint& point);
    void     EvLButtonDblClk(uint modKeys, TPoint& point);
    uint     EvNCCalcSize(bool calcValidRects, NCCALCSIZE_PARAMS far& calcSize);
    void     EvNCPaint();
    bool     EvEraseBkgnd(HDC);
    void     EvParentNotify(uint event, uint childHandleOrX, uint childIDOrY);
    void     EvWindowPosChanging(WINDOWPOS far& windowPos);

    // Internal dockable tiling support
    //
    void     CompressGridLines();
    void     CompressParallel(int width);
    TSize    ComputeDockingArea();

    TWindow* MoveDraggedWindow(TWindow* draggedWindow);
    void     MoveAllOthers(TWindow* draggedWindow, TWindow* movedWindow);

    int      GridSize(int baseCoord);

  protected_data:
    TAbsLocation    Location;     // Location on the frame
    TGridType       GridType;     // Type of grid

  DECLARE_RESPONSE_TABLE(TEdgeSlip);
};

//
// class THarbor
// ~~~~~ ~~~~~~~
// The object that holds all the docking slips. It performs the actual docking
// insertion & coordination. Is never visible, but is a window in order to
// capture the mouse.
//
class _OWLCLASS THarbor : public TWindow {
  public:
    THarbor(TDecoratedFrame& df);
   ~THarbor();

    // Dockable window insertion
    //
    void     Insert(TDockable& dockable, TAbsLocation location,
                    const TPoint* where = 0,
                    TRelPosition position = rpNone, TDockable* relativeTo = 0);

    // Move a dockable from one slip to another, programatically
    //
    void     Move(TDockable& dockable, TAbsLocation location,
                  const TPoint* where = 0,
                  TRelPosition position = rpNone, TDockable* relativeTo = 0);

    // Remove a dockable from the harbor
    //
    void     Remove(TDockable& dockable);

    // Called by docking slips
    //
    bool     DockDraggingBegin(TDockable& dockable, TPoint& pt,
                               TAbsLocation location,
                               TDockingSlip* dockingNotify = 0);

  protected:
    void         SetupWindow();

    TEdgeSlip*   GetEdgeSlip(TAbsLocation location);
    void         SetEdgeSlip(TAbsLocation location, TEdgeSlip* slip);
    TRelPosition GetSlipPosition(TAbsLocation location);

    virtual TEdgeSlip* ConstructEdgeSlip(TDecoratedFrame& df,
                                         TAbsLocation location);
    virtual TFloatingSlip* ConstructFloatingSlip(TDecoratedFrame& df,
                                                 int x, int y, TWindow* dockableWindow);

    void     EvMouseMove(uint modKeys, TPoint& point);
    void     EvLButtonUp(uint modKeys, TPoint& point);
    void     EvLButtonDblClk(uint modKeys, TPoint& point);

  private:
    TDecoratedFrame&  DecFrame;

    // Docking slip windows
    //
    TEdgeSlip*   SlipTop;
    TEdgeSlip*   SlipLeft;
    TEdgeSlip*   SlipBottom;
    TEdgeSlip*   SlipRight;

    // Dockable dragging state. Put into a struct packet
    //
    TDockable*    DragDockable;
    TWindowDC*    DragDC;
    TAbsLocation  DragOrgSlipLoc;  // Original slip location on mouseDown.
    TAbsLocation  DragSlipLoc;
    TRect         DragFrame;
    TSize         DragVSize;       // Size of dockable when vertical
    TSize         DragHSize;       // Size of dockable when horizontal
    TSize         DragNSize;       // Size of dockable when a natural shape
    TPoint        DragAnchor;
    TDockingSlip* DragNotificatee;

    TRect         SlipTR;
    TRect         SlipBR;
    TRect         SlipLR;
    TRect         SlipRR;

  DECLARE_RESPONSE_TABLE(THarbor);
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Set the back pointer to the harbor.
//
inline void TDockingSlip::SetHarbor(THarbor* harbor)
{
  Harbor = harbor;
}

//
// Retrieve the associated harbor.
//
inline THarbor* TDockingSlip::GetHarbor() const
{
  return Harbor;
}

//
// Return the count of layouts.
//
template <class T>
inline int TFastList<T>::Count() const
{
  return EntryCount;
}

//
// Retrieve the indexed layout.
//
template <class T>
inline T& TFastList<T>::operator [](int i) {
  return GetEntry(i);
}
#endif  // OWL_DOCKING_H
