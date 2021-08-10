//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#if !defined(__APPBTNBA_H)
#define __APPBTNBA_H

#include <owl\toolbox.h>
#include "appbtn.h"

//
// button bar that contains application buttons.
//
class TAppButtonBar : public TToolBox {
  public:
    static const int AppButtonIdBase;

    TAppButtonBar(TWindow*        parent,
                  int             numColumns = 2,
                  int             numRows = AS_MANY_AS_NEEDED,
                  TTileDirection  direction = Vertical,
                  TModule*        module = 0)
      : TToolBox(parent, numColumns, numRows, direction, module) {}

    void          SetupWindow();
    void          MoveButton(int srcLoc, int destLoc, const string& iconPath);
    void          ChangeOrientation(TTileDirection direction);
    void          DestroyButton(int loc);
    TAppButton*   ButtonWithId(int id);
    int           IdFromLoc(int loc) { return AppButtonIdBase + loc; }
    int           LocFromId(int id) { return id - AppButtonIdBase; }
    void          GetSize(TSize& sz) { GetDesiredSize(sz); }
    void          Flush(int del = 0);
    void          ReDraw();

  protected:
    void          EvRButtonDown(UINT modKeys, TPoint& point);
    void          EvLButtonUp(UINT modKeys, TPoint& point);
    void          EvLButtonDown(UINT modKeys, TPoint& point);
    void          EvMouseMove(UINT modKeys, TPoint& point);

  private:
    int           DragState;
    unsigned      DragButtonId;
    HCURSOR       OrigCursor;
    HCURSOR       DragCursor;
    TPoint        StartDragPoint;
    int           CM_PROPERTIES;
    int           CM_BUTTON_PRESSED;
    int           CM_BUTTON_DRAG;
        
    void          SetDragCursor();
    void          ResetOrigCursor();

  DECLARE_RESPONSE_TABLE(TAppButtonBar);
};

#endif // __APPBTNBA_H

